#include <iostream>
#include <vector>
#include <string>
using namespace std;

std::vector<string> keywords = {
    "cin", "printf", "if", "else", "for", "while", "#include", "iostream", "return", "int", "main", "float", "string"};

void print_op(const string &op, const string &var)
{
    cout << op << "\t\t\t" << var << endl;
}

void print_c(char op, const string &var)
{
    cout << op << "\t\t\t" << var << endl;
}

int search(char a)
{
    vector<char> oper = {'+', '-', '*', '/', '%'};
    vector<char> symb = {'<', '>', '(', ')', '{', '}', ';', '='};

    if (find(oper.begin(), oper.end(), a) != oper.end())
    {
        return 1;
    }
    if (find(symb.begin(), symb.end(), a) != symb.end())
    {
        return 2;
    }
    return 0;
}

bool search_k(const string &arr)
{
    return find(keywords.begin(), keywords.end(), arr) != keywords.end();
}

void Lexical_Analyzer(const string &buffer)
{
    string token;
    int n = buffer.length();
    int j = 0;

    cout << "Symbol\t\t\tToken\n";

    for (int i = 0; i < n; i++)
    {
        if (search(buffer[i]) == 1)
            print_c(buffer[i], "Operator");
        else if (search(buffer[i]) == 2)
            print_c(buffer[i], "Symbol");
        else if (isdigit(buffer[i]))
            print_c(buffer[i], "Constant");
        else
        {
            if (search(buffer[i + 1]) != 0 && buffer[i] != ' ')
            {
                token += buffer[i];
                if (search_k(token))
                {
                    print_op(token, "Keyword");
                    token.clear();
                }
                else
                {
                    print_op(token, "Identifier");
                    token.clear();
                }
            }
            else if (buffer[i] != ' ')
            {
                token += buffer[i];
            }
            else
            {
                if (search_k(token))
                {
                    print_op(token, "Keyword");
                    token.clear();
                }
                else if (!token.empty())
                {
                    print_op(token, "Identifier");
                    token.clear();
                }
            }
        }
    }
}

int main()
{
    string buffer, line;
    cout << "Enter the source code (end with an empty line):" << endl;
    while (getline(cin, line))
    {
        if (line.empty())
            break; // End input on an empty line
        buffer += line + "\n";
    }
    Lexical_Analyzer(buffer);
    return 0;
}
