#include "chatroom.h"

class User
{
public:
    User(string name) : name(name)
    {
        cout << "init user " + name << endl;
    }
    string getName()
    {
        return this->name;
    }
    void setName(string name)
    {
        this->name = name;
    }
    void showMessage(string message)
    {
        ChatRoom chatRoom;
        chatRoom.showMessage(this->name, message);
    }

private:
    string name;
};


void mediator_test() {

    User *user1 = new User("WuKong");
    User *user2 = new User("BaJie");
    User *user3 = new User("ShaSeng");
    cout << endl;
    user1->showMessage("Hello");
    user2->showMessage("Word");
    user3->showMessage("!");
}
