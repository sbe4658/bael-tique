#include "bael-tique.h"
/**
 * p_cercl - handles "poteaux cerculaire"
 * 
 * Return: a pointer to a struct poteau_s.
*/
secpoteau_t *p_cercl(secpoteau_t *p)
{
    secpoteau_t p;

    printf("Calcul de λ:\n");
    lambda = 4 * (p->lf / d);
    printf("λ = 4 x lf/D\nλ = 4 x %.4f/%d\n", p->lf, d);
    printf("λ = %.4f\n", lambda);
    p->lambda = lambda;
    alpha = calc_alpha();
    Br = calc_Br('c');
    calc_section('c');
    return (&p);
}
/**
 * p_rect - handles "poteaux cerculaire"
 * 
 * Return: a pointer to a struct poteau_s.
*/
secpoteau_t *p_rect(secpoteau_t *p)
{
    printf("Solution:\n");
    printf("Calcul de λ:\n");
    lambda = 2 * sqrt(3) * (p->lf / a);
    printf("λ = 2√3 x lf/D\nλ = 2√3 x %.4f/%d\n", p->lf, a);
    printf("λ = %.4f\n", lambda);
    p->lambda = lambda;
    alpha = calc_alpha();
    Br = calc_Br('r');
    calc_section('r');
    return (&p);
}
double calc_Br(char c)
{
    double Br = 0;

    printf("Calcul de Br:\n");
    if (c = 'c')
    {
        printf("Br = π(d - 0,02)²\n");
        printf("Br = π(%.2f - 0,02)²\n", d);
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

    printf("Calcul de Ath:\n");
    printf("Ath = ((Nu/\u03b1) - (Br x fc%d/0.9\u03b3b))\u03b3s/fe\n", (28 ? j >= 28 : j));
    Ath = ((Nu / alpha) - (Br * fc) / (0.9 * gamab)) * (gamas / fe);
    printf("Ath = ((%.4f/%.4f) - (%.4f x %d/0.9 x 1.5))1.15/%d\n", Nu, alpha, Br, fc, fe);
    printf("Ath = %.4f\n", Ath);
    if (c = 'c')
    {
        printf("Calcul de A(4u):\n");
        printf("A(4u) = 4πD\n");
        printf("A(4u) = 4π x %.2f\n", d);
        A4u = (4 * PI * d);
        printf("A(4u) = %.4f\n", A4u);
        printf("Calcul de A(0.2%%):\n");
        printf("A(0.2%%) = 0.2B/100\n");
        printf("A(0.2%%) = 0.2πr²/100\n");
        A2 = (0.2 * (PI * pow(d * 100/ 2, 2)) / 100);
        printf("A(0.2%%) = %.4f\n", A2);
        A5 = (5 * (PI * pow(d * 100/ 2, 2)) / 100); /* Pour la vérification de fragilité */
    }
    else
    {
        printf("Calcul de A(4u):\n");
        printf("A(4u) = 4πD\n");
        printf("A(4u) = 4π x %.2f\n", d);
        A4u = (4 * 2 * (a + b));
        printf("A(4u) = %.4f\n", A4u);
        printf("Calcul de A(0.2%%):\n");
        printf("A(0.2%%) = 0.2B/100\n");
        printf("A(0.2%%) = 0.2(ab)/100\n");
        A2 = (0.2 * ((a * 100) * (b * 100)) / 100);
        printf("A(0.2%%) = %.4f\n", A2);
        A5 = (5 * ((a * 100) * (b * 100)) / 100);
    }
    printf("Calcul de Amin:\n");
    printf("Amin = sup(A(4u); A(0.2%%)\n");
    Amin = max(A4u, A2);
    printf("Amin = sup(%.4f; %.4f\n", A4u, A2);
    printf("Calcul de Asc:\n");
    printf("Asc = sup(Ath; Amin\n");
    Asc = max(Amin, Ath);
    printf("Asc = sup(%.4f; %.4f)\n", Ath, Amin);
    printf("Vérification de la conditon de Non-fragilité:\n");
    if (Asc >= A2 && Asc <= A5)
        printf("0.2B/100 = %.3f ≤ Asc ≤ 5B/100 = %3.f\n", A2, A5);
    else
        dprintf(2, "Section d'asier non-convenable\n");
    return (Asc);
}
double calc_alpha(void)
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
        printf("Puisque 50 ≤ λ ≤ 70\ndonc: \u03b1 = 0.6 x (90/λ)²\n\u03b1 = 0.6 x 90/%.4f\n", lambda);
        alpha = 0.6 * (pow(90 / lambda, 2));
        printf("\u03b1: %.4f\n", alpha);
    }
    else if (lambda <= 50 && lambda >= 0)
    {
        printf("Puisque λ ≤ 50:\u03b1 = 0.85/1 + 0.2(λ/35)²\n\u03b1 = 0.85 / 1+ 0.2(%.4f/35)²\n", lambda);
        alpha = 0.85 / (1 + (0.2 * pow(lambda / 35, 2)));
        printf("\u03b1 = %.4f\n", alpha);
    }
    else
    {
        dprintf(2, "Erreur: la valeur de λ = %.2f est inferieur à zero\n", lambda);
        return (0);
    }
    printf("Calcul de \u03b1':\n");
    if (j >= 90)
    {
        printf("\u03b1' = \u03b1\n");
        alphap = alpha;
        printf("\u03b1' = %.4f\n", alpha);
    }
    else if (j < 90 && j >= 28)
    {
        printf("\u03b1' = \u03b1/1.10\n");
        printf("\u03b1' = %.4f/1.10\n", alpha);
        alphap = alpha / 1.1;
        printf("\u03b1' = %.4f\n", alphap);
    }
    else if (j < 28 && j >= 0)
    {
        printf("\u03b1' = \u03b1/1.20\n");
        printf("\u03b1' = %.4f/1.20\n", alpha);
        alphap = alpha / 1.2;
        printf("\u03b1' = %.4f\n", alphap);
    }
    return (alphap);
}