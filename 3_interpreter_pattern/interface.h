#include <string>
#include <iostream>
using namespace std;

class Expression
{
public:
    Expression(){}
    virtual ~Expression(){}
    virtual bool interpret(string context) = 0;
};

class TerminalExpression: public Expression
{
public:
    TerminalExpression(string data) : data(data)
    {
        cout << "init TerminalExpression" << endl;
    }
    bool interpret(string context)
    {
        if(context.find(data) != string::npos)
        {
            return true;
        }
        return false;
    }

private:
    string data;
};

class OrExpression: public Expression
{
public:
    OrExpression(Expression *exp1, Expression *exp2) : exp1(exp1), exp2(exp2)
    {
        cout << "init OrExpression" << endl;
    }
    bool interpret(string context)
    {
        return exp1->interpret(context) || exp2->interpret(context);
    }

private:
    Expression *exp1 = nullptr;
    Expression *exp2 = nullptr;
};

class AndExpression: public Expression
{
public:
    AndExpression(Expression *exp1, Expression *exp2) : exp1(exp1), exp2(exp2)
    {
        cout << "init AndExpression" << endl;
    }
    bool interpret(string context)
    {
        return exp1->interpret(context) && exp2->interpret(context);
    }

private:
    Expression *exp1 = nullptr;
    Expression *exp2 = nullptr;
};


void interpreter_test() {

    Expression *robert = new TerminalExpression("Robert");
    Expression *john = new TerminalExpression("John");
    Expression *isMale = new OrExpression(robert, john);
    Expression *julie = new TerminalExpression("Julie");
    Expression *married = new TerminalExpression("Married");
    Expression *isMarriedWoman = new AndExpression(julie, married);
    string ret1 = isMale->interpret("John") ? "true" : "false";
    string ret2 = isMarriedWoman->interpret("Married Julie") ? "true" : "false";


    cout << endl;
    cout << "John is male? " + ret1 << endl;
    cout << "Julie is a married women? " + ret2 << endl;
}
