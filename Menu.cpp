#include "Menu.h"

Mushroom::Mushroom() : bread(1), potatoes(0) { *SetNum() = 1; }

Tomato::Tomato() : bread(0), noodles(1) { *SetNum() = 1; }

Fish::Fish() : chips(1), potatoes(0) { *SetNum() = 1; }

Knuckle::Knuckle() : bread(1), potatoes(0) { *SetNum() = 1; }

//cout << "Sir you cannot order no soup" << endl;
Mushroom::Mushroom(int num_, bool bread_) {
	bool temp = 1;
	while (temp) {
		try {
			if (num_ > 0 && num_ <= 10) {
				temp = 0;
			}
			else
				throw num_;
		}
		catch (int n) {
			if (n <= 0)
				cout << "Sir you cannot order no soup" << endl;
			else
				cout << "Sir I am awfully sorry but I suppose there is a lack of soup" << endl;
			cin >> num_;
		}
	}

	*SetNum() = num_;
	bread = bread_;
	potatoes = !bread_;
}

Tomato::Tomato(int num_, bool bread_) {
	bool temp = 1;
	while (temp) {
		try {
			if (num_ > 0 && num_ <= 10) {
				temp = 0;
			}
			else
				throw num_;
		}
		catch (int n) {
			if (n <= 0)
				cout << "Sir you cannot order no soup" << endl;
			else
				cout << "Sir I am awfully sorry but I suppose there is a lack of soup" << endl;
			cin >> num_;
		}
	}

	*SetNum() = num_;
	bread = bread_;
	noodles = !bread_;
}


Fish::Fish(int num_, bool chips_) {
	bool temp = 1;
	while (temp) {
		try {
			if (num_ > 0 && num_ <= 10) {
				temp = 0;
			}
			else
				throw num_;
		}
		catch (int n) {
			if (n <= 0)
				cout << "Sir you cannot order no fish" << endl;
			else
				cout << "Sir I am awfully sorry but I suppose there is a lack of soup" << endl;
			cin >> num_;
		}
	}

	*SetNum() = num_;
	chips = chips_;
	potatoes = !chips_;
}

Knuckle::Knuckle(int num_, bool bread_) {
	bool temp = 1;
	while (temp) {
		try {
			if (num_ > 0 && num_ <= 10) {
				temp = 0;
			}
			else
				throw num_;
		}
		catch (int n) {
			if (n <= 0)
				cout << "Sir you cannot order no knuckle" << endl;
			else
				cout << "Sir I am awfully sorry but I suppose there is a lack of soup" << endl;
			cin >> num_;
		}
	}

	*SetNum() = num_;
	bread = bread_;
	potatoes = !bread_;
}

ostream& operator<<(ostream& os, const Mushroom& mushroom) {
	cout << "So " << mushroom.GetNum() << " mushroom soup with ";
	if (mushroom.bread == 1)
		os << "bread for You Sir" << endl;
	else
		os << "potatoes for You Sir" << endl;
	return os;
}


ostream& operator<<(ostream& os, const Tomato& tomato) {
	cout << "So " << tomato.GetNum() << " tomato soup with ";
	if (tomato.bread == 1)
		os << "bread for You Sir" << endl;
	else
		os << "noodles for You Sir" << endl;
	return os;
}


ostream& operator<<(ostream& os, const Fish& fish) {
	cout << "So " << fish.GetNum() << " fish with ";
	if (fish.potatoes == 1)
		os << "potatoes for You Sir" << endl;
	else
		os << "chips for You Sir" << endl;
	return os;
}


ostream& operator<<(ostream& os, const Knuckle& knuckle) {
	cout << "So " << knuckle.GetNum() << " knuckle with ";
	if (knuckle.bread == 1)
		os << "bread for You Sir" << endl;
	else
		os << "potatoes for You Sir" << endl;
	return os;
}

