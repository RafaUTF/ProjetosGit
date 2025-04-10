#include "Pessoa.h"

Pessoa::Pessoa(int nasc, const char* n){
	inicializa(nasc, n);
}
void Pessoa::inicializa(int nasc, const char* n) {
	setAno(nasc);
	setNome(n);
	idade = 0;
}
Pessoa::~Pessoa(){
	cout << nome << " morreu com " << idade << " anos" << endl;
}
void Pessoa::calcIdade(int atual){
	idade = atual - ano;
}
int Pessoa::getIdade(){
	return idade;
}
char* Pessoa::getNome(){
	return nome;
}
void Pessoa::setNome(const char* n){
	strcpy_s(nome, n);
}
void Pessoa::setAno(int nasc){
	ano = nasc;
}
void Pessoa::printIdade(){
	cout << nome << " tem " << idade << " anos." << endl;
}