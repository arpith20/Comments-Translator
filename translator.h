/*
 * translator.h
 *
 *  Created on: 12-Jan-2017
 *      Author: arpith
 */

#ifndef TRANSLATOR_H_
#define TRANSLATOR_H_

#include <string>

class translator {
private:
	std::string translated;
	bool multi_line;
public:
	translator();
	void usage();
	bool translate_file(char *file_name);
	std::string process(std::string line);
};

#endif /* TRANSLATOR_H_ */
