#pragma once
#include "Herbivore.h"

class LepusEuropaeus : public Herbivore  // конкретний клас-нащадок
{
public:
    // Конструктор без параметрів, ініціалізує об'єкт з вагою 4 кг
    LepusEuropaeus() : Herbivore("Заєць", 4) {}

    // Конструктор із параметром, дозволяє задати вагу
    LepusEuropaeus(unsigned short weight) : Herbivore("Заєць", weight) {}
};

// Європа
// https://en.wikipedia.org/wiki/European_hare