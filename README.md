# Comments Translator
A tool to translate comments in the source code.   

## Compile

<pre>
$ make clean
$ make 
</pre>

## Usage

<pre>
$ bin/translate file1 [file2 file3 ...]
</pre>
After the execution of the program, the comments in file1[, file2, file3, ...] would have all been translated.

## Notes

* Internally, this uses [command line translator](https://github.com/soimort/translate-shell). The script must be present in the bin/ directory and must have execute permissions. If not, download it from [here](https://github.com/soimort/translate-shell#user-content-option-1-direct-download) and grant the permission. Also, `gawk` is required for the functioning of this script. To install, please run `sudo apt-get install gawk`
* If you wish to translate the comments to a language other than English, modify the variable `command_part1` in `config.h` with parameters as specified in this [README](https://github.com/soimort/translate-shell#user-content-translate-a-word). 
* By default, this tool is set up to translate C/C++ programs. Modify the parameters in `config.h` if you wish to translate codes which use a different syntax to identify the comments. 
* Recompile the code if any changes to `config.h` is made.
