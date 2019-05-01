#include <iostream>
#include <string>
using namespace std;

struct bnode
{
	string sex;
	string color;
	int age;
	string name;
	bool radioactive_mutant_vampire_bunny;

	bnode *next;


};

class blist
{
private:
	bnode *head, *tail;
public:
	blist()
	{
		head = NULL;
		tail = NULL;
	}

	//Need to figure out how to randomly assign all node attributes
	void createnode() {
		bnode *temp = new bnode;
		temp->sex = "male";
		temp->color = "brown";
		temp->age = 0;
		temp->name = "B";
		temp->radioactive_mutant_vampire_bunny = false;
		temp->next = NULL;
		if (head == NULL) {
			head = temp;
			tail = temp;
			temp = NULL;
		}
		else {
			tail->next = temp;
			tail = temp;
		}
	}
	void createnode(string _sex, string _color, int _age, string _name, bool _rmvb)
	{
		bnode *temp = new bnode;
		temp->sex = _sex;
		temp->color = _color;
		temp->age = _age;
		temp->name = _name;
		temp->radioactive_mutant_vampire_bunny = _rmvb;
		temp->next = NULL;
		if (head == NULL)
		{
			head = temp;
			tail = temp;
			temp = NULL;
		}
		else
		{
			tail->next = temp;
			tail = temp;
		}
	}
	void display()
	{
		bnode *temp = new bnode;
		temp = head;
		while (temp != NULL)
		{
			cout << temp->sex << ',' << temp->color << ',' << temp->age << ',' << temp->sex << "\n";
			temp = temp->next;
		}
	}
	int count() {
		int count = 0;
		bnode *temp = new bnode;
		temp = head;
		while (temp != NULL) {
			count += 1;
			temp = temp->next;
		}
		return count;
	}

	int countmales() {
		int count = 0;
		bnode *temp = new bnode;
		temp = head;
		while (temp != NULL) {
			if (temp->sex == "male" && temp->age>1) {
				count += 1;
			}
			temp = temp->next;
		}
		return count;
	}

	void aging() {
		bnode *temp = new bnode;
		temp = head;
		while (temp != NULL)
		{
			temp->age += 1;
			temp = temp->next;
		}
	}

	//Need to make the newborn bunnies the same color as their mothers
	void procreate() {
		bnode *temp = new bnode;
		temp = head;
		while (temp != NULL)
		{
			if (temp->sex == "female" && temp->age > 1 && countmales() > 0) {
				createnode();
			}
			temp = temp->next;
		}
	}

	//Fixed,BUG:Currently ending program when first bunny dies
	void bunniesdie() {
		bnode *temp = new bnode;
		temp = head;
		while (temp->age > 10)
		{
			head = head->next;
			delete temp;
			temp = head;
			
				
			
		}
	}
};
