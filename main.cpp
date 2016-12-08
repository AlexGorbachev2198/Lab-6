#include <conio.h>
#include <iostream>
using namespace std;
struct Student
{
	char name[64];
	char surname[32];
	unsigned int year_of_birth;
	
};
struct List
{
	Student std;
	List *pNext;
};
void addFirst(List *& pF, List* p)
{
	p->pNext = pF;
	pF = p;
}
List * delFirst(List *&pF)
{
	if (pF == 0) return 0;
	List *p = pF;
	pF = pF->pNext;
	return p;
}
bool add(List *&pF, List * pZad, List *p)
{

	if (pZad == pF)
	{
		p->pNext = pF;
		pF = p;
		return true;
	}

	List *pPred = pF;
	while (pPred->pNext != pZad && pPred->pNext)
		pPred = pPred->pNext;
	if (pPred->pNext == 0) return false;
	p->pNext = pZad;
	pPred->pNext = p;
	return true;
}
List * del(List*& pF, List *p)
{
	if (pF == 0) return 0;
	if (pF == p)
	{
		pF = pF->pNext;
		return p;
	}
	else
	{
		List *pPred = pF;
		while (pPred->pNext != p && pPred->pNext)
			pPred = pPred->pNext;
		if (pPred->pNext == 0) return 0;
		pPred->pNext = p->pNext;
		return p;
	}
	while (delFirst(pF));
}
void output(List *pF)
{
	for (List *pi = pF; pi; pi = pi->pNext)
		cout << pi->std.surname << " " << pi->std.name << " " << pi->std.year_of_birth << endl;
}
int main(int argc, char* argv[])
{
	List *pF = 0;
	List *p;
	char Ex;
	do
	{
		p = (List *)malloc(sizeof(List));
        cout << endl;
		cout << "Name: ";
		cin.get();
		fflush(stdin);
		gets_s(p->std.name, 63);
        cout << "Surname: ";
		fflush(stdin);
		gets_s(p->std.surname, 31);
        cout << "Year of birth: ";
		fflush(stdin);
		cin >> p->std.year_of_birth;
        addFirst(pF, p);
		printf("For continue press Y or y");
		Ex = _getche();
		cin.clear();
		cout << endl;
    } while (Ex == 'Y' || Ex == 'y');
	cout << endl;
	output(pF);
	for (List *pi = pF; pi->pNext;)
	{
        double min = pi->std.year_of_birth;
		List *pmin = pi;
		for (List *pj = pi->pNext; pj; pj = pj->pNext)
			if (pj->std.year_of_birth < min)
			{
				min = pj->std.year_of_birth;
				pmin = pj;
			}
		if (pi != pmin)
		{
			del(pF, pmin);
			add(pF, pi, pmin);
		}
		else pi = pi->pNext;
	}
	cout << endl;
	cout << "Sorted: " << endl;
	output(pF);
	system("pause");
	return 0;
}
