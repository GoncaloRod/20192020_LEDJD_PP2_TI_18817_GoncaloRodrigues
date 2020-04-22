#ifndef STRUCTS_H_
#define STRUCTS_H_

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

#endif
