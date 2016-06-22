#include <stdio.h>
#include <string.h>
#include "Helpers.h"
#include "Vigenere.h"
#define BUFFER_SIZE 256
int main(int argc, char** argv) {
	// testing 
	char testKey[] = "tajne";
	char testData[] = "mo srwm bjehso cnngy crolt";
	int i;
	// flags
	char decryptFlag[] = "-d";
	char encryptFlag[] = "-e";
	char outputFlag[] = "-o";
	char inputFlag[] = "-i";
	char keyFlag[] = "-k";
	// encryption
	short encrypt = 0;
	// paths
	char* output;
	char* input;
	// buffer
	char buffer[BUFFER_SIZE];
	// key
	char* key;
	// check for flags
	if (argc != 8) {
		displayHelp();
	}
	// parse command line arguments
	for (i = 1;i < argc;i++) {
		if (!strcmp(argv[i], decryptFlag)) {
			encrypt = DECRYPT;
		} else
		if (!strcmp(argv[i], outputFlag)) {
			output = argv[++i];
		}else
		if (!strcmp(argv[i], inputFlag)) {
			input = argv[++i];
		}
		if (!strcmp(argv[i], keyFlag)) {
			key = argv[++i];
		}
		else
		if (!strcmp(argv[i], encryptFlag)) {
			encrypt = ENCRYPT;
		}
	}

	switch (encrypt) {
		case ENCRYPT:
			vigenereEncrypt(testData, testKey, ENCRYPT);
		case DECRYPT:
			vigenereEncrypt(testData, testKey, DECRYPT);
	}


	
	printf("%s", testData);

}

