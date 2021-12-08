#include <iostream>
#include "Driver.cpp"



using namespace std;

//this main function was used to collect data for timing. Since the cluster wont be able to provide user input.


int main(){

    Driver drive;
    string TeamA_CSV="seahawks";
    string TeamB_CSV="bears";
    string matchups="matchups.csv";
    string Players_CSV;

   

        //calc win prob for a single matchup
    drive.CalcTeamWinProb(TeamA_CSV,TeamB_CSV);
    
        // display all of the week's predictions
    drive.CalcAllTeamMatches(matchups);
        // predict the players stats for the week      
     drive.Players("/players/");
     
       
    return 0;
}
