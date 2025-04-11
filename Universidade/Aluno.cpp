#include "Aluno.h"

Aluno::Aluno(int nasc, const char* n):
	Pessoa(nasc,n)
{
	cout << "aluno nasceu" << endl;
	pUniv = NULL;
	RA = -1;

	//pAnte = NULL;
	//pProx = NULL;
	pDisc = NULL;
}
Aluno::Aluno():
	Pessoa()
{
	pUniv = NULL;
	RA = -1;

	//pAnte = NULL;
	//pProx = NULL;
	pDisc = NULL;
}
Aluno::~Aluno(){
	if(pUniv != NULL)
	cout << nome << " se formou na "
	<< pUniv->getNome() << ", tinha o RA:  " << RA << endl;

	pUniv = NULL;
	//pAnte = NULL;
	//pProx = NULL;
}
void Aluno::setUniv(Universidade* pu){
	pUniv = pu;
	cout << nome << " entrou na "
		<< pUniv->getNome() << endl;
}
void Aluno::setRA(int ra){
	RA = ra;
}
void Aluno::ondeEstudo(){
	if (pUniv != NULL)
	cout << "Aluno " << nome << " estuda na "
	<< pUniv->getNome() << endl;
	else
		cout << nome << " eh um vagabundo e nao estuda " << endl;
}

//void Aluno::setpAnte(Aluno* pa) {pAnte = pa;}
//void Aluno::setpProx(Aluno* pp) {pProx = pp;}
//Aluno* Aluno::getpAnte() { return pAnte; }
//Aluno* Aluno::getpProx() { return pProx; }
/*
void Aluno::setDisc(Disciplina* pd) { 
	if (pDisc == NULL) {
		pDisc = pd;
		pDisc->novoAluno(this);
	}
	else
		pDisc = NULL;
}*/
void Aluno::setDisc(Disciplina* pd) {
	if (pDisc != pd) {
		if (pd == NULL)
			pDisc->retiraAluno(this);
		else {// pd != NULL
			pd->novoAluno(this);
			if(pd->matriculado(this))
				pDisc = pd;
		}
	}
}


Disciplina* Aluno::getDisc() { return pDisc; }