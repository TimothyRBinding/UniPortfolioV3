/*
Programme name: StatePatternAndDecoratorPatternImplementation.cpp
Written by: Tim Binding
Written on: 10/03/2018

This programme is the firmware for the new ‘filled poptarts dispenser’,
the programme uses a state pattern and decorator pattern.

((Poptart_Dispenser*)CurrentContext) - This line of code is using a pointer 
to point to a particular set of data. The 'CurrentContext' points to a StateContext. 
The CurrentContext is being cast to a Poptart_Dispenser pointer. All of this allows 
us to access variables on the Poptart Dispenser object.
*/

#include<iostream>
#include<string>
#include<vector>

using namespace std;

//This programme uses enums to represent various states that the poptart dispenser is in.
enum state { Out_Of_Poptart, No_Credit, Has_Credit, Dispenses_Poptart };
enum stateParameter { No_Of_Poptarts, Credit, Cost_Of_Poptart };

enum poptartBases { Plain_Poptart_Base = 1, Spicy_Poptart_Base = 2, Chocolate_Poptart_Base = 4, Coconut_Poptart_Base = 8, Fruity_Poptart_Base = 16 };
enum fillerBases { Chocolate_Filling = 32, Banana_Filling = 64, Strawberry_Filling = 128, Raspberry_Filling = 256, Apple_Filling = 512, Blackberry_Filling = 1024, Maple_Filling = 2048, Marshmallow_Filling = 4096, Cheese_Filling = 8192, Cheese_And_Ham_Filling = 16384, Caramel_Filling = 32768, Vanilla_Filling = 65536 };

/* 
	This is a forward declaration, it avoids a complier error when the StateContext gets 
	called in the state class. StateContext is defined below. 
*/
class StateContext;

/*
State base class:
	The purpose of the state class is to dictate what the programme can do at
	any moment in time. The reason that the StateContext is in the state class
	is so the state can use the StateContext (declared as CurrentContext) to
	change the state of the programme. This state class is a base class for the
	derived classes later on in the programme. CurrentContext is declared as a
	pointer CurrentContext is protected and not public because we only want the
	CurrentContext to be used in the derived classes so it is not publicly
	accessible to avoid people causing issues by messing around with it.
*/
class State
{
protected:
	StateContext * CurrentContext;

public:
	State(StateContext* Context)
	{
		CurrentContext = Context;
		//Contents in CurrentContext is assigned to context
	}
	virtual ~State(void) {}
	virtual void transition(void) {}
};

/*
StateContext base class:
	The purpose of StateContext class is to give a list of all possible states
	and will point to the current one. The purpose of the stateIndex variable is
	to hold a value that represents the number of the current state the programme
	is in. The vector called 'availableStates' is to contain all possible states
	and holds a pointer to one that the programme is currently in. CurrentState,
	stateIndex and availableStates are protected and not public because we only
	want the pointers, integers and vectors in this class to be accessed only by
	the derived classes so it is not publicly accessible to avoid people causing
	issues by messing around with them.
*/
class StateContext
{
protected:
	State * CurrentState = nullptr;
	//Declares the CurrentState pointer to nothing so it is ready for 
	//data to be assigned to it.
	int stateIndex = 0;
	vector<State*> availableStates;
	vector<int> stateParameters;

public:
	virtual ~StateContext(void);
	virtual void setState(state newState);
	virtual int getStateIndex(void);
	virtual void setStateParam(stateParameter SP, int value);
	virtual int getStateParam(stateParameter SP);
};

/*
StateContext Destructor function:
	This function is used to take back the memory allocated in the vector of
	availableStates. The delete operator deallocates the memory in the vector.
	A 'for' loop is used to loop around the code until all of the memory is
	reclaimed, the 'for' loop uses the condition while 'i' less than
	availableState so it loops until the container is empty. The 'clear' dot
	notation gets rid of every element in the vector which leads to an empty
	container.
*/
StateContext::~StateContext(void)
{
	for (int i = 0; i < this->availableStates.size(); i++)
	{
		delete this->availableStates[i];
	}
	this->availableStates.clear();
	this->stateParameters.clear();
}

