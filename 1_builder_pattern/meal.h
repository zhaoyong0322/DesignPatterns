#include "foodinterface.h"
#include <vector>

class Meal
{
public:
    Meal()
    {
        vec.reserve(255);
    }
    void addFoodToVector(Food * food)
    {
        vec.push_back(food);
    }
    float getCost()
    {
        float ret = 0.0;
        for(auto &food: vec)
        {
            ret += food->getPrice();
        }
        return ret;
    }
    void showFoods()
    {
        for(auto &food: vec)
        {
            cout << "--------------------------" << endl;
            cout << food->getName() << endl;
            cout << food->getPack()->pack() << endl;
            cout << food->getPrice() << endl;
        }
    }

public:
    std::vector<Food *> vec;
};
