#include "ElAluno.h"

ElAluno::ElAluno() {
	paE = NULL;
	pAnte = NULL;
	pProx = NULL;
}
ElAluno::~ElAluno() {
	paE = NULL;
	pAnte = NULL;
	pProx = NULL;
}
void ElAluno::setAluno(Aluno* pa) {paE = pa;}
Aluno* ElAluno::getAluno() {return paE;}

void ElAluno::setpAnte(ElAluno* pa) { pAnte = pa; }
ElAluno* ElAluno::getpAnte() { return pAnte; }
void ElAluno::setpProx(ElAluno* pp) { pProx = pp; }
ElAluno* ElAluno::getpProx() { return pProx; }