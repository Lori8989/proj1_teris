#include <iostream>
#include <string>
#include <fstream>

static int row, col;
static int** board;
class Board {
public:
	Board(const int row, const int col) {
		board = new int* [row];
		for (int i = 0; i < row; i++) {
			board[i] = new int[col];
			for (int j = 0; j < col; j++) {
				board[i][j] = 0;
			}
		}
	};

	static void checkFullLine(const int curRow)
	{
		int lineFull = 0;//how many line will fall
		for (int i = 0; i < 4; i++) {
			int j = 0;
			for (; j < col; j++) {
				if (curRow - i < 0)
					break;
				if (board[curRow - i][j] != 1)//not full
					break;
			}
			if (j == col)
				lineFull++;
		}
		LineFall(lineFull);
	}
	static void LineFall(int n) {
		//from bottom to top update
		if (n > 0)
			std::cout << "clear: " << n << " lines!\n";
		while (n--) {
			for (int i = row - 1; i > 0; i--) {
				for (int j = 0; j < col; j++) {
					board[i][j] = board[i - 1][j];
				}
			}
			//top line is newly zero
			for (int j = 0; j < col; j++) {
				board[0][j] = 0;
			}
		}
	}
};

/*
class Obj {
	int p1x = 0, p1y = 0, p2x = 0, p2y = 0,
		p3x = 0, p3y = 0, p4x = 0, p4y = 0;
	Obj( int r, int c, int mv){}
};
*/
class T1 {
public:
	T1(int c, int mv) {
		//find the row it hits something
		int StopRow = 2;
		while (true) {//will not touch the ceiling?
			if (board[StopRow - 1][c + 1] == 1
				|| board[StopRow][c] == 1
				|| board[StopRow][c + 2] == 1) {
				StopRow--;
				break;
			}
			StopRow++;
			if (StopRow == row) {
				StopRow--;
				break;
			}
		}


		while (StopRow + 1 < row && board[StopRow + 1][c + mv + 1] == 0
			&& board[StopRow][c + mv] == 0
			&& board[StopRow][c + mv + 2] == 0)
		{
			StopRow++;
		}

		board[StopRow][c + mv + 1] = 1;
		board[StopRow - 1][c + mv] = 1;
		board[StopRow - 1][c + mv + 1] = 1;
		board[StopRow - 1][c + mv + 2] = 1;

		Board::checkFullLine(StopRow);
	}
};


class T2 {
public:
	T2(int c, int mv) {
		//find the row it hits something
		int StopRow = 3;
		while (true) {//will not touch the ceiling?
			if (board[StopRow - 1][c + 1] == 1
				|| board[StopRow][c] == 1) {
				StopRow--;
				break;
			}
			StopRow++;
			if (StopRow == row) {
				StopRow--;
				break;
			}
		}

		while (StopRow + 1 < row && board[StopRow + 1][c + mv + 1] == 0
			&& board[StopRow][c + mv] == 0)
		{
			StopRow++;
		}

		board[StopRow][c + mv + 1] = 1;
		board[StopRow - 1][c + mv] = 1;
		board[StopRow - 1][c + mv + 1] = 1;
		board[StopRow - 2][c + mv + 1] = 1;

		Board::checkFullLine(StopRow);
	}

};


class T3 {
public:
	T3(int c, int mv) {
		//find the row it hits something
		int StopRow = 2;
		while (true) {//will not touch the ceiling?
			if (board[StopRow][c] == 1
				|| board[StopRow][c + 1] == 1
				|| board[StopRow][c + 2] == 1) {
				StopRow--;
				break;
			}
			StopRow++;
			if (StopRow == row) {
				StopRow--;
				break;
			}
		}

		while (StopRow + 1 < row && board[StopRow + 1][c + mv + 1] == 0
			&& board[StopRow + 1][c + mv] == 0
			&& board[StopRow + 1][c + mv + 2] == 0)
		{
			StopRow++;
		}

		board[StopRow][c + mv] = 1;
		board[StopRow][c + mv + 1] = 1;
		board[StopRow][c + mv + 2] = 1;
		board[StopRow - 1][c + mv + 1] = 1;

		Board::checkFullLine(StopRow);
	}

};

