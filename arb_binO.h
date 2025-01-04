#include <stdio.h>
#include <stdlib.h>
#include "avl.h"

#ifndef _ARB_BINO_H
#define _ARB_BINO_H

typedef struct nod
{
	int cheie; //informatia din nod
	struct nod* fiu_stg, * fiu_dr;
}nod;

nod *creeaza_radacina(nod *radacina, int info);

nod *adauga_fiu(nod *nod, int info);

nod *cautare_nod(nod *radacina, int info);

void inordine1(nod *radacina);

void postordine1(nod *radacina);

void preordine1(nod *radacina);

void eliberare_emorie(nod *radacina);

nod *sterge1(nod *radacina, int info);

nod* cautare_random(nod* radacina, int val, int k);

void creeaza_random(nod* radacina,TNodAVL *r);

#endif
