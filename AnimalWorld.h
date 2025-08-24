#pragma once
#include "IContinent.h"

// Клас, що представляє екосистему "Світ тварин", виступає клієнтом 
// для фабрики IContinent. Керує колекціями травоїдних і хижаків та 
// моделює їх взаємодію.
class AnimalWorld  // "Світ тварин" - клієнтський клас
{
private:
    vector<Herbivore*> herbivores;  // колекція травоїдних тварин
    vector<Carnivore*> carnivores;  // колекція хижих тварин
    IContinent* continent;  // вказівник на фабрику континенту 
    // для створення тварин

public:
    // Конструктор, що ініціалізує світ тварин із заданою фабрикою континенту
    AnimalWorld(IContinent* cont);

    // Деструктор, що звільняє пам’ять, виділену для травоїдних, 
    // хижаків і континенту
    ~AnimalWorld();

    // Годує всіх травоїдних, викликаючи їхній метод EatGrass
    void MealsHerbivores();

    // Моделює полювання хижаків на травоїдних
    void NutritionCarnivores();

    // Повертає константне посилання на вектор вказівників на травоїдних
    const vector<Herbivore*>& GetHerbivores() const;

    // Повертає константне посилання на вектор вказівників на хижаків
    const vector<Carnivore*>& GetCarnivores() const;

    // Випадково перемішує порядок травоїдних і хижаків
    void ShuffleAnimals();

    // Виводить статус усіх тварин (травоїдних і хижаків)
    void PrintStatusAnimals();
};