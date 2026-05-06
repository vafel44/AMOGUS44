#define _CRT_SECURE_NO_WARNINGS  // Отключает предупреждения в Visual Studio

#include "Array.h"
#include <algorithm>  // для std::swap

// Конструктор с параметром (размер массива)
Array::Array(int s) : size(s) {
    data = new int[size];
    // Инициализируем нулями
    for (int i = 0; i < size; i++) {
        data[i] = 0;
    }
    std::cout << "Создан массив размером " << size << std::endl;
}

// Конструктор копирования (обязателен)
Array::Array(const Array& other) {
    size = other.size;
    data = new int[size];
    for (int i = 0; i < size; i++) {
        data[i] = other.data[i];
    }
    std::cout << "Создана копия массива размером " << size << std::endl;
}

// Деструктор
Array::~Array() {
    delete[] data;
    std::cout << "Массив размером " << size << " удален" << std::endl;
}

// Заполнение массива значениями с клавиатуры
void Array::fillArray() {
    std::cout << "Введите " << size << " элементов массива:" << std::endl;
    for (int i = 0; i < size; i++) {
        std::cout << "Элемент [" << i << "]: ";
        std::cin >> data[i];
    }
    std::cout << "Массив успешно заполнен!" << std::endl;
}

// Заполнение массива одним значением
void Array::fill(int value) {
    for (int i = 0; i < size; i++) {
        data[i] = value;
    }
    std::cout << "Массив заполнен значением " << value << std::endl;
}

// Отображение содержимого массива
void Array::display() const {
    std::cout << "Массив (размер " << size << "): ";
    for (int i = 0; i < size; i++) {
        std::cout << data[i] << " ";
    }
    std::cout << std::endl;
}

// Изменение размера массива
void Array::resize(int newSize) {
    // Выделяем новую память
    int* newData = new int[newSize];

    // Копируем старые данные (сколько поместится)
    int elementsToCopy = (size < newSize) ? size : newSize;
    for (int i = 0; i < elementsToCopy; i++) {
        newData[i] = data[i];
    }

    // Заполняем новые элементы нулями (если массив увеличился)
    for (int i = size; i < newSize; i++) {
        newData[i] = 0;
    }

    // Освобождаем старую память
    delete[] data;

    // Переключаемся на новый массив
    data = newData;
    size = newSize;

    std::cout << "Размер массива изменен с " << (size < newSize ? size : size)
        << " на " << size << std::endl;
}

// Сортировка массива (пузырьком)
void Array::sort() {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (data[j] > data[j + 1]) {
                // Меняем элементы местами
                int temp = data[j];
                data[j] = data[j + 1];
                data[j + 1] = temp;
            }
        }
    }
    std::cout << "Массив отсортирован по возрастанию" << std::endl;
}

// Поиск минимального значения
int Array::findMin() const {
    if (size == 0) {
        std::cout << "Массив пуст!" << std::endl;
        return 0;
    }

    int min = data[0];
    for (int i = 1; i < size; i++) {
        if (data[i] < min) {
            min = data[i];
        }
    }
    return min;
}

// Поиск максимального значения
int Array::findMax() const {
    if (size == 0) {
        std::cout << "Массив пуст!" << std::endl;
        return 0;
    }

    int max = data[0];
    for (int i = 1; i < size; i++) {
        if (data[i] > max) {
            max = data[i];
        }
    }
    return max;
}

// Получить элемент по индексу
int Array::getElement(int index) const {
    if (index >= 0 && index < size) {
        return data[index];
    }
    else {
        std::cout << "Ошибка: индекс " << index << " вне границ массива [0;"
            << size - 1 << "]" << std::endl;
        return 0;
    }
}

// Установить элемент по индексу
void Array::setElement(int index, int value) {
    if (index >= 0 && index < size) {
        data[index] = value;
        std::cout << "Элемент [" << index << "] установлен в значение " << value << std::endl;
    }
    else {
        std::cout << "Ошибка: индекс " << index << " вне границ массива [0;"
            << size - 1 << "]" << std::endl;
    }
}

// Получить размер массива
int Array::getSize() const {
    return size;
}