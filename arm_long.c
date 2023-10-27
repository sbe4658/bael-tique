#include "bael-tique.h"
void arm_long(secpoteau_t *p)
{
    int n = 0, i = 0;
    char *chek;

    while (1)
    {
        printf("Avez-vous la valeur de Nu? (oui/non)\n");
        scanf("%s", chek);
        if (strcmp(chek, "non"))
            scanf("donnez la valeur de Nu (en MN): %f", Nu);
        else
        {
            scanf("Donnez la valeur de G: %f Q: %f (en MN): ", G, Q);
            Nu = (1.35 * G) + (1.5 * Q); 
        }
        printf("Veulliez-vous changer la valeur de \u03b3b et \u03b3s? (oui/non)\n");
        scanf("%s", chek);
        if (strcmp(chek, "non"))
        {
            scanf("donnez la valeur de \u03b3b: ", gamab);
        }
        printf("La mjeures ou la plus de la motié des charges est appliquée:\n1. apès 90 jours\n2. avant 90 jours\n3. à un age avant 28 jours");
        scanf("%d", n);
        if  (n == 1)
            j = 90;
        else if (n == 2)
            j = 89;
        else if (n == 3)
        {
            scanf("Combien de jours: %d", j);
        }
        printf("fc%d", (28 ? j >= 28 : j));
        scanf("%f", fc);
        scanf("f\u2091 (en MPa): %f", fe);
        if (p->lf)
            scanf("Utilisez la valeur de lf calculer déja? (oui/non): %s", chek);
        if (strcmp(chek, "oui"))
            scanf("donnez la valeur de lf (en m): %f", p->lf);
        if (n == 0 && i >= 0)
            printf("choisissez la section de poteau:\n1. Cerculaire\n2. Rectangulaire\n");
        scanf("%d", n);
        if (n == 2)
        {
            scanf("La valeur de a (en m): ", a);
            scanf("La valeur de b (en m): ", b);
            p_rect(p);
            break;
        }
        else if (n == 1)
        {
            scanf("La valeur de d le diamiètre (en m): ", d);
            p_cercl(p);
            break;
        }
        else if (n == -1)
            return;
        else
        {
            dprintf(2, "Entrez une valeur entre 1 et 2 (-1: pour retournez)\n");
            n = 0;
            cls();
        }
    }
    p->alpha = alpha;
    p->lambda = lambda;
    p->j = j;
    alpha = 0;
    lambda = 0;
    j = 0;
}