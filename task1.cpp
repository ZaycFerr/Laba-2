#include <iostream>
using namespace std;

int main() {
    int X, Y, Z;

    // Ввод чисел с клавиатуры
    cout << "Введите X: ";
    cin >> X;
    cout << "Введите Y: ";
    cin >> Y;
    cout << "Введите Z: ";
    cin >> Z;

    // ПРОВЕРКА ВСЕХ УСЛОВИЙ:

    // 1. Каждое из чисел X и Y нечетное
    // Нечетное число имеет остаток 1 при делении на 2
    bool condition1 = (X % 2 == 1) && (Y % 2 == 1);

    // 2. Только одно из чисел X и Y меньше 20
    // Используем XOR-логику: (X<20 и Y>=20) ИЛИ (X>=20 и Y<20)
    bool condition2 = ((X < 20) && (Y >= 20)) || ((X >= 20) && (Y < 20));

    // 3. Хотя бы одно из чисел X и Y равно нулю
    // Достаточно выполнения одного из условий
    bool condition3 = (X == 0) || (Y == 0);

    // 4. Каждое из чисел X, Y, Z отрицательное
    // Все три числа должны быть меньше нуля
    bool condition4 = (X < 0) && (Y < 0) && (Z < 0);

    // 5. Только одно из чисел X, Y и Z кратно пяти
    // Число кратно 5, если остаток от деления на 5 равен 0
    // Проверяем три возможных случая:
    bool multipleX = (X % 5 == 0);  // X кратно 5
    bool multipleY = (Y % 5 == 0);  // Y кратно 5
    bool multipleZ = (Z % 5 == 0);  // Z кратно 5

    // Только одно условие должно быть true, остальные false
    bool condition5 = (multipleX && !multipleY && !multipleZ) ||  // Только X кратно 5
                      (!multipleX && multipleY && !multipleZ) ||  // Только Y кратно 5
                      (!multipleX && !multipleY && multipleZ);    // Только Z кратно 5

    // 6. Хотя бы одно из чисел X, Y, Z больше 100
    // Достаточно выполнения одного из условий
    bool condition6 = (X > 100) || (Y > 100) || (Z > 100);

    // ОБЪЕДИНЕНИЕ ВСЕХ УСЛОВИЙ
    // Все условия должны выполняться одновременно
    bool finalCondition = condition1 && condition2 && condition3 &&
                         condition4 && condition5 && condition6;

    // ВЫВОД РЕЗУЛЬТАТА
    if (finalCondition) {
        cout << "condition is true" << endl;
    } else {
        cout << "condition is false" << endl;
    }

    // ДОПОЛНИТЕЛЬНО: Вывод информации о выполнении каждого условия
    cout << "\n--- Детальная информация ---" << endl;
    cout << "1. X и Y нечетные: " << (condition1 ? "да" : "нет") << endl;
    cout << "2. Только одно из X,Y < 20: " << (condition2 ? "да" : "нет") << endl;
    cout << "3. X или Y = 0: " << (condition3 ? "да" : "нет") << endl;
    cout << "4. Все отрицательные: " << (condition4 ? "да" : "нет") << endl;
    cout << "5. Только одно кратно 5: " << (condition5 ? "да" : "нет") << endl;
    cout << "6. Хотя бы одно > 100: " << (condition6 ? "да" : "нет") << endl;

    return 0;
}