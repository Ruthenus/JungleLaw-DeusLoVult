#pragma once
#include "Carnivore.h"

class LynxLynx : public Carnivore  // конкретний клас-нащадок
{
public:
    // Конструктор без параметрів, ініціалізує об'єкт з силою укусу 800 Н
    LynxLynx() : Carnivore("Рись", 800) {}

    // Конструктор із параметром, дозволяє задати силу
    LynxLynx(unsigned short power) : Carnivore("Рись", power) {}
};

// Європа
// https://en.wikipedia.org/wiki/Eurasian_lynx