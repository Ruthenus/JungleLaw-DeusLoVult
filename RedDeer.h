#pragma once
#include "Herbivore.h"

class CervusElaphus : public Herbivore  // конкретний клас-нащадок
{
public:
    // Конструктор без параметрів, ініціалізує об'єкт з вагою 215 кг
    CervusElaphus() : Herbivore("Олень", 215) {}

    // Конструктор із параметром, дозволяє задати вагу
    CervusElaphus(unsigned short weight) : Herbivore("Олень", weight) {}
};

// Європа
// https://en.wikipedia.org/wiki/Red_deer