class T4 {
public:
	T4(int c, int mv) {
		//find the row it hits something
		int StopRow = 3;
		while (true) {//will not touch the ceiling?
			if (board[StopRow - 1][c] == 1
				|| board[StopRow][c + 1] == 1) {
				StopRow--;
				break;
			}
			StopRow++;
			if (StopRow == row) {
				StopRow--;
				break;
			}
		}


		while (StopRow + 1 < row && board[StopRow + 1][c + mv] == 0
			&& board[StopRow][c + mv + 1] == 0)
		{
			StopRow++;
		}

		board[StopRow][c + mv] = 1;
		board[StopRow - 1][c + mv] = 1;
		board[StopRow - 2][c + mv] = 1;
		board[StopRow - 1][c + mv + 1] = 1;

		Board::checkFullLine(StopRow);
	}

};

class L1 {
public:
	L1(int c, int mv) {
		//find the row it hits something
		int StopRow = 3;
		while (true) {//will not touch the ceiling?
			if (board[StopRow][c] == 1
				|| board[StopRow][c + 1] == 1) {
				StopRow--;
				break;
			}
			StopRow++;
			if (StopRow == row) {
				StopRow--;
				break;
			}
		}


		while (StopRow + 1 < row && board[StopRow + 1][c + mv + 1] == 0
			&& board[StopRow + 1][c + mv] == 0)
		{
			StopRow++;
		}

		board[StopRow][c + mv] = 1;
		board[StopRow][c + mv + 1] = 1;
		board[StopRow - 1][c + mv] = 1;
		board[StopRow - 2][c + mv] = 1;

		Board::checkFullLine(StopRow);
	}

};

class L2 {
public:
	L2(int c, int mv) {
		//find the row it hits something
		int StopRow = 2;
		while (true) {//will not touch the ceiling?
			if (board[StopRow - 1][c] == 1
				|| board[StopRow][c + 1] == 1
				|| board[StopRow][c + 2] == 1) {
				StopRow--;
				break;
			}
			StopRow++;
			if (StopRow == row) {
				StopRow--;
				break;
			}
		}


		while (StopRow + 1 < row && board[StopRow + 1][c + mv] == 0
			&& board[StopRow][c + mv + 1] == 0
			&& board[StopRow][c + mv + 2] == 0)
		{
			StopRow++;
		}
		board[StopRow][c + mv] = 1;
		board[StopRow - 1][c + mv] = 1;
		board[StopRow - 1][c + mv + 1] = 1;
		board[StopRow - 1][c + mv + 2] = 1;

		Board::checkFullLine(StopRow);
	}

};


class L3 {
public:
	L3(int c, int mv) {
		//find the row it hits something
		int StopRow = 3;
		while (true) {//will not touch the ceiling?
			if (board[StopRow - 2][c + 1] == 1
				|| board[StopRow][c] == 1) {
				StopRow--;
				break;
			}
			StopRow++;
			if (StopRow == row) {
				StopRow--;
				break;
			}
		}


		while (StopRow + 1 < row && board[StopRow + 1][c + mv + 1] == 0
			&& board[StopRow - 1][c + mv] == 0)
		{
			StopRow++;
		}

		board[StopRow][c + mv + 1] = 1;
		board[StopRow - 1][c + mv + 1] = 1;
		board[StopRow - 2][c + mv + 1] = 1;
		board[StopRow - 2][c + mv] = 1;

		Board::checkFullLine(StopRow);
	}

};

class L4 {
public:
	L4(int c, int mv) {
		//find the row it hits something
		int StopRow = 2;
		while (true) {//will not touch the ceiling?
			if (board[StopRow][c] == 1
				|| board[StopRow][c + 1] == 1
				|| board[StopRow][c + 2] == 1) {
				StopRow--;
				break;
			}
			StopRow++;
			if (StopRow == row) {
				StopRow--;
				break;
			}
		}


		while (StopRow + 1 < row && board[StopRow + 1][c + mv] == 0
			&& board[StopRow + 1][c + mv + 1] == 0
			&& board[StopRow + 1][c + mv + 2] == 0)
		{
			StopRow++;
		}

		board[StopRow][c + mv] = 1;
		board[StopRow][c + mv + 1] = 1;
		board[StopRow][c + mv + 2] = 1;
		board[StopRow - 1][c + mv + 2] = 1;

		Board::checkFullLine(StopRow);
	}

};

