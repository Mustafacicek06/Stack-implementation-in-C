// input-output stream header file
#include <iostream>
using namespace std;
// employee array size 
#define CAPACITY 100

// A structure creates a data type 
typedef struct Stack {
	int index;
	int employee[CAPACITY];
}Stacks;
// Real Stack
Stacks comp_Stack;
// Undo Stack
Stacks back_Stack;
// Controls for the undo function
bool control;
// main stack capacity control
int Stack_isFull() {
	if (comp_Stack.index >= CAPACITY - 1) return -1; else return 1;
}
// Returns true if Undo stack is empty, else false.
int BackStack_isEmpty() {
	if (back_Stack.index == -1)
		return -1;
	else
		return 1;
}
//  Returns true if Real stack is empty, else false.
int Stack_isEmpty() {
	if (comp_Stack.index == -1)
		return -1;
	else
		return 1;
}
// Adds an item in the stack. If the stack is full, 
// then it is said to be an Overflow condition.
void Stack_Push(int number) {
	// Real Stack control 
	if (Stack_isFull() == -1)
	{
		cout << "Could not add. Stack capacity is full.";
	}
	else
	{
		// Controls for the undo function
		control = true;
		comp_Stack.index++;
		comp_Stack.employee[comp_Stack.index] = number;
		cout << "Number addition is complete." << endl;


	}
}
// Pop: Removes an item from the stack. 
// The items are popped in the reversed order in which they are pushed.
// If the stack is empty, then it is said to be an Underflow condition.
int Stack_Pop() {
	int remove_employee;
	if (Stack_isEmpty() == -1)
	{
		cout << "Deletion failed. The stack is already empty." << endl;
		return -1;
	}
	else
	{
		// It backs up to the back stack for the undo function.
		// Controls for the undo function
		control = false;
		back_Stack.index++;
		remove_employee = comp_Stack.employee[comp_Stack.index];
		back_Stack.employee[back_Stack.index] = remove_employee;
		comp_Stack.index--;
		cout << "Number extraction from stack succeeded." << endl;
		return remove_employee;
	}

}
int undo() {
	int temp;
	if (BackStack_isEmpty() != -1 && control == false)
	{
		// If the pop function is used, it restores the backup.
		comp_Stack.index++;
		temp = back_Stack.employee[back_Stack.index];
		comp_Stack.employee[comp_Stack.index] = temp;
		back_Stack.index--;
		cout << temp << " Remove Undo is successful." << endl;
		return temp;
	}
	else
	{
		// It performs the undo function of the push function.
		temp = comp_Stack.employee[comp_Stack.index];
		comp_Stack.index--;
		// Controls for the undo function
		control = false;
		cout << temp << " Add Undo is successful." << endl;
		return temp;
	}



}

// Listing Function
void List() {
	int i;
	for (i = comp_Stack.index; i >= 0; i--)
		cout << comp_Stack.employee[i] << endl;
}


int main() {
	comp_Stack.index = -1;
	back_Stack.index = -1;

	char choice;
	int number;
	while (1)
	{
		cout << "\nAdd(a)\nRemove(r)\nUndo(u)\nList(l)\nQuit(q)\nYour Choice ? ";
		cin >> choice;
		switch (choice)
		{
		case 'a':
			cout << "Please enter number : ";
			cin >> number;
			Stack_Push(number);

			break;
		case 'r':
			Stack_Pop();
			break;
		case 'u':
			if (Stack_isEmpty() == -1)
				cout << "Undo is failed. The stack is already empty." << endl;
			else
				undo();
			break;
		case 'l':
			List();
			cout << "Listing successful." << endl;
			break;
		case 'q':
			exit(0);
		default:
			cout << "Please enter a correct letter." << endl;
			break;

		}
	}



	return 0;
}