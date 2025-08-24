#pragma once
#include "Herbivore.h"

class CapreolusCapreolus : public Herbivore  // конкретний клас-нащадок
{
public:
    // Конструктор без параметрів, ініціалізує об'єкт з вагою 21 кг
    CapreolusCapreolus() : Herbivore("Козуля", 21) {}

    // Конструктор із параметром, дозволяє задати вагу
    CapreolusCapreolus(unsigned short weight) : Herbivore("Козуля", weight) {}
};

// Європа
// https://en.wikipedia.org/wiki/Roe_deer