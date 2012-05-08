#include "utf8.h"

#include <string>
#include <unicode/utf8.h>

namespace std {
	int utf8_length(string const utf8_string) {
		int count = 0;

		for(auto i = utf8_string.begin(); i != utf8_string.end(); i++) {
			if(U8_IS_SINGLE(*i) || U8_IS_LEAD(*i))
				count++;
		}

		return count;
	}
}
