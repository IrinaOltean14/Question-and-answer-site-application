#pragma once
#include <vector>
using namespace std;

class Observer {
public:
	virtual void update() = 0;
	virtual ~Observer() {};
};

class Subject {
private:
	vector<Observer*> observers;
public:
	void addObserver(Observer* o) {
		observers.push_back(o);
	}

	void notify() {
		for (auto o : observers)
			o->update();
	}
};