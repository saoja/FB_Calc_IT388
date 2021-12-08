#ifndef _PLAYER_H
#define _PLAYER_H

#include <vector>
#include <algorithm>
#include <iostream>
#include <fstream>
#include <string>

using namespace std;
class Player{
    private:
        string name=" ";
        string team=" ";
        int age=25;
        int recivingYards=0;
        int recivingTargets=0;
        int routesRun=0;
        //calculations vars
        int yprr = 0;
        int ypt =0;
    public:
        Player();

        string  getName();
        
        string getTeam();
    
        int  getAge();

        int  getrecvYards();

        int  getrecvTargets();
   
        int  getroutesRun();
    
        int  getYprr();
   
        //yards per Target
        int getYpt();
    
        void  setName(string name);
   
        void  setTeam(string team);
    
    
        void setAge(int age);
   
        void  setRecvingYards(int recivingYards);
  
        void setRecivingTargets(int recivingTargets);
    
        void  setRoutesRun(int routesRun);


    
};
 #endif