#include <string>
#include <iostream>
#include <assert.h>
using namespace std;

class AbstractLogger
{
public:
    static const int INFO = 1;
    static const int DEBUG = 2;
    static const int ERROR = 3;
    AbstractLogger()
    {
        nextLogger = nullptr;
    }
    virtual ~AbstractLogger(){}
    void setNextLogger(AbstractLogger *next)
    {
        nextLogger = next;
    }
    void logMessage(int level, string message)
    {
        if (this->level <= level) {
            write(message);
        } else {
            assert(nextLogger != nullptr);
            nextLogger->write(message);
        }
    }
    virtual void write(string message) = 0;

protected:
    int level;
    AbstractLogger *nextLogger;
};

class ConsoleLogger: public AbstractLogger
{
public:
    ConsoleLogger(int level)
    {
        this->level = level;
        cout << "init ConsoleLogger" << endl;
    }
    void write(string message)
    {
        cout << "Standard Console::Logger: " + message << endl;
    }

};

class ErrorLogger: public AbstractLogger
{
public:
    ErrorLogger(int level)
    {
        this->level = level;
        cout << "init ErrorLogger" << endl;
    }
    void write(string message)
    {
        cout << "Error Console::Logger: " + message << endl;
    }
};

class FileLogger: public AbstractLogger
{
public:
    FileLogger(int level)
    {
        this->level = level;
        cout << "init FileLogger" << endl;
    }
    void write(string message)
    {
        cout << "File::Logger: " + message << endl;
    }
};

void chain_of_responsibility_test() {

    AbstractLogger *errorLogger = new ErrorLogger(AbstractLogger::ERROR);
    AbstractLogger *fileLogger = new FileLogger(AbstractLogger::DEBUG);
    AbstractLogger *consoleLogger = new ConsoleLogger(AbstractLogger::INFO);
    cout << endl;

    errorLogger->setNextLogger(fileLogger);
    fileLogger->setNextLogger(consoleLogger);

    errorLogger->logMessage(AbstractLogger::INFO,  "INFO level");
    errorLogger->logMessage(AbstractLogger::DEBUG, "DEBUG level");
    errorLogger->logMessage(AbstractLogger::ERROR, "ERROR level");
    cout << endl;

    fileLogger->logMessage(AbstractLogger::INFO,  "INFO level");
    fileLogger->logMessage(AbstractLogger::DEBUG, "DEBUG level");
    fileLogger->logMessage(AbstractLogger::ERROR, "ERROR level");
    cout << endl;
}
