#ifndef ROUTE_H
#define ROUTE_H

#include <iostream>
#include <string.h>
using namespace std;

class Route
{
private:
    string startDestination; // начальный пункт
    string endDestination; // конечный пункт
    string routeNumber; // номер маршрута

public:
    Route(); // конструктор по умолчанию
    Route(string startDestination, string endDestination, string routeNumber); // конструктор с параметром
    Route(const Route &r); // конструктор копирования
    ~Route(); // деструктор

    void Extract(); // метод извлечения значения
    void Get(); // метод доступа к полям
    string GetNumber(); // метод доступа к номеру маршрута
    string GetStart(); // метод доступа к начальному пункту
    string GetEnd(); // метод доступа к конечному пункту
    void Set(); // метод установки значения
    void Change(); // метод редактирования значений

    friend ostream &operator<< (ostream &stream, Route r); // перегрузка оператора извлеченния
    friend istream &operator>> (istream &stream, Route &r); // перегрузка оператора вставки
};

#endif
