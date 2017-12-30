#ifndef HX_SELECTOR_H
#define HX_SELECTOR_H

#include <string>
#include "Attr.h"
using namespace std;

class Selector
{
public: 
	enum SelectorType { SELECTOR_ALL_TYPE, SELECTOR_COL_TYPE };

	Selector() {}
    Selector(SelectorType s) : selectorType(s) {}
	Selector(SelectorType s, Attr c) : selectorType(s), col(c) {}
	
	SelectorType selectorType;
	
	Attr col;
};

#endif
