#include <string>
#include <iostream>
using namespace std;

class Led
{
public:
    Led() {}

    void on()
    {
        cout << "Light is On" << endl;
    }

    void off()
    {
        cout << "Light is Off" << endl;
    }
};

class Sound
{
public:
    Sound() {}

    void on()
    {
        cout << "Sound turn up " << endl;
    }

    void off()
    {
        cout << "Sound turn down ^^" << endl;
    }
};
