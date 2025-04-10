#pragma once
#include "stdafx.h"

class Pessoa
{
protected:
	int ano;
	int idade;
	char nome[30];

public:
	Pessoa(int nasc=2000, const char* n="noname");
	void inicializa(int nasc, const char* n);
	~Pessoa();
	void calcIdade(int atual);
	int getIdade();
	char* getNome();
	void setNome(const char* n);
	void setAno(int nasc = 0);
	void printIdade();

};

