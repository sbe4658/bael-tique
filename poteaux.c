#include "bael-tique.h"
/**
 * p_cercl - handles "poteaux cerculaire"
 * @n: the number of args.
 * 
 * Return: a pointer to a struct poteau_s.
*/
secpoteau_t *p_cercl(void)
{
    secpoteau_t p;

    printf("Calcul de λ:\n");
    lambda = 4 * (p.lf / d);
    printf("λ = 4 x lf/D\nλ = 4 x %.4f/%d\n", p.lf, d);
    printf("λ = %.4f\n", lambda);
    p.lambda = lambda;
    alpha = calc_alpha(p);
    Br = calc_Br('c');
    calc_section('c');
    return (&p);
}
double calc_Br(char c)
{
    double Br = 0;

    printf("Calcul de Br:\n");
    if (c = 'c')
    {
        printf("Br = π(d - 0.02)²\n");
        printf("Br = π(%.2f - 0.02)²\n", d);
        Br = PI * pow((d - 0.02), 2);
        printf("Br = %.4f\n", Br);
    }
    else
    {
        printf("Br = (a - 0.02)(b - 0.02)\n");
        printf("Br = (%.2f - 0.02)(%.2f - 0.02)\n", a, b);
        Br = (a - 0.02) * (b - 0.02);
        printf("Br = %.4f\n", Br);
    }
    return (Br);
}
double calc_section(char c)
{
    double Asc = 0, A4u = 0, Ath = 0, A2 = 0, A5 = 0, Amin = 0;

    Ath = ((Nu / alpha) - (Br * fc) / (0.9 * gamab)) * (gamas / fe);
    if (c = 'c')
    {
        A4u = (4 * PI * d);
        A2 = (0.2 * (PI * pow(d / 2, 2)) / 100);
        A5 = (5 * (PI * pow(d / 2, 2)) / 100);
    }
    else
    {
        A4u = (4 * 2 * (a + b));
        A2 = (0.2 * (a * b) / 100);
        A5 = (5 * (a * b) / 100);
    }
    Amin = max(A4u, A2);
    Asc = max(Amin, Ath);
    if (Asc >= A2 && Asc <= A5)
        printf("0.2B/100 = %.3f <= Asc <= 5B/100 = %3.f\n", A2, A5);
    return (Asc);
}
double calc_alpha(secpoteau_t p)
{
    double alphap = 0;

    printf("Calcul de alpha:\n");
    if (lambda > 70)
    {
        dprintf(2, "flexion composée");
        return (0);
    }
    else if (lambda > 50)
    {
        printf("\u03b1 = 0.6 x (90/λ)²\n\u03b1 = 0.6 x 90/%.4f\n", lambda);
        alpha = 0.6 * (pow(90 / lambda, 2));
        printf("\u03b1: %.4f\n", alpha);
    }
    else if (lambda <= 50 && lambda >= 0)
    {
        printf("\u03b1 = 0.85/1 + 0.2(λ/35)²\n\u03b1 = 0.85 / 1+ 0.2(%.4f/35)²\n", lambda);
        alpha = 0.85 / (1 + (0.2 * pow(lambda / 35, 2)));
        printf("\u03b1 = %.4f\n", alpha);
    }
    else
    {
        dprintf(2, "Erreur: la valeur de λ = %.2f est inferieur à zero\n", lambda);
        return (0);
    }
    if (j >= 90)
        alphap = alpha;
    else if (j < 90 && j >= 28)
        alphap = alpha / 1.1;
    else if (j < 28 && j >= 0)
        alphap = alpha / 1.2;
    return (alphap);
}