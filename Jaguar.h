#pragma once
#include "Carnivore.h"

class PantheraOnca : public Carnivore  // конкретний клас-нащадок
{
public:
    // Конструктор без параметрів, ініціалізує об'єкт з силою укусу 5000 Н
    PantheraOnca() : Carnivore("Ягуар", 5000) {}

    // Конструктор із параметром, дозволяє задати силу
    PantheraOnca(unsigned short power) : Carnivore("Ягуар", power) {}
};

// Південна Америка
// https://en.wikipedia.org/wiki/Jaguar