class J1 {
public:
	J1(int c, int mv) {
		//find the row it hits something
		int StopRow = 3;
		while (true) {//will not touch the ceiling?
			if (board[StopRow][c] == 1
				|| board[StopRow][c + 1] == 1) {
				StopRow--;
				break;
			}
			StopRow++;
			if (StopRow == row) {
				StopRow--;
				break;
			}
		}

		while (StopRow + 1 < row && board[StopRow + 1][c + mv + 1] == 0
			&& board[StopRow + 1][c + mv] == 0)
		{
			StopRow++;
		}

		board[StopRow][c + mv] = 1;
		board[StopRow][c + mv + 1] = 1;
		board[StopRow - 1][c + mv + 1] = 1;
		board[StopRow - 2][c + mv + 1] = 1;

		Board::checkFullLine(StopRow);
	}

};

class J2 {
public:
	J2(int c, int mv) {
		//find the row it hits something
		int StopRow = 2;
		while (true) {//will not touch the ceiling?
			if (board[StopRow][c] == 1
				|| board[StopRow - 1][c + 1] == 1
				|| board[StopRow - 1][c + 2] == 1) {
				StopRow--;
				break;
			}
			StopRow++;
			if (StopRow == row) {
				StopRow--;
				break;
			}
		}

		while (StopRow + 1 < row && board[StopRow + 1][c + mv + 1] == 0
			&& board[StopRow + 1][c + mv] == 0
			&& board[StopRow + 1][c + mv + 2] == 0)
		{
			StopRow++;
		}

		board[StopRow][c + mv] = 1;
		board[StopRow][c + mv + 1] = 1;
		board[StopRow][c + mv + 2] = 1;
		board[StopRow - 1][c + mv] = 1;

		Board::checkFullLine(StopRow);
	}

};


class J3 {
public:
	J3(int c, int mv) {
		//find the row it hits something
		int StopRow = 3;
		while (true) {//will not touch the ceiling?
			if (board[StopRow][c] == 1
				|| board[StopRow - 2][c + 1] == 1) {
				StopRow--;
				break;
			}
			StopRow++;
			if (StopRow == row) {
				StopRow--;
				break;
			}
		}

		while (StopRow + 1 < row && board[StopRow + 1][c + mv] == 0
			&& board[StopRow - 1][c + mv + 1] == 0)
		{
			StopRow++;
		}

		board[StopRow][c + mv] = 1;
		board[StopRow - 1][c + mv] = 1;
		board[StopRow - 2][c + mv] = 1;
		board[StopRow - 2][c + mv + 1] = 1;

		Board::checkFullLine(StopRow);
	}

};

class J4 {
public:
	J4(int c, int mv) {
		//find the row it hits something
		int StopRow = 2;
		while (true) {//will not touch the ceiling?
			if (board[StopRow - 1][c] == 1
				|| board[StopRow - 1][c + 1] == 1
				|| board[StopRow][c + 2] == 1) {
				StopRow--;
				break;
			}
			StopRow++;
			if (StopRow == row) {
				StopRow--;
				break;
			}
		}

		while (StopRow + 1 < row && board[StopRow][c + mv + 1] == 0
			&& board[StopRow][c + mv] == 0
			&& board[StopRow + 1][c + mv + 2] == 0)
		{
			StopRow++;
		}

		board[StopRow][c + mv + 2] = 1;
		board[StopRow - 1][c + mv] = 1;
		board[StopRow - 1][c + mv + 1] = 1;
		board[StopRow - 1][c + mv + 2] = 1;

		Board::checkFullLine(StopRow);
	}

};


