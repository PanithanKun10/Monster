#include "LL_and_Elemental Monster.h" 
#include <iostream>
using namespace std;
NODE::NODE(int Atk ,int Hp,int Or,string name){
          EXP=0;
          Max_EXP=10;
          lvl=1;
          atk=Atk;
          current_hp=Hp;
          Max_hp=Hp;
          Name=name;
          order=Or;
          nextPtr=NULL;
          pPtr=NULL;
}
NODE::~NODE(){
      cout<<"Killed Monster "<<this->show_order()<<endl;
}
void NODE::Show_NODE(){
    //Print Stats
    cout<<"lvl: "<<lvl<<endl;
    cout<<"No."<<order<<endl;
    cout<<"Monster: "<<Name<<endl;
    cout<<"ATK:"<<atk<<endl;
    cout<<"HP: "<<current_hp<<endl;;
}
NODE* NODE::move_next(){
      return nextPtr;
}
void NODE::set_next(NODE* node){
       nextPtr = node; //set nextPtr to 
}
void NODE::set_back(NODE* node){
       pPtr = node;  //set PreviousPtr to 
}
string NODE::show_name(){
    return Name;
}
NODE* NODE::move_back(){
    return pPtr;
}
int NODE::show_order(){ 
    return order;
}
void NODE::set_order_node(int n){ ///set monster order
      order=n;
}
void NODE::change_hp(int atk){   
    if(current_hp-atk>=0){
        current_hp-=atk;
    }else if(current_hp-atk<=0){
        current_hp=0;
    }
}
int NODE::show_hp(){
    return current_hp;
}
int NODE::show_Max_hp(){
    return Max_hp;
}
int NODE::show_atk(){
   return atk;
}
void NODE::set_name(string n){
     Name=n;
}
int NODE::show_elemental_DMG(){

    return elemental_DMG;

}
void NODE::set_elemental_DMG(int d){

   elemental_DMG=d;
 

}

void NODE::attack(NODE*t){

  cout<<"hello"<<endl;

}
string NODE::show_elemental(){

  

     return "EEEE";
}
void NODE::level(NODE*t,int e){
  lvl+=e;


}
void NODE::heal(int heal){
        if(current_hp+heal<Max_hp){
            current_hp+=heal;
        }else if(current_hp+heal>=Max_hp){
            current_hp=Max_hp;   
        }
}
int NODE::weakness_resistance(NODE* t,int g){



    return 0;
}