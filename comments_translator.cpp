//============================================================================
// Name        : comments_translator.cpp
// Author      : Arpith K
// Version     :
// Copyright   : 
// Description : Hello World in C, Ansi-style
//============================================================================

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "translator.h"

using namespace std;

int main(int argc, char *argv[]) {
	translator t;
	if (argc == 1) {
		t.usage();
		return EXIT_FAILURE;
	}
	for (int i = 1; i < argc; i++) {
		cout<<i<<". ";
		if(!t.translate_file(argv[i])){
			cout<<"Translating "<<argv[i]<<" failed"<<endl;
		}
	}
	return EXIT_SUCCESS;
}
