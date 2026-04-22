#include <iostream>  // Для ввода/вывода
#include <string>    // Для работы со строками
#include <iomanip>   // Для форматирования вывода (setprecision)

/**
 * Класс BankAccount представляет банковский счет
 * Демонстрирует инкапсуляцию и контроль доступа к данным
 */
class BankAccount {
private:
    // Закрытые поля - скрываем важную финансовую информацию
    std::string accountNumber;  // Номер счета (уникальный идентификатор)
    double balance;             // Текущий баланс счета
    std::string ownerName;      // Имя владельца счета

public:
    /**
     * Конструктор класса BankAccount
     * @param accountNumber - номер счета
     * @param ownerName - имя владельца
     * @param initialBalance - начальный баланс (по умолчанию 0)
     */
    BankAccount(const std::string& accountNumber, const std::string& ownerName, double initialBalance = 0.0) {
        this->accountNumber = accountNumber;  // Устанавливаем номер счета
        this->ownerName = ownerName;          // Устанавливаем имя владельца
        this->balance = initialBalance;       // Устанавливаем начальный баланс
    }

    /**
     * Геттер для номера счета (только чтение - номер нельзя изменить)
     * @return номер счета
     */
    std::string getAccountNumber() const {
        return accountNumber;
    }

    /**
     * Геттер для имени владельца
     * @return имя владельца счета
     */
    std::string getOwnerName() const {
        return ownerName;
    }

    /**
     * Геттер для баланса (только чтение - баланс меняется только через методы)
     * @return текущий баланс счета
     */
    double getBalance() const {
        return balance;
    }

    /**
     * Сеттер для имени владельца (чтение и запись)
     * @param ownerName - новое имя владельца
     */
    void setOwnerName(const std::string& ownerName) {
        // Проверяем, что имя не пустое
        if (!ownerName.empty()) {
            this->ownerName = ownerName;
        }
        else {
            std::cout << "Ошибка: Имя владельца не может быть пустым!" << std::endl;
        }
    }

    /**
     * Пополнение счета (депозит)
     * @param amount - сумма пополнения (должна быть положительной)
     */
    void deposit(double amount) {
        // Проверяем корректность суммы
        if (amount <= 0) {
            std::cout << "Ошибка: Сумма пополнения должна быть положительной!" << std::endl;
            return;  // Досрочно выходим из метода
        }

        // Увеличиваем баланс
        balance += amount;

        // Выводим информацию об операции (форматируем вывод до 2 знаков)
        std::cout << std::fixed << std::setprecision(2);
        std::cout << "✓ Счет пополнен на " << amount << " руб." << std::endl;
        std::cout << "  Текущий баланс: " << balance << " руб." << std::endl;
    }

    /**
     * Снятие средств со счета
     * @param amount - сумма снятия
     * @return true - если операция успешна, false - если недостаточно средств
     */
    bool withdraw(double amount) {
        // Проверяем корректность суммы
        if (amount <= 0) {
            std::cout << "Ошибка: Сумма снятия должна быть положительной!" << std::endl;
            return false;
        }

        // Проверяем, достаточно ли средств на счете
        if (amount > balance) {
            std::cout << std::fixed << std::setprecision(2);
            std::cout << "✗ Ошибка: Недостаточно средств!" << std::endl;
            std::cout << "  Доступно: " << balance << " руб." << std::endl;
            std::cout << "  Запрошено: " << amount << " руб." << std::endl;
            return false;  // Операция не выполнена
        }

        // Уменьшаем баланс
        balance -= amount;

        // Выводим информацию об успешной операции
        std::cout << std::fixed << std::setprecision(2);
        std::cout << "✓ Снято " << amount << " руб." << std::endl;
        std::cout << "  Текущий баланс: " << balance << " руб." << std::endl;
        return true;  // Операция выполнена успешно
    }

    /**
     * Выводит полную информацию о счете
     */
    void displayInfo() const {
        std::cout << "========== Информация о счете ==========" << std::endl;
        std::cout << "Номер счета: " << accountNumber << std::endl;
        std::cout << "Владелец: " << ownerName << std::endl;
        std::cout << std::fixed << std::setprecision(2);
        std::cout << "Баланс: " << balance << " руб." << std::endl;
        std::cout << "========================================" << std::endl;
    }
};

/**
 * Пример использования класса BankAccount
 */
int main() {
    // Создаем банковский счет с начальным балансом 1000 рублей
    BankAccount account("1234567890", "Иван Петров", 1000.0);
    setlocale(LC_ALL, "Russian");
    // Выводим информацию о счете
    account.displayInfo();

    std::cout << std::endl;

    // Пополняем счет
    account.deposit(500);

    std::cout << std::endl;

    // Снимаем деньги (успешная операция)
    account.withdraw(200);

    std::cout << std::endl;

    // Пытаемся снять больше, чем есть на счете (неуспешная операция)
    account.withdraw(2000);

    std::cout << std::endl;

    // Меняем имя владельца (демонстрация сеттера)
    account.setOwnerName("Петров Иван Иванович");

    // Выводим итоговую информацию
    std::cout << "Итоговая информация:" << std::endl;
    std::cout << "Владелец: " << account.getOwnerName() << std::endl;
    std::cout << "Баланс: " << account.getBalance() << " руб." << std::endl;

    return 0;
}