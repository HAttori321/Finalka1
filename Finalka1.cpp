#include <iostream>
#include <fstream>
#include <string>
using namespace std;

enum Operation {
    ADDITION,
    SUBTRACTION,
    MULTIPLICATION,
    DIVISION
};

int main() {

    double num1, num2, result;
    Operation operation;
    char opChar;

    while (true) {
        cout << "Enter first number: ";
        cin >> num1;

        cout << "Enter operation (+, -, *, /): ";
        cin >> opChar;

        bool validOperation = false;
        switch (opChar) 
        {
        case '+':
            operation = ADDITION;
            validOperation = true;
            break;
        case '-':
            operation = SUBTRACTION;
            validOperation = true;
            break;
        case '*':
            operation = MULTIPLICATION;
            validOperation = true;
            break;
        case '/':
            operation = DIVISION;
            validOperation = true;
            break;
        }

        if (!validOperation) {
            cout << "Invalid operation!" << endl;
            continue;
        }

        cout << "Enter second number: ";
        cin >> num2;

        switch (operation) {
        case ADDITION:
            result = num1 + num2;
            break;
        case SUBTRACTION:
            result = num1 - num2;
            break;
        case MULTIPLICATION:
            result = num1 * num2;
            break;
        case DIVISION:
            if (num2 == 0) 
            {
                cout << "Division by zero!" << endl;
                continue;
            }
            result = num1 / num2;
            break;
        }

        cout << "Result: " << result << endl;

        ofstream out("history.txt", ios::app);
        if (out.is_open()) {
            out << num1 << " ";
            switch (operation) {
            case ADDITION:
                out << "+";
                break;
            case SUBTRACTION:
                out << "-";
                break;
            case MULTIPLICATION:
                out << "*";
                break;
            case DIVISION:
                out << "/";
                break;
            }
            out << " " << num2 << " = " << result << endl;
            out.close();
        }
        else {
            cout << "Error opening history file!" << endl;
        }

        char choice;
        cout << "Continue? (y/n): ";
        cin >> choice;
        if (choice == 'n') {
            break;
        }
    }

    cout << "History of operations:" << endl;
    ifstream in("history.txt");
    if (in.is_open()) {
        string line;
        while (getline(in, line)) {
            cout << line << endl;
        }
        in.close();
    }
    else {
        cout << "History file is empty!" << endl;
    }
}
