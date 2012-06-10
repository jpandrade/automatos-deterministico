/*
 * Node.h
 *
 *  Created on: Jun 6, 2012
 *      Author: jpga
 */

#ifndef NODE_H_
#define NODE_H_

#include "Common.h"
#include "Transitions.h"
#include <vector>
using std::vector;

class Node {

private:
	int id;
	vector<Transitions*> transitions;
public:
	Node();
	Node(int);
	virtual ~Node();

	void addTransition(int, char);

	int haveTransition(char transicao) {
		for (int i=0; i<(int)transitions.size(); i++) {
			if (transitions[i]->transicao == transicao) {
				return transitions[i]->destino;
			}
		}
		return -1;
	}
	friend class Dfa;
};

#endif /* NODE_H_ */
