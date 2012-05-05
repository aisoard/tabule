#include "utf8.h"

#include <string>

namespace std {
	int utf8_length(string const utf8_string) {
		int count = 0;

		for(auto i = utf8_string.begin(); i != utf8_string.end(); i++) {
			unsigned char k = *i;
			if(0b00100000 <= k && k < 0b10000000 || 0b11000000 <= k)
				count++;
		}

		return count;
	}
}
