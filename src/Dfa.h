/*
 * Dfa.h
 *
 *      Author:
 *      e-mail:
 */

#ifndef DFA_H_
#define DFA_H_

#include "Common.h"
#include "DfaInterface.h"
#include "Node.h"
#include <vector>
using std::vector;

class Dfa : public DfaInterface
{

private:
	int nStates;
	vector<int> finalStates;
	vector<Node*> automatos;
	int startState;
public:
	static int numberOfDfas;
	// Construtor
	Dfa(char*);

	//Construtor de Copia
	Dfa(Dfa&);

	// Sobrecarregando o operador =
	//Dfa& Operator=(const Dfa&);

	void loadFromFile(const char* inputFilename);

	bool eval(const char* input, int sizeInput) const;

	int getNStates() const;
	void setNStates(int);

	static int getNumberOfDfas();

	void addFinalState(int);

	bool isFinalState(int) const;

	void setStartState(int);

	int getStartState();

	// Métodos de leitura no arquivo

	void readStartState(FILE *);

	void readFinalStates(FILE *);

	void readNStates(FILE *);

	void readTransitions(FILE *);

	// Métodos de transição

	void isValidTransition(int) const;






	// Deletar depois
	void listAllTransitions();

	void listStates();

};

#endif /* DFA_H_ */
