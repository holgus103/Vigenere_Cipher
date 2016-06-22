#include <string.h>
#include <ctype.h>
#include "Const.h"
#pragma once

void vigenereEncrypt(char* data, char* key, int size, VIGENERE_MODE mode);