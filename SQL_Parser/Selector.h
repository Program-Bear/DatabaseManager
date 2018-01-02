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

    string toString()
    {
        if (selectorType == Selector::SELECTOR_ALL_TYPE)
        {
            return "*";
        }
        else if (selectorType == Selector::SELECTOR_COL_TYPE)
        {
            return col.tbname + "." + col.attrname;
        }
        else if (selectorType == Selector::SELECTOR_SUM_TYPE)
        {
            return "SUM(" + col.tbname + "." + col.attrname + ")";
        }
        else if (selectorType == Selector::SELECTOR_AVG_TYPE)
        {
            return "AVG(" + col.tbname + "." + col.attrname + ")";
        }
        else if (selectorType == Selector::SELECTOR_MAX_TYPE)
        {
            return "MAX(" + col.tbname + "." + col.attrname + ")";
        }
        else  // se.selectorType == Selector::SELECTOR_MIN_TYPE
        {
            return "MIN(" + col.tbname + "." + col.attrname + ")";
        }
    }
	
	SelectorType selectorType;
	
	Attr col;
};

#endif
