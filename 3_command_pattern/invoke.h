#include <list>
#include <stack>
#include <unordered_map>
#include "command.h"

enum class CmdType {
    LED_On,
    LED_Off,
    Sound_up,
    Sound_down,
};

class Invoker
{
public:
    void addCmd(ICommand *cmd)
    {
        m_list.push_back(cmd);
    }
    void execute()
    {
        for (auto it: m_list) {
            it->execute();
        }
    }
    //void undo()
    //{
    //
    //}

private:
    std::list<ICommand *> m_list;
    //std::unordered_map<CmdType,ICommand *>m_CmdMap;
};

void command_test() {
    Led *pLed = new Led;
    Sound *pSound = new Sound;

    LEdOnCmd *pLedOnCmd = new LEdOnCmd(pLed);
    LEdOffCmd *pLedOffCmd = new LEdOffCmd(pLed);
    SoundUpCmd *pSoundUpCmd = new SoundUpCmd(pSound);
    SoundDownCmd * pSoundDownCmd = new SoundDownCmd(pSound);


    Invoker *pInvoker = new Invoker;
    pInvoker->addCmd(pLedOnCmd);
    pInvoker->addCmd(pLedOffCmd);
    pInvoker->addCmd(pSoundUpCmd);
    pInvoker->addCmd(pSoundDownCmd);

    pInvoker->execute();
}
