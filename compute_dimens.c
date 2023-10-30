#include "bael-tique.h"
/**
 * compute_dimens - calcul de dimensionement de poteux à partir de lambda
 * @p: struct poteau des informations sur poteau.
 * 
 * Return: Nothing.
*/
void compute_dimens(secpoteau_t *p)
{
    char *chek;
    int n = 0;
    double dmax = 0, dmin = 0;

    lfscanf("donnez la valeur de lf (en m): ", &(p->lf));
    lfscanf("Valeur de λ: ", &lambda);
    if (lambda > 35)
    {
        dprintf(2, "Valeur de lambda est supérieur à 35");
        return;
    }
    lambda = 0.708;
    Br = 1.907 * (Nu / fc); 
    dscanf("C'est quoi la section de poteau:\n1. cerculaire\n2. rectangulaire\nchoisissez 1 ou 2: ", &n);
    printf("Solution:\n");
    if (n == 1)
    {
        printf("4 x lf/λ ≤ D ≤ 4√3 x Br/π\n");
        dmax = sqrt(4 * (Br / PI));
        printf("4 x %.2f/%.3f ≤ D ≤ 4√3 x %.4f/π\n", p->lf, lambda, Br);
        dmin = 4 * (p->lf / lambda);
        printf("%.4f ≤ D ≤ %.4f\n", dmin, dmax);
    }
    else if (n == 2)
    {
        printf("a ≥ 2√3 x lf/λ\n");
        a = 2 * sqrt(3) * p->lf / lambda;
        printf("a = %.2f\n", a);
        printf("b ≤ (Br/(a-0.02)) + 0.02\n");
        b = (Br / (a - 0.02)) + 0.02;
        printf("b = %2.f\n", b);
    }
    else
    {
        dprintf(2, "Entrez une valeur entre 1 et 2");
        return;
    }
}
