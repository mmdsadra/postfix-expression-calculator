#pragma once
#include <string>
#include <iostream>

class tdList
{
public:

	class Class {
	public:
		std::string name;
		int score;
		int idc;
		Class() {
			idc = score = 0;
		}

		Class(std::string n, int s, int i)
			: name(n), score(s), idc(i)
		{

		}
		
		bool operator ==(Class& tm) {
			if (tm.idc == this->idc)
				return true;
			return false;
		}
		bool operator !=(Class& tm) {
			return !(tm == *this);
		}
	};

	class Student {
	public:
		std::string fname;
		std::string lname;
		int id;
		Student() {
			id = 0;
		}

		Student(std::string f, std::string l, int i)
			: fname(f), lname(l), id(i)
		{

		}
	};

	struct cnode {
		Class info;
		cnode* nex = nullptr;
	};

	struct snode {
		Student info;
		cnode* clist = nullptr;
		snode* nex = nullptr;
		snode() {
			
		}
	};

	//helpers:
	bool hasClass(snode*, Class&);
	inline void printClassdata(cnode*);
	inline void printstudentData(snode*);
	void addclass(int, Class&);
	snode* findbyID(int i) {
		snode* ptr = p;
		while (ptr->info.id != i)
			ptr = ptr->nex;
		return ptr;
	}

	//for project:
	void addStudent(Student&);
	void addclass(snode*, Class&);
	void delclass(snode*, Class&);
	void printclasses(snode*);
	void printstudents(Class&);
	void topclass(Class&);
	float aveClass(Class&);

private:
	snode* p = nullptr;

public:

	//exist:
	~tdList() {
		snode* ptr = p;
		while (ptr != nullptr) {
			cnode* cptr = ptr->clist;
			while (cptr != nullptr) {
				cnode* tm = cptr;
				cptr = cptr->nex;
				delclass(ptr, tm->info);
			}
			snode* tmp = ptr;
			ptr = tmp->nex;
			tmp->nex = nullptr;
			delete tmp;
			tmp = nullptr;
			p = ptr;
		}
	}
};