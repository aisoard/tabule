#include "crunch.h"

#include "main.h"
#include "utf8.h"

#include <iostream>
#include <string>

void crunch_chunk(chunk_t & chunk, tabs_t & tabs) {
	/* For each new line in the chunk */
	for(static int i = 0; i < chunk.size(); i++) {
		int k;

		/* Update min size of each tab */
		for(k = 0; k < chunk[i].size()-1; k++) {
			while(k >= tabs.size())
				tabs.push_back(0);

			tabs[k] = std::max<int>(tabs[k], utf8_length(chunk[i][k]));
		}

		/* When number of tab decrease, update offset of corresponding tabs on previous lines with enought tab */
		while(k < tabs.size()) {
			for(int j = i-1; j >= 0 && k < chunk[j].size()-1; j--)
				for(int x = std::max<int>(min_tab_width, tabs.back()+1) - utf8_length(chunk[j][tabs.size()-1]); x > 0; x--)
					chunk[j][tabs.size()-1].push_back(' ');

			tabs.pop_back();
		}

		/* Print until this line with no tab */
		if(!k) {
			while(i > 0) {
				for(int l = 0; l < chunk[0].size(); l++)
					std::cout << chunk[0][l];

				std::cout << std::endl;

				chunk.pop_front();
				i--;
			}
		}
	}
}
