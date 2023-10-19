#include <string>
#include <vector>
#include <iostream>
using namespace std;

class Iterator
{
public:
    Iterator() {}
    virtual ~Iterator() { }
    virtual bool hasNext() = 0;
    virtual string next() = 0;
};

class NameIterator: public Iterator
{
public:
    NameIterator(size_t index, std::vector<string> vector) : index(index), vector(vector){}
    bool hasNext()
    {
        if(index < vector.size() - 1)
        {
            return true;
        }
        return false;
    }
    string next()
    {
        if(this->hasNext())
        {
            return vector.at(index++);
        }
        return nullptr;
    }

private:
    size_t index;
    std::vector<string> vector;
};

class Container
{
public:
    Container(){}
    virtual ~Container(){}
    virtual Iterator* getIterator() = 0;
};

class NameRepository: public Container
{
public:
    NameRepository(size_t index, std::vector<string> vector)
    : index(index), vector(vector)
    {

    }


    Iterator* getIterator()
    {
        return new NameIterator(index, vector);
    }

private:
    size_t index;
    std::vector<string> vector;
};


void interator_test() {

    std::vector<string> vector { "Billy","Alice","Kitty","Ben","Jason","Jack","Miss"  };

    NameRepository *nameRepository = new NameRepository(0, vector);

    for (Iterator *iterator = nameRepository->getIterator(); iterator->hasNext();)
    {
        cout << iterator->next() << endl;
    }

}
