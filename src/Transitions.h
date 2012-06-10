/*
 * Transitions.h
 *
 *  Created on: Jun 6, 2012
 *      Author: jpga
 */

#ifndef TRANSITIONS_H_
#define TRANSITIONS_H_

class Transitions {
	int destino;
	char transicao;
public:
	Transitions();
	Transitions(int, char);
	virtual ~Transitions();

	friend class Dfa;
	friend class Node;
};

#endif /* TRANSITIONS_H_ */
