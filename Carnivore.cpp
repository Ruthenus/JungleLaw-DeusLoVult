#include "Carnivore.h"
#include <iostream>
#include <stdexcept>

using namespace::std;

// Щодо порівняння сили та маси: 1 кілограм-сила = 9.80665 Ньютон
// https://en.wikipedia.org/wiki/Kilogram-force


// Конструктор, що ініціалізує вид, силу та стан життя м'ясоїда
Carnivore::Carnivore(const string& sp, unsigned short p)
{
    // Перевірка, чи не є назва виду порожньою
    if (sp.empty()) {
        throw invalid_argument("Назва виду не може бути порожньою!");
    }
    // Перевірка, чи сила не перевищує максимальне значення
    if (p > 65535) {
        throw invalid_argument("Сила не може перевищувати 65535 Ньютон "
            "для типу unsigned short!");
    }

    // Ініціалізація полів об'єкта: вид, сила та стан життя
    this->species = sp;
    this->power = p;
    this->life = true;
};


// Сетер для повернення до життя хижака та наповнення його силою
void Carnivore::SetAlive(bool alive) {
    this->life = alive;
    this->power = 1483;
}


// Гетер для отримання назви виду хижака після його воскресіння
string Carnivore::GetName() const { return this->species; }


// Метод, що моделює процес поїдання травоїда хижаком
void Carnivore::Eat(Herbivore* herbivore, unsigned short powerGain)
{
    // Нормалізація приросту сили: максимум 10% від поточної сили 
    // або мінімум 10 Н
    unsigned short maxPowerGain =
        static_cast<unsigned short>(this->power * 0.1);
    if (maxPowerGain < 10) maxPowerGain = 10;

    // Якщо переданий powerGain перевищує норму — обмежити його:
    if (powerGain > maxPowerGain) {
        /*
        cout << "Приріст сили " << powerGain << " Н занадто великий для "
            << "особини виду " << this->species << " з силою "
            << this->power << " Н. Обмежено до " << maxPowerGain << " Н.\n";
        */
        powerGain = maxPowerGain;
    }

    // Перевірка, чи хижак живий
    if (!this->life) {
        cout << this->species << " мертвий.\n";
        return;
    }

    // Перевірка, чи переданий вказівник на травоїда не є nullptr
    if (herbivore == nullptr) {
        cout << this->species << " не може їсти якесь nullptr!\n";
        return;
    }

    // Перевірка, чи травоїд живий, -> в AnimalWorld::NutritionCarnivores()
    
    if (!herbivore->IsAlive()) {
        cout << this->species
            << " цурається дохлятини, шукає далі кого з'їсти!!!\n";
        return;
    }
    
    // Порівняння сили хижака з вагою травоїда
    if (this->power > herbivore->GetWeight()) {
        // Перевірка на переповнення сили (максимум 65535)
        if (this->power > 65535 - powerGain) {
            throw overflow_error("Сила хижака не може перевищувати 65535 Н!");
        }
        // Збільшення сили хижака після успішного поїдання
        this->power += powerGain;
        herbivore->SetAlive(false);
        cout << this->species << " з'їв (з'їла) особину виду "
            << herbivore->GetName() << ", сила збільшилась до "
            << this->power << " Н.\n";
    }
    else {
        // Якщо хижак не зміг з'їсти травоїда
        if (this->power <= powerGain) {
            cout << this->species << " гине після тривалої голодівки...\n";
            this->power = 0;
            this->life = false;
        }
        else {
            // Зменшення сили хижака через невдалу спробу
            this->power -= powerGain;
            cout << this->species << " як не з'їв (з'їла), то надкусив(-ла) "
                << "особину виду " << herbivore->GetName()
                << ", сила зменшилась до " << this->power << " Н.\n";
        }
    }
}


// Метод для виведення поточного стану хижака
void Carnivore::PrintStatus() const
{
    cout << "М'ясоїд виду: " << this->species << ", Сила: " << this->power
        << " Н, Живий: " << (this->life ? "Так!!!" : "Ні...") << "\n";
}


// Віртуальний деструктор
Carnivore::~Carnivore() = default;