#pragma once
#include "Herbivore.h"

class LagostomusMaximus : public Herbivore  // конкретний клас-нащадок
{
public:
    // Конструктор без параметрів, ініціалізує об'єкт з вагою 5 кг
    LagostomusMaximus() : Herbivore("Віскача", 5) {}

    // Конструктор із параметром, дозволяє задати вагу
    LagostomusMaximus(unsigned short weight) : Herbivore("Віскача", weight) {}
};

// Південна Америка
// https://en.wikipedia.org/wiki/Plains_viscacha