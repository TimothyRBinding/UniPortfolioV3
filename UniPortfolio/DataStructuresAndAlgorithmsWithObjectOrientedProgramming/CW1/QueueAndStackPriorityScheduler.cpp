/*
Programme: QueueAndStackPriorityScheduler.cpp
Written by: Tim Binding
Written on: 4/01/2018

Description: This is a programme that consists of two computer memory structures 
for assigning and using memory in the 'Windowless 9' operating system. 
These two computer memory structures are called a 'stack' and a 'queue'.
This programme also contains a scheduler which is a subclass on queue.

The stack and queue in this programme allows for the pushing and enqueuing 
of data depending on the amount of memory that is available and this programme
allows for the poping and dequeuing data that is in the stack and queue. The 
prioritised scheduler processes based on priority.
*/

#include<iostream>

using namespace std;

class Node
{
public:
	Node(int value, Node* nextptr = NULL, Node* prevptr = NULL, int currentpriority = 0); //constructer function
	int getVal(void);
	Node* getNext(void);
	Node* getPrev(void);
	void setVal(int value);
	void setPrev(Node* prevptr);
	void setNext(Node* nextptr);
	int getPriority(void);
	void setPriority(int priority);

private:
	Node* next;
	Node* prev;
	int priority;
	int value;
};

class Stack
{
public:
	Stack(void);
	~Stack(void);
	void Push(int value);
	Node* NodePop(void);
	int Pop(void);

private:
	Node* top;
};

class Queue
{
public:
	Queue(void);
	~Queue(void);
	void Enqueue(int i, int priority = 0);
	int Dequeue(void);

protected:
	Node* back;
	Node* front;

private:
	virtual Node* NodeDequeue(void);
};

class Scheduler : public Queue
{
private:
	Node* NodeDequeue(void);
};

/*
Node constructor function:
	This is the 'node' constructor function, this function links private 
    variables such priority so that anytime a new node is created these values 
    are assigned.
*/

Node::Node(int value, Node* nextptr, Node* prevptr, int currentpriority)
{
	priority = currentpriority;
	Node::value = value; 
	//'value' had to be called directly due to a naming conflict as they were 
    //both called value.
	next = nextptr;
	prev = prevptr;
}

/*
getVal, getNext, getPrev, getPriority functions:
	Returns the values in the private class so they can be used outside
	of the class we do this because we want to prevent unauthorised access 
	to the values so we have control on how the values are accessed.
*/
int Node::getVal(void)
{
	return value;
}
Node* Node::getNext(void)
{
	return next;
}
Node* Node::getPrev(void)
{
	return prev;
}
int Node::getPriority(void)
{
	return priority;
}

/*
setVal, setPrev, setNext function:
	These functions alter the integer values in the private class, we do this 
    for the same reason as the 'get' functions above.
*/
void Node::setVal(int value)
{
	this->value = value;
}
void Node::setPrev(Node* prevptr)
{
	this->prev = prevptr;
}
void Node::setNext(Node* nextptr)
{
	this->next = nextptr;
}
void Node::setPriority(int priority)
{
	this->priority = priority;
}

//Stack code

/*
Stack constructor function:
	Initialises the top to point to nothing so they can be used by the
	stack.
*/
Stack::Stack(void)
{
	top = nullptr;
}

/*
Stack deconstructor function:
	This function uses a while loop to deconstruct the stack to take back the 
	memory that was allocated. The while loop takes layers off the stack off 
	by constantly deleting 'nodePop's' returning value until 'top' points 
	to nothing.
*/
Stack::~Stack(void)
{
	while (top != nullptr) //While the top of the stack is not empty then
	{
		delete NodePop(); //Uses a delete operator to reclaim the memory 
		//space when the values being taken from the top of the stack
		//until its empty.
	}
}

/*
Stack Push function:
	This function is responsible for adding numbers to the stack 
	creating a chain of nodes based on the values implemented. 
	This function creates new memory space and then stores the 
	values inside there.
*/

void Stack::Push(int value)
{
	Node* tmpptr = new Node(value); //Allocates new memory and assigns the value
    //of 'value' to 'tmptr'.
	tmpptr->setNext(top); //Sets the node top before top so it becomes the new 
    //layer.
	top = tmpptr; //Sets the newly pushed value to 'top'.
}

/*
Node pop:
	This section of code is for the pop function and is also used in the stack 
    deconstructor. Removes item from the top then gives back that value while 
    reassigning top.
*/

Node* Stack::NodePop(void)
{
	Node *tmpptr = top; //Assigns top value to 'tmpptr'
	if (top != nullptr) //Checks if item is there then
	{
		top = top->getNext(); //Moves to the next item in the stack
	}
	return tmpptr; //Returns the orginal top item
}

