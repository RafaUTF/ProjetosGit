#pragma once
#include "stdafx.h"
class Departamento;
//class Universidade;
class ElAluno;
class Aluno;

class Disciplina
{
private:
	int nAlunos;
	int iAlunos;
	int periodo;
	char nome[30];
	char areaConhecimento[30];
	Departamento* pDepD;//
	Disciplina* pAnte;
	Disciplina* pProx;

	ElAluno* pInicio;
	ElAluno* pAtual;
public:
	

	Disciplina(const char* n = "", const char* a = "", int p = -1, int na = 45);
	void inicializa(const char* n, const char* a,int p, int na);
	~Disciplina();
	void setNome(const char* n);
	char* getNome();
	void setArea(const char* a);
	char* getArea();
	void setDep(Departamento* pd);//
	Departamento* getDep();//

	Disciplina* getpAnte();
	Disciplina* getpProx();

	void setpAnte(Disciplina* pa);
	void setpProx(Disciplina* pp);

	void setPeriodo(const int p);
	int getPeriodo();

	//metodos alunos
	void novoAluno(Aluno* pa);
	void retiraAluno(Aluno* pa);
	//void matriculado(Aluno* pa);
	int matriculado(Aluno* pa);
	void listaAlunos();
	void listaAlunos2();


};

