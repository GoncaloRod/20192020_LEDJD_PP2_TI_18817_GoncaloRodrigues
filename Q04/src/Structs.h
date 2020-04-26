#ifndef STRUCTS_H_
#define STRUCTS_H_

#include <stdio.h>
#include <string.h>
#include <assert.h>

typedef struct player
{
	char nickname[32];
	char name[32];
	int age;
} Player;

/**
 * Calculate hash value for a player.
 *
 * @param player Player to calculate hash value.
 * @param hashSize Size of the hash.
 */
int PlayerHash(void* player, int hashSize)
{
	int nicknameSum = 0;
	Player* p;

	// Ensure parameters were passed correctly
	assert(player != NULL);

	p = (Player*)player;

	for (int i = 0; i < strlen(p->nickname); i++)
		nicknameSum += (int)p->nickname[i];

	return nicknameSum % hashSize;
}

/**
 * Compare two players.
 *
 * @param player1 Player 1 to compare.
 * @param player2 Player 2 to compare.
 *
 * @return 1 if player1 is greater than player2.
 * @return 0 if player1 is equal to player2.
 * @return -1 if player1 is less than player2.
 */
int ComparePlayers(void* player1, void* player2)
{
	// Ensure parameters were passed correctly
	assert(player1 != NULL);
	assert(player2 != NULL);
	
	return strcmp(((Player*)player1)->nickname, ((Player*)player2)->nickname);
}

/**
 * Print a player on the screen.
 *
 * @param player Player to print.
 */
void PrintPlayer(void* player)
{
	Player* p;

	// Ensure parameters were passes correctly
	assert(player != NULL);

	p = (Player*)player;

	printf("\"%s\" %s %d years\n", p->nickname, p->name, p->age);
}

/**
 * Get the age of a player.
 *
 * @param player Player to get age.
 */
int GetPlayerAge(void* player)
{
	// Ensure parameters were passed correctly
	assert(player != NULL);

	return ((Player*)player)->age;
}

#endif