class S1 {
public:
	S1(int c, int mv) {
		//find the row it hits something
		int StopRow = 2;
		while (true) {//will not touch the ceiling?
			if (board[StopRow - 1][c] == 1
				|| board[StopRow - 1][c + 1] == 1
				|| board[StopRow][c + 2] == 1) {
				StopRow--;
				break;
			}
			StopRow++;
			if (StopRow == row) {
				StopRow--;
				break;
			}
		}

		while (StopRow + 1 < row && board[StopRow + 1][c + mv + 1] == 0
			&& board[StopRow + 1][c + mv] == 0
			&& board[StopRow][c + mv + 2] == 0)
		{
			StopRow++;
		}

		board[StopRow][c + mv] = 1;
		board[StopRow][c + mv + 1] = 1;
		board[StopRow - 1][c + mv + 1] = 1;
		board[StopRow - 1][c + mv + 2] = 1;

		Board::checkFullLine(StopRow);
	}

};


class S2 {
public:
	S2(int c, int mv) {
		//find the row it hits something
		int StopRow = 3;
		while (true) {//will not touch the ceiling?
			if (board[StopRow][c] == 1
				|| board[StopRow + 1][c + 1] == 1) {
				StopRow--;
				break;
			}
			StopRow++;
			if (StopRow == row) {
				StopRow--;
				break;
			}
		}

		while (StopRow + 1 < row && board[StopRow + 1][c + mv + 1] == 0
			&& board[StopRow][c + mv] == 0)
		{
			StopRow++;
		}

		board[StopRow][c + mv + 1] = 1;
		board[StopRow - 1][c + mv] = 1;
		board[StopRow - 1][c + mv + 1] = 1;
		board[StopRow - 2][c + mv] = 1;

		Board::checkFullLine(StopRow);
	}//OK

};


class Z1 {
public:
	Z1(int c, int mv) {
		//find the row it hits something
		int StopRow = 2;
		while (true) {//will not touch the ceiling?
			if (board[StopRow][c] == 1
				|| board[StopRow - 1][c + 1] == 1
				|| board[StopRow - 1][c + 2] == 1) {
				StopRow--;
				break;
			}
			StopRow++;
			if (StopRow == row) {
				StopRow--;
				break;
			}
		}

		while (StopRow + 1 < row && board[StopRow + 1][c + mv + 1] == 0
			&& board[StopRow][c + mv] == 0
			&& board[StopRow + 1][c + mv + 2] == 0)
		{
			StopRow++;
		}

		board[StopRow][c + mv + 1] = 1;
		board[StopRow][c + mv + 2] = 1;
		board[StopRow - 1][c + mv] = 1;
		board[StopRow - 1][c + mv + 1] = 1;

		Board::checkFullLine(StopRow);
	}//OK

};


class Z2 {
public:
	Z2(int c, int mv) {
		int StopRow = 3;
		while (true) {//will not touch the ceiling?
			if (board[StopRow - 1][c] == 1
				|| board[StopRow][c + 1] == 1) {
				StopRow--;
				break;
			}
			StopRow++;
			if (StopRow == row) {
				StopRow--;
				break;
			}
		}


		while (StopRow + 1 < row && board[StopRow][c + mv + 1] == 0
			&& board[StopRow + 1][c + mv] == 0)
		{
			StopRow++;
		}

		board[StopRow][c + mv] = 1;
		board[StopRow - 1][c + mv] = 1;
		board[StopRow - 1][c + mv + 1] = 1;
		board[StopRow - 2][c + mv + 1] = 1;

		Board::checkFullLine(StopRow);
	}//OK

};


class I1 {
public:
	I1(int c, int mv) {
		//find the row it hits something
		int StopRow = 4;
		while (true) {//will not touch the ceiling?
			if (board[StopRow][c] == 1) {
				StopRow--;
				break;
			}
			StopRow++;
			if (StopRow == row) {
				StopRow--;
				break;
			}
		}

		while (StopRow + 1 < row && board[StopRow + 1][c + mv] == 0)
		{
			StopRow++;
		}

		board[StopRow][c + mv] = 1;
		board[StopRow - 1][c + mv] = 1;
		board[StopRow - 2][c + mv] = 1;
		board[StopRow - 3][c + mv] = 1;

		Board::checkFullLine(StopRow);
	}

};

