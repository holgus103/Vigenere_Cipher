#include <string.h>
#include <ctype.h>
#include "Const.h"
#define NUM_LETTERS 26
#pragma once

void vigenereEncrypt(char* data, char* key, VIGENERE_MODE mode);