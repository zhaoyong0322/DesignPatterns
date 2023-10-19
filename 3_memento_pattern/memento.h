#pragma once
#include <string>
#include <iostream>
using namespace std;

class Memento
{
public:
    Memento(string state) : state(state)
    {
        cout << "init Memento " + state << endl;
    }
    string getState()
    {
        return this->state;
    }

private:
    string state;
};
