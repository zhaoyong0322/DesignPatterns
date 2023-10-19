#include <string>
#include <ctime>
#include <iostream>
using namespace std;

class ChatRoom
{
public:
    void showMessage(string name, string message)
    {
        time_t setTime;
        time(&setTime);
        tm* ptm = localtime(&setTime);
        std::string time = std::to_string(ptm->tm_year + 1900)
                         + "/"
                         + std::to_string(ptm->tm_mon + 1)
                         + "/"
                         + std::to_string(ptm->tm_mday)
                         + " "
                         + std::to_string(ptm->tm_hour) + ":"
                         + std::to_string(ptm->tm_min) + ":"
                         + std::to_string(ptm->tm_sec);
        cout << time + " [ " + name + " ] : " + message << endl;
    }
};
