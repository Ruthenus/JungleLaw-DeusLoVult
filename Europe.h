#pragma once
#include "IContinent.h"  // інтерфейс абстрактної фабрики
#include "Fox.h"         // лисиці
#include "Hare.h"        // зайці
#include "Lynx.h"        // рисі
#include "RedDeer.h"     // олені
#include "RoeDeer.h"     // сарни
#include "Wolf.h"        // вовки


// Конкретна фабрика для створення світу тварин Європи
class Europe : public IContinent
{
public:
    void CreateHerbivores(vector<Herbivore*>& herbivores) override;
    void CreateCarnivores(vector<Carnivore*>& carnivores) override;
};