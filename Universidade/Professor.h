#pragma once
#include "Pessoa.h"
#include "Universidade.h"

class Professor: public Pessoa
{
private:
	Universidade* pUniv;
	Departamento* pDep;
	Disciplina* pDisc;
public:
	Professor(int nasc, const char* n);
	Professor();
	~Professor();
	void setUniv(Universidade* pu);
	void setDep(Departamento* pd);

	void setDiscDepUniv(Disciplina* pdi);

	void ondeTrabalho();
};

