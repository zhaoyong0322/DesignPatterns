#include "father.h"
#include <vector>
#include <string>

class XiaoMi;
class HuaWei;
class Oppo;

class MobilePhoneVisitor {
public:
   virtual void visit(XiaoMi *pXiaoMi) =0;
   virtual void visit(HuaWei *pHuaWei) =0;
   virtual void visit(Oppo *pOppo) = 0;

protected:
    MobilePhoneVisitor() {}
};

class IMobilePhone
{
public:
    virtual void dial() = 0;
    virtual void sendMsg() = 0;
    virtual void hang() = 0;
    virtual void recvMsg() = 0;
    virtual void accept(MobilePhoneVisitor *p) = 0;
};

class XiaoMi : public IMobilePhone
{
public:
    XiaoMi() {}

    void accept(MobilePhoneVisitor *p) {
        p->visit(this);
    }

    void dial() {
        std::cout<< "XiaoMi" <<" "<< "dialing" << std::endl;
    }
     void sendMsg() {
        std::cout<< "XiaoMi" <<" "<< "sendMsg" << std::endl;
     }
     void hang() {
        std::cout<< "XiaoMi" <<" "<< "hang" << std::endl;
     }
     void recvMsg() {
        std::cout<< "XiaoMi" <<" "<< "recvMsg" << std::endl;
     }
};

class HuaWei : public IMobilePhone
{
 public:
     HuaWei() { }
     void dial() {
        std::cout<< "HuaWei" <<" "<< "dialing" << std::endl;
     }
     void sendMsg(){
        std::cout<< "HuaWei" <<" "<< "sendMsg" << std::endl;
     }
     void hang() {
        std::cout<< "HuaWei" <<" "<< "hang" << std::endl;
     }
     void recvMsg() {
        std::cout<< "HuaWei" <<" "<< "recvMsg" << std::endl;
     }
     void accept(MobilePhoneVisitor *p) {
        p->visit(this);
     }
};

class Oppo : public IMobilePhone
{
 public:
     Oppo() { }
     void dial() {
        std::cout<< "Oppo" <<" "<< "dialing" << std::endl;
     }
     void sendMsg(){
        std::cout<< "Oppo" <<" "<< "sendMsg" << std::endl;
     }
     void hang() {
        std::cout<< "Oppo" <<" "<< "hang" << std::endl;
     }
     void recvMsg() {
        std::cout<< "Oppo" <<" "<< "recvMsg" << std::endl;
     }
     void accept(MobilePhoneVisitor *p) {
        p->visit(this);
     }
};

class Win7Config : public MobilePhoneVisitor {
 public:
     Win7Config() {};

     void visit(XiaoMi * p) override {
        p->dial();
        p->sendMsg();
        p->recvMsg();
        p->hang();
     }

     void visit(HuaWei * p) override {
        p->dial();
        p->sendMsg();
        p->recvMsg();
        p->hang();
     }

     void visit(Oppo * p) override {
        p->dial();
        p->sendMsg();
        p->recvMsg();
        p->hang();
     }
 };


void visitor_test() {
     Win7Config * pWin7Config = new Win7Config;//访问者
     XiaoMi *pXiaoMi = new XiaoMi;
     pXiaoMi->accept(pWin7Config);//双重分发(两个多态-accept-visit)
}
