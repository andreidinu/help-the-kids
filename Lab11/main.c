#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/* Structurile sunt folosite pentru a retine mai multe date (chiar si diferite,
spre deosebire de vectori) la un loc.
============================================================================= */

/* Definim structura Student si tipul de date folosit va fi
"struct Student_1". De exemplu: struct student a;*/
struct student {
    char nume[40];
    int an;
    float medie;
};
/* nume, an, medie se numesc campurile structurii. */

/* Definim o structura anonima pe care n-o vom mai putea instantia ulterior
si instantiem doar la definirea ei doua variabile de acest tip. */
struct {
    float abscisa, ordonata;
} punct1;

/* Definim structura Punct pe care o vom mai putea instantia ulterior de
fiecare data cand vom avea nevoie */
struct punct {
    float abscisa, ordonata;
} punct2;
/* De data aceasta putem oricand in cod sa instantiem: struct punct punct2; */

/* Ca sa nu mai caram dupa noi keyword-ul "struct", definim un tip (ca in
laboratorul de biti, tipul SET) */
typedef struct complex {
    float real, imaginar;
} Complex;
/* Acum vom putea instantia un numar complex in doua moduri:
    1. struct complex nr1;
    2. Complex nr1; */

/* Uniunile sunt grupari de tipuri de date care iti permit sa accesezi un
singur camp la un moment dat. Sunt folosite pentru a economisi memorie.
============================================================================= */

/* Exact ca la structuri, se pot crea typedef-uri si pentru uniuni. */
typedef union numar {
    char cifra;
    int intreg;
    double real;
} Numar;

/* Tipuri auxiliare folosite pentru demonstratii */
struct aux1 {
    char a;
    int b;
    double c;
};

struct aux2 {
    int b;
    char a;
    double c;
};

struct aux3 {
    double c;
    char a;
    int b;
};

void aduna_a_b_pune_rezultat_in_c(Complex a, Complex b, Complex *c) {
    c->real = a.real + b.real;
    c->imaginar = a.imaginar + b.imaginar;
}

void aduna_elementele_vectorului(Complex *v, int n, Complex *suma) {
    int i = 0;
    suma->real = 0;
    suma->imaginar = 0;

    for (i = 0; i < n; ++i) {
        aduna_a_b_pune_rezultat_in_c(*suma, v[i], suma);
    }
}

int main() {
    /* Initializare si accesarea campurilor */
    struct student s1, s2;
    
    strcpy(s1.nume, "George");
    s1.an = 1998;
    s1.medie = 9.25;

    strcpy(s2.nume, "Mirel");
    s2.an = 1995;
    s2.medie = 8.7;

    printf( "%s are media mai mare decat %s. E e inteles, deoarece el a facut "
            "deja TS in anul 2, fiind nascut in anul %d. Totusi, nu e o "
            "diferenta mare intre %f si %f. Exista speranta!\n", s1.nume,
            s2.nume, s2.an, s1.medie, s2.medie);

    /* Alocare dinamica de structuri */
    Complex *nr1, *v_complex;
    /* Alocarea unui numar complex */
    nr1 = (Complex *) malloc(1 * sizeof(Complex));
    /* Alocarea unui vector de 2 numere complexe */
    v_complex = (Complex *) malloc(3 * sizeof(Complex));

    /* Dereferentiere clasica. */
    (*nr1).real = 2;
    /* Accesarea membrului prin operatorul "->" */
    nr1->imaginar = 5;

    v_complex[0].real = 1;
    v_complex[0].imaginar = 2;
    v_complex[1].real = 5;
    v_complex[1].imaginar = 0;

    Complex suma;
    aduna_elementele_vectorului(v_complex, 2, &suma);
    aduna_a_b_pune_rezultat_in_c(suma, *nr1, &suma);

    printf("Suma tuturor numerelor complexe definite: %f + %fi.\n",
        suma.real, suma.imaginar);

    return 0;
}