#include "AnimalWorld.h"
#include <iostream>
#include <random>
#include <algorithm>  // потрібно для std::shuffle
#include <stdexcept>
#include <set>        // моралізація методу NutritionCarnivores

// fixed logic error: кілька хижаків їли одного травоїдного!

using namespace::std;


// Конструктор: ініціалізує світ тварин із заданою фабрикою континенту.
// Приймає вказівник cont на фабрику IContinent для створення тварин.
// Створює вектори травоїдних і хижаків за допомогою фабрики континенту.
AnimalWorld::AnimalWorld(IContinent* cont) : continent(cont)
{
    try {
        // Створення вектора травоїдних herbivores
        continent->CreateHerbivores(herbivores);
        // Створення вектора хижаків carnivores
        continent->CreateCarnivores(carnivores);
    }
    catch (const exception& e) {
        // Обробка винятків під час створення тварин
        cerr << "Помилка при створенні тварин: " << e.what() << "\n";
    }
}


// Деструктор: Звільняє пам’ять для всіх травоїдних, хижаків і континенту
AnimalWorld::~AnimalWorld()
{
    // Видалення всіх об'єктів травоїдних
    for (auto* const h : herbivores) delete h;
    // Видалення всіх об’єктів хижаків
    for (auto* const c : carnivores) delete c;
    // Видалення фабрики континенту
    delete continent;
}


// Годує всіх травоїдних, викликаючи їхній метод EatGrass
void AnimalWorld::MealsHerbivores()
{
    cout << "\n\tГодування травоїдних:\n";
    for (auto* const herbivore : herbivores) {
        // з перевіркою на nullptr для уникнення збоїв
        if (herbivore) herbivore->EatGrass();
    }
}

// Моделює "закон джунглів", де хижаки полюють на травоїдних.
// Кожен хижак може з'їсти не більше одного травоїдного за цикл.
// Виправлена логічна помилка: раніше кілька хижаків могли з'їсти 
// одного й того ж травоїдного в одній ітерації через те, 
// що стан травоїдного (life) змінювався після перевірки IsAlive(), 
// але вектор herbivores не оновлювався. Тепер використовується std::set 
// для відстеження з'їдених травоїдних, що гарантує, що кожен травоїд 
// може бути з'їдений лише один раз за ітерацію.
void AnimalWorld::NutritionCarnivores()
{
    // Виводимо заголовок ітерації
    cout << "\n\tПовторення закону джунглів:\n";

    // Створюємо множину вказівників на травоїдних, яких вже з'їли
    set<Herbivore*> eatenHerbivores;  // відстежуємо з'їдених травоїдних
    // std::set гарантує унікальність елементів
    // https://learn.microsoft.com/ru-ru/cpp/standard-library/set-class?view=msvc-170

    // Підраховуємо кількість живих травоїдних перед початком ітерації
    size_t aliveHerbivores = count_if(herbivores.begin(), herbivores.end(),
        [](const Herbivore* h) { return h->IsAlive(); });
    // count_if — алгоритм STL, що рахує елементи, які задовольняють умову
    // https://en.cppreference.com/w/cpp/algorithm/count.html

    cout << "Живих травоїдних перед ітерацією: " << aliveHerbivores << "\n";

    // Основний цикл по хижаках
    for (auto* const c : carnivores) {
        bool ate = false;  // прапорець: чи поїв хижак
        
        // Вкладений цикл по травоїдних
        for (auto* const h : herbivores) {
            // Перевіряємо три умови:
            // 1. Травоїдний живий
            // 2. Хижак ще не їв
            // 3. Травоїдний ще не був з'їдений іншим хижаком!
            // А як у дикій природі?!
            if (h->IsAlive() && !ate && 
                eatenHerbivores.find(h) == eatenHerbivores.end()) {
                // find(h) == end() — перевірка, чи елемент відсутній у множині

                // Виводимо спробу поїдання
                // cout << "Хижак " << c->GetName() << " намагається з'їсти "
                //    << "травоїдного виду " << h->GetName() << "\n";
                
                // Хижак намагається з'їсти травоїдного
                c->Eat(h);  // виклик методу Eat, який змінює стан h

                // Якщо після поїдання травоїдний помер
                if (!h->IsAlive()) {
                    ate = true;  // позначаємо, що хижак поїв
                    eatenHerbivores.insert(h);  // додаємо до з'їдених
                    break;  // вихід з внутрішнього циклу — хижак їсть лише одного
                }
            }
        }

        // Якщо хижак не знайшов жертву
        if (!ate) {
            cout << "Хижак " << c->GetName() 
                << " не знайшов живих травоїдних.\n";
        }
    }

    // Підсумкова статистика
    cout << "З'їдено травоїдних у цій ітерації: " 
        << eatenHerbivores.size() << "\n";
    // Повторний підрахунок живих після ітерації
    cout << "Живих травоїдних після ітерації: "
        << count_if(herbivores.begin(), herbivores.end(),
            [](const Herbivore* h) { return h->IsAlive(); }) << "\n";
}


// Повертає константне посилання на вектор вказівників травоїдних
const vector<Herbivore*>& AnimalWorld::GetHerbivores() const
{
    return herbivores;
}


// Повертає константне посилання на вектор вказівників хижаків
const vector<Carnivore*>& AnimalWorld::GetCarnivores() const
{
    return carnivores;
}


// Випадково перемішує порядок травоїдних і хижаків для моделювання 
// випадкових взаємодій у природі
void AnimalWorld::ShuffleAnimals()
{
    // Ініціалізація генератора випадкових чисел
    random_device rd;
    // https://learn.microsoft.com/en-us/cpp/standard-library/random-device-class?view=msvc-170
    mt19937 g(rd());  // застосовано алгоритм "Вихор Мерсенна"
    // https://cplusplus.com/reference/random/mt19937/

    // Перемішування вектора травоїдних
    shuffle(herbivores.begin(), herbivores.end(), g);
    // Перемішування вектора хижаків
    shuffle(carnivores.begin(), carnivores.end(), g);
    // https://en.cppreference.com/w/cpp/algorithm/shuffle
}


// Виводить статус усіх тварин (травоїдних і хижаків)
void AnimalWorld::PrintStatusAnimals()
{
    cout << "\n\tСтатус травоїдних:\n";
    for (auto* const h : herbivores) {
        if (h) h->PrintStatus();  // вивід статусу для кожного травоїдного
    }
    cout << "\n\tСтатус м'ясоїдних (хижаків):\n";
    for (auto* const c : carnivores) {
        if (c) c->PrintStatus();  // вивід статусу для кожного хижака
    }
}