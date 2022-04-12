#include <iostream>
#include "Menu.h"
#include "Order.h"
using namespace std;

int main()
{
	//PART 1
	cout << endl << "-------- PART 1 -------- " << endl;
	Tomato tomato;
	Mushroom mushroom(15, 0);
	Knuckle knuckle(0, 1);
	Fish fish(10, 1);
	cout << tomato << mushroom << knuckle << fish;
	//PART 2
	cout << endl << "-------- PART 2 -------- " << endl;
	Dinner* food[6] = { &tomato, &mushroom, new Fish(3,0), new Fish(5,0),  new Tomato(10,1), &knuckle };
	Order order(food, 6);
	Dinner* food2[1] = { nullptr };
	Order order2(food2, 1);
	cout << "Order one" << order;
	cout << "Order two" << order2;
	//PART 3
	cout << endl << "-------- PART 3 -------- " << endl;
	order.fix();
	cout << "Order one fixed" << order;
}
