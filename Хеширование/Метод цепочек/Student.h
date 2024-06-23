#pragma once

#include <iostream>

using namespace std;

class Student
{
	public:
		string ID;
		string FullName;

		int Course;
		string Group;

		bool IsTuition;

		struct { string Exam; int Grade; } Exams[5];

		Student(string fullName = "", string id = "", int course = -1, string group = "", bool ist = false)
		{
			this->FullName = fullName;
			this->ID = id;
			this->Course = course;
			this->Group = group;
			this->IsTuition = ist;

			for (int i = 0; i < 5; i++)
			{
				this->Exams[i] = { "", -1 };
			}
		}

		bool operator==(const Student& other)
		{
			return ((other.FullName == this->FullName) && (other.ID == this->ID) && (other.Course == this->Course));
		}
};

