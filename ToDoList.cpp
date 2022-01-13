// ToDoList.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <string>
using namespace std;


////////Functions area/////////////////////////////////////

//Заполнение массива базовыми значениями
void BaseInfo(string* arr[]) {

	string baseArr[3][5]{
		{"Do something", "High", "I need to do difficult task", "10/10/2022", "12:00"},
		{"Do something", "Low", "I need to do not so difficult task", "12/09/2022", "09:30"},
		{"Do something", "Medium", "I need to do the task", "15/04/2022", "11:00"},
	};

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			arr[i][j] = baseArr[i][j];
		}
	}
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
		cout << "***" << endl;
	}
}

//Перегрузка функции вывода для отображения одной задачи
void PrintArr(int number, string* arr[], int cols) {
	string arrTitle[]{ "Name", "Priority", "Description", "date", "time" };
	cout << "Task " << number << ":\n";
	for (int i = 0; i < cols; i++)
	{
		cout << arrTitle[i] << ": " << arr[number - 1][i] << "\n";
	}
	cout << "***" << endl;
}


//функция ввода записи с клавиатуры
void TypeLine(string arr[]) {

	cout << "Enter task name: ";
	cin >> arr[0];
	cout << endl;

	cout << "Enter task priority: ";
	cin >> arr[1];
	cout << endl;

	cout << "Enter task description: ";
	cin >> arr[2];
	cout << endl;

	cout << "Enter task date: ";
	cin >> arr[3];
	cout << endl;

	cout << "Enter task time: ";
	cin >> arr[4];
	cout << endl;
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
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			newArray[i][j] = arr[i][j];
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
		if (i != number - 1) {
			for (int j = 0; j < cols; j++)
			{
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


//////////////////////////////////////////////////////////////////////



int main()
{
	cout << "***To Do List***" << endl;
	int rows = 3;
	const int cols = 5;
	string lineArray[cols];

	//объявление и инициализация двумерного динамического массива
	string** tdl = new string * [rows];
	for (int i = 0; i < rows; i++) {
		tdl[i] = new string[cols];
	}


	BaseInfo(tdl);
	PrintArr(tdl, rows, cols);
	//PushBack(tdl, lineArray, rows, cols);
	//RemoveLine(tdl, rows, cols);
	EditTask(tdl, lineArray, rows, cols);
	PrintArr(tdl, rows, cols);













	for (int i = 0; i < rows; i++)
	{
		delete[] tdl[i];
	}
	delete[] tdl;




}


