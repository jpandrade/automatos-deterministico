/*
 * main.cpp
 *
 *      Author:
 *      e-mail:
 */

#include "Dfa.h"
#include "DfaInterface.h"
#include "Common.h"

const char* howToUsage();

int main(int argc, char **argv)
{
	DfaInterface *dfa;
	char* filename, input[100];

	if (argc < 2) {
		fprintf(stderr, "Utilizacao errada!\n\n");
		fprintf(stderr, "%s", howToUsage());
		exit(1);
	}
	filename = new char[strlen(argv[1]+1)];
	strcpy(filename, argv[1]);

	dfa = new Dfa(filename);

	while (scanf ("%s", input) != EOF) {
		if (dfa->eval(input, strlen(input)) == true)
			printf ("accepted!\n");
		else
			printf ("not accepted!\n");
	}

	return 0;
}

const char* howToUsage()
{
	return "Entrada:\n"
			"$ ./dfa [filename]\n"
			"\n"
			"Onde:\n"
			"  filename: nome do arquivo de configuração do automato finito "
			"deterministico.\n\n";
}
