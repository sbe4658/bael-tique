#include "bael-tique.h"
/**
 * dimens - calcul de demensions de semelle.
 * @conad: contrainte admissible de sols.
 *
 * Return: Nothing.
 */
void dimens(double conad)
{
    double S, A, B, conbar, D, h, psem;
    int tmp = 0;

    Nser = G + Q;
    S = Nser / conad;

    A = sqrt(S * (a / b));
    A = div_par_5(A);

    B = sqrt(S * (b / a));
    B = div_par_5(B);

    D = div_par_5(max((A - a) / 4, (B - b) / 4));
    h = D + 0.05;

    psem = (A * B * h) * 0.025;
    conbar = (Nser + psem) / A * B;
    if (conbar > conad)
        dprintf(2, "\n");
}
/**
 * div_par_5 - le plus proche nombre div par 5cm.
 * @n: Nombre.
 * 
 * Return: le plus proche nombre div par 5.
 */
double div_par_5(double n)
{
    int tmp;

    n *= 100;
    tmp = (int)(n);
    while (tmp % 5)
        tmp++;
    n = (double)(tmp) / 100;    
    return (n);
}