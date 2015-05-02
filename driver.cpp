#include <iostream>
#include <vector>
#include "Prototype1.cpp"
using namespace std;
void printMenu(){
    cout<<"======Main Menu======"<<endl;

    cout<<"1. Enter New Player"<<endl;
    cout<<"2. Exit Solo Queue"<<endl;
    cout<<"3. Re-enter Solo Queue"<<endl;
    cout<<"4. Display Player Information"<<endl;
    cout<<"5. Display Players Currently in Solo Queue"<<endl;
    cout<<"6. Display Matches Currently Taking Place"<<endl;
    cout<<"7. Display Players not in Queue and not in Game "<<endl;
    cout<<"8. Quit"<<endl;
    cout<<"====================="<<endl;
}

int main(){
    printMenu();

    lolQueue mainQueue;
    bool quit = false;
    int input;
    while (quit == false){

        cin >> input;
        cin.clear();
        cin.ignore(10000,'\n');

        switch(input){
            case 1:{
                /*
                */
                string username;
                string promoWins = "11";     //promoWins is initially 11 so that it is > 10, allowing us to enter the while loop

                cout<<"Enter Username: "<<endl;     //enter username
                getline(cin , username);
                cout<<"Enter Number of Promotional Games out of 10 won: "<<endl;       //enter wins
                cin >> promoWins;

                while (promoWins != "0" && promoWins != "1" && promoWins != "2" && promoWins != "3" && promoWins != "4" && promoWins != "5" && promoWins != "6" && promoWins != "7" && promoWins != "8" && promoWins != "9" && promoWins != "10" ){        //we stay here until a valid number of wins is given
                   cout<<"Invalid Input. Please submit a number between 0 and 10: "<<endl;
      
                    cin>>promoWins;
                    cin.clear();
                    cin.ignore(10000,'\n');

                }
                if (mainQueue.alreadyexists(username)){     //we check if the given username already exists.
                    cout<<"Player already exists. New user cannot be created."<<endl;
                }
                else{
                    cout<<"Player Created"<<endl;
                    player* tempplayer = mainQueue.newPlayer(username, stoi(promoWins));      //when we find a valid new user, we make a new player, give a rank, and put them in the hashtable
                    cout<<endl;
                    mainQueue.determinePlayerRank(tempplayer);
                    cout<<endl;
                    mainQueue.enterSoloQueue(tempplayer);
                }
                printMenu();
                break;
            }

            case 2:{
                /*
                This function allows a user to leave the hash table
                */
                string username;

                cout<<"Enter Username: "<<endl;
                getline(cin , username);
                player* tempplayer = NULL;
                for (int i = 0; i < mainQueue.playerVector.size(); i++){
                    if (mainQueue.playerVector.at(i)->ign == username){
                        tempplayer = mainQueue.playerVector.at(i);
                        break;
                    }
                }

                if (tempplayer == NULL){            //checks if user exists
                    cout<<"Player has not been created."<<endl;
                }

                else if (!tempplayer->isInQueue){
                    if (tempplayer->isInMatch){         //for these two conditions, it checks if the user's either in a match or already out of queue and
                        cout<<"Player is currently in match."<<endl;        //not in a match
                    }
                    else{
                        cout<<"Player is already out of queue"<<endl;
                    }
                }

                else {
                    mainQueue.leaveSoloQueue(tempplayer);       //if all conditions are met, it goes to leavesoloqueue
                }
                printMenu();

                break;
            }


            case 3:{
                /*
                This function is used to re-enter a player into the queue after they leave
                */
                string username;

                cout<<"Enter Username: "<<endl;         //We search if the player exists first. alreadyexists function
                getline(cin , username);                //cannot be used here because it is a bool function and enterSoloQueue Requires a *player type variable
                player* tempplayer = NULL;
                for (int i = 0; i < mainQueue.playerVector.size(); i++){
                    if (mainQueue.playerVector.at(i)->ign == username){
                        tempplayer = mainQueue.playerVector.at(i);
                        break;
                    }
                }

                if (tempplayer == NULL){
                    cout<<"Player does not exist."<<endl;
                }

                else{
                    mainQueue.enterSoloQueue(tempplayer);       //if all conditions are met, it goes to entersoloqueue
                }
                printMenu();

                break;
            }

            case 4:{
                /*
                Prints player information
                */
                string username;
                cout<<"Enter Username: "<<endl;
                getline(cin , username);                                    //See explanation starting on line 108
                player* tempplayer = NULL;
                for (int i = 0; i < mainQueue.playerVector.size(); i++){
                    if (mainQueue.playerVector.at(i)->ign == username){
                        tempplayer = mainQueue.playerVector.at(i);
                        break;
                    }
                }
                if (tempplayer == NULL){
                    cout<<"Player not found."<<endl;
                }
                else {
                    mainQueue.displayPlayer(tempplayer);
                }
                printMenu();
                break;
            }

            case 5:{
                /*
                    Prints players who are still in the queue, going from bronze to challenger
                */
                mainQueue.displaySoloQueue();
                printMenu();
                break;
            }


            case 6:{
                /*
                Prints all matches currently taking place
                */
                mainQueue.displayMatches();
                printMenu();
                break;
            }
            case 7:{
                /*
                Prints all players who are neither in queue nor in a match
                */
                mainQueue.displayInactives();
                printMenu();
                break;
            }
            case 8:{
                quit = true;
                break;
            }
            default:
                cout << "Invalid Input" << endl;
                cin.clear();
                printMenu();
                break;
        }
    }

    cout<<"Goodbye!"<<endl;
}
