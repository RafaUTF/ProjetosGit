#pragma once
#include "Professor.h"
#include "Aluno.h"

//#include "Disciplina.h"

class Principal
{
private:
	int anoAT;

	Aluno Rafa;
	Aluno Luiz;
	Aluno Arthur;
	Aluno Carlos;
	Aluno Deborah;

	Professor Barreto;
	Professor Simao;

	Universidade utf;
	Universidade puc;

	Departamento dafis;
	Departamento dainf;

	Disciplina matDisc;
	Disciplina tecProg;
	Disciplina fis1;
	Disciplina fis2;
	Disciplina fis3;
	Disciplina fis4;

public:
	Principal();

	void inicializa();
	void inicializaUniv();
	void inicializaDep();
	void inicializaDisc();
	void inicializaAlunos();
	void inicializaProf();


	~Principal();

	void executar();
	void calcIdade();
	void Univ();
	void Dep();
	void listaDisc();
	void listaAlunos();
};

