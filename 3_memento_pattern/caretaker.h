#include "memento.h"
#include <vector>

class Caretaker
{
public:
    void add(Memento *memento)
    {
        vector.push_back(memento);
    }
    Memento *getMemento(size_t index)
    {
        return vector.at(index);
    }
    size_t getVectorLength()
    {
        return vector.size();
    }

private:
    std::vector<Memento *> vector;
};
