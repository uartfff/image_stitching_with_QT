#define _CRT_SECURE_NO_DEPRECATE
#include"fileName.h"
#include"includes.h"
void show(const pictureType& pictureInfo)
{
	for (unsigned long i = 0; i < pictureInfo.pictureNum; i++)
	{
		cout << pictureInfo.pictureName[i] <<"时间:"<<pictureInfo.pictureTime[i]<< endl;
	}
}

//获取所有的文件名
//int GetAllFiles(const string path, pictureType& pictureInfo)
//{
//	long   hFile = 0;
//	//文件信息  
//	struct _finddata_t fileinfo;
//	string p;
//	pictureInfo.pictureNum = 0;
//	hFile = _findfirst(p.assign(path).append("\\*").c_str(), &fileinfo);
//	if (hFile == -1)
//		return -1;
//	else
//	{
//		do
//		{
//			if ((fileinfo.attrib &  _A_SUBDIR))
//			{
//				if (strcmp(fileinfo.name, ".") != 0 && strcmp(fileinfo.name, "..") != 0)
//				{
//					GetAllFiles(p.assign(path).append("\\").append(fileinfo.name), pictureInfo);
//				}
//			}
//			else
//			{
//				pictureInfo.pictureNum++;
//				pictureInfo.pictureName.push_back(p.assign(fileinfo.name));
//				cout <<&fileinfo.time_create<<endl;
//				pictureInfo.pictureTime.push_back(p.assign(ctime(&fileinfo.time_create)));
//			}
//
//		} while (_findnext(hFile, &fileinfo) == 0);
//
//		_findclose(hFile);
//	}
//	return 0;
//
//}

/*************获取图片信息,包括图片名,创建时间,图片数量*********
****************************参数说明****************************
**************path:图片文件夹路径********
**************pictureInfo:图片信息存储容器,pictureType是自定义的数据类型********
**************format:图片格式,一般使用.jpg****************************/
int GetAllFormatFiles(const string path, pictureType& pictureInfo, const string format)
{
	//文件句柄  
	//long   hFile = 0;//32位系统
	intptr_t  hFile = 0;//64位系统
	//文件信息  
	struct _finddata_t fileinfo;
	string p;
	pictureInfo.pictureNum = 0;
	//hFile = _findfirst(p.assign(path).append("\\*" + format).c_str(), &fileinfo);
	hFile = _findfirst(p.assign(path).append("/*" + format).c_str(), &fileinfo);
	if (hFile == -1)
		return -1;
	else 
	{
		do
		{
			if ((fileinfo.attrib &  _A_SUBDIR))
			{
				if (strcmp(fileinfo.name, ".") != 0 && strcmp(fileinfo.name, "..") != 0)
				{
					//GetAllFormatFiles(p.assign(path).append("\\").append(fileinfo.name), pictureInfo, format);
					GetAllFormatFiles(p.assign(path).append("/").append(fileinfo.name), pictureInfo, format);
				}
			}
			else
			{
				pictureInfo.pictureNum++;
				pictureInfo.pictureName.push_back(p.assign(fileinfo.name));
				pictureInfo.pictureTime.push_back(p.assign(ctime(&fileinfo.time_create)));
			}
		} while (_findnext(hFile, &fileinfo) == 0);

		_findclose(hFile);
	}
	return 0;
}




