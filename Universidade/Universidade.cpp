#include "Universidade.h"

Universidade::Universidade(const char* n) {
	setNome(n);
	//int i;
	//for (i = 0;i < DEPTS;i++) {
	//	pDepU[i] = NULL;
	//}
}
Universidade::~Universidade() {
	cout << nome << " EXPLODIU!!!" << endl;
}
void Universidade::setNome(const char* n) {
	strcpy_s(nome, n);
}
char* Universidade::getNome() {
	return nome;
}

void Universidade::setNovoDep(Departamento* pd) {
	/*
	int i = 0;
	while (i < DEPTS) {
		if (pDepU[i] == NULL) {
			pDepU[i] = pd;
			break;
		}
		i++;
	}
	if (i == DEPTS)
		cout << "sem espaco para um departamento de " 
		<< pd->getNome() <<endl;
		*/
	pDepU.push_back(pd);
		
}
Departamento* Universidade::getDep(int i) {
	/*
	list<Departamento*>::iterator navegador;
	int j = 0;
	for (navegador = pDepU.begin();navegador != pDepU.end() && j != i;navegador++,j++);
	return *navegador;
	*/
	return pDepU[i];
}
void Universidade::printDepts() {
	cout << nome << " tem departamentos de:" << endl;
	//for(int i=0;pDepU[i]!=NULL&&i<DEPTS;i++)
		//cout << pDepU[i]->getNome() << endl;
	// VECTOR
	for (int i = 0;i< (int)pDepU.size();i++)
		cout << pDepU[i]->getNome() << endl;
	/* LISTA
	list<Departamento*>::iterator navegador;
	for (navegador=pDepU.begin();navegador != pDepU.end();navegador++)
		cout << (*navegador)->getNome() << endl;
	*/

}