/*
setState function:
	This function is responsible for setting the state. This is used to pass in
	new states and sets the 'StateIndex' to the state in the vector called
	'availableStates' and does the same for the other respective states.
*/
void StateContext::setState(state newState)
{
	this->CurrentState = availableStates[newState];
	this->stateIndex = newState;
	this->CurrentState->transition();
}

/*
getStateIndex function:
	This function returns the data in stateIndex when the function is called.
	This function's purpose is to give value that represents the current index
	of the state.
*/
int StateContext::getStateIndex(void)
{
	return this->stateIndex;
}

/*
setStateParam function:
	This function sets the state parameter to the contents
	of value. These functions work with the corresponding 
	functions in the Product_Dispenser to change the credit,
	cost of poptarts and number of poptarts.
*/
void StateContext::setStateParam(stateParameter SP, int value)
{
	this->stateParameters[SP] = value;
}
int StateContext::getStateParam(stateParameter SP)
{
	return this->stateParameters[SP];
}

/*
Transition class
	The transition class is the default implementation of the function, the
	functions in this class gets overridden later in the programme. This class
	is responsible for the error messages when a function is called but the
	function didn't get overridden so it runs one of these functions and
	therefore displays an error, one of these errors may include attempting to
	run a function from a different state.

	The class member functions in this case are returned to false instead of
	returning to true, returning to false stops the function from returning a
	value and continuing the execution of code in the function, these functions
	display an error when they are run before stopping the function.
*/
class Transition
{
public:
	virtual bool insertMoney(int) { cout << "Error!" << endl; return false; }
	virtual bool makeSelection(int) { cout << "Error!" << endl; return false; }
	virtual bool moneyRejected(void) { cout << "Error!" << endl; return false; }
	virtual bool addPoptart(int) { cout << "Error!" << endl; return false; }
	virtual bool dispense(void) { cout << "Error!" << endl; return false; }
};

/*
PoptartState class:
	The PoptartState class is the base class for all of the states, it inheritance
	from both State and Transition. The purpose of this class is to act as an
	intermediate class between the State, Transition classes and the primary
	state classes e.g. NoCredit, Out_Of_Poptart. This class does not get made
	as a state so no instance of poptartstate is created in the programme.
*/
class PoptartState : public State, public Transition
{
public:
	PoptartState(StateContext* Context) : State(Context) {}
};

/*
Sub-classes of PoptartState:
	OutOfPoptart derived class,
	NoCredit derived class,
	HasCredit derived class,
	DispensesPoptart derived class,
	All of these classes are derived classes of PoptartState which is a child
	class of State and Transition. These classes act as a specialized version of
	state. These functions are the ones that override the functions that are in
	the transition class. When the programme is set in one state the programme
	can can't access or run other functions that aren't in part of the state.
*/

class OutOfPoptart : public PoptartState
{
public:
	OutOfPoptart(StateContext* Context) : PoptartState(Context) {}
	bool insertMoney(int money);
	bool makeSelection(int option);
	bool moneyRejected(void);
	bool addPoptart(int number);
	bool dispense(void);
};
class NoCredit : public PoptartState
{
public:
	NoCredit(StateContext* Context) : PoptartState(Context) {}
	bool insertMoney(int money);
	bool makeSelection(int option);
	bool moneyRejected(void);
	bool addPoptart(int number);
	bool dispense(void);
};
class HasCredit : public PoptartState
{
public:
	HasCredit(StateContext* Context) : PoptartState(Context) {}
	bool insertMoney(int money);
	bool makeSelection(int option);
	bool moneyRejected(void);
	bool addPoptart(int number);
	bool dispense(void);
};
class DispensesPoptart : public PoptartState
{
public:
	DispensesPoptart(StateContext* Context) : PoptartState(Context) {}
	bool insertMoney(int money);
	bool makeSelection(int option);
	bool moneyRejected(void);
	bool addPoptart(int number);
	bool dispense(void);
};

