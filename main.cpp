#include <iostream>
#include <string>
#include "classes.h"
using namespace std;



void bunnyloop(blist list);

int main() {

	blist list;  //creating object list of type blist

	bunnyloop(list);


	return 0;
}

void bunnyloop(blist list) {
	int bunnys = 5;
	int year = 0;

	list.createnode("male", "black", 5, "Bunnicula", true);
	list.createnode("female", "white", 2, "Bunn Bunns", false);
	list.createnode("female", "brown", 2, "Hopster", true);
	list.createnode("male", "white", 1, "BB", false);
	list.createnode("male", "black", 1, "Ya Boi", false);
	
	while (bunnys > 1) {
		year += 1;
		list.aging();
		list.procreate();
		list.bunniesdie();

		list.display();
		bunnys = list.count();
		cout << list.count() << endl;
	}
}