class I2 {
public:
	I2(int c, int mv) {
		int StopRow = 1;
		while (true) {
			if (board[StopRow][c] == 1
				|| board[StopRow][c + 1] == 1
				|| board[StopRow][c + 2] == 1
				|| board[StopRow][c + 3] == 1) {
				StopRow--;
				break;
			}
			StopRow++;
			if (StopRow == row) {
				StopRow--;
				break;
			}
		}

		while (StopRow + 1 < row && board[StopRow + 1][c + mv] == 0
			&& board[StopRow + 1][c + mv + 1] == 0
			&& board[StopRow + 1][c + mv + 2] == 0
			&& board[StopRow + 1][c + mv + 3] == 0)
		{
			StopRow++;
		}

		board[StopRow][c + mv] = 1;
		board[StopRow][c + mv + 1] = 1;
		board[StopRow][c + mv + 2] = 1;
		board[StopRow][c + mv + 3] = 1;

		Board::checkFullLine(StopRow);
	}

};

class O {
public:
	O(int c, int mv) {
		int StopRow = 2;
		while (true) {//will not touch the ceiling?
			if (board[StopRow][c] == 1
				|| board[StopRow][c + 1] == 1) {
				StopRow--;
				break;
			}
			StopRow++;
			if (StopRow == row) {
				StopRow--;
				break;
			}
		}

		while (StopRow + 1 < row && board[StopRow + 1][c + mv] == 0
			&& board[StopRow + 1][c + mv + 1] == 0)
		{
			StopRow++;
		}

		board[StopRow][c + mv] = 1;
		board[StopRow][c + mv + 1] = 1;
		board[StopRow - 1][c + mv] = 1;
		board[StopRow - 1][c + mv + 1] = 1;

		Board::checkFullLine(StopRow);
	}

};


int main(int argc, char* argv[])
{
	int c, mv;
	std::string str;

	std::ifstream f_in;
	f_in.open(argv[1], std::ifstream::in);//as input, and only read
	if (!f_in.is_open())
	{
		std::cout << "Open file fails! f_in\n";
		return 0;
	}
	else std::cout << "1\n";
	f_in >> row >> col;
	Board(row, col);

	/*
	std::string str;
	std::cin >> r >> c;
	*/
	while (f_in >> str)
	{
		if (str == "End") {
			break;
		}
		f_in >> c >> mv;
		c--;
		switch (str[0])
		{
		case'T':
			if (str[1] == '1')
				T1(c, mv);
			else if (str[1] == '2')
				T2(c, mv);
			else if (str[1] == '3')
				T3(c, mv);
			else
				T4(c, mv);
			break;
		case'L':
			if (str[1] == '1')
				L1(c, mv);
			else if (str[1] == '2')
				L2(c, mv);
			else if (str[1] == '3')
				L3(c, mv);
			else
				L4(c, mv);
			break;
		case'J':
			if (str[1] == '1')
				J1(c, mv);
			else if (str[1] == '2')
				J2(c, mv);
			else if (str[1] == '3')
				J3(c, mv);
			else
				J4(c, mv);
			break;
		case'S':
			if (str[1] == '1')
				S1(c, mv);
			else
				S2(c, mv);
			break;
		case'Z':
			if (str[1] == '1')
				Z1(c, mv);
			else
				Z2(c, mv);
			break;
		case'I':
			if (str[1] == '1')
				I1(c, mv);
			else
				I2(c, mv);
			break;
		case'O':
			O(c, mv);
			break;
		default:
			std::cout << "input wrong object name.\n";
			return 1;
			break;
		}
		/*
		std::cout << "new:\n";
		for (int i = 0; i < row; i++) {
			for (int j = 0; j < col; j++) {
				std::cout << board[i][j] << " ";
			}
			std::cout << "\n";
		}
		*/
	}


	f_in.close();
	if (f_in.is_open())
	{
		std::cout << "Close file fails! f_in\n";
		return 2;
	}

	std::ofstream f_out;
	f_out.open("final.data", std::ofstream::out | std::ofstream::trunc);
	if (!f_out.is_open())
	{
		std::cout << "close file fails! f_out\n";
		return 2;
	}

	for (int i = 0; i < row; ++i)
	{
		for (int j = 0; j < col - 1; ++j)
		{
			f_out << board[i][j];
			f_out << " ";
		}
		f_out << board[i][col - 1] << "\n";
	}

	f_out.close();
	if (f_out.is_open())
		std::cout << "close file fails! f_out\n";

	return 0;
}

