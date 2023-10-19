//#创建型模式(5)
//#include "1_singleton_pattern/singletonpattern.h"
//#include "1_simple_factory_pattern/shapefactory.h"
//#include "1_factory_method_pattern/factory_method.h"
//#include "1_abstract_factory_pattern/factoryproducer.h"
//#include "1_builder_pattern/meakbuilder.h"
//#include "1_prototype_pattern/interface.h"

//#结构型模式(7)
//#include "2_proxy_pattern/interface.h"
//#include "2_decorator_pattern/second_interface.h"
//#include "2_adapter_pattern/class_adaptor.h"
//#include "2_adapter_pattern/object_adaptor.h"
//#include "2_facade_pattern/facade_interface.h"
//#include "2_flyweight_pattern/shapefactory.h"
//#include "2_bridge_pattern/second_interface.h"
//#include "2_composite_pattern/file.h"

//#行为型模式(11)
//#include "3_observer_pattern/subject.h"
//#include "3_template_pattern/interface.h"
//#include "3_strategy_pattern/context.h"
//#include "3_visitor_pattern/interface.h"
//#include "3_mediator_pattern/usr.h"
//#include "3_state_pattern/interface.h"
//#include "3_command_pattern/invoke.h"
//#include "3_iterator_pattern/interface.h"
//#include "3_interpreter_pattern/interface.h"
//#include "3_chain_of_responsibility_pattern/interface.h"
//#include "3_memento_pattern/interface.h"

int main()
{
    ///1-单例模式--Go
    //sington_test();

    ///1-简单工厂模式--Go
    //simple_factory_test();

    ///1-工厂方法模式--Go
    //factory_method_test();

    ///1-抽象工厂模式
    //abstract_factory_test();

    //1-建造者模式
    //builder_test();

    //1-原型模式
    //prototype_test();

    ///////////////////////////////////////////////////////////////////////////
    //2-代理模式
    //proxy_test();//--Go

    //2-装饰模式： 符合组合优于继承设计原则
    //decorator_test();//--Go

    //适配器模式

    //2-类-适配器 --Go
    //class_adaptor_test();

    //2-对象-适配器--Go
    //object_adaptor_test();

    //2-享元模式
    //flyweight_test();

    //2-外观模式
    //facade_test();

    //2-桥接模式
    //bridge_test();

    //2-组合模式
    //composite_test();

    ///////////////////////////////////////////////////////////////////////////
    //3-观察者模式--Go
    //observer_test();

    //3-模板模式--Go
    //template_test();

    //3-策略模式--Go
    //strategy_test();

    //3-状态模式 --Go
    //state_test();

    //3-访问者模式
    //visitor_test();

    //3-中介者模式
    //mediator_test();

    //3-命令模式 --Go
    //command_test();

    //3-责任链模式
    //chain_of_responsibility_test();

    //3-迭代器模式
    //interpreter_test();

    //3-解析器模式
    //interpreter_test();

    //3-备忘录模式
    //memento_test();

    return 0;
}













