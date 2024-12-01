#include <iostream>

class Boy
{
public:

	void setWalcking(Walking* w) {
		m_walk = w;
	}

	Walking* m_walk;

	void move() {
		m_walk->move();
	}
};


class Walking {
public:
	void move() {
		std::cout << "walk" << std::endl;
	}
};


class Run : public Walking {
public:
	void move() {
		std::cout << "run" << std::endl;
	}
};

class Jump : public Walking {
public:
	void move() {
		std::cout << "jump" << std::endl;
	}
};

class Fly //: public Walking
{
public:
	//void move() {

	//}

	void fly() {
		std::cout << "fly" << std::endl;
	}
};

class MoveByFly : public Walking {
	void move() {
		f.fly();
	}
	Fly f;
};


void setStrategy() {

	Boy boy;
	auto w = new Walking;
	boy.setWalcking(w);

	auto j = new Jump;
	boy.setWalcking(j);

	auto f = new MoveByFly;
	boy.setWalcking(f);


}

