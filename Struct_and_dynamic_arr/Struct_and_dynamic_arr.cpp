#include <iostream>
#include <stdio.h>
#include <string>
#include <Windows.h>

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

struct complexNum {
	double a;
	double b;
};

void output_complex(complexNum number);

complexNum sum(complexNum first, complexNum second);

complexNum subtraction(complexNum first, complexNum second);

complexNum mult(complexNum first, complexNum second);

complexNum div(complexNum first, complexNum second);

struct automobile
{
	int length;
	int clearance;
	double engine_volume;
	int engine_power;
	int wheel_diameter;
	string color;
	string transmission;
};

automobile add_info_about_auto(automobile& mitsubishi);

void output_auto(automobile& mitsubishi);

void search_info(automobile& mitsubishi);

struct book 
{
	string name;
	string author;
	string publisher;
	string genre;
};

void output_book(book* book_info, int& size) {
	for (int i = 0; i < size; i++) {
		cout << " Номер книги в библиотеке - " << i+1 << endl;
		cout <<"  - " << book_info[i].author << "  \n";
		cout <<"  - "<< book_info[i].name << "  \n";
		cout <<"  - " << book_info[i].publisher << "  \n";
		cout <<"  - " << book_info[i].genre << "  \n\n";
	}
}

void change_book(book* book_info, int &size) {
	int chnum;
	output_book(book_info, size);
	cout << "Введите номер книги, которую хотите отредактировать: \n";
	 cin >> chnum;
	 cout << " Название - ";
	 cin >> book_info[chnum-1].name;
	 cout << " Автор - ";
	 cin >> book_info[chnum-1].author;
	 cout << " Издательство - ";
	 cin >> book_info[chnum-1].publisher;
	 cout << " Жанр - ";
	 cin >> book_info[chnum-1].genre;
	
}

book* search_book(book* book_info, int &size) {
	int srh;
	string search1;
	char search2[25];
	
		cout << "\tПоиск: \n"
			<< "[1] По автору \n"
			<< "[2] По названию\n"
			<< "[0] Выход \n";
	do{
		cin >> srh;
	
		if (srh == 1) 
		{
			cout << " Введите фамилию автора: \n";
			cin >> search1;
			//gets_s(search1, 24);
			//cout << search1;
			//system("pause");
			for (int i = 0; i < size; i++) {
				if (book_info[i].author == search1) {
					cout << " Номер книги в библиотеке - " << i + 1 << endl;
					cout << " Автор - " << book_info[i].author << "  \n";
					cout << " Название - " << book_info[i].name << "  \n";
					cout << " Издательство - " << book_info[i].publisher << "  \n";
					cout << " Жанр - " << book_info[i].genre << "  \n\n";
				}
			}
		}
		else if (srh == 2) {
			cout << " Введите название книги: \n";
			//cin >> search2;
			gets_s(search2, 24);
			for (int i = 0; i < size; i++) {
				if (book_info[i].name == search2) {
					cout << " Номер книги в библиотеке - " << i + 1 << endl;
					cout << " Автор - " << book_info[i].author << "  \n";
					cout << " Название - " << book_info[i].name << "  \n";
					cout << " Издательство - " << book_info[i].publisher << "  \n";
					cout << " Жанр - " << book_info[i].genre << "  \n\n";
				}
			}
		}
	} while (srh != 0);

	return book_info;
}

book* sort_book(book* book_info, int &size) {
	int srt;
	string temp;
	cout << "\tСортировка: \n"
		<< "[1] По автору \n"
		<< "[2] По названию\n"
		<< "[3] По издательству \n"
		<< "[0] Выход \n";
	do {
		cin >> srt;
		if (srt == 1) {
			
			for (int i = 0; i < size; i++) {
				temp = book_info[i].author;
				book_info[i].author = book_info[i].publisher;
				book_info[i].publisher = temp;
			}
		}
		else if (srt == 2) {
			for (int i = 0; i < size; i++) {
				temp = book_info[i].author;
				book_info[i].author = book_info[i].publisher;
				book_info[i].publisher = temp;
			}
		}

	} while (srt != 0);
	return book_info;
}



