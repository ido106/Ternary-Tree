/************
* Ido Aharon
* 01
* ex5
*************/
#include "queue.h"
#include "ex6.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

void iniQueue(Queue* q);
int isEmpty(Queue* q);
void enQueue(Queue* q, void* key, Member* fHead);
void* deQueue(Queue* q);
void destroyNodes(QNode* node);
void destoryQueue(Queue* q);

/***********************************************************
* Function Name: iniQueue
* Input: Queue* q
* Output: none
* Function operation: function that initiallizes the queue
************************************************************/
void iniQueue(Queue* q) {
	q->front = NULL;
	q->rear = NULL;
}

/****************************************************************
* Function Name: isEmpty
* Input: Queue* q
* Output: int (1 for yes 0 for no)
* Function operation: function that checks if the queue is empty
*****************************************************************/
int isEmpty(Queue* q) {
	return (q->front == NULL);
}

/**********************************************************************************************************
* Function Name: enQueue
* Input: Queue* q, void* key, Member* fHead
* Output: void
* Function operation: **fHead IS OPTIONAL** just in case we will have to free the heap if malloc fails.
*					  it can be removed if we want to use queue to other purposes!
*					  the function gets a queue and adds a new value to the rear of the queue.
*					  first, the function allocates memory for new temp node( the malloc is failed the
*					  function frees BOTH TREE AND QUEUE FROM HEAP. then, set the values to the temp node.
*					  if queue not empty, make this new node rear. if the queue is empty both front and
*					  rear point this node.
***********************************************************************************************************/
void enQueue(Queue* q, void* key, Member* fHead) {
	QNode* temp;
	//make new node and malloc space. if malloc fails, free all data
	temp = (QNode*)malloc(sizeof(QNode));
	// ** FREE ALL - BOTH TRRE AND QUEUE
	if (temp == NULL) {
		destoryQueue(q);
		failedMalloc(fHead);
	}
	//set the data of the new node
	temp->key = key;
	temp->next = NULL;
	//if queue not empty, make this new node rear
	if (!isEmpty(q)) {
		q->rear->next = temp;
		q->rear = temp;
	}
	//if the queue is empty both front and rear point this node
	else {
		q->front = q->rear = temp;
	}
}

/***********************************************************************************************************
* Function Name: deQueue
* Input: Queue* q
* Output: void*
* Function operation: the function deQueues a value from the queue. if the queue is empty, the function
*					  doesn't do anything. then the function sets a key to save the pointer of the current
*					  node, rellocates the pointer, free the current pointer(for he is not necessary anymore),
*					  and returns the pointer to the current data.
*************************************************************************************************************/
void* deQueue(Queue* q) {
	if (isEmpty(q))
		return NULL;
	QNode* temp;
	//keep the data of the front node
	void* key = q->front->key;
	//point the temp node to the front node in queue
	temp = q->front;
	//point the front pointer to next in turn
	q->front = q->front->next;
	//free data
	free(temp);
	//return the data
	return key;
}

/***************************************************************************
* Function Name: destroyNodes
* Input: QNode* node
* Output: none
* Function operation: recursive function that releases all nodes from queue
***************************************************************************/
void destroyNodes(QNode* node) {
	//exit condition
	if (node == NULL)
		return;
	//destroy next node
	destroyNodes(node->next);
	//free node
	node->next = NULL;
	free(node);
}

/**********************************************************************************************************
* Function Name: destoryQueue
* Input: Queue* q
* Output: none
* Function operation: function that frees all queue. first the function frees all nodes with DestroyNodes
*					  function, then frees the queue itself.
***********************************************************************************************************/
void destoryQueue(Queue* q) {
	//free all nodes
	destroyNodes(q->front);
	//free queue
	q->front = NULL;
	q->rear = NULL;
	free(q);
}

/**********************************************************************************************************
* Function Name: printQueue
* Input: Member **root,void(*pBfsMem)(char*name,int id)
* Output: none
* Function operation: the function gets the root of the tree and prints all member sorted by BFS. this is
*					  a generic-type function, printing with any kind of output.
*					  if the famiily is not created return. malloc new queue(if malloc failed freeAll and
*					  exit. initiallize queue, set the current member as the head of the family and enter
*					  the loop that prints the tree BFS-sorted until all family members are printed.
***********************************************************************************************************/
void printQueue(Member* root, void(*pBfsMem)(char* name, int id)) {
	//if family is not created don't do anything
	if (root == NULL)
		return;
	//define queue and malloc space
	Queue* q;
	q = (Queue*)malloc(sizeof(Queue));
	//if malloc fails release all allocated memory from heap and exit
	if (q == NULL) {
		destoryQueue(q);
		freeAll(root, 1);
	}
	//initiallize queue
	iniQueue(q);
	//current member is the head of the family
	Member* cMember = root;
	//while loop that runs untill all family members are wasted
	while (cMember != NULL) {
		//print member
		pBfsMem(cMember->name, cMember->id);
		//if there is a member in the left side add him to queue
		if (cMember->left != NULL)
			enQueue(q, (Member*)cMember->left, root);
		//if there is a member in the middle side add him to queue
		if (cMember->middle != NULL)
			enQueue(q, (Member*)cMember->middle, root);
		//if there is a member in the right side add him to queue.
		if (cMember->right != NULL)
			enQueue(q, (Member*)cMember->right, root);
		//set the current member as the first member shown in the queue and continue till all members are printed
		cMember = (Member*)deQueue(q);
	}
	//free queue
	destoryQueue(q);
}
