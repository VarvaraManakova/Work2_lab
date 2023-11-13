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
    cout << *this;
}

// метод доступа к полям
void Route::Get()
{
    // обнуляем поток ввода
    string buf;
    getline(cin, buf);

    string choice;
    cout << "\nЧто хотите получить?\n" <<
                "1 - Начальный пункт назначения\n" <<
                "2 - Конечный пункт назначения\n" <<
                "3 - Номер маршрута\n" <<
                "4 - Все поля" << endl;
    cout << "Выбор: ";
    cin >> choice;

    // обработка исключений
    try
    {
        for (int id = 0; id < choice.size(); id ++)
        {
            if (choice[id] >= 'A' && choice[id] <= 'Z') throw "Error";
        }
    }
    catch(const char*mssg)
    {
        cout << "Неверный ввод" << endl;
    }

    if (choice == "1") cout << "\nНачальный пункт назначения: " << this->startDestination << endl;
    else if (choice == "2") cout << "\nКонечный пункт назначения: " << this->endDestination << endl;
    else if (choice == "3") cout << "\nНомер маршрута: " << this->routeNumber << endl;
    else if (choice == "4") cout << "\nНачальный пункт назначения: " << this->startDestination << " | Конечный пункт назначения: " << this->endDestination << " | Номер маршрута: " << this->routeNumber << endl;
    else
    {
        cout << "Ошибка выбора" << endl;
        exit(0);
    }
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
    // обнуляем поток ввода
    string buf;
    getline(cin, buf);

    string choice;
    cout << "\nЧто хотите изменить?\n" <<
                "1 - Начальный пункт\n" <<
                "2 - Конечный пункт\n" <<
                "3 - Номер маршрута\n" << endl;
    cout << "Выбор: ";
    cin >> choice;

    try
    {
        for (int id = 0; id < choice.size(); id ++)
        {
            if (choice[id] >= 'A' && choice[id] <= 'Z') throw "Error";
        }
    }
    catch(const char*mssg)
    {
        cout << "Неверный ввод" << endl;
    }

    if (choice == "1")
    {
        getline(cin, choice);

        cout << "Начальный пункт: ";
        getline(cin, this->startDestination);
    }
    else if (choice == "2")
    {
        getline(cin, choice);

        cout << "Конечный пункт: ";
        getline(cin, this->endDestination);
    }
    else if (choice == "3")
    {
        getline(cin, choice);

        cout << "Номер маршрута: ";
        getline(cin, this->routeNumber);
    }
    else
    {
        cout << "Ошибка выбора" << endl;
        exit(0);
    }
}

ostream &operator<< (ostream &stream, Route &r) // перегрузка оператора извлеченния
{
    stream << "\nВсе поля класса:" << endl;
    stream << r.startDestination << endl;
    stream << r.endDestination << endl;
    stream << r.routeNumber << endl;

    return stream;
}

istream &operator>> (istream &stream, Route &r) // перегрузка оператора вставки
{
    string buf;

    cout << "\nВставка значений:" << endl;
    cout << "Начальный пункт: ";
    getline(stream, buf);
    r.startDestination = buf;

    cout << "Конечный пункт: ";
    getline(stream, buf);
    r.endDestination = buf;

    cout << "Номер маршрута: ";
    getline(stream, buf);
    r.routeNumber = buf;

    return stream;
}
