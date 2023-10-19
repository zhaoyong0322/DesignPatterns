//#include "context.h"
#include <string>
#include <iostream>
#include <map>
using namespace std;

class DownLoadManager;

class State
{
protected:
    State(){}
    virtual ~State(){}
public:
    virtual void down(string user,string item,DownLoadManager *p) = 0;

};

class NormalDownLoad : public State {
public:
    void down(string user, string item, DownLoadManager *p) override {
        cout<< "welcome " << user << "download: " << item <<endl;
    }
};

class RepeateDownLoad : public State {
public:
    void down(string user, string item, DownLoadManager *p) override {
        cout<< "Please do not repeat download : " << item <<endl;
    }
};

class SpiteDownLoad : public State {
public:
    void down(string user, string item, DownLoadManager *p) override {
        cout<< "Please do not repeat download : " << item << endl;
    }
};

class BlackDownLoad : public State {
public:
    void down(string user, string item, DownLoadManager *p) override {
        cout<< user << ", You download too frequency, will be added to black name list." << endl;
    }
};

class DownLoadManager {
public:

    void downlod(string user,string item) {
        int oldCnt = 0;
        if (m_mapDownCnt.count(user) > 0) {
            oldCnt = m_mapDownCnt[user];
        } else {
            m_mapDownCnt[user] = 0;
        }
        oldCnt++;
        m_mapDownCnt[user] = oldCnt;

        if (oldCnt == 1) {
            m_pSate  = new NormalDownLoad();
        } else if (oldCnt == 2) {
            m_pSate  = new RepeateDownLoad();
        } else if (oldCnt == 3) {
            m_pSate  = new SpiteDownLoad();
        } else if (oldCnt == 4) {
            m_pSate  = new BlackDownLoad();
        }
        m_pSate->down(user,item,this);
    }

private:
    State * m_pSate = nullptr;
    map<string,string> m_mapDown;
    map<string,int> m_mapDownCnt;

};

void state_test() {

    DownLoadManager * p = new DownLoadManager;
    for (int i = 0; i < 4; i++) {
        p->downlod("zhao","C++ Design Pattern");
    }
}
