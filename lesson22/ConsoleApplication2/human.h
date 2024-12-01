#pragma once
#include <string>
#include <iostream>

class Human
{
public:
	std::string name;
	int age;
	virtual void makeWork() {
		std::cout << " zdorovye ";
	}
	Human copy() {
		Human h;
		h.age = age;
		h.name = name;
		return h;
	}

	void makePizza() {
		takeIngrediants();
		// plita();
		// coock();
	}

protected:
	virtual void takeIngrediants() {

	};

};

class Grajdanin : public Human
{
public:
	int countryCode;
	void makeWork() override {
		std::cout << "army";
	}
	
	void takeIngrediants() {
		//...
	};
};


class Worker : public Grajdanin
{
public:
	float salary;
	int firma;
	void makeWork() override {
		std::cout << "make maoney";
	}
	void takeIngrediants() {

	};
};


class Tokar {
public:
	virtual void tochitDetali() = 0;
};


class Svarshik {
public:
	virtual void varitDetali() = 0;
};

class IMainMaster {
public:
	virtual void tochitDetali() = 0;
	virtual void varitDetali() = 0;
};

class Master : public Tokar, public Svarshik
{
public:
	void tochitDetali() {

	}

	void varitDetali() {

	}

	void makeWork() {

	}
};

void registerHuman(Human* h) {
	//....
}


void funcWorker(){

	Human* h = new Grajdanin;
	Human* h2 = new  Worker;

	registerHuman(h);
	registerHuman(h2);

	//if (h.type() == Worker) {
	//	h->makeMobey()
	//}

	for (auto hi : { h, h2 }) {
		hi->makeWork();
		hi->makePizza();
	}

};

