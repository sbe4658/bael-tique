#include "bael-tique.h"
void arm_long(secpoteau_t *p)
{
    int n = 0, i = 0;
    char chek = '0';

    while (1)
    {
        clr_buff();
        printf("Avez-vous la valeur de Nu? (oui/non)\n");
        scanf(" %c", &chek);
        if (chek == 'o')
        {
            scanf("donnez la valeur de Nu (en MN): %lf", &Nu);
        }
        else if (chek == 'n')
        {
            scanf("Donnez la valeur de G: %lf Q: %lf (en MN)", &G, &Q);
            Nu = (1.35 * G) + (1.5 * Q);
        }
        else
            dprintf(2, "repondez par o (oui) ou n (non)\n");

        printf("%c\n", chek);
        printf("Veulliez-vous changer la valeur de \u03b3b et \u03b3s? (oui/non)\n");
        scanf(" %c", &chek);

        printf("%c", chek);
        if (chek == 'o')
        {
            scanf("donnez la valeur de \u03b3b: %lf et \u03b3s: %lf", &gamab, &gamas);
        }

        printf("La mjeures ou la plus de la moitié des charges est appliquée:\n1. après 90 jours\n2. avant 90 jours\n3. à un âge avant 28 jours\n");
        scanf("%d", &n);

        if (n == 1)
            j = 90;
        else if (n == 2)
            j = 89;
        else if (n == 3)
        {
            scanf("Combien de jours: %d", &j);
        }

        printf("fc%d: ", (j >= 28 ? 28 : j));
        scanf("%lf", &fc);

        printf("f\u2091 (en MPa): ");
        scanf("%d", &fe);

        printf("What's wrong dawng: %lf\n", p->lf);

        if (p->lf)
        {
            scanf("Utilisez la valeur de lf calculée déjà? o/n: %c", &chek);

            if (chek == 'o')
                scanf("donnez la valeur de lf (en m): %lf", &(p->lf));
        }

        if (n == 0 && i >= 0)
            printf("choisissez la section de poteau:\n1. Cerculaire\n2. Rectangulaire\n");

        scanf("%d", &n);

        if (n == 2)
        {
            scanf("La valeur de a (en m): %lf", &a);
            scanf("La valeur de b (en m): %lf", &b);
            p_rect(p);
            break;
        }
        else if (n == 1)
        {
            scanf("La valeur de d le diamètre (en m): %lf", &d);
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
/**
 * clr_buff - clears the stdin
 * 
 * Return: Nothing.
*/
void clr_buff(void)
{
    int c;

    while( (c = fgetc(stdin)) != EOF && c != '\n' );
}