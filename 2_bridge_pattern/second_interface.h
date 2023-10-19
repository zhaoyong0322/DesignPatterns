#include <iostream>
using namespace std;

class IOS {
public:
    IOS(){};
    virtual ~IOS() {};
    virtual void run() = 0;
};

class Window : public IOS {
public:
    void run() override {
        cout<< "Windows is running:"<<endl;
    }
};

class Linux : public IOS {
public:
    void run() override {
        cout<< "Linux is running:"<<endl;
    }
};

class HarmonyOS : public IOS {
public:
    void run() override {
        cout<< "Harmony is running:"<<endl;
    }
};

//////////////////////////////////////////////////////

class IComputer {
public:
    IComputer() {};
    virtual ~IComputer() {};
    virtual void install(IOS *pOS) = 0;
};

class Lenovel : public IComputer {
public:
    void install(IOS *pOS) override {
        cout<< "Lenovel have installed : ";
        pOS->run();
    }
};

class XiaoMi : public IComputer {
public:
    void install(IOS *pOS) override {
        cout<< "XiaoMi have installed : ";
        pOS->run();
    }
};

class HuaWei : public IComputer {
public:
    void install(IOS *pOS) override {
        cout<< "Huawei have installed : ";
        pOS->run();
    }
};



void bridge_test() {
    Window *pWin = new Window;
    Linux *pLinux = new Linux;
    HarmonyOS *pHarmony = new HarmonyOS;

    Lenovel *pLenovel = new Lenovel;
    pLenovel->install(pWin);
    pLenovel->install(pLinux);
    pLenovel->install(pHarmony);

    XiaoMi *pXiaoMi = new XiaoMi;
    pXiaoMi->install(pWin);
    pXiaoMi->install(pLinux);
    pXiaoMi->install(pHarmony);

    HuaWei *pHuaWei = new HuaWei;
    pHuaWei->install(pWin);
    pHuaWei->install(pLinux);
    pHuaWei->install(pHarmony);

}
