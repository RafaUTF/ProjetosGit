#pragma once
#include "Departamento.h"
#include <vector>
//#include <list>
using namespace std;
#define DEPTS 2

class Universidade
{
private:
	char nome[30];
	//Departamento* pDepU[DEPTS];
	vector<Departamento*> pDepU;
	//list<Departamento*> pDepU;
public:
	Universidade(const char* n = "uniesquina");
	~Universidade();
	void setNome(const char* n);
	char* getNome();
	void setNovoDep(Departamento* pd);
	Departamento* getDep(int i);
	void printDepts();
};

