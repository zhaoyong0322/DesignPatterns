QT += core
QT -= gui

CONFIG += c++11

TARGET = DesignPatterns
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

#创建型模式(5)
include(1_singleton_pattern/1_singleton_pattern.pri)#单例模式
include(1_simple_factory_pattern/1_simple_factory_pattern.pri)#简单工厂模式
include(1_factory_method_pattern/1_factory_method_pattern.pri)#工厂方法模式
include(1_abstract_factory_pattern/1_abstract_factory_pattern.pri)#抽象工厂模式
include(1_builder_pattern/1_builder_pattern.pri)#建造者模式
include(1_prototype_pattern/1_prototype_pattern.pri)#原型模式

#结构型模式(7)
include(2_proxy_pattern/2_proxy_pattern.pri)#代理模式
include(2_decorator_pattern/2_decorator_pattern.pri)#装饰模式
include(2_adapter_pattern/2_adapter_pattern.pri)#适配器模式
include(2_bridge_pattern/2_bridge_pattern.pri)#桥接模式
include(2_facade_pattern/2_facade_pattern.pri)#外观模式
include(2_composite_pattern/2_composite_pattern.pri)#组合模式
include(2_flyweight_pattern/2_flyweight_pattern.pri)#享元模式

#行为型模式(11)
include(3_observer_pattern/3_observer_pattern.pri)#观察者模式
include(3_template_pattern/3_template_pattern.pri)#模版模式
include(3_strategy_pattern/3_strategy_pattern.pri)#策略模式
include(3_visitor_pattern/3_visitor_pattern.pri)#访问者模式
include(3_mediator_pattern/3_mediator_pattern.pri)#中介者模式
include(3_state_pattern/3_state_pattern.pri)#状态模式
include(3_chain_of_responsibility_pattern/3_chain_of_responsibility_pattern.pri)#责任链模式
include(3_command_pattern/3_command_pattern.pri)#命令模式
include(3_iterator_pattern/3_iterator_pattern.pri)#迭代器模式
include(3_interpreter_pattern/3_interpreter_pattern.pri)#解释器模式
include(3_memento_pattern/3_memento_pattern.pri)#备忘录模式














