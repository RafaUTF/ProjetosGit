#pragma once
#include "Aluno.h"
class ElAluno
{
private:
	Aluno* paE;
	ElAluno* pAnte;
	ElAluno* pProx;
public:
	ElAluno();
	~ElAluno();
	void setAluno(Aluno* pa);
	Aluno* getAluno();

	void setpAnte(ElAluno* pa);
	ElAluno* getpAnte();
	void setpProx(ElAluno* pp);
	ElAluno* getpProx();
};

