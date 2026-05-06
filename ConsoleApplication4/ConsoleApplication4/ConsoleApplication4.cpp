#include "Array.h"
#include <iostream>
#include <Windows.h>  // для SetConsoleCP и SetConsoleOutputCP

int main() {
    // Настройка консоли для поддержки русских символов
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    std::cout << "========== ДЕМОНСТРАЦИЯ РАБОТЫ КЛАССА ARRAY ==========\n" << std::endl;

    // 1. Демонстрация конструктора
    std::cout << "1. Создание массива с параметром (размер 5):" << std::endl;
    Array arr1(5);
    arr1.display();
    std::cout << std::endl;

    // 2. Демонстрация заполнения массива значениями с клавиатуры
    std::cout << "2. Заполнение массива значениями:" << std::endl;
    Array arr2(5);
    arr2.fillArray();
    arr2.display();
    std::cout << std::endl;

    // 3. Демонстрация заполнения одним значением
    std::cout << "3. Заполнение массива одним значением (42):" << std::endl;
    Array arr3(6);
    arr3.fill(42);
    arr3.display();
    std::cout << std::endl;

    // 4. Демонстрация конструктора копирования
    std::cout << "4. Конструктор копирования:" << std::endl;
    Array arr4(4);
    arr4.fillArray();
    std::cout << "Оригинал: ";
    arr4.display();
    Array arr5 = arr4;  // Вызов конструктора копирования
    std::cout << "Копия: ";
    arr5.display();
    std::cout << std::endl;

    // 5. Демонстрация поиска минимума и максимума
    std::cout << "5. Поиск минимума и максимума:" << std::endl;
    Array arr6(5);
    arr6.fillArray();
    arr6.display();
    std::cout << "Минимальное значение: " << arr6.findMin() << std::endl;
    std::cout << "Максимальное значение: " << arr6.findMax() << std::endl;
    std::cout << std::endl;

    // 6. Демонстрация сортировки
    std::cout << "6. Сортировка массива:" << std::endl;
    Array arr7(5);
    arr7.fillArray();
    std::cout << "До сортировки: ";
    arr7.display();
    arr7.sort();
    std::cout << "После сортировки: ";
    arr7.display();
    std::cout << std::endl;

    // 7. Демонстрация изменения размера
    std::cout << "7. Изменение размера массива:" << std::endl;
    Array arr8(3);
    arr8.fill(10);
    arr8.display();
    arr8.resize(6);
    arr8.display();
    arr8.resize(4);
    arr8.display();
    std::cout << std::endl;

    // 8. Демонстрация работы с элементами по индексу
    std::cout << "8. Работа с элементами по индексу:" << std::endl;
    Array arr9(5);
    arr9.fill(100);
    arr9.display();
    std::cout << "Элемент с индексом 2: " << arr9.getElement(2) << std::endl;
    arr9.setElement(3, 999);
    arr9.display();
    std::cout << "Размер массива: " << arr9.getSize() << std::endl;
    std::cout << std::endl;

    // 9. Демонстрация автоматического вызова деструктора
    std::cout << "9. Деструктор (будет вызван автоматически при выходе из main):" << std::endl;

    std::cout << "\n========== КОНЕЦ ДЕМОНСТРАЦИИ ==========" << std::endl;

    return 0;
}