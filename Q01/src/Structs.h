#ifndef STRUCTS_H_
#define STRUCTS_H_

#include <stdio.h>
#include <assert.h>

typedef struct person
{
	int nhsNumber;
	char name[32];
	int age;
} Person;

void PrintPerson(void* person)
{
	Person* p = (Person*) person;
	
	printf("%s, %d years, number %d\n", p->name, p->age, p->nhsNumber);
}

float GetPersonAge(void* person)
{
	assert(person!= NULL);
	
	return (float)((Person*)person)->age;
}

#endif
