#pragma once
#include "IContinent.h"  // інтерфейс абстрактної фабрики
#include "Agouti.h"      // південноамериканські золотисті зайці
#include "Capybara.h"    // водосвинки звичайні
#include "Guanaco.h"     // лами
#include "Jaguar.h"      // великі кішки
#include "Ocelot.h"      // маленькі ягуароподібні кішки
#include "Puma.h"        // кугуари
#include "Viscacha.h"    // шиншили


// Конкретна фабрика для створення світу тварин Південної Америки
class SouthAmerica : public IContinent
{
public:
    void CreateHerbivores(vector<Herbivore*>& herbivores) override;
    void CreateCarnivores(vector<Carnivore*>& carnivores) override;
};