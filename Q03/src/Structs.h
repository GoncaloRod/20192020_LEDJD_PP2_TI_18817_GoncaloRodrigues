#ifndef STRUCTS_H_
#define STRUCTS_H_

#include <stdio.h>
#include <assert.h>
#include <string.h>

typedef struct affiliate
{
	int id;
	char name[32];
	int age;
} Affiliate;

/**
 * Calculate hash code for an affiliate.
 *
 * @param data Memory address of the affiliate.
 * @param size Size of the hash table.
 */
int AffiliateHash(void* data, int hashSize)
{
	// Ensure that parameters were passed correctly
	assert(data != NULL);

	return ((Affiliate*)data)->id % hashSize;
}

/**
 * Compare to affiliates.
 *
 * @param affiliate1 Affiliate 1 to compare.
 * @param affiliate2 Affiliate 2 to compare.
 *
 * @return 1 if affiliate1 is greater than affiliate2.
 * @return 0 if affiliate1 is equal to affiliate2.
 * @return -1 if affiliate1 is less than affiliate2.
 */
int CompareAffiliates(void* affiliate1, void* affiliate2)
{
    Affiliate* aff1;
    Affiliate* aff2;

    // Ensure parameters were passed correctly
    assert(affiliate1 != NULL);
    assert(affiliate2 != NULL);

    aff1 = (Affiliate*)affiliate1;
    aff2 = (Affiliate*)affiliate2;

    if (aff1->id > aff2->id)
        return 1;
    else if (aff1->id == aff2->id)
        return 0;
    else
        return -1;
}

/**
 * Print an affiliate to the screen.
 *
 * @param affiliate Memory address of the affiliate to print.
 */
void PrintAffiliate(void* affiliate)
{
    Affiliate* aff;

    // Ensure parameters were passed correctly
    assert(affiliate != NULL);

    aff = (Affiliate*)affiliate;

    printf("%s, %d years, number %d", aff->name, aff->age, aff->id);
}

#endif
