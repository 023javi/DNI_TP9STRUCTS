#include <stdio.h>
#include <stdlib.h>
#include <string.h>1

typedef struct {
    unsigned dia, mes, anyo;
} DATE;

struct ALUMNO {
    char DNI[9+1];
    char nom_comp[20+1];
    DATE nac;
};

const char nombres[8][10+1]={"jose","roberto","fernando","mario",
"sandra", "raquel", "isabel", "pilar"};
const char apellidos[8][10+1]={"garcia", "hernandez", "gutierrez",
"gomez", "fernandez", "lopez", "sanchez", "perez" };

void print_DATE(DATE );
void print_ALUMNO (struct ALUMNO);
void rand_DATE(DATE  *);
void rand_nom_comp(char [20+1]);
void rand_ALUMNO(struct ALUMNO  *);
unsigned es_fecha_valida(DATE);

void print_DATE(DATE *fecha) {
    printf("%d/%d/%d\n", fecha->dia, fecha->mes, fecha->anyo);
}

int main(void)
{

    return 0;
}
