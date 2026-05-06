#ifndef ARRAY_H
#define ARRAY_H

#include <iostream>

class Array {
private:
    int* data;    // Указатель на динамический массив
    int size;     // Размер массива

public:
    // Конструктор с параметром (размер массива)
    Array(int s = 10);

    // Конструктор копирования (обязателен)
    Array(const Array& other);

    // Деструктор
    ~Array();

    // Заполнение массива значениями с клавиатуры
    void fillArray();

    // Заполнение массива одним значением
    void fill(int value);

    // Отображение содержимого массива
    void display() const;

    // Изменение размера массива
    void resize(int newSize);

    // Сортировка массива (пузырьком)
    void sort();

    // Поиск минимального значения
    int findMin() const;

    // Поиск максимального значения
    int findMax() const;

    // Получить элемент по индексу
    int getElement(int index) const;

    // Установить элемент по индексу
    void setElement(int index, int value);

    // Получить размер массива
    int getSize() const;
};

#endif // ARRAY_H