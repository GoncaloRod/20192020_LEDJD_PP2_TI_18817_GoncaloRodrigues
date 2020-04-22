#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#include "Structs.h"
#include "Collections.h"

int main(int argc, char** argv)
{
	List* list = NULL;
	List* cur;
	Medicine* medicine;
	Medicine medicines[] = {
		{.id = 5437, .name = "Yeet", .availableStock = 20},
		{.id = 1245, .name = "Lmao", .availableStock = 20},
		{.id = 6346, .name = "Suck", .availableStock = 20},
		{.id = 7874, .name = "My Dick", .availableStock = 20},
	};

	for (int i = 0; i < sizeof(medicines) / sizeof(Medicine); i++)
	{
		medicine = (Medicine*)malloc(sizeof(Medicine));
		
		assert(medicine != NULL);

		medicine->id = medicines[i].id;
		medicines->availableStock	= medicines->availableStock;
		strcpy(medicine->name, medicines[i].name);

		AddSorted(&list, (void*)medicine, &CompareMedicines);
	}

	

	return 0;
}