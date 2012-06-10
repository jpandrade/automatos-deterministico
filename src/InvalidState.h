/*
 * InvalidState.h
 *
 *  Created on: May 22, 2012
 *      Author: jpga
 */

#ifndef INVALIDSTATE_H_
#define INVALIDSTATE_H_

#include <exception>

using std::exception;

class InvalidState: public exception {
	public:
		virtual const char* what() const throw() {
			return "Estado inválido, programa finalizado!";
		}
} invalidState;

#endif /* INVALIDSTATE_H_ */
