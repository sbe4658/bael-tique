#ifndef BAEL
#define BAEL

/* Headers */
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include <unistd.h>
#include <uchar.h>
#include <math.h>

/* Macros and constants */
#define min(a, b) \
   ({ __typeof__ (a) _a = (a); \
       __typeof__ (b) _b = (b); \
     _a < _b ? _a : _b; })
#define max(a, b) \
   ({ __typeof__ (a) _a = (a); \
       __typeof__ (b) _b = (b); \
     _a > _b ? _a : _b; })
#define PI 3.14159265
extern double Q, G;
extern double Nu, fc, Nser;
extern double gamab, gamas, lambda, alpha, Br, d, a, b;
extern int j, fe;

/**
 * struct poteau_s - informations sur le poteaux.
 * @lf: longeur fe flambement.
 * @lambda: (function pointer) section de poteau les dimensionement.
*/
typedef struct poteau_s
{
    double lf;
    int j;
    double lambda;
    double alpha;
    double dlmin;
    double dlmax; /* diamétre d'arm longitidinales max*/
    double dt; /* diamétre d'arm transversales */
    double t; /* espacement */
} secpoteau_t;

/**
 * struct history_s - LIFO data structure stores prev results.
 * @poteau: pointer to the most recent secpoteau_t structure.
 * @next: pointer to the next node.
 * there will be "Semelle" in future.
*/
typedef struct history_t
{
    secpoteau_t *poteau;
    struct history_t *next;
} history;

/* Functions */
double calc_alpha(void);
double calc_section(char c);
double calc_Br(char c);
secpoteau_t *p_cercl(secpoteau_t *p);
secpoteau_t *p_rect(secpoteau_t *p);
void arm_trans(secpoteau_t *p);
void arm_long(secpoteau_t *p);
void compute_dimens(secpoteau_t *p);
int determ_de_lf(secpoteau_t *p);
void clr_buff(void);
void dscanf(const char *prompt, int *value);
void lfscanf(const char *prompt, double *value); 
char cscanf(const char *prompt);
double div_par_5(double n);
double natural(double n);

#endif