/*
Product class:
	This class is the interface of the poptart dispenser. The functions: 
	'ReturnNext', 'RemoveHighestCostItem', 'ReturnHighestCostItem'
	and 'RemoveHighestCostItem' are not used.
	
*/
class Product
{
	friend class Filling;
protected:
	string product_description;
	int itemCost = 0;
	virtual Product* ReturnNext(void);
	virtual void RemoveHighestCostItem(Product* HighestItem);
public:
	virtual void consume(void);
	virtual int cost(void);
	virtual string description(void);
	virtual Product* ReturnHighestCostItem(void);
	virtual void RemoveHighestCostItem(void);
};

class Poptart : public Product
{
public:
	Poptart(void)
	{
		this->product_description = "Poptart";
		this->itemCost = 50;
	}
};

/*
Poptart_Dispenser class:
	Poptart_Dispenser inherits the variables and contexts of HasCredit
	and DispensesPoptart utlizing a friend class declarations.
	Functions declared in this class are corresponding class functions
	depending on which state the program is currently in.
*/
class Poptart_Dispenser : public StateContext, public Transition
{
	friend class DispensesPoptart;
	friend class HasCredit;
private:
	PoptartState * PoptartCurrentState = nullptr;
	bool itemDispensed = false;
	Product* DispensedItem = nullptr;
	bool itemRetrieved = false;
public:
	Poptart_Dispenser(int inventory_count);
	~Poptart_Dispenser(void);
	bool insertMoney(int money);
	bool makeSelection(int option);
	bool moneyRejected(void);
	bool addPoptart(int number);
	bool dispense(void);
	Product* getProduct(void);
	virtual void setStateParam(stateParameter SP, int value);
	virtual int getStateParam(stateParameter SP);
};

/*
Poptart_Dispenser destructor function:
	When the item has not been retrieved then the memory space
	that DispensedItem once held is reclaimed.
*/
Poptart_Dispenser::~Poptart_Dispenser(void)
{
	if (!this->itemRetrieved)
	{
		delete this->DispensedItem;
	}
}

/*
Wrapper functions:
	These are wrapper functions that call the corresponding function on the
	current state object. This set of code is the public interface of the
	programme, the reason this is considered the interface of the programme is
	because these are the functions that will be used when the firmware is
	combined with the hardware to make the poptart dispenser machine function
	as intended. The behaviour of these functions will depend on the current
	state of the programme.
*/
bool Poptart_Dispenser::insertMoney(int money)
{
	PoptartCurrentState = (PoptartState*)this->CurrentState;
	return this->PoptartCurrentState->insertMoney(money);
}
bool Poptart_Dispenser::makeSelection(int option)
{
	PoptartCurrentState = (PoptartState*)this->CurrentState;
	return this->PoptartCurrentState->makeSelection(option);
}
bool Poptart_Dispenser::moneyRejected(void)
{
	PoptartCurrentState = (PoptartState*)this->CurrentState;
	return this->PoptartCurrentState->moneyRejected();
}
bool Poptart_Dispenser::addPoptart(int number)
{
	PoptartCurrentState = (PoptartState*)this->CurrentState;
	return this->PoptartCurrentState->addPoptart(number);
}
bool Poptart_Dispenser::dispense(void)
{
	PoptartCurrentState = (PoptartState*)this->CurrentState;
	return this->PoptartCurrentState->dispense();
}

Product* Poptart_Dispenser::getProduct(void)
{
	if (this->itemDispensed)
	{
		this->itemDispensed = false;
		this->itemRetrieved = true;
		return this->DispensedItem;
	}
	return nullptr;
}

/*
SetStateParam function:
	This function is responsible for changing the credit,
	cost of poptarts and number of poptarts enum values.
*/
void Poptart_Dispenser::setStateParam(stateParameter SP, int value)
{
	if (SP == Cost_Of_Poptart) return;
	this->stateParameters[SP] = value;
}

