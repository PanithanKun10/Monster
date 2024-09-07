#include <iostream>
using namespace std;
class NODE {
       int EXP; // Monster EXP
       int Max_EXP; // Monster MAX_HP
       int lvl; // monster level
       int atk; // monster Attack DMG
       int elemental_DMG;// monster elemental DMG
       int order;//order of monster
       int current_hp; // monster current HP
       int Max_hp;
       string Name; // monster name
       //==============================
        NODE *nextPtr;// next pointer
        NODE *pPtr;// Previous pointer

public:
      NODE(int,int,int,string="Unknown");
      ~NODE();
      virtual void Show_NODE();// temp show
      NODE* move_next();//nextptr
      NODE* move_back();//previousptr
      void set_next(NODE*); //set nextptr
      void set_back(NODE*); //set backptr
      string show_name();//show name
      int show_order();//show order no.
      void set_order_node(int);//set order no.
      void change_hp(int);//cahnge hp
      int show_hp();//show current hp
      void set_name(string);//set monster name
      int show_atk();//show atk
      int show_Max_hp();//show  max hp
      void set_elemental_DMG(int);//set elemental DMG
      int show_elemental_DMG();//show elemental DMG
      virtual void attack(NODE*);//monster use elemental skills
      virtual string show_elemental();//show elemental name
      virtual int weakness_resistance(NODE*,int);//check elemental weakness each others
      void level(NODE*,int);//set level
      void heal(int);
};
typedef NODE* NodePtr;