// tictactoe 0.3 Alpha by Artem B.
#include <iostream>
#include <string>
using namespace std;

string coord[3][3] = { {"0,0","0,1","0,2"},{"1,0","1,1","1,2"},{"2,0","2,1","2,2"} }; // Main 2d array for the game, i'll regret declaring it as a global var later

void init(), reset(), propose(); // Initialize board, reset board and offer a rematch
void cinFail(int &fcoord, string fplayer, int fcounter, int exception); // This function deals with the bad cins (asks to re-enter)
int checkWin(); // Function to check if the player won (executes every time after placing a symbol)
string confirm; // string to confirm if the player wants a rematch

int main() {

	int coord1, coord2, over = 0; // declaring local vars to operate with

	reset(); // Using reset function to reset the array

	while (over != 9) { // Main while loop which contains two smaller while loops for player rotation
		while (true) { // Player X turn loop

			int coordCounter = 1; // Counter for coordinates
			string playername = "Player 1 (X)"; // The name of the player (easier to use variables)
			init(); // Updating the board

			cout << playername << ":" << endl; 
			cout << "Coord " << coordCounter << ": ";
			cin >> coord1;

			try { // Using try..catch to throw an exception #1 and output it as an error
				if (coord1 > 2 || coord1 < 0 || cin.fail()) { // in case if coord1 > 2 or coord1 < 0 or is not an integer exception is thrown and cinFail is executed
					throw 1;
				}
			}
			catch (int e) {
				cinFail(coord1, playername, coordCounter, e);
			}

			init();
			coordCounter++; // To the next coordinate

			cout << playername << ":" << endl;
			cout << "Coord " << coordCounter << ": ";
			cin >> coord2;

			try { // Same scheme for dealing with cin.fail() and other bad stuff
				if (coord2 > 2 || coord2 < 0 || cin.fail()) {
					throw 2;
				}
			}
			catch (int e) {
				cinFail(coord2, playername, coordCounter, e);
			}

			if (coord[coord1][coord2] == " X " || coord[coord1][coord2] == " O ") { // Checking if the square is not occupied
				cout << "You can't use this square" << endl;
				system("pause");
			}

			else {
				coord[coord1][coord2] = " X "; // If it is not, setting the square value to "X"
				over++; // Incrementing over (when over == 9 game ends because there are only 9 squares)
				init();
				if (checkWin() == 1) { // Checking if the player has won
					propose(); // If yes then executing propose function 
				}
				else // If not just carry on
					break;
			}

			//init();

		}

		//init();

		if (over == 9) { // If variable equals to 9 then all the squares are occupied
			cout << "You are out of turns. Draw." << endl;
			break; // Exit the loop
		}

		while (true) { // Almost the same loop but for the second player
			int coordCounter = 1;
			string playername = "Player 2 (O)";
			init();

			cout << playername << ":" << endl;
			cout << "Coord " << coordCounter << ": ";
			cin >> coord1;

			try { // Using try to throw an exception and use cinFail() to deal with bad inputs
				if (coord1 > 2 || coord1 < 0 || cin.fail()) {
					throw 1;
				}
			}
			catch (int e) {
				cinFail(coord1, playername, coordCounter, e);
			}

			init();
			coordCounter++; // On to the next coordinate!

			cout << playername << ":" << endl;
			cout << "Coord " << coordCounter << ": ";
			cin >> coord2;

			try { // Using try to throw an exception and use cinFail() to deal with bad inputs
				if (coord2 > 2 || coord2 < 0 || cin.fail()) {
					throw 2;
				}
			}
			catch (int e) {
				cinFail(coord2, playername, coordCounter, e);
			}

			if (coord[coord1][coord2] == " X " || coord[coord1][coord2] == " O ") { // Checking if the square is not occupied
				cout << "You can't use this square" << endl;
				system("pause");
			}

			else {
				coord[coord1][coord2] = " O "; // If it is not, setting the square value to "O"
				over++; // Incrementing over (when over == 9 game ends because there are only 9 squares)
				init();
				if (checkWin() == 1) { // Checking if the player has won
					propose(); // Executing propose()
				}

				else
					break;
			}

			//init();
		}

		//init();

		if (over == 9) { // Reserve if statement for 100% end of the loop
			cout << "You are out of turns. Draw." << endl;
			break; // breaking the loop
		}
	}

	return 0;
}

