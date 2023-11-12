#include "bael-tique.h"
void arm_trans(secpoteau_t *p)
{
    double dt = 0, t = 0, lmin = 0;

    system("clear");
    printf("Calcule de diamétre des armatures transversales\n");
    lfscanf("Donner la valeur de d ou a (sa depend au section): ", &lmin);
    lfscanf("diamétre Ølmax (en mm): ", &(p->dlmax));
    lfscanf("diamétre Ølmin (en mm): ", &(p->dlmin));

    system("clear");
    printf("Solution:\n");
    printf("Øt > Ølmax/3\nt > Ølmax/3 = %f\n", p->dlmax/3);
    dt = p->dlmax/3;
    dt = div_par_5(dt);
    printf("donc Øt = %.0f\n\n", dt);

    printf("Calcule d'espacement:\n");
    printf("t < inf(15Ølmin; 40cm; a+10cm)\n");
    printf("t < inf(%.1f; 40cm; %.0f+10cm)\n", 15 * (p->dlmin/10), lmin * 100);
    t = min(min(15 * (p->dlmin/10), 40), ((lmin * 100) + 10));
    printf("t < %.1f\n", t);
    t = natural(t);
    printf("l'espacement t = %.0f\n\n", t);
}
/**
 * natural - inf and div by 5.
 * @n: a given number.
 * 
 * Return: the computed number.
*/
double natural(double n)
{
    int nat = (int)(n);

    while (nat % 5)
        nat--;
    n = (double)(nat);
    return(n);
}