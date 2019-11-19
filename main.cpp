// tictactoe 0.1 Alpha by Artem B.
#include <iostream>
#include <string>
using namespace std;

string coord[3][3] = { {"0,0","0,1","0,2"},{"1,0","1,1","1,2"},{"2,0","2,1","2,2"} }; // Main 2d array for the game, i'll regret declaring it as a global var later

void init(), reset(); // functions' prototypes
int checkWin();
string confirm; // string to confirm if the player wants a rematch (see ln 129)

int main() {
rematch: // Rematch goto (see ln 134)
	reset(); // Using reset function when going to rematch:

	int coord1, coord2, over = 0; // declaring local vars to operate with

	while (over != 9) { // Main while loop which contains two smaller while loops for player rotation
		while (true) {

			init();

			cout << "Player 1 (X): " << endl;
		cin_coord1_X:

			cout << "Coord 1: ";
			cin >> coord1;
			if (coord1 > 2 || coord1 < 0) {
				cout << "Invalid input" << endl;
				system("pause");
				init();
				goto cin_coord1_X;
			}
		cin_coord2_X:

			cout << "Coord 2: ";
			cin >> coord2;

			if (coord2 > 2 || coord2 < 0) {
				cout << "Invalid input" << endl;
				system("pause");
				init();
				goto cin_coord2_X;
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

			init();

		}

		init();

		if (over == 9) {
			cout << "You are out of turns. Draw." << endl;
			break;
		}

		while (true) {
			init();

			cout << "Player 2 (O): " << endl;

		cin_coord1_O:

			cout << "Coord 1: ";
			cin >> coord1;
			if (coord1 > 2 || coord1 < 0) {
				cout << "Invalid input" << endl;
				system("pause");
				init();
				goto cin_coord1_O;
			}
		cin_coord2_O:

			cout << "Coord 2: ";
			cin >> coord2;

			if (coord2 > 2 || coord2 < 0) {
				cout << "Invalid input" << endl;
				system("pause");
				init();
				goto cin_coord2_O;
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
					goto propose;
				}

				else
					break;
			}

			init();
		}

		init();

		if (over == 9) {
			cout << "You are out of turns. Draw." << endl;
			break;
		}
	}
propose:

	cout << "Want to rematch? (y/n): ";
	cin >> confirm;

	if (confirm == "y" || confirm == "Y") {
		
		goto rematch;
	}

	return 0;
}

void init() { // Main menu (board) for the game
	system("cls"); // Clears the console
	cout << "tictactoe Alpha 0.1\n\n";
	cout << "By Artem B.\n\n\n";

	cout << "Player 1 (X)  -  Player 2 (O)" << endl << endl;
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