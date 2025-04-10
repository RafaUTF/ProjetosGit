#include "Professor.h"

Professor::Professor(int nasc, const char* n):
Pessoa(nasc,n)
{
	pUniv = NULL;
	pDep = NULL;
	cout << "Prof. " << nome << " ainda nao foi contratado" << endl;

}
Professor::Professor() :
	Pessoa()
{
	pUniv = NULL;
	pDep = NULL;
	cout << "Prof. " << nome << " ainda nao foi contratado" << endl;
}

Professor::~Professor(){
	if (pUniv != NULL && pDep != NULL)
		cout << nome << " foi demitido da "
		<< pUniv->getNome() << ", trabalhava com " << pDep->getNome() << endl;
	else
		cout << "sei la kkkk" << endl;
}

void Professor::setUniv(Universidade* pu){
	pUniv = pu;
	//cout << nome << " foi contratado pela "
	//	<< pUniv->getNome() << endl;
}
void Professor::setDep(Departamento* pd){
	pDep = pd;
	//cout << nome << " agora trabalha com "
	//	<< pDep->getNome() << endl;
}
void Professor::setDiscDepUniv(Disciplina* pdi) {
	pDisc = pdi;
	pDep = pdi->getDep();
	pUniv = pDep->getUniv();
}






void Professor::ondeTrabalho(){
	if (pDisc ==NULL||pUniv == NULL || pDep == NULL)
		cout << nome << " eh um vagabundo e nao da aula " << endl;
	else
		cout << "Prof. " << nome << " da a materia: " << 
		pDisc->getNome() << ". Trabalha com "
		<< pDep->getNome() << " na " << pUniv->getNome() << endl;

}