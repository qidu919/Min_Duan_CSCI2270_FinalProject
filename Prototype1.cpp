#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Prototype1.h"
using namespace std;

/*
Function Prototype:

Function Description:

Example:

Precondition:

Post Condition:

*/
lolQueue::lolQueue(){
    /*
    This Constructor initializes the newMatchID to 1, so the first match can have an ID 1,
    and initializes all the hash table slots to NULL so that the function addSoloPlayer can
    function properly.
    */
    newMatchID = 1;
    for (int i = 0; i < 7; i++){
        soloHashTable[i] = NULL;

    }
}
lolQueue::~lolQueue(){

}

/*
Function Prototype:
lolQueue::newPlayer(string pName, int wins)

Function Description:
This function creates a new player, given the name and number of wins. Additionally,
queueposition, rankt, isRanked, isInQueue, and isInMatch are all initialized to their
default values, all the while putting the player in the playervector.

Example:
string playerName = "Qiu";
int wins = 3;
player* lolQueue::newPlayer(playerName, wins);

Precondition:
Has a name that is non-null and win count is non-negative.

Post Condition:
Fields in the player struct are all initialized on the heap.

*/
player* lolQueue::newPlayer(string pName, int wins)
{

    player *newp = new player;
    newp->ign = pName;
    newp->queuePosition = 0;
    newp->pWins = wins;
    newp->rankt = "Unranked";
    newp->prev = NULL;
    newp->next = NULL;
    newp->isRanked = false;
    newp->isInQueue = false;
    newp->isInMatch = false;
    playerVector.push_back(newp);
    return newp;
}
/*
Function Prototype:
player* determinePlayerRank(player* inPlayer);
Function Description:
This function determines a player's rank division based on their number of wins.
With the given ranges, the player's rankt is set and isRanked is set to true.
Example:
player* determinePlayerRank(inPlayer);
Precondition:
Must have a non negative ranked wins and must have a node with player info on it.
Post Condition:
The struct node must holds true and able to return
*/
player* lolQueue::determinePlayerRank(player* inPlayer){

    if (inPlayer->isRanked){
        cout<<"This player is already ranked"<<endl;
    }
    else{
        int nw = 0;

        nw = inPlayer->pWins;
        if (nw == 1 || nw == 2 || nw == 0){
            inPlayer->rankt = "Bronze";
        }
        else if (nw == 3 || nw == 4) {
            inPlayer->rankt = "Silver";
        }
        else if (nw == 5 || nw == 6){
            inPlayer->rankt = "Gold";
        }
        else if (nw == 7 ){
            inPlayer->rankt = "Platinum";
            }
        else if (nw == 8){
            inPlayer->rankt = "Diamond";
        }
        else if (nw == 9){
            inPlayer->rankt = "Master";
        }
        else if (nw >= 10){
            inPlayer->rankt = "Challenger";
        }
        cout<<"Based on number of wins in promotional games, player has been placed in "<<inPlayer->rankt<<" division."<<endl;
        inPlayer->isRanked = true;
    }
}
/*
Function Prototype:
bool alreadyexists(string pname);
Function Description:
This function goes through the playervector to see if it can find a match for the
given name.
Example:
string pname = "GODLIKE"
alreadyexists(pname);
Precondition:
there must be a name and a vector to look through, vector must not be NULL
Post Condition:
Does not change the vector, just a search.
*/
bool lolQueue::alreadyexists(string pname){

    bool found = false;
    for (int i = 0; i < playerVector.size(); i++){
        if (playerVector.at(i)->ign == pname){
            found = true;
            break;
        }
    }

    return found;
}

