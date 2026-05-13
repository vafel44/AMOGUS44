#include "Matrix.h"
#include <stdexcept>
#include <iomanip>

/**
 * Конструктор матрицы
 */
Matrix::Matrix(int r, int c) : rows(r), cols(c) {
    if (r < 0 || c < 0) {
        throw std::invalid_argument("Oshibka: Razmery matricy ne mogut byt otricatelnymi!");
    }
    data.resize(rows, std::vector<int>(cols, 0));  // Выделяем память и заполняем нулями
}

/**
 * Конструктор копирования
 */
Matrix::Matrix(const Matrix& other) : rows(other.rows), cols(other.cols) {
    data = other.data;  // Копируем данные
}

/**
 * Оператор доступа к элементу (для изменения)
 * @param i номер строки
 * @param j номер столбца
 * @return ссылка на элемент
 */
int& Matrix::operator()(int i, int j) {
    if (i < 0 || i >= rows || j < 0 || j >= cols) {
        throw std::out_of_range("Oshibka: Indeks vne diapazona matricy!");
    }
    return data[i][j];
}

/**
 * Оператор доступа к элементу (для чтения)
 */
const int& Matrix::operator()(int i, int j) const {
    if (i < 0 || i >= rows || j < 0 || j >= cols) {
        throw std::out_of_range("Oshibka: Indeks vne diapazona matricy!");
    }
    return data[i][j];
}

/**
 * Сложение матриц
 * Требует одинаковых размеров
 */
Matrix Matrix::operator+(const Matrix& other) const {
    if (rows != other.rows || cols != other.cols) {
        throw std::invalid_argument("Oshibka: Razmery matric dolzhny sovpadat!");
    }

    Matrix result(rows, cols);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result.data[i][j] = data[i][j] + other.data[i][j];
        }
    }
    return result;
}

/**
 * Вычитание матриц
 * Требует одинаковых размеров
 */
Matrix Matrix::operator-(const Matrix& other) const {
    if (rows != other.rows || cols != other.cols) {
        throw std::invalid_argument("Oshibka: Razmery matric dolzhny sovpadat!");
    }

    Matrix result(rows, cols);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result.data[i][j] = data[i][j] - other.data[i][j];
        }
    }
    return result;
}

/**
 * Умножение матриц
 * Требует: количество столбцов первой = количеству строк второй
 */
Matrix Matrix::operator*(const Matrix& other) const {
    if (cols != other.rows) {
        throw std::invalid_argument("Oshibka: Kolichestvo stolbcov pervoy matricy dolzhno ravnyatsya kolichestvu strok vtoroy!");
    }

    Matrix result(rows, other.cols);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < other.cols; j++) {
            int sum = 0;  // Сумма произведений
            for (int k = 0; k < cols; k++) {
                sum += data[i][k] * other.data[k][j];
            }
            result.data[i][j] = sum;
        }
    }
    return result;
}

/**
 * Умножение матрицы на скаляр
 */
Matrix Matrix::operator*(int scalar) const {
    Matrix result(rows, cols);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result.data[i][j] = data[i][j] * scalar;
        }
    }
    return result;
}

/**
 * Деление матрицы на скаляр
 */
Matrix Matrix::operator/(int scalar) const {
    if (scalar == 0) {
        throw std::invalid_argument("Oshibka: Delenie na nol!");
    }

    Matrix result(rows, cols);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result.data[i][j] = data[i][j] / scalar;
        }
    }
    return result;
}

/**
 * Оператор равенства
 * Сравнивает поэлементно
 */
bool Matrix::operator==(const Matrix& other) const {
    if (rows != other.rows || cols != other.cols) {
        return false;
    }

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (data[i][j] != other.data[i][j]) {
                return false;
            }
        }
    }
    return true;
}

/**
 * Оператор неравенства
 */
bool Matrix::operator!=(const Matrix& other) const {
    return !(*this == other);
}

/**
 * Оператор меньше
 * Сравнивает по сумме всех элементов матрицы
 */
bool Matrix::operator<(const Matrix& other) const {
    int sum1 = 0, sum2 = 0;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            sum1 += data[i][j];
        }
    }
    for (int i = 0; i < other.rows; i++) {
        for (int j = 0; j < other.cols; j++) {
            sum2 += other.data[i][j];
        }
    }
    return sum1 < sum2;
}

/**
 * Оператор больше
 */
bool Matrix::operator>(const Matrix& other) const {
    return other < *this;
}

/**
 * Составной оператор +=
 */
Matrix& Matrix::operator+=(const Matrix& other) {
    *this = *this + other;
    return *this;
}

/**
 * Составной оператор -=
 */
Matrix& Matrix::operator-=(const Matrix& other) {
    *this = *this - other;
    return *this;
}

/**
 * Составной оператор *=
 */
Matrix& Matrix::operator*=(int scalar) {
    *this = *this * scalar;
    return *this;
}

/**
 * Составной оператор /=
 */
Matrix& Matrix::operator/=(int scalar) {
    *this = *this / scalar;
    return *this;
}

/**
 * Заполнение матрицы одним значением
 */
void Matrix::fill(int value) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            data[i][j] = value;
        }
    }
}

/**
 * Транспонирование матрицы
 * Меняет строки и столбцы местами
 */
Matrix Matrix::transpose() const {
    Matrix result(cols, rows);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result.data[j][i] = data[i][j];
        }
    }
    return result;
}

/**
 * Вычисление определителя матрицы
 * Работает только для квадратных матриц
 */
int Matrix::determinant() const {
    if (rows != cols) {
        throw std::invalid_argument("Oshibka: Opredelitel mozhno vychislit tolko dlya kvadratnoy matricy!");
    }

    // Для матрицы 1x1 определитель = единственному элементу
    if (rows == 1) {
        return data[0][0];
    }

    // Для матрицы 2x2: a*d - b*c
    if (rows == 2) {
        return data[0][0] * data[1][1] - data[0][1] * data[1][0];
    }

    // Для матриц больше 2x2 используем разложение по первой строке
    int det = 0;
    for (int j = 0; j < cols; j++) {
        // Создаём подматрицу без первой строки и j-го столбца
        Matrix submatrix(rows - 1, cols - 1);
        for (int i = 1; i < rows; i++) {
            for (int k = 0, colIdx = 0; k < cols; k++) {
                if (k == j) continue;  // Пропускаем j-й столбец
                submatrix(i - 1, colIdx++) = data[i][k];
            }
        }
        // Знак (-1)^j и рекурсивный вызов
        det += (j % 2 == 0 ? 1 : -1) * data[0][j] * submatrix.determinant();
    }
    return det;
}

/**
 * Оператор вывода матрицы в консоль
 */
std::ostream& operator<<(std::ostream& os, const Matrix& m) {
    for (int i = 0; i < m.rows; i++) {
        for (int j = 0; j < m.cols; j++) {
            os << std::setw(8) << m.data[i][j] << " ";
        }
        os << std::endl;
    }
    return os;
}

/**
 * Оператор ввода матрицы из консоли
 */
std::istream& operator>>(std::istream& is, Matrix& m) {
    for (int i = 0; i < m.rows; i++) {
        for (int j = 0; j < m.cols; j++) {
            is >> m.data[i][j];
        }
    }
    return is;
}