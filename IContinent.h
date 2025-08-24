#pragma once
// Директива #pragma once забезпечує одноразове підключення заголовочного 
// файлу,щоб уникнути повторного включення та помилок компіляції
#include <vector>
#include "Herbivore.h"  // базовий клас травоїдних тварин
#include "Carnivore.h"  // базовий клас м'ясоїдних тварин

using std::vector;

// https://gist.github.com/sunmeat/7eb7779f12d6edbb0bdb2266957aed83
// https://gist.github.com/sunmeat/e9a3ac7ca33347eec1bae0b99321969f

// Абстрактний базовий клас, що визначає інтерфейс для континенту
__interface IContinent
    // https://learn.microsoft.com/en-us/cpp/cpp/interface?view=msvc-170
{
    // Мається на увазі чисто віртуальна функція для створення 
    // травоїдних для певного континенту
    void CreateHerbivores(vector<Herbivore*>& herbivores);
    // Мається на увазі чисто віртуальна функція для створення 
    // хижаків для певного континенту
    void CreateCarnivores(vector<Carnivore*>& carnivores);

    // Віртуальний деструктор тут необов'язковий!
};

// Породжувальний патерн проєктування "Абстрактна фабрика"
// https://refactoring.guru/uk/design-patterns/abstract-factory