#pragma once
#include "Herbivore.h"


class Carnivore  // базовий клас для м'ясоїдних (хижих) тварин
{
protected:
    bool life;              // статус, що вказує, чи жива тварина (true)
    string species;         // назва виду або породи тварини
    unsigned short power;   // сила хижака в ньютонах (не більше 65535)

public:
    // Конструктор, що ініціалізує вид, силу та стан життя м'ясоїда.
    // Параметри: sp - вид тварини, p - початкова сила.
    Carnivore(const string& sp, unsigned short p);

    // Сетер для повернення до життя хижака
    void SetAlive(bool alive);

    // Гетер для отримання назви виду хижака 
    string GetName() const;

    // Метод "їсти", який приймає об'єкт травоїдного (вказівник на клас).
    // Параметр powerGain — приріст сили тварини внаслідок поїдання 
    // травоїдного (за замовчуванням 10 Н).
    void Eat(Herbivore* herbivore, unsigned short powerGain = 10);

    // Метод для виведення поточного стану тварини
    void PrintStatus() const;

    // Віртуальний деструктор для коректного очищення в похідних класах
    virtual ~Carnivore();
};