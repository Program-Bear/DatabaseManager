#ifndef _SCHEMA_ENTRY_H
#define _SCHEMA_ENTRY_H

#include <string>
#include <vector>
#include "Attr.h"

using std::string;
using std::vector;

class SchemaEntry
{
public:
    enum EntryKind { NORMAL_KIND, PRIMARY_KIND, FOREIGN_KIND };
    
    SchemaEntry() {}
    
    SchemaEntry(string& f, string& t, int len, int notN) :
    	field(f), type(t), length(len), notNull(notN)
    {
    	
    }

    string toString()
    {
        string ans = "";
        
        if (entrykind == SchemaEntry::NORMAL_KIND)
        {
            ans += field + " " + type;
            if (type == "int" || type == "varchar")
            {
                ans += "(" + std::to_string(length) + ")";
            }
            ans += notNull ? " NOT NULL" : "";
        }                      
        else if (entrykind == SchemaEntry::PRIMARY_KIND)
        {
            ans += "Primary Key : ";

            for (auto name : primaryKeyList)
            {
                ans += name + ", ";
            } 
        }
        else if (entrykind == SchemaEntry::FOREIGN_KIND)
        {
            ans += "Foreign Key : " + foreignKey + " ";
            ans += "REFERENCES " + foreignAttr.tbname + "." + foreignAttr.attrname;
        }

        return ans;
    }
    
    string field;
    string type;
    int length;
    bool notNull;
    
    EntryKind entrykind;
    
    // PRIMARY KEY
    vector<string> primaryKeyList;
    
    // FOREIGN KEY
    string foreignKey;
    Attr foreignAttr;
};

#endif
