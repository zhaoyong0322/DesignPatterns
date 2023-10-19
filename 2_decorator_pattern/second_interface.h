#include "first_interface.h"

class ShapeDecorator
{
public:
    ShapeDecorator(Shape *shape)
    {
        this->shape = shape;
    }
    virtual ~ShapeDecorator(){}
    virtual void draw()
    {
        shape->draw();
    }

protected:
    Shape *shape;
};

class RedShapeDecorator: public ShapeDecorator
{
public:
    RedShapeDecorator(Shape *shape) : ShapeDecorator(shape){}

    void setRedBorder()
    {
        cout << "Border color: Red" << endl;
    }
    void draw()
    {
        shape->draw();
        setRedBorder();//功能增强代码
    }
};

void decorator_test() {

   Shape *circle = new Circle();
   ShapeDecorator *redCircle = new RedShapeDecorator(new Circle());
   ShapeDecorator *redRectangle = new RedShapeDecorator(new Rectangle());
   circle->draw();
   cout << endl;
   redCircle->draw();
   cout << endl;
   redRectangle->draw();

}
