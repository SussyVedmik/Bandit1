#include "Bandit.h"
#include <iostream>
using namespace std;

int main() {
    Bandit slotMachine;
    char input;
    setlocale(LC_ALL, "Russian");

    cout << "Добро пожаловать в игру 'Однорукий бандит'!" << endl;
    cout << "Нажмите Enter для вращения барабанов (или 'q' для выхода)." << endl;

    while (true) {
        cout << "\nВаш текущий баланс: " << slotMachine.getBalance() << " очков." << endl;
        cout << "Вращаем барабаны... ";
        cin.get(input);

        if (input == 'q') break;

        slotMachine.spin();
        slotMachine.displayResult();

        slotMachine.checkWin();
    }

    cout << "Спасибо за игру! Ваш финальный баланс: " << slotMachine.getBalance() << " очков." << endl;
    return 0;
}
