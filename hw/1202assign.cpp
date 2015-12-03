#include <iostream>
using namespace std;

struct node
{
	int value;
	node *prev;
	node *next;
};

class list
{
public:
	node *head;
	node *tail;
	int size;
	list() {
		head = new node;
		tail = new node;
		size = 0;
		head->next = tail;
		tail->prev = head;
	}
	void appendT(int item)
	{
		node *p = new node;
		p->value = item;
		p->prev = tail->prev;
		p->next = tail;
		tail->prev->next = p;
		tail->prev = p;
	}
	void appendH(int item)
	{
		node *p = new node;
		p->value = item;
		p->prev = head;
		p->next = head->next;
		head->next->prev = p;
		head->next = p;
	}
};


int main()
{
	list a, b, c;

	char temp = 0;
	while ((temp = cin.get()) != '\n') { //how to input data!!!
		a.appendT(temp - '0'); //ascii!!
		++a.size;
	}
	while ((temp = cin.get()) != '\n') {
		b.appendT(temp - '0');
		++b.size;
	}

	int prevnum = 0;  //to add one
	node *aptr = (a.tail)->prev, *bptr = (b.tail)->prev, *cptr;
	while (aptr != a.head || bptr != b.head) { //note not to use &&
		int na = 0, nb = 0;
		if (aptr != a.head) {
			na = aptr->value;
			aptr = aptr->prev;
		}
		if (bptr != b.head) {
			nb = bptr->value;
			bptr = bptr->prev;
		}
		int tmp = prevnum;
		c.appendH((na + nb + tmp) % 10);
		prevnum = (na + nb + tmp) / 10;
	}
	if (prevnum == 1) c.appendH(1);
	
	cptr = (c.head)->next; //position of initilize cptr
	while (cptr != c.tail) {
		cout << cptr->value;
		cptr = cptr->next;
	}
	cout << endl;
	//while (1);
	return 0;
}