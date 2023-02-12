#include"newFile.h"
#include"includes.h"
using namespace std;



/*************将图片信息和飞机姿态数据写入一个文件中*********
****************************参数说明*************************
**************newPath:新文件的路径,注意命名成.cvs文件********
**************data:飞机姿态数据******************************
**************pictureInfo:图片信息***************************/
int newDataWrite(const string newPath,vector<vector<string>>& data,pictureType& pictureInfo)
{

	ofstream outPictureFile(newPath, ios::out);
	if (!outPictureFile.is_open())
	{
		return -1;
	}

	outPictureFile << "序号" << "," << "名字" << ","  << "拍摄距离" << "," << "经度" 
				   << "," << "纬度" << "," << "高度" << "," << "滚转角" << "," << "俯仰角" 
				   << "," << "偏航角" << "," << "向北速度" << "," << "向东速度" << "," << "垂直速度" << ","
				   << "横滚角" << "," << "俯仰角" << "," << "偏航角" << ","<< "创建时间"<<endl;
	for (unsigned int i = 0; i < data.size(); i++)
	{

		/*outPictureFile << i + 1 << "," << pictureInfo.pictureName[i];
		for (unsigned int j = 0; j < data[i].size(); j++)
		{
			outPictureFile << " "<<data[i][j];
		}
		outPictureFile << endl;*/
		outPictureFile << i + 1 << "," << pictureInfo.pictureName[i];
		for (unsigned int j = 0; j < data[i].size(); j++)
		{
			if(j< data[i].size()-1)
				outPictureFile << "," << data[i][j];
			//输出时将格林威治时间改成易读时间
			if (j ==data[i].size() - 1) {
				int t = stoi(data[i][j], nullptr, 10);
				long long time = t;
				data[i][j] = ctime(&time);
				outPictureFile << "," << data[i][j];
			}
		}
		//outPictureFile << endl;
		//outPictureFile << "," << pictureInfo.pictureTime[i];

	}
	outPictureFile.close();
	return 0;
}
