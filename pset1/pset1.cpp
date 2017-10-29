//============================================================================
// Name        : pset1.cpp
// Author      : Jimmy
// Description : Find string pattern in matrix
//============================================================================
#include <iostream>
#include <sstream>
#include <string>
#include <typeinfo>

using namespace std;

// initial setting
#define maxRows 10
#define maxCols 10

// Arrays use for change n, e, w, s directions
int rowNum[] = { -1, 0, 0, 1 };
int colNum[] = { 0, -1, 1, 0 };

char matrix[maxRows][maxCols];
string anslis;

void FindPattern(string word, char* reused);
bool move_checker(int row, int col, int prevRow, int prevCol);
void move_operator_T(char matrix[][maxCols], string word, int n);
void DFS_T(char matrix[][maxCols], int row, int col, int prevRow, int prevCol,
		string word, string path, int index, int n);
void move_operator_F(char matrix[][maxCols], string word, int n);
void DFS_F(char matrix[][maxCols], int row, int col, int prevRow, int prevCol,
		string word, string path, int index, int n);

int main() {
	for (int row = 0; row < maxRows; row++) {
		stringstream ss1;
		ss1 << "Row: ";
		ss1 << row + 1;
		cout << ss1.str() << " > " << flush;
		string input;
		cin >> input;
		while (input.size() != maxCols) {
				cout << "Input format error!" << endl;
				cout << "Max length: " << maxCols << endl;
				cout << ss1.str() << " > " << flush;
				cin >> input;
			}
		for (int col = 0; col < maxCols; col++) {
			matrix[row][col] = input[col];
		}
	}

	//	Show matrix
	cout << endl;
	cout << "[Your matrix]" << endl;
	cout << "=============" << endl;
	for (int row = 0; row < maxRows; row++) {
		for (int col = 0; col < maxCols; col++) {
			cout << matrix[row][col] << " " << flush;
		}
		cout << endl;
	}
	cout << "=============" << endl;
	bool replay = true;
	while (replay) {
		// reused check
		anslis = "";
		char reused;
		cout << "Do you want element to be reused? (Y/N)" << endl;
		cout << "> " << flush;
		char ans_reuse;
		cin >> ans_reuse;

		if (ans_reuse == 'Y' || ans_reuse == 'y') {
			cout << "===== You can reuse element! =====" << endl;
			reused = 'T';
		} else if (ans_reuse == 'N' || ans_reuse == 'n') {
			cout << "===== You can't reuse element! =====" << endl;
			reused = 'F';
		} else {
			cout << "===== Input error, shut down =====" << endl;
			return 0;
		}

		//	Enter pattern
		string patt;
		cout << "Enter check pattern" << endl;
		cout << "> " << flush;
		cin >> patt;

		while (patt.size() > 10) {
			cout << "Pattern length can't exceed 10, re-enter!" << endl;
			cout << "Enter check pattern" << endl;
			cout << "> " << flush;
			cin >> patt;
		}

		FindPattern(patt, &reused);

		if (anslis == "") {
			cout << "no match" << endl;
		}

		//	Re-enter pattern?
		cout << "Replay? (Y/N)" << endl;
		cout << "> " << flush;
		char ans_replay;
		cin >> ans_replay;
		cout << "=============" << endl;
		if (ans_replay == 'N' || ans_replay == 'n') {
			replay = false;
			cout << "Shut down" << endl;
		} else if (ans_replay == 'Y' || ans_replay == 'y') {
			replay = true;
		} else {
			cout << "===== Input error, shut down =====" << endl;
			return 0;
		}
	}
	return 0;
}

void FindPattern(string word, char* reused) {
	if (*reused == 'T') {
		move_operator_T(matrix, word, word.size() - 1);
	} else {
		move_operator_F(matrix, word, word.size() - 1);
	}
}

// Check n,e,w,s direction's accessibility
bool move_checker(int row, int col, int prevRow, int prevCol) {
	return (row >= 0) && (row < maxRows) && (col >= 0) && (col < maxCols)
			&& !(row == prevRow && col == prevCol);
}

/*
 * reused = True case
 */
void move_operator_T(char matrix[][maxCols], string word, int n) {
	// traverse through the all cells of given matrix
	for (int i = 0; i < maxRows; i++) {
		for (int j = 0; j < maxCols; j++) {
			// occurrence of first character in matrix
			if (matrix[i][j] == word[0]) {
				// check and print if path exists
				DFS_T(matrix, i, j, -1, -1, word, "", 0, n);
			}
		}
	}
}

// Depth-first-search
void DFS_T(char matrix[][maxCols], int row, int col, int prevRow, int prevCol,
		string word, string path, int index, int n) {
	if (index > n || matrix[row][col] != word[index])
		return;

	//append current location for matched return
	path += "(" + to_string(row) + "," + to_string(col) + ") ";

	if (index == n) {
		cout << path << endl;
		anslis += path;
	}

	// Recur for n, e, w, s neighbors
	for (int k = 0; k < 4; k++) {
		if (move_checker(row + rowNum[k], col + colNum[k], prevRow, prevCol)) {
			DFS_T(matrix, row + rowNum[k], col + colNum[k], row, col, word,
					path, index + 1, n);
		}
	}
}

/*
 * reused = False case
 */

void move_operator_F(char matrix[][maxCols], string word, int n) {
	// traverse through the all cells of given matrix
	for (int i = 0; i < maxRows; i++) {
		for (int j = 0; j < maxCols; j++) {
			// occurrence of first character in matrix
			if (matrix[i][j] == word[0]) {
				// check and print if path exists
				DFS_F(matrix, i, j, -1, -1, word, "", 0, n);
			}
		}
	}
}

// Depth-first-search
void DFS_F(char matrix[][maxCols], int row, int col, int prevRow, int prevCol,
		string word, string path, int index, int n) {
	if (index > n || matrix[row][col] != word[index])
		return;
	// check whether a point is reused
	string reuse = "(" + to_string(row) + "," + to_string(col) + ") ";
	if (path.find(reuse) != std::string::npos) {
		return;
	}

	//append current location for matched return
	path += "(" + to_string(row) + "," + to_string(col) + ") ";

	if (index == n) {
		cout << path << endl;
		anslis += path;
	}

	// Recur for n, e, w, s neighbors
	for (int k = 0; k < 4; k++) {
		if (move_checker(row + rowNum[k], col + colNum[k], prevRow, prevCol)) {
			DFS_F(matrix, row + rowNum[k], col + colNum[k], row, col, word,
					path, index + 1, n);
		}
	}
}
