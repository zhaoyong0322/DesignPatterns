//#include "context.h"
#include <string>
#include <iostream>
#include <map>
#include <list>
#include <array>

using namespace std;

class DownLoadManager;

class State
{
protected:
    State(){}
    virtual ~State(){}
public:
    virtual void down(string user,string item) = 0;

};

class NormalDownLoad : public State {
public:
    void down(string user, string item) override {
        cout<< user << ",Welcome download:" << item <<endl;
    }
};

class RepeateDownLoad : public State {
public:
    void down(string user, string item) override {
        cout<<user<< ",Please do not repeat download : " << item <<endl;
    }
};

class SpiteDownLoad : public State {
public:
    void down(string user, string item) override {
        (void)item;
        cout<< user << ",You download behavior is sipte, download will be cancelled." <<  endl;
    }
};

class BlackDownLoad : public State {
public:
    void down(string user, string item) override {
        (void)item;
        cout<< user << ",You download too frequency, will be added to black name list." << endl;
    }
};

class DownCntRange {
public:
    DownCntRange(int min,int max, State *pState)
        : m_min(min),m_max(max),m_pState(pState)
    {

    }
    State* getState() {
        return m_pState;
    }
    bool inRange(int cnt) {
        return (cnt >= m_min && cnt <= m_max) ? true : false ;
    }
private:
    int m_min;
    int m_max;
    State  *m_pState;
};

class DownLoadManager {
public:
    DownLoadManager() {
        m_stateList.push_back(new DownCntRange(1,3,new NormalDownLoad()));//正常下载
        m_stateList.push_back(new DownCntRange(4,6,new RepeateDownLoad()));//重复下载
        m_stateList.push_back(new DownCntRange(7,10,new SpiteDownLoad()));//恶意下载
        m_stateList.push_back(new DownCntRange(10,100,new BlackDownLoad()));//列入黑名单
    }

    void downlod(string user,string item) {

        m_mapDownCnt[user]++;

        int oldCnt = m_mapDownCnt[user];

        for(auto range : m_stateList) {
            if(range->inRange(oldCnt)) {
                m_pSate = range->getState();
                m_pSate->down(user,item);
            }
        }

        //if (oldCnt == 1) {
        //    m_pSate  = new NormalDownLoad();
        //} else if (oldCnt == 2) {
        //    m_pSate  = new RepeateDownLoad();
        //} else if (oldCnt == 3) {
        //    m_pSate  = new SpiteDownLoad();
        //} else if (oldCnt == 4) {
        //    m_pSate  = new BlackDownLoad();
        //}
        //m_pSate->down(user,item);
    }

private:
    State * m_pSate = nullptr;
    map<string,string> m_mapDown;
    map<string,int> m_mapDownCnt;

    list<DownCntRange*> m_stateList;

};




void state_test() {

    DownLoadManager * p = new DownLoadManager;
    for (int i = 0; i < 20; i++) {
        p->downlod("Zhao Yong","C++ Design Pattern");
    }
}
