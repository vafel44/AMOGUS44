#include "Vector3D.h"
#include <cmath>
#include <stdexcept>

// Инициализация статического счётчика
int Vector3D::vectorCount = 0;

/**
 * Конструктор с параметрами
 */
Vector3D::Vector3D(double x, double y, double z) : coords{ x, y, z } {
    vectorCount++;  // Увеличиваем счётчик при создании
}

/**
 * Конструктор копирования
 */
Vector3D::Vector3D(const Vector3D& other) {
    // Копируем координаты
    coords[0] = other.coords[0];
    coords[1] = other.coords[1];
    coords[2] = other.coords[2];
    vectorCount++;  // Увеличиваем счётчик при копировании
}

/**
 * Деструктор
 */
Vector3D::~Vector3D() {
    vectorCount--;  // Уменьшаем счётчик при удалении
}

/**
 * Статический метод для получения количества векторов
 */
int Vector3D::getVectorCount() {
    return vectorCount;
}

/**
 * Оператор доступа по индексу (для изменения)
 * @param index индекс (0 для x, 1 для y, 2 для z)
 * @return ссылка на координату
 */
double& Vector3D::operator[](int index) {
    // Проверка границ
    if (index < 0 || index > 2) {
        throw std::out_of_range("Oshibka: Indeks dolzhen byt 0, 1 ili 2!");
    }
    return coords[index];
}

/**
 * Оператор доступа по индексу (для чтения)
 */
const double& Vector3D::operator[](int index) const {
    if (index < 0 || index > 2) {
        throw std::out_of_range("Oshibka: Indeks dolzhen byt 0, 1 ili 2!");
    }
    return coords[index];
}

/**
 * Векторная сумма
 * Складываем соответствующие координаты
 */
Vector3D Vector3D::operator+(const Vector3D& other) const {
    return Vector3D(
        coords[0] + other.coords[0],
        coords[1] + other.coords[1],
        coords[2] + other.coords[2]
    );
}

/**
 * Векторная разность
 * Вычитаем соответствующие координаты
 */
Vector3D Vector3D::operator-(const Vector3D& other) const {
    return Vector3D(
        coords[0] - other.coords[0],
        coords[1] - other.coords[1],
        coords[2] - other.coords[2]
    );
}

/**
 * Скалярное произведение
 * Формула: a·b = a.x*b.x + a.y*b.y + a.z*b.z
 */
double Vector3D::operator*(const Vector3D& other) const {
    return coords[0] * other.coords[0] +
        coords[1] * other.coords[1] +
        coords[2] * other.coords[2];
}

/**
 * Умножение на скаляр
 * Умножаем каждую координату на число
 */
Vector3D Vector3D::operator*(double scalar) const {
    return Vector3D(
        coords[0] * scalar,
        coords[1] * scalar,
        coords[2] * scalar
    );
}

/**
 * Умножение скаляра на вектор (дружественная функция)
 * Позволяет писать 5 * v
 */
Vector3D operator*(double scalar, const Vector3D& v) {
    return v * scalar;
}

/**
 * Составной оператор +=
 * Прибавляет другой вектор к текущему
 */
Vector3D& Vector3D::operator+=(const Vector3D& other) {
    coords[0] += other.coords[0];
    coords[1] += other.coords[1];
    coords[2] += other.coords[2];
    return *this;  // Возвращаем ссылку на текущий объект
}

/**
 * Составной оператор -=
 * Вычитает другой вектор из текущего
 */
Vector3D& Vector3D::operator-=(const Vector3D& other) {
    coords[0] -= other.coords[0];
    coords[1] -= other.coords[1];
    coords[2] -= other.coords[2];
    return *this;
}

/**
 * Составной оператор *=
 * Умножает текущий вектор на скаляр
 */
Vector3D& Vector3D::operator*=(double scalar) {
    coords[0] *= scalar;
    coords[1] *= scalar;
    coords[2] *= scalar;
    return *this;
}

/**
 * Префиксная форма инкремента (++v)
 * Увеличиваем все координаты на 1 и возвращаем изменённый вектор
 */
Vector3D& Vector3D::operator++() {
    coords[0]++;
    coords[1]++;
    coords[2]++;
    return *this;
}

/**
 * Постфиксная форма инкремента (v++)
 * Создаём копию, увеличиваем оригинал, возвращаем копию
 */
Vector3D Vector3D::operator++(int) {
    Vector3D temp = *this;  // Сохраняем старое значение
    coords[0]++;
    coords[1]++;
    coords[2]++;
    return temp;  // Возвращаем старое значение
}

/**
 * Префиксная форма декремента (--v)
 * Уменьшаем все координаты на 1 и возвращаем изменённый вектор
 */
Vector3D& Vector3D::operator--() {
    coords[0]--;
    coords[1]--;
    coords[2]--;
    return *this;
}

/**
 * Постфиксная форма декремента (v--)
 * Создаём копию, уменьшаем оригинал, возвращаем копию
 */
Vector3D Vector3D::operator--(int) {
    Vector3D temp = *this;
    coords[0]--;
    coords[1]--;
    coords[2]--;
    return temp;
}

/**
 * Вычисление длины (модуля) вектора
 * Формула: |v| = sqrt(x? + y? + z?)
 */
double Vector3D::length() const {
    return std::sqrt(coords[0] * coords[0] +
        coords[1] * coords[1] +
        coords[2] * coords[2]);
}

/**
 * Нормализация вектора
 * Возвращает единичный вектор в том же направлении
 * @throws std::runtime_error если вектор нулевой
 */
Vector3D Vector3D::normalize() const {
    double len = length();
    if (len == 0) {
        throw std::runtime_error("Oshibka: Nevozmozhno normalizovat nulevoy vektor!");
    }
    return *this * (1.0 / len);  // Делим каждую координату на длину
}

/**
 * Вывод вектора на экран
 * Формат: (x, y, z)
 */
void Vector3D::print() const {
    std::cout << "(" << coords[0] << ", " << coords[1] << ", " << coords[2] << ")";
}