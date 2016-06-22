#include "Vigenere.h"

void vigenereEncrypt(char* data, char* key, int size, VIGENERE_MODE mode) {
	int i;
	// get key length
	int keyLength = strlen(key);
	// base
	char base;
	// key base
	char keyBase = 'A';
	// key counter
	int keyCounter = 0;
	for (i = 0; i < size; i++) {
		if (!isalpha(data[i])) {
			continue;
		}
		// get alphabetic base for letter
		base = isupper(data[i]) ? 'A' : 'a';
		data[i] = base + ((data[i] - base) + mode * (key[keyCounter % keyLength] - keyBase)) % NUM_LETTERS;
		if (data[i] < base)
			data[i] += NUM_LETTERS;
		// if key end is reached, reset the key position counter
		if (++keyCounter == keyLength)
			keyCounter = 0;

	}
		
}
