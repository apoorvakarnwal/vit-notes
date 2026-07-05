#include <iostream>
#include <unordered_map>
using namespace std;

unordered_map<string, double> symbolTable;

void constantfolding(const string &vars, double value)
{
    symbolTable[vars] = value;
}
int main()
{
    double constant1 = 22 * 26.5;
    cout << "Optimized constant for 22 * 26.5: " << constant1 << endl;
    constantfolding("Constant1", constant1);

    double constant2 = 45 * 10 / 15 + 100;
    cout << "Optimized constant for 45 * 10 / 15 + 100: " << constant2 << endl;
    constantfolding("Constant2", constant2);

    double constant3 = 2024 * 31 / 21 + 1979 - 2000;
    cout << "Optimized constant for 2024 * 31 / 21 + 1979 - 2000: " << constant3 << endl;
    constantfolding("Constant3", constant3);

    cout << "Symbol Table with Optimized Constants\n";
    for (auto &entry : symbolTable)
    {
        cout << entry.first << "  " << entry.second << endl;
    }
    return 0;
}