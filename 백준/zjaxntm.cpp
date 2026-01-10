#include<bits/stdc++.h>

using namespace std;

int P_HP, P_ATK, P_HEAL, M_HP, M_ATK, turnCnt;
string cmd;

class Character {
    protected:
        int hp;
        int atk;
    public:
        Character(int hp, int atk) : hp(hp), atk(atk) {}
        bool isDead() const {return hp <=0; }
        int getAttack () const {return atk; }
        void takeDamage(int dmg) { hp -= dmg; }
        int getHP() const {return hp; }

};

class Player : public Character
{
    int healAmount;
    public:
        Player(int hp, int atk, int heal) : Character(hp, atk), healAmount(heal) {}
        void act(const string& cmd, Character& target) 
        {
            if(cmd == "attack") 
            {
                target.takeDamage(atk);
            } 
            else if (cmd == "heal") 
            {
                hp += healAmount;
            }
        }
};

class Monster : public Character 
{
    public:
        Monster(int hp, int atk) : Character(hp, atk) {}
        void attack(Character& target)
        {
            target.takeDamage(atk);
        }
};

int main()
{

    cin >> P_HP >> P_ATK >> P_HEAL;
    cin >> M_HP >> M_ATK;

    Player player(P_HP, P_ATK, P_HEAL);
    Monster monster(M_HP, M_ATK);

    while(scanf("%s", &cmd) != EOF)
    {
        if(P_HP<=0);
    }

}