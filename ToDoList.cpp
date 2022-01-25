
#include <iostream>
#include <string>
#include <cctype>
using namespace std;


////////Functions area/////////////////////////////////////

//Заполнение массива базовыми значениями
void BaseInfo(string* arr[]) {

	string baseArr[3][5]{
		{"Do smth1", "High", "I need to do difficult task", "10/10/2022", "12:00"},
		{"Do smth2", "Low", "I need to do not so difficult task", "12/09/2022", "09:30"},
		{"Do smth3", "Medium", "I need to do the task", "15/04/2022", "11:00"},
	};

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			arr[i][j] = baseArr[i][j];
		}
	}
}

//Новая версия заполнения массива тестовыми данными
void BaseInfo(string**& arr, string* linearr, int& rows, const int cols) {
	string baseArr[3][5]{
		{"Do smth1", "High", "I need to do difficult task", "10/10/2022", "12:00"},
		{"Do smth2", "Low", "I need to do not so difficult task", "12/09/2022", "09:30"},
		{"Do smth3", "Medium", "I need to do the task", "15/04/2022", "11:00"},
	};


}

//Вывод массива на экран
void PrintArr(string* arr[], int rows, int cols) {
	string arrTitle[]{ "Name", "Priority", "Description", "date", "time" };

	for (int i = 0; i < rows; i++)
	{
		cout << "Task " << i + 1 << ":\n";
		for (int j = 0; j < cols; j++)
		{
			cout << arrTitle[j] << ": " << arr[i][j] << "\n";
		}
		cout << "***\n\n";
	}
}

//Перегрузка функции вывода для отображения одной задачи
void PrintArr(int number, string* arr[], int cols) {
	string arrTitle[]{ "Name", "Priority", "Description", "Date", "Time" };
	cout << "Task " << number << ":\n";
	for (int i = 0; i < cols; i++)
	{
		cout << arrTitle[i] << ": " << arr[number - 1][i] << "\n";
	}
	cout << "***" << endl;
}


//функция ввода записи с клавиатуры
void TypeLine(string arr[]) {

	string arrTitle[]{ "name", "priority", "description", "date", "time" };
	
	for (int i = 0; i < 5; i++)		
	{
		cout << "Enter task " << arrTitle[i] << ": ";
		getline(cin, arr[0]);
		cout << endl;
	}
	
}

//функция добавления новой записи в конец массива
void PushBack(string**& arr, string* linearr, int& rows, const int cols) {
	TypeLine(linearr);

	//Объявление и инициализация временного двумерного массива
	string** newArray = new string * [rows + 1];
	for (int i = 0; i < rows + 1; i++) {
		newArray[i] = new string[cols];
	}

	//Заполнение временного массива уже имеющимися данными
	if (rows > 0) {
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < cols; j++)
			{
				newArray[i][j] = arr[i][j];
			}
		}
	}

	//добавление новой записи в конец временного массива
	for (int i = 0; i < cols; i++)
	{
		newArray[rows][i] = linearr[i];
	}


	for (int i = 0; i < rows; i++)
	{
		delete[] arr[i];
	}
	delete[] arr;
	rows++;

	arr = newArray;

}
//Удаление указанной записи
void RemoveLine(string**& arr, int& rows, const int cols) {
	int number;

	cout << "Enter the number of the task to remove: ";
	cin >> number;

	rows--;
	string** newArray = new string * [rows];
	for (int i = 0; i < rows; i++) {
		newArray[i] = new string[cols];
	}
	
	for (int i = 0; i < rows; i++)
	{

		for (int j = 0; j < cols; j++)
		{
			if (i >= number - 1) {
				newArray[i][j] = arr[i + 1][j];
			}
			else {
				newArray[i][j] = arr[i][j];
			}
		}

	}

	for (int i = 0; i < rows; i++)
	{
		delete[] arr[i];
	}
	delete[] arr;


	arr = newArray;

}

