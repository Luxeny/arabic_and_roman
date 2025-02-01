#include <iostream>
#include <string>
using namespace std;

// Преобразует арабское число в римское
string roman_numeral(int num) {
    string result = "";
    pair<int, string> roman[] = {
        {1000, "M"}, {900, "CM"}, {500, "D"}, {400, "CD"},
        {100, "C"}, {90, "XC"}, {50, "L"}, {40, "XL"},
        {10, "X"}, {9, "IX"}, {5, "V"}, {4, "IV"}, {1, "I"}
    };

    for (const auto &element : roman) {
        while (num >= element.first) {
            result += element.second;
            num -= element.first;
        }
    }
    return result;
}

int main() {
    int num;
    cout << "Введите арабское число (1-3999): ";
    cin >> num;

    if (num < 1 || num > 3999) {
        cout << "Число должно быть в диапазоне 1-3999." << endl;
        return 1;
    }

    cout << "Перевод в римскую цифру: " << roman_numeral(num) << endl;
    return 0;
}