#include "Team.h"


 
    Team::Team(){
      
    }
    
    int  Team::getWins(){return totalWins;}
    
    int  Team::getYardsAll(){return yardsAllowed;}
    
    int Team::getYds(){return yds;}
    
    int Team::getPts(){return pts;}
    
    int Team::getPtsA(){return ptsA;}
    
    string Team::getName(){return name;}
    
    int Team::getYardsAllowed(){return yardsAllowed;}
   
    void Team::setName(string name){this-> name=name;}
   
    void Team::setWins(int totalWins){this->totalWins=totalWins;}
    
    void Team::setYardsAllowed(int yardsAllowed){this->yardsAllowed=yardsAllowed;}
    
    void Team::setYds(int yds){this->yds=yds;}
   
    void Team::setTotalPts(int pts){this-> pts=pts;}
  
    void Team::setPtsAllowed(int ptsA){this-> ptsA=ptsA;}
    
    //calc
    
    double  Team::calcWinProb(Team A, Team B){
        double predict=(    (A.getWins()*0.3)   +   (A.getYds()*.15)    +   (A.getYardsAllowed()*.25)   +   (A.getPts()*.15)    +   (A.getPtsA()*.15)   )  /
                       (    (B.getWins()*0.3)   +   (B.getYds()*.15)    +   (B.getYardsAllowed()*.25)   +   (B.getPts()*.15)    +   (B.getPtsA()*.15)   );
        return predict;
        
    }


    