void init() { // Main menu (board) for the game
	system("cls"); // Clears the console
	cout << "tictactoe Alpha 0.3\n\n"; // Name of the project
	cout << "By Artem B.\n\n\n"; // My info

	cout << "Player 1 (X)  -  Player 2 (O)" << endl << endl; // The board itself
	cout << endl;
	cout << "     |     |     " << endl;
	cout << " " << coord[0][0] << " | " << coord[0][1] << " | " << coord[0][2] << endl;
	cout << "_____|_____|_____" << endl;
	cout << "     |     |     " << endl;
	cout << " " << coord[1][0] << " | " << coord[1][1] << " | " << coord[1][2] << endl;
	cout << "_____|_____|_____" << endl;
	cout << "     |     |     " << endl;
	cout << " " << coord[2][0] << " | " << coord[2][1] << " | " << coord[2][2] << endl;
	cout << "     |     |     " << endl << endl;
}

int checkWin() {
	int winX = 0, winO = 0;

	if (coord[0][0] == " X " && coord[0][1] == " X " && coord[0][2] == " X ") // Winning combos for player X
		winX++; // If the combo is true then winX++ (see ln 202)
	if (coord[1][0] == " X " && coord[1][1] == " X " && coord[1][2] == " X ")
		winX++;
	if (coord[2][0] == " X " && coord[2][1] == " X " && coord[2][2] == " X ")
		winX++;
	if (coord[0][0] == " X " && coord[1][0] == " X " && coord[2][0] == " X ")
		winX++;
	if (coord[0][1] == " X " && coord[1][1] == " X " && coord[2][1] == " X ")
		winX++;
	if (coord[0][2] == " X " && coord[1][2] == " X " && coord[2][2] == " X ")
		winX++;
	if (coord[0][0] == " X " && coord[1][1] == " X " && coord[2][2] == " X ")
		winX++;
	if (coord[0][2] == " X " && coord[1][1] == " X " && coord[2][0] == " X ")
		winX++;

	if (coord[0][0] == " O " && coord[0][1] == " O " && coord[0][2] == " O ") // Winning combos for player O
		winO++; // If the combo is true then winO++ (see ln 208)
	if (coord[1][0] == " O " && coord[1][1] == " O " && coord[1][2] == " O ")
		winO++;
	if (coord[2][0] == " O " && coord[2][1] == " O " && coord[2][2] == " O ")
		winO++;
	if (coord[0][0] == " O " && coord[1][0] == " O " && coord[2][0] == " O ")
		winO++;
	if (coord[0][1] == " O " && coord[1][1] == " O " && coord[2][1] == " O ")
		winO++;
	if (coord[0][2] == " O " && coord[1][2] == " O " && coord[2][2] == " O ")
		winO++;
	if (coord[0][0] == " O " && coord[1][1] == " O " && coord[2][2] == " O ")
		winO++;
	if (coord[0][2] == " O " && coord[1][1] == " O " && coord[2][0] == " O ")
		winO++;

	if (winX == 1) { // If winX == 1 then the function prints and returns value 1
		cout << "Player 1 (X) wins!" << endl;
		system("pause");
		return 1;
	}

	if (winO == 1) { // If winO == 1 then the function prints and returns value 1
		cout << "Player 2 (O) wins!" << endl;
		system("pause");
		return 1;
	}

	return 0; // If none of the two ifs is true then the function returns 0 
}

void reset() { // Reset function for the main array because it is a global variable (damn) and rematching (couldn't think of anything better)
	coord[0][0] = "0,0";
	coord[0][1] = "0,1";
	coord[0][2] = "0,2";
	coord[1][0] = "1,0";
	coord[1][1] = "1,1";
	coord[1][2] = "1,2";
	coord[2][0] = "2,0";
	coord[2][1] = "2,1";
	coord[2][2] = "2,2";
}

void cinFail(int &fcoord, string fplayer, int fcounter, int exception) { // One of the most important functions in the game, it deals with bad inputs
	cout << "Invalid input" << endl;
	cout << "Exception #: " << exception << endl; // Output the number of exception
	system("pause");
	init();

	while (fcoord > 2 || fcoord < 0 || cin.fail()) { // Executing while loop to check if the input is changed to a good one
		cout << fplayer << ":" << endl;
		cout << "Coord " << fcounter << ": ";
		cin.clear(); // Clearing the bad flag on cin, so we can use cin further
		cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignoring the rest of the line 
		cin >> fcoord;
		if (fcoord > 2 || fcoord < 0 || cin.fail()) { // Almost the same thing, I made it just for the output of "Invalid input", other way it's not needed
			cout << "Invalid input" << endl;
			cout << "Exception #: " << exception << endl;
			system("pause");
		}
		init(); // Initializing the board again
	}
	
}

void propose() {
	cout << "Want to rematch? (y/n): "; // Asking the player if he wants to rematch
	cin >> confirm;

	if (confirm == "y" || confirm == "Y") {

		reset(); // Resetting the board and executing the loops once again
	}

	else if (confirm == "n" || confirm == "N") {
		exit(0); // Exiting the program with 0 code
	}
}