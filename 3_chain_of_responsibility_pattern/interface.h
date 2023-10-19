#include <string>
#include <iostream>
#include <sstream>
#include <assert.h>
using namespace std;

template <class T>
string ConvertToStr (T value) {
    stringstream ss;
    ss << value;
    return ss.str();
}


class Handle {
public:
    void setSuccessor(Handle *pHandle) {
        m_pHandle = pHandle;
    }
    virtual string handFeeReq(int fee) = 0 ;
protected:
    Handle *m_pHandle;
};


class DirectManager : public Handle {
public:
    string handFeeReq(int fee) override {
        string tmp = "";
        if (fee < 500) {
            tmp = "Direct Manager approved:" + ConvertToStr(fee) ;
            return tmp;
        } else {
            if (m_pHandle) {
                return m_pHandle->handFeeReq(fee);
            }
        }
        return tmp;
    }
};

class N1Manager : public Handle {

 public:
    string handFeeReq(int fee) override {
        string tmp = "";
        if (fee >= 500 && fee < 1000) {
            tmp = "N+1  approved:" + ConvertToStr(fee) ;
            return tmp;
        } else {
            if (m_pHandle) {
                return m_pHandle->handFeeReq(fee);
            }
        }
        return tmp;
    }
};

class VPManager : public Handle {
public:
    string handFeeReq(int fee) override {
        string tmp = "";
        if (fee >=1000) {
            tmp = "N+2 approved:" + ConvertToStr(fee) ;
            return tmp;
        } else {
            if (m_pHandle) {
                return m_pHandle->handFeeReq(fee);
            }
        }
        return tmp;
    }
};

int chain_of_responsibility_test() {

    Handle * pH1 = new DirectManager();
    Handle * pH2 = new N1Manager();
    Handle * pH3 = new VPManager();
    pH1->setSuccessor(pH2);
    pH2->setSuccessor(pH3);

    cout << pH1->handFeeReq(128) << std::endl;
    cout << pH1->handFeeReq(512) << std::endl;
    cout << pH1->handFeeReq(1014)<< std::endl;


    system("pause");
    return 0;
}

