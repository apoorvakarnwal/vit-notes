#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>
using namespace std;

struct Variable
{
    string name;
    string type;
    int size;
    int offset;
};

vector<Variable> variables;
int offset = 1000;
unordered_set<string> valid_types = {"int", "float", "double", "char"};

void add_variable(const string &name, const string &type, int size, int array_size)
{
    int size2 = (array_size > 0) ? size * array_size : size;
    variables.push_back({name, type, size2, offset});
    offset += size2;
}

void print_table()
{
    cout << "Location | Name | Type  | Size\n";
    for (const auto &var : variables)
    {
        cout << var.offset << "       | " << var.name << " | " << var.type << " | " << var.size << "\n";
    }
}
int get_type_size(const string &type)
{
    if (type == "int")
        return sizeof(int);
    if (type == "float")
        return sizeof(float);
    if (type == "double")
        return sizeof(double);
    if (type == "char")
        return sizeof(char);
    return 0;
}

void process_declaration(const string &type, const string &name, int size, int array_size)
{
    if (valid_types.find(type) != valid_types.end())
    {
        add_variable(name, type, size, array_size);
    }
    else
    {
        cerr << "Error: Invalid type '" << type << "' for variable '" << name << "'\n";
    }
}
// void lexicalanalysis(const string &input)
// {
//     size_t i = 0;
//     while (i < input.length())
//     {
//         while (i < input.length() && isspace(input[i]))
//         {
//             i++;
//         }

//         if (i < input.length() && (isalpha(input[i]) || input[i] == '_'))
//         {
//             string buffer;
//             while (i < input.length() && (isalnum(input[i]) || input[i] == '_'))
//             {
//                 buffer += input[i++];
//             }
//             if (valid_types.find(buffer) != valid_types.end())
//             {
//                 string type = buffer;
//                 while (i < input.length() && input[i] != ';')
//                 {
//                     while (i < input.length() && isspace(input[i]))
//                         ++i;

//                     if (i < input.length() && (isalpha(input[i]) || input[i] == '_'))
//                     {
//                         string var_name;
//                         while (i < input.length() && (isalnum(input[i]) || input[i] == '_'))
//                         {
//                             var_name += input[i++];
//                         }

//                         int size = get_type_size(type);
//                         int array_size = 0;
//                         if (i < input.length() && input[i] == '[')
//                         {
//                             ++i;
//                             while (i < input.length() && isdigit(input[i]))
//                             {
//                                 array_size = array_size * 10 + (input[i] - '0');
//                                 ++i;
//                             }
//                             if (i < input.length() && input[i] == ']')
//                                 ++i;
//                         }

//                         process_declaration(type, var_name, size, array_size);
//                     }
//                 }

//                 if (i < input.length() && input[i] == ';')
//                 {
//                     ++i;
//                 }
//             }
//             else
//             {
//                 cerr << "Error: Invalid type or declaration starting with '" << buffer << "'\n";
//                 while (i < input.length() && input[i] != ';')
//                 {
//                     ++i;
//                 }
//                 if (i < input.length() && input[i] == ';')
//                     ++i;
//             }
//         }
//         else
//         {
//             ++i;
//         }
//     }
// }
void lexicalanalysis(const string &input)
{
    size_t i = 0;
    while (i < input.length())
    {
        // Skip whitespace
        while (i < input.length() && isspace(input[i]))
        {
            i++;
        }

        // Process a valid type or identifier (keyword or variable name)
        if (i < input.length() && (isalpha(input[i]) || input[i] == '_'))
        {
            string buffer;
            // Collect the potential type or identifier
            while (i < input.length() && (isalnum(input[i]) || input[i] == '_'))
            {
                buffer += input[i++];
            }

            // If it's a valid type (int, float, etc.)
            if (valid_types.find(buffer) != valid_types.end())
            {
                string type = buffer;

                // Skip any whitespace
                while (i < input.length() && isspace(input[i]))
                    ++i;

                // Now expect a variable name
                string var_name;
                while (i < input.length() && (isalnum(input[i]) || input[i] == '_'))
                {
                    var_name += input[i++];
                }

                // Check if the variable name starts with a digit
                if (isdigit(var_name[0]))
                {
                    cerr << "Error: Variable name '" << var_name << "' cannot start with a number.\n";
                    // Skip until semicolon (or end of statement)
                    while (i < input.length() && input[i] != ';')
                    {
                        ++i;
                    }
                    if (i < input.length() && input[i] == ';')
                        ++i;
                    continue;
                }

                int size = get_type_size(type);
                int array_size = 0;

                // Handle array declarations (e.g., int arr[10])
                if (i < input.length() && input[i] == '[')
                {
                    ++i;
                    while (i < input.length() && isdigit(input[i]))
                    {
                        array_size = array_size * 10 + (input[i] - '0');
                        ++i;
                    }
                    if (i < input.length() && input[i] == ']')
                        ++i; // Skip closing bracket
                }

                // Process the valid variable declaration
                process_declaration(type, var_name, size, array_size);
            }
            else
            {
                cerr << "Error: Invalid type or declaration starting with '" << buffer << "'\n";
                while (i < input.length() && input[i] != ';')
                {
                    ++i;
                }
                if (i < input.length() && input[i] == ';')
                    ++i;
            }
        }
        else
        {
            ++i; // Skip invalid characters
        }
    }
}

int main()
{
    string input;
    cout << "Enter declarations: ";
    getline(cin, input);

    cout << "Tokens - \n";
    lexicalanalysis(input);
    print_table();

    return 0;
}