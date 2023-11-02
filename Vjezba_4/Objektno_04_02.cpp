#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <sstream>
#include <cstring>
#include "Objektno_04.hpp"
using namespace std;


int zad1(string str, string substr) {
	int count = 0;

	int found = str.find(substr, 0);
	while (found != string::npos) {
		count++;
		found = str.find(substr, found + 1);
	}

	return count;
}




bool isPunctuation(char c) {
	return ((c == '.') || (c == ',') || (c == '?') || (c == '!'));
}

string zad2(string str) {
	string res = "";
	int len = str.length();
	char tempBefore = ' ', tempAfter = ' ';


	int i = 0, j = -1;

	bool spaceFound = false;

	while (++j < len && str[j] == ' ');

	while (j < len)
	{
		if (str[j] != ' ')
		{
			if ((str[j] == '.' || str[j] == ',' ||
				str[j] == '?') && i - 1 >= 0 &&
				str[i - 1] == ' ')
				str[i - 1] = str[j++];

			else
				str[i++] = str[j++];

			spaceFound = false;
		}
		else if (str[j++] == ' ')
		{
			if (!spaceFound)
			{
				str[i++] = ' ';
				spaceFound = true;
			}
		}
	}

	if (i <= 1) {
		str.erase(str.begin() + i, str.end());
	}
	else {
		str.erase(str.begin() + i - 1, str.end());
	}

	len = str.length();

	

	for (int i = 0; i < len; i++) {
		if (isPunctuation(str[i])) {
			if (i == 0) {
				tempAfter = str[i + 1];
				if (tempAfter != ' ') {
					str.insert(i + 1, " ");
				}
			}

			else if (i == (len - 1)) {
				tempBefore = str[i - 1];
				if (tempBefore == ' ') {
					str.erase(str.begin() + i - 1);
				}
			}

			else {
				tempBefore = str[i - 1];
				tempAfter = str[i + 1];

				if (tempAfter != ' ') {
					str.insert(i + 1, " ");
				}

				if (tempBefore == ' ') {
					str.erase(str.begin() + i - 1);
				}
			}
		}

	}

	return str;
}


void zad3(vector<string>& vektor) {

	string str;

	for (int i = 0; i < vektor.size(); i++) {
		cout << "Enter a string" << endl;
		getline(cin, str);

		reverse(str.begin(), str.end());
		vektor.at(i) = str;
	}
	cout << "\n";

	sort(vektor.begin(), vektor.end());

	for (int i = 0; i < vektor.size(); i++) {
		cout << vektor.at(i) << endl;
	}
}



bool is_vowel(char c)
{
	c = tolower(c);
	return c == 'a'
		or c == 'e'
		or c == 'i'
		or c == 'o'
		or c == 'u'
		;
}

void piglatin(string& str)
{
	stringstream ss(str);
	string pig_latin;
	string word;
	int i = 0;
	char punct;
	while (ss >> word)
	{
		if (ispunct(word.back()))
		{
			punct = word.back();
			word.pop_back();
		}
		if (is_vowel(word[0])) {
			word += "hay";
			pig_latin += word + ' ';
		}
		else {
			while (!is_vowel(word[i]))
			{
				word.push_back(word[i]);
				word.erase(word.begin());
			}
			word += "ay";
			pig_latin += word + ' ';
		}
	}
	pig_latin.pop_back();
	pig_latin += punct;
	cout << pig_latin;
}