/*
Function Prototype:
void enterSoloQueue(player* inPlayer)
Function Description:
This function causes the player to be placed into the hashtable.
Based again on the rank division of the player, an index corresponding to
the division and the player are placed into the addSoloPlayer function.
Example:
enterSoloQueue(inPlayer)
Precondition:
There has to be a player with sufficient information in the player struct
Post Condition:
That nothing changes during the function
*/
void lolQueue::enterSoloQueue(player* inPlayer){

    if (inPlayer->rankt == "Unranked"){
        cout<<"Player rank has not been verified yet. Please verify rank before attempting to enter queue."<<endl;
    }
    else if (inPlayer->isInQueue){
        cout<<"Player is already in queue."<<endl;
    }
    else if (inPlayer->isInMatch){
        cout<<"Player is already in a match."<<endl;
    }
    else{
        if(inPlayer->rankt == "Bronze"){
            addSoloPlayer(0, inPlayer);
        }
        else if(inPlayer->rankt == "Silver"){
            addSoloPlayer(1, inPlayer);
        }
        else if(inPlayer->rankt == "Gold"){
            addSoloPlayer(2, inPlayer);
        }
        else if(inPlayer->rankt == "Platinum"){
            addSoloPlayer(3, inPlayer);
        }
        else if(inPlayer->rankt == "Diamond"){
            addSoloPlayer(4, inPlayer);
        }
        else if(inPlayer->rankt == "Master"){
            addSoloPlayer(5, inPlayer);
        }
        else if(inPlayer->rankt == "Challenger"){
            addSoloPlayer(6, inPlayer);
        }
    }
}


/*
Function Prototype:
void addSoloPlayer (int index, player* inPlayer);
Function Description:
addSoloPlayer is used as the second step in putting a player in the hash table.
Example:
int index= 1;
addSoloPlayer (index, inPlayer)
Precondition:
Must have a player index and a player struct
Post Condition:
Player is added to the hash table.
*/
void lolQueue::addSoloPlayer (int index, player* inPlayer){

    inPlayer->isInQueue = true;     // First, it is declared that the player is now in queue
    cout<<"Added to Solo Queue"<<endl;
    if (soloHashTable[index] == NULL){  //if the hash table at the given index is empty, the new player becomes the head at that hash table branch
        soloHashTable[index] = inPlayer;
    }
    else{           // on the other hand, if there already are players in the haah table index specified, the new player is put at the end of the branch
        player* node;
        node = soloHashTable[index];
        while (node->next != NULL){
            node = node->next;
        }
        node->next = inPlayer;
        inPlayer->prev = node;
        inPlayer->queuePosition = node->queuePosition + 1;      //This specifies the new player as the current last member in that particular index
    }

    if (inPlayer->queuePosition == 9){  //once that index has reached 10 players, as seen by how the last player now has an index 9, createSoloMatch is called
        createSoloMatch(index);
    }
}

/*
Function Prototype:
void leaveSoloQueue(player *inPlayer);
Function Description:
There will be an option to exist out of the queue (hash table).
This function is made to move a player out of his/her respective position in the hash table
Example:
leaveSoloQueue(inPlayer)
Precondition:
PLayer is in queue.
Post Condition:
player must be deleted off hash table.
*/

