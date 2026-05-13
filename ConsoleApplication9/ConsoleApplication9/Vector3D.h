#ifndef VECTOR3D_H
#define VECTOR3D_H

#include <iostream>

/**
 * Класс для работы с трёхмерными векторами
 * Поддерживает все основные векторные операции
 */
class Vector3D {
private:
    double coords[3];          // Массив из трёх координат [x, y, z]
    static int vectorCount;    // Статический счётчик созданных векторов

public:
    // Конструкторы и деструктор
    Vector3D(double x = 0, double y = 0, double z = 0);        // Конструктор с параметрами
    Vector3D(const Vector3D& other);                          // Конструктор копирования
    ~Vector3D();                                              // Деструктор

    /**
     * Статический метод для получения количества векторов
     * @return количество существующих векторов
     */
    static int getVectorCount();

    // ========== ОПЕРАТОР ДОСТУПА ПО ИНДЕКСУ ==========

    double& operator[](int index);                // Для изменения (неконстантный)
    const double& operator[](int index) const;   // Для чтения (константный)

    // ========== АРИФМЕТИЧЕСКИЕ ОПЕРАТОРЫ ==========

    Vector3D operator+(const Vector3D& other) const;   // Векторная сумма
    Vector3D operator-(const Vector3D& other) const;   // Векторная разность
    double operator*(const Vector3D& other) const;     // Скалярное произведение
    Vector3D operator*(double scalar) const;          // Умножение на скаляр

    // ========== СОСТАВНЫЕ ОПЕРАТОРЫ ==========

    Vector3D& operator+=(const Vector3D& other);   // Присоединение вектора
    Vector3D& operator-=(const Vector3D& other);   // Вычитание вектора
    Vector3D& operator*=(double scalar);           // Умножение на скаляр

    // ========== ОПЕРАТОРЫ ИНКРЕМЕНТА/ДЕКРЕМЕНТА ==========

    Vector3D& operator++();    // Префиксная форма (++v) - увеличивает все координаты на 1
    Vector3D operator++(int);  // Постфиксная форма (v++) - возвращает старое значение
    Vector3D& operator--();    // Префиксная форма (--v) - уменьшает все координаты на 1
    Vector3D operator--(int);  // Постфиксная форма (v--) - возвращает старое значение

    // ========== ДОПОЛНИТЕЛЬНЫЕ МЕТОДЫ ==========

    double length() const;           // Вычисление длины (модуля) вектора
    Vector3D normalize() const;      // Нормализация вектора (приведение к единичной длине)
    void print() const;              // Вывод вектора на экран в формате (x, y, z)

    /**
     * Дружественная функция для умножения скаляра на вектор
     * Позволяет писать: 5 * v (а не только v * 5)
     */
    friend Vector3D operator*(double scalar, const Vector3D& v);
};

#endif