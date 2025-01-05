#include <stdio.h>

#define MAXLINE 1000

void remove_comments(char input[], char output[]);

int main() {
    char c, input[MAXLINE];
    char output[MAXLINE];
    int index = 0;

    while ((c = getchar()) != EOF && index < MAXLINE - 1) {
        input[index++] = c;
    }
    input[index] = '\0';

    remove_comments(input, output);

    printf("\nProgram without comments:\n");
    printf("%s", output);

    return 0;
}

void remove_comments(char input[], char output[]) {
    int i = 0, j = 0;
    int in_string = 0, in_char = 0;

    while (input[i] != '\0') {
        if (input[i] == '"' && !in_char) {
            output[j++] = input[i++];
            in_string = !in_string;
            while (in_string && input[i] != '\0') {
                output[j++] = input[i];
                if (input[i] == '"' && input[i - 1] != '\\') {
                    in_string = 0;
                }
                i++;
            }
        }
        else if (input[i] == '\'' && !in_string) {
            output[j++] = input[i++];
            in_char = !in_char;
            while (in_char && input[i] != '\0') {
                output[j++] = input[i];
                if (input[i] == '\'' && input[i - 1] != '\\') {
                    in_char = 0;
                }
                i++;
            }
        }
        else if (input[i] == '/' && input[i + 1] == '/' && !in_string && !in_char) {
            i += 2;
            while (input[i] != '\n' && input[i] != '\0') {
                i++;
            }
        } else if (input[i] == '/' && input[i + 1] == '*' && !in_string && !in_char) {
            i += 2;
            while (!(input[i] == '*' && input[i + 1] == '/') && input[i] != '\0') {
                i++;
            }
            if (input[i] != '\0') i += 2;
        } else {
            output[j++] = input[i++];
        }
    }

    output[j] = '\0';
}