/*
Stack pop:
	This section of code is used to take out the most recent inputted node.
	This function removes one data item everytime its called.
	Gives back the value to be used possibly later on in the programme.
*/

int Stack::Pop(void)
{
	Node *tmpptr = NodePop(); 
    //Calls nodepop to get the value from the top of the stack

	int retNum = 0;

	if (tmpptr != nullptr) //Checks if the item that 'tmpptr' is not empty
	{
		retNum = tmpptr->getVal(); //Sets 'retnum' to value 'tmpptr'
	}
	else
	{
		throw ""; 
        //'throw' is used in case the stack is empty so it will stop poping
	}

	delete tmpptr; //Removes the orginal top node and takes back the memory
	return retNum; //Returns the number so it can be used
}

//Queue code

/*
Queue constructor:
	Initialises the pointers to point to nothing so they can be used by the 
	queue.
*/
Queue::Queue(void)
{
	front = back = nullptr;
}

/*
Queue destructor:
	This function uses a while loop to take back the memory that was allocated 
	for the queue. The while loop takes layers off the stack off 
	by constantly deleting 'NodeDequeue's' returning value until front points 
	to nothing.
*/
Queue::~Queue(void)
{
	while (front != nullptr)
	{
		delete NodeDequeue();
	}
}

/*
Queue's enqueue function:
	This function is responsible for putting data items onto the queue.
	When this function passes a value it will put that value onto the queue.
*/
void Queue::Enqueue(int i, int priority)
{
	Node* tmpptr = new Node(i, back, nullptr, priority); 
	//Allocates new memory and assigns priority to value passed as 'i'
	back = tmpptr; 
    //'back' is set as 'tmpptr', sticking on the back of the queue

	if (front == nullptr)
	{
		front = back; //Used when there is no item in the queue
	}
	else 
	{
		(back->getNext())->setPrev(back); 
		//'getNext' gives a pointer back of the data item ahead 
		//'setPrev' points back to the previous node
	}
}

/*
Queue's dequeue function:
	The dequeue function is used to remove the data items that is in the queue.
	This function returns the value of the item on the front of the queue before
	deleting it from the queue. This function also returns a data item for use.
*/
int Queue::Dequeue(void)
{
	Node *tmpptr = NodeDequeue(); //Overwritten using virtual inheritence
	int retNum = 0;

	if (tmpptr != nullptr)
	{
		retNum = tmpptr->getVal();
	}
	else
	{
		throw ""; //'throw' is used in case the queue is empty so it will not continue this function
	}

	if (front == nullptr)
	{
		back = front;
	}

	delete tmpptr;
	return retNum;
}

/*
Node dequeue:
	This section of code is for the dequeue function and queue
	destructor function. Takes from the front of the queue and 
	gives it back.
*/
Node* Queue::NodeDequeue(void)
{
	Node *tmpptr = front;
	if (front != nullptr) //If the front node is not empty then
	{
		front = front->getPrev(); //Move backwards once on the node

		if (front != nullptr) //If the front node is still not empty then
		{
			front->setNext(nullptr); //Sets the next node in the list to empty
		}
	}
	return tmpptr;
}

//Scheduler

/*
Scheduler NodeDequeue
	This section of code is for the node dequeue for scheduler, it is a function
    that is used in the dequeue function. This code allows for the scheduling as
    many processes as there is memory available. This code searches for the item
    with the highest priority and returns it.
*/

Node* Scheduler::NodeDequeue(void)
{
	Node* tmp = front;
	Node* look = tmp->getPrev();

	while (look != nullptr) //While the node with highest priority has not been found
	{
		if (look->getPriority() > tmp->getPriority()) 
		//This code searches for the node with the highest priority assigned to it
		{
			tmp = look; //Once found 'look' is assigned to 'tmp'
		}
		look = look->getPrev(); //Moves to the previous node till it reaches the end
	}

	//Extracts the 'prev' and 'next' integer
	Node* prevtmp = tmp->getPrev();
	Node* nexttmp = tmp->getNext();

	if (prevtmp != nullptr)
	{
		prevtmp->setNext(nexttmp); //Points the 'prevtmp' to 'nexttmp' node
	}
	else
	{
		back = nexttmp; 
        //Back of the queue has been reached so assign the value in 'nexttmp' to 'back'
	}

	if (nexttmp != nullptr)
	{
		nexttmp->setPrev(prevtmp); //Points the 'nexttmp' to 'prevtmp' node
	}
	else
	{
		front = prevtmp; 
        //Front of the queue has been reached so assign the value in 'prevtmp' to 'front'
	}

	return tmp;
}
