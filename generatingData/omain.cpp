#include"includes.h"
using namespace std;
int omain()
{
	//��Ƭ�ļ���·��
	//string picturePath = "C:\\Users\\think\\Desktop\\ͼ�����ݶ�ȡ\\��Ƭ";F:\20181126���ž�ұ����\ͼ�����ݶ�ȡ\��Ƭ����
	string picturePath = "F:\\20181126���ž�ұ����\\ͼ�����ݶ�ȡ\\��Ƭ����";
	//�ɻ���̬����·��
	//string dataPath	   = "C:/Users/think/Desktop/ͼ�����ݶ�ȡ/picture.txt";
	string dataPath = "F:\\20181126���ž�ұ����\\ͼ�����ݶ�ȡ\\��Ƭ����\\picture1.txt";
	//string picturePath = "C:\\Users\\think\\Desktop\\ͼ�����ݶ�ȡ\\�½��ļ���\\�½��ļ���";
	//�������ɵ��ļ�·��,����Ϊ.csv��ʽ
	//string newDataPath = "C:\\Users\\think\\Desktop\\ͼ�����ݶ�ȡ\\NewData.csv";
	string newDataPath = "F:\\20181126���ž�ұ����\\ͼ�����ݶ�ȡ\\��Ƭ����\\ƥ��������.csv";
	//�洢ͼƬ��Ϣ�ı���
	pictureType pictureInfo;
//	vector<string> data;
	//�洢�ɻ���̬���ݵ�����
	vector<vector<string>> data;

	//��ȡ���и�ʽΪjpg���ļ�
	const string format = ".jpg";
	//�õ�ͼƬ��Ϣ
	if (GetAllFormatFiles(picturePath, pictureInfo, format) == -1)
	{
		cout << "error:can't find *.jpg files!"<<endl;
	};
//	cout << pictureInfo.pictureNum << endl;
  // show(pictureInfo);
	
	//��ȡ����
	//if (getData(dataPath, data, pictureInfo.pictureNum) == -1)
	//{
	//	cout << "error:can't open the file!" << endl;
	//};
//	show(data);
//	cout << endl<<endl;
	//for (int i = 0; i < data[0].size(); i++)
	//{
	//	cout << i<<":"<<data[0][i] << "####  ";
	//}
	//�õ��ɻ���̬
	if (getData1(dataPath, data, pictureInfo.pictureNum) == -1)
	{
		cout << "error:can't open the file!" << endl;
	};
	//show1(data);

	//�����ɵ��ļ�
	if (newDataWrite(newDataPath, data, pictureInfo) == -1)
	{
		cout <<"error:create file failed!"<< endl;
	}
	return 0;
}