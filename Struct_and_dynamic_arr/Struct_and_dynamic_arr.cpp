#include <iostream>
#include <stdio.h>
#include <string>
#include <conio.h>

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

struct phone_name
{
	string name;
	long long number;
};

phone_name* input_num_and_name(phone_name* arr_name_number, int& r);

phone_name* output(phone_name* arr_name_number, int& r);

phone_name* change_data(phone_name* arr_name_number, int& r);

void search(phone_name* arr_name_number, int& r);



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
	system("pause");
	system("cls");

	puts("Task 5________________________\n");
	int r = 3, menu_item;
	phone_name* arr_name_number = new phone_name[r];
	do{
	cout << "\n\tMenu: \n\n"
		<< "[1] Enter data;\n"
		<< "[2] Output data;\n"
		<< "[3] Cahnge data;\n"
		<< "[4] Search;\n"
		<< "[0] Exit \n";
	cin >> menu_item;
	switch (menu_item) {
	case 1: {
		input_num_and_name(arr_name_number, r);
		system("pause");
		system("cls");
		break;
	}
	case 2: {
		output(arr_name_number, r);
		system("pause");
		system("cls");
		break;
	}
	case 3: {
		change_data(arr_name_number, r);
		system("pause");
		system("cls");
		break;
	}
	case 4: {
		search(arr_name_number, r);
		system("pause");
		system("cls");
		break;
	}
	default:
		if (menu_item == 0) break;
		cout << "Wrong menu item!\n";
		system("pause");
		system("cls");
		continue;
	}
	} while (menu_item != 0);

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

phone_name* input_num_and_name(phone_name* arr_name_number, int& r) {
	for (int i = 0; i < r; i++) {
		puts("Enter the name: ");
		cin >> arr_name_number[i].name;
		puts("Enter the number: ");
		cin >> arr_name_number[i].number;
	}
	return arr_name_number;
}

phone_name* output(phone_name* arr_name_number, int& r) {
	for (int i = 0; i < r; i++) {
		cout << '[' << i + 1 << "] " << arr_name_number[i].name << "\t";
		cout << arr_name_number[i].number << endl;
	}
	return arr_name_number;
}

phone_name* change_data(phone_name* arr_name_number, int& r) {
	int change;
	puts("Which item to change? ");
	output(arr_name_number, r);
	cin >> change;
	puts("Enter the new name: ");
	cin >> arr_name_number[change - 1].name;
	puts("Enter the new number: ");
	cin >> arr_name_number[change - 1].number;
	change = 0;
	return arr_name_number;

}

void search(phone_name* arr_name_number, int& r) {
	long long find_num;
	string find_name;
	int ch;
	puts("Choose a search method: ");
	cout << "[1] - By name;\n"
		<< "[2] - by number;\n";
	cin >> ch;

	if (ch == 1) {
		puts("Enter the name: ");
		cin >> find_name;
		for (int i = 0; i < r; i++) {
			if (arr_name_number[i].name == find_name) {
				cout << arr_name_number[i].name << "\t";
				cout << arr_name_number[i].number << endl;
			}
		}
	}
	else if (ch == 2) {
		puts("Enter the number: ");
		cin >> find_num;
		for (int i = 0; i < r; i++) {
			if (arr_name_number[i].number == find_num) {
				cout << arr_name_number[i].name << endl;
				cout << arr_name_number[i].number << endl;
			}
		}
	}

}