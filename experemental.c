#include "bael-tique.h"
/**
 * lfscanf - reads the user input for double values.
 * @prompt: a message shown.
 * @value: a mem address to store the value
 *
 * Return: Nothing.
 */
void lfscanf(const char *prompt, double *value) {
    char input[100];
    while (1)
    {
        printf("%s", prompt);
        fgets(input, sizeof(input), stdin);
        if (sscanf(input, "%lf", value) == 1)
            break;
        else
            printf("Erreur: enterez a valeur comme: 0.00\n");
    }
}

/**
 * dscanf - reads the user input for decimal values.
 * @prompt: a message shown.
 * @value: a mem address to store the value
 *
 * Return: Nothing.
 */
void dscanf(const char *prompt, int *value) 
{
    char input[100]; // Adjust buffer size as needed
    while (1)
    {
        printf("%s", prompt);
        fgets(input, sizeof(input), stdin);
        if (sscanf(input, "%d", value) == 1)
            break;
        else 
            printf("Erreur: enterez a valeur decimal.\n");
    }
}

/**
 * cscanf - reads the user input for char values.
 * @prompt: a message shown.
 * @value: a mem address to store the value
 *
 * Return: Nothing.
 */
char cscanf(const char *prompt)
{
    char input[100]; // Adjust the buffer size as needed
    char value;

    while (1) {
        printf("%s", prompt);
        fgets(input, sizeof(input), stdin);

        if (sscanf(input, " %c", &value) == 1)
            return value;
        else
            printf("Invalid input. Please enter a single character.\n");
    }
}
