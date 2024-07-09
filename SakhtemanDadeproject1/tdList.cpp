
#include "tdList.h"

bool tdList::hasClass(snode* s, Class& c)
{
	cnode* ptr = s->clist;
	while (ptr != nullptr)
		if (ptr->info == c)
			break;
		else
			ptr = ptr->nex;

	if (ptr != nullptr)
		return true;
	return false;
}

inline void tdList::printClassdata(cnode* x)
{
	using namespace std;
	cout << "Class Name : " << x->info.name << endl;
	cout << "Class ID : " << x->info.idc << endl;
	cout << "Class score : " << x->info.score << endl;
}

inline void tdList::printstudentData(snode* x)
{
	using namespace std;
	cout << "Students Name : " << x->info.fname << " " << x->info.lname << endl;
	cout << "Students ID : " << x->info.id << endl;
	printclasses(x);
}

void tdList::addclass(int x1, Class& x2)
{
	snode* ptr = p;
	while (ptr != nullptr) {
		if (ptr->info.id == x1) {
			addclass(ptr, x2);
			break;
		}
		ptr = ptr->nex;
	}
}

void tdList::addStudent(Student& x)
{
	snode* ptr = p;
	if (ptr == nullptr) {
		snode* tmp = new snode;
		tmp->info = x;
		p = tmp;
	}
	else {
		while (ptr->nex != nullptr)
			ptr = ptr->nex;
		snode* tmp = new snode;
		tmp->info = x;
		ptr->nex = tmp;
	}
}

void tdList::addclass(snode* x1, Class& x2)
{
	cnode* ptr = x1->clist;
	if (ptr == nullptr) {
		ptr = new cnode;
		ptr->info = x2;
		x1->clist = ptr;
	}
	else {
		while (ptr->nex != nullptr)
			ptr = ptr->nex;
		cnode* tmp = new cnode;
		tmp->info = x2;
		ptr->nex = tmp;
	}

}

void tdList::delclass(snode* x1, Class& x2)
{
	cnode* ptr = x1->clist;
	if (ptr->info == x2) {
		cnode* tmp = ptr;
		x1->clist = tmp->nex;
		tmp->nex = nullptr;
		delete tmp;
		tmp = nullptr;
	}
	else {
		while (ptr->nex != nullptr) {
			if (ptr->nex->info == x2) {
				cnode* tmp = ptr->nex;
				ptr->nex = tmp->nex;
				tmp->nex = nullptr;
				delete tmp;
				tmp = nullptr;
				break;
			}
		}
	}
}

void tdList::printclasses(snode* x)
{
	float sum = 0;
	int cnt = 0;
	cnode* ptr = x->clist;
	while (ptr != nullptr) {
		cnt++;
		sum += ptr->info.score;
		printClassdata(ptr);
		ptr = ptr->nex;
	}
	std::cout << "Average : " << sum / cnt << '\n';
}

void tdList::printstudents(Class& x)
{
	snode* ptr = p;
	while (ptr != nullptr) {
		if (hasClass(ptr, x))
			printstudentData(ptr);
		ptr = ptr->nex;
	}
}

void tdList::topclass(Class& x)
{
	snode* ptr = p;
	snode* tops = p;
	float topscore = 0;
	while (ptr != nullptr) {
		if (hasClass(ptr, x)) {
			cnode* tmp = ptr->clist;
			while (tmp->info != x)
				tmp = tmp->nex;
			if (topscore <= tmp->info.score) {
				topscore = tmp->info.score;
				tops = ptr;
			}
		}
		ptr = ptr->nex;
	}
	printstudentData(tops);
}

float tdList::aveClass(Class& x)
{
	snode* ptr = p;
	float sum = 0;
	int cnt = 0;
	while (ptr != nullptr) {
		if (hasClass(ptr, x)) {
			cnode* tmp = ptr->clist;
			while (tmp->info != x)
				tmp = tmp->nex;
			sum += tmp->info.score;
			cnt++;
		}
		ptr = ptr->nex;
	}
	std::cout << "Class Average is : " << sum / cnt << '\n';
	return sum / cnt;
}

inline void everytimeprint() {
	using namespace std;
	cout << "To add a student enter 1" << endl;
	cout << "To add a class for a student enter 2" << endl;
	cout << "To delete a class of a student enter 3" << endl;
	cout << "To print report card of a student enter 4" << endl;
	cout << "To print classes of a studnet enter 5" << endl;
	cout << "To print top studnet of a class enter 6" << endl;
	cout << "To print avarage of a class enter 7" << endl;
	cout << "To exit enter 8" << endl;
}

//Just tesing :)
/*/
int main() {
	tdList st;
	int n;
	tdList::Student s1;
	tdList::Class c1;
	using namespace std;
	string str1;
	int i;
	while (true)
	{
		everytimeprint();
		cin >> n;
		switch (n)
		{
		case 1:
			cout << "enter first name :" << endl;
			cin >> str1;
			s1.fname = str1;
			cout << "enter last name :" << endl;
			cin >> str1;
			s1.lname = str1;
			cout << "enter id :" << endl;
			cin >> i;
			s1.id = i;
			st.addStudent(s1);
			break;
		case 2:
			cout << "enter name of class : " << endl;
			cin >> str1;
			c1.name = str1;
			cout << "enter id of class : " << endl;
			cin >> i;
			c1.idc = i;
			cout << "enter score : " << endl;
			cin >> i;
			c1.score = i;
			cout << "enter students id to add : " << endl;
			cin >> i;
			st.addclass(i, c1);
			break;
		case 3:
			cout << "enter ID of class : " << endl;
			int x, y;
			cin >> x;
			cout << "enter Id of student : " << endl;
			cin >> y;
			c1.idc = x;
			st.delclass(st.findbyID(y), c1);
			break;
		case 4:
			cout << "enter ID : " << endl;
			cin >> i;
			st.printstudentData(st.findbyID(i));
			break;
		case 5:
			cout << "enter ID : " << endl;
			cin >> i;
			st.printclasses(st.findbyID(i));
			break;
		case 6:
			cout << "enter ID : " << endl;
			cin >> i;
			c1.idc = i;
			st.topclass(c1);
			break;
		case 7:
			cout << "enter ID : " << endl;
			cin >> i;
			c1.idc = i;
			cout << st.aveClass(c1) << endl;
			break;
		case 8:
			return 0;
		default:
			break;
		}
	}
}

*/