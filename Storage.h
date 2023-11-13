#ifndef STORAGE_H
#define STORAGE_H

#include <iostream>
#include <string>
#include "Route.h"

using namespace std;

class Store
{
private:
    Route **array; // массив хранения данных
    int countElement; // подсчет кол-ва элементов в массиве

public:
    Store(); // конструктор по умолчанию
    Store(int size); // конструктор с параметром
    Store(const Store &s); // конструктор копирования
    ~Store(); // деструктор

    void SortedArray(); // сортировка после ввода
    void FindStart(); // поиск по пункту назначения
    void FindEnd(); // поиск по пункту назначения
    void ExtractField(); // извлечь значения объекта
    void GetFiel(); // получить поля
    void Set(); // вставить значение объекта
    void Change(); // изменить значение
    void Delete(); // удалить значние
};

#endif
