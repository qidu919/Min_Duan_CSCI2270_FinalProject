#ifndef PROTOTYPE1_H
#define PROTOTYPE1_H
#include <vector>
#include <iostream>

struct player
{
    /*
    Each player has:
        * A Username (ign)
        * The number of promotional games wins (pWins)
        * An int, queuePosition, that represents the player's spot in queue once he/she is placed in queue.
        * A ranked division (rankt) that's Bronze, Silver, Gold, Platinum, Diamond, Master, Challenge, or Undecided
        * A previous and next pointer, which is used to organize their place in the hash table
        * A boolean that determines whether or not he/she is currently in a ranked division
        * A boolean that determines whether or not he/she is in queue
        * A boolean that determines whether or not he/she is in a match
    */
    std::string ign;
    int pWins;
    int queuePosition;
    std::string rankt;
    player* prev;
    player* next;
    bool isRanked;
    bool isInQueue;
    bool isInMatch;
};



struct soloMatch{
    /*
    Each solo match has:
    ------------------------------------------------------------------------------------------------------
        *A match ID (ID)
        *The rank of the match (matchRank)
        *An array that holds all of the players who are in the game
    */
    int ID;
    std::string matchRank;
    player* playerArray[10];
};


class lolQueue
{
    public:
        lolQueue ();
        ~lolQueue ();

        player* newPlayer (std::string pname, int wins);

        player* determinePlayerRank (player* inPlayer);

        bool alreadyexists(std::string pname);

        void enterSoloQueue (player* inPlayer);

        void addSoloPlayer (int index, player *inPlayer);

        void leaveSoloQueue (player *inPlayer);

        void displayPlayer (player* inPlayer);

        void displayMatches ();

        void displaySoloQueue ();

        void displayInactives ();

        void createSoloMatch (int index);

        std::vector <soloMatch*> soloMatchVector;
        std::vector <player*> playerVector;

    protected:
    private:
        /*
        In the private section we have:
        ------------------------------------------------------------------------------------------------------
            *newMatchID, which is used to create a new ID every time a match is made. When a match is made,
             newMatchID increases by 1 to make a new ID in preparation for the next match.

            *soloHashTable, which is the hash table that holds the players who chose Solo Queue. The seven
             spaces represent the seven ranks (bronze, silver, gold, platinum, diamond, master, and challenger).

        */
        int newMatchID;

        player* soloHashTable[7];
};

#endif // PROTOTYPE1_H
