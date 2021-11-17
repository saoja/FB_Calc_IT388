#include <iostream>
#include "downloaders.cpp"
#include "Driver.cpp"
using namespace std;

bool menu();

int main(){

    cout<<"---Weekly Football Predictor---\n";
    cout<<"---Stephen Oja, Tre Blankenship\n";
    cout<<"---2021\n\n";

    return 0;
}

bool menu(){

    // variables for menu use
    int selection;  // function type
    string user_in; // team or player names

    // Menu
    cout<<"Select an option # (ex. '2'):\n";
    cout<<"\t1. Single Game Prediction\n";
    cout<<"\t2. All Game Predictions\n";
    cout<<"\t3. Player Prediction\n";
    cout<<"\t4. Quit\n";
    cout<<"Selection: ";
    cin>>selection;
    cout<<"Enter the name (mascot for a team): ";
    cin>>user_in;
    
    Driver drive =new Driver();

    // execute correct function
    switch(selection){
        case 1:
            // download the correct data
            // single game prediction
            string TeamA_CSV;
            string TeamB_CSV;
            drive.calcTeamWinProb(TeamA_CSV,TeamB_CSV);
            break;
        case 2:
            // download the correct data
            // display all of the week's predictions
            vector<string> matchups;
            //push_back() all teams csv files in matchups this week
            drive.calcAllTeamMatchUps();
            break;
        case 3:
            // download the correct data
            // predict the players stats for the week
            string Players_CSV;
            drive.Players(Players_CSV);
        case 4:
            return false;
            break;
        default:
            cout<<"Error: Enter a correct number (1-4)";
            menu();
            break;
    }

    // continue?
    char cont;
    cout<<"Continue? [y/n] : ";
    cin>>cont;
    if(cont == 'y'){
        menu();
    }
    else if(cont == 'n'){
        cout<<"exiting...";
        exit(-1);
    }
    else{
        cout<<"Incorrect input, terminating...";
        exit(-1);
    }
}
