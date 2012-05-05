#include "parse_args.h"

#include "main.h"

#include <iostream>
#include <sstream>
#include <cstdlib>

#include <unistd.h>
#include <getopt.h>

char const * short_options = "ht:kn";

struct option const long_options[] = {
	{ "help", no_argument, NULL, 'h' },
	{ "tab-width", required_argument, NULL, 't' },
	{ "keep-tabs", no_argument, NULL, 'k' },
	{ "no-keep-tabs", no_argument, NULL, 'n' },
	{ 0, 0, 0, 0 }
};

void print_usage(char* program) {
	std::cerr << "Usage: " << program << " [OPTIONS...]" << std::endl;
	std::cerr << "Description: Read the standard input, expands tabulation into space by keeping alignments of consecutive lines, then print to standard output." << std::endl;
	std::cerr << std::endl;
	std::cerr << "  -h, --help                   print this help and quit" << std::endl;
	std::cerr << "  -t, --tab-width[=]<integer>  minimum size of a tabulation (current: " << min_tab_width << ")" << std::endl;
	std::cerr << "  -k, --keep-tabs              keep valid tabulations" << (keep_tabs ? " (current)" : "") << std::endl;
	std::cerr << "  -n, --no-keep-tabs           expand valid tabulations" << (keep_tabs ? "" : " (current)") << std::endl;
	std::cerr << std::endl;
	std::cerr << "Author: Alexandre Isoard <alexandre.isoard@gmail.com>" << std::endl;
}

int check_args(char* program) {
	if(min_tab_width > 0) {
		return 0;
	}

	std::cerr << program << ": invalid minimum tab width (" << min_tab_width << ")" << std::endl;
	return 1;
}

int parse_args(int nb_arg, char* args[]) {
	int option;

	for(option = getopt_long(nb_arg, args, short_options, long_options, NULL); option != -1; option = getopt_long(nb_arg, args, short_options, long_options, NULL)) {
		switch(option) {
			case 'k':
				keep_tabs = true;
				break;
			case 'n':
				keep_tabs = false;
				break;
			case 't':
				min_tab_width = std::atoi(optarg);
				break;
			default:
				print_usage(args[0]);
				return 1;
		}
	}

	if(check_args(args[0])) {
		print_usage(args[0]);
		return 1;
	}

	return 0;
}
