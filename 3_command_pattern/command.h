#include "device.h"

class ICommand
{
public:
    ICommand() {}
    virtual ~ICommand(){}
    virtual void execute() = 0;
};

class LEdOnCmd: public ICommand
{
public:
    LEdOnCmd(Led *pLed) : m_pLed(pLed){}
    void execute()
    {
        m_pLed->on();
    }
private:
    Led *m_pLed;
};

class LEdOffCmd: public ICommand
{
public:
    LEdOffCmd(Led *pLed) : m_pLed(pLed){}
    void execute()
    {
        m_pLed->off();
    }
private:
    Led *m_pLed;
};

class SoundUpCmd: public ICommand
{
public:
    SoundUpCmd(Sound *pSound) : m_pSound(pSound){}
    void execute()
    {
        m_pSound->on();
    }
private:
    Sound *m_pSound;
};

class SoundDownCmd: public ICommand
{
public:
    SoundDownCmd(Sound *pSound) : m_pSound(pSound){}
    void execute()
    {
        m_pSound->off();
    }
private:
    Sound *m_pSound;
};


