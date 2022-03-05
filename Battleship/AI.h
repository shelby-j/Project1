#ifndef AI_H
#define AI_H

#include <iostream>
#include <string>
#include <list>
#include "Board.h"
using namespace std;

class AI {
    private:
        int m_size; //Integer variable representing size of battleship board (10x10)
        Board* p1Board; //Pointer to instance of Board class that represents Player 1's board
        Board* AIBoard; //Pointer to instance of Board class that represents Player 2's board
        bool PTurn; //Boolean variable keeps track of which player's turn it is at any given time.
        string letters;

      
	public:
        /*----------
        * @pre numShips >=1 && <= 5
        * @post constructor creates an instance of the Executive class
        * @param int numShips (1-5, chosen # of battleships for first player)
        * @return no true return, just creates instance of the class
        * -------*/
        AI(int numShips);

        /*----------
        * @pre an instance of Executive class must exist to be deleted
        * @post Executive class instance is deleted
        * @param none
        * @return none, just deleted instance of class
        * -------*/
        ~AI();

        /*----------
        * @pre
        * @post
        * @param Board* board (pointer to player's board) and int numShips (# of ships chosen for play)
        * @return none - void function
        * -------*/
        void chooseShipLoc(Board* board, int numShips);

        /*----------
        * @pre must have instances of Executive class and Board class for gameplay
        * @post gameplay can commence
        * @param none - no arguments passed in
        * @return none - void function
        * -------*/
        void run();

        /*----------
        * @pre 
        * @post switch players
        * @param none - no arguments passed in
        * @return none - void function
        * -------*/
        void playerSwitch();
        
        /*----------
        * @pre must pass in a character c for correct conversion
        * @post converts character to integer
        * @param char c, a character desired to be converted to an integer
        * @return a converted integer
        * -------*/
        int charToInt(char c);

        /*----------
        * @pre must input an #iistring
        * @post checks to see whether the given location is valid in reference to board size and description
        * @param #iistring input, the string representing the desired location on board
        * @return #iistring, representation as to whether or not a valid location was chosen
        * -------*/
        string validateLoc(string input);

        /*----------
        * @pre must input an #iistring
        * @post checks to see if a given string input is valid
        * @param #iistring input, the string to check validity
        * @return bool, to determine if the string is valid or not
        * -------*/
        bool checkInput(string input);
        
        /*----------
        * @pre char input must be V (for vertical) or H (for horizontal) for meaningful orientation
        * @post orients ship on board in accordance with selection, can be horizontal or vertical
        * @param char input (V or H)
        * @return char representing chosen orientation
        * -------*/
        char validateDirection(char input);

        int level();

        void AIsetup(Board* board, int numShips);

        string randomLoc();

        void easyLevel();

        // void mediumLevel();

        // void hardLevel(player_ship);
        
        // string shotfromlist(list);
};

#endif