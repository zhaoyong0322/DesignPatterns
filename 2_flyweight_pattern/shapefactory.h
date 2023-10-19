#include "interface.h"
#include <map>

class ShapeFactory
{
public:
    std::map<string, CommonSource*> map;
    auto getCommonSource(string color) -> CommonSource*
    {
        auto iter = map.find(color);
        if (iter != map.end()) {
            return iter->second;
        } else {
            CommonSource *pCS = new CommonSource(color);
            map.insert({ color, pCS });
            cout << "Creating circle of color : " << color << endl;
            return pCS;
        }
    }
};


void flyweight_test() {

    ShapeFactory shapeFactory;
    string array[] = { "Red", "Blue", "Red", "Yellow", "Blue" };
    for (auto color : array)
    {
        int x = rand() % 100;
        int y = rand() % 100;
        int radius = rand() % 100;

        CommonSource *pCS = shapeFactory.getCommonSource(color);

        Circle *circle = new Circle(pCS);
        circle->setX(x);
        circle->setY(y);
        circle->setRadius(radius);
        circle->draw();
    }

}
