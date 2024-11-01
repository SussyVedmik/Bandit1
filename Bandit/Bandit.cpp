#include "Bandit.h"
#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

Bandit::Bandit() {
    symbols = { "CH", "LE", "GR", "ST", "BE" };
    reels.resize(NUM_REELS);
    balance = 0;
    srand(static_cast<unsigned int>(time(0)));
}

void Bandit::spin() {
    for (int i = 0; i < NUM_REELS; ++i) {
        reels[i] = rand() % NUM_SYMBOLS;
    }
}

void Bandit::displayResult() const {
    cout << "Результат: ";
    for (int i = 0; i < NUM_REELS; ++i) {
        cout << symbols[reels[i]] << " ";
    }
    cout << endl;
}

bool Bandit::checkWin() {
    int winnings = calculateWinnings();
    if (winnings > 0) {
        balance += winnings;
        cout << "Поздравляем! Вы выиграли " << winnings << " очков!" << endl;
        return true;
    }
    else {
        cout << "Попробуйте снова." << endl;
        return false;
    }
}

int Bandit::calculateWinnings() const {
    if (reels[0] == reels[1] && reels[1] == reels[2]) {
        if (symbols[reels[0]] == "CH") return 100;
        if (symbols[reels[0]] == "LE") return 50;
        if (symbols[reels[0]] == "GR") return 30;
        if (symbols[reels[0]] == "ST") return 20;
        if (symbols[reels[0]] == "BE") return 10;
    }
    else if (reels[0] == reels[1] || reels[1] == reels[2] || reels[0] == reels[2]) {
        return 5;
    }
    return 0;
}

int Bandit::getBalance() const {
    return balance;
}