int main()
{
	//setlocale(LC_ALL, "ru");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	//Dynamic array

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

	//Struct

	puts("Task 1________________________\n");
	complexNum first, second;
	first.a = 4;
	first.b = 5;
	second.a = 3;
	second.b = -8;
	complexNum result = sum(first, second);
	output_complex(result);
	result = subtraction(first, second);
	output_complex(result);
	result = mult(first, second);
	output_complex(result);
	result = div(first, second);
	output_complex(result);
	system("pause");
	system("cls");

	puts("Task 2________________________\n");
	automobile mitsubishi;
	do {
	cout << "\n\tMenu: \n\n"
		<< "[1] Enter information;\n"
		<< "[2] Output information;\n"
		<< "[3] Search;\n"
		<< "[0] Exit \n";
	cin >> menu_item;
	
		switch (menu_item)
		{
		case 1: {
			add_info_about_auto(mitsubishi);
			system("pause");
			system("cls");
			break;
		}
		case 2: {
			output_auto(mitsubishi);
			system("pause");
			system("cls");
			break;
		}
		case 3: {
			search_info(mitsubishi);
			system("pause");
			system("cls");
			break;
		}
		default:
			break;
		}
	} while (menu_item != 0);
	system("pause");
	system("cls");

	puts("Task 3________________________\n");
	 int size = 10;
	 
		 book* book_info = new book[size];
		 book_info[0].name = "Колобок";
		 book_info[0].author = "Писахов";
		 book_info[0].publisher = "Дрофа";
		 book_info[0].genre = "Фольклор";
		 book_info[1].name = "Сказки бабушки Галины";
		 book_info[1].author = "Галина";
		 book_info[1].publisher = "Дрофа";
		 book_info[1].genre = "Фольклор";
		 book_info[2].name = "Война и мир";
		 book_info[2].author = "Толстой";
		 book_info[2].publisher = "Просвещение";
		 book_info[2].genre = "Дрофа";
		 book_info[3].name = "Мастер и Маргарита";
		 book_info[3].author = "Булгаков";
		 book_info[3].publisher = "Проба";
		 book_info[3].genre = "Фэнтези";
		 book_info[4].name = "Двенадцать стульев";
		 book_info[4].author = "Петров";
		 book_info[4].publisher = "Проба";
		 book_info[4].genre = "Комедия";
		 book_info[5].name = "Преступление и наказание";
		 book_info[5].author = "Достоевский";
		 book_info[5].publisher = "Проба";
		 book_info[5].genre = "Детектив";
		 book_info[6].name = "Палата № 6";
		 book_info[6].author = "Чехов";
		 book_info[6].publisher = "Дрофа";
		 book_info[6].genre = "Комедия";
		 book_info[7].name = "Евгений Онегин";
		 book_info[7].author = "Пушкин";
		 book_info[7].publisher = "Проба";
		 book_info[7].genre = "Драма";
		 book_info[8].name = "Ревизор";
		 book_info[8].author = "Гоголь";
		 book_info[8].publisher = "Просвещение";
		 book_info[8].genre = "Комедия";
		 book_info[9].name = "Шерлок холмс";
		 book_info[9].author = "Доиль";
		 book_info[9].publisher = "Просвещение";
		 book_info[9].genre = "Детектив";
	 
	do {
		cout << "\n\tБиблиотека: \n\n"
			<< "[1] Печать всех книг;\n"
			<< "[2] Редактировать книгу;\n"
			<< "[3] Поиск ;\n"
			<< "[4] Сортировка книг по названию \n"
			<< "[5] Сортировка книг по автору \n"
			<< "[6] Сортировка книг по издательству \n"
			<< "[0] Выход \n";

		cin >> menu_item;
		switch (menu_item)
		{
		case 1: {
			output_book(book_info, size);
			system("pause");
			system("cls");
			break;
		}
		case 2: {
			change_book(book_info, size);
			system("pause");
			system("cls");
			break;
		}
		case 3: {
			search_book(book_info, size);
			system("pause");
			system("cls");
			break;
		}
		case 4: {
			sort_book(book_info, size);
			break;
		}
		default:
			break;
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

void output_complex(complexNum number)
{
	if (number.b > 0)
		cout << number.a << " + " << number.b << "i" << std::endl;
	else
		cout << number.a << " - " << fabs(number.b) << "i" << std::endl;
}

complexNum sum(complexNum first, complexNum second)
{
	complexNum result;
	result.a = first.a + second.a;
	result.b = first.b + second.b;
	return result;
}

complexNum subtraction(complexNum first, complexNum second)
{
	complexNum result;
	result.a = first.a - second.a;
	result.b = first.b - second.b;
	return result;
}

complexNum mult(complexNum first, complexNum second)
{
	complexNum result;
	result.a = (first.a * second.a) - (first.b * second.b);
	result.b = (first.b * second.a) + (first.a * second.b);
	return result;
}

complexNum div(complexNum first, complexNum second)
{
	complexNum result;
	result.a = ((first.a * second.a) + (first.b * second.b)) / ((second.a * second.a) + (second.b * second.b));
	result.b = ((first.b * second.a) - (first.a * second.b)) / ((second.a * second.a) + (second.b * second.b));
	return result;
}

automobile add_info_about_auto(automobile& mitsubishi) {
	puts("Enter lenght (cm):");
	cin >> mitsubishi.length;
	puts("Enter clearance(mm):");
	cin >> mitsubishi.clearance;
	puts("Enter engine volume(L):");
	cin >> mitsubishi.engine_volume;
	puts("Enter engine power(HP):");
	cin >> mitsubishi.engine_power;
	puts("Enter wheel diameter(cm):");
	cin >> mitsubishi.wheel_diameter;
	puts("Enter color:");
	cin >> mitsubishi.color;
	puts("Enter transmission type:");
	cin >> mitsubishi.transmission;

	return mitsubishi;
}

void output_auto(automobile& mitsubishi) {
	cout << "Lenght - " << mitsubishi.length << " cm \n";
	cout << "Clearance - " << mitsubishi.clearance << " mm \n";
	cout << "Engine volume - " << mitsubishi.engine_volume << " L \n";
	cout << "Engine power - " << mitsubishi.engine_power << " HP \n";
	cout << "Wheel diameter - " << mitsubishi.wheel_diameter << " c \n";
	cout << "Color - " << mitsubishi.color << " \n";
	cout << "Transmission type - " << mitsubishi.transmission << " \n";
}

void search_info(automobile& mitsubishi) {
	int sr;
	do {
		puts("What is the value to find? ");
		cout << "[1] Lenght \n"
			<< "[2] Clearance  \n"
			<< "[3] Engine volume  \n"
			<< "[4] Engine power  \n"
			<< "[5] Wheel diameter  \n"
			<< "[6] Color  \n"
			<< "[7] Transmission type  \n"
			<< "[0] Exit to main menu \n";
		cin >> sr;
		switch (sr)
		{
		case 1: {
			cout << "Lenght - " << mitsubishi.length << " cm \n";
			system("pause");
			system("cls");
			break;
		}
		case 2: {
			cout << "Clearance - " << mitsubishi.clearance << " mm \n";
			system("pause");
			system("cls");
			break;
		}
		case 3: {
			cout << "Engine volume - " << mitsubishi.engine_volume << " L \n";

			system("pause");
			system("cls");
			break;
		}
		case 4: {
			cout << "Engine power - " << mitsubishi.engine_power << " HP \n";
			system("pause");
			system("cls");
			break;
		}
		case 5: {
			cout << "Wheel diameter - " << mitsubishi.wheel_diameter << " c \n";
			system("pause");
			system("cls");
			break;
		}
		case 6: {
			cout << "Color - " << mitsubishi.color << " \n";
			system("pause");
			system("cls");
			break;
		}
		case 7: {
			cout << "Transmission type - " << mitsubishi.transmission << " \n";
			system("pause");
			system("cls");
			break;
		}
		default:
			break;
		}
	} while (sr != 0);
}