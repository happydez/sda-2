#include <iostream>

#include "Student.h"
#include "HashTable.h"

using namespace std;

int studentHashFunction(Student s, int tableSize, int key = 32)
{
	int hashResult = 0;

	for (auto ch : s.ID)
	{
		hashResult = (key * hashResult + ch) % tableSize;
	}

	return (hashResult * 2 + 1) % tableSize;
}

struct StudentHashFunction
{
	int operator()(Student s, int tableSize) const
	{
		return studentHashFunction(s, tableSize);
	}
};

int main()
{

	auto students = new Student[5]
	{
		Student("Student 1", "62245", 2, "1", true),
		Student("Student 1", "78112", 2, "3", true),
		Student("Student 1", "68144", 1, "3", false),
		Student("Student 1", "11379", 3, "2", false),
		Student("Student 1", "57831", 2, "5", true),
	};

	auto ts = new HashTable<Student, StudentHashFunction>();

	for (int i = 0; i < 5; i++)
	{
		ts->Add(students[i]);
		cout << ts->Contains(students[i]) << endl;
	}

	cout << endl << string(32, '-') << endl;

	cout << ts->Contains(Student("Student 2", "62245", 2, "1", true)) << endl;

	cout << string(32, '-') << endl;

	for (int i = 0; i < 5; i++)
	{
		ts->Remove(students[i]);
		cout << ts->Contains(students[i]) << endl;
	}

	return 0;
}