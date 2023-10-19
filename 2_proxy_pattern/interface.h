#include <string>
#include <iostream>
using namespace std;


class Subject {
 public:
  virtual void Request() const = 0;
};

class RealSubject : public Subject {
 public:
  void Request() const override {
    std::cout << "RealSubject: Handling request.\n";
  }
};

class Proxy : public Subject {

  /**
   * The Proxy maintains a reference to an object of the RealSubject class. It
   * can be either lazy-loaded or passed to the Proxy by the client.
   */
  public:
  Proxy(RealSubject *real_subject) : real_subject_(real_subject) {}

  ~Proxy() {
     delete real_subject_;
  }

  /**
   * The most common applications of the Proxy pattern are lazy loading,
   * caching, controlling the access, logging, etc. A Proxy can perform one of
   * these things and then, depending on the result, pass the execution to the
   * same method in a linked RealSubject object.
   */

  void Request() const override {
    if (this->CheckAccess()) {//控制访问
        this->real_subject_->Request();
        this->LogAccess();
    }
  }

 private:
  RealSubject *real_subject_;

  bool CheckAccess() const {
    // Some real checks should go here.
    std::cout << "Proxy: Checking access right before\n";
    return true;
  }
  void LogAccess() const {
    std::cout << "Proxy: Logging the time of request.\n";
  }
};


void proxy_test() {

    RealSubject *pRealSubject = new RealSubject();
    pRealSubject->Request();
    std::cout<<std::endl;
    Proxy *proxy = new Proxy(new RealSubject(*pRealSubject));//依赖注入
    proxy->Request();
    delete pRealSubject;
    delete proxy;


   //C++11 使用智能指针不需要手动 delete,如下所示
   //std::shared_ptr<RealSubject> pRealSubject (new RealSubject());
   //pRealSubject->Request();
   //std::cout<<std::endl;
   //std::shared_ptr<Proxy>  proxy = std::make_shared<Proxy>(pRealSubject.get());
   //proxy->Request();

}
