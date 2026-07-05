#include <iostream>
#include <unordered_map>
#include <string>
#include <sstream>
#include <cstdlib> // For atof (string to float conversion)

using namespace std;

unordered_map<string, double> symbolTable;

void constantfolding(const string &varName, double value)
{
    symbolTable[varName] = value;
}

int main()
{
    string expression, varName;
    cout << "Enter expressions (or type 'exit' to stop):\n";
    while (true)
    {
        cout << "\nEnter an expression (e.g., 22 + 10): ";
        getline(cin, expression);

        if (expression == "exit")
            break;

        cout << "Enter variable name to store result: ";
        cin >> varName;
        cin.ignore();

        double result = 0;

        stringstream ss(expression);
        double num;
        char op = '+';

        while (ss >> num)
        {
            if (op == '+')
                result += num;
            else if (op == '-')
                result -= num;
            else if (op == '*')
                result *= num;
            else if (op == '/')
                result /= num;

            ss >> op;
        }
        constantfolding(varName, result);
        cout << "Symbol Table:\n";
        for (const auto &entry : symbolTable)
        {
            cout << entry.first << " = " << entry.second << endl;
        }
    }

    return 0;
}
