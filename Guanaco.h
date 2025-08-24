#pragma once
#include "Herbivore.h"

class LamaGuanicoe : public Herbivore  // конкретний клас-нащадок
{
public:
    // Конструктор без параметрів, ініціалізує об'єкт з вагою 115 кг
    LamaGuanicoe() : Herbivore("Гуанако", 115) {}

    // Конструктор із параметром, дозволяє задати вагу
    LamaGuanicoe(unsigned short weight) : Herbivore("Гуанако", weight) {}
};

// Південна Америка
// https://en.wikipedia.org/wiki/Guanaco