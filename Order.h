#pragma once
#include "Menu.h"

class Order
{
	Dinner** order;
	int size;
public:
	Order();
	Order(Dinner** plates, int size_);
	~Order();
	int* CountType(Dinner* food);
	void fix();
	friend ostream& operator <<(ostream& os, Order food);
};


Order::Order()
{
	order = nullptr;
	size = 0;
}

Order::Order(Dinner** plates, int size_) {
	size = size_;
	order = new Dinner * [size_];
	for (int i = 0; i < size_; i++) {
		order[i] = plates[i];
	}
}

Order::~Order()
{
	order = nullptr;
	size = 0;
}


ostream& operator<<(ostream& os, Order food) {
	os << endl;
	for (int i = 0; i < food.size; i++) {
		if (!food.order[i]) {
			os << "Sir, my sincerest apologies but something went wrong with your order";
			return os;
		}
		Tomato* tom = dynamic_cast<Tomato*>(food.order[i]);
		Mushroom* mus = dynamic_cast<Mushroom*>(food.order[i]);
		Knuckle* knu = dynamic_cast<Knuckle*>(food.order[i]);
		Fish* fish = dynamic_cast<Fish*>(food.order[i]);
		if (tom)
			os << *tom;
		else if (mus)
			os << *mus;
		else if (knu)
			os << *knu;
		else if (fish)
			os << *fish;
	}
	return os;
}

int* Order::CountType(Dinner* food) {
	int* temp = nullptr;

	int tempsize = 0;
	Tomato* tom = dynamic_cast<Tomato*>(food);
	Mushroom* mus = dynamic_cast<Mushroom*>(food);
	Knuckle* knu = dynamic_cast<Knuckle*>(food);
	Fish* fish = dynamic_cast<Fish*>(food);
	if (tom) {
		for (int i = 0; i < size; i++) {
			Tomato* tom2 = dynamic_cast<Tomato*>(order[i]);
			if (tom2 && (tom->GetBool() == tom2->GetBool())) {
				int j = 0;
				int* temp2 = new int[tempsize + 1];
				for (; j < tempsize; j++) {
					temp2[j] = temp[j];
				};
				tempsize++;
				temp2[j] = i;
				temp = temp2;
			}
		}
	}
	else if (mus) {
		for (int i = 0; i < size; i++) {
			Mushroom* mus2 = dynamic_cast<Mushroom*>(order[i]);
			if (mus2 && (mus->GetBool() == mus2->GetBool())) {
				int j = 0;
				int* temp2 = new int[tempsize + 1];
				for (; j < tempsize; j++) {
					temp2[j] = temp[j];
				};
				tempsize++;
				temp2[j] = i;
				temp = temp2;
			}
		}
	}
	else if (fish) {
		for (int i = 0; i < size; i++) {
			Fish* fish2 = dynamic_cast<Fish*>(order[i]);
			if (fish2 && (fish->GetBool() == fish2->GetBool())) {
				int j = 0;
				int* temp2 = new int[tempsize + 1];
				for (; j < tempsize; j++) {
					temp2[j] = temp[j];
				};
				tempsize++;
				temp2[j] = i;
				temp = temp2;
			}
		}
	}
	else if (knu) {
		for (int i = 0; i < size; i++) {
			Knuckle* knu2 = dynamic_cast<Knuckle*>(order[i]);
			if (knu2 && (knu->GetBool() == knu2->GetBool())) {
				int j = 0;
				int* temp2 = new int[tempsize + 1];
				for (; j < tempsize; j++) {
					temp2[j] = temp[j];
				};
				tempsize++;
				temp2[j] = i;
				temp = temp2;
			}
		}
	}
	if (tempsize > 1) {
		int* temp2 = new int[tempsize + 1];
		for (int j = 0; j < tempsize; j++) {
			temp2[j] = temp[j];
		};
		temp2[tempsize] = -1;
		temp = temp2;
		return temp;
	}
	else
		return nullptr;
}

void Order::fix() {
	for (int i = 0; i < 2; i++) {
		Tomato tom(1, i);
		int* temp = Order::CountType(&tom);
		if (temp != nullptr) {
			int i = 1;
			while (temp[i] != -1) {
				*order[temp[0]]->SetNum() = order[temp[0]]->GetNum() + order[temp[i]]->GetNum();
				i++;
			}
			i = 1;
			Dinner** ordertemp = new Dinner * [size - i + 1];
			for (int l = 0; l < size; l++) {
				if (l != temp[i]) {
					ordertemp[l - i + 1] = order[l];
				}
				else
					i++;
			}
			size = size - i + 1;
			order = ordertemp;
		}
	}
	for (int i = 0; i < 2; i++) {
		Mushroom mus(1, i);
		int* temp = Order::CountType(&mus);
		if (temp != nullptr) {
			int i = 1;
			while (temp[i] != -1) {
				*order[temp[0]]->SetNum() = order[temp[0]]->GetNum() + order[temp[i]]->GetNum();
				i++;
			}
			i = 1;
			Dinner** ordertemp = new Dinner * [size];
			for (int l = 0; l < size; l++) {
				if (l != temp[i])
					ordertemp[l - i + 1] = order[l];
				else
					i++;
			}
			size = size - i + 1;
			order = ordertemp;
		}
	}
	for (int i = 0; i < 2; i++) {
		Knuckle knu(1, i);
		int* temp = Order::CountType(&knu);
		if (temp != nullptr) {
			int i = 1;
			while (temp[i] != -1) {
				*order[temp[0]]->SetNum() = order[temp[0]]->GetNum() + order[temp[i]]->GetNum();
				i++;
			}
			i = 1;
			Dinner** ordertemp = new Dinner * [size];
			for (int l = 0; l < size; l++) {
				if (l != temp[i])
					ordertemp[l - i + 1] = order[l];
				else
					i++;
			}
			size = size - i + 1;
			order = ordertemp;
		}
	}
	for (int i = 0; i < 2; i++) {
		Fish fish(1, i);
		int* temp = Order::CountType(&fish);
		if (temp != nullptr) {
			int i = 1;
			while (temp[i] != -1) {
				*order[temp[0]]->SetNum() = order[temp[0]]->GetNum() + order[temp[i]]->GetNum();
				i++;
			}
			i = 1;
			Dinner** ordertemp = new Dinner * [size];
			for (int l = 0; l < size; l++) {
				if (l != temp[i])
					ordertemp[l - i + 1] = order[l];
				else
					i++;
			}
			size = size - i + 1;
			order = ordertemp;
		}
	}
}