#pragma once
#include "Herbivore.h"

class Dasyprocta : public Herbivore  // конкретний клас-нащадок
{
public:
    // Конструктор без параметрів, ініціалізує об'єкт з вагою 3 кг
    Dasyprocta() : Herbivore("Агуті", 3) {}

    // Конструктор із параметром, дозволяє задати вагу
    Dasyprocta(unsigned short weight) : Herbivore("Агуті", weight) {}
};

// Південна Америка
// https://en.wikipedia.org/wiki/Agouti