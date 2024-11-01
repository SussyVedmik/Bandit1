#pragma once
#include <vector>
#include <string>
using namespace std;

class Bandit {
public:
    Bandit();
    void spin();
    void displayResult() const;
    bool checkWin();
    int getBalance() const;
private:
    static const int NUM_REELS = 3;
    static const int NUM_SYMBOLS = 5;
    vector<string> symbols;
    vector<int> reels;
    int balance;
    int calculateWinnings() const;
};


