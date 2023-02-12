#include"includes.h"
using namespace std;
int omain()
{
	//照片文件夹路径
	//string picturePath = "C:\\Users\\think\\Desktop\\图像数据读取\\照片";F:\20181126大桥局冶金大道\图像数据读取\照片数据
	string picturePath = "F:\\20181126大桥局冶金大道\\图像数据读取\\照片数据";
	//飞机姿态数据路径
	//string dataPath	   = "C:/Users/think/Desktop/图像数据读取/picture.txt";
	string dataPath = "F:\\20181126大桥局冶金大道\\图像数据读取\\照片数据\\picture1.txt";
	//string picturePath = "C:\\Users\\think\\Desktop\\图像数据读取\\新建文件夹\\新建文件夹";
	//最终生成的文件路径,命名为.csv格式
	//string newDataPath = "C:\\Users\\think\\Desktop\\图像数据读取\\NewData.csv";
	string newDataPath = "F:\\20181126大桥局冶金大道\\图像数据读取\\照片数据\\匹配后的数据.csv";
	//存储图片信息的变量
	pictureType pictureInfo;
//	vector<string> data;
	//存储飞机姿态数据的容器
	vector<vector<string>> data;

	//读取所有格式为jpg的文件
	const string format = ".jpg";
	//得到图片信息
	if (GetAllFormatFiles(picturePath, pictureInfo, format) == -1)
	{
		cout << "error:can't find *.jpg files!"<<endl;
	};
//	cout << pictureInfo.pictureNum << endl;
  // show(pictureInfo);
	
	//读取数据
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
	//得到飞机姿态
	if (getData1(dataPath, data, pictureInfo.pictureNum) == -1)
	{
		cout << "error:can't open the file!" << endl;
	};
	//show1(data);

	//新生成的文件
	if (newDataWrite(newDataPath, data, pictureInfo) == -1)
	{
		cout <<"error:create file failed!"<< endl;
	}
	return 0;
}