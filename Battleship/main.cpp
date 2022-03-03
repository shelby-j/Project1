/*-------------------------------------------------------
 *      File Name: main.cpp
 *      Authors: Alice Kuang, Thresa Kelly, Minwoo Lee, Justin Sizoo, Maggie Swartz (Group #14)
 *      Assignment: EECS_448 Project #1
 *      Description: This is the main.cpp file that triggers all program functionality/begins battleship
 *      Date Last Modified: 02/12/2022
 *-----------------------------------------------------*/

#include "Executive.h"
#include "AI.h"

using namespace std;
//void welcomeMsg() {
//    cout << "\n\nWelcome to Battleship!\n\n";
//    cout << "Select your ships and take turns guessing your opponents' ship locations.\n";
//    cout << "First player to sink all their opponent's ships wins.\n\n";
//}

int main(int argc, char* argv[]) { //To run the program, user must enter ./Battleship and the number of ships they'd like to play with.
	//welcomeMsg();
	if (argc != 2)
	{ //If the user does not enter 2 arguments into the command line, the below error message will display.
			cout << "Invalid number of parameters! To run the program, enter ./Battleship followed by the number of desired ships (1, 2, 3, 4, or 5).\n";
	}
	else //When the user has etered ./Battleship and a second argument into the command line, they enter the below if/else loop.
	{
		if (atoi(argv[1]) < 1 || atoi(argv[1]) > 5)	{ //If 2nd argument converted to an integer is not between 1 and 5 inclusive, display error message.
		cout << "Invalid number of ships! Must be 1, 2, 3, 4, or 5.\n";
		}
		else //If the 2nd argument converted to an integer is between 1 and 5 inclusive...
		{
			//prompt menu for user to choose
			char mode;
			cout<<"Choose your mode\n";
			cout<<"A. Against your friend\nB. Against AI\n";
			cin>>mode;
			while (mode != 'A' && mode != 'B') {
				cout<<"Invalid input. Please choose again (A/B): ";
				cin>>mode;
			}
			if (mode == 'A') {
				int numShips = atoi(argv[1]); //Sets the variable integer numShips equal to the 2nd argument converted to an integer.
				cout << "\nNumber of ships selected for Player 1: " << numShips << "\n"; //Displays number of ships the first player has selected.
				Executive exec(numShips); //Creates an instance of the Executive class called exec, with numShips passed in as the argument.
				exec.run(); //Triggers run function within created instance of the Executive class.
			}
			else if (mode == 'B') 
			{
				int numShips = atoi(argv[1]);
				cout << "\nNumber of ships selected: " << numShips << "\n";
				AI ai(numShips);
				ai.run();
			}
			
		}
	}
	return (0);
}
