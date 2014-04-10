#ifndef HELPERS_H
#define HELPERS_H

#include <string>
#include <sstream>

using namespace std;

namespace Helpers{
	string strToLower(string str){
		for(std::string::size_type i=0;i<str.length();++i){
			str[i] = tolower(str[i]);
		}
		return str;
	}
	bool StringToDouble(const string& s, double &i){
		istringstream myStream(s);

		if(myStream >> i)
			return true;
		else
			return false;
	}
	bool StringToInt(const string &s, int &i)
	{
		istringstream myStream(s);

		if (myStream>>i)
			return true;
		else
			return false;
	}
}

#endif