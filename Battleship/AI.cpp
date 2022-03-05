#include "AI.h"
#include <limits>
#include <iostream>
#include <cctype>
using namespace std;

AI::AI(int numShips) { //Constructor for AI class, takes in selected number of ships as a parameter.
	m_size = 10; //Sets member variable m_size equal to 10 (creation of 10x10 playing board.
	PTurn = false; //Variable PTurn keeps track of which player's turn it is, starts at false so Player 1 will go first when gameplay begins.
    letters = "abcdefghik";
    p1Board = new Board(m_size, "Player 1"); //Creates instance of Board class for Player 1, takes in m_size and name "Player 1" as parameters.
	AIBoard = new Board(m_size, "AI"); //Creates instance of Board class for Player 2, take in m_size and name "Player 2" as parameters.
	p1Board->printBoard("Initial"); //Prints out initial board prior to ship location selection.
	 chooseShipLoc(p1Board, numShips); //Player 1 places their ships on their board w/ selected number of ships.
	AIBoard->printBoard("Initial"); //Prints out initial board prior to ship location sleection.
	AIsetup(AIBoard, numShips); //Player 2 places their ships on their board w/ selected number of ships.
}

AI::~AI() { //Destructor for the AI class.
	delete p1Board; //Deletes instance of Board class associated with Player 1.
	delete AIBoard; //Deletes instance of Board class associated with Player 2.
}

void AI::run() { //Void run function enables all gameplay functionality.
	int lv;
    lv = level();
    cout<<lv;

	
    switch(lv) {
        case 1:
           easyLevel();
    //     case 2:
    //         // mediumLevel();

        // case 3: 
			
    //         // hardLevel(player_ship);
    // }
    }
    if (PTurn == 0) {
        cout << "\nGame end: Player " << PTurn+1 << " wins.\n";
    }
    else if (PTurn == 1) {
        cout << "\nGame end: AI wins.\n"; 
    }
}

void AI::playerSwitch() {
	char confirm;
	cout << "Press the Y key to confirm player switch: ";
	cin >> confirm;
	while (cin.fail() || (confirm != 'Y' && confirm != 'y')) { //While innapropriate input occurs...
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n'); //Utilize cin.fail and output error message, need correct input to continue.
		cout << "Invalid Input - Press the Y key to confirm player switch: ";
		cin >> confirm; //Retry to get valid input.
	}
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	PTurn = !PTurn; //Update PTurn to move onto the next player and allow them to place their ships or start gameplay.
	cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
	cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
}

void AI::chooseShipLoc(Board* board, int numShips) {//chooseShipLoc function places ships with board pointer and numShips desired as parameters.

	string shipLoc = ""; //Initializes shipLoc to empty string.
	int row = 0; //Initializes row integer to 0.
	int col = 0; //Initializes column integer to 0.
	char temp; //Temp for converting to lowercase
	char direction; //Char variable representing ship direction (orientation).
	bool inserted = false; //Boolean variable keeps track of whether the ship was inserted, initialized to false.
	for (int i = 0; i < numShips; i++) { //For loop traverses desired number of ships.
		while (!inserted) { //While loop continues while the ship has not been inserted successfully.
			cout << "Player " << PTurn+1 << ", Input a location for ship " << i+1 << ": "; //Message directs current player to insert their ship.
			
            shipLoc = validateLoc(shipLoc); //Validate ship location.
			
            if(shipLoc.length() ==3) { //This code is necessary to validate if player wants to insert in row 10.
				row = 9;
				temp = tolower(shipLoc[2]);
				col = charToInt(temp);
			} else { //Valdiating ship location if in rows 1 to 9.
				row = charToInt(shipLoc[0]);
				temp = tolower(shipLoc[1]);
				col = charToInt(temp);
			}
			if (i == 0) {
				direction = 'H'; //If i=0, the first ship is being entered and a direction is not necessary.
			} else { //Else have user input if they want the ship oriented horizontally or vertically.
				cout << "Input a direction ('H' for horizontal or 'V' for vertical): ";
				direction = validateDirection(direction); //Make sure ship location is still valid with desired orientation.
			}
			if (!board->insertShip(i+1, row, col, direction)) { //If you cannot insert at desired location/orientation, user has to try again.
				cout << "Error - Invalid Location : Ship already exists here or extends outside board. Try again\n"; //Error message.
			} else {
				inserted = true; //Else, ship was inserted at desired location/orientation successfully!
				board->printBoard("Place"); //Mark the change on the place board.
			}
		} //Closes out while loop.
        inserted = false;
	} //Closes out for loop.
	playerSwitch(); // switch player
    
}

int AI::charToInt(char c) { //charToInt takes in a character and converts that to the ASCII correlated integer value.
	int num = (int)c; //Set num variable equal to (int)c.
	if (num > 71) {
		num -= 97; //ASCII (a-j) is equal to 97 to 107, so subtract off 97 to convert to correct integer value.
	} else {
		num -= 49; //ASCII (1-9)
	}
	
	return num; //Return num integer value.
}

