#pragma once
#include "Carnivore.h"

class LeopardusPardalis : public Carnivore  // конкретний клас-нащадок
{
public:
    // Конструктор без параметрів, ініціалізує об'єкт з силою укусу 350 Н
    LeopardusPardalis() : Carnivore("Оцелот", 350) {}

    // Конструктор із параметром, дозволяє задати силу
    LeopardusPardalis(unsigned short power) : Carnivore("Оцелот", power) {}
};

// Південна Америка
// https://en.wikipedia.org/wiki/Ocelot