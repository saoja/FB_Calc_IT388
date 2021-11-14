#include <iostream>
#include <downloaders.cpp>

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

    // execute correct function
    switch(selection){
        case 1:
            // download the correct data
            // single game prediction
            break;
        case 2:
            // download the correct data
            // display all of the week's predictions
            break;
        case 3:
            // download the correct data
            // predict the players stats for the week
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