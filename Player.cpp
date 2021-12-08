
#include "Player.h"
Player::Player(){}
string Player::getName(){
    return name;
}

string Player::getTeam(){
    return team;
}

int Player:: getAge(){
    return age;
}

int  Player::getrecvYards(){ return recivingYards;}

int  Player::getrecvTargets(){ return recivingTargets;}

   
int  Player::getroutesRun(){ return routesRun;}

      
//calculations vars
//Yards per routes run
    
int  Player::getYprr(){
    yprr=recivingYards/routesRun;
    return yprr;
}
   
    //yards per Target
int Player::getYpt(){
    ypt =  recivingYards/ recivingTargets;
    return ypt;
}
    



    
    
   
    void  Player::setName(string name){
        this->name=name;
    }
   
     void  Player::setTeam(string team){
        this->team=team;
    }
    
    void Player::setAge(int age){
        this->age=age;
    }
   
    void  Player::setRecvingYards(int recivingYards){this->recivingYards=recivingYards;}
  
    void Player::setRecivingTargets(int recivingTargets){this->recivingTargets=recivingTargets;}
    
    void  Player::setRoutesRun(int routesRun){this->routesRun=routesRun;}
  



