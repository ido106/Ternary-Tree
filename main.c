/************
* Ido Aharon
* 01
* ex5
*************/
#include "ex6.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
	//definition of family
	Member* family = NULL;
	char choice;
	//print the menu and scan the option
	printMenu();
	//scan option
	scanf(" %c", &choice);
	//continue till break;
	while (choice !='0') {
		switch (choice) {
		case '1': createFamily(&family);
			break;
		case '2': addMeeting(&family);
			break;
		case '3': printFamTree(&family);
			break;
		case '4': isolation(&family);
			break;
		case '5': superSpreader(&family);
			break;
		case '6': vaccine(&family);
			break;
		case '7': printMenu();
			break;
		default: printf("Error: unrecognized operation.\n");
			break;
		}
		//print it only if the user didn't ask to print menu or print family
		if (choice != '7' && choice != '3')
			printf("Select the next operation (insert 7 for the entire menu):\n");
		//scan new choice
		scanf(" %c", &choice);
	}
	//free all memory from heap
	freeAll(family, 2);
	return 0;
}
