#include <iostream>

using namespace std;

class Animal
{
	public:
	Animal()
	{
		greeting = "Ahh";
	}
	
	//this is the constructor
	Animal (string sound)
	{
		greeting = sound;
	}
	
	void speak()
	{
		cout << greeting << endl;
	}
	private:
	string greeting;
};

int main()
{
//Animal lion; this calls the defualt constructor
Animal lion("roar"); // calls the same function, but puts roar in the string
Animal cat("woof");
Animal elephant("meow");
//these animals are on the stack

lion.speak();
cat.speak();
elephant.speak();
// these animals live on the heap/off the stack

Animal * tiger = new Animal("roar, as well!");
Animal * liger = new Animal ("LOL");
Animal * person;

person = new Animal("Don't eat me");

//these animals are pointers
(*tiger).speak();
//this syntax (above) is ugly
//this syntax is preferable
tiger->speak();
liger->speak();
person->speak();

//whenever you do something new, you need to delete, as well
delete tiger;
delete liger;
delete person;
return 0;
}