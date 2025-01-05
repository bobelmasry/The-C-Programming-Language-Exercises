#include <stdio.h>

#define MAXLINE 1000

void check_syntax(const char *input);

int main() {
    char c, input[MAXLINE];
    int index = 0;

    while ((c = getchar()) != EOF && index < MAXLINE - 1) {
        input[index++] = c;
    }
    input[index] = '\0';

    check_syntax(input);

    return 0;
}

void check_syntax(const char *input) {
    int parentheses = 0, brackets = 0, braces = 0;
    int in_string = 0, in_char = 0, in_comment = 0;

    for (int i = 0; input[i] != '\0'; i++) {
        if (in_comment) {
            if (input[i] == '*' && input[i + 1] == '/') {
                in_comment = 0;
                i++;
            }
            continue;
        }

        if (input[i] == '/' && input[i + 1] == '*') {
            in_comment = 1;
            i++;
            continue;
        }

        if (in_string) {
            if (input[i] == '"' && input[i - 1] != '\\') {
                in_string = 0;
            }
            continue;
        }

        if (in_char) {
            if (input[i] == '\'' && input[i - 1] != '\\') {
                in_char = 0;
            }
            continue;
        }

        if (input[i] == '"') {
            in_string = 1;
            continue;
        }

        if (input[i] == '\'') {
            in_char = 1;
            continue;
        }

        if (input[i] == '(') parentheses++;
        else if (input[i] == ')') parentheses--;
        else if (input[i] == '[') brackets++;
        else if (input[i] == ']') brackets--;
        else if (input[i] == '{') braces++;
        else if (input[i] == '}') braces--;

        if (parentheses < 0) {
            printf("Error: Unmatched ')' at position %d\n", i);
            parentheses = 0;
        }
        if (brackets < 0) {
            printf("Error: Unmatched ']' at position %d\n", i);
            brackets = 0;
        }
        if (braces < 0) {
            printf("Error: Unmatched '}' at position %d\n", i);
            braces = 0;
        }
    }

    if (parentheses > 0) {
        printf("Error: %d unmatched '('\n", parentheses);
    }
    if (brackets > 0) {
        printf("Error: %d unmatched '[`\n", brackets);
    }
    if (braces > 0) {
        printf("Error: %d unmatched '{`\n", braces);
    }
}
