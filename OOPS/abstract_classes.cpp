#include <iostream>
using namespace std;

class Vehicle {
	public :
		string color;

		// Pure virtual fn
	virtual void print() = 0;


};


class Car : public Vehicle {
	public :
		int numGears;




		
		void print() {
			cout << "Car" << endl;
		}


};

int main() {
	Vehicle v;

	Car c;

	/*
	Car c;

	v.print();

	c.print();


	Vehicle *v1 = new Vehicle;

	Vehicle *v2;
	// v2 = &v;

	v2 = &c;

	v1 -> print();

	v2 -> print();
	*/

}


