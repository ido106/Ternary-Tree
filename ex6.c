/************
* Ido Aharon
* 01
* ex5
*************/

#include "Utils.h"
#include "ex6.h"
#include "queue.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

static Member* newMember(char* name, int id, Member* fHead,Member* father);
static Member* findMember(int id, Member* currentMember);
static void getNameID(char* name, int* id);
static void printPrintMenu();
static void printPrintMenu();
static void printPreOrder(Member* root);
static void printLeftOrder(Member* root);
static void pBfsTree(char* name, int id);
static void stayHomeBfs(char* name, int id);

/*********************************************************************************************************
* Function Name: superSpreader
* Input: Member** fhead
* Output: none
* Function operation: the function get a member that got infected and warns father and all sub-tree BFS 
*					  sorted. this is a generic function using pBfsTree function and PrintQueue function,
*					  so it's not necesarry to rewrite the code.
*********************************************************************************************************/
void superSpreader(Member** fhead) {
	if (*fhead == NULL) {
		printf("Please create the family first\n");
		return;
	}
	//suspected member
	Member* susMember = NULL;
	int id;
	printf("Enter the ID of the suspected Superspreader\n");
	scanf(" %d", &id);
	//find the pointer of the chosen member
	susMember = findMember(id, *fhead);
	//check if the suspected member does not exist
	if (susMember == NULL) {
		printf("ID %d does not exist\n", id);
		return;
	}
	//print the father
	if(susMember->father!=NULL)
		printf("#StayHome! %s %d\n", susMember->father->name, susMember->father->id);
	//print BFS sorted all next meetings
	printQueue(susMember, stayHomeBfs);
}

/*********************************************************************************
* Function Name: printFamTree
* Input: Member** fHead
* Output: none
* Function operation: the function prints the family tree as the next choices:
*					  1) 2D Tree print 2) pre order 3) left order 4) BFS order
*					  if tree is empty don't print anything
*********************************************************************************/
void printFamTree(Member** fHead) {
	char choice;
	//print the menu and scan the choice
	printPrintMenu();
	scanf(" %c", &choice);
	//continue till input is valid
	while (1) {
		switch (choice) {
		case '0':
			//return to main menu option
			printMenu();
			return;
			break;
		case '1':
			//if family is not created don't print
			if (*fHead != NULL)
				print2DUtil(*fHead, SPACES);
			//go back to main meny
			printMenu();
			return;
			break;
		case '2':
			//if family is not created don't print
			if (*fHead != NULL)
				printPreOrder(*fHead);
			//go back to main menu
			printMenu();
			return;
			break;
		case '3':
			//if family is not created don't print
			if (*fHead != NULL)
				printLeftOrder(*fHead);
			//go back to main menu
			printMenu();
			return;
			break;
		case '4':
			//if family is not created don't print
			if (*fHead != NULL)
				printQueue(*fHead, pBfsTree);
			//go back to main menu
			printMenu();
			return;
			break;
		default:
			//if it's an invalid input, print an error message
			printf("Error: unrecognized operation.\n");
			//print the menu and scan the choice
			printPrintMenu();
			scanf(" %c", &choice);
			break;
		}
	}
}

/*********************************************************************************************
* Function Name: pBfsTree
* Input: char* name, int id
* Output: none
* Function operation: the function prints the name and the id of the member with space between
**********************************************************************************************/
void pBfsTree(char* name, int id) {
	printf("%s %d\n", name, id);
}

/***************************************************
* Function Name: pBfsTree
* Input: char* name, int id
* Output: none
* Function operation: stay home BFS SORTED printing
****************************************************/
void stayHomeBfs(char* name, int id) {
	printf("#StayHome! %s %d\n", name, id);
}

/*********************************************************************************
* Function Name: printLeftOrder
* Input: Member* root
* Output: none
* Function operation: the function prints the family tree Left-order,recursively.
*********************************************************************************/
void printLeftOrder(Member* root) {
	if (root == NULL)
		return;
	printLeftOrder(root->left);
	printf("%s ID: %d\n", root->name, root->id);
	printLeftOrder(root->middle);
	printLeftOrder(root->right);
}

/*********************************************************************************
* Function Name: printPreOrder
* Input: Member* root
* Output: none
* Function operation: the function prints the family tree pre-order,recursively.
*********************************************************************************/
void printPreOrder(Member* root) {
	if (root == NULL)
		return;
	printf("%s ID: %d\n", root->name, root->id);
	printPreOrder(root->left);
	printPreOrder(root->middle);
	printPreOrder(root->right);
}

