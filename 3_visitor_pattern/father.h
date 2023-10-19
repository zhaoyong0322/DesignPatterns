#include <iostream>
using  namespace std;
class Computer;
class Mouse;
class Keyboard;
class Monitor;

class ComputerPartVisitor
{
public:
    ComputerPartVisitor(){}
    virtual ~ComputerPartVisitor(){}
    virtual void visit(Computer*computer) = 0;
    virtual void visit(Mouse *mouse) = 0;
    virtual void visit(Keyboard *keyboard) = 0;
    virtual void visit(Monitor *monitor) = 0;
};

class ComputerPart
{
public:
    ComputerPart(){}
    virtual ~ComputerPart() {}
    virtual void accept(ComputerPartVisitor *computerPartVisitor) = 0;
    virtual string getString() = 0;
};
