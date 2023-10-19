#include <iostream>
using namespace std;

class DrawApi
{
public:
    DrawApi(){}
    virtual ~DrawApi(){}

    virtual void drawCircle(int radius, int x, int y)
    {
            cout << "drawing CIRCLE [  radius: " << radius << ", x: " << x << ", y: " << y << " ]" << endl;
    };

    virtual void drawRect(int width, int height) {
        cout << "drawing RECT [  width: " << width << ", height: " << height << endl;
    } ;

    virtual void drawLine(int width) {
        cout << "drawing Line [  width: " << width << endl;
    } ;
};

class RedCircle: public DrawApi
{
public:
    void drawCircle(int radius, int x, int y)
    {
        cout << "drawing circle [ color: red, radius: " << radius << ", x: " << x << ", y: " << y << " ]" << endl;
    }
};

class GreenCircle: public DrawApi
{
public:
    void drawCircle(int radius, int x, int y)
    {
        cout << "drawing circle [ color: green, radius: " << radius << ", x: " << x << ", y: " << y << " ]" << endl;
    }
};

class YellowRect: public DrawApi
{
public:
    void drawRect(int width, int height) {
        cout << "drawing rect [ color: yellow, width: " << width << ", height: " << height << endl;
    } ;
};


class Shape
{
public:
    virtual ~Shape(){}
    DrawApi *getDrawApi()
    {
        return this->drawApi;
    }
    virtual void draw() = 0;

protected:
    DrawApi *drawApi;
    Shape(DrawApi *drawApi): drawApi(drawApi) { }
};

class Circle: public Shape
{
public:
    Circle(int radius, int x, int y, DrawApi *drawApi): Shape(drawApi)
    {
        this->x = x;
        this->y = y;
        this->radius = radius;
    }
    void draw()
    {
        getDrawApi()->drawCircle(radius, x, y);
    }

private:
    int x;
    int y;
    int radius;
};

class Rect: public Shape
{
public:
    Rect(int x, int y,int h, int w, DrawApi *drawApi): Shape(drawApi)
    {
        this->x = x;
        this->y = y;
        this->height = h;
        this->width  = w;

    }
    void draw()
    {
        getDrawApi()->drawRect(height,width);
    }

private:
    int x;
    int y;
    int width;
    int height;
};


void bridge_test() {

    DrawApi *redDrawApi    = new RedCircle();
    DrawApi *greenDrawApi  = new GreenCircle();
    DrawApi *yellowDrawApi = new YellowRect();

    Shape *redCircle   = new Circle(100, 10, 10, redDrawApi);
    Shape *greenCircle = new Circle(100, 10, 10, greenDrawApi);
    Shape *yellowRect  = new Rect(0,0, 10, 10,   yellowDrawApi);

    redCircle->draw();
    greenCircle->draw();
    yellowRect->draw();

}
