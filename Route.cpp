#include <iostream>
#include <string.h>
#include "Route.h"

using namespace std;

// конструктор по умолчанию
Route::Route()
{
    this->startDestination = "None";
    this->endDestination = "None";
    this->routeNumber = "None";

    cout << "Вызван конструктор по умолчанию класса Route" << endl;
}

// конструктор с параметром
Route::Route(string startDestination, string endDestination, string routeNumber)
{
    this->startDestination = startDestination;
    this->endDestination = endDestination;
    this->routeNumber = routeNumber;

    cout << "Вызван конструктор с параметром класса Route" << endl;
}

// конструктор копирования
Route::Route(const Route &r)
{
    this->startDestination = r.startDestination;
    this->endDestination = r.endDestination;
    this->routeNumber = r.routeNumber;

    cout << "Вызван конструктор копирования класса Route" << endl;
}

// деструктор
Route::~Route()
{
    cout << "Вызван деструктор класса Route" << endl;
}

// метод извлечения значений
void Route::Extract()
{
    cout << this;
}

// метод доступа к полям
void Route::Get()
{
    string choice;

    // обработка исключений
    try
    {
        cout << "Что хотите получить?" <<
                "1 - Начальный пункт назначения" <<
                "2 - Конечный пункт назначения" <<
                "3 - Номер маршрута" <<
                "4 - Все поля" << endl;
        cout << "Выбор: ";
        cin >> choice;

        for (int id = 0; id < choice.size(); id ++)
        {
            if (choice[id] >= 'A' && choice[id] <= 'Z') throw "Error";
        }
    }
    catch(const char*mssg)
    {
        cout << "Неверный ввод" << endl;
    }

    if (choice == "1") cout << "Пункт назначения: " << this->startDestination << endl;
    else if (choice == "2") cout << "Номер поезда: " << this->endDestination << endl;
    else if (choice == "3") cout << "Время отправления: " << this->routeNumber << endl;
    else if (choice == "4") cout << "Пункт назначения: " << this->startDestination << "Номер поезда: " << this->endDestination << "Время отправления: " << this->routeNumber << endl;
    else
    {
        cout << "Ошибка выбора" << endl;
        exit(0);
    }

    getline(cin, choice); // обнуляем поток ввода
}

// метод доступа к номеру маршрута
string Route::GetNumber()
{
    return this->routeNumber;
}

// получить начальный пункт
string Route::GetStart()
{
    return this->startDestination;
}

// получить конечный пункт
string Route::GetEnd()
{
    return this->endDestination;
}

// метод вставки значения
void Route::Set()
{
    cin >> *this;
}

// метод изменения значений
void Route::Change()
{
    string choice;

    try
    {
        cout << "Что хотите изменить?" <<
                "1 - Начальный пункт" <<
                "2 - Конечный пункт" <<
                "3 - Номер маршрута" <<
                "4 - Все поля" << endl;
        cout << "Выбор: ";
        cin >> choice;

        for (int id = 0; id < choice.size(); id ++)
        {
            if (choice[id] >= 'A' && choice[id] <= 'Z') throw "Error";
        }
    }
    catch(const char*mssg)
    {
        cout << "Неверный ввод" << endl;
    }

    getline(cin, choice); // обнуляем поток ввода

    if (choice == "1")
    {
        cout << "Пункт назначения: ";
        cin >> this->startDestination;
    }
    else if (choice == "2")
    {
        cout << "Номер поезда: ";
        cin >> this->endDestination;
    }
    else if (choice == "3")
    {
        cout << "Время отправления: ";
        cin >> this->routeNumber;
    }
    else
    {
        cout << "Ошибка выбора" << endl;
        exit(0);
    }

    getline(cin, choice); // обнуляем поток ввода
}

ostream &operator<< (ostream &stream, Route r) // перегрузка оператора извлеченния
{
    stream << "Все поля класса:" << endl;
    stream << r.startDestination << endl;
    stream << r.endDestination << endl;
    stream << r.routeNumber << endl;

    return stream;
}

istream &operator>> (istream &stream, Route &r) // перегрузка оператора вставки
{
    cout << "Вставка значений:" << endl;
    cout << "Начальный пункт: ";
    stream >> r.startDestination;
    cout << "Конечный пункт: ";
    stream >> r.endDestination;
    cout << "Номер маршрута: ";
    stream >> r.routeNumber;
    string buf;
    getline(stream, buf); // обнуляем поток ввода
    return stream;
}
