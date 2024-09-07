#include <iostream>
#include <conio.h>
#include ""
using namespace std;
int main(int argc,char **argv){
    int atk;
    int hp;
    string name;
    char choose;
    cout<<"Your name:";
    cin>>name;
     LL trainer(name);
     do{
    cout<<"Hi "<<name<<'!'<<endl;
    cout<<""<<trainer.show_size()<<"/"<<"6"<<endl;
    cout<<"trainer: "<<trainer.show_name()<<"\t"<<trainer.show_hp()<<"/"<<trainer.show_Max_hp()<<endl;
    trainer.Show_all();
    cout<<"CHOOSE:"<<endl;
    cout<<"A.Random Monster"<<endl;
    cout<<"B.Delete Monster"<<endl;
    cout<<"C.heal All"<<endl;
    choose=getch();//input
    choose=tolower(choose);//lowercase
    try{
     if(choose<97||choose>99){
        throw "for i in range(100) Stupid Fuck";
     }
    }
    catch(const char* error){
         cout<<error<<endl;
         cin.clear();
        cin.ignore(50,'\n');
      }
    switch(choose){
         case('a'):
         if(trainer.show_size()<=6){
             trainer.ADD(&trainer);//add note
          system("cls");
         }else{
           cout<<"Maximum of monsters are 6!"<<endl;
         }
         break;
         case('b'):
         trainer.Delete(&trainer);//delete node
         trainer.Show_all();
         break;
         case('c'):
         trainer.heal_all(&trainer);
         break;
    }
    //if(trainer.show_size()>0) trainer.Boss_start();
     }while(choose!='x'&&trainer.show_hp()>0);
    if(trainer.show_hp()<=0){
      system("cls");
      cout<<"GAME OVER"<<endl;
    }
    

    return 0;
}