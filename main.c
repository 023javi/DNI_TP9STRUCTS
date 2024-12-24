#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define A 80

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

void rand_DATE(DATE *fecha) {
    do {
        fecha->dia = (rand() % 31) + 1;
        fecha->mes = (rand() % 12) + 1;
        fecha->anyo = (rand() % 7) + 1999;
    }while(!is_fecha_valida(*fecha));
}

void rand_nom_comp(char nom_comp[20+1]) {
    int rand_name = rand() % 8;
    int rand_apell = rand() % 8;

    strcpy(nom_comp, apellidos[rand_apell]);
    strcat(nom_comp, ", ");
    strcat(nom_comp, nombres[rand_name]);
}

void rand_dig(char *dig) {
    *dig = rand() % 10 + '0';
}

void rand_DNI(int *DNI) {
    char dig;
    *DNI = 0;
    for (int i = 0; i < 8; i++) {
        rand_dig(&dig);
        *DNI = *DNI * 10 + (dig - '0');
    }
}

unsigned resto_DNI(unsigned DNI) {
    return DNI % 23;
}

char letra_calculada(unsigned restoDNI) {
    char letra[] = "TRWAGMYFPDXBNJZSQVHLCKE";
    return letra[restoDNI];
}

void rand_DNI_to_str(char *dnic[10+1]) {
    int dni = 0;
    rand_DNI(&dni); // Generar el DNI
    int resto = resto_DNI(dni); // Calcular el resto
    char letra[2]; // Espacio para la letra + terminador nulo

    itoa(dni, dnic, 10); // Convertir el DNI a cadena
    letra[0] = letra_calculada(resto); // Asignar la letra calculada
    letra[1] = '\0'; // Asegurar el terminador nulo

    strcat(dnic, letra); // Concatenar la letra al final del DNI
}

void rand_ALUMNO(struct ALUMNO *alumno) {
    rand_DNI_to_str(alumno->DNI);
    rand_nom_comp(alumno->nom_comp); // Generar el nombre completo aleatorio
    rand_DATE(&alumno->nac); // Generar la fecha de nacimiento aleatoria
}



int main(void) {
    srand(time(NULL));
    struct ALUMNO alumnos[A];

    for (int i = 0; i < A; i++) {
        rand_ALUMNO(&alumnos[i]);
        print_ALUMNO(alumnos[i]);
    }

    return 0;
}