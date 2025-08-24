#include "SouthAmerica.h"

// Реалізація конкретної фабрики для створення екосистеми Південної Америки

void SouthAmerica::CreateHerbivores(vector<Herbivore*>& herbivores)
{
    vector<Herbivore*> newHerbivores;  // допоміжний вектор травоїдних

    // Локальна утиліта для додавання певної кількості особин одного виду
    auto Add = [&](size_t count, auto creator) {
        for (size_t i = 0; i < count; ++i)
            newHerbivores.push_back(creator());
        };
    // size_t count - кількість разів, яку потрібно викликати creator;
    // auto creator - лямбда-функція, яка повертає вказівник на об'єкт класу.
    // https://learn.microsoft.com/en-us/cpp/cpp/lambda-expressions-in-cpp?view=msvc-170

    // 38 особин агуті (Dasyprocta spp. - дрібні травоїдні)
    Add(38, []() { return new Dasyprocta(); });
    // 27 особин капібари (Hydrochoerus hydrochaeris - великі травоїдні)
    Add(27, []() { return new HydrochoerusHydrochaeris(); });
    // 20 особин гуанако (Lama guanicoe - великі травоїдні)
    Add(20, []() { return new LamaGuanicoe(); });
    // 32 особини віскачі (Lagostomus maximus - дрібні гризуни)
    Add(32, []() { return new LagostomusMaximus(); });

    // Додаємо створених особин до загального вектора травоїдних
    herbivores.insert(herbivores.end(), newHerbivores.begin(),
        newHerbivores.end());
}


void SouthAmerica::CreateCarnivores(vector<Carnivore*>& carnivores)
{
    vector<Carnivore*> newCarnivores;  // допоміжний вектор м'ясоїдних

    // Локальна утиліта для додавання певної кількості особин одного виду.
    // count — кількість особин; creator — лямбда-функція, яка створює 
    // новий екземпляр класу-нащадка Carnivore.
    auto Add = [&](size_t count, auto creator) {
        for (size_t i = 0; i < count; ++i)
            newCarnivores.push_back(creator());
        };

    // 18 оцелотів (Leopardus pardalis - дрібні хижаки)
    Add(18, []() { return new LeopardusPardalis(); });
    // 10 пум (Puma concolor - середні хижаки)
    Add(10, []() { return new PumaConcolor(); });
    // 5 ягуарів (Panthera onca - великі хижаки)
    Add(5, []() { return new PantheraOnca(); });

    // Додаємо створених особин до загального вектора м'ясоїдних
    carnivores.insert(carnivores.end(), newCarnivores.begin(),
        newCarnivores.end());
}