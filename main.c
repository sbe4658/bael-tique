#include "bael-tique.h"

/* Needed */
double Q = 0, G = 0, Nu = 0, fc = 0;
double gamab = 1.5, gamas = 1.15, lambda = 0, alpha = 0, Br = 0, d = 0, a = 0, b = 0; /* A l'etats normaux */
int j = 0, fe = 0;

/**
 * main - a simple program to compute "le diamétre des armature d'acier"
 * 
 * Return: 0 on success, otherwise -1.
*/
int main(void)
{
    char *q;
    int n = 0, i = 0;
    secpoteau_t p;
    history *h = NULL;

    p.lf = 0;
    while (1)
    {
        printf("\033[33mDe quoi avez-vous besoin pour calculer:\033[0m\n1. Section d'asier pour les armatures longitidinales pour poteau\n");
        printf("2. La valeur de lf\n3. Détemination des dimensions de sections\n");
        printf("4. diamétre et espacement d'armatures transversales\n5. Section d'asier pour les armatures longitidinales pour semelle\n");
        dscanf("", &n);
        if (n == 1)
            arm_long(&p);
        else if (n == 2)
            determ_de_lf(&p);
        else if (n == 3)
            compute_dimens(&p);
        else if (n == 4)
            arm_trans(&p);
        else if (n == 5)
	{
	    system("clear");
            dprintf(2, "\033[31msystem taye7 xD\033[0m\n");
	    sleep(4);
	}
        else
        {
            system("clear");
            dprintf(2, "Entrez une valeur entre 1 et 5\n");
            n = 0;
        }
        i++;
    }
    return (0);
}
int determ_de_lf(secpoteau_t *p)
{
    char c = '0', t = '0';
    int i = 0;
    double L0 = 0;

    printf("L\u2092: ");
    lfscanf("", &L0);
    printf("choisissez en chaque la lettre covenable a votre cas\n(a): encastré\t(b): articulé\t(c): encastré et possibelment deplacé par traction\t(e): revenir ou menu\n(n): null\n");
    c = cscanf("Au pied: %c");
    t = cscanf("en tête: %c");
    while (1)
    {
        system("clear");
        printf("\033[32mSolution:\033[0m\n");
        if (c == 'e' || t == 'e')
            return (0);
        else if (c == 'a' && t == 'n')
        {
            printf("lf = 2L\u2092\n");
            p->lf = 2 * L0;
            printf("lf = %.4f\n\n", p->lf);
            break;
        }
        else if (((c == 'a') && t == 'c') || (c == 'b' && t == 'b'))
        {
            printf("lf = L\u2092\n");
            p->lf = L0;
            printf("lf = %.4f\n\n", p->lf);
            break;
        }
        else if (((c == 'a') && t == 'b') || (c == 'b' && t == 'a'))
        {
            printf("lf = 0.707L\u2092\n");
            p->lf = 0.707 * L0;
            printf("lf = %.4f\n\n", p->lf);
            break;
        }
        else if (c == 'a' && t == 'a')
        {
            printf("lf = L\u2092/2\n");
            p->lf = L0 / 2;
            printf("lf = %.4f\n\n", p->lf);
            break;
        }
        else
        {
            system("clear");
            dprintf(2, "%c ou %c est inconnu\n", c, t);
            c = '0';
        }
    }
    return (0);
}
