#include <stdio.h>
#include <stdlib.h>
#include <string.h>1
#include <time.h>

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

void print_DATE(DATE fecha) {
    printf("%d-%d-%d\n", fecha.dia, fecha.mes, fecha.anyo);
}

void print_ALUMNO(struct ALUMNO alumno) {
    printf("%s\t%s\t", alumno.DNI, alumno.nom_comp);
    print_DATE(alumno.nac);
}

void rand_DATE(DATE *fecha) {
    int day = 0, month = 0, year = 0;
    month = (rand() % 12) + 1;

    year = (rand() % 7) + 1999;



    fecha->dia = day;
    fecha->mes = month;
    fecha->anyo = year;
}

unsigned is_fecha_valida(DATE fecha) {
    if (fecha.mes < 1 || fecha.mes > 12) {
        return 0;
    }

    int dias_en_mes[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30 ,31};
    if (fecha.mes == 2 && fecha.anyo % 400 && fecha.anyo % 100) {
        dias_en_mes[fecha.mes - 1]++;
    }

    if (fecha.dia > dias_en_mes[fecha.mes - 1] || fecha.dia < 1) {
        return 0;
    }

    if (fecha.anyo < 1999 && fecha.anyo > 2005) {
        return 0;
    }

    return 1;
}

int main(void)
{
    srand(time(NULL));
    return 0;
}
