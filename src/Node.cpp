/*
 * Node.cpp
 *
 *  Created on: Jun 6, 2012
 *      Author: jpga
 */

#include "Node.h"

Node::Node() {}

Node::Node(int id) {
	this->id = id;
}

Node::~Node() {
	// TODO Auto-generated destructor stub
}

void Node::addTransition(int destino, char transicao) {
	Transitions *t = new Transitions(destino, transicao);
	transitions.push_back(t);
}
