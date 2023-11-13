#include <iostream>
#include "Storage.h"
#include "Route.h"
#include "TextScan.h"
#include <string>

using namespace std;

int main()
{
    Store store; // объект, где будут храниться данные

    // цикл меню
    while (1)
    {
        string choice; // переменная выбора пользователя

        cout << "\n~~~МЕНЮ~~~" << endl;
        cout << "1 - Поиск по начальному пункту назначения\n"
             << "2 - Поиск по конечному пункту назначения\n"
             << "3 - Извлечь поля объекта\n"
             << "4 - Получить определенные поля\n"
             << "5 - Вставить значение\n"
             << "6 - Изменить значение\n"
             << "7 - Удалить значение\n"
             << "8 - Вывести строки без двузначных чисел" << endl;
        cout << "Выбор: ";
        cin >> choice; // ввод выбора
        cout << "\n" << endl;

        // обработка ввода (исключительные ситуации)
        try
        {
            // проверяем все символы
            for (int id = 0; id < choice.size(); id++)
            {
                // если буква, кидаем ошибку
                if (isalpha(choice[id])) throw "Error";
            }

            // если выбор не лежит в диапазоне, кидаем ошибку
            if (choice > "8" || choice < "1") throw "Error";
        }
        catch(const char*mssg) // обработка ошибки
        {
            cout << "Ошибка ввода" << endl;
            exit(0);
        }

        // проверка выбора пользователя
        if (choice == "1") store.FindStart();
        else if (choice == "2") store.FindEnd();
        else if (choice == "3") store.ExtractField();
        else if (choice == "4") store.GetFiel();
        else if (choice == "5") store.Set();
        else if (choice == "6") store.Change();
        else if (choice == "7") store.Delete();
        else if (choice == "8") TextScaner();
        else {cout << "Ошибка ввода" << endl; exit(0);}
    }
}
