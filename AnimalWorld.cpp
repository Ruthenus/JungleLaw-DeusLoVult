#include "AnimalWorld.h"
#include <iostream>
#include <random>
#include <algorithm>  // потрібно для std::shuffle
#include <stdexcept>

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
// Кожен хижак може з’їсти не більше одного травоїдного за цикл
void AnimalWorld::NutritionCarnivores()
{
    cout << "\n\tПовторення закону джунглів:\n";
    for (auto* const c : carnivores) {
        bool ate = false;  // прапорець, що вказує, чи хижак уже поїв
        for (auto* const h : herbivores) {
            // Перевірка, чи травоїд живий і чи хижак ще не їв
            if (h->IsAlive() && !ate) {
                c->Eat(h);  // хижак намагається з'їсти травоїдного
                if (!h->IsAlive()) {
                    ate = true;  // позначка, що хижак з'їв
                    // хижак з'їв одного, припиняємо для нього цикл!
                }
            }
        }
    }
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