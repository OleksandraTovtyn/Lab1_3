#include <iostream>
#include <locale>

using namespace std;

class LongLong {
private:
    long highPart;
    long lowPart;

public:
    LongLong(long high, long low) : highPart(high), lowPart(low) {}

    // Арифметичні операції
    LongLong operator-(const LongLong& other) const {
        return LongLong(highPart - other.highPart, lowPart - other.lowPart);
    }

    LongLong operator/(const LongLong& other) const {
        return LongLong(highPart / other.highPart, lowPart / other.lowPart);
    }

    // Операції порівняння
    bool operator<=(const LongLong& other) const {
        return (highPart < other.highPart) || (highPart == other.highPart && lowPart <= other.lowPart);
    }

    bool operator==(const LongLong& other) const {
        return (highPart == other.highPart) && (lowPart == other.lowPart);
    }

    bool operator!=(const LongLong& other) const {
        return !(*this == other);
    }

    // Оператор виведення
    friend ostream& operator<<(ostream& os, const LongLong& obj) {
        os << "Старша частина: " << obj.highPart << ", Молодша частина: " << obj.lowPart;
        return os;
    }
};

int main() {
    setlocale(LC_ALL, "ukr");

    long highPart1, lowPart1, highPart2, lowPart2;

    cout << "Введiть старшу частину для числа 1: ";
    cin >> highPart1;

    cout << "Введiть молодшу частину для числа 1: ";
    cin >> lowPart1;

    cout << "Введiть старшу частину для числа 2: ";
    cin >> highPart2;

    cout << "Введiть молодшу частину для числа 2: ";
    cin >> lowPart2;

    LongLong num1(highPart1, lowPart1);
    LongLong num2(highPart2, lowPart2);

    LongLong resultSubtraction = num1 - num2;
    LongLong resultDivision = num1 / num2;

    cout << "Рiзниця: " << resultSubtraction << endl;
    cout << "Дiлення: " << resultDivision << endl;

    if (num1 <= num2) {
        cout << "Число 1 не бiльше або дорiвнює числу 2" << endl;
    }
    else {
        cout << "Число 1 бiльше числа 2" << endl;
    }

    if (num1 == num2) {
        cout << "Число 1 дорiвнює числу 2" << endl;
    }
    else {
        cout << "Число 1 не дорiвнює числу 2" << endl;
    }

    return 0;
}
