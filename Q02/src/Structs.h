#ifndef STRUCTS_H_
#define STRUCTS_H_

#include <stdio.h>

typedef struct medicine
{
	int id;
	char name[32];
	int availableStock;
} Medicine;

/**
 * Compare 2 medicines.
 *
 * @param med1 Medicine 1.
 * @param med2 Medicine 2.
 *
 * @return 1 If med1 is greater than med2.
 * @return 0 If med1 is equal to med2.
 * @return -1 If med1 is less than med2.
 */
int CompareMedicines(void* med1, void* med2)
{
    Medicine m1 = *(Medicine*)med1;
    Medicine m2 = *(Medicine*)med2;

    if (m1.id > m2.id)
        return 1;
    else if (m1.id == m2.id)
        return 0;
    else
        return -1;
}

/**
 * Print a Medicine on the screen.
 *
 * @param medicine Address to the medicine to print.
 */
void PrintMedicine(void* medicine)
{
    Medicine med = *(Medicine*)medicine;

    printf("%d - %s - %d available\n", med.id, med.name, med.availableStock);
}

/**
 * Get stock from a medicine.
 *
 * @param medicine Address to the medicine to print.
 */
int GetMedicineStock(void* medicine)
{
    return ((Medicine*)medicine)->availableStock;
}

#endif
