/*
 * FileNotFoundException.h
 *
 *  Created on: May 22, 2012
 *      Author: jpga
 */

#ifndef FILENOTFOUNDEXCEPTION_H_
#define FILENOTFOUNDEXCEPTION_H_

#include <exception>

using std::exception;

class FileNotFoundException: public exception {
	public:
		virtual const char* what() const throw() {
			return "Arquivo não encontrado!";
		}
} fileNotFoundException;

#endif /* FILENOTFOUNDEXCEPTION_H_ */