/*********************************************************************************************************
* Function Name: vaccine
* Input: Member** fhead
* Output: none
* Function operation: the function gets a member that got vaccinated. then function frees that member and
*					  all of his meetings for they are in no harm any more. first get the id of the
*					  member who got vaccinated. then release the pointer of the father leading to this
*					  meeting (only if the pointer is not aimed at the root), then free that specipic
*					  member and all of his subtree with a message. if the pointer was aimed at the root,
*					  set the pointer of the first member to NULL again.
*********************************************************************************************************/
void vaccine(Member** fhead) {
	if (*fhead == NULL) {
		printf("Please create the family first\n");
		return;
	}
	int id;
	//the suspected member
	Member* susMember = NULL;
	printf("Who got vaccinated (ID)?\n");
	scanf(" %d", &id);
	//get the member who vaccinated
	susMember = findMember(id, *fhead);
	//check if the suspected member does not exist
	if (susMember == NULL) {
		printf("There is no ID %d\n", id);
		return;
	}
	//release father from son only if its not the root
	if (susMember != *fhead && susMember->father->left == susMember)
		susMember->father->left = NULL;
	else if (susMember != *fhead && susMember->father->middle == susMember)
		susMember->father->middle = NULL;
	else if (susMember != *fhead && susMember->father->right == susMember)
		susMember->father->right = NULL;
	//free tree and print a message with function
	freeAll(susMember, 2);
	//if the vaccinated member is the head of the family reset pointer to root
	if (susMember == *fhead)
		*fhead = NULL;
}

/******************************************************
* Function Name: printPrintMenu
* Input: none
* Output: none
* Function operation: the function prints the print menu
********************************************************/
void printPrintMenu() {
	printf("Please select an operation:\n\
\t0. Return to the main menu.\n\
\t1. Print Trin-Ari family.\n\
\t2. Print Pre-order.\n\
\t3. Print Left-order.\n\
\t4. Print BFS.\n");
}

/******************************************************
* Function Name: printMenu
* Input: none
* Output: none
* Function operation: the function prints the main menu
********************************************************/
void printMenu() {
	printf("Please select an operation:\n\
\t0. Exit.\n\
\t1. Create family.\n\
\t2. Add family member.\n\
\t3. Print Family-Tree.\n\
\t4. Bidud.\n\
\t5. Superspreader.\n\
\t6. Vaccine.\n\
\t7. Print the menu.\n");
}

/************************************************************************************************************
* Function Name: newMember
* Input: char* name, int id, Member* fHead
* Output: Member*
* Function operation: the function creates a new member. first, the function allocates new memory from heap.
*					  if the malloc fails, the function releases all memory from heap and exit.
*					  after, the function set the correct id, name and resets the left,middle and right
*					  meetings.
*************************************************************************************************************/
Member* newMember(char* name, int id, Member* fHead,Member* father) {
	Member* pMember = (Member*)malloc(sizeof(Member));
	//if malloc fails print error, free all allocated memory and exit from called function
	if (pMember == NULL)
		failedMalloc(fHead);
	//set the id
	pMember->id = id;
	//set the name address pointer
	pMember->name = name;
	//reset meetings
	pMember->left = NULL;
	pMember->middle = NULL;
	pMember->right = NULL;
	pMember->father = father;
	return pMember;
}

/********************************************************************************************************
* Function Name: freeAll
* Input: Member *fHead,int choice
* Output: none
* Function operation: the function releases chosen memory from heap. also, if choice==2 function prints
*					  survival message.
********************************************************************************************************/
void freeAll(Member *fHead,int choice) {
	//if pointer is NULL return
	if (!fHead)
		return;
	freeAll(fHead->left,choice);
	freeAll(fHead->middle,choice);
	freeAll(fHead->right,choice);
	if(choice==2)
		printf("%s ID: %d Survived!\n", fHead->name, fHead->id);
	free(fHead->name);
	free(fHead);
}

/******************************************************************************************************
* Function Name: createFamily
* Input: Member** fHead
* Output: none
* Function operation: the function creates the root- first the function checks if the root has already
*					  been created. after the function mallocs new memory for name(if malloc fail free
*					  all and exit). after, the function gets the name and id of the head of family,
*					  and creates the root.
******************************************************************************************************/
void createFamily(Member** fHead) {
	char* name;
	int id;
	//check if the family has already been created
	if (*fHead != NULL) {
		printf("The family has already been created\n");
		return;
	}
	//else, allocate new memory for the head of the family and check if the allocation succeedd
	name = (char*)malloc(sizeof(char) * NAME);
	if (name == NULL)
		failedMalloc(*fHead);
	//get the name and id
	getNameID(name, &id);
	//create head of family and print hello message
	*fHead = newMember(name, id, *fHead, NULL);
	printf("Hello %s, ID: %d\n", name, id);
}