/*
getStateParma
	This function is responsible for getting the the credit,
	cost of poptarts and number of poptarts enum values.
*/
int Poptart_Dispenser::getStateParam(stateParameter SP)
{
	if (SP == Cost_Of_Poptart)
	{
		if (DispensedItem == nullptr) return 0;
		return DispensedItem->cost();
	}
	return this->stateParameters[SP];
}

/*
	This class is the core part of the decorator pattern, the decorator pattern
	is a pattern that adds specific new behaviour to an object and does not
	alter the behaviour of objects that are also in the class.
*/
class Filling : public Product
{
protected:
	Product *product;
public:
	void addToPoptart(Product *filling)
	{
		product = filling;
	}
	int cost(void)
	{
		return this->itemCost + product->cost();
	}
	string description(void)
	{
		return this->product_description;
	}
	virtual void consume(void)
	{
		delete this;
	}
};

/*
Poptart objects:
	The poptart objects specifies the name and the cost of each poptart these
	are used in the 'makeSelection' function. These classes are child classes of poptart.
*/
class PlainPoptart : public Poptart
{
public:
	PlainPoptart()
	{
		this->product_description = "Plain poptart";
		this->itemCost = 100;
	}
};
class SpicyPoptart : public Poptart
{
public:
	SpicyPoptart()
	{
		this->product_description = "Spicy poptart";
		this->itemCost = 150;
	}
};
class ChocolatePoptart : public Poptart
{
public:
	ChocolatePoptart()
	{
		this->product_description = "Chocolate poptart";
		this->itemCost = 200;
	}
};
class CoconutPoptart : public Poptart
{
public:
	CoconutPoptart()
	{
		this->product_description = "Coconut poptart";
		this->itemCost = 200;
	}
};
class FruityPoptart : public Poptart
{
public:
	FruityPoptart()
	{
		this->product_description = "Fruity poptart";
		this->itemCost = 200;
	}
};

class Filler : public Filling
{
public:
	Filler(void)
	{
		this->product_description = "Filler";
		this->itemCost = 50;
	}
};

/*
Filling objects:
	The filling objects specifies the name and the cost of each filling these
	are used in the 'makeSelection' function. These classes are child classes of filler.
*/
class ChocolateFillings : public Filler
{
public:
	ChocolateFillings()
	{
		this->product_description = "Chocolate filler";
		this->itemCost = 20;
	}
};
class BananaFillings : public  Filler
{
public:
	BananaFillings()
	{
		this->product_description = "Banana filler";
		this->itemCost = 50;
	}
};
class StrawberryFillings : public Filler
{
public:
	StrawberryFillings()
	{
		this->product_description = "Strawberry filler";
		this->itemCost = 50;
	}
};
class RaspberryFillings : public Filler
{
public:
	RaspberryFillings()
	{
		this->product_description = "Raspberry filler";
		this->itemCost = 50;
	}
};
class AppleFillings : public Filler
{
public:
	AppleFillings()
	{
		this->product_description = "Apple filler";
		this->itemCost = 50;
	}
};
class BlackberryFillings : public Filler
{
public:
	BlackberryFillings()
	{
		this->product_description = "Blackberry filler";
		this->itemCost = 50;
	}
};
class MapleFillings : public Filler
{
public:
	MapleFillings()
	{
		this->product_description = "Maple filler";
		this->itemCost = 100;
	}
};
class MarshmallowFillings : public Filler
{
public:
	MarshmallowFillings()
	{
		this->product_description = "Marshmallow filler";
		this->itemCost = 20;
	}
};
class CheeseFillings : public Filler
{
public:
	CheeseFillings()
	{
		this->product_description = "Cheese filler";
		this->itemCost = 70;
	}
};
class CheeseAndHamFillings : public Filler
{
public:
	CheeseAndHamFillings()
	{
		this->product_description = "Cheese and Ham filler";
		this->itemCost = 100;
	}
};
class CaramelFillings : public Filler
{
public:
	CaramelFillings()
	{
		this->product_description = "Caramel filler";
		this->itemCost = 20;
	}
};
class VanillaFillings : public Filler
{
public:
	VanillaFillings()
	{
		this->product_description = "Vanilla filler";
		this->itemCost = 50;
	}
};

