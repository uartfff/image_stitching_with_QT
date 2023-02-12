#include"newFile.h"
#include"includes.h"
using namespace std;



/*************��ͼƬ��Ϣ�ͷɻ���̬����д��һ���ļ���*********
****************************����˵��*************************
**************newPath:���ļ���·��,ע��������.cvs�ļ�********
**************data:�ɻ���̬����******************************
**************pictureInfo:ͼƬ��Ϣ***************************/
int newDataWrite(const string newPath,vector<vector<string>>& data,pictureType& pictureInfo)
{

	ofstream outPictureFile(newPath, ios::out);
	if (!outPictureFile.is_open())
	{
		return -1;
	}

	outPictureFile << "���" << "," << "����" << ","  << "�������" << "," << "����" 
				   << "," << "γ��" << "," << "�߶�" << "," << "��ת��" << "," << "������" 
				   << "," << "ƫ����" << "," << "���ٶ�" << "," << "���ٶ�" << "," << "��ֱ�ٶ�" << ","
				   << "�����" << "," << "������" << "," << "ƫ����" << ","<< "����ʱ��"<<endl;
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
			//���ʱ����������ʱ��ĳ��׶�ʱ��
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
