#pragma once
#include "Pessoa.h"
#include "Universidade.h"

class Aluno: public Pessoa
{
private:
	Universidade* pUniv;
	int RA;

	Aluno* pAnte;
	Aluno* pProx;

	Disciplina* pDisc;

public:
	Aluno(int nasc, const char* n);
	Aluno();
	~Aluno();
	void setUniv(Universidade* pu);
	void setRA(int ra);
	void ondeEstudo();

	void setpAnte(Aluno* pa);
	Aluno* getpAnte();
	void setpProx(Aluno* pp);
	Aluno* getpProx();

	void setDisc(Disciplina* pd);
	Disciplina* getDisc();
};

