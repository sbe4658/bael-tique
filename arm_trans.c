#include "bael-tique.h"
void arm_trans(secpoteau_t *p)
{
    int dlmax, dt = 0, t = 0;
    double chk = 0, tmp = 0;

    scanf("diamétre Ølmax (en m): %d et Ølmin (en m):", p->dlmax, p->dlmin);
    printf("Solution:\n");
    dlmax = p->dlmax;
    printf("Øt > Ølmax/3\nØlmax/3 = %f\n", dlmax/3);
    chk = dlmax/3;
    dt = chk;
    dt++;
    while (dt % 5 != 0)
            dt++;
    printf("donc Øt = %d", chk);
    printf("Calcul d'espacement:\n");
    printf("t < inf(15Ølmin; 40cm; a+10cm)");
    printf("t < inf(%d; 40cm; %.2f+10cm)", 15 * dt * 100, a * 100);
    tmp = min(min(15 * dt * 100, 40), (a * 100) + 10);
    t = tmp;
    t--;
    while (t % 5)
        t--;
    printf("l'espacement t = %d", t);
}