/*
Programme: StackAndQueueWithPointers.cpp
Written by: Tim Binding
Written on: 10/02/2017

Description: This is a programme that consists of two computer memory structures 
for assigning and using memory in the 'Windowless 9' operating system. 
These two computer memory structures are called a 'stack' and a 'queue'.

The stack and queue in this programme allows for the pushing and enqueuing 
of data depending on the amount of memory that is available and this programme
allows for the poping and dequeuing data that is in the stack and queue. 

The stack will display its numbers based on the last one that was pushed in, 
the queue will display its numbers by starting with the one that was implemented 
first.

Overview - Explanation of the code for users who wish to incorporate the 
existing code into their own programmes.

Code overview - Technical explanation of code for people who wish to edit the 
code.
*/

#include<iostream>

using namespace std;

/*
Node class:
	This class is used for the creation of nodes.

	The First declaration in the class is saying that type T for template 
	contains a variable and declares that variable as type T, this variable 
	is used for taking values from a 'for' loop in the 'programme' function
	and then put that through two functions called 'push' and 'enqueue'.

	pNext and pPrevious are pointers that are set to 'null' meaning that they 
	are pointing to nothing.
*/
template<typename T>
class Node
{
public:
	T value;
	Node *pNext = nullptr;
	Node *pPrevious = nullptr;
};

template <typename T>
class Stack
{
public:
	~Stack(void);
	void push(T value);
	Node<T>* nodePop(void);
	T pop(void);

protected:
	int count = 0; //Not used
	Node<T> *pTop = nullptr; //Top pointer for the top of the stack
};

template <typename T>
class Queue : protected Stack<T>
{
private:
	Node<T> *pFront = nullptr; //The front pointer for the queue
public:
	Queue(void);
	~Queue(void);
	virtual void enqueue(T value);
	virtual Node<T>* nodeDequeue(void);
	virtual T dequeue(void);
};

/*
Deconstructor stack function:
	Overview: 
	This function uses a while loop to deconstruct the stack to take back the 
	memory that was allocated. The while loop takes layers off the stack off 
	by constantly deleting 'nodePop's returning value until pTop is points 
	to nothing.

	Code overview:
	While the top of the stack is not empty then
		It will use a delete operator to reclaim the memory space taken up by 
		the data that the pointers are referencing data in nodePop.
*/
template <typename T>
Stack<T>::~Stack(void)
{
	while (pTop != nullptr)
	{
		delete nodePop();
	}
}

/*
Stack push function:
	Overview:
	This function pushes the numbers from the 'for' loop in the 'programme' 
	function into the stack, creating a chain of nodes based on the values 
	implemented. This function creates new memory space and then stores the 
	values inside there.

	Code overview:
	The first line of this function allocates memory for a new node.

	The second line makes the new node (pTmp) point to the property called 
    'value'.

	The third line points to the node that is currently on the top of the stack 
    and names it pTop.
    
	The fourth line makes pTop replaces pTmp as the new node.
*/
template <typename T>
void Stack<T>::push(T value) 
{
	Node<T>* pTmp = new Node<T>;
	pTmp->value = value; 
	pTmp->pNext = pTop;
	pTop = pTmp;
}

/*
Stack pop:
	Overview: 
	This section of code is getting rid of a layer on the stack a process that 
    is referred to as pop. This function removes one data item every time its 
    called. The function returns a value at the end of the function so that it 
    can be used in the 'programme' function to be displayed to a screen.
	
	Code overview:
	On the first line pTmp is declared as a pointer
	
	The second line creates a variable called ret (return) and assigns it to 
    zero so it can be used to return the value at the end of the function.
	
	The programme asks if pTmp points to nothing then
		The pointer is dereferenced and the variable 'ret' becomes whatever's in 
        the 'value'.
	If pTmp does equal to nothing then
		The programme will throw an exception if pTmp is empty.

	The delete operator is used on pTmp to reclaim the memory.

	The contents of the 'ret' variable is returned and gives back the value when 
    the function is called in the programme function.
*/
template <typename T>
T Stack<T>::pop(void)
{
	Node<T> *pTmp = nodePop();
	int ret = 0;

	if (pTmp != nullptr)
	{
		ret = pTmp->value;
	}
	else
	{
		throw "Stack Empty";
	}
	delete pTmp;
	return ret;
}

/*
Node pop:
	Overview:
	This section of code is used for removing nodes in the stack, this 
    function is called in the pop function. This removes one node
	each time it is called. Nodepop returns a value from the stack 
	this then goes to the pop function.

	Code overview:
	The first line of code for this function references to the items that's on 
    the currently on the top of the stack and assigns that as pTop.
	
	On the second line the programme asks:
	If pTop is empty then
		Move the values that pNext is pointing to, then points it to pTop.
		
	The value in pTmp is returned so it can be used in the pop function.
*/
template <typename T>
Node<T>* Stack<T>::nodePop(void)
{
	Node<T> *pTmp = pTop;
	if (pTop != nullptr)
	{
		pTop = pTop->pNext;
	}
	return pTmp;
}

/*
Queue constructor:
	Initialises the pointers to point to nothing so they can be used by the 
	queue.
*/
template <typename T>
Queue<T>::Queue(void)
{
	pFront = pTop = nullptr;
}

