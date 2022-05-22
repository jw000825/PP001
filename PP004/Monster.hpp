class Monster
{
public:
    int x;
    int y;

    Monster()
    {
        x = 50;
        y = 7;
    }
    ~Monster()
    {

    }

    void MoveMonster()
    {
        x--;
    }
    void MoveFastMonster()
    {
        x -= 2;
    }
    void ResetMonster()
    {
        x = 50;
    }
};