/************
* Ido Aharon
* 01
* ex5
*************/
#ifndef _EX6_H_
#define _EX6_H_

//including the \0
#define NAME 50

//name has to allocate dinamicly
typedef struct Member
{
	char* name;
	int id;
	struct Member* right;
	struct Member* middle;
	struct Member* left;
	struct Member* father;
}Member;

void printMenu();
void createFamily(Member** fHead);
void addMeeting(Member** head);
void freeAll(Member* fHead,int choice);
void printFamTree(Member** fHead);
void failedMalloc(Member* fHead);
void isolation(Member** fhead);
void superSpreader(Member** fhead);
void vaccine(Member** fhead);

#endif
