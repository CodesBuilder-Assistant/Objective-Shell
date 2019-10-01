#ifndef ALIAS_HPP
#define ALIAS_HPP
#include <wchar.h>
#include <vector>
#include <string>
using std::vector;
using std::wstring;

extern vector<wstring>arguments;

typedef struct alias_struct
{
    wstring alias;
    wstring original;
}alias;

vector<alias>aliases;

void ReplaceAliases(void)
{
    for(int i=0;i<arguments.size();i++)
        for(int i=0;i<aliases.size();i++)
            if(arguments[i]==aliases[i].alias)
                arguments[i]=aliases[i].original;
}

void AddAlias(const wchar_t *_alias,const wchar_t *original)
{
    alias push_alias;
    push_alias.alias=_alias;
    push_alias.original=original;
    aliases.push_back(push_alias);
}

void RemoveAlias(const wchar_t *target_alias)
{
    vector<alias>aliases_after_removed_target_alias;
    for(int i=0;i<aliases.size();i++)
        if(aliases[i].alias!=target_alias)
            aliases_after_removed_target_alias.push_back(aliases[i]);
    aliases=aliases_after_removed_target_alias;
}

#endif