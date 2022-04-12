#pragma once
#include <iostream>

using namespace std;

class Dinner {
    int num = 0;
public:
    virtual ~Dinner() = default;
    virtual Dinner* Clone() const { return new Dinner(*this); };
    int GetNum() const { return num; };
    int* SetNum() { return &num; };

};

class Soup : public Dinner {
};

class OnPlate : public Dinner {
};

class Mushroom : public Soup {
    bool bread = 1;
    bool potatoes;
public:
    Mushroom();
    Mushroom(int num_, bool bread_);
    Mushroom* Clone() const { return new Mushroom(*this); };
    bool GetBool() const { return bread; };
    friend ostream& operator<<(ostream& os, const Mushroom& mushroom);
};

class Tomato : public Soup {
    bool noodles = 1;
    bool bread;
public:
    Tomato();
    Tomato(int num_, bool noodles_);
    Tomato* Clone() const { return new Tomato(*this); };
    bool GetBool() const { return noodles; };
    friend ostream& operator<<(ostream& os, const Tomato& tomato);
};

class Fish : public OnPlate {
    bool chips = 1;
    bool potatoes;
public:
    Fish();
    Fish(int num_, bool chips_);
    Fish* Clone() const { return new Fish(*this); };
    bool GetBool() const { return chips; };
    friend ostream& operator<<(ostream& os, const Fish& fish);
};

class Knuckle : public OnPlate {
    bool bread = 1;
    bool potatoes;
public:
    Knuckle();
    Knuckle(int num_, bool bread_);
    Knuckle* Clone() const { return new Knuckle(*this); };
    bool GetBool() const { return bread; };
    friend ostream& operator<<(ostream& os, const Knuckle& knuckle);
};


