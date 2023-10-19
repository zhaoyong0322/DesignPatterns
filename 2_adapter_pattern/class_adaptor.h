#include <string>
#include <iostream>
using namespace std;

/**
 * The Target defines the domain-specific interface used by the client code.
 */
class Target {
 public:
  virtual ~Target() = default;
  virtual std::string Request() const {
    return "Target: The default target's behavior.";
  }
};

/**
 * The Adaptee contains some useful behavior, but its interface is incompatible
 * with the existing client code. The Adaptee needs some adaptation before the
 * client code can use it.
 */
class Adaptee {
 public:
  std::string SpecificRequest() const {
    return ".eetpadA eht fo roivaheb laicepS";
  }
};

/**
 * The Adapter makes the Adaptee's interface compatible with the Target's
 * interface using multiple inheritance.
 */
class Adapter : public Target, public Adaptee {
 public:
  Adapter() {}
  std::string Request() const override {

    std::string to_reverse = SpecificRequest();
    std::reverse(to_reverse.begin(), to_reverse.end());
    return "Adapter: (TRANSLATED) " + to_reverse;

  }
};


void class_adaptor_test() {
    //类适配器
    {
        std::cout << "Client: Class Adaptor:\n";
        Target *target = new Target;
        std::cout << target->Request();
        std::cout << "\n\n";
        Adaptee *adaptee = new Adaptee;
        std::cout << "Client: The Adaptee class has a weird interface. See, I don't understand it:\n";
        std::cout << "Adaptee: " << adaptee->SpecificRequest();
        std::cout << "\n\n";
        std::cout << "Client: But I can work with it via the Adapter:\n";
        Adapter *adapter = new Adapter;
        std::cout << adapter->Request();
        std::cout << "\n";

        delete target;
        delete adaptee;
        delete adapter;
    }

}
