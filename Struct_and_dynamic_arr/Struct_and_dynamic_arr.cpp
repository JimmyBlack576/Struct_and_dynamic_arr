#include <iostream>

using namespace std;
//output arr
void print_arr(int** arr, int row, int col);
//add column
int** add_col(int** arr, int col, int row, int pos);
//delete column
int** del_col(int** arr, int col, int row, int pos);

void move_row(int** arr, int col, int row) {
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

int main()
{

	puts("Task 1_____________________________\n");
	int pos, col = 3, row = 3;
	//создание двумерного динамического массива
	int** arr = new int* [row];
	for (int i = 0; i < row; i++) {
		arr[i] = new int[col];
	}

	//инициализация двумерного динамического массива
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
	cin >> pos;
	arr = del_col(arr, col, row, pos);
	print_arr(arr, row, col-1);
	system("pause");
	system("cls");

	puts("Task 3_____________________________\n");
	print_arr(arr, row, col - 1);
	int choise;
	puts("Сhoose what to move (1 - Row / 2 - Column):  ");
	cin >> choise;
	if (choise == 1) {
		cin >> pos;
		while (pos!=0) {
			move_row(arr, col, row);
			pos--;
		}
	}
	else if (choise == 2) {

	}
	print_arr(arr, row, col - 1);
	system("pause");
	system("cls");

	puts("Task 4________________________\n");


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

