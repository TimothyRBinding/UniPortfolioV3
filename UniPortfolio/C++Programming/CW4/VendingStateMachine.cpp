/*
Programme: VendingStateMachine.cpp
Written by: Tim Binding

Description: This programme is the firmware for the new chocolate vending machine. 
The code was created and designed around the state diagram given by ChocDispeser
LTD, it works by using a state pattern.
*/

#include<iostream>
#include<vector>

using namespace std;

enum state { Out_Of_Chocolate, No_Credit, Has_Credit, Dispenses_Chocolate, Maintenance_Mode };
//The programme uses enums to represents various states that the chocolate dispenser is in.

class StateContext; /* This is a forward declaration, it avoids complier error 
when the StateContext gets called in the state class. StateContext is declared
down below. */

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
	StateContext* CurrentContext;
public:
	State(StateContext* Context)
	{
		CurrentContext = Context; 
        //Whatevers in CurrentContext is assigned to context
	}
	virtual ~State(void) {}
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
	State* CurrentState = nullptr; 
	//Declares the CurrentState pointer to nothing so it is ready for 
    //information to be assigned to it.
	int stateIndex = 0;
	vector<State*> availableStates;
public:
	virtual ~StateContext(void);
	virtual void setState(state newState);
	virtual int getStateIndex(void);
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
}

/*
setState function:
	This function is responsible for setting the state. This is used to pass in 
    new states and sets the 'StateIndex' to the state in the vector called 
    'availableStates'.
*/

