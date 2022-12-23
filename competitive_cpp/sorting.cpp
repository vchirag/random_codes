#include<iostream>
#include<stdio.h>
// #include<array>
#include<ctime>
#include<cstdlib>

class arraySort
{
private:
	// Number of elements in the array
	int nElements = 5;

	// Displays the current array
	int arrDisplay(int* arr)
	{	
		std::cout << "The randomly generated array of 5 numbers between 1 and 100 is:\n";
		for(int i = 0; i < nElements; i++)
		{
			std::cout << arr[i] << " ";
		}

		std::cout << "\n";

		return 0;
	}

	int sortDisplay(int* arr)
	{
		for(int i = 0; i < nElements; i++)
		{
			std::cout << arr[i] << " ";
		}

		std::cout << "\n";

		return 0;
	}

	// Variables for choice menu
	int choice = 0;
	int choiceMin = 1;
	int choiceMax = 3;

	int bubbleSort(int* arr)
	{
		int temp = 0;
		int flag = 0;

		std::cout << "\n";

		for(int i = 0; i < nElements - 1; i++)
		{
			flag = 0;
			for(int j = 0; j < nElements - 1 - i; j++)
			{
				if(arr[j] > arr[j+1])
				{
					temp = arr[j+1];
					arr[j+1] = arr[j];
					arr[j] = temp;
					flag = 1;
				}
				// std::cout << "\n";
				sortDisplay(arr);
			}

			std::cout << "\nArray after pass " << i + 1 << "\n";
			sortDisplay(arr);
			std::cout << "\n";
			
			if(flag == 0)
				break;
		}


		return 0;
	}
	
public:
	// Constructor of the class
	arraySort();

	// Giving the user choice to select the type of sorting technique
	int sortSelector(int* arr)
	{
		std::cout << "\n\n1 = Bubble Sort\n";
		std::cout << "2 = Insertion Sort\n";
		std::cout << "3 = Selection Sort\n";

		std::cout << "\nEnter the sort type (1-3): ";
		std::cin >> choice;
		
		switch(choice)
		{
			case 1: 
				bubbleSort(arr);			
				break;

			case 2: 
				// insertionSort();
				std::cout << "success";
				break;

			case 3: 
				// selectionSort();
				std::cout << "success";
				break;
				
			default:
				std::cout << "Enter again!\n\n";
				std::cout << "--------------------";
				
				// Recursion to repeat the choice selection for an invalid choice
				sortSelector(arr);
		}
		return 0;
	}


};
	// Constructor
	arraySort::arraySort()
	{
		// Declare an array with (nElements - 1) elements
		int arr[nElements - 1];

		// Initialize random number generator
		srand(time(0));

		for(int i = 0; i <= nElements; i++)
		{
			// Assign the ith index some random number between 1 and 1000
			arr[i] = (rand() % 100) + 1;
		}

		// Call the display function
		arrDisplay(arr);
		sortSelector(arr);
	}




int main()
{
	arraySort objSort;

	return 0;
}





