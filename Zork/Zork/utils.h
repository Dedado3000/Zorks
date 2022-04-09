#pragma once
#ifndef __Utils__
#define __Utils__

#include <string>
#include <vector>

using namespace std;



void Tokenize(const string& line, vector<string>& args);

bool IsEquals(const string& a, const char* b);

#endif //__Utils__