void lolQueue::leaveSoloQueue(player *inPlayer){
    /*
    this function is made to move a player out of his/her respective position in the hash table
    */
    int index;                                          //we need to get the index of the player's rank first
    if(inPlayer->rankt == "Bronze"){
            index = 0;
        }
        else if(inPlayer->rankt == "Silver"){
            index = 1;
        }
        else if(inPlayer->rankt == "Gold"){
            index = 2;
        }
        else if(inPlayer->rankt == "Platinum"){
            index = 3;
        }
        else if(inPlayer->rankt == "Diamond"){
            index = 4;
        }
        else if(inPlayer->rankt == "Master"){
            index = 5;
        }
        else if(inPlayer->rankt == "Challenger"){
            index = 6;
        }

    if (inPlayer == soloHashTable[index]){      //checks to see if the player to be deleted is the head of its hash queue
        if (soloHashTable[index]->next == NULL){
            soloHashTable[index] = NULL;            //if it's alone, simply declare the head null and readjust the next/prev of the removed player
        }
        else{
            soloHashTable[index]->next->prev = NULL;        //if it's not alone, move the next player to the head and readjust next/prev
            soloHashTable[index] = soloHashTable[index]->next;
            player* node = soloHashTable[index];
            int i = 0;                                  //this portion and ones like it in the function
            while (node != NULL){                           //are made to reassign queuepositions
                node->queuePosition = i;                    //after a player has been removed
                node = node->next;
                i++;
            }

            inPlayer->next = NULL;          //since the removed player is now free, both its next and prev must be NULL (its previous was already null in this case because it was the head)
        }
    }
    else if (inPlayer->next == NULL){       //checks to see if the node to be removed is the last node in its queue
        inPlayer->prev->next = NULL;
        inPlayer->prev = NULL;                  //turns the second to last player's next to NULL in order to be the tail
        player* node = soloHashTable[index];
        int i = 0;
        while (node != NULL){
            node->queuePosition = i;        //see explanation for the similar while loop above
            node = node->next;
            i++;
        }
    }
    else{                               //in the last case, where it's in between two tangible nodes, we adjust the next/prev of its neighbors to seal it out
        inPlayer->next->prev = inPlayer->prev;
        inPlayer->prev->next = inPlayer->next;
        inPlayer->next = NULL;              //reset the next/prev of the removed player
        inPlayer->prev = NULL;
        int i = 0;
        player* node = soloHashTable[index];
        while (node != NULL){
            node->queuePosition = i;
            node = node->next;
            i++;
        }
    }
    inPlayer->isInQueue = false;            //resetting the isInQueue and position
    inPlayer->queuePosition = 0;
}



void lolQueue::displayPlayer (player* inPlayer){
    /*
    displays some player information
    */
    cout<< "In Game Name: " << inPlayer->ign << endl;
    cout<< "Player Rank: " << inPlayer->rankt << endl;
    cout<< "Placement Wins: " << inPlayer->pWins << endl;
}



void lolQueue::displayMatches (){

}
void lolQueue::displaySoloQueue (){

}

void lolQueue::displayInactives(){
}

/*
Function Prototype:
void createSoloMatch (int index);
Function Description:
Once the 10 players of a division have been found, we now need to create a match
and get empty the hash table at the division index
Example:
int index =1;
createSoloMatch (index);
Precondition:
There has to be a player index.
Post Condition:
created a solo match with 10 players inside.
*/
void lolQueue::createSoloMatch (int index){

    cout << "Solo Match Found!"<<endl;


    soloMatch *newm = new soloMatch;       // First the division of the match is stated
    if (index == 0){
        newm->matchRank = "Bronze";
    }
    else if (index == 1){
        newm->matchRank = "Silver";
    }
    else if (index == 2){
        newm->matchRank = "Gold";
    }
    else if (index == 3){
        newm->matchRank = "Platinum";
    }
    else if (index == 4){
        newm->matchRank = "Diamond";
    }
    else if (index == 5){
        newm->matchRank = "Master";
    }
    else{
        newm->matchRank = "Challenger";
    }

    cout << "Match ID: "<<newMatchID;
    newm->ID = newMatchID;      //the match is given an ID and the next possible ID is specified
    newMatchID++;
    cout <<endl;

    cout<<"Division: "<<newm->matchRank<<endl;
    cout<<"Players: "<<endl;                    //Then, all the players involved in the match are listed
    player* node = soloHashTable[index];
    for (int i = 0; i < 10; i++){
        newm->playerArray[i] = node;
        node->isInQueue = false;
        node->isInMatch = true;
        cout<<node->ign<<endl;
        node = node->next;
    }

    soloHashTable[index] = NULL;        //The hash table at the division's index is emptied
    soloMatchVector.push_back(newm);     //The newly made match is put into the matchVector


}
