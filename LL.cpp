#include "LL_and_Elemental Monster.h" 
#include <iostream>
#include <ctime>
#include <windows.h>
using namespace std;
LL::LL(string n,int a){
     trainer=n;
     atk=a;
     hp=100;
     size=0;
     HeadPtr=NULL;
}
LL::~LL(){
   

}    
void LL::ADD(LL* q){//ADD NODE
     int sel=0;//check selection
     string n;
     srand(time(NULL));
     cout<<".";
      Sleep(500);
    int atk=(rand())%20;//ATK DMG 0-20
      cout<<".";
      Sleep(500);
   int hp=(rand())%101;//HP 0-60
      cout<<"."<<endl;
      Sleep(500);
    string name="Unknown";//Monster name
     NodePtr temp = q->HeadPtr;
     NodePtr Currentptr = NULL;
     NodePtr Previousptr = NULL;
     bool A;
     Random(atk,hp);//Random stats
     if(!temp){
          temp= new El_monster(atk,hp,size+1,name);  // create NOde 
          sel=Select_fight(temp);
          if(sel==1){
             A=q->fight(temp,q); // fight (false if escape and true if capture successfully)
          }
          if(sel==1&&A){
             q->HeadPtr=temp;//head = first NODE
          Previousptr=q->HeadPtr;
          Currentptr=q->HeadPtr;
          size++;
          cout<<"Set name Monster: "<<endl;
          cin>>n;
          temp->set_name(n);
          //prev and current point the same place
          }
          
     }else{
          temp= new El_monster(atk,hp,size+1,name);  // create NOde 
          sel=Select_fight(temp);
          if(sel==1){
          bool A=q->fight(temp,q); // fight (false if escape and true if capture successfully)       
          }
          if(sel==1&&A){
           Currentptr=q->HeadPtr;
          while(Currentptr->move_next()!=NULL){
               Currentptr=Currentptr->move_next(); //move current
          }
           Previousptr=Currentptr;
           Currentptr->set_next(temp); //linked NextPtr
           Currentptr=temp;
           Currentptr->set_back(Previousptr);//linked pPtr 
           size++;
           cout<<"Set name Monster: "<<endl;
          cin>>n;
          temp->set_name(n);
          }
           
     }
     if(sel==0||A==false||temp->show_hp()<=0){
               delete(temp);
          }
}
void LL::Add_boss(LL *q){
  int tolhp=0,tolatk=0,atk,hp;
  NodePtr t = q->HeadPtr;
  /*NodePtr Currentptr = NULL;
  NodePtr Previousptr = NULL;*/
  while(t!=NULL){
    tolhp+=t->show_Max_hp();
    tolatk+=t->show_atk();
    t=t->move_next();
  }
  srand(time(NULL));
  hp=tolhp*0.5; 
  hp+=(rand()%101-50)/100*hp;
  //boss hp = half of sum of all current monster hp + random addition of -50% to +50% of that value
  srand(time(NULL));
  atk=tolatk*0.5; 
  atk+=(rand()%51-25)/100*hp;
  //boss hp = half of sum of all current monster hp + random addition of -25% to +25% of that value
  NodePtr temp= new El_monster(atk,hp,size+1,"Boss");
}
void LL::Show_all(){//SHOW ALL NODES
    NodePtr t=HeadPtr;
    int i;
    for(i=0; i<size; i++){
     t->Show_NODE();
     t=t->move_next();
     cout<<"=================================="<<endl;
    }
}
void LL::Delete_all(){//DELETE ALL NODES
    NodePtr t = HeadPtr;
    while(t!=NULL){
     cout<<"Delete  "<<t->show_name()<<endl;
     HeadPtr=HeadPtr->move_next();
     delete(t);
     t=HeadPtr;
    }
}
void LL::Random(int& atk, int& hp){//Random stats
if(atk<10){ //atk>=10
atk=10;
}
if(hp<50){ //hp>=50
     hp=50;
}    
}
bool LL::Select( char select){//check select
     bool A;
       switch (select)
       {
       case ('y'):
          A=true;
          break;
       case ('n'):
         A=false;
          break;
       }
       return A;
}
int LL::Select_fight(NODE*node){//select fight
     char select;
     int sel;
     do{
      node->Show_NODE();
     cout<<"Fight it?"<<endl;
     cout<<"y/n"<<endl;
     cin>>select;//input 
     select=tolower(select); //change to lowercase (just in case for the input is an Uppercase)
     cout<<'['<<select<<']'<<endl;
     if(select!='y'&&select!='n'){
         cout<<"Invalid! Try Again!"<<endl;
         fflush(stdin);
          continue;
     }
     if(select=='y'||select=='n'){
         if(Select(select)){
         sel =1;
         break;
        }else{
         sel = 0;
         break;
        }
     }
     }while(select!='y'&&select!='n');//loop while input wrongly
     return sel;
}
void LL::Delete(LL* q){//delete node
 if(size>0){
     string select;
     NodePtr PreviousPtr=q->HeadPtr;
     NodePtr CurrentPtr=PreviousPtr->move_next();
     NodePtr temp=NULL;
     NodePtr temp2=NULL;
    
     do{
     cout<<"Input Monster Number to DELETE:";
     cin>>select;
     cout<<"["<<stoi(select)<<"]"<<endl;
     if(Check_num(select)){
           if(stoi(select) == PreviousPtr->show_order()&&PreviousPtr==q->HeadPtr){
           temp=PreviousPtr;
           PreviousPtr=PreviousPtr->move_next();
           q->HeadPtr=PreviousPtr;
           delete(temp);
           size--;
           q->Set_order(q);
           break;
       }else {
          
          while(stoi(select) != PreviousPtr->show_order()&&CurrentPtr!=NULL){
                 PreviousPtr=CurrentPtr;
                 CurrentPtr=CurrentPtr->move_next();
          }
          
          if(CurrentPtr!=NULL&& stoi(select) == PreviousPtr->show_order()){
               temp=PreviousPtr;
               PreviousPtr=PreviousPtr->move_back();
               PreviousPtr->set_next(CurrentPtr);
               CurrentPtr->set_back(PreviousPtr);
               delete(temp);
               size--; 
             q->Set_order(q);
               break;                         
          }
          if(CurrentPtr==NULL){
               temp=PreviousPtr;
               PreviousPtr=PreviousPtr->move_back();
               PreviousPtr->set_next(NULL);
               temp->set_back(NULL);
               delete(temp);
               size--;
               if(size==1){
                 CurrentPtr=PreviousPtr;
               }else if(size>1){
                  CurrentPtr=PreviousPtr;
               PreviousPtr=PreviousPtr->move_back();
     
               }   
              q->Set_order(q);
               break;
          }
          
       }

     }else{
      cout<<"Try again!"<<endl;
      continue;
     }

     }while(1);
  }else{
    cout<<"No monster to kill!"<<endl;
  }

}
bool LL::Boss_start(LL *q){
  int found=0;
  NodePtr t = HeadPtr;
  while(t!=NULL||found==0){
    if(Check_boss(t)==true){
      found=1;
      break;
    }
    t=t->move_next();
  }
  t=HeadPtr;
  if(found==1){
    fight(t,q);
  }
  else{
    Add_boss(q);
  }
}
bool LL::Check_boss(NODE *node){
  bool A;
  if(node->show_name().compare("Boss")==0){
    A=true;
  }
  else A=false;
  return A;
}
bool LL::Check_num(string str){
      int i;
      for(i=0; i<str.length(); i++){ //.length() like strlen()
          if(isdigit(str[i])==false){
               return false;
          }

      }
    return true;
}
void LL::Set_order(LL*q){
      int i;
      NodePtr t = q->HeadPtr;
      for(i=1; i<=size; i++){
         t->set_order_node(i);//set number
        t=t->move_next();
      }
}
bool LL::fight(NODE *t,LL*q){
    char select;
    bool A;
    int fight=0;
    do{
    if(q->size==0){
     do{
      int turn=1;
     t->Show_NODE();
     cout<<"Trainer "<<q->show_name()<<"\t"<<"HP: "<<q->show_hp()<<endl;
     cout<<"CHOOSE:"<<endl;
    cout<<"A.Attack"<<endl;
    cout<<"B.Use Potion"<<endl;
    cout<<"C.Capture"<<endl;
    cout<<"D.Escape"<<endl;
    cin>>select;
    select=tolower(select);
    cout<<'['<<select<<']'<<endl;
    switch (select)
    {
    case ('a'):
    if(t->show_hp()>0){
      q->attack(t);
    }
        break;
    case('b'):
       if(q->show_potion()>0){
         q->use_potion();
       }else{
        Sleep(1000);
       cout<<"Potion is Empty"<<endl;
       Sleep(1000);
       continue;
       }
        break;
    case('c'):
    if(Check_boss(t)!=true){
      if(q->capture(t)){
        cout<<"Capture Successfully!"<<endl;
        A=true;
        fight=1;
      }else{
        cout<<"Capture Failed!"<<endl;
        A=false;
      }
    }
    else{
      cout<<"Boss monster cannot be captured!"<<endl;
    }
     break;
     case('d'):
     A=false;
     break;
    }
    if(select!='d'&&A==false){
       turn=0;
       if(turn==0&&t->show_hp()>0){
          cout<<"Out of Turn!"<<endl;
         q->take_DMG(t);
       }                                                                                                                                                                                                                                                                                                         
    }
    if(t->show_hp()<=0){
      system("cls");
      Sleep(1500);
       cout<<"Monster "<<t->show_name()<<" have been killed"<<endl;
      Sleep(1500);
      fight=1;
    }
    if(q->show_hp()==0){
       fight=1;
    }
    }while(select>=97&&select<=99&&t->show_hp()>0&& A==false&&q->show_hp()>0);
    }else if(q->show_size()>0){
      int sel=0;
    do{
      int turn=1;
      int order;
      NodePtr select_mon=NULL;
      q->Show_all();
          if(sel==0){
       do{
       cout<<"CHOOSE Monster (order no.):"<<endl;
       cin>>order; 
       select_mon = select_monster(order);
       try{
        if(select_mon==NULL||order>size){
          throw "Can't find Try again!";
        }
        if(Check_boss(select_mon)==true){
          throw "Can't select Boss monster!";
        }
       }
       catch(const char* n){
        cout<<n<<endl;
        cin.clear();
        cin.ignore(50,'\n');
       }
       
      }while(select_mon==NULL||order>size);
      sel++;
      }
      t->Show_NODE();
     select_mon->Show_NODE();
     cout<<"CHOOSE:"<<endl;
    cout<<"A.Attack"<<endl;
    cout<<"B.Use Potion to Monster"<<endl;
    cout<<"C.Capture"<<endl;
    cout<<"D.Escape"<<endl;
    cin>>select;
    select=tolower(select);
    cout<<'['<<select<<']'<<endl;
    switch (select)
    {
    case ('a'):
    if(t->show_hp()>0){
      select_mon->attack(t);
    }
        break;
    case('b'):
       if(q->show_potion()>0){
         q->use_potion_to_monster(select_mon);
       }else{
       cout<<"Potion is Empty"<<endl;
       }
        break;
    case('c'):
    if(Check_boss(t)==false){
      if(q->capture(t)){
        cout<<"Capture Successfully!"<<endl;
        A=true;
        fight=1;
      }else{
        cout<<"Capture Failed!"<<endl;
        A=false;
      }
    }
    else{
      cout<<"Boss monster cannot be captured!"<<endl;
    }
     break;
     case('d'):
     A=false;
     break;
    }
    if(select!='d'&&A==false){
       turn=0;
       if(turn==0&&t->show_hp()>0){
          cout<<"Out of Turn!"<<endl;
         t->attack(select_mon);
       }                                                                                                                                                                                                                                                                                                         
    }
    if(select_mon->show_hp()<=0){
      cout<<"Monster "<<select_mon->show_name()<<" have been killed"<<endl;
      q->delete_dead_monster(select_mon,q);
    }
    if(t->show_hp()<=0){
      system("cls");
      Sleep(1500);
       cout<<"Monster "<<t->show_name()<<" have been killed"<<endl;
      Sleep(1500);
      if(Check_boss(t)==true){
        NodePtr temp=q->HeadPtr;
        while(temp!=NULL){
          temp->level(temp,1);
          temp->move_next();
        }
      }
      fight=1;
    }
    }while(select>=97&&select<=99&&t->show_hp()>0&& A==false&&q->show_hp()>0);

    }
    }while(fight==0);
    return A;
}
int LL::show_attack(){
      return atk;
}
void LL::attack(NODE *t){
    int DMG;
    int Crit;
    int count=0;
    srand(time(NULL));
    Crit=(int)(rand()%100);
    if(Crit>=95){
      Crit=1;
    }else{
      Crit=0;
    }
    DMG=atk+((0.1)*t->show_Max_hp());
   
   if(Crit==1){

    DMG=DMG*(1+0.5);
   }
   Sleep(1500);
   if(t->show_Max_hp()>0){
if(t->show_hp()-(DMG)>0&&count==0){
  t->change_hp(DMG);
  if(Crit==0){
   cout<<'['<<t->show_name()<<" takes "<<DMG<<" DMG!]"<<endl;
  }else if(Crit==1){
    cout<<"[Critical ATK!]"<<endl;
    cout<<'['<<t->show_name()<<" takes "<<DMG<<" DMG!]"<<endl;
  }
  count++;
}
if(t->show_hp()-(DMG)<=0&&count==0){
   if(Crit==0){
   cout<<'['<<t->show_name()<<" takes "<<DMG<<" DMG!]"<<endl;
  }else if(Crit==1){
    cout<<"[Critical ATK!]"<<endl;
    cout<<'['<<t->show_name()<<" takes "<<DMG<<" DMG!]"<<endl;
    } 
    t->change_hp(DMG);
     count++;       
      {
  Sleep(1500);
        
         }
      }
  }
}
void LL::use_potion(){
   int Bonus_heal;
  Bonus_heal=5+(0.3*max_hp);
      if(hp>0)
      {
        if(hp+Bonus_heal<=max_hp)
        {
           hp=hp+(Bonus_heal);
            potions--;
        }else if(hp+Bonus_heal>max_hp)
          {
        hp = max_hp;
        potions--;
          }
          Sleep(1000);
       cout<<'['<<trainer<<" heals yourself "<<Bonus_heal<<" HP]"<<endl;
       Sleep(1000);   
      }  
       if(hp<=0){
        Sleep(1000); 
       cout<<"HP IS 0 CANT HEAL!"<<endl;    
       Sleep(1000);  
       }
   
}
int LL::show_potion(){
     return potions;
}
int LL::show_size(){
     return size;
}
int LL::show_hp(){
     return hp;
}
int LL::show_Max_hp(){

     return max_hp;
}
string LL::show_name(){
  return trainer;
}
bool LL::capture(NODE *t){
  int change;
  bool A;
     if(t->show_hp()==t->show_Max_hp()){
         A=false;
     }
     if(t->show_hp()<=(0.5)*t->show_Max_hp()){
        change=rand()%100;
        if(change%2==0){
          A=true;
        }else{
          A=false;
        }

      }else if(t->show_hp()<=(0.3)*t->show_Max_hp()){
        change=rand()%100;
        if(change<70){
          A=true;
        }else{
          A=false;
        }
    }else if(t->show_hp()<=(0.1)*t->show_Max_hp()){
        change=rand()%100;
        if(change<99){
          A=true;
        }else{
          A=false;
        }
}
        return A;
}
void LL::change_hp(int DMG){
       hp-=DMG;
       if(hp-=DMG<=0){
        hp=0;
       }
      
}
void LL::take_DMG(NODE*t){
     int DMG;
    int Crit;
    int count=0;
    srand(time(NULL));
    Crit=(int)(rand()%100);
    if(Crit>=95){
      Crit=1;
    }else{
      Crit=0;
    }
    DMG=t->show_elemental_DMG()+((0.1)*max_hp);
   
   if(Crit==1){

    DMG=DMG*(1+0.5);
   }
   Sleep(1500);
   if(max_hp>0){
if(hp-(DMG)>0&&count==0){
  hp-=DMG;
  if(Crit==0){
    Sleep(1000); 
   cout<<'['<<trainer<<" takes "<<t->show_elemental()<<" "<<DMG<<" DMG!]"<<endl;
   Sleep(1000); 
  }else if(Crit==1){
    Sleep(1000); 
    cout<<"[Critical ATK!]"<<endl;
    Sleep(1000); 
    cout<<'['<<trainer<<" takes "<<t->show_elemental()<<" "<<DMG<<" DMG!]"<<endl;
    Sleep(1000); 
  }
  count++;
} 
if(hp-(DMG)<=0&&count==0){
     hp=0;
     count++;
  }
    
}
}
NODE* LL::select_monster(int n){
NodePtr t =  NULL;
NodePtr temp = HeadPtr;
int i;
   for(i=0;i<size;i++){
      if(temp->show_order()==n){
        t=temp;
        break;
      }
     if(i==size&&t->show_order()!=n){
      t=NULL;
     }
   }
   return t;
}
void LL::use_potion_to_monster(NODE*t ){
    int Bonus_heal;
    int heal=20;
  Bonus_heal=heal+(0.3*t->show_Max_hp());
      if(t->show_hp()>0)
      {
        if(t->show_hp()+Bonus_heal<=t->show_Max_hp())
        {
            t->heal(Bonus_heal);
            potions--;
        }
          Sleep(1000);
       cout<<'['<<trainer<<" heals monster "<<t->show_name()<<" "<<Bonus_heal<<" HP]"<<endl;
       Sleep(1000);   
      }  
}
void LL::heal_all(LL* q){
   hp=max_hp;
  NodePtr temp=q->HeadPtr;
  while(temp){
    temp->heal(temp->show_Max_hp());
    temp=temp->move_next();
  }
  Sleep(750);
  cout<<"All healed!"<<endl;
  Sleep(750);
}
void LL::delete_dead_monster(NODE*t,LL* q){//delete node
     string select;
     NodePtr PreviousPtr=q->HeadPtr;
     NodePtr CurrentPtr=PreviousPtr->move_next();
     NodePtr temp=NULL;
     NodePtr temp2=NULL;
     if(t->show_order()==1){
      temp=t;
       q->HeadPtr=q->HeadPtr->move_next();
       CurrentPtr=q->HeadPtr;
       PreviousPtr=temp;
       CurrentPtr->set_back(NULL);
       PreviousPtr->set_next(NULL);
       delete(temp);
     }else if (t->show_order()>1&&t->show_order()<q->show_size()){
         temp=t;
         PreviousPtr=temp->move_back();
         CurrentPtr=temp->move_next();
         PreviousPtr->set_next(CurrentPtr);
         CurrentPtr->set_back(PreviousPtr);
         temp->set_back(NULL);
         temp->set_next(NULL);
         delete(temp);

     }else if(t->show_order()==size){
      temp =t;
      PreviousPtr=temp->move_back();
      CurrentPtr=temp;
      PreviousPtr->set_next(NULL);
      CurrentPtr->set_back(NULL);
      delete(temp);
     }
    size--;
}