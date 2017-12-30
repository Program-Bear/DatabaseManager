#ifndef HX_SET_H
#define HX_SET_H

#include <list>
#include <string>
#include "Value.h"
using namespace std;

class Set
{
public: 
	Set() {}
    Set(string s, Value v) : colName(s), value(v) {}
    
	string colName;
	Value value;
};

#endif
