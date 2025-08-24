#include "Sunday.h"
#include "Europe.h"
#include "SouthAmerica.h"
#include <iostream>
#include <windows.h>
#include <stdexcept>

using namespace::std;


int main() {
    // Налаштування кодування консолі для української мови
    SetConsoleOutputCP(1251);

    // Очищення екрану консолі
    system("cls");

    // Виведення заголовка застосунку
    cout << "\t\t~~~У СВІТІ ТВАРИН~~~\n\n";

    try {
        // Створення об'єкта європейського континенту
        IContinent* europe = new Europe();
        if (!europe) {
            throw runtime_error("Помилка створення об'єкта Europe!");
        }

        // Створення об'єкта AnimalWorld для Європи
        AnimalWorld animalEurope(europe);

        // Виведення заголовка для тваринного світу Європи
        cout << "\t\t\t++ЗВІРІ ЄВРОПИ++\n";

        // Виведення початкового статусу всіх тварин та очищення консолі
        animalEurope.PrintStatusAnimals();
        Sleep(20000);  // затримка 20 секунд, щоб встигнути прочитати
        system("cls");

        // Цикл із симуляцією трофічної взаємодії в екосистемі Європи
        for (int i = 0; i < 5; ++i) {  // п'ятиразове харчування
            // Перемішування порядку тварин для випадкової взаємодії
            animalEurope.ShuffleAnimals();
            // Годування всіх травоїдних тварин
            animalEurope.MealsHerbivores();
            // Харчування всіх м'ясоїдних тварин після полювання
            animalEurope.NutritionCarnivores();
            // Затримка 30 секунд між ітераціями для спостереження
            Sleep(30000);
            // Очищення екрану консолі після кожної ітерації
            system("cls");
        }

        // Акт волі до відродження тваринного світу Європи
        DeusVult vultEurope(animalEurope);
        // Воскресіння всіх травоїдних
        vultEurope.ReviveAllHerbivores();
        // Сповнення силою всіх м'ясоїдних
        vultEurope.ReviveAllCarnivores();
        // Затримка 30 секунд для прослави Бога
        Sleep(30000);


        // Створення об'єкта південноамериканського континенту
        IContinent* southAmerica = new SouthAmerica();
        if (!southAmerica) {
            throw runtime_error("Помилка створення об'єкта SouthAmerica!");
        }

        // Створення об'єкта AnimalWorld для Південної Америки
        AnimalWorld animalSouthAmerica(southAmerica);

        // Очищення екрану консолі
        system("cls");

        // Виведення заголовка для тваринного світу Південної Америки
        cout << "\t\t\t++ЗВІРІ ПІВДЕННОЇ АМЕРИКИ++\n";

        // Виведення початкового статусу всіх тварин та очищення консолі
        animalSouthAmerica.PrintStatusAnimals();
        Sleep(30000);  // затримка 30 секунд, щоб встигнути прочитати
        system("cls");

        // Цикл із симуляцією трофічної взаємодії для Південної Америки
        for (int i = 0; i < 5; ++i) {  // п'ятиразове харчування
            // Перемішування порядку тварин для випадкової взаємодії
            animalSouthAmerica.ShuffleAnimals();
            // Годування всіх травоїдних тварин
            animalSouthAmerica.MealsHerbivores();
            // Харчування всіх м'ясоїдних тварин після полювання
            animalSouthAmerica.NutritionCarnivores();
            // Затримка 45 секунд між ітераціями для спостереження
            Sleep(45000);
            // Очищення екрану консолі після кожної ітерації
            system("cls");
        }

        // Акт волі до відродження тваринного світу Південної Америки
        DeusVult vultSouthAmerica(animalSouthAmerica);
        // Воскресіння всіх травоїдних
        vultSouthAmerica.ReviveAllHerbivores();
        // Сповнення силою всіх м'ясоїдних
        vultSouthAmerica.ReviveAllCarnivores();

        // Очищення пам’яті для europe і southAmerica виконується 
        // деструктором AnimalWorld. Деструктори animalEurope і 
        // animalSouthAmerica викликаються автоматично.
    }

    catch (const exception& e) {
        // Обробка винятків
        cerr << "Помилка: " << e.what() << "\n";
        return 1;
    }

    catch (...) {
        // Обробка невідомих винятків
        std::cerr << "Невідома помилка" << "\n";
        return 1;
    }

    return 0;
}