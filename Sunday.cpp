// Реалізація методів класу DeusVult
#include "Sunday.h"
#include <iostream>

using namespace std;


DeusVult::DeusVult(AnimalWorld& world) : animalWorld(world) {}

// Метод для воскресіння всіх травоїдних тварин.
// Проходить по вектору травоїдних і відроджує тих, хто не живий.
void DeusVult::ReviveAllHerbivores()
{
    cout << "\n\tВоскресіння травоїдних:\n";
    for (auto* const h : animalWorld.GetHerbivores()) {
        if (!h->IsAlive()) h->SetAlive(true);  // див. Herbivore.cpp
        cout << h->GetName() << " відроджений (відроджена)!\n";
    }
}

// Метод для воскресіння всіх м'ясоїдних тварин.
// Проходить по вектору м'ясоїдних і відроджує їх, встановлючи силу 1483 Н.
void DeusVult::ReviveAllCarnivores()
{
    cout << "\n\tВоскресіння м'ясоїдних:\n";
    for (auto* const c : animalWorld.GetCarnivores()) {
        c->SetAlive(true);  // див. Carnivore.cpp
        cout << c->GetName() << " відроджений (відроджена)!\n";
    }
}