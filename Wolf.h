#pragma once
#include "Carnivore.h"

class CanisLupus : public Carnivore  // конкретний клас-нащадок
{
public:
    // Конструктор без параметрів, ініціалізує об'єкт з силою укусу 400 Н
    CanisLupus() : Carnivore("Вовк", 400) {}

    // Конструктор із параметром, дозволяє задати силу
    CanisLupus(unsigned short power) : Carnivore("Вовк", power) {}
};

// Європа
// https://en.wikipedia.org/wiki/Wolf