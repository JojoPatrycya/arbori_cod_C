#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "arb_binO.h"
#include "avl.h"



nod* creeaza_radacina(nod *radacina, int info) 
{
	/*if (radacina)
	{
		printf("exista deja o radacina\n");
	}*/
	//else
	//{
		radacina = (nod*)malloc(sizeof(nod));
		if (radacina == NULL)
		{
			printf("Eroare alocare memorie nod ->");
			exit(-1);
		}
		radacina->cheie = info;
		radacina->fiu_stg = NULL;
		radacina->fiu_dr = NULL;
		return radacina;
		
		
	//}
}


nod* adauga_fiu(nod* radacina, int info)
{

	if (radacina == NULL)
	{
		return creeaza_radacina(radacina,info);
	}
	if (info <= radacina->cheie) //daca nodul ce vrem sa il adaugam e mai mic ca radacina
	{
		radacina->fiu_stg = adauga_fiu(radacina->fiu_stg, info);// adauga nodul in subarborele stg
	}
	else //daca nodul e mai mare ca radacina
	{
		radacina->fiu_dr = adauga_fiu(radacina->fiu_dr, info); //adauga nodul in subarb dr
	}
	return radacina;
}



nod* cautare_nod(nod* radacina, int info)
{
	if (radacina == NULL || radacina->cheie == info) //daca nu mai exista nod sau am ajuns la nodul cautat
	{
		return radacina; // returnam nodul
	}
	
	if (info < radacina->cheie) //daca nodul cautat e mai mic ca radacina
		{
			return cautare_nod(radacina->fiu_stg, info); // cauta in subarborele stg
		}
	return cautare_nod(radacina->fiu_dr, info); //altfel cauta in subarborele drept

	

}

void inordine1(nod* radacina) //SRD
{
	if (radacina != NULL)
	{
		inordine1(radacina->fiu_stg);
		printf("%d\n", radacina->cheie);
		inordine1(radacina->fiu_dr);
	}
}


void preordine1(nod* radacina) //RSD
{
	if (radacina != NULL)
	{
		printf("%d\n", radacina->cheie);
		preordine1(radacina->fiu_stg);
		preordine1(radacina->fiu_dr);
	}
}


void postordine1(nod* radacina) //SDR
{
	if (radacina != NULL)
	{
		postordine1(radacina->fiu_stg);
		postordine1(radacina->fiu_dr);
		printf("%d\n", radacina->cheie);
	}
}
void eliberare_memorie(nod* radacina)
{
	if (radacina != NULL)
	{
		eliberare_memorie(radacina->fiu_stg);
		eliberare_memorie(radacina->fiu_dr);
		free(radacina);
	}
}

nod* sterge1(nod* radacina, int info)
{
	if (radacina == NULL)
	{
		return NULL;
	}

	if (info < radacina->cheie) //daca nodul ce il vrem sters e mai mic ca radacina, il stergem din subarb stg
	{
		radacina->fiu_stg = sterge1(radacina->fiu_stg, info);
	}
	else if (info > radacina->cheie)
	{
		radacina->fiu_dr = sterge1(radacina->fiu_dr, info);//daca nodul ce il vrem sters e mai mic ca radacina, il stergem din subarb dr
	}
	else //daca nodul ce vrem sa il stergem e radacina
	{
		nod* aux = radacina;
		if (radacina->fiu_stg == NULL)
		{
			radacina = aux->fiu_dr;
			free(aux);
		}
		else if (radacina->fiu_dr == NULL)
		{
			radacina = aux->fiu_stg;
			free(aux);
		}
		else
		{
			nod* aux2 = radacina->fiu_dr; // Successor in inordine
			while (aux2->fiu_stg != NULL)
			{
				aux2 = aux2->fiu_stg;
			}

			radacina->cheie = aux2->cheie;
			radacina->fiu_dr = sterge1(radacina->fiu_dr, aux2->cheie);
		}
	}
	return radacina;
}

nod* cautare_random(nod *radacina, int val, int k)
{
	if (radacina != NULL && radacina->cheie==val) //daca am ajuns la nodul cautat
	{
		printf("s-a gasit nodul dupa %d incercari\n", k + 1);
		return radacina; // returnam nodul
	}
	if (radacina == NULL)
	{
		printf("nu s-a gasit nodul\n");
		return radacina;
	}
	if (val < radacina->cheie) //daca nodul cautat e mai mic ca radacina
	{
		
		return cautare_random(radacina->fiu_stg, val, k+1); // cauta in subarborele stg
	}
	
	return cautare_random(radacina->fiu_dr, val, k+1); //altfel cauta in subarborele drept




}

void creeaza_random(nod *radacina,TNodAVL *r)
{
	srand(time(NULL));
	int v[100], n = 0,vAVL[100];
	for (int i = 1; i <= 1000; i++)
	{
		int x = rand() % 1000;
		radacina = adauga_fiu(radacina, x);

		int y = rand() % 1000;
		r = adauga(r, y);

		if (i % 100 == 0)
		{
			v[n] = x;
			vAVL[n] = y;
			n++;
		}
		
	}
	printf("arbore binar: \n");
	inordine1(radacina);

	printf("\n\n");

	printf("vector valori pt binar: \n");
	for (int i = 0; i < n; i++)
	{
		printf("%d \n", v[i]);
	}
	
	
	//srand(time(NULL));
	printf("cautare pt binar: \n");
	for (int i = 1; i <= 10; i++)
	{
		int x = rand() % 1000;
		printf("val cautata este %d ", x);
		
		int k = 0;
		cautare_random(radacina, x, k);
		
	}	

	printf("arbore avl: \n");
    tiparArbore(r);

    printf("\n\n");
	
    printf("vectori valori pt avl: \n");
    for (int i = 0; i < n; i++)
    {
        printf("%d \n", vAVL[i]);
    }


    //srand(time(NULL));
    printf("cautare pt avl: \n");
    for (int i = 1; i <= 10; i++)
    {
        int x = rand() % 1000;
        printf("val cautata este %d ", x);

        int k = 0;
        cautare_random_avl(r, x, k);


    }

	
}

