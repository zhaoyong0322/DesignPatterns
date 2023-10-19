#include <string>
#include <iostream>
using namespace std;


class Target {
 public:
  virtual ~Target() = default;
  virtual std::string Request() const {
    return "Target: The default target's behavior.";
  }
};


class Adaptee {
 public:
  std::string specificRequest() const {
    return ".eetpadA eht fo roivaheb laicepS";
  }
};

/**
 * The Adapter makes the Adaptee's interface compatible with the Target's
 * interface using multiple inheritance.
 */
class Adapter : public Target {
 public:
  Adapter(Adaptee *pAdaptee): m_pAdaptee(pAdaptee) {}

  std::string Request() const override {

    std::string to_reverse = m_pAdaptee->specificRequest();

    std::reverse(to_reverse.begin(), to_reverse.end());
    return "Adapter: (TRANSLATED) " + to_reverse;
  }

 private:
  Adaptee *m_pAdaptee;
};

void object_adaptor_test() {
    //类适配器
    {
        std::cout << "Client: Object Adaptor :\n";
        Target *target = new Target;
        std::cout << target->Request();
        std::cout << "\n\n";
        Adaptee *adaptee = new Adaptee;
        std::cout << "Client: The Adaptee class has a weird interface. See, I don't understand it:\n";
        std::cout << "Adaptee: " << adaptee->specificRequest();
        std::cout << "\n\n";
        std::cout << "Client: But I can work with it via the Adapter:\n";
        Adapter *adapter = new Adapter(adaptee);
        std::cout << adapter->Request();
        std::cout << "\n";

        delete target;
        delete adaptee;
        delete adapter;
    }

}