/******************************************************************************************************
* Function Name: addMeeting
* Input: Member** head
* Output: none
* Function operation: the function creates a meeting(add a child to a leaf). if there is no family, the
*					  function prints error. else, the function get the id of the member we want to set
*				      a meeting with. if he's not exist, the function print error. else, the function
*					  mallocs new space to the name(if malloc fails exit) and keep asking for an
*					  unoccupied id. the function sets the meeting from left to right order, and if
*					  there is no meetings left for the original member, the function frees the malloc
*					  name,prints an error and exit.
********************************************************************************************************/
void addMeeting(Member** head) {
	//the chosen member to make an appointment, also set the pointer to the first member
	Member* cMember = NULL, * pFirst = *head, * isFound = NULL;
	//original id and the futured selected id
	int oId, sId;
	char* name;
	//check if the family is not created
	if (*head == NULL) {
		printf("Please create the family first\n");
		return;
	}
	printf("Enter the ID of the person who wants to make an appointment?\n");
	scanf(" %d", &oId);
	//find the wanted member
	cMember = findMember(oId, pFirst);
	//check if the member doesn't exist
	if (cMember == NULL) {
		printf("There is no ID %d\n", oId);
		return;
	}
	//check if the member is full of meetings
	if (cMember->left != NULL && cMember->middle != NULL && cMember->right != NULL) {
		printf("%s ID: %d can't meet more than 3 members!\n", cMember->name, cMember->id);
		return;
	}
	//malloc new space for name
	name = (char*)malloc(sizeof(char) * NAME);
	//check if the malloc failed
	if (name == NULL) 
		failedMalloc(*head);
	//get name and id
	getNameID(name, &sId);
	//search if the ID is already belong to someone
	isFound = findMember(sId, pFirst);
	//if the id is already exist keep asking for new id
	while (isFound != NULL) {
		//print error and get name again
		printf("ID %d belongs to %s\n", isFound->id, isFound->name);
		getNameID(name, &sId);
		isFound = findMember(sId, pFirst);
	}
	//create member, first check if left side is available
	if (cMember->left == NULL)
		cMember->left = newMember(name, sId, *head, cMember);
	//else, check middle
	else if (cMember->middle == NULL)
		cMember->middle = newMember(name, sId, *head, cMember);
	//else set into right
	else
		cMember->right = newMember(name, sId, *head, cMember);
	//print a welcome message
	printf("Hello %s, ID: %d\n", name, sId);
}

/*****************************************************************************************************
* Function Name: findMember
* Input: int id, Member* currentMember
* Output: Member*
* Function operation:  Potential recursive function. exit condition: if pointer is NULL return NULL.
*					   else compare between id's. if identical- return the current member pointer.
*					   else, search for member from left to right, recursively.
******************************************************************************************************/
Member* findMember(int id, Member* currentMember) {
	Member* left = NULL, * middle = NULL, * right = NULL;
	//if the root is empty return null
	if (currentMember == NULL)
		return NULL;
	//check if the id's are the same. if they are, return pointer to this member
	if (id == currentMember->id)
		return currentMember;
	//else continue checking with the next members, start with left
	left= findMember(id, currentMember->left);
	if (left != NULL)
		return left;
	//if left not found search in middle
	middle = findMember(id, currentMember->middle);
	if (middle != NULL)
		return middle;
	//if right not found search in right.
	right = findMember(id, currentMember->right);
	if (right != NULL)
		return right;
	return NULL;
}

/************************************************************************************************************
* Function Name: isolation
* Input: Member** fhead
* Output: none
* Function operation: the function get a member that got infected and warns all direct meetings to go
*					  to isolation: father first, than member himself, left meeting, middle meeting, right
*					  meeting. if the family is not created ask for creation first. else, ask for suspected
*					  member ID. if there is no such member- print error and exit. else, print the isolation
*					  warning as the above order.
************************************************************************************************************/
void isolation(Member** fhead) {
	if (*fhead == NULL) {
		printf("Please create the family first\n");
		return;
	}
	//suspected member
	Member* susMember = NULL;
	int id;
	printf("Enter the ID of the suspected member\n");
	scanf(" %d", &id);
	//find the pointer of the chosen member
	susMember = findMember(id, *fhead);
	//check if the suspected member does not exist
	if (susMember == NULL) {
		printf("ID %d does not exist\n", id);
		return;
	}
	//if father does exist print him
	if (susMember->father != NULL)
		printf("#StayHome! %s %d\n", susMember->father->name, susMember->father->id);
	//print the suspected member
	printf("#StayHome! %s %d\n", susMember->name, susMember->id);
	//print left meeting if exist
	if (susMember->left != NULL)
		printf("#StayHome! %s %d\n", susMember->left->name, susMember->left->id);
	//print middle meeting
	if (susMember->middle != NULL)
		printf("#StayHome! %s %d\n", susMember->middle->name, susMember->middle->id);
	//print right meeting
	if (susMember->right != NULL)
		printf("#StayHome! %s %d\n", susMember->right->name, susMember->right->id);
}

/*****************************************************************************************************
* Function Name: getNameID
* Input: char* name, int* id
* Output: none
* Function operation:  the function resets the name in case the name has already set before. then the
*					   function asks for name and id and sets them.
******************************************************************************************************/
void getNameID(char* name, int* id) {
	//reset name
	for (int i = 0; i < NAME; i++)
		name[i] = '\0';
	//get name
	printf("enter name\n");
	scanf(" %[^\n]", name);
	//get id
	printf("enter ID\n");
	scanf(" %d", id);
}

/***************************************************************************************************
* Function Name: failedMalloc
* Input: Member* fHead
* Output: none
* Function operation:  the function prints that the malloc fails, releases all memory from heap and
*					   exit from program.
****************************************************************************************************/
void failedMalloc(Member* fHead) {
	printf("Malloc Failed!\n");
	freeAll(fHead, 1);
	exit(1);
}
