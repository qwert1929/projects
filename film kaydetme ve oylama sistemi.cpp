#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>

using namespace std;

class Node {
	public:
    	int year;
    	double rate;
    	string name;
    	Node *next;
    	
};
Node *head = new Node();

void add(string name, double rate, int year)
{
	
	// Create new Node to Insert Record
	Node *t = new Node();
	t->name = name;
	t->rate = rate;
	t->year = year;
	t->next = NULL;

	// Insert at Begin
	if (head == NULL)
	{
		t->next = head;
		head = t;
		cout<<"first insertion to beginning\n";
	} 
	// Insert at middle or End
	else
	{
		Node *c = head;
		while (c->next != NULL && c->next->name < t->name)
		{
			c = c->next;
		}
		t->next = c->next;
		c->next = t;
		cout<<"inserted mid or end\n";
	}
	cout<<endl;
	//cout << "Record Inserted "<< "Successfully\n";
}

void remove(string name)
{
    Node ** head_ref = &head;
    // Store head node
    Node* temp = *head_ref;
    Node* prev = NULL;
     
    // If head node itself holds
    // the key to be deleted
    if (temp != NULL && temp->name == name)
    {
        *head_ref = temp->next; // Changed head
        delete temp;            // free old head
        return;
    }
 
    // Else Search for the key to be deleted,
    // keep track of the previous node as we
    // need to change 'prev->next' */
      else
    {
    while (temp != NULL && temp->name != name)
    {
        prev = temp;
        temp = temp->next;
    }
 
    // If key was not present in linked list
    if (temp == NULL)
        return;
 
    // Unlink the node from linked list
    prev->next = temp->next;
 
    // Free memory
    delete temp;
    }
}

void display()
{
	Node *p = head;
	if (p == NULL)
	{
		cout << "No Record "<< "Available\n";
	}
	else
	{
		cout << "Movie info:\n";
		// Until p is not NULL
		while (p != NULL)
		{
			cout << p->name <<setw(20)<< " \t"<< p->year <<setw(10)<< "\t"<< p->rate <<setw(10)<< "\t"<< endl;
			p = p->next;
		}
		cout<<endl;
	}
}
void update(string name, double rate)
{
	// if head is NULL
	if (!head) {
		cout << "No such Record "<< "Avialable\n";
		return;
	}

	// Otherwise
	else {
		Node* p = head;
		while (p) {
			if (p->name == name)
			{
			p->rate=rate;
			//cout << "movie name\t"<< p->name << endl;
			//cout << "new rate\t"<< p->rate << endl;
				return;
			}
			p = p->next;
			
		}

		if (p == NULL)
			cout << "No such Record "<< "Avialable\n";
	}
	
}

void printByYear()
{
	Node *temphead = head;
	int tempyear;
	string tempname;
	int j;
	int counter = 0;
	while (temphead)
	{
		temphead = temphead->next;
		counter++;
	}
	temphead = head;
	
	for (j=0; j<counter; j++)
	{
		while (temphead->next)
		{
			if ((temphead->year) < (temphead->next->year))
			{
				tempyear = temphead->year;
				temphead->year = temphead->next->year;
				temphead->next->year = tempyear;

				tempname = temphead->name;
				temphead->name = temphead->next->name;
				temphead->next->name = tempname;
				
				
			}
			temphead = temphead->next;
		}	
		temphead = head;
	}
	cout<<"Printed by year:\n"<<endl;
	display();
}

void printByName()
{
	Node *temphead = head;
	int tempyear;
	string tempname;
	int j;
	int counter = 0;
	while (temphead)
	{
		temphead = temphead->next;
		counter++;
	}
	temphead = head;

	for (j=0; j<counter; j++)
	{
		while (temphead->next)
		{
			if (temphead->name > temphead->next->name)
			{
				tempyear = temphead->year;
				temphead->year = temphead->next->year;
				temphead->next->year = tempyear;

				tempname = temphead->name;
				temphead->name = temphead->next->name;
				temphead->next->name = tempname;
			}
			temphead = temphead->next;
		}
		temphead = head;
	}

	cout<<"Printed by name:\n"<<endl;
	display();
}
void printByRate()
{
	Node *temphead = head;
	int temprate;
	string tempname;
	int j;
	int counter = 0;
	while (temphead)
	{
		temphead = temphead->next;
		counter++;
	}
	temphead = head;

	for (j=0; j<counter; j++)
	{
		while (temphead->next)
		{
			if (temphead->rate < temphead->next->rate)
			{
				temprate = temphead->rate;
				temphead->rate = temphead->next->rate;
				temphead->next->rate = temprate;

				tempname = temphead->name;
				temphead->name = temphead->next->name;
				temphead->next->name = tempname;
			}
			temphead = temphead->next;
		}
		temphead = head;
	}
	cout<<"Printed by rate:\n"<<endl;
	display();
}

void saveToFileByYear()
{
	ofstream myfile;
  	myfile.open ("output.txt");
  	//myfile.display();
  	myfile.close();
  	
}

int main() {
	head = NULL;
	add("aa",9.9,2000);
	add("gg",5.3,2015);
	add("ss",8.2,1995);
	add("bb",8.5,1980);
	display();
	remove("aa");
	remove("ss");
	remove("aa");
	update("ss",6.5);
	update("gg",6.3);
	display();
	printByYear();
	printByName();
	printByRate();
	saveToFileByYear();
//Meriç Tunahan Tomruk
	return 0;
}
