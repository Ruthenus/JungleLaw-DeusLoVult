#include "Europe.h"

// Реалізація конкретної фабрики для створення екосистеми в Європі

void Europe::CreateHerbivores(vector<Herbivore*>& herbivores)
{
    // Травоїдні Європи з типовими масами
    vector<Herbivore*> newHerbivores = {
        // 15 зайців (Lepus europaeus) ~4 кг
        new LepusEuropaeus(5), new LepusEuropaeus(5), new LepusEuropaeus(5),
        new LepusEuropaeus(5), new LepusEuropaeus(5), new LepusEuropaeus(),
        new LepusEuropaeus(), new LepusEuropaeus(), new LepusEuropaeus(),
        new LepusEuropaeus(), new LepusEuropaeus(), new LepusEuropaeus(),
        new LepusEuropaeus(), new LepusEuropaeus(), new LepusEuropaeus(),

        // 3 олені (Cervus elaphus) ~215 кг
        new CervusElaphus(), new CervusElaphus(210), new CervusElaphus(230),

        // 6 козуль (Capreolus capreolus) ~21 кг
        new CapreolusCapreolus(), new CapreolusCapreolus(),
        new CapreolusCapreolus(23), new CapreolusCapreolus(24),
        new CapreolusCapreolus(25), new CapreolusCapreolus(22),
    };
    herbivores.insert(herbivores.end(), newHerbivores.begin(),
        newHerbivores.end());
    // https://learn.microsoft.com/en-us/cpp/standard-library/vector-class?view=msvc-170#insert
    // https://learn.microsoft.com/en-us/cpp/standard-library/vector-class?view=msvc-170#end
}


void Europe::CreateCarnivores(vector<Carnivore*>& carnivores)
{
    // М'ясоїдні Європи з типовою силою укусу в ньютонах
    vector<Carnivore*> newCarnivores = {
        // 4 лисиці (Vulpes vulpes) ~130 Н
        new VulpesVulpes(), new VulpesVulpes(140),
        new VulpesVulpes(), new VulpesVulpes(120),

        // 2 рисі (Lynx lynx) ~800 Н
        new LynxLynx(), new LynxLynx(900),

        // 4 вовки (Canis lupus) ~400 Н
        new CanisLupus(), new CanisLupus(450),
        new CanisLupus(420), new CanisLupus(350),
    };
    carnivores.insert(carnivores.end(), newCarnivores.begin(),
        newCarnivores.end());
}