#ifndef FRACTION_H
#define FRACTION_H

#include <iostream>

/**
 * Класс для работы с обыкновенными дробями
 * Дробь всегда хранится в сокращённом виде, знаменатель положительный
 */
class Fraction {
private:
    int numerator;    // Числитель дроби
    int denominator;  // Знаменатель дроби (всегда положительный)

    /**
     * Сокращает дробь и приводит знаменатель к положительному значению
     * Использует алгоритм Евклида для нахождения НОД
     */
    void reduce();

public:
    /**
     * Конструктор дроби
     * @param num Числитель (по умолчанию 0)
     * @param den Знаменатель (по умолчанию 1)
     * @throws std::invalid_argument если знаменатель равен 0
     */
    Fraction(int num = 0, int den = 1);

    /**
     * Деструктор по умолчанию
     */
    ~Fraction() = default;

    // ========== АРИФМЕТИЧЕСКИЕ ОПЕРАТОРЫ ==========

    /**
     * Оператор сложения двух дробей
     * @param other Вторая дробь
     * @return Результат сложения
     */
    Fraction operator+(const Fraction& other) const;

    /**
     * Оператор вычитания двух дробей
     * @param other Вторая дробь
     * @return Результат вычитания
     */
    Fraction operator-(const Fraction& other) const;

    /**
     * Оператор умножения двух дробей
     * @param other Вторая дробь
     * @return Результат умножения
     */
    Fraction operator*(const Fraction& other) const;

    /**
     * Оператор деления двух дробей
     * @param other Вторая дробь (делитель)
     * @return Результат деления
     * @throws std::invalid_argument если делитель равен 0
     */
    Fraction operator/(const Fraction& other) const;

    // ========== ОПЕРАТОРЫ СРАВНЕНИЯ ==========

    bool operator==(const Fraction& other) const;  // Равенство
    bool operator!=(const Fraction& other) const;  // Неравенство
    bool operator<(const Fraction& other) const;   // Меньше
    bool operator>(const Fraction& other) const;   // Больше
    bool operator<=(const Fraction& other) const;  // Меньше или равно
    bool operator>=(const Fraction& other) const;  // Больше или равно

    // ========== ОПЕРАТОРЫ ВВОДА/ВЫВОДА ==========

    /**
     * Дружественная функция для вывода дроби в консоль
     * Формат вывода: числитель/знаменатель или целая часть для неправильных дробей
     */
    friend std::ostream& operator<<(std::ostream& os, const Fraction& f);

    /**
     * Дружественная функция для ввода дроби из консоли
     * Ожидает формат: числитель/знаменатель (например: 3/4)
     */
    friend std::istream& operator>>(std::istream& is, Fraction& f);

    // ========== ДОПОЛНИТЕЛЬНЫЕ МЕТОДЫ ==========

    double toDouble() const;                    // Преобразование в десятичную дробь
    int getNumerator() const { return numerator; }     // Получить числитель
    int getDenominator() const { return denominator; } // Получить знаменатель
};

#endif