#include "Disciplina.h"
#include "Aluno.h"//
#include "Departamento.h"
//#include "Universidade.h"

Disciplina::Disciplina(const char* n, const char* a,int p, int na){
	inicializa(n, a, p, na);
}
void Disciplina::inicializa(const char* n, const char* a, int p, int na) {
	setNome(n);
	setArea(a);
	nAlunos = na;
	periodo = p;
	iAlunos = 0;

	pDepD = NULL;//
	pAnte = NULL;
	pProx = NULL;

	pInicio = NULL;
	pAtual = NULL;

}

Disciplina::~Disciplina(){
	pDepD = NULL;//
	pAnte = NULL;
	pProx = NULL;
	pInicio = NULL;
	pAtual = NULL;
}

void Disciplina::setNome(const char* n) {
	strcpy_s(nome, n);
}
char* Disciplina::getNome() {
	return nome;
}
void Disciplina::setArea(const char* a) {
	strcpy_s(areaConhecimento, a);
}
char* Disciplina::getArea() {
	return areaConhecimento;
}
/*
void Disciplina::setDep(Departamento* pd) {
	if (pDepD != pd) {
		pDepD = pd;
		pDepD->novaDisc(this);
	}
}
*/
void Disciplina::setDep(Departamento* pd) {
	if (pDepD != pd) {
		pDepD = pd;
		if (pDepD != NULL)
			pDepD->novaDisc(this);
	}
}

Departamento* Disciplina::getDep() {
	return pDepD;
}
//
Disciplina* Disciplina::getpAnte() { return pAnte; }
Disciplina* Disciplina::getpProx() { return pProx; }

void Disciplina::setpAnte(Disciplina* pa) {
	pAnte = pa;
}
void Disciplina::setpProx(Disciplina* pp) {
	pProx = pp;
}
void Disciplina::setPeriodo(const int p) { periodo = p; }
int Disciplina::getPeriodo() { return periodo; }


void Disciplina::listaAlunos() {
	cout << "Os " << iAlunos << " de " << nAlunos << " alunos de " << nome << ":" << endl;
	for (Aluno* px = pInicio;px != NULL;px = px->getpProx())
		cout << px->getNome() << endl;
}
void Disciplina::listaAlunos2() {
	cout << "Os " << iAlunos << " de " << nAlunos << " alunos de " << nome << ":" << endl;
	for (Aluno* px = pAtual;px != NULL;px = px->getpAnte())
		cout << px->getNome() << endl;
}

void Disciplina::novoAluno(Aluno* pa) {
	int ja_ta = 0;
	Aluno* px;
	for (px = pInicio;px != NULL && ja_ta == 0;px = px->getpProx())
		if (px == pa)
			ja_ta = 1;
	if (!ja_ta&&iAlunos<nAlunos) {
		if (pInicio == NULL) {//1a materia
			pInicio = pa;
			pAtual = pa;
		}
		else {//mais uma materia
			for (px = pInicio;px->getpProx() != NULL && pa->getNome()[0] > px->getNome()[0];px = px->getpProx());
			if (px->getpProx() == NULL && pa->getNome()[0] >= px->getNome()[0]) {//ultima posicao perfeito
				px->setpProx(pa);
				pa->setpAnte(px);
				pAtual = pa;
			}
			else {// if (pd->getPeriodo() < px->getPeriodo()) {//meio ou inicio
				if (px->getpAnte() != NULL) {
					pa->setpAnte(px->getpAnte());
					px->getpAnte()->setpProx(pa);
				}
				else//px->getpAnte() == NULL
					pInicio = pa;
				pa->setpProx(px);
				px->setpAnte(pa);
			}
		}
		iAlunos++;
		pa->setDisc(this);
	}
	else if (iAlunos == nAlunos&&!ja_ta) {
		cout << "O aluno " << pa->getNome()
			<< " nao conseguiu vaga em  " << nome << endl;
		pa->setDisc(NULL);
	}
}
/*
void Disciplina::novoAluno(Aluno* pa) {
	int ja_ta = 0;
	Aluno* px;
	for (px = pInicio;px != NULL && ja_ta == 0;px = px->getpProx())
		if (px == pa)
			ja_ta = 1;
	if (!ja_ta) {
		if (pInicio == NULL) {//1a materia
			pInicio = pa;
			pAtual = pa;
		}
		else {//mais uma materia
			for (px = pInicio;px->getpProx() != NULL && a_maior_b(pa,px);px = px->getpProx());
			if (px->getpProx() == NULL && !a_maior_b(pa, px)) {//ultima posicao perfeito
				px->setpProx(pa);
				pa->setpAnte(px);
				pAtual = pa;
			}
			else {// if (pd->getPeriodo() < px->getPeriodo()) {//meio ou inicio
				if (px->getpAnte() != NULL) {
					pa->setpAnte(px->getpAnte());
					px->getpAnte()->setpProx(pa);
				}
				else//px->getpAnte() == NULL
					pInicio = pa;
				pa->setpProx(px);
				px->setpAnte(pa);
			}
		}
		//pa->setDisc(this);
	}
}
*/

int Disciplina::a_maior_b(Aluno* a, Aluno* b) {
	int i;
	for (i = 0;a->getNome()[i] != '\0' && b->getNome()[i] != '\0';i++) {
		if (a->getNome()[i] > b->getNome()[i])
			return 1;
		else if (a->getNome()[i] < b->getNome()[i])
			return 0;
	}
	if (a->getNome()[i] != '\0')//se o a for maior
		return 1;
	//else if (b->getNome()[i] != '\0')
	return 0;
}

void Disciplina::matriculado(Aluno* pa) {
	if (pa->getDisc() == this)
		cout << "O aluno " << pa->getNome()
		<< " esta matriculado na disciplina " << nome << endl;
	else
		cout << "O aluno " << pa->getNome()
		<< " NAO esta matriculado na disciplina " << nome << endl;
}

void Disciplina::retiraAluno(Aluno* pa) {
	if (pa->getDisc()!=this)
		cout << "O aluno " << pa->getNome()
		<< " nao esta matriculado na disciplina " << nome << endl;
	else {
		iAlunos--;
		pa->setDisc(NULL);//if(pa==pInicio&&pa==pAtual)
		if (pa->getpAnte() == NULL && pa->getpProx() == NULL) {
			pInicio = NULL;
			pAtual = NULL;
		}//else if(pa==pAtual)
		else if (pa->getpProx() == NULL) { //&& pa->getpAnte() != NULL
			pa->getpAnte()->setpProx(NULL);
			pAtual = pa->getpAnte();
			pa->setpAnte(NULL);
		}
		else {//meio ou inicio
			if (pa->getpAnte() != NULL) //if (pa != pInicio)
				pa->getpAnte()->setpProx(pa->getpProx());
			else
				pInicio = pa->getpProx();

			pa->getpProx()->setpAnte(pa->getpAnte());

			pa->setpAnte(NULL);
			pa->setpProx(NULL);
		}
	}


}