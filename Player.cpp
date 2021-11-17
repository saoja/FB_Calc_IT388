

#include <vector>
#include <algorithm>
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Player{
    public:

        string name=" ";
        string team=" ";
        int age=0;
        int recivingYards=0;
        int recivingTargets=0;
        int routesRun=0;
        //calculations vars
        int yprr = 0;
        int ypt =0;

    Player(){}

    string  getName(){
        return name;
    }

    string getTeam(){
        return team;
    }

    int  getAge(){
        return age;
    }

    int  getrecvYards(){ return recivingYards;}

    int  getrecvTargets(){ return recivingTargets;}

   
    int  getroutesRun(){ return routesRun;}

      
    //calculations vars
    //Yards per routes run
    
    int  getYprr(){
        yprr=recivingYards/routesRun;
        return yprr;
    }
   
    //yards per Target
    int getYpt(){
        ypt =  recivingYards/ recivingTargets;
        return ypt;
    }
    



    
    
   
    void  setName(string name){
        this->name=name;
    }
   
     void  setTeam(string team){
        this->team=team;
    }
    
    void setAge(int age){
        this->age=age;
    }
   
    void  setRecvingYards(int recivingYards){this->recivingYards=recivingYards;}
  
    void setRecivingTargets(int recivingTargets){this->recivingTargets=recivingTargets;}
    
    void  setRoutesRun(int routesRun){this->routesRun=routesRun;}
  
};


