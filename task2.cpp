#include <iostream>
#include <utility>
#include <cmath>

using namespace std;

int main() {
    // Используем int вместо byte
    pair<int, int> positionA, positionB;

    // Ввод координат с клавиатуры
    cout << "Введите координаты позиции A (a b): ";
    cin >> positionA.first >> positionA.second; //то что мы вводим
    cout << "Введите координаты позиции B (c d): "; //вывод
    cin >> positionB.first >> positionB.second;

    // ПРОВЕРКА КОРРЕКТНОСТИ ВВОДА
    if (positionA.first < 1 || positionA.first > 8 ||
        positionA.second < 1 || positionA.second > 8 ||
        positionB.first < 1 || positionB.first > 8 ||
        positionB.second < 1 || positionB.second > 8) {
        cout << "Ошибка: координаты должны быть от 1 до 8!" << endl;
        return 1;
    }

    // 1. УСЛОВИЕ ДЛЯ ЛАДЬИ
    bool rook_threat = (positionA.first == positionB.first) ||
                      (positionA.second == positionB.second);

    // 2. УСЛОВИЕ ДЛЯ СЛОНА
    bool bishop_threat = (abs(positionA.first - positionB.first) ==
                         abs(positionA.second - positionB.second));

    // 3. УСЛОВИЕ ДЛЯ КОРОЛЯ
    bool king_move = (abs(positionA.first - positionB.first) <= 1) &&
                    (abs(positionA.second - positionB.second) <= 1);

    // 4. УСЛОВИЕ ДЛЯ ФЕРЗЯ
    bool queen_threat = rook_threat || bishop_threat;

    // 5. УСЛОВИЯ ДЛЯ БЕЛОЙ ПЕШКИ
    bool pawn_normal = (positionA.first == positionB.first) &&
                      (positionB.second == positionA.second + 1);

    bool pawn_capture = (abs(positionA.first - positionB.first) == 1) &&
                       (positionB.second == positionA.second + 1);

    // ВЫВОД РЕЗУЛЬТАТОВ
    cout << "\n--- РЕЗУЛЬТАТЫ ---" << endl;
    cout << "Ладья угрожает полю B: " << (rook_threat ? "ДА" : "НЕТ") << endl;
    cout << "Слон угрожает полю B: " << (bishop_threat ? "ДА" : "НЕТ") << endl;
    cout << "Король может пойти на B: " << (king_move ? "ДА" : "НЕТ") << endl;
    cout << "Ферзь угрожает полю B: " << (queen_threat ? "ДА" : "НЕТ") << endl;
    cout << "Пешка может пойти на B (обычный ход): " << (pawn_normal ? "ДА" : "НЕТ") << endl;
    cout << "Пешка может пойти на B (взятие): " << (pawn_capture ? "ДА" : "НЕТ") << endl;

    return 0;
}