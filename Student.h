#pragma once
#include "ALL_libraries.h"



class Student
{
private:
	char* surname;
	char* name;
	char* patronymic;
	int age;
	int* credits;
	int count_of_credits;
	bool exam;
	float average_rating;

public:
	Student();
	Student(const char* surname, const char* name, const char* patronymic);
	~Student();

	const char* Get_name();
	const char* Get_surname();
	const char* Get_patronymic();
	int Get_age()const;
	int Get_count_of_credits() const;
	float Get_avegare_rating() const;
	void Show_credits() const;
	bool Get_exam() const;
	void Show_Student();

	Student& operator += (int credits);
	bool operator == (const Student& other); // перегрузка оператора равенства

	bool operator != (const Student& other); // перегрузка оператора неравенства

	bool operator < (const Student& other); // оператор сравнения <

	bool operator > (const Student& other); // оператор сравнения >




};