/*
Errors for 'OutOfPoptart':
	Functions for the OutOfPoptart state, if these functions are called while in this state these errors will appear.
*/
bool OutOfPoptart::insertMoney(int money)
{
	cout << "Error: Out of poptarts...Insert more poptarts into the machine before making inserting money..." << endl;
	return false;
}
bool OutOfPoptart::makeSelection(int option)
{
	cout << "Error: Out of poptarts...Insert more poptarts into the machine before making a selection..." << endl;
	return false;
}
bool OutOfPoptart::dispense(void)
{
	cout << "Error: Out of poptarts...Insert more poptarts into the machine and then make a selection..." << endl;
	return false;
}

/*
OutOfPoptart 'moneyRejected' function:
	Sets credit to zero and sets state Out_Of_Poptart.
*/
bool OutOfPoptart::moneyRejected(void)
{
	cout << "Money rejected..." << endl;
	((Poptart_Dispenser*)CurrentContext)->setStateParam(Credit, 0);
	CurrentContext->setState(Out_Of_Poptart);
	return true;
}

/*
OutOfPoptart 'addPoptart' function:
	The addPoptart function is used to take a number that represents the 
    number of poptarts that the user wants to add and adds that value to
    the inventory then displays what's currently in the inventory.
*/
bool OutOfPoptart::addPoptart(int number)
{
	((Poptart_Dispenser*)CurrentContext)->setStateParam(No_Of_Poptarts, number);
	cout << "Adding poptarts...Poptarts: " << ((Poptart_Dispenser*)CurrentContext)->getStateParam(No_Of_Poptarts) << endl;
	((Poptart_Dispenser*)CurrentContext)->setState(No_Credit);
	return true;
}

/*
NoCredit 'insert money' function:
	The insertMoney function is used to add credit from the state of no credit
	and then displays the credit currently in the machine, then it will then set the state from
	NoCredit to Has_Credit.
*/
bool NoCredit::insertMoney(int money)
{
	((Poptart_Dispenser*)CurrentContext)->setStateParam(Credit, money);
	cout << "Adding credit...Credit = " << ((Poptart_Dispenser*)CurrentContext)->getStateParam(Credit) << endl;
	CurrentContext->setState(Has_Credit);
	return true;
}
/*
Errors for 'NoCredit':
	Functions for the NoCredit state, if these functions are called while in this state these errors will appear.
*/

bool NoCredit::makeSelection(int option)
{
	cout << "Error: No credit...Insert more credits into the machine before making a selection..." << endl;
	return false;
}
bool NoCredit::moneyRejected(void)
{
	cout << "Error: No credit...Credit cannot be rejected because their is no money to reject..." << endl;
	return false;
}
bool NoCredit::addPoptart(int number)
{
	cout << "Error: Poptarts already inserted, please empty and insert the desired amount..." << endl;
	return false;
}
bool NoCredit::dispense(void)
{
	cout << "Error: No credit...Insert more credits into the machine and then make a selection...";
	return false;
}

/*
HasCredit 'insertMoney' function:
	The purpose of this function is to add credit when there is credit in the 
    machine and then it will display the credit onto the screen.
*/
bool HasCredit::insertMoney(int money)
{
	((Poptart_Dispenser*)CurrentContext)->setStateParam(Credit, ((Poptart_Dispenser*)CurrentContext)->getStateParam(Credit) + money);
	cout << "Adding credit...Money = " << ((Poptart_Dispenser*)CurrentContext)->getStateParam(Credit);
	return true;
}
/*
HasCredit 'moneyRejected' function:
	This function is for rejecting the money that has been put into the machine.
	The function sets credit to zero and sets the state to NoCredit.
*/
bool HasCredit::moneyRejected(void)
{
	cout << "Money rejected..." << endl;
	((Poptart_Dispenser*)CurrentContext)->setStateParam(Credit, 0);
	((Poptart_Dispenser*)CurrentContext)->setState(No_Credit);
	return true;
}

