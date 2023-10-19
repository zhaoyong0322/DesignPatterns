#include <iostream>
using namespace std;

class Observer
{
public:
    Observer(){}
    virtual ~Observer(){}
    virtual void update() = 0;
};

class BinaryObserver: public Observer
{
public:
    void update()
    {
        cout << "BinaryObserver update" << endl;
    }
};

class OctalObserver: public Observer
{
public:
    void update()
    {
        cout << "OctalObserver update" << endl;
    }
};

class HexaObserver: public Observer
{
public:
    void update()
    {
        cout << "HexaObserver update" << endl;
    }
};
