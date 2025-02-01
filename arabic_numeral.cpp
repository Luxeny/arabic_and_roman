#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

// Преобразует римское число в арабское
int arabic_numeral(const string& roman) {
    unordered_map<char, int> arabic = {
        {'I', 1}, {'V', 5}, {'X', 10}, {'L', 50},
        {'C', 100}, {'D', 500}, {'M', 1000}
    };

    int result = 0;
    int n = roman.size();

    for (int i = 0; i < n; ++i) {
        if (i + 1 < n && arabic[roman[i]] < arabic[roman[i + 1]]) {
            result -= arabic[roman[i]];
        } 
        else {
            result += arabic[roman[i]];
        }
    }
    return result;
}

int main() {
    string roman;
    cout << "Введите римское число: ";
    cin >> roman;

    int arabic = arabic_numeral(roman);
    cout << "Арабское число: " << arabic << endl;

    return 0;
}