void StateContext::setState(state newState)
{
	this->CurrentState = availableStates[newState];
	this->stateIndex = newState;
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
Transition base class:
	The transition class is the default implementation of the function, the 
    functions in this class gets overridden later in the programme. This class 
    is responsible for the error messages when a function is called but the 
    function didn't get overridden so it runs one of these functions and 
    therefore displays an error, one of these errors may include attempting to 
    run a function from a different state.

	The class member functions in this case are returned to false instead of 
	returning to true, returning to false stops the function from returning a 
	value and continuing the execution of code in the function, these functions
    display an error when they are run before stopping the function. Virtual 
    functions are used because these function will be redefined in the derived 
    classes below the Chocolate_Dispenser.
*/

class Transition
{
public:
	virtual bool insertMoney(int) { cout << "Error!" << endl; return false; }
	virtual bool makeSelection(int) { cout << "Error!" << endl; return false; }
	virtual bool moneyRejected(void) { cout << "Error!" << endl; return false; }
	virtual bool addChocolate(int) { cout << "Error!" << endl; return false; }
	virtual bool dispense(void) { cout << "Error!" << endl; return false; }
	virtual bool enterPin(int) { cout << "Error!" << endl; return false; }
	virtual bool exit(void) { cout << "Error!" << endl; return false; }
};

/*
ChocoState class:
	The ChocoState class is the base class for all of the states, it inheritance
    from both State and Transition. The purpose of this class is to act as an 
    intermidiate class between the State, Transition classes and the primary 
    state classes e.g. NoCredit, Out_Of_Chocolate. This class does not get made 
    as a state so no instance of chocostate is created	in the programme.
*/

class ChocoState : public State, public Transition
{
public:
	ChocoState(StateContext* Context) : State(Context) {}
};

/*
Chocolate_Dispenser class:
	This class declares several classes and declares them as friend classes,
    this class uses friend classes to allow access to the class member variables
    and functions.

	'credit', 'inventory' and 'pin' are variables that don't need to be changed,
    this is why they are in the private class. 'inventory' represents the number 
    of chocolate bars in the machine. 'credit' is the money that is in the 
    machine.
*/

class Chocolate_Dispenser : public StateContext, public Transition
{
	friend class OutOfChocolate;
	friend class NoCredit;
	friend class HasCredit;
	friend class DispensesChocolate;
	friend class MaintenanceMode;
private:
	int inventory = 0;
	int credit = 0;
	int pin = 54321;
public:
	Chocolate_Dispenser(void);
	bool insertMoney(int credit);
	bool makeSelection(int option);
	bool moneyRejected(void);
	bool addChocolate(int number);
	bool dispense(void);
	bool enterPin(int pin);
	bool exit(void);
};

/*
Wrapper functions:
    These are wrapper functions that call the corresponding function on the 
    current state object. This set of code is the public interface of the 
    programme, the reason this is considered the interface of the programme is 
    because these are the functions that will be used when the firmware is 
    combined with the hardware to make the chocolate dispenser machine function 
    as intended. The behaviour of these functions will depend on the current 
    state of the programme.
*/

bool Chocolate_Dispenser::insertMoney(int credit)
{
	return ((ChocoState*)CurrentState)->insertMoney(credit);
}
bool Chocolate_Dispenser::makeSelection(int option)
{
	return ((ChocoState*)CurrentState)->makeSelection(option);
}
bool Chocolate_Dispenser::moneyRejected(void)
{
	return ((ChocoState*)CurrentState)->moneyRejected();
}
bool Chocolate_Dispenser::addChocolate(int number)
{
	return ((ChocoState*)CurrentState)->addChocolate(number);
}
bool Chocolate_Dispenser::dispense(void)
{
	return((ChocoState*)CurrentState)->dispense();
}
bool Chocolate_Dispenser::enterPin(int pin)
{
	return ((ChocoState*)CurrentState)->enterPin(pin); 
}
bool Chocolate_Dispenser::exit(void)
{
	return ((ChocoState*)CurrentState)->exit();
}

/*
OutOfChocolate derived class,
NoCredit derived class,
HasCredit derived class,
DispensesChocolate derived class,
MaintenanceMode derived class:
	All of these classes are derived classes of ChocoState which is a child 
    class of State and Transition. These classes act as a specialized version of
    state. These functions are the ones that override the functions that are in 
    the transition class. When the programme is set in one state the programme 
    can can't access or run other functions that aren't in part of the state.
*/

class OutOfChocolate : public ChocoState
{
public:
	OutOfChocolate(StateContext* Context) : ChocoState(Context) {}
	bool enterPin(int pin);
};

class NoCredit : public ChocoState
{
public:
	NoCredit(StateContext* Context) : ChocoState(Context) {}
	bool insertMoney(int credit);
	bool enterPin(int pin);
};

class HasCredit : public ChocoState
{
public:
	HasCredit(StateContext* Context) : ChocoState(Context) {}
	bool insertMoney(int credit);
	bool makeSelection(int option);
	bool moneyRejected(void);
};

class DispensesChocolate : public ChocoState
{
public:
	DispensesChocolate(StateContext* Context) : ChocoState(Context) {}
	bool dispense(void);
};

class MaintenanceMode : public ChocoState
{
public:
	MaintenanceMode(StateContext* Context) : ChocoState(Context) {}
	bool addChocolate(int number);
	bool exit(void);
};

/*
((Chocolate_Dispenser*)CurrentContext)->inventory - This line of code and 
    variations of it appear quite a few times in the functions below. The code
    is using a pointer to point to inventory in the Chocolate_Dispenser class in
    this case in other variations it will point to the other data in 
    Chocolate_Dispenser such as the pin and credit. The 'CurrentContext' points 
    to a StateContext. The CurrentContext is being cast to a Chocolate_Dispenser
    pointer. All of this allows us to access variables on the Chocolatedispenser
    object.
*/

/*
addChocolate function:
	The addChocolate function is used to take a number that represents the 
    number of chocolate bars that the user wants to add and adds that value to
    the inventory then displays text and what's currently in the inventory.
*/

bool MaintenanceMode::addChocolate(int number)
{
	((Chocolate_Dispenser*)CurrentContext)->inventory += number;
	cout << "Adding chocolate... Inventory = " << ((Chocolate_Dispenser*)CurrentContext)->inventory << endl;
	return true;
}

/*
insertMoney(For NoCredit) function:
	The insertMoney function is used to add credit from the state of no credit
	and then displays the credit in the machine it will then set the state from 
	NoCredit to Has_Credit.
*/

bool NoCredit::insertMoney(int credit)
{
	((Chocolate_Dispenser*)CurrentContext)->credit += credit;
	cout << "Adding credit... Credit = " << ((Chocolate_Dispenser*)CurrentContext)->credit << endl;
	CurrentContext->setState(Has_Credit);
	return true;
}

/*
insertMoney(For HasCredit) function:
	The purpose of this function is to add credit when there is credit in the 
    machine and then it will display the credit onto the screen.
*/

bool HasCredit::insertMoney(int credit)
{
	((Chocolate_Dispenser*)CurrentContext)->credit += credit;
	cout << "Adding credit... Credit = " << ((Chocolate_Dispenser*)CurrentContext)->credit << endl;
	return true;
}

/*
makeSelection function:
	The function is used for the user selection process it takes a value that
    is the number of chocolate bars that the user wants to order. The function 
    checks if the user has enough money to pay for the chocolate and if the 
    machine has enough chocolate bars inside ready to be dispensed. 
    
    If the inserted money and chocolate in the machine are sufficient for the 
    order a message will appear telling the user that the inserted money and the
    chocolate in the machine is sufficient for order and then deducts the money 
    and chocolate in the machine by the option set by the user. The state is set 
	to Dispenses_Chocolate so it begins the dispensing the chocolate.
*/

bool HasCredit::makeSelection(int option)
{
	cout << "You have selected " << option << " bar(s) of chocolate" << endl; 
    //Displays the option that has been selected

	if (((Chocolate_Dispenser*)CurrentContext)->inventory < option)
	{
		cout << "Error: you have selected more chocolate than the machine contains" << endl;
		return false;
		/*
			This if statement checks if there is enough chocolate (inventory) in
            the dispenser for the number of chocolate bars (option) ordered by 
            the customer. If there is not enough chocolate in the dispenser for 
            the order then it produces an error message and stops the function 
            by returning false so that it doesn't continue on executing the rest 
            of the code in the function.
		*/
	}
	
	if(((Chocolate_Dispenser*)CurrentContext)->credit < option)
	{
		cout << "Error: You don't have enough money for that selection" << endl;	
		return false;
		/*
			This if statement checks if the credit in the machine is enough to 
            pay for the option selected, if there's not enough money in the 
            machine then an error message will pop up and it 
		*/
	}
	
	cout << "Credit and inventory is sufficient for your selection" << endl;

	((Chocolate_Dispenser*)CurrentContext)->inventory -= option;
	((Chocolate_Dispenser*)CurrentContext)->credit -= option;

	CurrentContext->setState(Dispenses_Chocolate);

	return true;
}

/*
moneyRejected function:
	This function is for rejecting the money that has been put into the machine.
	The function sets credit to zero and sets the state to NoCredit.
*/

bool HasCredit::moneyRejected(void)
{
	cout << "Rejecting money....." << endl;
	((Chocolate_Dispenser*)CurrentContext)->credit = 0;
	CurrentContext->setState(No_Credit);
	return true;
}

/*
dispense function:
	The dispense function is called when the machine begins to dispense the 
    chocolate. Displays the current number of chocolate bars (inventory) and 
    amount money currently in the machine (credit).

	If statements are used to check if there is any chocolate bars in the 
    machine and if there is enough credit in the machine, it will set states 
    accordingly.
*/

bool DispensesChocolate::dispense(void)
{
	cout << "Dispensing..." << endl;
	cout << "Inventory = " << ((Chocolate_Dispenser*)CurrentContext)->inventory << endl;
	cout << "Credit = " << ((Chocolate_Dispenser*)CurrentContext)->credit << endl;

	if (((Chocolate_Dispenser*)CurrentContext)->inventory == 0)
	{
		CurrentContext->setState(Out_Of_Chocolate);
	}
	else if (((Chocolate_Dispenser*)CurrentContext)->credit == 0)
	{
		CurrentContext->setState(No_Credit);
	}
	else
	{
		CurrentContext->setState(Has_Credit);
	}
	return true;
}

/*
enterPin(For OutOfChocolate) function:
	The purpose of this function is to stop unauthorised users access to 
    maintenance mode. It does this by asking the user to enter a pin and checks 
    if pin is not correct using an if statement then it changes the state to 
    Out_Of_Chocolate and returns false to stop the function from continuing this
    is checking that the pin is correct. If the pin is correct then the state
    will be set to Maintenance_Mode.
*/

bool OutOfChocolate::enterPin(int pin)
{
	if (pin != ((Chocolate_Dispenser*)CurrentContext)->pin)
	{
		CurrentContext->setState(Out_Of_Chocolate);
		cout << "Invalid pin..." << endl;
		return false;
	}
	else
	{
		cout << endl << "You have entered Maintenance Mode..." << endl;
		CurrentContext->setState(Maintenance_Mode);
	}
	return true;
}

/*
enterPin(For NoCredit) function:
	This functions purpose is the same as the enterPin function for 
    OutOfChocolate, the function also works allot in the same way as the enterPin
    function for OutOfChocolate however its different as when it checks if the 
    user entered pin is not equal to the actual pin it instead changes the state 
    top Has_Credit rather than OutOfChocolate. The code says otherwise if the 
    pin is correct then the state is set to Maintenance_Mode.
*/

bool NoCredit::enterPin(int pin)
{
	if (pin != ((Chocolate_Dispenser*)CurrentContext)->pin)
	{
		CurrentContext->setState(No_Credit);
		cout << "Invalid pin..." << endl;
		return false;
	}
	else
	{
		cout << endl << "You have entered Maintenance Mode..." << endl;
		CurrentContext->setState(Maintenance_Mode);
	}
	return true;
}

/*
exit function:
	The exit function is used to check if the number of chocolate bars in the
    machine is zero then set the current state to Out_Of_Chocolate. Otherwise if
    the inventory is greater than zero then it sets the current state to No_Credit.
*/

bool MaintenanceMode::exit(void)
	{

	if (((Chocolate_Dispenser*)CurrentContext)->inventory == 0)
	{
		CurrentContext->setState(Out_Of_Chocolate);
	}
	else if (((Chocolate_Dispenser*)CurrentContext)->inventory > 0)
	{
		CurrentContext->setState(No_Credit);
	}

	cout << endl << "You have now exited Maintenance Mode..." << endl;

	return true;
}

/*
Chocolate_Dispenser function:
	This function is responsible for creating new instances and storing them 
    into the list (vector), this function allocates memory in availableStates 
    using pushback ready for data from these classes to be pushed in. The
	point of this function is so that the programme knows what state it is in
	by using availableStates as a list of states that the programme can be set 
	to. By the end of the function it initializes the setState to Out_Of_Chocolate.

	It is very important that each class is created in this order so that 
	it corresponds with the values of the enum at the top of the programme,
	this is because the enum value is used to access the state from the 
    available state vector.
*/

Chocolate_Dispenser::Chocolate_Dispenser(void)
{
	this->availableStates.push_back(new OutOfChocolate(this));
	this->availableStates.push_back(new NoCredit(this));
	this->availableStates.push_back(new HasCredit(this));
	this->availableStates.push_back(new DispensesChocolate(this));
	this->availableStates.push_back(new MaintenanceMode(this));

	this->setState(Out_Of_Chocolate);
}

/*
programme function:
	The 'programme' function is used for the calling of all these functions so
	they don't have to be put in the main. The code in this section is for
    testing to show that the code above works as intended. A menu has been 
    created for the user to test different areas of the programme individually 
    and be able to pass any value they want into the functions. 
	
	The reason the maintenance mode options and dispensing options are put on the 
	same menu is so that they can be tested properly, for instance the user can't 
	addChocolate unless they are in maintenance mode, if we try to add chocolate
	outside of maintenance mode the programme will fail.
*/

void programme(void)
{
	Chocolate_Dispenser MyDispenser;

	int choice = 0;
	int enteredPin = 0;
	int amountOfInsertedMoney = 0;
	int amountOfRequestedChocolate = 0;
	int amountOfAddedChocolate = 0;

	cout << "		Chocolate dispensing machine (test code)" << endl << endl;
	cout << "Type one of the choices below and press enter" << endl << endl;
	cout << "What do you want to do?" << endl;
	cout << "Type '1' to insert money" << endl;
	cout << "Type '2' to get back money" << endl;
	cout << "Type '3' to make a selection" << endl;
	cout << "Type '4' to dispense chocolate" << endl;
	cout << "Type '5' to go into maintenance mode" << endl;
	cout << "Type '6' to add chocolate (maintenance mode)" << endl;
	cout << "Type '7' to exit maintenance mode" << endl;
	cout << "Type '8' to end programme" << endl << endl;

	while(cin >> choice)
	{
		switch (choice) 
		{
		case 1:
			cout << "Amount of money you want to insert: ";
			cin >> amountOfInsertedMoney;
			MyDispenser.insertMoney(amountOfInsertedMoney); 
			//This will display an error if their is no chocolate in the machine
			break;

		case 2:
			MyDispenser.moneyRejected();
			break;

		case 3:
			cout << "How many bars of chocolates do you want to buy: ";
			cin >> amountOfRequestedChocolate;
			MyDispenser.makeSelection(amountOfRequestedChocolate);

			break;

		case 4:
			MyDispenser.dispense();
			break;

		case 5:
			cout << "Enter the pin: ";
			cin >> enteredPin;
			MyDispenser.enterPin(enteredPin);
			//If you try to run this function while in maintenance mode it will produce an error
			break;

		case 6:
			cout << "Amount of chocolate you want to add: ";
			cin >> amountOfAddedChocolate;
			MyDispenser.addChocolate(amountOfAddedChocolate);
			//Can only run this function if the state is set to maintenance mode otherwise an error is displayed
			break;

		case 7:
			MyDispenser.exit();
			//Displays an error if run while not in maintenance mode
			break;

		case 8:
			cout << "Ending programme...";
			exit(0);

		default:
			cout << choice << " is not an available choice" << endl;
			break;
		}

		cout << endl;
		cout << "What do you want to do now?" << endl;
	}
}

int main()
{
	programme();
	cin.ignore();
	cin.get(); //Stops the screen from closing down.
	return 0;
}
