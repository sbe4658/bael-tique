#include "bael-tique.h"
void compute_dimens(secpoteau_t *p)
{
    char *chek;

    if (p->lf)
        scanf("Utilisez la valeur de lf calculer déja? (oui/non): %s", chek);
    if (strcmp(chek, "oui"))
        scanf("donnez la valeur de lf (en m): %f", p->lf);
    scanf("Valeur de λ: %f", lambda);
    if (lambda > 35)
        dprintf(2, "Valeur de lambda est supérieur à 35");
    else
        lambda = 0.708;
    
}