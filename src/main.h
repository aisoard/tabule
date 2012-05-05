#ifndef MAIN_H
#define MAIN_H

#include <string>
#include <vector>
#include <deque>

typedef	std::vector<std::string> line_t;
typedef std::deque<line_t> chunk_t;

typedef std::vector<int> tabs_t;

extern int min_tab_width;
extern bool keep_tabs;

#endif // MAIN_H
