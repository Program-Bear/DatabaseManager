#ifndef _SCHEMA_ENTRY_H
#define _SCHEMA_ENTRY_H

#include <string>
#include <list>
#include "Attr.h"

using std::string;
using std::list;

class SchemaEntry
{
public:
    enum EntryKind { NORMAL_KIND, PRIMARY_KIND, FOREIGN_KIND };
    
    SchemaEntry() {}
    
    SchemaEntry(string& f, string& t, int len, int notN) :
    	field(f), type(t), length(len), notNull(notN)
    {
    	
    }
    
    string field;
    string type;
    int length;
    bool notNull;
    
    EntryKind entrykind;
    
    // PRIMARY KEY
    list<string> primaryKeyList;
    
    // FOREIGN KEY
    string foreignKey;
    Attr foreignAttr;
};

#endif
