#include<iostream>
#include<stdio.h>

// Define a structure to store the (kind-of) doubly linked list node
struct node
{
	int data;
	struct node* left;
	struct node* right;
};



struct node* create()
{
	// Initializing a new object of the structure
	struct node* newnode;

	// Allocating memory to the object newnode
	newnode = (struct node*)malloc(sizeof(struct node));

	// A variable to store data
	char x;

	std::cout << "\nEnter data (N for NO data):";  
	std::cin >> x;

	// Leaving the node of the tree 
	if ((char)x == 'N')
		return 0;

	// Recursive filling of the nodes
	else
	{
		// Filling in the x value in the data variable of the structure
		newnode -> data = (int)x;

		// Asking if whether this node has a left child or not
		// If yes, dynamically fill it until terminated by 
		std::cout << "\nLeft child of " << x << ": ";
		newnode -> left = create();

		// Similarly filling the rught child of the respective node
		std::cout << "\nRight child of " << x << ": ";
		newnode -> right = create();
		
		return newnode;
	}


}


int main()
{
	// Create an object of the structure node
	struct node* root;

	// Dynamically allocate the memory to this node using recursive call on create function
	root = create();
}
