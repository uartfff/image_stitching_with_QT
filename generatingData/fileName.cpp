#define _CRT_SECURE_NO_DEPRECATE
#include"fileName.h"
#include"includes.h"
void show(const pictureType& pictureInfo)
{
	for (unsigned long i = 0; i < pictureInfo.pictureNum; i++)
	{
		cout << pictureInfo.pictureName[i] <<"ʱ��:"<<pictureInfo.pictureTime[i]<< endl;
	}
}

//��ȡ���е��ļ���
//int GetAllFiles(const string path, pictureType& pictureInfo)
//{
//	long   hFile = 0;
//	//�ļ���Ϣ  
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

/*************��ȡͼƬ��Ϣ,����ͼƬ��,����ʱ��,ͼƬ����*********
****************************����˵��****************************
**************path:ͼƬ�ļ���·��********
**************pictureInfo:ͼƬ��Ϣ�洢����,pictureType���Զ������������********
**************format:ͼƬ��ʽ,һ��ʹ��.jpg****************************/
int GetAllFormatFiles(const string path, pictureType& pictureInfo, const string format)
{
	//�ļ����  
	//long   hFile = 0;//32λϵͳ
	intptr_t  hFile = 0;//64λϵͳ
	//�ļ���Ϣ  
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