/*
HasCredit 'makeSelection' function:
	The bitwise symbol '&' evaluates whether or not the poptart or fillers
	are inside the option bracket, this is done for every poptart and filler.

	Once the poptart or filler have been found the object is created and set to
	the pointer pPoptart.
*/
bool HasCredit::makeSelection(int option)
{
	Product* pPoptart = nullptr;
	Filling* pFiller = nullptr;
	//The pointers are pointing to nothing read to be used later in the function

	Poptart_Dispenser* dispense = static_cast <Poptart_Dispenser*>((Poptart_Dispenser*)CurrentContext);
	//The 'static_cast' operator is used so that the variables in the class can be accessed

	dispense->itemDispensed = false;
	dispense->itemRetrieved = false;
	//itemRetrived and itemDispensed are set to false to specify that the item has not been retrived and dispensed.

	if ((option & Plain_Poptart_Base) == Plain_Poptart_Base) //Checks 
	{
		pPoptart = new PlainPoptart();

		cout << "Poptart: " << pPoptart->description() << endl;
	}
	else if ((option & Spicy_Poptart_Base) == Spicy_Poptart_Base)
	{
		pPoptart = new SpicyPoptart();

		cout << "Poptart: " << pPoptart->description() << endl;
	}
	else if ((option & Chocolate_Poptart_Base) == Chocolate_Poptart_Base)
	{
		pPoptart = new ChocolatePoptart();

		cout << "Poptart: " << pPoptart->description() << endl;
	}
	else if ((option & Coconut_Poptart_Base) == Coconut_Poptart_Base)
	{
		pPoptart = new CoconutPoptart();

		cout << "Poptart: " << pPoptart->description() << endl;
	}
	else if ((option & Fruity_Poptart_Base) == Fruity_Poptart_Base)
	{
		pPoptart = new FruityPoptart();

		cout << "Poptart: " << pPoptart->description() << endl;
	}
	else
	{
		cout << "Error" << endl;
		return false;
	}

	if ((option & Chocolate_Filling) == Chocolate_Filling)
	{
		option -= Chocolate_Filling;
		pFiller = new ChocolateFillings();

		cout << "Filling: " << pFiller->description() << endl;

	}
	else if ((option & Banana_Filling) == Banana_Filling)
	{
		option -= Banana_Filling;
		pFiller = new BananaFillings();

		cout << "Filling: " << pFiller->description() << endl;

	}
	else if ((option & Strawberry_Filling) == Strawberry_Filling)
	{
		option -= Strawberry_Filling;
		pFiller = new StrawberryFillings();

		cout << "Filling: " << pFiller->description() << endl;

	}
	else if ((option & Raspberry_Filling) == Raspberry_Filling)
	{
		option -= Raspberry_Filling;
		pFiller = new RaspberryFillings();

		cout << "Filling: " << pFiller->description() << endl;

	}
	else if ((option & Apple_Filling) == Apple_Filling)
	{
		option -= Apple_Filling;
		pFiller = new AppleFillings();

		cout << "Filling: "<< pFiller->description() << endl;

	}
	else if ((option & Blackberry_Filling) == Blackberry_Filling)
	{
		option -= Blackberry_Filling;
		pFiller = new BlackberryFillings();

		cout << "Filling: " << pFiller->description() << endl;

	}
	else if ((option & Maple_Filling) == Maple_Filling)
	{
		option -= Maple_Filling;
		pFiller = new MapleFillings();

		cout << "Filling: " << pFiller->description() << endl;

	}
	else if ((option & Marshmallow_Filling) == Marshmallow_Filling)
	{
		option -= Marshmallow_Filling;
		pFiller = new MarshmallowFillings();

		cout << "Filling: " << pFiller->description() << endl;

	}
	else if ((option & Cheese_Filling) == Cheese_Filling)
	{
		option -= Cheese_Filling;
		pFiller = new CheeseAndHamFillings();

		cout << "Filling: " << pFiller->description() << endl;

	}
	else if ((option & Caramel_Filling) == Caramel_Filling)
	{
		option -= Caramel_Filling;
		pFiller = new CaramelFillings();

		cout << "Filling: " << pFiller->description() << endl;
	}
	else if ((option & Vanilla_Filling) == Vanilla_Filling)
	{
		option -= Vanilla_Filling;
		pFiller = new VanillaFillings();

		cout << "Filling: " << pFiller->description() << endl;
	}
	else
	{
		cout << "Error" << endl;
		return false;
	}

	if (pPoptart && pFiller != nullptr)
	{
		pFiller->addToPoptart(pPoptart);
		pPoptart = pFiller;
		
		((Poptart_Dispenser*)CurrentContext)->setStateParam(Cost_Of_Poptart, pFiller->cost()); 
		//Calculates the cost and sets Cost_Of_Poptart to the cost of the poptart and filler combined
	}
	else if (pPoptart != nullptr && pFiller == nullptr)
	{
		((Poptart_Dispenser*)CurrentContext)->setStateParam(Cost_Of_Poptart, pPoptart->cost()); 
		//Calculates the cost and sets Cost_Of_Poptart to the cost of the poptart
	}
	else
	{
		cout << "Error: Invalid selection" << endl;
		return false;
	}

	//The dispensing begins here so the credit is checked before the state is set to Dispenses_Poptart to comply with the state diagram

	((Poptart_Dispenser*)CurrentContext)->DispensedItem = pPoptart;
	//The pPoptart contents is set to DispensedItem. This is the item that will be dispensed

	if (((Poptart_Dispenser*)CurrentContext)->getStateParam(Cost_Of_Poptart) <= ((Poptart_Dispenser*)CurrentContext)->getStateParam(Credit)) //Checks if the machine has enough credit inserted
	{
		this->CurrentContext->setStateParam(Credit, ((Poptart_Dispenser*)CurrentContext)->getStateParam(Credit) - ((Poptart_Dispenser*)CurrentContext)->getStateParam(Cost_Of_Poptart)); 
		//Credit is  deducted  from the cost of the poptart
		this->CurrentContext->setState(Dispenses_Poptart); //State set to Dispenses_Poptart
		cout << "Credit: " << ((Poptart_Dispenser*)CurrentContext)->getStateParam(Credit) << endl;
		return true;
	}
	else
	{
		cout << "Error: Not enough Credit!";
		return false;
	}
}

