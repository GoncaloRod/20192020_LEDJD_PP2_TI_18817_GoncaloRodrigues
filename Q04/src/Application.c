#define _CRTDBG_MAP_ALLOC
#include <crtdbg.h>

#include <stdio.h>
#include <stdlib.h>

#include "Structs.h"
#include "Collections.h"

int main(int argc, char** argv)
{
	HashTable* hashTable;
	Player* player;

	Player players[] = {
		{.nickname = "legobrainiac", .name = "Tomas Pinto", .age = 20},
		{.nickname = "IceN", .name = "Carlos Bruno", .age = 20},
		{.nickname = "Louis", .name = "Luis Lisboa", .age = 20},
		{.nickname = "Riki", .name = "Henrique Gomes", .age = 20},
		{.nickname = "GoncaloRod", .name = "Goncalo Rodrigues", .age = 20},
		{.nickname = "Core", .name = "Joao Castanheira", .age = 17},
		{.nickname = "Benemax", .name = "Leonardo", .age = 18},
		{.nickname = "Qwerty", .name = "David", .age = 17},
		{.nickname = "Dred", .name = "Andre Monteiro", .age = 19},
		{.nickname = "Vyper", .name = "Claudio Reis", .age = 20},
		{.nickname = "GoncaloRod", .name = "Fake Goncalo", .age = 19},
	};

	hashTable = CreateHashTable(10, &PlayerHash);

	// Add data from static array to hash table
	for (int i = 0; i < sizeof(players) / sizeof(Player); i++)
	{
		player = (Player*)malloc(sizeof(Player));

		strcpy(player->nickname, players[i].nickname);
		strcpy(player->name, players[i].name);
		player->age = players[i].age;

		HashTableAdd(hashTable, player, &ComparePlayers);
	}

	// Update
	player = HashTableGet(hashTable, &players[4], &ComparePlayers);
	player->age--;

	// Remove
	HashTableRemove(hashTable, &players[8], &ComparePlayers, &free);

	// Print hast table data to the screen
	PrintHashTable(hashTable, &PrintPlayer);

	// Calculate average for hash table data
	printf("\nHash table average: %.0f\n", HashTableAverage(hashTable, &GetPlayerAge));

	// Clear hash table from memory
	ClearHashTable(&hashTable, &free);

	_CrtDumpMemoryLeaks();

	return 0;
}
