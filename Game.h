#ifndef GAME_H
#define GAME_H
class Game
{
private:
    static constexpr char fileName[] = "plants.txt";
    void GameSetUp();
    bool success_;
public:
    Game();
    ~Game();
    bool Success() const {return success_;}
};
#endif