bool AI::checkInput(string input)
{
	bool invalidLength = false; //Boolean value restrictLength initialized to zero (false).
	bool invalidChar = false; //Boolean value validChar initialized to zero (false).
	if(input.length() < 2 || input.length() > 3) invalidLength = true; //Restrict the length to strings of 2 or 3.
	if(input.length() == 2) //i.e. 1 digit followed by 1 letter.
	{
		if (isdigit(input[1])) invalidChar = true;
		int row = charToInt(input[0]); // convert row to int
		char temp = tolower(input[1]);
		int col = charToInt(temp); //convert col to int
		if(row < 0 || row >= 10 || col < 0 || col >= 10) invalidChar = true; //Validate lowercase char case.
	}
	else if(input.length() == 3) //i.e. 2 digit followed by 1 letter.
	{
		if (isdigit(input[2])) invalidChar = true;
		int row1 = charToInt(input[0]); //Index 0 is tens place of row
		int row2 = charToInt(input[1]); //Index 1 is ones place of row
		char temp = tolower(input[2]);
		int col = charToInt(temp); //convert col to int
		if (row1 != 0 || row2 != -1) invalidChar = true; //Row != 10
		if(col < 0 || col >= 10) invalidChar = true; //Validate lowercase char case.
	}
	if (invalidLength || invalidChar) return true;
	else return false;
}

string AI::validateLoc(string input) { //Collects user input for string and ensures it is a valid entry, i.e. follow row-column format.
	cin >> input; //Collect user input.
	bool invalid = checkInput(input);
	while (cin.fail() || invalid) { //While innapropriate input occurs...
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n'); //Utilize cin.fail and output error message, need correct input to continue.
		if (invalid)
		{
			cout << "Your input should specify the row and then column, i.e. 1a. Try again: ";
		}
		cin >> input; //input = validateLoc(input);
		invalid = checkInput(input);
	}
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	return input; //Return string input that has been validated.
}

char AI::validateDirection(char input) { //validateDirection function interprets user input for orientation, returns 'v'(vertical)  or 'h' (horizontal).
    cin >> input; //Takes in user input to determine ship orientation.
    input = tolower(input); //Convets input to lowercase equivalent if not already lowercase (H==h and V==v).
	while (cin.fail() || (input != 'h' && input != 'v')) { //If user input is not h for horizontal or v for vertical...
		cin.clear(); //Using cin.fail functionality...
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Sorry, your input was invalid. Try again: "; //Display error message and give user opportunity to input until acceptable input.
		cin >> input;
		input = tolower(input);
	}
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	return input; //Return input value as 'v' or 'h' to reprsent desired orientation.
}

int AI::level() {
	int lv;
	cout<<"Choose your level (1, 2, 3): \n1. Easy\n2. Medium\n3. Hard";
	cin>>lv;
	while (lv!=1 && lv !=2 && lv != 3) {
		cout<<"Invalid input. Please try again.";
		cout<<"Choose your level (1, 2, 3): \n1. Easy\n2. Medium\n3. Hard";
		cin>>lv;
	}
	return lv;
    
}

void AI::AIsetup(Board* board, int numShips) {
	string shipLoc = ""; //Initializes shipLoc to empty string.
	int row = 0; //Initializes row integer to 0.
	int col = 0; //Initializes column integer to 0.
	char temp; //Temp for converting to lowercase
	char direction; //Char variable representing ship direction (orientation).
	bool inserted = false; //Boolean variable keeps track of whether the ship was inserted, initialized to false.
	for (int i = 0; i < numShips; i++) { //For loop traverses desired number of ships.
		while (!inserted) { //While loop continues while the ship has not been inserted successfully.
			//generate random ship locations
			shipLoc = randomLoc();
			if(shipLoc.length() ==3) { //This code is necessary to validate if player wants to insert in row 10.
				row = 9;
				temp = tolower(shipLoc[2]);
				col = charToInt(temp);
			} else { //Valdiating ship location if in rows 1 to 9.
				row = charToInt(shipLoc[0]);
				temp = tolower(shipLoc[1]);
				col = charToInt(temp);
			}
			if (i == 0) {
				direction = 'H'; //If i=0, the first ship is being entered and a direction is not necessary.
			} else { //generate random between V and H
				char dr[] ={'V','H'};
				direction = dr[(rand() % 2)]; //Make sure ship location is still valid with desired orientation.
			}

			if (!board->insertShip(i+1, row, col, direction)) { //If you cannot insert at desired location/orientation, user has to try again.
				continue;
			} else {
				inserted = true; //Else, ship was inserted at desired location/orientation successfully!
				board->printBoard("Place"); //Mark the change on the place board.
			}
		} 
        inserted = false;
	} 
	playerSwitch();
}

//function return random location generated by AI
string AI::randomLoc() {
	int row = (rand() % 10) +1 ; //randomly pick a number for row
    char col = letters[(rand() % 10)];
	string s_col(1,col); //randomly choose the column to start
    string shipLoc = to_string(row) + s_col;
	return shipLoc;
}



