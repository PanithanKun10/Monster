#include <iostream>
#include "NODE.h"
using namespace std;
typedef NODE* NodePtr;
class LL{
   NodePtr HeadPtr;
   string trainer;
   int atk;
   int size;
   int max_hp=100;
   int hp=max_hp;
   int potions=3;
   public:
   LL(string="Hum",int=20);
   ~LL();
   void ADD(LL*);//add node
   void Show_all();//show all nodes
   void Random(int&,int&);//random stats
   void Set_order(LL*);//set order
   bool fight(NODE*,LL*);//fight monster
   void Delete(LL*);//delete
   string show_name();
   int show_hp();//show hp
   int show_potion();//show potions
   void Delete_all();//delete all nodes
   bool Select(char);//select (yes or no)
   void attack(NODE*);//attack monster
   int  show_attack();//show ATK
   void use_potion();//use potion
   void use_potion_to_monster(NODE*);// use potion to omonster
   int Select_fight(NODE*);//select fight
   bool Check_num(string);//check var
  void Add_boss(LL*);//add boss node
   bool Check_boss(NODE*);//check if it's a boss
   bool Boss_start(LL*);//initiate boss match
   int show_Max_hp();//show max_hp
   bool capture(NODE*t);//capture monster
   int show_size();//show size
   void change_hp(int);//change hp
   void take_DMG(NODE*);//take dmg received
   void heal_all(LL*);
   void delete_dead_monster(NODE*,LL*);
   NODE* select_monster(int);//select monster (if size >0)
};
class El_monster :public NODE{
        int E; //Elemental type
        int Pyro=0; //Fire
        int Hydro=0; //Water
        int Geo=0; //Stone
        int Anemo=0; //Wind

        int Pyro_DMG; //Fire DMG
        int Hydro_DMG; //Water DMG
        int Geo_DMG; //Stone DMG
        int Anemo_DMG; //Wind DMG

public:
     El_monster(int,int,int,string="Unknown"); //Create Element of monster 
     ~El_monster();
     void element(); // set Element
     void Show_NODE();//show node
     void attack(NODE*);//monster use elemental skills
     void set_DMG();// set elemental DMG
     string show_elemental();//show elemental
     int weakness_resistance(NODE*,int);//check elemental weakness each others
};
typedef El_monster* ElPtr;
class Boss :public NODE{
        int E; //Elemental type
        int Pyro=0; //Fire
        int Hydro=0; //Water
        int Geo=0; //Stone
        int Anemo=0; //Wind

        int Pyro_DMG; //Fire DMG
        int Hydro_DMG; //Water DMG
        int Geo_DMG; //Stone DMG
        int Anemo_DMG; //Wind DMG

public:
     Boss(int,int,int,string="Boss"); //Create Element of monster 
     ~Boss();
     void element(); // set Element
     void Show_NODE();//show node
     void attack(NODE*);//monster use elemental skills
     void set_DMG();// set elemental DMG
     string show_elemental();//show elemental
     int weakness_resistance(NODE*,int);//check elemental weakness each others
};
typedef Boss* BossPtr;
