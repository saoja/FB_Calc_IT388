#ifndef TEAM_H
#define TEAH_H

#include <vector>
#include <algorithm>
#include <iostream>
#include <fstream>
#include <string>
#include "Player.cpp"
using namespace std;

class Team{
   public:
 
    Team();
    
    int  getWins();
    
    int  getYardsAll();
    
    int getYds();
    
    int getPts();
    
    int getPtsA();
    
    string getName();
    
    int getYardsAllowed();
   
    void setName(string name);
   
    void setWins(int totalWins);
    
    void setYardsAllowed(int yardsAllowed);
    
    void setYds(int yds);
   
    void setTotalPts(int pts);
  
    void setPtsAllowed(int ptsA);
    
    //calc
    
    double  calcWinProb(Team A, Team B);

    private:
        string name="";
        int totalWins=0;
        int yardsAllowed=0;
        int yds=0;
        int pts=0;
        int ptsA=0;
        double winProb=0;

};
 #endif