void AI::easyLevel(){
	Board* board = p1Board; //Creates a pointer to Board instance p1Board (Player 1).
	Board* opBoard = AIBoard; //Creates a pointer to Board instance opBoard (Player 2).
	while (true) {
		string shot = ""; //Initializes string shot to an empty string.
        int row = 0; //Initializes row location integer to 0.
		int col = 0; //Initializes column location integer to 0.
		char tmp; //temp to convert to lowercase
		board->printBoard("Place");
		board->printBoard("Shot"); //Print the updated shotGrid.
		if (PTurn==0) {
			cout << "Take your shot: ";
			shot = validateLoc(shot); //Validate shot location.
			
			if (shot.length() == 3) { //If function helps to process shot location if in row 10 (legnth is 3 due to char + 10).
				row = 9; //If we are in row = 10...
				tmp = tolower(shot[2]);
				col = charToInt(tmp); //Then correctly convert to integer to identify appropriate location.
			} else { //Else if we are in rows 1-9...
				row = charToInt(shot[0]); //Convert string to appropriate location identification.
				tmp = tolower(shot[1]);
				col = charToInt(tmp);
			}
			while (!board->validShot(row, col)) { //Ensure that shot isn't in same position
				cout << "Error - you have already shot at this location, take your shot again: ";
				shot = validateLoc(shot);
				if (shot.length() == 3) { //If function helps to process shot location if in row 10 (legnth is 3 due to char + 10).
					row = 9; //If we are in row = 10...
					tmp = tolower(shot[2]);
					col = charToInt(tmp); //Then correctly convert to integer to identify appropriate location.
				} else { //Else if we are in rows 1-9...
					row = charToInt(shot[0]); //Convert string to appropriate location identification.
					tmp = tolower(shot[1]);
					col = charToInt(tmp);
				}
			}

			if (board->shootShot(row, col, opBoard)) { //Check to see if there was a hit or miss at shot location.
				if (opBoard->sinkStatus(row, col)) { //See if this shot resulted in the sinking of a ship...
					cout << "SUNK!\n\n"; //If it did, output message indicating sunk status.
				} else cout << "HIT!\n\n"; //If not sunk, but a hit did occur, then issue message indicating hit status.

				if (opBoard->checkWin()) { //Check to see if this round of gameplay resulted in a winner.
					board->printBoard("Shot");
					break;
				}
			} else { //Else, a hit did not occur in this round of gameplay.
				cout << "MISS!\n\n"; //Output message indicating a miss occured.
				board->printBoard("Shot"); //Print shot board.
				Board* temp = board; //Create temp board.
				board = opBoard; //Set equal to opponent's board.
				opBoard = temp; //Set opponent's board equal to temp.
				playerSwitch();
			}
		}

		if (PTurn == 1) {
			string shot = randomLoc();
			if (shot.length() == 3) { //If function helps to process shot location if in row 10 (legnth is 3 due to char + 10).
				row = 9; //If we are in row = 10...
				tmp = tolower(shot[2]);
				col = charToInt(tmp); //Then correctly convert to integer to identify appropriate location.
			} else { //Else if we are in rows 1-9...
				row = charToInt(shot[0]); //Convert string to appropriate location identification.
				tmp = tolower(shot[1]);
				col = charToInt(tmp);
			}
			while (!board->validShot(row, col)) { //Ensure that shot isn't in same position
				shot = randomLoc();
				if (shot.length() == 3) { //If function helps to process shot location if in row 10 (legnth is 3 due to char + 10).
					row = 9; //If we are in row = 10...
					tmp = tolower(shot[2]);
					col = charToInt(tmp); //Then correctly convert to integer to identify appropriate location.
				} else { //Else if we are in rows 1-9...
					row = charToInt(shot[0]); //Convert string to appropriate location identification.
					tmp = tolower(shot[1]);
					col = charToInt(tmp);
				}
			}

			//shooting part
			if (board->shootShot(row, col, opBoard)) { //Check to see if there was a hit or miss at shot location.
				if (opBoard->sinkStatus(row, col)) { //See if this shot resulted in the sinking of a ship...
					cout << "SUNK!\n\n"; //If it did, output message indicating sunk status.
				} else cout << "HIT!\n\n"; //If not sunk, but a hit did occur, then issue message indicating hit status.

				if (opBoard->checkWin()) { //Check to see if this round of gameplay resulted in a winner.
					board->printBoard("Shot");
					break;
				}
			}
			else { //Else, a hit did not occur in this round of gameplay.
				cout << "MISS!\n\n"; //Output message indicating a miss occured.
				board->printBoard("Shot"); //Print shot board.
			}
			Board* temp = board; //Create temp board.
			board = opBoard; //Set equal to opponent's board.
			opBoard = temp; //Set opponent's board equal to temp.
			playerSwitch();
		}
	}
}
