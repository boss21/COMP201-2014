#include <iostream>
#include <string>
using namespace std;

// A class to represent fingers on a hand
class FingerCount
{

public:

	// Initializes the hand
	//
	// Postconditions: all fingers down
	FingerCount();

	// Initializes the hand
	//
	// Postconditions: only those fingers up where the corresponding
	//                 character is a pipe ('|')
	FingerCount(const string& hand);

	// Sets a single finger
	//
	// Postconditions: finger at index is set to raised
	void setFinger(int index, bool raised);

	// Sets the entire hand at once
	//
	// Preconditions: hand array is at least size 5
	// Postconditions: for each element of hand, the
	//                 corresponding finger state is set
	void setHand(bool hand[]);

	// Sets the entire hand at once
	// Preconditions: hand is at least length 5
	// Postconditions: for each character of hand that is a pipe ('|')
	//                 the corresponding figure is raised, all others
	//                 lowered
	void setHand(const string& hand);

	// Sets the hand to thumbs up
	//
	// Postconditions: index 0 is raised, all others lowered
	void thumbsUp();


	// Sets the hand to peace sign
	//
	// Postconditions: indexes 1 and 2 are raised, all others lowered
	void peace();

	// Sets the hand to a closed fist
	//
	// Postconditions: all fingers lowered
	void fist();

	// Sets the hand to open
	//
	// Postconditions: all fingers raised
	void highFive();

	// Gets the status of a finger
	// Returns: if index is in [0, 4], returns true if the corresponding finger is raised;
	//			false if index is out of range
	bool getFinger(int index) const;

	// Gets the number of raised fingers
	//
	// Returns: the number of fingers that are raised
	int numFingers() const;

	// Gets a string representation of the hand state
	// Returns: a string with 5 characters; for each finger that is raised, a pipe ('|')
	//          otherwise an underscore ('_')
	string fingerString() const;

	// Gets the total number of raised fingers between
	// two hands
	// Returns: total number of raised fingers between fc1 and fc2
	friend int sum(const FingerCount& fc1, const FingerCount& fc2);

	// Gets the total number of raised fingers between
	// two hands
	// Returns: total number of raised fingers between fc1 and fc2
	friend int operator +(const FingerCount& fc1, const FingerCount& fc2);

	// Compares two hands
	// Returns: true if the the states of all fingers are the same for fc1 and fc2
	friend bool operator ==(const FingerCount& fc1, const FingerCount& fc2);

	// Outputs the string representation of a hand
	// Postconditions: the string representation of fc is sent to outs
	// Returns: outs
	friend ostream& operator <<(ostream& outs, const FingerCount& fc);

private:
	bool fingers[5];

};

int main()
{

	FingerCount fc1;
	cout << fc1 << " (" << fc1.numFingers() << ") = _____ (0)" << endl;

	FingerCount fc2("_|___");
	cout << fc2 << " (" << fc2.numFingers() << ") = _|___ (1)" << endl;

	cout << (fc1 == fc2) << " = 0" << endl;
	cout << (fc1 + fc2) << " = 1" << endl;

	//

	fc2.fist();
	// this whole part my code got wrong
	cout << (fc1 == fc2) << " = 1" << endl;
	cout << (fc1.numFingers() == fc2.numFingers()) << " = 1" << endl;
	cout << (fc1 + fc2) << " = 0" << endl;

	//

	fc1.thumbsUp();
	cout << (fc1 == fc2) << " = 0" << endl;
	cout << (fc1.numFingers() + fc2.numFingers()) << " = 1" << endl;

	//

	fc2.setHand("|___|");
	fc1.setFinger(4, true);

	cout << endl;
	cout << (fc1 == fc2) << " = 1" << endl;
	cout << (fc1.numFingers() == fc2.numFingers()) << " = 1" << endl;

	//

	bool hand[] = { false, false, false, true, false };
	fc2.setHand(hand);

	fc1.highFive();

	cout << (fc1 + fc2) << " = 6" << endl;

	//

	fc1.peace();
	cout << fc1 << " = _||__" << endl;

	//

	return 0;

}

///////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////

