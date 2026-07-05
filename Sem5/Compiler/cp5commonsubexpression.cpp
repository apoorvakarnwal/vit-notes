#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <cctype>
#include <algorithm>
using namespace std;
struct Statement
{
    string variable;
    string expression;
};
void trim(string &str)
{
    str.erase(str.begin(), find_if(str.begin(), str.end(), [](unsigned char ch)
                                   { return !isspace(ch); }));
    str.erase(find_if(str.rbegin(), str.rend(), [](unsigned char ch)
                      { return !isspace(ch); })
                  .base(),
              str.end());
}
void printStatements(const vector<Statement> &statements)
{
    for (const auto &stmt : statements)
    {
        cout << stmt.variable << " = " << stmt.expression << ";\n";
    }
}
void eliminateCommonSubexpressions(vector<Statement> &statements)
{
    unordered_map<string, string> exprMap; // <expression,variable>
    for (auto &stmt : statements)
    {
        if (exprMap.count(stmt.expression))
        {
            stmt.expression = exprMap[stmt.expression];
        }
        else
        {
            exprMap[stmt.expression] = stmt.variable;
        }
    }
}
bool parseStatement(const string &statement, vector<Statement> &statements)
{
    size_t equalPos = statement.find('=');
    if (equalPos == string::npos)
    {
        cout << "Error: Invalid statement format. Missing '='.\n";
        return false;
    }
    string var = statement.substr(0, equalPos);
    string expr = statement.substr(equalPos + 1);
    trim(var);
    trim(expr);
    if (var.empty() || expr.empty())
    {
        cout << "Error: Empty variable or expression in statement.\n";
        return false;
    }
    Statement temp;
    temp.expression = expr;
    temp.variable = var;
    statements.emplace_back(temp);
    return true;
}

int main()
{
    vector<Statement> statements;
    string input;
    cout << "Enter expressions:\n";
    getline(cin, input);
    size_t pos = 0;
    while (pos < input.size())
    {
        size_t nextPos = input.find(';', pos);
        string token = input.substr(pos, nextPos - pos);
        if (!parseStatement(token, statements))
        {
            return 1;
        }
        pos = nextPos + 1;
    }
    if (statements.empty())
    {
        cout << "No valid statements found.\n";
        return 1;
    }
    cout << "\nBefore common subexpression elimination:\n";
    printStatements(statements);
    eliminateCommonSubexpressions(statements);
    cout << "\nAfter common subexpression elimination:\n";
    printStatements(statements);
    return 0;
}