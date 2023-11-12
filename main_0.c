#include "bael-tique.h"
double Q = 0, G = 0, Nu = 0, fc = 0, Nser = 0;
double gamab = 1.5, gamas = 1.15, lambda = 0, alpha = 0, Br = 0, d = 0, a = 0, b = 0; /* A l'etats normaux */
int j = 0, fe = 0;
/**
 * main - Calculs de section d'ascier.
 * 
 * Return: Always 0.
*/
int main(void)
{
    int n = 0;
    secpoteau_t p;

    p.lf = 0;
    while (1)
    {
        printf("\033[33mQuelle section avez-vous besoin pour calculer:\033[0m\n");
        printf("1. Poteaux\n");
        printf("2. Semelles\n");
        dscanf("Choissez (1 ou 2): ", &n);
        if (n == 1)
        {
            printf("\033[31mPoteaux:\033[0m\n");
            printf("|_ 1. Section d'ascier des armature longitudinales\n");
            printf("|_ 2. Section d'ascier des armature transversales\n");
            printf("|_ 3. Détermination du dimensionnement de poteau\n");
            dscanf("Choissez (1, 2 ou 3): ", &n);
            if (n == 1)
                arm_long(&p);
            else if (n == 2)
                arm_trans(&p);
            else if (n == 3)
                compute_dimens(&p);
            else
                dprintf(2, "\033[31mErreur: Entrez une valeur entre 1 et 3\033[0m\n");
        }
        else if (n == 2)
        {
            printf("\033[32mSemelles:\033[0m\n");
            printf("|_ 1. Section d'ascier des armature longitudinales\n");
            printf("|_ 2. Section d'ascier des armature transversales\n");
            dscanf("Choissez (1 ou 2): ", &n);
        }
        else
            dprintf(2, "\033[31mErreur: Entrez une valeur entre 1 et 3\033[0m\n");
    }
}