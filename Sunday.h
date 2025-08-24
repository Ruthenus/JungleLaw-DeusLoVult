// Заголовковий файл для класу DeusVult
#pragma once
#include "AnimalWorld.h"

class DeusVult  // керує відродженням тварин у світі
{
private:
    AnimalWorld& animalWorld;  // посилання на об'єкт AnimalWorld, 
    // який містить вектори травоїдних і м'ясоїдних тварин
public:
    DeusVult(AnimalWorld& world);  // конструктор класу
    // Воскресіння всіх травоїдних тварин
    void ReviveAllHerbivores();
    // Воскресіння всіх м'ясоїдних тварин та наповнення їх силою
    void ReviveAllCarnivores();
};


// https://www.bible.com.ua/answers/r/24/332884