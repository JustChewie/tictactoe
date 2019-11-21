// tictactoe 0.2 Alpha by Artem B.
#include <iostream>
#include <string>
using namespace std;

string coord[3][3] = { {"0,0","0,1","0,2"},{"1,0","1,1","1,2"},{"2,0","2,1","2,2"} }; // Main 2d array for the game, i'll regret declaring it as a global var later

void init(), reset(); // functions' prototypes
void cinFail(int &fcoord, string fplayer, int fcounter);
int checkWin();
string confirm; // string to confirm if the player wants a rematch (see ln 129)

int main() {
rematch: // Rematch goto (see ln 134)
	reset(); // Using reset function when going to rematch:

	int coord1, coord2, over = 0; // declaring local vars to operate with

	while (over != 9) { // Main while loop which contains two smaller while loops for player rotation
		while (true) {
			
			int coordCounter = 1;
			string playername = "Player 1 (X)";
			init();
			
			cout << playername << ":" << endl;
			cout << "Coord " << coordCounter << ": ";
			cin >> coord1;

			if (coord1 > 2 || coord1 < 0) {
				cinFail(coord1, playername, coordCounter);
			}

			else {
				init();
			}

			coordCounter++;

			cout << playername << ":" << endl;
			cout << "Coord " << coordCounter << ": ";
			cin >> coord2;

			if (coord2 > 2 || coord2 < 0) {
				cinFail(coord2, playername, coordCounter);
			}

			if (coord[coord1][coord2] == " X " || coord[coord1][coord2] == " O ") {
				cout << "You can't use this square" << endl;
				system("pause");
			}

			else {
				coord[coord1][coord2] = " X ";
				over++;
				init();
				if (checkWin() == 1) {
					goto propose;
				}
				else 
					break;
			}

			//init();

		}

		//init();

		if (over == 9) {
			cout << "You are out of turns. Draw." << endl;
			break;
		}

		while (true) {
			int coordCounter = 1;
			string playername = "Player 2 (O)";
			init();

			cout << playername << ":" << endl;
			cout << "Coord " << coordCounter << ": ";
			cin >> coord1;

			if (coord1 > 2 || coord1 < 0) {
				cinFail(coord1, playername, coordCounter);
			}

			else {
				init();
			}
			coordCounter++;

			cout << playername << ":" << endl;
			cout << "Coord " << coordCounter << ": ";
			cin >> coord2;

			if (coord2 > 2 || coord2 < 0) {
				cinFail(coord1, playername, coordCounter);
			}

			if (coord[coord1][coord2] == " X " || coord[coord1][coord2] == " O ") {
				cout << "You can't use this square" << endl;
				system("pause");
			}

			else {
				coord[coord1][coord2] = " O ";
				over++;
				init();
				if (checkWin() == 1) {
					goto propose; // see ln 127
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
propose: // Label propose (see ln 56, 110)

	cout << "Want to rematch? (y/n): "; // Asking the player if he wants to rematch
	cin >> confirm;

	if (confirm == "y" || confirm == "Y") { // If the player types 'y' or 'Y' then executing goto
		
		goto rematch; // Going to rematch (see ln 13)
	}

	return 0;
}

void init() { // Main menu (board) for the game
	system("cls"); // Clears the console
	cout << "tictactoe Alpha 0.1\n\n"; // Name of the project
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
		winX++; // If the combo is true then winX++ (see ln 193)
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
		winO++; // If the combo is true then winO++ (see ln 199)
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

void cinFail(int &fcoord, string fplayer, int fcounter) {
	cout << "Invalid input" << endl;
	system("pause");
	init();
	while (fcoord > 2 || fcoord < 0) {
		cout << fplayer << ":" << endl;
		cout << "Coord " << fcounter << ": ";
		cin >> fcoord;
		if (fcoord > 2 || fcoord < 0) {
			cout << "Invalid input" << endl;
			system("pause");
		}
		init();
	}
	
}