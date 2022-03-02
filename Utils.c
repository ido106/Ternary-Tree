/************
* Ido Aharon
* 01
* ex5
*************/
#include <stdio.h>
#include "Utils.h"
#include "ex6.h"
#define COUNT 8


/***********************************************************
* Function Name: print2DUtil
* Input: Member* root, int space
* Output: none
* Function operation: Function to print Trinary tree in 2D
*					  It does reverse inorder traversal
*					  ADDED FROM PIAZZA !
************************************************************/
void print2DUtil(Member* root, int space)
{
	// Base case 
	if (root == NULL)
		return;
	// Increase distance between levels 
	space += COUNT;
	// Process right child first 
	print2DUtil(root->right, space);
	for (int i = COUNT; i < space; i++)
		printf(" ");
	printf("%s %d\n", root->name, root->id);
	// Process middle child 
	print2DUtil(root->middle, space);
	printf("\n");
	// Process left child 
	print2DUtil(root->left, space);
}
