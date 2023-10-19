#include <string>
#include <vector>
#include <iostream>
#include <list>
using namespace std;

class IFile
{
public:    
    virtual void display() = 0;
    virtual int add(IFile *file) = 0;
    virtual int remove(IFile *file) = 0;
    virtual list<IFile*>* getChild() = 0 ;
};


class File : public IFile  {
public:
    File(string name): m_name(name) {

    };
    void display() override {
        std::cout<< m_name <<std::endl;
    }
    int add(IFile  *file) override {
        //file can not add a file
        (void) file;
        return -1;
    };
    int remove(IFile *file) override {
        //m_list.remove(file);
        (void)file;
        return -1;
    }
    list<IFile *> * getChild() override {
        return nullptr;
    }

private:
    string m_name;
};

class Dir : public IFile  {
public:
    Dir(string name): m_name(name) {
        m_list = new list<IFile*>;
    };
    ~Dir() {
        delete m_list;
    }

    void display() override {
        std::cout<< m_name << std::endl;
    }

    int add(IFile  *file) override {
        m_list->push_back(file);
        return 0;
    };
    int remove(IFile *file) override {
        m_list->remove(file);
        return 0;
    }
    list<IFile *> * getChild() override {
        return m_list;
    }

private:
    string m_name;
    list<IFile *> *m_list = nullptr;
};


void showTree(IFile *root, int level) {
    if (!root)
        return;
    for (int i = 0; i < level; i++) {
        std::cout<< "\t";
    }
    root->display();
    list<IFile *> *l1 = root->getChild();
    if (l1 != nullptr) {
        for (auto iter = l1->begin(); iter != l1->end(); iter++) {
            if((*iter)->getChild() == nullptr) {
                for(int j = 0; j < level; j++) {
                    std::cout<<"\t";
                }
                (*iter)->display();
            } else { //文件夹:递归调用
                showTree(*iter,level+1);
            }
        }
    }
}


void composite_test() {
    Dir *pRoot = new  Dir("C:");
    Dir *pDir1 = new  Dir("Program Files");
    Dir *pDir2 = new  Dir("AppData");

    File *pFile1 = new File("a.txt");
    File *pFile2 = new File("b.txt");
    File *pFile3 = new File("1.cpp");

    pRoot->add(pDir1);
    pRoot->add(pDir2);

    pDir1->add(pFile1);
    pDir1->add(pFile2);

    pDir2->add(pFile3);

    showTree(pRoot,0);

}