template <typename T>
Queue<T>::~Queue(void)
{
	//Uses stack destructor
}

/*
Queue's enqueue function:
	Overview:
	This function is responsible for putting data items onto the queue.
	When this function is given a value it will put that value onto the queue.
	This function reuses the code from the stack, reusing code makes the 
	programme more efficient as the programme not creating more space for 
    pointers.

	Code overview:
	The first line takes the first value and reuses the code from the push 
    function to put it on the back of the queue.

	The code checks:
	 If pFront is empty then
		If that is the case then the newly added data becomes pFront, making it 
        the only node in the link list.
	Otherwise
		This makes the next item in the queue point to the back (pTop) so that 
		it can be added to the queue.
*/
template <typename T>
void Queue<T>::enqueue(T value)
{
	this->push(value);

	if (pFront == nullptr)
	{
		pFront = pTop;
	}
	else (pTop->pNext)->pPrevious = pTop;
}

/*
Queue's dequeue function:
	Overview:
	The dequeue function is used to remove the data items that is in the queue.
	This function returns the value of the item on the front of the queue before
	deleting it from the queue. This function removes one data item everytime 
    its called.
	
	Code overview:
	The first line of this code gives back the item.
	
	'ret' is called and set to zero.

	The code asks: 
    If the pTmp is not empty then
		The pointer is dereferenced and the variable 'ret' takes the data that's 
		in the 'value'.
	Otherwise
		This programme will throw an exception if the queue is empty.

	If the front pointer (pFront) is pointing to nothing then
		Make the back pointer (pTop) point to nothing.

	It will then delete pTmp so the memory can be reallocated
	and the value in ret is return so it can be used.
*/
template <typename T>
T Queue<T>::dequeue(void)
{
	Node<T> *pTmp = nodeDequeue();
	T ret = 0;

	if (pTmp != nullptr)
	{
		ret = pTmp->value;
	}
	else
	{
		throw "Queue Empty";
	}

	if (pFront == nullptr)
	{
		pTop = pFront;
	}
	delete pTmp;
	return ret;
}

/*
Node dequeue:
	Overview:
	This section of code is for the node dequeue, it is a function that is used 
    in the dequeue function. This function is used to remove the nodes in the
	queue and this function returns the value being pointed to by 'pTmp' at the 
	end.
	
	Code overview:
	The first line reads what's contained inside of pTmp and saves it as front 
	this gets a pointer from the front item and assigns it to pFront
	
	The second line says if the queue is not empty then
		pFront points to previous node, this moves the pointer back one node.
		This makes the pNext pointer become empty.

	If there is nothing in the queue then
		It returns the pTmp pointer empty value.

		If there is something in the list then
			It will return the pointer in front of the queue.
*/
template <typename T>
Node<T>* Queue<T>::nodeDequeue(void)
{
	Node<T> *pTmp = pFront;
	if (pFront != nullptr)
	{
		pFront = pFront->pPrevious;

		if (pFront != nullptr)
		{
			pFront->pNext = nullptr;
		}
	}
	return pTmp;
}

/*
	The 'programme' function is used for the calling of all these functions so 
	they don't have to be put in the main. This section of code is to test the
	stack and the queue just to show the user that this programme works. 

	A 'for' loop is used to push and enqueue numbers onto the stack and queue.
	Count is the loop integer that counts from zero to twenty then implements 
    those numbers into the stack and the queue.

	Try statements execute a selection of code with caution, try statements are 
    used for handling possible exceptions they are useful for creating safety 
    code. A catch statement is used as part of a try statement, it catches 
	anything that goes wrong without causing the programme to crash.
	
	In this programme the try and catch statement are used to stop the while
	loops in stack and queue section so that the code is adaptable and if the
	numbers that are going to be inputted via the for loop in this section are 
	changed then the stack and queue will still work.

	Stack section:
		Prints "Stack Output: " to the console, while statement displays all 
		of the numbers in the stack in the order that they are popped out.

	Queue section:
		Prints "Queue Output: " to the console, a while statement displays all
		of the numbers in the queue, the order is sorted as the ones who were 
		first to the ones queued last.
*/
void programme(void)
{
	Stack<int> MyStack;
	Queue<int> MyQueue;
	
	for (int count = 0; count <= 20; count++)
	{
        MyStack.push(count);
        MyQueue.enqueue(count);
	}
	
	cout << "		Stack and Queue programme" << endl; //Title of the programme

	//Stack:

	try
	{
		cout << "Stack Output: " << endl;

		while (true)
		{
			cout << MyStack.pop() << " ";
		}
	}
	catch (...) 
	{
		cout << endl; 
		//This code is executed after the last item in the stack has been poped.
	}

	cout << endl; //Space between the stack and queue numbers

	//Queue:

	try
	{
		cout << "Queue Output: " << endl;

		while (true)
		{
			cout << MyQueue.dequeue() << " ";
		}
	}
	catch (...)
	{
		cout << endl; 
		//This code is executed after the last item in the queue has been dequeued.
	}
}

int main()
{
	programme();
	cin.get(); //Stops the screen from closing down.
	return 0;
}
