#include "Bandit.h"
#include <iostream>
using namespace std;

int main() {
    Bandit slotMachine;
    char input;
    setlocale(LC_ALL, "Russian");

    cout << "����� ���������� � ���� '��������� ������'!" << endl;
    cout << "������� Enter ��� �������� ��������� (��� 'q' ��� ������)." << endl;

    while (true) {
        cout << "\n��� ������� ������: " << slotMachine.getBalance() << " �����." << endl;
        cout << "������� ��������... ";
        cin.get(input);

        if (input == 'q') break;

        slotMachine.spin();
        slotMachine.displayResult();

        slotMachine.checkWin();
    }

    cout << "������� �� ����! ��� ��������� ������: " << slotMachine.getBalance() << " �����." << endl;
    return 0;
}
