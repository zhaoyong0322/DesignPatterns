#include <iostream>
using namespace std;

class Game
{
public:
    Game(){}
    virtual ~Game() {}
    virtual void initialize() = 0;
    virtual void startPlay() = 0;
    virtual void endPlay() = 0;

    //子类不需要实现此方法
    virtual void play() final
    {
        initialize();
        startPlay();
        endPlay();
    }
};

class TableTennis : public Game
{
public:
    void initialize()
    {
        cout << "TableTennis Initialized Start playing" << endl;
    }
    void startPlay()
    {
        cout << "TableTennis Started Enjoy the game" << endl;
    }
    void endPlay()
    {
        cout << "TableTennis Finished" << endl;
    }
};

class Football : public Game
{
public:
    void initialize()
    {
        cout << "Football Game Initialized Start playing" << endl;
    }
    void startPlay()
    {
        cout << "Football Game Started Enjoy the game" << endl;
    }
    void endPlay()
    {
        cout << "Football Game Finished" << endl;
    }
};

void template_test() {
    Game *game = new TableTennis();
    game->play();
    cout << endl;
    game = new Football();
    game->play();
}
