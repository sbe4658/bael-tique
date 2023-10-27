#ifndef BAEL
#define BAEL

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
extern int Q, G, fe;
extern int Nu, fc;
extern double gamab, gamas, lambda, alpha, Br, d, a = 0, b = 0;
extern __attribute__((unsused)) j;

/* Headers */
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include <unistd.h>
#include <uchar.h>
#include <math.h>

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

#endif