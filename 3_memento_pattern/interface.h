//#include "memento.h"
#include <vector>
#include <string>
#include <iostream>
using namespace std;
//using std::string;

class OriginalWord;

class Memento {
public:
    Memento(string word) : m_strWord(word) {

    }
private:
    friend class OriginalWord;
    string getWord() {
        return m_strWord;
    }
    string m_strWord;

};


class OriginalWord {
public:
    OriginalWord(string word) : m_strWord(word) {

    }
    Memento * saveWords() {
        return new Memento(m_strWord);
    }
    void restoreWord(Memento *pMemento) {
        m_strWord = pMemento->getWord();
        std::cout<<"存档恢复成功!" << std::endl;
    }

    void showWord() {
        std::cout<<m_strWord << std::endl;
    }
private:
    string m_strWord;

};


//设置快照，获取快照
class CareTaker {
public:
    //Caretaker(){};
    void setMemento(Memento *p){
        m_pMemento = p;
    }
    Memento *getMemento() {
        return m_pMemento;
    }
private:
    Memento *m_pMemento;
};


void memento_test() {

    CareTaker *pCT = new CareTaker;
    OriginalWord *pODFirst = new OriginalWord("Hello");
    pODFirst->showWord();
    pCT->setMemento(pODFirst->saveWords());

    OriginalWord *pODSec = new OriginalWord("Word");
    pODSec->showWord();
    //pCT->setMemento(pODSec->saveWords());

    OriginalWord *pODThird = new OriginalWord("你好！");
    pODThird->showWord();
    //pCT->setMemento(pODThird->saveWords());


    pODFirst->restoreWord(pCT->getMemento());
    pODFirst->showWord();

}
