#include <stdio.h>
#include <string.h>
#include <stdlib.h> 

#include "Helpers.h"
#include "Vigenere.h"
#define _CRT_SECURE_NO_DEPRECATE
#define _CRT_SECURE_NO_WARNINGS
int main(int argc, char** argv) {
	FILE* inputFile = NULL;
	FILE* outputFile = NULL;
	int i;
	int size = 0;
	// flags
	char decryptFlag[] = "-d";
	char encryptFlag[] = "-e";
	char outputFlag[] = "-o";
	char inputFlag[] = "-i";
	char keyFlag[] = "-k";
	// encryption
	VIGENERE_MODE encrypt = 0;
	// paths
	char* output;
	char* input;
	// buffer
	char* buffer;
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
		}
		else
			if (!strcmp(argv[i], outputFlag)) {
				output = argv[++i];
			}
			else
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
	// check no action flag found, exit
	if (!encrypt) {
		displayHelp();
		exit(3);
	}
	// check if key has only CAPITALS
	for (i = 0; i < strlen(key);i++) {
		if (islower(key[i])) {
			exit(4);
		}
	}

	// open files
	inputFile = fopen(input, "rb");
	if (NULL == inputFile) {
		logError(errno);
		exit(1);
	}

	outputFile = fopen(output, "wb");
	if (NULL == outputFile) {
		logError(errno);
		exit(2);
	}
	// foreach chunk encrypt
	buffer = (char*)malloc(strlen(key)*CHUNK_SIZE);
	for (size = fread(buffer, sizeof(char), CHUNK_SIZE*strlen(key), inputFile);size != 0;size = fread(buffer, sizeof(char), CHUNK_SIZE*strlen(key), inputFile)) {
		// process every chunk
		vigenereEncrypt(buffer, key, size, encrypt);
		// write result of the processing
		fwrite(buffer, sizeof(char), size, outputFile);
	}

	// close all files
	fclose(inputFile);
	fclose(outputFile);
	// free buffer
	free(buffer);

}

