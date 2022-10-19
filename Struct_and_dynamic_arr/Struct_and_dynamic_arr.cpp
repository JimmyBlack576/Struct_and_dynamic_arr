#include <iostream>

using namespace std;
//output arr
void print_arr(int** arr, int row, int col);
//add column
int** add_col(int** arr, int col, int row, int pos);
//delete column
int** del_col(int** arr, int col, int row, int pos);
//shift rows up and down
void move_row(int** arr, int col, int row, int dir);
//shift columns left and right
void move_col(int** arr, int col, int row, int dir);
//create dynamic array for matrix
int** matrix(int row, int col);

void filling_matrix(int** arr1, int row, int col);

void print_matrix(int** arr1, int row, int col);
//transposition matrix
int** transpon_matrix(int** arr1, int& row, int& col);


int main()
{

	puts("Task 1_____________________________\n");
	int pos, col = 3, row = 3;
	int** arr = new int* [row];
	for (int i = 0; i < row; i++) {
		arr[i] = new int[col];
	}

	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			arr[i][j] = i+j*2;
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}
	puts("Enter the position: ");
	cin >> pos;
	arr = add_col(arr, col, row, pos);
	print_arr(arr, row, col);
	system("pause");
	system("cls");

	puts("Task 2_____________________________\n");
	print_arr(arr, row, col);
	puts("Enter the position: ");
	cin >> pos;
	arr = del_col(arr, col, row, pos);
	print_arr(arr, row, col-1);
	system("pause");
	system("cls");

	puts("Task 3_____________________________\n");
	print_arr(arr, row, col - 1);
	int choise, dir;
	puts("Choose what to move (1 - Row / 2 - Column):  ");
	cin >> choise;
	if (choise == 1) {
		puts("Up [1] or Down [2] ? ");
		cin >> dir;
		puts("Enter position:");
		cin >> pos;
		while (pos!=0) {
			move_row(arr, col, row, dir);
			pos--;
		}
	}
	else if (choise == 2) {
		puts("Left [1] or Right [2] ? ");
		cin >> dir;
		puts("Enter position:");
		cin >> pos;
		while (pos != 0) {
			move_col(arr, col, row, dir);
			pos--;
		}
	}
	print_arr(arr, row, col - 1);
	system("pause");
	system("cls");

	puts("Task 4________________________\n");
	puts("Enter the number of rows:");
	cin >> row;
	puts("Enter the number of columns:");
	cin >> col;
	int** arr1 = matrix(row, col);
	filling_matrix(arr1, row, col);
	print_matrix(arr1, row, col);
	arr1 = transpon_matrix(arr1, row, col);
	cout << endl;
	print_matrix(arr1, row, col);
}

void print_arr(int** arr, int row, int col) {
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col + 1; j++) {

			cout << arr[i][j] << " ";
		}
		cout << endl;
	}
}

int** add_col(int** arr, int col, int row, int pos) {
	int** new_arr = new int* [row];
	for (int i = 0; i < row; i++) {
		new_arr[i] = new int[col + 1];
	}

	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col + 1; j++) {
			if (j == pos) {
				new_arr[i][j] = 1;
			}
			else {
				if (j < pos)
					new_arr[i][j] = arr[i][j];
				if (j > pos)
					new_arr[i][j] = arr[i][j - 1];
			}
		}
	}
	for (int i = 0; i < row; i++)
	{
		delete[] arr[i];
	}
	delete[] arr;
	return new_arr;
}

int** del_col(int** arr, int col, int row, int pos) {
	int** new_arr = new int* [row];
	for (int i = 0; i < row; i++) {
		new_arr[i] = new int[col];
	}

	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			if (j == pos) {
				new_arr[i][j] = arr[i][j + 1];
			}
			else {
				if (j < pos)
					new_arr[i][j] = arr[i][j];
				if (j > pos)
					new_arr[i][j] = arr[i][j + 1];
			}
		}
	}
	for (int i = 0; i < row; i++)
	{
		delete[] arr[i];
	}
	delete[] arr;
	return new_arr;
}

void move_row(int** arr, int col, int row, int dir) {
	if (dir == 2) {
		int* tmp = new int[col];

		for (int j = 0; j < col; j++) {
			tmp[j] = arr[row - 1][j];
		}

		for (int i = row - 1; i > 0; i--) {
			for (int j = 0; j < col; j++) {
				arr[i][j] = arr[i - 1][j];
			}
		}

		for (int j = 0; j < col; j++) {
			arr[0][j] = tmp[j];
		}

		delete[] tmp;
	}
	else if (dir == 1) {
		int* tmp = new int[col];

		for (int j = 0; j < col; j++)
			tmp[j] = arr[0][j];

		for (int i = 0; i < row - 1; i++)
			for (int j = 0; j < col; j++)
				arr[i][j] = arr[i + 1][j];

		for (int j = 0; j < col; j++)
			arr[row - 1][j] = tmp[j];

		delete[] tmp;
	}
}

void move_col(int** arr, int col, int row, int dir) {
	if (dir == 1) {
		int* tmp = new int[row];

		for (int i = 0; i < row; i++) {
			tmp[i] = arr[i][0];
		}

		for (int i = 0; i < row; i++) {
			for (int j = 0; j < col - 1; j++) {
				arr[i][j] = arr[i][j + 1];
			}
		}

		for (int i = 0; i < row; i++) {
			arr[i][col - 1] = tmp[i];
		}

		delete[] tmp;
	}
	else if (dir == 2) {
		int* tmp = new int[row];

		for (int i = 0; i < row; i++) {
			tmp[i] = arr[i][col - 1];
		}

		for (int i = 0; i < row; i++) {
			for (int j = col - 1; j > 0; j--) {
				arr[i][j] = arr[i][j - 1];
			}
		}
		for (int i = 0; i < row; i++) {
			arr[i][0] = tmp[i];
		}

		delete[] tmp;
	}
}

int** matrix(int row, int col) {
	int** arr1 = new int* [row];
	for (int i = 0; i < row; i++) {
		arr1[i] = new int[col];
	}
	return arr1;
}

void filling_matrix(int** arr1, int row, int col) {
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			arr1[i][j] = rand() % 9 + 1;
		}
		cout << endl;
	}
}

void print_matrix(int** arr1, int row, int col) {
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			cout << arr1[i][j] << "  ";
		}
		cout << endl;
	}
}

int** transpon_matrix(int** arr1, int& row, int& col) {
	int** temp_matrix = matrix(col, row);
	for (int i = 0; i < col; i++) {
		for (int j = 0; j < row; j++) {
			temp_matrix[i][j] = arr1[j][i];
		}
		cout << endl;
	}

	for (int i = 0; i < row; i++) {
		delete[] arr1[i];
	}
	delete[] arr1;

	int temp = row;
	row = col;
	col = temp;

	return temp_matrix;
}