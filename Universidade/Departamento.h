#pragma once
#include "Disciplina.h"
class Universidade;

class Departamento
{
private:
	char nome[20];
	Universidade* pUniv;
	Disciplina* pInicio;
	Disciplina* pAtual;
public:
	Departamento(const char* n = "estatistica");
	~Departamento();
	void setNome(const char* n);
	char* getNome();
	void setUniv(Universidade* pu);
	Universidade* getUniv();

	//adicionar metodos diciplina
	void novaDisc(Disciplina* pd);
	void listaDisc();
};

