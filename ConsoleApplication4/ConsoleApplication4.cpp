#include <iostream>  // Для ввода/вывода
#include <string>    // Для работы со строками
#include <iomanip>   // Для форматирования вывода

/**
 * Класс Product представляет товар на складе
 * Использует публичные поля (автосвойства в терминах C#)
 * Демонстрирует простой подход к созданию класса-сущности
 */
class Product {
public:
    // Публичные поля (автосвойства) - доступны напрямую
    std::string Name;   // Название товара
    double Price;       // Цена товара
    int Quantity;       // Количество товара на складе

    /**
     * Конструктор класса Product
     * @param name - название товара
     * @param price - цена товара
     * @param quantity - количество на складе
     */
    Product(const std::string& name, double price, int quantity) {
        Name = name;          // Инициализируем название
        Price = price;        // Инициализируем цену
        Quantity = quantity;  // Инициализируем количество
    }

    /**
     * Рассчитывает общую стоимость товара на складе
     * @return цена * количество (общая стоимость)
     */
    double getTotalValue() const {
        // Простое умножение цены на количество
        return Price * Quantity;
    }

    /**
     * Продажа товара (уменьшение количества на складе)
     * @param amount - количество товара для продажи
     * @return true - если продажа успешна, false - если недостаточно товара
     */
    bool sell(int amount) {
        // Проверяем, что количество для продажи положительное
        if (amount <= 0) {
            std::cout << "Ошибка: Количество для продажи должно быть положительным!" << std::endl;
            return false;
        }

        // Проверяем, достаточно ли товара на складе
        if (amount > Quantity) {
            std::cout << std::fixed << std::setprecision(2);
            std::cout << "✗ Ошибка: Недостаточно товара на складе!" << std::endl;
            std::cout << "  Доступно: " << Quantity << " шт." << std::endl;
            std::cout << "  Запрошено: " << amount << " шт." << std::endl;
            return false;  // Продажа не удалась
        }

        // Уменьшаем количество товара
        Quantity -= amount;

        // Выводим информацию об успешной продаже
        std::cout << std::fixed << std::setprecision(2);
        std::cout << "✓ Продажа выполнена успешно!" << std::endl;
        std::cout << "  Товар: " << Name << std::endl;
        std::cout << "  Продано: " << amount << " шт." << std::endl;
        std::cout << "  Осталось: " << Quantity << " шт." << std::endl;
        std::cout << "  Сумма продажи: " << (Price * amount) << " руб." << std::endl;

        return true;  // Продажа успешна
    }

    /**
     * Выводит полную информацию о товаре
     */
    void displayInfo() const {
        std::cout << "========== Информация о товаре ==========" << std::endl;
        std::cout << "Название: " << Name << std::endl;
        std::cout << std::fixed << std::setprecision(2);
        std::cout << "Цена: " << Price << " руб." << std::endl;
        std::cout << "Количество на складе: " << Quantity << " шт." << std::endl;
        std::cout << "Общая стоимость: " << getTotalValue() << " руб." << std::endl;
        std::cout << "=========================================" << std::endl;
    }
};

/**
 * Альтернативная версия класса Product с приватными полями
 * Более строгий подход к инкапсуляции
 */
class ProductEncapsulated {
private:
    // Приватные поля - скрываем детали реализации
    std::string name;
    double price;
    int quantity;

public:
    /**
     * Конструктор
     */
    ProductEncapsulated(const std::string& name, double price, int quantity) {
        this->name = name;
        this->price = price;
        this->quantity = quantity;
    }

    // Геттеры (только для чтения)
    std::string getName() const { return name; }
    double getPrice() const { return price; }
    int getQuantity() const { return quantity; }

    // Сеттеры (с проверкой корректности)
    void setName(const std::string& name) {
        if (!name.empty()) this->name = name;
    }

    void setPrice(double price) {
        if (price >= 0) this->price = price;
    }

    void setQuantity(int quantity) {
        if (quantity >= 0) this->quantity = quantity;
    }

    /**
     * Общая стоимость
     */
    double getTotalValue() const {
        return price * quantity;
    }

    /**
     * Продажа товара
     */
    bool sell(int amount) {
        if (amount <= 0) {
            std::cout << "Ошибка: Количество должно быть положительным!" << std::endl;
            return false;
        }

        if (amount > quantity) {
            std::cout << "Ошибка: Недостаточно товара!" << std::endl;
            return false;
        }

        quantity -= amount;
        std::cout << "Продано " << amount << " шт. Осталось: " << quantity << " шт." << std::endl;
        return true;
    }
};

/**
 * Пример использования класса Product
 */
int main() {
    // Создаем товар: ноутбук по цене 50000 руб, 10 штук на складе
    Product product("Ноутбук", 50000.0, 10);
    setlocale(LC_ALL, "Russian");
    // Выводим информацию о товаре
    product.displayInfo();

    std::cout << std::endl;

    // Продаем 3 ноутбука
    product.sell(3);

    std::cout << std::endl;

    // Выводим обновленную информацию
    std::cout << "После продажи:" << std::endl;
    std::cout << "Осталось: " << product.Quantity << " шт." << std::endl;
    std::cout << "Общая стоимость: " << product.getTotalValue() << " руб." << std::endl;

    std::cout << std::endl;

    // Пытаемся продать больше, чем есть (ошибка)
    product.sell(10);

    std::cout << std::endl;

    // Демонстрация работы с публичными полями
    std::cout << "Изменение цены через прямое обращение к полю:" << std::endl;
    product.Price = 45000.0;  // Устраиваем распродажу
    std::cout << "Новая цена: " << product.Price << " руб." << std::endl;
    std::cout << "Общая стоимость: " << product.getTotalValue() << " руб." << std::endl;

    return 0;
}