FingerCount::FingerCount()
{
	// Initializes the hand
	//
	// Postconditions: all fingers down
	for (int i = 0; i <= 4; i++)
		fingers[i] = false;

	for (int i = 0; i <= 4; i++)
	{
		if (fingers[i] == false)
		{
			cout << '_';
		}
	}
}

FingerCount::FingerCount(const string& hand)
{
	for (int i = 0; i <= 4; i++)
		fingers[i] = false;
	// 
	for (int i = 0; i <= 4; i++)
	{
		if (hand.at(i) == '_')
		{
			fingers[i] = false;
			cout << '_';
		}
		else
		{
			fingers[i] = true;
			cout << '|';
		}
	}
}

void FingerCount::setFinger(int index, bool raised)
{
	// Sets a single finger
	//
	// Postconditions: finger at index is set to raised
	fingers[index] = raised;

}

void FingerCount::setHand(bool hand[])
{
	// Sets the entire hand at once
	//
	// Preconditions: hand array is at least size 5
	// Postconditions: for each element of hand, the
	//                 corresponding finger state is set 
	for (int i = 0; i <= 4; i++)
	{
		fingers[i] = hand[i];
	}

}

void FingerCount::setHand(const string& hand)
{
	// Your code here
	for (int i = 0; i <= 4; i++)
	{
		if (hand.at(i) == '_')
		{
			fingers[i] = false;
			cout << '_';
		}
		else
		{
			fingers[i] = true;
			cout << '|';
		}
	}

}

void FingerCount::thumbsUp()
{
	// Your code here
	fingers[0] = true;
	fingers[1] = false;
	fingers[2] = false;
	fingers[3] = false;
	fingers[4] = false;
}

void FingerCount::peace()
{
	// Your code here
	fingers[0] = false;
	fingers[1] = true;
	fingers[2] = true;
	fingers[3] = false;
	fingers[4] = false;
	
}

void FingerCount::fist()
{
	// Your code here
	for (int i = 0; i <= 4; i++)
		fingers[i] = false;
}

void FingerCount::highFive()
{
	// Your code here
	for (int i = 0; i <= 4; i++)
	fingers[i] = true;
}

bool FingerCount::getFinger(int index) const
{
	// Gets the status of a finger
	// Returns: if index is in [0, 4], returns true if the corresponding finger is raised;
	//			false if index is out of range
	if ((index > 0) && (index <= 4))
	{
		if ( fingers[index] == true)
		{
			return true;
		}
	}
	return false;
}

int FingerCount::numFingers() const
{
	// Gets the number of raised fingers
	//
	// Returns: the number of fingers that are raised
	int count = 0;
	for (int i = 0; i <= 4; i++)
	{
		if (fingers[i] == true)
		{
			count++;
		}
	}
	return count;
}

string FingerCount::fingerString() const
{
	
	string temp;
	for (int i = 0; i <= 4; i++)
	{
		if (fingers[i] == true)
		{
			temp.at(i) = '|';
		}
		else
		{
			temp.at(i) = '_';
		}
	}
	return temp;
}

int sum(const FingerCount& fc1, const FingerCount& fc2)
{
	// Gets the total number of raised fingers between
	// two hands
	// Returns: total number of raised fingers between fc1 and fc2


	return (fc1.numFingers() + fc2.numFingers());
}


int operator +(const FingerCount& fc1, const FingerCount& fc2)
{
	// Gets the total number of raised fingers between
	// two hands
	// Returns: total number of raised fingers between fc1 and fc2
	int sum;
	sum = fc1.numFingers() + fc2.numFingers();

	return sum;
}

bool operator ==(const FingerCount& fc1, const FingerCount& fc2)
{
	// Compares two hands
	// Returns: true if the the states of all fingers are the same for fc1 and fc2
	if (fc1.numFingers() == fc2.numFingers())
	{
		return true;
	}
	return false;
}

ostream& operator <<(ostream& outs, const FingerCount& fc)
{
	// Your code here
	for (int i = 0; i <= 4; i++)
	{
		if (fc.fingers[i] == true)
		{
			outs << "|";
		}
		else
		{
			outs << "_";
		}
	}
	return outs;
}
