#pragma once
#include "Carnivore.h"

class VulpesVulpes : public Carnivore  // конкретний клас-нащадок
{
public:
    // Конструктор без параметрів, ініціалізує об'єкт з силою укусу 130 Н
    VulpesVulpes() : Carnivore("Лисиця", 130) {}

    // Конструктор із параметром, дозволяє задати силу
    VulpesVulpes(unsigned short power) : Carnivore("Лисиця", power) {}
};

// Європа
// https://en.wikipedia.org/wiki/Red_fox