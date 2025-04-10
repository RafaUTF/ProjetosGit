#include "Departamento.h"
//#include "Universidade.h" nao precisa ??

Departamento::Departamento(const char* n) {
	setNome(n);
	pInicio = NULL;
	pAtual = NULL;
}
Departamento::~Departamento() {
	cout << nome << " is dead" << endl;
}
void Departamento::setNome(const char* n) {
	strcpy_s(nome, n);
}
char* Departamento::getNome() {
	return nome;
}
void Departamento::setUniv(Universidade* pu) {
	pUniv = pu;
}
Universidade* Departamento::getUniv() {
	return pUniv;
}

void Departamento::novaDisc(Disciplina* pd) {
	int ja_ta = 0;
	Disciplina* px;
	for (px = pInicio;px != NULL && ja_ta == 0;px = px->getpProx())
		if (px == pd)
			ja_ta = 1;
	if (!ja_ta) {
		if (pInicio == NULL) {//1a materia
			pInicio = pd;
			pAtual = pd;
		}
		else {//mais uma materia
			for (px = pInicio;px->getpProx() != NULL && pd->getPeriodo() > px->getPeriodo();px = px->getpProx());
			if (px->getpProx() == NULL&&pd->getPeriodo() >= px->getPeriodo()) {//ultima posicao perfeito
				px->setpProx(pd);
				pd->setpAnte(px);
				pAtual = pd;
			}
			else{// if (pd->getPeriodo() < px->getPeriodo()) {//meio ou inicio
				if (px->getpAnte() != NULL) {
					pd->setpAnte(px->getpAnte());
					px->getpAnte()->setpProx(pd);
				}
				else//px->getpAnte() == NULL
					pInicio = pd;
				pd->setpProx(px);
				px->setpAnte(pd);
			}
		}
		pd->setDep(this);
	}
}

void Departamento::listaDisc() {
	cout << "Disciplinas de " << nome << ":" << endl;
	for (Disciplina* px = pInicio;px != NULL;px = px->getpProx())
		cout << px->getNome() << endl;
}