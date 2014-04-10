#ifndef PALINDROME_H
#define PALINDROME_H
#include <iostream>
#include <string>
#include <cctype>
#include "Helpers.h"

using namespace std;

namespace Palindrome{

	bool is_pal(const string& s);
	string remove_punct(const string& s, const string& punct);
	string reverse(const string& s);
	void swap(char& v1, char& v2);

	bool is_pal(const string& s){
		string punct(",;:.'?\"!");
		string str(s);
		str = Helpers::strToLower(str);

		string lower_str = remove_punct(str,punct);

		return (lower_str == reverse(lower_str));
	}
	string remove_punct(const string& s, const string& punct){

		string no_punct;
		int strlen = s.length(),
		punctlen = punct.length();

		for(int i = 0; i< strlen; ++i){
			string a = s.substr(i,1);
			int loc = punct.find(a,0);

			if(loc < 0 || loc >= punctlen){
				no_punct = no_punct + a;
			}
		}

		return no_punct;

	}
	void swap(char& v1, char& v2){
		char temp = v1;
		v1 = v2;
		v2 = temp;
	}
	string reverse(const string& s){

		string temp = s;
		int start = 0,
		end = s.length();

		while (start < end){
			end--;
			swap(temp[start], temp[end]);
			start++;
		}

		return temp;

	}
}
#endif