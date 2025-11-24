#include <iostream>
using namespace std;

int main() {
    // 1. Произведение всех целых чисел от 8 до 15
    long long product1 = 1;
    // Используем long long вместо int, так как произведение может быть очень большим
    for (int i = 8; i <= 15; i++) {
        product1 *= i;
    }
    cout << "1. Произведение чисел от 8 до 15: " << product1 << endl;

    // 2. Произведение всех целых чисел от a до 20
    int a;
    cout << "\nВведите число a (1 < a < 20): ";
    cin >> a;

    if (a <= 1 || a >= 20) {
        cout << "Ошибка: a должно быть в диапазоне 1 < a < 20!" << endl;
        return 1;
    }

    long long product2 = 1;
    for (int i = a; i <= 20; i++) {
        product2 *= i;
    }
    cout << "2. Произведение чисел от " << a << " до 20: " << product2 << endl;

    // 3. Произведение всех целых чисел от 1 до b
    int b;
    cout << "\nВведите число b (1 < b < 20): ";
    cin >> b;

    if (b <= 1 || b >= 20) {
        cout << "Ошибка: b должно быть в диапазоне 1 < b < 20!" << endl;
        return 1;
    }

    long long product3 = 1;
    for (int i = 1; i <= b; i++) {
        product3 *= i;
    }
    cout << "3. Произведение чисел от 1 до " << b << ": " << product3 << endl;

    // 4. Произведение всех целых чисел от a до b
    // Используем новые переменные, чтобы не конфликтовать с предыдущими
    int start, end;
    cout << "\nВведите числа start и end (end >= start): ";
    cin >> start >> end;

    if (end < start) {
        cout << "Ошибка: end должно быть больше или равно start!" << endl;
        return 1;
    }

    long long product4 = 1;
    cout << "Вычисляем произведение от " << start << " до " << end << ":" << endl;

    for (int i = start; i <= end; i++) {
        cout << "Умножаем: " << product4 << " * " << i;
        product4 *= i;
        cout << " = " << product4 << endl;
    }

    cout << "4. Произведение чисел от " << start << " до " << end << ": " << product4 << endl;

    return 0;
}