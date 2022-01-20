#include "Student.h"

Student::Student()
{
	const char* Surname[10] = { "Петров", "Сидоров" , "Кравченко" , "Тимощук" , "Краснов" , "Чекулаев"
				, "Колбаскин" , "Салатов" , "Пивоваров" , "Зоровиков" };
	surname = new char[100];
	strcpy_s(surname, 99, Surname[rand() % 10]);
	const char* Name[10] = { "Игорь" , "Дмитрий","Виктор","Петр","Василий","Константин", "Александр",
		"Алексей","Иван","Андрей" };
	name = new char[100];
	strcpy_s(name, 99, Name[rand() % 10]);
	const char* Patronomic[10] = { "Витальевич", "Викторович","Петрович","Василиевич",
		"Максимович","Юрьевич","Андреевич","Ульянович","Иванович","Федорович" };
	patronymic = new char[100];
	strcpy_s(patronymic, 99, Patronomic[rand() % 10]);
	age = rand() % 4 + 17;
	count_of_credits = 10;
	credits = new int[count_of_credits];
	for (int i = 0; i < count_of_credits; i++)
	{
		credits[i] = rand() % 11 + 1;
	}
	float sum = 0 ;
	for (int i = 0; i < 10; i++)
	{
		sum += credits[i];
	}
	average_rating = sum / 10;
	exam = rand() % 2;
	
}

Student::Student(const char* surname, const char* name, const char* patronymic)
{
	this->surname = new char[100];
	strcpy_s(this->surname, 99, surname);
	this->name = new char[100];
	strcpy_s(this->name, 99, name);
	this->patronymic = new char[100];
	strcpy_s(this->patronymic, 99, patronymic);
	age = rand() % 4 + 17;
	count_of_credits = 10;
	credits = new int[count_of_credits];
	for (int i = 0; i < count_of_credits; i++)
	{
		credits[i] = rand() % 11 + 1;
	}
	float sum=0;
	for (int i = 0; i < count_of_credits; i++)
	{
		sum += credits[i];
	}
	average_rating = sum / count_of_credits;
	exam = rand() % 2;
}

Student::~Student()
{
	if (surname != nullptr)
	{
		delete[] surname;
		//surname = nullptr;
	}
	if (name != nullptr)
	{
		delete[] name;
		//name = nullptr;
	}
	if (patronymic != nullptr)
	{
		delete[] patronymic;
		//patronymic = nullptr;
	}
	if (credits != nullptr)
	{
		delete[] credits;
		//credits = nullptr;
	}
}

const char* Student::Get_name() 
{
	return name;
}

const char* Student::Get_surname() 
{
	return surname;
}

const char* Student::Get_patronymic() 
{
	return patronymic;
}

float Student::Get_avegare_rating() const
{

	return average_rating;
}

int Student::Get_age()const
{
	return age;
}

int Student::Get_count_of_credits() const
{
	return count_of_credits;
}

void Student::Show_credits() const
{
	for (int i = 0; i < count_of_credits; i++)
	{
		cout << credits[i] << "  ";
	}
}

bool Student::Get_exam() const
{
	return exam;
}

void Student::Show_Student()
{
	cout << "-----------------" << endl;
	cout << "Информация о студенте: " << endl;
	cout << "Фамилия: " << Get_surname() << endl;
	cout << "Имя: " << Get_name() << endl;
	cout << "Отчество: " << Get_patronymic() << endl;
	cout << "Возраст: " << Get_age() << endl;
	cout << "Оценки: ";
	Show_credits();
	cout << "\nСдача екзамена: " << boolalpha << Get_exam() << endl;
	cout << "Средняя оценка студента: " << average_rating << endl;
}

Student& Student::operator +=(int one_credit) // добавление оценки одному студенту
{
	int *credits = new int[count_of_credits + 1];
	for (int i = 0; i < count_of_credits; i++)
	{
		credits[i] = this->credits[i];
	}
	credits[count_of_credits] = one_credit;
	delete[] this->credits;
	this->credits = credits;
	count_of_credits++;
	return *this;
}

bool Student::operator == (const Student& other) // перегрузка оператора равенства
{
	return this->Get_avegare_rating() == other.Get_avegare_rating();
}

bool Student::operator != (const Student& other) // перегрузка оператора неравенства
{
	return !(this->Get_avegare_rating() == other.Get_avegare_rating());
}

bool Student::operator < (const Student& other) // оператор сравнения <
{
	return this->Get_avegare_rating() < other.Get_avegare_rating();
}

bool Student::operator > (const Student& other) // оператор сравнения >
{
	return this->Get_avegare_rating() > other.Get_avegare_rating();
}


