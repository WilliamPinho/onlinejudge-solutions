#include <iostream>
#include <cctype>
#include <algorithm>

using namespace std;

bool attacked[8][8];
char b[8][8];

void markBishop(int row, int col) {
	for(int i = row+1, j = col+1; i < 8 && j < 8 && b[i][j] == ' '; ++i, ++j) attacked[i][j] = true;
	for(int i = row-1, j = col+1; i > -1 && j < 8 && b[i][j] == ' '; --i, ++j) attacked[i][j] = true;
	for(int i = row+1, j = col-1; i < 8 && j > -1 && b[i][j] == ' '; ++i, --j) attacked[i][j] = true;
	for(int i = row-1, j = col-1; i > -1 && j > -1 && b[i][j] == ' '; --i, --j) attacked[i][j] = true;
}

void markRook(int row, int col) {
	for(int j = col + 1; j < 8 && b[row][j] == ' '; ++j) attacked[row][j] = true;
	for(int j = col - 1; j > -1 && b[row][j] == ' '; --j) attacked[row][j] = true;
	for(int i = row + 1; i < 8 && b[i][col] == ' '; ++i) attacked[i][col] = true;
	for(int i = row - 1; i > -1 && b[i][col] == ' '; --i) attacked[i][col] = true;
}

void markKnight(int row, int col) {
	if(row-2 > -1 && col-1 > -1) attacked[row-2][col-1] = true;
	if(row-2 > -1 && col+1 < 8) attacked[row-2][col+1] = true;
	if(row-1 > -1 && col-2 > -1) attacked[row-1][col-2] = true;
	if(row-1 > -1 && col+2 < 8) attacked[row-1][col+2] = true;
	if(row+2 < 8 && col+1 < 8) attacked[row+2][col+1] = true;
	if(row+2 < 8 && col-1 > -1) attacked[row+2][col-1] = true;
	if(row+1 < 8 && col-2 > -1) attacked[row+1][col-2] = true;
	if(row+1 < 8 && col+2 < 8) attacked[row+1][col+2] = true;
}

void markQueen(int row, int col) {
	markBishop(row, col);
	markRook(row,col);
}

void markKing(int row, int col) {
	if(row-1 > -1) {
		if(col-1 > -1) attacked[row-1][col-1] = true;
		attacked[row-1][col] = true;
		if(col+1 < 8) attacked[row-1][col+1] = true;
	}
	if(col-1 > -1) attacked[row][col-1] = true;
	if(col+1 < 8) attacked[row][col+1] = true;
	if(row+1 < 8) {
		if(col-1 > -1) attacked[row+1][col-1] = true;
		attacked[row+1][col] = true;
		if(col+1 < 8) attacked[row+1][col+1] = true;
	}
}

void markPawn(int row, int col, bool isBlackPawn) {
	if(isBlackPawn && row+1 != 8) {
		if(col-1 > -1) attacked[row+1][col-1] = true;
		if(col + 1 < 8) attacked[row+1][col+1] = true;
	} 
	if(!isBlackPawn && row-1 != -1) {
		if(col-1 > -1) attacked[row-1][col-1] = true;
		if(col + 1 < 8) attacked[row-1][col+1] = true;
	} 
}

void markAttacked(char piece, int row, int col) {
	attacked[row][col] = true;
	bool isBlackPawn = piece == 'p';
	piece = tolower(piece);
	switch(piece) {
		case 'r': markRook(row, col); break;
		case 'b': markBishop(row, col); break;
		case 'n': markKnight(row, col); break;
		case 'q': markQueen(row, col); break;
		case 'k': markKing(row, col); break;
		default: markPawn(row, col, isBlackPawn);
	}
}

int countNonAttacked() {
	int count = 0;
	for(int i = 0; i < 8; ++i) 
		for(int j = 0; j < 8; ++j) 
			if(!attacked[i][j]) 
				count++;
	return count;
}


int main() {
	string line;
	ios::sync_with_stdio(false);
	while(cin >> line) {
		for(int i = 0; i < 8; ++i) {
			fill(attacked[i], attacked[i] + 8, false);
			fill(b[i], b[i] + 8, ' ');
		}
		int row = 0, col = 0;
		char c;
		for(int i = 0; i < line.length(); ++i) {
			c = line[i];
			if(isdigit(c)) fill(b[row] + col, b[row] + col + (c - '0'), ' '), col += c - '0';
			else if(isalpha(c)) b[row][col++] = c;
			if(c == '/') { col = 0, row++; }
		}
		for(int i = 0; i < 8; ++i) 
			for(int j = 0; j < 8; ++j) 
				if(b[i][j] != ' ') 
					markAttacked(b[i][j], i, j);
		cout << countNonAttacked() << endl;
	}
	return 0;
}