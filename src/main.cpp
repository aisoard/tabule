#include <iostream>
#include <sstream>

#include <string>
#include <vector>
#include <deque>

#include "main.h"
#include "parse_args.h"
#include "crunch.h"

int min_tab_width = 8;

int main(int nb_arg, char* args[]) {
	if(parse_args(nb_arg, args)) {
		return 1;
	}

	tabs_t tabs;
	chunk_t chunk;
	line_t line;
	std::string raw;

	for(std::getline(std::cin, raw); std::cin.good(); std::getline(std::cin, raw)) {
		std::stringstream sraw(raw);
		std::string tab;

		for(line.clear(); sraw.good(); line.push_back(tab))
			std::getline(sraw, tab, '\t');

		chunk.push_back(line);

		crunch_chunk(chunk, tabs);
	}

	chunk.push_back(line_t(1, ""));

	crunch_chunk(chunk, tabs);

	return 0;
}
