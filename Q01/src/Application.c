#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Collections.h"
#include "Structs.h"

int main(int argc, char** argv)
{
	Queue* queue = NULL;
	Person* person;
	int c;
	
	// Static array of people to populate queue just for simplicity sake.
	Person people[] = {
		{ .nhsNumber = 123456789, .name = "legobrainiac", .age = 20 },
		{ .nhsNumber = 123456789, .name = "Louis", .age = 21 },
		{ .nhsNumber = 123456789, .name = "IceN", .age = 20 },
		{ .nhsNumber = 123456789, .name = "Riki", .age = 19 },
		{ .nhsNumber = 123456789, .name = "Dred", .age = 19 },
		{ .nhsNumber = 123456789, .name = "Core", .age = 16 },
		{ .nhsNumber = 123456789, .name = "Qwerty", .age = 16 },
		{ .nhsNumber = 123456789, .name = "Bene", .age = 18 },
	};
	
	// Populate queue with data inside the array
	for (int i = 0; i < sizeof(people) / sizeof(Person); ++i)
	{
		person = (Person*)malloc(sizeof(Person));
		
		// Copy data from person in array to new person
		memcpy(person, people + i, sizeof(Person));
		
		Enqueue(&queue, (void*)person);
	}
	
	printf("People in queue:\n");
	PrintQueue(queue, &PrintPerson);
	
	printf("\nAge average: %.0f years\n", AverageQueue(queue, &GetPersonAge));

	ClearQueue(&queue, &free);
	
	return 0;
}