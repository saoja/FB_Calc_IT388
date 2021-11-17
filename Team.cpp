#include <vector>
#include <algorithm>
#include <iostream>
#include <fstream>
#include <string>
#include "Player.cpp"
using namespace std;

class Team{
    public:
        vector<Player> members;
        string name=0;
        int totalWins=0;
        int yardsAllowed=0;
        int yds=0;
        int pts=0;
        int ptsA=0;
        double winProb=0;
 
    Team(){
      
    }

    void addPlayer(Player p){
        members.push_back(p);
    }
    
    int  getWins(){return totalWins;}
    
    int  getYardsAll(){return yardsAllowed;}
    
    int getYds(){return yds;}
    
    int getPts(){return pts;}
    
    int getPtsA(){return ptsA;}
    
    string getName(){return name;}
    
    int getYardsAllowed(){return yardsAllowed;}
   
    void setName(string name){this-> name=name;}
   
    void setWins(int totalWins){this->totalWins=totalWins;}
    
    void setYardsAllowed(int yardsAllowed){this->yardsAllowed=yardsAllowed;}
    
    void setYds(int yds){this->yds=yds;}
   
    void setTotalPts(int pts){this-> pts=pts;}
  
    void setPtsAllowed(int ptsA){this-> ptsA=ptsA;}
    
    //calc
    
    double  calcWinProb(Team A, Team B){
        double predict=(    (A.getWins()*0.3)   +   (A.getYds()*.15)    +   (A.getYardsAllowed()*.25)   +   (A.getPts()*.15)    +   (A.getPtsA()*.15)   )  /
                       (    (B.getWins()*0.3)   +   (B.getYds()*.15)    +   (B.getYardsAllowed()*.25)   +   (B.getPts()*.15)    +   (B.getPtsA()*.15)   );
        return predict;
        
    }
};

    
