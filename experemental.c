#include "bael-tique.h"
#include <stdio.h>
#include <string.h>

void getDoubleInput(const char *prompt, double *value) {
    char input[100]; // Adjust buffer size as needed
    while (1) {
        printf("%s", prompt);
        fgets(input, sizeof(input), stdin);
        if (sscanf(input, "%lf", value) == 1) {
            break;
        } else {
            printf("Invalid input. Please enter a valid number.\n");
        }
    }
}

void getIntInput(const char *prompt, int *value) {
    char input[100]; // Adjust buffer size as needed
    while (1) {
        printf("%s", prompt);
        fgets(input, sizeof(input), stdin);
        if (sscanf(input, "%d", value) == 1) {
            break;
        } else {
            printf("Invalid input. Please enter a valid integer.\n");
        }
    }
}

int main() {
    int n = 0, i = 0;
    char chek;

    while (1) {
        printf("Avez-vous la valeur de Nu? (oui/non)\n");
        fgets(input, sizeof(input), stdin);

        if (strncmp(input, "oui", 3) == 0) {
            chek = 'o';
            getDoubleInput("donnez la valeur de Nu (en MN): ", &Nu);
        } else if (strncmp(input, "non", 3) == 0) {
            chek = 'n';
            getDoubleInput("Donnez la valeur de G: ", &G);
            getDoubleInput("Donnez la valeur de Q: ", &Q);
            Nu = (1.35 * G) + (1.5 * Q);
        } else {
            printf("Repondez par 'oui' ou 'non'\n");
            continue; // Retry the loop
        }

        printf("Veulliez-vous changer la valeur de \u03b3b et \u03b3s? (oui/non)\n");
        fgets(input, sizeof(input), stdin);

        if (strncmp(input, "oui", 3) == 0) {
            getDoubleInput("donnez la valeur de \u03b3b: ", &gamab);
            getDoubleInput("donnez la valeur de \u03b3s: ", &gamas);
        }

        // Handle other input and continue your program flow here.
    }

    return 0;
}
