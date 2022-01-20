#pragma once
#include "ALL_libraries.h"
#include "Student.h"

class Group
{
private:
	int count_of_student;
	Student* student = nullptr;
	char* name_of_group = nullptr;
	char* specialization = nullptr;
	int course;
public:
	Group();
	Group(int count_of_student);
	Group(int count_of_student, const char* name_of_group, const char* specialization);
	Group(const char* name_of_group, const char* specialization);
	Group(const Group& original);
	~Group();

	

	void Set_name_of_group(const char* name_of_group);// ����� ��������� ����� ������
	void Set_specialization(const char* specialization);// ����� ��������� ������������� ������
	

	void Set_course(int course);  // ����� ��������� �����
	int Get_course() const;
	void Show_Group();  // ����� ���� ��������� ������
	void Add_Student_2();
	void Add_Student(); //����� ���������� ��������
	void Add_Student(const char* surname, const char* name, const char* patronymic);
	void Dismiss_for_exam(); // ����� ���������� ��������� �� ��������� ���
	void Dismiss_for_credits(); // ���������� �� ��������������
	//void Sum_group(const Group& original); // ������� ����� (������ �������)
	void Merge_groups(const Group& first, const Group& second); // ������� ���� �����
	
	

};
