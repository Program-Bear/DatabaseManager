#ifndef HX_SELECTOR_H
#define HX_SELECTOR_H

#include <string>
#include "Attr.h"
using namespace std;

class Selector
{
public: 
	enum SelectorType 
	{ 
		SELECTOR_ALL_TYPE, 
		SELECTOR_COL_TYPE, 
		SELECTOR_SUM_TYPE, 
		SELECTOR_AVG_TYPE, 
		SELECTOR_MAX_TYPE, 
		SELECTOR_MIN_TYPE
	};

	Selector() {}
    Selector(SelectorType s) : selectorType(s) {}
	Selector(SelectorType s, Attr c) : selectorType(s), col(c) {}
	
	SelectorType selectorType;
	
	Attr col;
};

#endif
