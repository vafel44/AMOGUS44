#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>
#include <vector>

/**
 * Класс для работы с матрицами (только для типа int)
 */
class Matrix {
private:
    int rows;                         // Количество строк
    int cols;                         // Количество столбцов
    std::vector<std::vector<int>> data; // Двумерный вектор для хранения данных

public:
    /**
     * Конструктор матрицы
     * @param r количество строк
     * @param c количество столбцов
     * @throws std::invalid_argument если размеры отрицательные
     */
    Matrix(int r = 0, int c = 0);

    /**
     * Конструктор копирования
     */
    Matrix(const Matrix& other);

    /**
     * Деструктор по умолчанию
     */
    ~Matrix() = default;

    // ========== ОПЕРАТОР ДОСТУПА К ЭЛЕМЕНТАМ ==========

    int& operator()(int i, int j);                // Для изменения
    const int& operator()(int i, int j) const;   // Для чтения

    // ========== АРИФМЕТИЧЕСКИЕ ОПЕРАТОРЫ ==========

    Matrix operator+(const Matrix& other) const;   // Сложение матриц
    Matrix operator-(const Matrix& other) const;   // Вычитание матриц
    Matrix operator*(const Matrix& other) const;   // Умножение матриц
    Matrix operator*(int scalar) const;            // Умножение на скаляр
    Matrix operator/(int scalar) const;            // Деление на скаляр

    // ========== ОПЕРАТОРЫ СРАВНЕНИЯ ==========

    bool operator==(const Matrix& other) const;   // Равенство
    bool operator!=(const Matrix& other) const;   // Неравенство
    bool operator<(const Matrix& other) const;    // Меньше (по сумме элементов)
    bool operator>(const Matrix& other) const;    // Больше (по сумме элементов)

    // ========== СОСТАВНЫЕ ОПЕРАТОРЫ ==========

    Matrix& operator+=(const Matrix& other);   // Сложение с присваиванием
    Matrix& operator-=(const Matrix& other);   // Вычитание с присваиванием
    Matrix& operator*=(int scalar);            // Умножение на скаляр с присваиванием
    Matrix& operator/=(int scalar);            // Деление на скаляр с присваиванием

    // ========== ОПЕРАТОРЫ ВВОДА/ВЫВОДА ==========

    friend std::ostream& operator<<(std::ostream& os, const Matrix& m);
    friend std::istream& operator>>(std::istream& is, Matrix& m);

    // ========== ДОПОЛНИТЕЛЬНЫЕ МЕТОДЫ ==========

    int getRows() const { return rows; }   // Получить количество строк
    int getCols() const { return cols; }   // Получить количество столбцов

    void fill(int value);                  // Заполнить матрицу одним значением
    Matrix transpose() const;              // Транспонирование матрицы
    int determinant() const;               // Вычисление определителя (только для квадратных)
};

#endif