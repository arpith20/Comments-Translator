/*
 * translator.cpp
 *
 *  Created on: 12-Jan-2017
 *      Author: arpith
 */

#include <fstream>
#include <iostream>
#include <array>
#include <memory>
#include "translator.h"
#include "config.h"

using namespace std;

translator::translator() {
	multi_line = false;
	translated = "";

}

void translator::usage() {
	string line;
	ifstream myfile("usage");
	if (myfile.is_open()) {
		while (getline(myfile, line)) {
			cout << line << '\n';
		}
		myfile.close();
	}

	else
		cout << "Unable to open file";
}

bool translator::translate_file(char *file) {
	cout << " Translating " << file << endl;

	string line;
	ifstream infile(file);
	ofstream outfile("result.txt");
	if (infile.is_open()) {
		while (getline(infile, line)) {
			line = process(line);
			outfile << line << endl;
		}
		infile.close();
		outfile.close();
	}

	else
		cout << "Unable to open file";

	cout << "Translating " << file << " was successful." << endl;
	return true;
}

string exec(const char* cmd) {
	array<char, 128> buffer;
	string result;
	shared_ptr<FILE> pipe(popen(cmd, "r"), pclose);
	if (!pipe)
		throw runtime_error("popen() failed!");
	while (!feof(pipe.get())) {
		if (fgets(buffer.data(), 128, pipe.get()) != NULL)
			result += buffer.data();
	}
	return result;
}

string translator::process(string line) {
	string command;
	if (multi_line == true) {

		cout << "Multi line: " << line << "\n";

		if (line.find("*/") != string::npos) {
			multi_line = false;
			translated = line.substr(0, line.find("*/"));
		} else
			translated = line;

		command = path + command_part1 + translated + command_part2;

		translated = exec(command.c_str());
		cout << "\t translated: " << translated << endl;

		if (line.find("*/") != string::npos) {
			line = translated + line.substr(line.find("*/"));
		} else {
			line = translated;
		}

		return line;
	}
	if (line.find("//") != string::npos && translate_single_line) {

		cout << " Single line: " << line << "\n";
		translated = line.substr(line.find("//") + 2);

		command = path + command_part1 + translated + command_part2;

		translated = exec(command.c_str());
		cout << "\t Translated: " << translated << endl;

		line = line.substr(0, line.find("//") + 2) + translated;

		return line;
	}
	if (line.find("/*") != string::npos && translate_multi_line) {

		cout << "Multi line: " << line << "\n";
		multi_line = true;

		if (line.find("*/") != string::npos) {
			multi_line = false;
			translated = line.substr(line.find("/*") + 2,
					(line.find("*/")) - (line.find("/*") + 2));
		} else
			translated = line.substr(line.find("/*") + 2);

		command = path + command_part1 + translated + command_part2;

		translated = exec(command.c_str());
		cout << "\t translated: " << translated << endl;

		if (line.find("*/") != string::npos) {
			string line1 = line.substr(0, line.find("/*") + 2);
			string line2 = line.substr(line.find("*/"));
			line = line1 + translated + line2;
		} else {
			line = line.substr(0, line.find("/*") + 2) + translated;
		}

		return line;
	}
	cout << "No comment: " << line << "\n";
	return line;
}
