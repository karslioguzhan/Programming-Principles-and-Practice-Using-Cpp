#include "Symbol_table.h"

Symbol_table* Symbol_table::getInstance()
{
	if (referenceSymbolTable == nullptr)
	{
		referenceSymbolTable = new Symbol_table;
	}
	return referenceSymbolTable;
}

// Get string values
double Symbol_table::get_value(string s)
{
	// Iterate through vector and check if input string is in names
	for (int i = 0; i < names.size(); ++i)
		if (names[i].name == s) return names[i].value;
	error("get: undefined name ", s);
}

// Setter for names with string and value
void Symbol_table::set_value(string s, double d)
{
	for (int i = 0; i <= names.size(); ++i)
		if (names[i].name == s) {
			names[i].value = d;
			return;
		}
	error("set: undefined name ", s);
}

// Check if string is declared
int Symbol_table::is_declared(string s)
{
	for (int i = 0; i < names.size(); ++i)
		if (names[i].name == s) return i;
	return -1;
}

// Handle declarations
double Symbol_table::declaration()
{
	Token t = ts.get();
	// kind name
	if (t.kind != 'a') error("name expected in declaration");
	string name = t.name;
	// Case for const
	if (strcmp(name.c_str(), "const") == 0)
	{
		Token variableNameToken = ts.get();
		if (variableNameToken.kind != 'a')
		{
			error("name expected in declaration");
		}
		string name = variableNameToken.name;
		Token equalSignToken = ts.get();
		if (equalSignToken.kind != '=') error("= missing in declaration of ", name);
		double d = expression();
		int searchResult{ is_declared(name) };
		if (searchResult >= 0 && !names.at(searchResult).isConst) // TODO Continue here
		{
			names.at(searchResult).value = d;
			names.at(searchResult).isConst = true;
			return d;
		}
		names.push_back(Variable(name, d, true));
		return d;
	}
	// Default case
	Token t2 = ts.get();
	if (t2.kind != '=') error("= missing in declaration of ", name);
	double d = expression();
	int searchResult{ is_declared(name) };
	if (searchResult >= 0 && names.at(searchResult).isConst)
	{
		error("Cannot override const variable");
	}
	if (searchResult >= 0 && !names.at(searchResult).isConst) // TODO Continue here
	{
		names.at(searchResult).value = d;
		return d;
	}

	names.push_back(Variable(name, d, false));
	return d;
}