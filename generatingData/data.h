#ifndef _DATA_H
#define _DATA_H
#include<iostream>
//#include<istream>
#include<fstream>
#include<sstream>
#include<vector>
#include<string>
#include"includes.h"

using namespace std;
int getData(const string dataPath, vector<string>& data, const unsigned int numLine);
int getData1(const string dataPath, vector<vector<string>>& data, const unsigned int numLine);
void show(const vector<string>& data);
void show1(const vector<vector<string>>);

#endif
