#ifndef COLUMN_H
#define COLUMN_H

#include <map>
#include <string>

#include "SemValue.h"

using std::map;
using std::string;

class Column
{
public:
    Column() {}
    Column(string _colName) : colName(colName) {}
    Column(string _colName, string _dataType, int _length, bool _isNotNull) :
        colName(_colName), dataType(_dataType), length(_length), isNotNull(_isNotNull), isForeign(false) {}
    Column(string _foreignKey, bool _isForeign, string t, string c) :
        isNotNull(false), colName(_foreignKey), isForeign(_isForeign), referenceTableName(t), referenceColName(c) {}

    string colName;

    string dataType;  // "int" "varchar" "date" "float"  date : "2017/12/31" stored as VARCHAR(15)
    int length;
    bool isNotNull;

    bool isForeign;
    string referenceTableName;
    string referenceColName;
};

#endif  // COLUMN_H