//редактирование записи
void EditTask(string**& arr, string* linearr, int rows, const int cols) {
	int number;
	cout << "Number of the task you want to edit: ";
	cin >> number;
	cout << "Chosen task:" << endl;
	PrintArr(number, arr, cols);
	TypeLine(linearr);

	string** newArray = new string * [rows];
	for (int i = 0; i < rows; i++) {
		newArray[i] = new string[cols];
	}

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			if (i == number - 1)
				newArray[i][j] = linearr[j];
			else newArray[i][j] = arr[i][j];
		}
	}

	for (int i = 0; i < rows; i++)
	{
		delete[] arr[i];
	}
	delete[] arr;


	arr = newArray;
}

//поиск по имени
void SearchName(string* arr[], int rows, int cols) {
	string search;
	cout << "Type the name of task: \n";
	getline(cin, search);
	int matches = 0;
	for (int i = 0; i < rows; i++)
	{
		if (arr[i][0] == search) {
			cout << "Result:" << endl;
			PrintArr(i + 1, arr, cols);
			matches++;
		}
	}
	cout << "Matches: " << matches << endl;

}

//поиск по приоритету
void SearchPrior(string* arr[], int rows, int cols) {
	int num;
	string search;
	string priorities[3]{ "High", "Medium", "Low" };

	bool isWrong = false;
	do
	{
		cout << "Chose the priority of task: \nHigh: 1\nMedium: 2\nLow: 3\n";
		cin >> num;
		if (num > 0 && num <= 3) {
			int matches = 0;
			for (int i = 0; i < rows; i++)
			{
				if (arr[i][1] == priorities[num - 1]) {
					cout << endl;
					PrintArr(i + 1, arr, cols);
					matches++;
				}
			}
			cout << "Matches: " << matches << endl;

			isWrong = false;
		}
		else {
			cout << "Wrong value. Try again\n";
			isWrong = true;
		}

	} while (isWrong == true);
}

//функция для вывода вопроса о выходе
int yesNo() {
	int res;
	cout << "Whould you like to make another request? \n1 - Yes\n0 - No\n";
	do {
		cin >> res;	
		cin.ignore();
		cout << endl;
		if (res != 0 && res != 1) cout << "\"0\" or \"1\" only\n";
	} while (res != 0 && res != 1);
	return res;
}
//////////////////////////////////////////////////////////////////////



int main()
{
	cout << "***To Do List***" << endl;
	int rows = 0;
	const int cols = 5;
	string lineArray[cols];

	//объявление и инициализация двумерного динамического массива
	string** tdl = new string * [rows];
	for (int i = 0; i < rows; i++) {
		tdl[i] = new string[cols];
	}

	

	//Основной интерфейс программы
	
	cout << "Hello, i'm your To Do List.\n";
	int num;
	bool goOn = 1;
	while (goOn) {
		cout << "Choose what you want to do with your tasks:" << endl;
		cout << "1 - Display your tasks\n";
		cout << "2 - Add new task\n";
		cout << "3 - Remove task\n";
		cout << "4 - Edit task\n";
		cout << "5 - Search task by name\n";
		cout << "6 - Search task by priority\n";
		cout << "0 - Exit\n";
		cin >> num;	
		cin.ignore();
		cout << endl;
		switch (num)
		{
		case 1:
			PrintArr(tdl, rows, cols);
			goOn = yesNo();
			break;
		case 2:
			PushBack(tdl, lineArray, rows, cols);
			goOn = yesNo();
			break;
		case 3:
			RemoveLine(tdl, rows, cols);
			goOn = yesNo();
			break;
		case 4:
			EditTask(tdl, lineArray, rows, cols);
			goOn = yesNo();
			break;
		case 5:
			SearchName(tdl, rows, cols);
			goOn = yesNo();
			break;
		case 6:
			SearchPrior(tdl, rows, cols);
			goOn = yesNo();
			break;
		case 0:
			goOn = 0;
			break;
		default:
			cout << "Bad request\n";
			break;
		}

	}

	

	//PrintArr(tdl, rows, cols);
	//RemoveLine(tdl, rows, cols);
	//PushBack(tdl, lineArray, rows, cols);	
	//EditTask(tdl, lineArray, rows, cols);
	//SearchName(tdl, rows, cols);
	//SearchPrior(tdl, rows, cols);



	for (int i = 0; i < rows; i++)
	{
		delete[] tdl[i];
	}
	delete[] tdl;

}


