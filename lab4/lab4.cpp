#include <iostream>
#include <iomanip>
#include <cmath>

// Функция для очистки буфера ввода при ошибке или некорректном вводе
void clearInputBuffer() {
    std::cin.clear();
    std::cin.ignore(32767, '\n');
}

//--------------------------------------------------------------------------------------------------
// УРОВЕНЬ 1 (Базовый - Вариант 13)
// Задание: По числу (1-4) вывести математическую операцию: 1-+, 2--, 3-*, 4-/
//--------------------------------------------------------------------------------------------------
void runTask1() {
    std::cout << "\n==========================================\n";
    std::cout << "[ БАЗОВЫЙ УРОВЕНЬ: Выбор математической операции ]\n";
    std::cout << "==========================================\n";

    int code = 0;
    std::cout << "Введите код операции (1-4): ";

    while (!(std::cin >> code)) {
        std::cout << "Ошибка! Введите целое число от 1 до 4: ";
        clearInputBuffer();
    }

    switch (code) {
        case 1:
            std::cout << "Операция №1 соответствует символу: +\n";
            break;
        case 2:
            std::cout << "Операция №2 соответствует символу: -\n";
            break;
        case 3:
            std::cout << "Операция №3 соответствует символу: *\n";
            break;
        case 4:
            std::cout << "Операция №4 соответствует символу: /\n";
            break;
        default:
            std::cout << "Ошибка: введите число строго в диапазоне от 1 до 4!\n";
            break;
    }
}

//--------------------------------------------------------------------------------------------------
// УРОВЕНЬ 2 (Средний - Вариант 13)
// Задание: Меню программы: 1-Запуск, 2-Настройки, 3-Справка, 0-Выход. Вывод сообщений.
//--------------------------------------------------------------------------------------------------
void runTask2() {
    std::cout << "\n==========================================\n";
    std::cout << "[ СРЕДНИЙ УРОВЕНЬ: Меню программы ]\n";
    std::cout << "==========================================\n";
    std::cout << "1 — Запуск\n";
    std::cout << "2 — Настройки\n";
    std::cout << "3 — Справка\n";
    std::cout << "0 — Выход\n";
    std::cout << "Выберите пункт меню (0-3): ";

    int menuChoice = 0;
    while (!(std::cin >> menuChoice)) {
        std::cout << "Ошибка ввода! Введите цифру от 0 до 3: ";
        clearInputBuffer();
    }

    switch (menuChoice) {
        case 1:
            std::cout << "Статус: Программа успешно запущена!\n";
            break;
        case 2:
            std::cout << "Статус: Открыты настройки приложения.\n";
            break;
        case 3:
            std::cout << "Справка: Данная программа разработана в рамках ЛР №4 (Вариант 13).\n";
            break;
        case 0:
            std::cout << "Статус: Возврат из меню.\n";
            break;
        default:
            std::cout << "Ошибка: Неверный пункт меню! Выберите от 0 до 3.\n";
            break;
    }
}

