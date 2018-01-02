#ifndef PARSER_DATABASE_H
#define PARSER_DATABASE_H

#include <map>
#include <string>

#include "Table.h"

using std::map;
using std::string;

class Database
{
public:
    Database() {}
    Database(string _dbName) : dbName(_dbName) {}

    string dbName;
    map<string, Table> tables;
};

#endif  // PARSER_DATABASE_H
