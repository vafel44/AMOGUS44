#include <iostream>  // Для ввода/вывода
#include <string>    // Для работы со строками
#include <iomanip>   // Для форматирования вывода

/**
 * Класс Student представляет студента с его личными данными и успеваемостью
 * Демонстрирует принцип инкапсуляции: данные скрыты, доступ через методы
 */
class Student {
private:
    // Закрытые поля - скрываем детали реализации
    std::string fullName;  // Полное имя студента
    std::string group;     // Номер группы
    int grades[5];         // Массив оценок (ровно 5 предметов)

public:
    /**
     * Конструктор класса Student
     * @param fullName - полное имя студента
     * @param group - номер группы
     * @param grades - массив оценок (должен содержать 5 элементов)
     */
    Student(const std::string& fullName, const std::string& group, const int grades[5]) {
        // Инициализируем поля значениями, переданными в конструктор
        this->fullName = fullName;  // this-> указывает на поле текущего объекта
        this->group = group;

        // Копируем каждую оценку из переданного массива
        for (int i = 0; i < 5; i++) {
            this->grades[i] = grades[i];
        }
    }

    /**
     * Геттер для имени студента (только для чтения)
     * Метод помечен const, так как он не изменяет состояние объекта
     * @return полное имя студента
     */
    std::string getFullName() const {
        return fullName;
    }

    /**
     * Геттер для группы студента (только для чтения)
     * @return номер группы
     */
    std::string getGroup() const {
        return group;
    }

    /**
     * Вычисляет средний балл студента
     * @return среднее арифметическое всех оценок
     */
    double getAverageGrade() const {
        int sum = 0;  // Переменная для суммирования оценок

        // Суммируем все оценки
        for (int i = 0; i < 5; i++) {
            sum += grades[i];
        }

        // Возвращаем среднее значение (явно преобразуем в double для точности)
        return static_cast<double>(sum) / 5.0;
    }

    /**
     * Выводит полную информацию о студенте на экран
     * Метод только читает данные, поэтому помечен const
     */
    void displayInfo() const {
        std::cout << "========== Информация о студенте ==========" << std::endl;
        std::cout << "ФИО: " << fullName << std::endl;
        std::cout << "Группа: " << group << std::endl;

        // Выводим все оценки через запятую
        std::cout << "Оценки: ";
        for (int i = 0; i < 5; i++) {
            std::cout << grades[i];
            if (i < 4) std::cout << ", ";  // После последней оценки запятую не ставим
        }
        std::cout << std::endl;

        // Выводим средний балл с двумя знаками после запятой
        std::cout << std::fixed << std::setprecision(2);
        std::cout << "Средний балл: " << getAverageGrade() << std::endl;
        std::cout << "===========================================" << std::endl;
    }
};

/**
 * Пример использования класса Student
 */
int main() {
    // Создаем массив оценок для студента
    int grades[] = { 5, 4, 5, 3, 4 };  // 5 оценок по разным предметам
    setlocale(LC_ALL, "Russian");
    // Создаем объект Student с помощью конструктора
    Student student("Иванов Иван Иванович", "Группа 101", grades);

    // Выводим информацию о студенте
    student.displayInfo();

    // Пример использования геттеров
    std::cout << "\nДоступ к данным через геттеры:" << std::endl;
    std::cout << "Имя: " << student.getFullName() << std::endl;
    std::cout << "Группа: " << student.getGroup() << std::endl;

    return 0;  // Успешное завершение программы
}