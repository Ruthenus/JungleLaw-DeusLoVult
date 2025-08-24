#pragma once
#include <string>

using std::string;


class Herbivore  // базовий клас для травоїдних тварин
{
protected:
    bool life;              // статус, що вказує, чи жива тварина (true)
    string species;         // назва виду або породи тварини
    unsigned short weight;  // маса тварини в кілограмах (не більше 65535)

public:
    // Конструктор, що ініціалізує вид, вагу та статус життя травоїда.
    // Параметри: sp - вид тварини, wt - початкова вага.
    Herbivore(const string& sp, unsigned short wt);

    // Сетер для статусу життя травоїда (змінює хижак)
    void SetAlive(bool alive);

    // Гетер для отримання назви виду тварини 
    string GetName() const;  // використано в реалізації класу Carnivore

    // Гетер для отримання ваги тварини
    unsigned short GetWeight() const;  // використано в Carnivore.cpp

    // Предикат для перевірки, чи живий травоїд
    bool IsAlive() const;  // використано в Carnivore.cpp

    // Метод (спосіб) поїдання трави твариною.
    // Параметр weightGain — приріст ваги тварини внаслідок споживання 
    // трави (за замовчуванням 10 кг).

    void EatGrass(unsigned short weightGain = 10);

    // Метод для виведення поточного стану тварини
    void PrintStatus() const;

    // Віртуальний деструктор для коректного очищення в похідних класах
    virtual ~Herbivore();
};