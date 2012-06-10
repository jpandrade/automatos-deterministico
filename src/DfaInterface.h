/*
 * DfaInterface.h
 *
 *      Author:
 *      e-mail:
 */

#ifndef DFAINTERFACE_H_
#define DFAINTERFACE_H_

class DfaInterface {

public:
	virtual ~DfaInterface();
	virtual bool eval(const char* input, int sizeInput) const = 0;
	virtual void loadFromFile(const char* inputFilename) = 0;

};

#endif /* DFAINTERFACE_H_ */
