#include <iostream>
#include "Driver.cpp"


using namespace std;



int main(){

    // variables for menu use
    int selection=1;  // function type
    string user_in; // team or player names

    // Menu
    cout<<"Select an option # (ex. '2'):\n";
    cout<<"\t1. Single Game Prediction\n";
    cout<<"\t2. All Game Predictions\n";
    cout<<"\t3. Player Prediction\n";
    cout<<"\t4. Quit\n";
    cout<<"Selection: ";
 
    //cout<<"Enter the name (mascot for a team): ";
    cin>>user_in;
    
    Driver drive;
    string TeamA_CSV;
    string TeamB_CSV;
    string matchups="matchups.csv";
    string Players_CSV;
    // execute correct function
    switch(selection){
        case 1:
            // single game prediction
            cout<<"Enter first team name): ";
            cin>>TeamA_CSV;
            cout<<"Enter second team name): ";
            cin>>TeamB_CSV;
            drive.CalcTeamWinProb(TeamA_CSV,TeamB_CSV);
            break;
        case 2:
        
            // display all of the week's predictions
            cout<<"Match up probabilities"<<endl;
            drive.CalcAllTeamMatches(matchups);
            break;
        case 3:
       
            // predict the players stats for the week
            cout<<"Player's Ranking"<<endl;;
            drive.Players(Players_CSV);
        case 4:
            return false;
            break;
        default:
            cout<<"Error: Enter a correct number (1-4)";
            break;
    }

}
