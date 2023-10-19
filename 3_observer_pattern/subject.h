#include <vector>
#include "interface.h"

class Observer;

class ISubject {
public:
     virtual void attach(Observer *observer) = 0;
     virtual void notifyAll() = 0;
};

class Subject : public  ISubject
{
public:
    Subject(size_t state) : state(state) {}

    size_t getState()
    {
        return this->state;
    }

    void setState(size_t state)
    {
        if (this->state != state) {
            this->state = state;
            notifyAll();
        }
    }

    void attach(Observer *observer) override
    {
        vector.push_back(observer);
    }

    void notifyAll() override
    {
        for (auto &itor : vector) {
            itor->update();
        }
    }

private:
    std::vector<Observer*> vector;
    size_t state;
};


void observer_test() {
    Subject *subject = new Subject(10);
    //Observer *binaryObserver = new BinaryObserver();
    //Observer *octalObserver = new OctalObserver();
    //Observer *hexaObserver = new HexaObserver();
    subject->attach(new BinaryObserver());
    subject->attach(new OctalObserver());
    subject->attach(new HexaObserver());
    //cout << subject->getState() << endl;
    subject->setState(20);
    //cout << subject->getState() << endl;
}