/*
Errors for 'HasCredit':
	Functions for the HasCredit state, if these functions are called while in this state, these errors will appear.
*/
bool HasCredit::addPoptart(int number)
{
	cout << "Error: Poptarts cannot be added while their is poptarts and credits in the machine...";
	return false;
}
bool HasCredit::dispense(void)
{
	cout << "Error: Error has occurred while dispensing...";
	return false;
}

/*
DispensesPoptart 'dispense' function:
	The dispense function is called when the machine begins to dispense the poptart.
*/
bool DispensesPoptart::dispense(void)
{
	((Poptart_Dispenser*)CurrentContext)->setStateParam(No_Of_Poptarts, ((Poptart_Dispenser*)CurrentContext)->getStateParam(No_Of_Poptarts) - 1);
	//Deducts a poptart from the number of poptarts in the machine

	Poptart_Dispenser* dispense = static_cast <Poptart_Dispenser*>((Poptart_Dispenser*)CurrentContext);
	//The 'static_cast' operator is used so that the variables in the class can be accessed

	cout << "Number of Poptarts: " << ((Poptart_Dispenser*)CurrentContext)->getStateParam(No_Of_Poptarts) << endl;

	cout << "Dispensed" << endl;

	if (((Poptart_Dispenser*)CurrentContext)->getStateParam(No_Of_Poptarts) == 0)
		//Checks to if the number of poptarts is zero
	{
		cout << "Error: Out of poptarts, money is rejected..." << endl;
		((Poptart_Dispenser*)CurrentContext)->setStateParam(Credit, 0); //Sets credit to zero (Money ejects)
		((Poptart_Dispenser*)CurrentContext)->setState(Out_Of_Poptart); //State set to Out_Of_Poptart
	}

	else if (((Poptart_Dispenser*)CurrentContext)->getStateParam(Credit) == 0)
		//Checks to if the credit is zero
	{
		((Poptart_Dispenser*)CurrentContext)->setState(No_Credit); //State set to No_Credit
	}

	else if (((Poptart_Dispenser*)CurrentContext)->getStateParam(Credit) > 0)
		//Checks to if there is credit in the machine
	{
		((Poptart_Dispenser*)CurrentContext)->setState(Has_Credit); //State set to Has_Credit
	}
	else
	{
		cout << "Error: Unknown dispensing error has occurred" << endl;
		dispense->itemDispensed = false; //Returned to false to specify that the item failed to dispense
		return false;
	}
	dispense->itemDispensed = true; //Dispense successful
	return true;
}

