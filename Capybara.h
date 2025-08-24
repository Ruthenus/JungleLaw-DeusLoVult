#pragma once
#include "Herbivore.h"

class HydrochoerusHydrochaeris : public Herbivore  // конкретний клас-нащадок
{
public:
    // Конструктор без параметрів, ініціалізує об'єкт з вагою 47 кг
    HydrochoerusHydrochaeris() : Herbivore("Капібара", 47) {}

    // Конструктор із параметром, дозволяє задати вагу
    HydrochoerusHydrochaeris(unsigned short weight) :
        Herbivore("Капібара", weight) {
    }
};

// Південна Америка
// https://en.wikipedia.org/wiki/Capybara