//--------------------------------------------------------------------------------------------------
// УРОВЕНЬ 3 (Повышенный - Вариант 13)
// Задание: Калькулятор кредита: меню (1-Аннуитетный, 2-Дифференцированный, 3-Досрочное погашение)
//--------------------------------------------------------------------------------------------------
void runTask3() {
    std::cout << "\n==========================================\n";
    std::cout << "[ ПОВЫШЕННЫЙ УРОВЕНЬ: Калькулятор кредита ]\n";
    std::cout << "==========================================\n";
    std::cout << "1 — Аннуитетный платёж\n";
    std::cout << "2 — Дифференцированный платёж\n";
    std::cout << "3 — Досрочное погашение\n";
    std::cout << "Выберите тип расчета (1-3): ";

    int calcChoice = 0;
    while (!(std::cin >> calcChoice)) {
        std::cout << "Ошибка ввода! Введите число от 1 до 3: ";
        clearInputBuffer();
    }

    if (calcChoice < 1 || calcChoice > 3) {
        std::cout << "Ошибка: неверный выбор режима расчета кредита!\n";
        return;
    }

    double loanAmount = 0.0;
    double annualRate = 0.0;
    int months = 0;

    std::cout << "Введите сумму кредита (руб.): ";
    while (!(std::cin >> loanAmount) || loanAmount <= 0) {
        std::cout << "Ошибка! Сумма должна быть больше 0. Повторите ввод: ";
        clearInputBuffer();
    }

    std::cout << "Введите годовую процентную ставку (%): ";
    while (!(std::cin >> annualRate) || annualRate < 0) {
        std::cout << "Ошибка! Ставка не может быть отрицательной. Повторите ввод: ";
        clearInputBuffer();
    }

    std::cout << "Введите срок кредита (месяцев): ";
    while (!(std::cin >> months) || months <= 0) {
        std::cout << "Ошибка! Срок должен быть целым положительным числом. Повторите ввод: ";
        clearInputBuffer();
    }

    std::cout << std::fixed << std::setprecision(2);

    switch (calcChoice) {
        case 1: { // Аннуитетный платёж
            double monthlyRate = (annualRate / 100.0) / 12.0;
            double annuityPayment = loanAmount * (monthlyRate * std::pow(1.0 + monthlyRate, months)) / 
                                    (std::pow(1.0 + monthlyRate, months) - 1.0);
            double totalPayment = annuityPayment * months;

            std::cout << "\n--- Результат: Аннуитетный платёж ---\n";
            std::cout << "Ежемесячный платёж: " << annuityPayment << " руб.\n";
            std::cout << "Общая сумма выплат: " << totalPayment << " руб.\n";
            break;
        }
        case 2: { // Дифференцированный платёж
            std::cout << "\n--- Результат: Дифференцированный платёж ---\n";
            double principalPart = loanAmount / months;
            double firstMonthPayment = principalPart + loanAmount * ((annualRate / 100.0) / 12.0);
            double lastMonthPayment = principalPart + principalPart * ((annualRate / 100.0) / 12.0);

            std::cout << "Платёж в первый месяц: " << firstMonthPayment << " руб.\n";
            std::cout << "Платёж в последний месяц: " << lastMonthPayment << " руб.\n";
            break;
        }
        case 3: { // Досрочное погашение
            double monthlyRate = (annualRate / 100.0) / 12.0;
            double basePayment = loanAmount * (monthlyRate * std::pow(1.0 + monthlyRate, months)) / 
                                 (std::pow(1.0 + monthlyRate, months) - 1.0);

            double extraPayment = 0.0;
            std::cout << "Введите сумму досрочного внесения (единоразово): ";
            while (!(std::cin >> extraPayment) || extraPayment < 0) {
                std::cout << "Ошибка! Сумма не может быть отрицательной: ";
                clearInputBuffer();
            }

            double remainingDebt = loanAmount - extraPayment;
            if (remainingDebt <= 0) {
                std::cout << "Кредит полностью погашен досрочно!\n";
            } else {
                std::cout << "\n--- Результат: Досрочное погашение ---\n";
                std::cout << "Остаток долга после досрочного взноса: " << remainingDebt << " руб.\n";
                std::cout << "Базовый ежемесячный платёж сохранен: " << basePayment << " руб.\n";
            }
            break;
        }
        default:
            std::cout << "Непредвиденная ошибка в выборе режима.\n";
            break;
    }
}

//--------------------------------------------------------------------------------------------------
// Главная функция с консольным меню
//--------------------------------------------------------------------------------------------------
int main() {
    setlocale(LC_ALL, "ru");

    int choice = 0;
    do {
        std::cout << "\n==========================================\n";
        std::cout << "   ЛАБОРАТОРНАЯ РАБОТА №4 (ВАРИАНТ 13)\n";
        std::cout << "==========================================\n";
        std::cout << "1 — Базовый уровень (Выбор математической операции)\n";
        std::cout << "2 — Средний уровень (Меню программы)\n";
        std::cout << "3 — Повышенный уровень (Калькулятор кредита)\n";
        std::cout << "4 — Выполнить ВСЕ уровни подряд\n";
        std::cout << "0 — Выход\n";
        std::cout << "Выберите действие (0-4): ";

        if (!(std::cin >> choice)) {
            clearInputBuffer();
            choice = -1;
            continue;
        }

        switch (choice) {
            case 1:
                runTask1();
                break;
            case 2:
                runTask2();
                break;
            case 3:
                runTask3();
                break;
            case 4:
                runTask1();
                runTask2();
                runTask3();
                break;
            case 0:
                std::cout << "\nЗавершение работы программы.\n";
                break;
            default:
                std::cout << "\nНекорректный выбор! Введите число от 0 до 4.\n";
                break;
        }
    } while (choice != 0);

    return 0;
}