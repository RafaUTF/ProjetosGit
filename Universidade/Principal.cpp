#include "Principal.h"

Principal::Principal(){
	anoAT = 2025;
	inicializa();
}
void Principal::inicializa(){
	inicializaUniv();
	inicializaDep();
	inicializaDisc();
	inicializaAlunos();
	inicializaProf();
}

void Principal::inicializaUniv(){
	utf.setNome("UTFPR");
}
void Principal::inicializaDep(){
	dafis.setNome("Fisica");
	dainf.setNome("Progamacao");
	dafis.setUniv(&utf);
	dainf.setUniv(&utf);


}
void Principal::inicializaDisc(){
	matDisc.inicializa("Matematica Discreta", "Logica", 4, 10),
	tecProg.inicializa("Tecnicas de Programacao", "Orientacao Objeto", 3, 15),
	fis1.inicializa("Fisica Teorica 1", "Mecanica Newtoniana", 1, 4),
	fis2.inicializa("Fisica Teorica 2", "Hidro,ondas,termo", 2, 20),
	fis3.inicializa("Fisica Teorica 3", "Eletrica", 3, 20),
	fis4.inicializa("Fisica Teorica 4", "Relatividade", 4, 20);

	//tecProg.setDep(&dainf);
	//matDisc.setDep(&dainf);

	dainf.novaDisc(&matDisc);
	dainf.novaDisc(&tecProg);
	
	fis1.setDep(&dafis);
	dafis.novaDisc(&fis4);
	fis3.setDep(&dafis);
	dafis.novaDisc(&fis2);
	
	fis3.setDep(&dafis);
	fis4.setDep(&dafis);

	dafis.novaDisc(&fis1);
	dafis.novaDisc(&fis2);
	dafis.novaDisc(&fis3);
	dafis.novaDisc(&fis4);
}
void Principal::inicializaAlunos() {
	Rafa.inicializa(2006, "Rafael Fernandes");
	Luiz.inicializa(2004, "Luiz Henrique");
	Carlos.inicializa(2006, "Carlos Laplace");
	Arthur.inicializa(2006, "Arthur Herbele");
	Deborah.inicializa(2006, "Deborah Feijo");
	
	Rafa.setDisc(&fis1);
	fis1.novoAluno(&Carlos);
	Deborah.setDisc(&fis1);
	fis1.novoAluno(&Deborah);
	fis1.novoAluno(&Arthur);
	Deborah.setDisc(&fis1);
	Luiz.setDisc(&fis1);
	fis1.novoAluno(&Luiz);
}
void Principal::inicializaProf() {
	Barreto.inicializa(1990, "Rafael Barreto");
	Simao.inicializa(1980, "Jean Simao");

	//Barreto.setUniv(&utf);
	//Simao.setUniv(&utf);
	//Barreto.setDep(&dafis);
	//Simao.setDep(&dainf);
	Barreto.setDiscDepUniv(&fis1);
	Simao.setDiscDepUniv(&tecProg);
}


Principal::~Principal(){
	cout <<endl<< endl<< "acabou o programa" << endl;
}

void Principal::executar() {
	calcIdade();
	Univ();
	Dep();
	listaDisc();
	listaAlunos();


	/*
	int a;
	cout << "ano atual:" << endl;
	cin >> a;
	Rafa.calcIdade(a);
	cout << endl << Rafa.getNome() << endl;
	cout << endl << Rafa.getIdade() << endl;
	Luiz.calcIdade(a);
	Luiz.printIdade();
	*/
	/*
	utf.setNovoDep(&dafis);
	utf.setNovoDep(&dainf);
	utf.printDepts();
	cout << utf.getNome() << " tem um departamento de "
	<< utf.getDep(0)->getNome() << endl;
	cout << utf.getNome() << " tem um departamento de "
	<< utf.getDep(1)->getNome() << endl;
	*/

	/*
	Simao.calcIdade(2025);
	Simao.printIdade();
	Barreto.calcIdade(2025);
	Barreto.printIdade();

	Barreto.setUniv(&utf);
	Simao.setUniv(&utf);
	Barreto.setDep(&dafis);
	Simao.setDep(&dainf);

	Barreto.ondeTrabalho();
	Simao.ondeTrabalho();
	*/
}

void Principal::calcIdade() {
	Rafa.calcIdade(anoAT);
	Luiz.calcIdade(anoAT);
	Barreto.calcIdade(anoAT);
	Simao.calcIdade(anoAT);
	
	Rafa.printIdade();
	Luiz.printIdade();
	Barreto.printIdade();
	Simao.printIdade();
}

void Principal::Univ() {
	Barreto.ondeTrabalho();
	Simao.ondeTrabalho();
}
void Principal::Dep() {
	
}
void Principal::listaDisc() {
	dainf.listaDisc();
	dafis.listaDisc();
}

void Principal::listaAlunos() {
	
	//fis1.matriculado(&Luiz);
	cout << endl << fis1.matriculado(&Rafa) << endl;
	cout << endl << fis1.matriculado(&Luiz) << endl;

	fis1.listaAlunos();
	//fis1.retiraAluno(&Luiz);
	//fis1.retiraAluno(&Rafa);

	fis1.listaAlunos2();
}