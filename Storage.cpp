#include <iostream>
#include <string>
#include <algorithm>
#include "Storage.h"
#include "Route.h"

using namespace std;

// конструктор по умолчанию
Store::Store()
{
    this->array = new Route*[8]; // выделяем память под 8 элементов
    this->countElement = 0; // кол-во элементов = 0
    cout << "Вызван конструктор по умолчанию класса Store" << endl;
}

// конструктор с параметром
Store::Store(int size)
{
    this->array = new Route*[size]; // выделяем память под 8 элементов
    this->countElement = 0; // кол-во элементов = 0
    cout << "Вызван конструктор c параметром класса Store" << endl;
}

// конструктор копирования
Store::Store(const Store &s)
{
    this->countElement = s.countElement; // копируем кол-во элементов
    this->array = new Route*[this->countElement]; // создаем массив на 8 элементов

    for (int id = 0; id < this->countElement; id++) this->array[id] = s.array[id]; // копируем элементы

    cout << "Вызван конструктор копирования класса Store" << endl;
}

// деструктор
Store::~Store()
{
    delete array; // высвобождаем память
    cout << "Вызван деструктор класса Store" << endl;
}

// сортировка массива
void Store::SortedArray()
{
    // метод сортировки пузырьком
    for (int id1 = 0; id1 < countElement; id1++) // кол-во итераций = кол-ву элементов
    {
        for (int id2 = 0; id2 < countElement - 1; id2++) // перебираем элементы не доходя до последнего
        {
            if (stoi(array[id2]->GetNumber()) > stoi(array[id2+1]->GetNumber())) // если текущий больше последуещего, то меняем их местами
            {
                Route *buf = array[id2];
                array[id2] = array[id2+1];
                array[id2+1] = buf;
            }
        }
    }
}

// поиск по началу маршрута
void Store::FindStart()
{
    // очищаем буфер ввода
    string buf;
    getline(cin, buf);

    string findDestination; // переменная хранин введеный пункт
    cout << "\nЧтобы узнать информацию о маршрутах, введите начальный пункт назначения: ";
    getline(cin, findDestination);

    int flagFind = 0; // флаг на найденность таких маршрутов

    cout << "\n~Информация о маршрутах~" << endl;

    for (int id = 0; id < countElement; id++) // перебираем все элементы
    {
        if (findDestination == array[id]->GetStart()) // если мы нашли такой пункт
        {
            flagFind = 1; // меняев флаг
            cout << array[id]->GetNumber() << endl; // выводим номер маршрута
        }
    }

    if (!flagFind) cout << "\nМаршрутов нет!" << endl; // если не нашли пункт
}

// аналогично нахождению по началу маршрута
void Store::FindEnd()
{
    // очищаем буфер ввода
    string buf;
    getline(cin, buf);

    string findDestination;
    cout << "\nЧтобы узнать информацию о маршрутах, введите начальный пункт назначения: ";
    getline(cin, findDestination);

    int flagFind = 0;

    cout << "\n~Информация о маршрутах~" << endl;

    for (int id = 0; id < countElement; id++)
    {

        if (findDestination == array[id]->GetEnd())
        {
            flagFind = 1;
            cout << array[id]->GetNumber() << endl;
        }
    }

    if (!flagFind) cout << "\nМаршрутов нет!" << endl;
}

// извлечение значения
void Store::ExtractField()
{
    for (int id = 0; id < countElement; id++) array[id]->Extract(); // извлекаем значения из всех элементов
}

// получение полей
void Store::GetFiel()
{
    // очищаем буфер ввода
    string buf;
    getline(cin, buf);

    string choice; // переменная выбора элемента
    cout << "\nВведите номер элемента, поля которого вы хотите вывести: ";
    cin >> choice; // ввод

    // проверка на правильность ввода (работа с исключительной ситуацией)
    try
    {
        // если есть буква, кидаем ошибку
        for (int id = 0; id < choice.size(); id++) if (isalpha(choice[id])) throw "Error";

        // если есть буква
        if (!all_of(choice.begin(), choice.end(), ::isdigit)) throw "Error";
    }
    catch(const char*mssg)
    {
        cout << "Неверный ввод!" << endl;
    }

    // если выбор элемента превышает значения кол-ва элементов или меньше 0, то ошибка
    if (choice > to_string(countElement) or choice < "0")
    {
        cout << "Ошибка ввода" << endl;
        exit(0);
    }

    else
    {
        int idChoice = stoi(choice);
        array[idChoice]->Get(); // выводим поля
    }
}

// метод установки значения
void Store::Set()
{
    // очищаем буфер ввода
    string buf;
    getline(cin, buf);

    if (countElement > 7) cout << "\nКол-во элементов не может быть больше 8" << endl;
    else
    {
        Route *route = new Route();
        route->Set();
        array[countElement++] = route;
    }

    this->SortedArray();
}

// метод изменения значения
void Store::Change()
{
    // очищаем буфер ввода
    string buf;
    getline(cin, buf);

    cout << "\nВыберете номер элемента, данные которого хотите изменить: ";
    string choice;
    cin >> choice;

    try
    {
        // если есть буква
        for (int id = 0; id < choice.size(); id++) if (isalpha(choice[id])) throw "Error";

        // если не лежит в диапазоне
        if (choice > to_string(countElement) or choice < "0") throw "Error";
    }
    catch(const char*mssg)
    {
        cout << "Ошибка ввода!" << endl;
        exit(0);
    }

    array[stoi(choice)]->Change();
}

// метод удаления
void Store::Delete()
{
    // очищаем буфер ввода
    string buf;
    getline(cin, buf);

    cout << "Выберете номер элемента, данные которого хотите удалить: ";
    string choice;
    cin >> choice;

    try
    {
        for (int id = 0; id < choice.size(); id++) if (isalpha(choice[id])) throw "Error";
        if (choice > to_string(countElement) or choice < "0") throw "Error";
    }
    catch(const char*mssg)
    {
        cout << "Ошибка ввода!" << endl;
        exit(0);
    }

    // удаление значений
    for (int id = stoi(choice); id < countElement - 1; id++) array[id] = array[id+1];
    countElement--;
}