/*
Errors for 'DispensesPoptart':
	Functions for the DispensesPoptart state, if these functions are called while in this state, these errors will appear.
*/
bool DispensesPoptart::insertMoney(int money)
{
	cout << "Error: Credit cannot be added while dispensing...";
	return false;
}
bool DispensesPoptart::makeSelection(int option)
{
	cout << "Error: Selection has already been made...";
	return false;
}
bool DispensesPoptart::moneyRejected(void)
{
	cout << "Error: Credit cannot be added while dispensing";
	return false;
}
bool DispensesPoptart::addPoptart(int number)
{
	cout << "Error: Poptarts cannot be added while dispensing";
	return false;
}

/*
'cost' function:
	The 'cost' function extracts the protected 'itemCost' value of the respective poptart
*/
int Product::cost(void)
{
	return this->itemCost;
}

/*
'description' function:
	The 'description' function extracts the protected 'product_description' string of the respective poptart
*/
string Product::description(void)
{
	return this->product_description;
}
/*
'consume' function:
	The consume function is supposed to be used in the main
*/
void Product::consume(void)
{
	delete this;
}

/*
Unused functions
*/
Product* Product::ReturnNext(void)
{
	return 0;
}
Product* Product::ReturnHighestCostItem(void)
{
	return 0;
}
void Product::RemoveHighestCostItem(Product* HighestItem) {	}
void Product::RemoveHighestCostItem(void) {	}

/*
Poptart_Dispenser function:
	This function is responsible for creating new instances and storing them 
    into the list (vector), this function allocates memory in availableStates 
    using pushback ready for data from these classes to be pushed in. The
	point of this function is so that the programme knows what state it is in
	by using availableStates as a list of states that the programme can be set 
	to. By the end of the function it initializes the setState to Out_Of_Poptarts.

	It is very important that each class is created in this order so that 
	it corresponds with the values of the enum at the top of the programme,
	this is because the enum value is used to access the state from the 
    available state vector.
*/
Poptart_Dispenser::Poptart_Dispenser(int inventory_count)
{
	this->availableStates.push_back(new OutOfPoptart(this));
	this->availableStates.push_back(new NoCredit(this));
	this->availableStates.push_back(new HasCredit(this));
	this->availableStates.push_back(new DispensesPoptart(this));
	this->stateParameters.push_back(0); //number of poptarts
	this->stateParameters.push_back(0); //Credits available

	this->setState(Out_Of_Poptart); //Sets the starting state to Out_Of_Poptarts

	if (inventory_count > 0) 
	//This is used to increase the number of poptarts by one everytime the condition becomes true
	{
		this->addPoptart(inventory_count);
	}
}