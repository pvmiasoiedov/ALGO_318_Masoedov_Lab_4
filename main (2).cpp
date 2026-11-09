#include <iostream>

using namespace std;


// ЗАВДАННЯ 1: Proc1 та Proc26


// Proc1: процедура, що обчислює третю степінь числа A і повертає через параметр B (дійсні числа)
void PowerA3(double A, double &B) {
    B = A * A * A;
}

// Proc26: функція Sign (X), що повертає -1, 0 або 1 для дійсного числа X
int Sign(double X) {
    if (X < 0) {
        return -1;
    } else if (X == 0) {
        return 0;
    } else {
        return 1;
    }
}

// Процедура для виконання Завдання 1 у меню
void Task1_Runner() {
    cout << "=== ВИКОНАННЯ ЗАВДАННЯ 1 ===" << endl;
    
    // Частина 1: Proc1 (знайти треті ступені п'яти даних чисел без циклів)
    cout << "\n--- Proc1 (Третя степінь для 5 чисел) ---" << endl;
    double n1, n2, n3, n4, n5;
    double res1, res2, res3, res4, res5;

    cout << "Введіть 5 дійсних чисел через пробіл: ";
    cin >> n1 >> n2 >> n3 >> n4 >> n5;

    PowerA3(n1, res1);
    PowerA3(n2, res2);
    PowerA3(n3, res3);
    PowerA3(n4, res4);
    PowerA3(n5, res5);

    cout << "Результати піднесення до 3-ї степені:" << endl;
    cout << n1 << "^3 = " << res1 << endl;
    cout << n2 << "^3 = " << res2 << endl;
    cout << n3 << "^3 = " << res3 << endl;
    cout << n4 << "^3 = " << res4 << endl;
    cout << n5 << "^3 = " << res5 << endl;

    // Частина 2: Proc26 (знайти Sign(A) + Sign(B))
    cout << "\n--- Proc26 (Значення Sign(A) + Sign(B)) ---" << endl;
    double A, B_val;
    cout << "Введіть число A: ";
    cin >> A;
    cout << "Введіть число B: ";
    cin >> B_val;

    int sumSign = Sign(A) + Sign(B_val);
    cout << "Sign(" << A << ") + Sign(" << B_val << ") = " << sumSign << endl;
}



// ЗАВДАННЯ 2: Integer35


// 1) Функція введення з перевіркою на коректність (години не можуть бути від'ємними)
bool in_Hours(int &pHours) {
    cout << "Введіть кількість годин (ціле невід'ємне число): ";
    cin >> pHours;
    
    // Перевірка помилок введення (наприклад, введення тексту) або від'ємного значення
    if (cin.fail() || pHours < 0) {
        cin.clear(); // скидаємо прапорець помилки
        cin.ignore(32767, '\n'); // очищаємо буфер введення
        return false; // дані некоректні
    }
    return true; // дані коректні
}

// 2) Функція підрахунку результату (повертає кількість діб, залишок годин передаємо за посиланням)
int calc_Days(int pHours, int &pRemHours) {
    pRemHours = pHours % 24;
    return pHours / 24;
}

// 3) Функція виведення результату в консоль
void out_Integer35(int days, int remHours) {
    cout << "Результат: Діб = " << days << ", залишок годин = " << remHours << endl;
}

// Процедура для виконання Завдання 2 у меню
void Task2_Runner() {
    cout << "=== ВИКОНАННЯ ЗАВДАННЯ 2 (Integer35) ===" << endl;
    int hours = 0;
    int remainder = 0;

    // Виклик функції введення та перевірка коректності
    if (!in_Hours(hours)) {
        cout << "Помилка: введено некоректні дані! Розрахунки не виконуються." << endl;
        return;
    }

    // Підрахунок і виведення
    int days = calc_Days(hours, remainder);
    out_Integer35(days, remainder);
}



// ЗАВДАННЯ 3: Меню вибору

void Task3_Menu() {
    int choice;
    do {
        cout << "\n===============================" << endl;
        cout << "           ГОЛОВНЕ МЕНЮ        " << endl;
        cout << "===============================" << endl;
        cout << "1. Завдання 1 (Proc1 та Proc26)" << endl;
        cout << "2. Завдання 2 (Integer35)" << endl;
        cout << "0. Вихід" << endl;
        cout << "Оберіть пункт меню (0-2): ";
        cin >> choice;

        switch (choice) {
            case 1:
                Task1_Runner();
                break;
            case 2:
                Task2_Runner();
                break;
            case 0:
                cout << "Вихід з програми. До побачення!" << endl;
                break;
            default:
                cout << "Невірний вибір! Будь ласка, оберіть від 0 до 2." << endl;
        }
    } while (choice != 0);
}



// ГОЛОВНА ФУНКЦІЯ MAIN

int main() {
    // Встановлення української локалі для коректного виведення в консоль
    setlocale(LC_ALL, "Ukrainian");

    // Запуск головного меню 
    Task3_Menu();

    return 0;
}