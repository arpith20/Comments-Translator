/*
 * config.h
 *
 *  Created on: 12-Jan-2017
 *      Author: arpith
 */

#ifndef CONFIG_H_
#define CONFIG_H_

#include <string>


bool translate_single_line = true;
bool translate_multi_line = true;

std::string single_line_comment = "//";
std::string multi_line_comment_start = "/*";
std::string multi_line_comment_end = "*/";

//Path where the trans perl script is saved.
//For more information on 'trans', visit https://github.com/soimort/translate-shell
std::string path = "./";

//The final command to execute will be:
//command_part1 + "text to translate" + command_part2
//Eg "./trans -no-auto -brief \""+ 可爱 +"\" | tr -d '\n'";
std::string command_part1 = "trans -no-auto -brief \"";
std::string command_part2 = "\" | tr -d '\n'";


#endif /* CONFIG_H_ */
