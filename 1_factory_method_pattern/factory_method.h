#include "interface.h"
#include <map>

class Shape;

class IFacory {
 public:
    IFacory(){};
    virtual ~IFacory(){};
    virtual Shape* getShapeFactory() = 0;
};

class CircleFactory: public IFacory {
public:
    CircleFactory () {

    }
    Shape * getShapeFactory() override {
        //对象的创建逻辑比较复杂
        //...省略复杂的创建过程
        return new Circle();
    }
};

class SquareFactory: public IFacory {
public:
    SquareFactory () {

    }
    Shape * getShapeFactory() override {
        //对象的创建逻辑比较复杂
        //...省略复杂的创建过程
        return new Square();
    }
};

class RectangleFactory: public IFacory {
public:
    RectangleFactory () {

    }
    Shape * getShapeFactory() override {
        //对象的创建逻辑比较复杂
        //...省略复杂的创建过程
        return new Rectangle();
    }
};

//工厂方法基于简单工厂模式，将对象的创建逻辑进一步拆分到各个工厂类中
class FactoryMethod
{
public:
    FactoryMethod() {
        m_cached_factory.insert({"Circle", new CircleFactory});
        m_cached_factory.insert({"Square", new SquareFactory});
        m_cached_factory.insert({"Rectangle", new RectangleFactory});
    }

    Shape* getShape(string type)
    {
        if (m_cached_factory.count(type)) {
            Shape *pShape = m_cached_factory[type]->getShapeFactory();
            return pShape;
        } else {
            return nullptr;
        }
    }

private:

    static map<string, IFacory*> m_cached_factory;

};

map<string, IFacory*> FactoryMethod::m_cached_factory;



void factory_method_test() {

    FactoryMethod FactoryMethod;
    Shape* pShape = FactoryMethod.getShape("Square");
    pShape->draw();
    cout <<"---------"<< endl;
    pShape = FactoryMethod.getShape("Rectangle");
    pShape->draw();
    cout <<"---------"<< endl;
    pShape = FactoryMethod.getShape("Circle");
    pShape->draw();
    cout << endl;

}
