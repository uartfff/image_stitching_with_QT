#include"data.h"
#include"includes.h"
/**********��ȡ�ɻ���̬����Ϣ����************
*******************����˵��******************
************dataPath:TXT�ļ�·��,�ļ���ÿ�д���һ����Ϣ*************
************data:������Ϣ������,Ҫ��ǰ����,���ú�������Ϣ�ͱ��������������*******
************numLine:��ȡ�ļ�������************
************����0�����ȡ�ɹ�,-1�����ȡʧ��*/
int getData(const string dataPath, vector<string>& data, const unsigned int numLine)
{
	ifstream  dataFile(dataPath, std::ios::ate);//��λ���ļ�ĩβ
	static vector<string> data1;
	data1.push_back("error:can't open file");
	if (!dataFile.is_open())
	{
		return -1;
	}
	dataFile.seekg(-2, dataFile.cur);//��ĩβ���������ַ�,�ܿ����з�

	// �ٶ������ȡlineCount�м�¼
//	int lineCount = 3;
	for (unsigned int i = 0; i < numLine; i++)
	{
		// �鿴��ǰһ���ַ��Ƿ�Ϊ�س������ж��Ƿ�һ�н������Ҳ�Ϊ�ļ�ͷ
		while (dataFile.peek() != dataFile.widen('\n') && (long)dataFile.tellg() != 0)
		{
			dataFile.seekg(-1, dataFile.cur);
		}
		//��Ϊ���з�,���ж���һ��
		if (dataFile.peek() == dataFile.widen('\n'))
		{
			dataFile.seekg(-1, dataFile.cur);
		}
	}
	if ((long)dataFile.tellg() != 0)	//�����һ��,����ָ���ʱָ�����һ�е���һ��ĩβ,
	{									//������3������ָ�����һ�еĿ�ͷ
		dataFile.seekg(3, dataFile.cur);
	}

	string  dataLine;
	//�����е����ݶ���result��
	while (getline(dataFile, dataLine))
	{
		data.push_back(dataLine);
	}
	dataFile.close();
	return 0;
};



/**********��ȡ�ɻ���̬����Ϣ����************
*******************����˵��******************
************dataPath:TXT�ļ�·��,�ļ���ÿ�д���һ����Ϣ*************
************data:������Ϣ�Ķ�ά����,Ҫ��ǰ����,���ú�������Ϣ�ͱ��������������*******
************numLine:��ȡ�ļ�������************
************����0�����ȡ�ɹ�,-1�����ȡʧ��*/
int getData1(const string dataPath, vector<vector<string>>& data, const unsigned int numLine)
{
	ifstream  dataFile(dataPath, std::ios::ate);//��λ���ļ�ĩβ
	//static vector<string> data1;
	//data1.push_back("error:can't open file");
	if (!dataFile.is_open())
	{
		return -1;
	}
	dataFile.seekg(-2, dataFile.cur);//��ĩβ���������ַ�,�ܿ����з�

	// �ٶ������ȡlineCount�м�¼
	//	int lineCount = 3;
	for (unsigned int i = 0; i < numLine-2; i++)
	{
		// �鿴��ǰһ���ַ��Ƿ�Ϊ�س������ж��Ƿ�һ�н������Ҳ�Ϊ�ļ�ͷ
		while (dataFile.peek() != dataFile.widen('\n') && (long)dataFile.tellg() != 0)
		{
			dataFile.seekg(-1, dataFile.cur);
		}
		//��Ϊ���з�,���ж���һ��
		if (dataFile.peek() == dataFile.widen('\n'))
		{
			dataFile.seekg(-1, dataFile.cur);
		}
	}
	if ((long)dataFile.tellg() != 0)	//�����һ��,����ָ���ʱָ�����һ�е���һ��ĩβ,
	{									//������3������ָ�����һ�еĿ�ͷ
		dataFile.seekg(3, dataFile.cur);
	}

	string  dataLine;
	//�����е����ݶ���result��
	while (getline(dataFile, dataLine))
	{
		istringstream ss(dataLine);
		string str;
		vector<string> dataArray;
		while (getline(ss, str, ' ')) {
			if (str.length() == 0)
				continue;
			dataArray.push_back(str);
		}
		data.push_back(dataArray);
	}
	dataFile.close();
	return 0;
};


//void show(const vector<string>& data)
//{
//	for (unsigned int i = 0; i < data.size(); i++)
//	{
//		cout << data[i] << endl;
//	}
//}
//
//void show1(const vector<vector<string>> data)
//{
//	for (unsigned int i = 0; i < data.size(); i++)
//	{
//		for (unsigned int j = 0; j < data[i].size(); j++)
//		{
//			cout << data[i][j] << "   ";
//		}
//		cout << endl;
//	}
//}

