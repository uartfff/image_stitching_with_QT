#ifndef _NEWFILE_H
#define _NEWFILE_H
#include"fileName.h"
#include<iostream>
#include<vector>
#include<string>
#include<fstream>
#include"includes.h"
using namespace std;

int newDataWrite(const string newPath, vector<vector<string>>& data,struct pictureT& pictureInfo);

#endif