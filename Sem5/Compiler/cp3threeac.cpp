#include <iostream>
#include <string>
#include <vector>
using namespace std;

int nextOp(const string &arr, int pos)
{
    for (int i = pos + 1; i < arr.length(); i++)
        if (arr[i] == '=' || arr[i] == '+' || arr[i] == '-' || arr[i] == '*' || arr[i] == '/' || arr[i] == ';')
            return i;
    return -1;
}
bool isKeyword(const string &str)
{
    const string keywords[] = {"char", "double", "float", "int", "long", "short"};
    for (const auto &keyword : keywords)
    {
        if (str == keyword)
        {
            return true;
        }
    }
    return false;
}
void parseExpression(const string &lhs, const string &expr, vector<string> &identifiers, vector<string> &operators)
{
    bool isFloat = false;
    string temp;
    for (char c : expr)
    {
        if (isalnum(c) || c == '.')
        {
            temp += c;
            if (c == '.')
            {
                isFloat = true;
            }
        }

        else if (c == '+' || c == '-' || c == '*' || c == '/')
        {
            if (!temp.empty())
            {
                if (isKeyword(temp))
                {
                    cout << "Invalid variable name";
                    return;
                }
                if (isdigit(temp[0]))
                {
                    temp = "#" + temp;
                }
                identifiers.push_back(temp);
                temp.clear();
            }
            operators.push_back(string(1, c));
        }
    }
    if (!temp.empty())
    {
        if (isKeyword(temp))
        {
            cout << "Invalid variable name";
            return;
        }
        if (isdigit(temp[0]))
        {
            temp = "#" + temp;
        }
        identifiers.push_back(temp);
    }

    for (const auto &id : identifiers)
        cout << id << " " << id << endl;

    // Generate assembly code for addition or multiplication
    if (operators.size() == 1)
    {
        string op = "";
        if (operators[0] == "+")
        {
            op = isFloat ? "ADDF" : "ADD";
        }
        else if (operators[0] == "-")
        {
            op = isFloat ? "SUBF" : "SUB";
        }
        else if (operators[0] == "*")
        {
            op = isFloat ? "MULF" : "MUL";
        }
        else if (operators[0] == "/")
        {
            op = isFloat ? "DIVF" : "DIV";
        }

        if (isFloat)
        {
            cout << "\nMOVF " << identifiers[1] << ", R1\n";
            cout << op << " " << identifiers[0] << ", R1\n";
            cout << "MOVF R1," << lhs << endl;
        }
        else
        {
            cout << "\nMOV " << identifiers[1] << ", R1\n";
            cout << op << " " << identifiers[0] << ", R1\n";
            cout << "MOV R1," << lhs << endl;
        }
    }
}

int main()
{
    string s;
    cout << "Enter code: ";
    getline(cin, s);

    int assign = nextOp(s, 0);
    if (assign != -1 && s[assign] == '=')
    {
        string lhs = s.substr(0, assign);
        lhs.erase(lhs.find_last_not_of(" \t") + 1); // Trim spaces
        cout << "LHS variable: " << lhs << endl;

        string rhs = s.substr(assign + 1);
        rhs.erase(rhs.find_last_not_of(" \t") + 1);

        vector<string> identifiers;
        vector<string> operators;

        parseExpression(lhs, rhs, identifiers, operators);
    }
    return 0;
}