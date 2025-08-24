#include "Herbivore.h"
#include <iostream>
#include <stdexcept>

using namespace::std;


// Конструктор, що ініціалізує вид, вагу та статус життя травоїда
Herbivore::Herbivore(const string& sp, unsigned short wt)
{
    // Перевірка, чи не є назва виду порожньою
    if (sp.empty()) {
        throw invalid_argument("Назва виду не може бути порожньою!");
    }
    // Перевірка, чи вага не перевищує максимальне значення
    if (wt > 65535) {
        throw invalid_argument("Вага не може перевищувати 65535 кг "
            "для типу unsigned short!");
    }

    // Ініціалізація полів об'єкта: вид, вага та стан життя
    this->species = sp;
    this->weight = wt;
    this->life = true;
};


// Сетер для статусу життя травоїда (змінює хижак)
void Herbivore::SetAlive(bool alive) { this->life = alive; }
// Встановлює значення стану життя - живий чи мертвий!

// Гетер для отримання назви виду тварини
string Herbivore::GetName() const { return this->species; }

// Гетер для отримання ваги тварини
unsigned short Herbivore::GetWeight() const { return this->weight; }

// Предикат для перевірки, чи живий травоїд
bool Herbivore::IsAlive() const { return this->life; }


// Визначення методу поїдання трави твариною

void Herbivore::EatGrass(unsigned short weightGain)
{
    // Нормалізація приросту ваги: максимум 5% від поточної ваги 
    // або мінімум 1 кг
    unsigned short maxWeightGain =
        static_cast<unsigned short>(this->weight * 0.05);
    if (maxWeightGain < 1) maxWeightGain = 1;

    // Якщо переданий weightGain перевищує норму — обмежити його:
    if (weightGain > maxWeightGain) {
        /*
        cout << "Приріст ваги " << weightGain << " кг занадто великий для "
            << "особини виду " << this->species << " з вагою "
            << this->weight << " кг. Обмежено до " << maxWeightGain
            << " кг.\n";
        */
        weightGain = maxWeightGain;
    }

    // Перевірка, чи травоїд живий перед поїданням трави
    if (this->life) {
        // Перевірка на переповнення ваги (максимум 65535 кг)
        if (this->weight > 65535 - weightGain) {  // 65535 - 10 = 65525
            throw overflow_error("Вага тварини не може перевищувати "
                "65535 кг!");
            // https://en.cppreference.com/w/cpp/error/overflow_error.html
        }
        // Збільшення ваги травоїда після поїдання трави
        this->weight += weightGain;
        cout << this->species << " спокійно собі їсть траву, вага "
            << "збільшується до " << this->weight << " кг.\n";
    }
    else {
        cout << this->species << " мертвий.\n";
    }
}


// Метод для виведення поточного стану тварини
void Herbivore::PrintStatus() const
{
    // Виведення інформації про вид, вагу та стан життя травоїда
    cout << "Травоїд виду: " << this->species << ", Вага: " << this->weight
        << " кг, Живий: " << (this->life ? "Так!" : "Ні.") << "\n";
}


// Віртуальний деструктор
Herbivore::~Herbivore() = default;