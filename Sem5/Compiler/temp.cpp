#include <iostream>
#include <sstream>
#include <unordered_map>
#include <string>
using namespace std;

void checkTypes(string &var1, string &var2, unordered_map<string, string> &typeMap)
{
    if (typeMap.find(var1) != typeMap.end() && typeMap.find(var2) != typeMap.end())
    {
        if (typeMap[var1] == typeMap[var2])
            cout << "type of " << var1 << " & " << var2 << " -->MATCHED" << endl;
        else
            cout << "type of " << var1 << " & " << var2 << " -->NOT MATCHED" << endl;
    }
    else
    {
        cout << "type of " << var1 << " & " << var2 << " -->NOT MATCHED" << endl;
    }
}
int main()
{
    string input;
    cout << "Enter the Input String : ";
    getline(cin, input);
    unordered_map<string, string> typeMap;
    stringstream ss(input);
    string segment;
    while (getline(ss, segment, ';'))
    {
        stringstream segStream(segment);
        string var, type, word;

        if (segment.find('=') == string::npos)
        {
            segStream >> type;
            while (segStream >> var)
            {
                if (var.back() == ',')
                    var.pop_back();
                typeMap[var] = type;
            }
        }
        else
        {
            string var1, var2, op, var3;
            segStream >> var1 >> op >> var2;
            if (op != "=")
            {
                typeMap[op] = var1;
            }
            else
            {
                if (segStream >> op >> var3)
                {
                    checkTypes(var2, var3, typeMap);
                }
                checkTypes(var1, var2, typeMap);
            }
        }
    }
    return 0;
}