#ifndef TABLE_H
#define TABLE_H

#include <map>
#include <string>

#include "Column.h"

using std::map;
using std::string;

class Table
{
public:
    // Constructor
    Table() {}
    Table(string _tbName) : tbName(_tbName) {}

    string tbName;
    map<string, Column> columns;
};

#endif  // TABLE_H
