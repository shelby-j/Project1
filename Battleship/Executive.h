/*-------------------------------------------------------

 *-----------------------------------------------------*/

#ifndef EXECUTIVE_H
#define EXECUTIVE_H

#include <iostream>
#include <string>
#include "Board.h"

class Executive {
	private:
		int m_size; //Integer variable representing size of battleship board (10x10)
		Board* p1Board; //Pointer to instance of Board class that represents Player 1's board
		Board* p2Board; //Pointer to instance of Board class that represents Player 2's board
		bool PTurn; //Boolean variable keeps track of which player's turn it is at any given time.

        std::string level; //AI level - 1. Easy, 2: Medium, 3: Hard
        
        bool previousHit;   //the previous is hit -> the next shot will be adjacency
        int previousRow;    //previous row
        int previousCol;    //previous col

	public:
    		/*----------
     		* @pre numShips >=1 && <= 5
     		* @post constructor creates an instance of the Executive class
     		* @param int numShips (1-5, chosen # of battleships for first player)
     		* @return no true return, just creates instance of the class
     		* -------*/
    		Executive(int numShips);

		/*----------
     		* @pre an instance of Executive class must exist to be deleted
     		* @post Executive class instance is deleted
     		* @param none
     		* @return none, just deleted instance of class
     		* -------*/
    		~Executive();

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
     		* @pre must input an std::string
     		* @post checks to see whether the given location is valid in reference to board size and description
     		* @param std::string input, the string representing the desired location on board
     		* @return std::string, representation as to whether or not a valid location was chosen
     		* -------*/
    		std::string validateLoc(std::string input);

		/*----------
	  		* @pre must input an std::string
     		* @post checks to see if a given string input is valid
		   	* @param std::string input, the string to check validity
		    * @return bool, to determine if the string is valid or not
			* -------*/
			bool checkInput(std::string input);
     		
		/*----------
     		* @pre char input must be V (for vertical) or H (for horizontal) for meaningful orientation
     		* @post orients ship on board in accordance with selection, can be horizontal or vertical
     		* @param char input (V or H)
     		* @return char representing chosen orientation
     		* -------*/
    		char validateDirection(char input);

            /*----------
                * @pre
                * @post
                * @param Board* board (pointer to player's board) and int numShips (# of ships chosen for play)
                * @return none - void function
                * -------*/
            void chooseRandomShipLoc(Board* board, int numShips);  //new code added

            /*----------
            * @pre must input an std::string
            * @post checks to see whether the level of AI location is valid
            * @param std::string input, the string representing the level
            * @return std::string, representation as to whether or not a valid level was chosen
            * -------*/
            std::string validateLevel(std::string input);  //new code added

            /*----------
            * @pre must input an std::string
            * @post checks to see whether the given location is valid in reference to board size and description
            * @param std::string input, the string representing the desired location on board
            * @return std::string, representation as to whether or not a valid location was chosen
            * -------*/
            std::string validateAILoc(std::string input, Board* board, Board* opBoard);  //new code added
};

#endif
