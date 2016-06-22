#include "Helpers.h"

void displayHelp() {
	printf("USAGE: -o output -i input -k KEY -d|-e /n key must be CAPITAL!");
}

void logError(int err) {
	printf("Error %s", strerror(err));
}