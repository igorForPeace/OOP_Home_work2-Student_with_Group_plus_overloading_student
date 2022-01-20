#include "Student.h"
#include "Group.h"

int main()
{
	setlocale(LC_ALL, "RUSSIAN");
	srand(time(0));
	
	Student A;
	A.Show_Student();
	A += 3;
	A.Show_Student();

	Student C;
	C.Show_Student();
	Student D;
	D.Show_Student();
	cout << endl;
	bool result = C < D;
	cout << boolalpha << result << endl;

	return 0;
}