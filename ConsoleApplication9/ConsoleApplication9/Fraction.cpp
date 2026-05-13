#include "Fraction.h"
#include <stdexcept>
#include <cmath>

/**
 * Вспомогательная функция для нахождения НОД (наибольший общий делитель)
 * Используется алгоритм Евклида
 */
int findGCD(int a, int b) {
    a = std::abs(a);  // Берём модуль числа
    b = std::abs(b);
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

/**
 * Метод сокращения дроби
 */
void Fraction::reduce() {
    // Проверка на нулевой знаменатель
    if (denominator == 0) {
        throw std::invalid_argument("Oshibka: Znamenatel ne mozhet byt nulyom!");
    }

    // Находим НОД и делим на него числитель и знаменатель
    int gcd = findGCD(numerator, denominator);
    numerator /= gcd;
    denominator /= gcd;

    // Знаменатель всегда делаем положительным
    if (denominator < 0) {
        numerator = -numerator;
        denominator = -denominator;
    }
}

/**
 * Конструктор дроби
 */
Fraction::Fraction(int num, int den) : numerator(num), denominator(den) {
    if (den == 0) {
        throw std::invalid_argument("Oshibka: Znamenatel ne mozhet byt nulyom!");
    }
    reduce(); // Сокращаем дробь после создания
}

/**
 * Оператор сложения
 * Формула: a/b + c/d = (a*d + c*b) / (b*d)
 */
Fraction Fraction::operator+(const Fraction& other) const {
    return Fraction(
        numerator * other.denominator + other.numerator * denominator,
        denominator * other.denominator
    );
}

/**
 * Оператор вычитания
 * Формула: a/b - c/d = (a*d - c*b) / (b*d)
 */
Fraction Fraction::operator-(const Fraction& other) const {
    return Fraction(
        numerator * other.denominator - other.numerator * denominator,
        denominator * other.denominator
    );
}

/**
 * Оператор умножения
 * Формула: a/b * c/d = (a*c) / (b*d)
 */
Fraction Fraction::operator*(const Fraction& other) const {
    return Fraction(
        numerator * other.numerator,
        denominator * other.denominator
    );
}

/**
 * Оператор деления
 * Формула: (a/b) / (c/d) = (a*d) / (b*c)
 */
Fraction Fraction::operator/(const Fraction& other) const {
    if (other.numerator == 0) {
        throw std::invalid_argument("Oshibka: Delenie na nol!");
    }
    return Fraction(
        numerator * other.denominator,
        denominator * other.numerator
    );
}

/**
 * Оператор равенства
 */
bool Fraction::operator==(const Fraction& other) const {
    return numerator == other.numerator && denominator == other.denominator;
}

/**
 * Оператор неравенства
 */
bool Fraction::operator!=(const Fraction& other) const {
    return !(*this == other);
}

/**
 * Оператор меньше
 * Сравниваем дроби приводя к общему знаменателю
 */
bool Fraction::operator<(const Fraction& other) const {
    return numerator * other.denominator < other.numerator * denominator;
}

/**
 * Оператор больше
 */
bool Fraction::operator>(const Fraction& other) const {
    return other < *this;
}

/**
 * Оператор меньше или равно
 */
bool Fraction::operator<=(const Fraction& other) const {
    return !(*this > other);
}

/**
 * Оператор больше или равно
 */
bool Fraction::operator>=(const Fraction& other) const {
    return !(*this < other);
}

/**
 * Оператор вывода в консоль
 */
std::ostream& operator<<(std::ostream& os, const Fraction& f) {
    if (f.denominator == 1) {
        // Если знаменатель = 1, выводим только числитель
        os << f.numerator;
    }
    else if (std::abs(f.numerator) > std::abs(f.denominator)) {
        // Выделяем целую часть для неправильных дробей
        int integer = f.numerator / f.denominator;
        int remainder = std::abs(f.numerator % f.denominator);
        if (remainder == 0) {
            os << integer;
        }
        else {
            int sign = (f.numerator < 0) ? -1 : 1;
            os << integer << " " << remainder * sign << "/" << f.denominator;
        }
    }
    else {
        // Правильная дробь - выводим как числитель/знаменатель
        os << f.numerator << "/" << f.denominator;
    }
    return os;
}

/**
 * Оператор ввода из консоли
 * Ожидает формат: числитель/знаменатель (например: 3/4)
 */
std::istream& operator>>(std::istream& is, Fraction& f) {
    char slash;
    is >> f.numerator >> slash >> f.denominator;
    if (f.denominator == 0) {
        throw std::invalid_argument("Oshibka: Znamenatel ne mozhet byt nulyom!");
    }
    f.reduce();
    return is;
}

/**
 * Преобразование в десятичную дробь
 */
double Fraction::toDouble() const {
    return static_cast<double>(numerator) / denominator;
}