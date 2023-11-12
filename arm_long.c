#include "bael-tique.h"
void arm_long(secpoteau_t *p)
{
    int n = 0;
    char chek[1024];

    while (1)
    {
        system("clear");
        printf("Avez-vous la valeur de Nu? (oui/non)\n");
        fgets(chek, 1024, stdin);
        if (strncmp(chek, "non", 3))
        {
            lfscanf("donnez la valeur de Nu (en MN): ", &Nu);
        }
        else if (strncmp(chek, "oui", 3))
        {
            lfscanf("Donnez la valeur de G (en MN): ", &Q);
            lfscanf("Donnez la valeur de Q (en MN): ", &Q);
            Nu = (1.35 * G) + (1.5 * Q);
        }
        else
            dprintf(2, "repondez par (oui) ou (non)\n");

        printf("Veulliez-vous changer la valeur de \u03b3b et \u03b3s? (oui/non)\n");
        fgets(chek, 1024, stdin);
        if (strncmp(chek, "non", 3))
        {
            lfscanf("donnez la valeur de \u03b3b: ", &gamab);
            lfscanf("donnez la valeur de \u03b3s: ", &gamas);
        }

        printf("La mjeures ou la plus de la moitié des charges est appliquée:\n1. après 90 jours\n2. avant 90 jours\n3. à un âge avant 28 jours\n");
        dscanf("", &n);

        if (n == 1)
            j = 90;
        else if (n == 2)
            j = 89;
        else if (n == 3)
        {
            dscanf("Combien de jours: ", &j);
        }

        printf("fc%d: ", (j >= 28 ? 28 : j));
        lfscanf("", &fc);

        dscanf("f\u2091 (en MPa): ", &fe);
        
        lfscanf("donnez la valeur de lf (en m): ", &(p->lf));
        dscanf("choisissez la section de poteau:\n1. Cerculaire\n2. Rectangulaire\n", &n);
        if (n == 2)
        {
            lfscanf("La valeur de a (en m): ", &a);
            lfscanf("La valeur de b (en m): ", &b);
            p_rect(p);
            break;
        }
        else if (n == 1)
        {
            lfscanf("La valeur de d le diamètre (en m): ", &d);
            p_cercl(p);
            break;
        }
        else if (n == -1)
            return;
        else
        {
            system("clear");
            dprintf(2, "Entrez une valeur entre 1 et 2 (-1: pour retournez)\n");
            n = 0;
        }
    }
    p->alpha = alpha;
    p->lambda = lambda;
    p->j = j;
    alpha = 0;
    lambda = 0;
    j = 0;
}
