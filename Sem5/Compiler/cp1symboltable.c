#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#define MAX_VARS 100
#define BUFFER_SIZE 100
typedef struct
{
    char name[BUFFER_SIZE];
    char type[BUFFER_SIZE];
    int size;
    int offset;
} Variable;
Variable variables[MAX_VARS];
int var_count = 0;
int offset = 1000;
int invalid_type_added = 0;
void add_variable(const char *name, const char *type, int size, int array_size)
{
    if (var_count < MAX_VARS)
    {
        strcpy(variables[var_count].name, name);
        strcpy(variables[var_count].type, type);
        if (array_size > 0)
        {
            variables[var_count].size = size * array_size;
        }
        else
        {
            variables[var_count].size = size;
        }
        variables[var_count].offset = offset;
        offset += variables[var_count].size;
    }
    else
    {
        printf("Error: Maximum number of variables exceeded.\n");
    }
}

void print_table()
{
    printf("Location | Name | Type | Size\n");
    printf(" \n");
    for (int i = 0; i < var_count; i++)
    {
        printf("%-7d | %-4s | %-10s | %d\n",
               variables[i].offset, variables[i].name, variables[i].type, variables[i].size);
    }
}
void lexicalanalysis(char input[])
{
    int i = 0;
    while (input[i] != '\0')
    {
        while (isspace(input[i]))
        {
            i++;
        }
        if (isalpha(input[i]) || input[i] == '_')
        {
            char buffer[BUFFER_SIZE];
            int j = 0;
            while (isalnum(input[i]) || input[i] == '_')
            {
                buffer[j++] = input[i++];
            }
            buffer[j] = '\0';
            int is_valid_type = 0;
            if (strcmp(buffer, "int") == 0 || strcmp(buffer, "float") == 0 || strcmp(buffer, "double") == 0 || strcmp(buffer, "char") == 0)
            {
                is_valid_type = 1;
                char type[BUFFER_SIZE];
                strcpy(type, buffer);
                while (input[i] != '\0' && input[i] != ';')
                {
                    while (isspace(input[i]))
                    {
                        i++;
                    }
                    if (isalpha(input[i]) || input[i] == '_')
                    {
                        char var_name[BUFFER_SIZE];
                        int k = 0;
                        while (isalnum(input[i]) || input[i] == '_')
                        {
                            var_name[k++] = input[i++];
                        }
                        var_name[k] = '\0';
                        int size = 0;
                        int array_size = 0;
                        if (strcmp(type, "int") == 0)
                            size = 2;
                        else if (strcmp(type, "float") == 0)
                            size = sizeof(float);
                        else if (strcmp(type, "double") == 0)
                            size = sizeof(double);
                        else if (strcmp(type, "char") == 0)
                            size = sizeof(char);
                        if (input[i] == '[')
                        {
                            i++;
                            array_size = 0;
                            while (isdigit(input[i]))
                            {
                                array_size = array_size * 10 + (input[i] - '0');
                                i++;
                            }
                            if (input[i] == ']')
                            {
                                i++;
                            }
                        }
                        add_variable(var_name, type, size, array_size);
                        while (input[i] == ',' || isspace(input[i]))
                        {
                            i++;
                        }
                    }
                }
                if (input[i] == ';')
                    i++;
            }
            else
            {
                if (!invalid_type_added)
                {
                    printf("Error: Invalid keyword or type '%s'\n", buffer);
                    char type[BUFFER_SIZE];
                    snprintf(type, sizeof(type), "Type invalid");
                    add_variable("invalid", type, 0, 0);
                }
                while (input[i] != '\0' && input[i] != ';')
                {
                    i++;
                }
                if (input[i] == ';')
                    i++;
            }
        }
        else
        {
            i++;
        }
    }
}
int main()
{
    char input[BUFFER_SIZE];
    printf("Enter declarations: ");
    fgets(input, sizeof(input), stdin);
    printf("Tokens - \n");
    lexicalanalysis(input);
    print_table();
    return 0;
}