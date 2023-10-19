#include "memento.h"

class Originator
{
public:
    void setState(string state)
    {
        this->state = state;
    }
    string getState()
    {
        return this->state;
    }
    Memento *saveStateToMemento()
    {
        return new Memento(this->state);
    }
    void getStateFromMemento(Memento *memento)
    {
        this->state = memento->getState();
    }

private:
    string state;
};
