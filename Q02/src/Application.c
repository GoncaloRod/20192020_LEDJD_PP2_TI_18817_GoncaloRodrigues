#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#include "Structs.h"
#include "Collections.h"

int main(int argc, char** argv)
{
	List* list = NULL;
	Medicine* medicine;
	Medicine med;

	// Static array of people to populate queue just for simplicity sake.
	Medicine medicines[] = {
		{.id = 5437, .name = "Med 1", .availableStock = 20},
		{.id = 1245, .name = "Med 2", .availableStock = 20},
		{.id = 6346, .name = "Med 3", .availableStock = 20},
		{.id = 7874, .name = "Med 4", .availableStock = 20},
		{.id = 3537, .name = "Med 5", .availableStock = 0}
	};

	// Populate list with data inside the array
	for (int i = 0; i < sizeof(medicines) / sizeof(Medicine); i++)
	{
		medicine = (Medicine*)malloc(sizeof(Medicine));
		
		assert(medicine != NULL);

		medicine->id = medicines[i].id;
		medicine->availableStock = medicines[i].availableStock;
		strcpy(medicine->name, medicines[i].name);

		AddSorted(&list, (void*)medicine, &CompareMedicines);
	}

	// Update
	med.id = 1245;
	medicine = GetElement(list, &med, &CompareMedicines);
	medicine->availableStock += 5;

	// Remove
	med.id = 5437;
	RemoveElement(&list, &med, &CompareMedicines, &free);

	// Prints
	PrintListAscending(list, &PrintMedicine);

	printf("\n");

	PrintListDescending(list, &PrintMedicine);

	printf("\nTotal stock: %d\n", ListSum(list, &GetMedicineStock));
	printf("Average stock: %.0f\n", ListAverage(list, &GetMedicineStock));

	// Clear list
	ClearList(&list, &free);

	return 0;
}