#include <stdio.h>
#include <stdlib.h>
#include "arb_binO.h"
#include "arb_binO.c"
#include "avl.h"
#include "avl.c"

int main()
{
	nod* radacina = NULL;
	/*radacina = adauga_fiu(radacina, 20);
	adauga_fiu(radacina, 10);
	adauga_fiu(radacina, 15);
	adauga_fiu(radacina, 13);
	adauga_fiu(radacina, 18);
	adauga_fiu(radacina, 5);
	*/

	
	

	TNodAVL* r = NULL;
	creeaza_random(radacina,r);
	//creeaza_random_avl(r);

	/*printf("inordine:\n");
	inordine(radacina);
	printf("preordine:\n");
	preordine(radacina);
	printf("postordine:\n");
	postordine(radacina);
	*/

	
	/*if (cautare_nod(radacina, 25))
	{
		printf("da");
	}
	else
	{
		printf("nu");
	}
	*/
	//sterge(radacina, 13);

	
	
	

	return 0;
}