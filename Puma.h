#pragma once
#include "Carnivore.h"

class PumaConcolor : public Carnivore  // конкретний клас-нащадок
{
public:
    // Конструктор без параметрів, ініціалізує об'єкт з силою укусу 530 Н
    PumaConcolor() : Carnivore("Пума", 530) {}

    // Конструктор із параметром, дозволяє задати силу
    PumaConcolor(unsigned short power) : Carnivore("Пума", power) {}
};

// Південна Америка
// https://en.wikipedia.org/wiki/Cougar