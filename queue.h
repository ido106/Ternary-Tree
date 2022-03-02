/************
* Ido Aharon
* 01
* ex5
*************/
#ifndef _QUEUE_H
#define _QUEUE_H
#include "ex6.h"

// A linked list (LL) node to store a queue entry 
typedef struct QNode {
	void* key;
	struct QNode* next;
}QNode;

//The queue, front stores the front node of LL and rear stores the last node of LL
typedef struct Queue {
	struct QNode* front, * rear;
}Queue;

void printQueue(Member* root, void(*pBfsMem)(char* name, int id));

#endif
