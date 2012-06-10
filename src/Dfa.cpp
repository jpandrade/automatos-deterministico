/*
 * Dfa.cpp
 *
 *      Author:
 *      e-mail:
 */

#include "Dfa.h"
#include "FileNotFoundException.h"
#include "InvalidState.h"
#include <cstdio>

int Dfa::numberOfDfas = 0;

Dfa::Dfa(char* filename){
	Dfa::numberOfDfas++;
	// Tenta abrir o arquivo, senao pega excecao
	try {
		loadFromFile(filename);
	} catch (FileNotFoundException & e) {
		fprintf(stderr, "%s\n\n",e.what());
		exit(1);
	}
}

void Dfa::loadFromFile(const char* inputFilename) {
	// Tenta abrir o arquivo em modo leitura
	// se não conseguir, lança uma exceção
	FILE *p;
	p = fopen(inputFilename,"r");
	if (p == NULL) {
		throw fileNotFoundException;
	}

	// Arquivo foi aberto corretamente
	// Começar a ler os dados

	// Le a primeira linha, contendo o estado inicial
	readStartState(p);

	// Le a segunda linha, contendo os estados finais
	readFinalStates(p);

	// Le a terceira linha, contendo a quantidade de estados
	readNStates(p);

	// Le as transicoes
	readTransitions(p);

	listAllTransitions();


}

int inline Dfa::getNStates() const {
	return nStates;
}

void Dfa::setNStates(int nStates) {
	this->nStates = nStates;
	//printf("Numero de estados é : %d\n",this->nStates);
}

bool Dfa::eval(const char* input, int sizeInput) const {
	int nextNode;
	int currentState = startState;
	for (int i=0; i<sizeInput; i++) {
		// Busca se tem transicao
		nextNode = automatos[currentState]->haveTransition(input[i]);
		printf("NextNode = %d\n",nextNode);
		if (nextNode == -1) {
			return false;
		}
		currentState = nextNode;
	}

	// Chegou aqui, entao toda a palavra tinha transicao
	// Agora testar se o estado em que acabou o automato é um estado final

	return isFinalState(currentState);
}

int Dfa::getNumberOfDfas() {
	return Dfa::numberOfDfas;
}

void Dfa::addFinalState(int state) {
	finalStates.push_back(state);
	//printf("inserido estado %d agora lista de estados finais tem %d elementos\n",state,finalStates.size());
}

void Dfa::setStartState(int state) {
	startState = state;
}

int Dfa::getStartState() {
	return startState;
}

void Dfa::listStates() {
	int i;
	for (i = 0; i < (int)finalStates.size(); i++) {
		//printf("%d\n",finalStates[i]);
	}
}

void Dfa::isValidTransition(int state) const {
	if (state < 0 || state >= getNStates()) {
		throw invalidState;
	}
}

bool Dfa::isFinalState(int state) const {
	for (int i=0; i<(int)finalStates.size(); i++) {
		if (finalStates[i] == state) {
			return true;
		}
	}
	return false;
}

void Dfa::readStartState(FILE *p) {
	int number;
	fscanf(p,"%d",&number);
	// Seta o estado inicial
	setStartState(number);
}

void Dfa::readFinalStates(FILE *p) {
	int i,finalState;
	// Le primeiro a quantidade de estados finais
	int qtdFinalStates = 0;
	fscanf(p,"%d",&qtdFinalStates);

	// Agora percorre um laço pegando os estados finais e adicionando no vetor de estados finais
	for (i=0; i<qtdFinalStates; i++) {
		fscanf(p,"%d",&finalState);
		addFinalState(finalState);
	}
}

void Dfa::readNStates(FILE *p) {
	int number;
	fscanf(p,"%d",&number);
	// Seta a quantidade de estados
	setNStates(number);

	for (int i=0; i<nStates; i++) {
		Node *n = new Node(i);
		automatos.push_back(n);
	}

	for (int i=0; i<nStates; i++) {
		//printf("Estado %d Posicao %d\n",automatos[i]->id,i);
	}
}

void Dfa::readTransitions(FILE *p) {
	int fonteState, destinoState;
	char transition;
	try {
		while (fscanf(p,"%d %d %c",&fonteState, &destinoState, &transition) != EOF) {
			isValidTransition(fonteState);
			isValidTransition(destinoState);
			automatos[fonteState]->addTransition(destinoState,transition);
			//printf("Fonte: %d Destino: %d Transicao: %c\n",fonteState, destinoState, transition);
		}
	} catch (InvalidState &e) {
		fprintf(stderr, "%s\n\n",e.what());
		exit(1);
	}
}

void Dfa::listAllTransitions() {
	for (int i=0; i<nStates; i++) {
		//printf("Id %d\n",automatos[i]->id);
		for (int j=0; j<(int)automatos[i]->transitions.size(); j++) {
			//printf("Transicao para %d valor %c\n",automatos[i]->transitions[j]->destino, automatos[i]->transitions[j]->transicao);
		}
	}
}

