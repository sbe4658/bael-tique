#include "bael-tique.h"

/* Needed */
int Q = 0, G = 0, Nu = 0, fc = 0, fe = 0;
double gamab = 1.5, gamas = 1.15, lambda = 0, alpha = 0, Br = 0, d = 0, a = 0, b = 0; /* A l'etats normaux */
__attribute__((unsused)) int j = 90;
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

    while (1)
    {
        printf("bael-tique\nCalcul des poteaux on comprission simple\ndonnée les valeurs suivants:");
        scanf("fc28 (en MPa): ", fc);
        scanf("f\u2091 (en MPa): ", fe);
        scanf("lf: ", p.lf);
        if (n == 0 && i >= 0)
            printf("choisissez la section de poteau:\n1. Cerculaire\n2. Rectangulaire\n");
        scanf("", n);
        if (n == 2)
        {
            scanf("La valeur de a (en m): ", a);
            scanf("La valeur de b (en m): ", b);
        }
        else if (n == 1)
            scanf("La valeur de d le diamiètre (en m): ", d);
        else
        {
            dprintf(2, "Entrez une valeur entre 1 et 2 (Cerculaire et regtangulaire)\n");
            n = 0;
            cls();
        }
        i++;
    }
    return (0);
}
int determ_de_lf(double L0, secpoteau_t *p)
{
    char c = '0', t = '0';
    int i = 0;

    while (1)
    {
        printf("choisissez en chaque la lettre correspendante a votre cas\n(a): encastré\t(b): articulé\t(c): encastré et possibelment deplacé par traction\t(e): revenir ou menu\n(n): null\n");
        scanf("Au pied: ", c);
        scanf("en tête: ", t);
        if (c == 'e' || t == 'e')
            return (69);
        else if (c == 'a' && t == 'n')
        {
                printf("lf = 2L\u2092\n");
            p->lf = 2 * L0;
            break;
        }
        else if (((c == 'a') && t == 'c') || (c == 'b' && t == 'b'))
        {
            printf("lf = L\u2092\n");
            p->lf = L0;
            break;
        }
        else if (((c == 'a') && t == 'b') || (c == 'b' && t == 'a'))
        {
            printf("lf = 0.707L\u2092\n");
            p->lf = 0.707 * L0;
            break;
        }
        /* TODO: Add the last case */
        else
        {
            dprintf(2, "%c ou %c est inconnu\n", c, t);
            c = '0';
            cls();
        }
    }
    return (0);
}