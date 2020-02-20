#ifndef COLLECTIONS_H_
#define COLLECTIONS_H_

typedef struct _node
{
	struct _node* next;
	void* value;
} Node;

typedef struct _list
{
	Node* head;
	Node* tail;
	int count;
} List;

List* CreateList();
static Node* CreateNode();

void Enqueue(List* list, void* data);
void* Dequeue(List* list);
void* Peek(List* list);

void FreeList(List* list, void (*freeValue)(void*));

#endif