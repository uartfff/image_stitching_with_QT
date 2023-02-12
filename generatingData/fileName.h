#ifndef _FILENAME_H
#define _FILENAME_H
#include <io.h>
#include <fstream>
#include <string>
#include <vector>
#include<time.h>
#include"includes.h"
using namespace std;
typedef struct pictureT
{
	vector<string> pictureName;
	vector<string> pictureTime;
	unsigned int   pictureNum;
}pictureType;


int GetAllFiles(const string path, pictureType& pictureInfo);
int GetAllFormatFiles(const string path, pictureType& pictureInfo, const string format);
void show(const pictureType& pictureInfo);


#endif