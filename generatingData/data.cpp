#include"data.h"
#include"includes.h"
/**********读取飞机姿态的信息函数************
*******************参数说明******************
************dataPath:TXT文件路径,文件是每行代表一条信息*************
************data:保存信息的容器,要提前定义,调用函数后信息就保存在这个容器中*******
************numLine:读取文件的行数************
************返回0代表读取成功,-1代表读取失败*/
int getData(const string dataPath, vector<string>& data, const unsigned int numLine)
{
	ifstream  dataFile(dataPath, std::ios::ate);//定位到文件末尾
	static vector<string> data1;
	data1.push_back("error:can't open file");
	if (!dataFile.is_open())
	{
		return -1;
	}
	dataFile.seekg(-2, dataFile.cur);//从末尾返回两个字符,避开换行符

	// 假定反向读取lineCount行记录
//	int lineCount = 3;
	for (unsigned int i = 0; i < numLine; i++)
	{
		// 查看当前一个字符是否为回车符来判断是否一行结束并且不为文件头
		while (dataFile.peek() != dataFile.widen('\n') && (long)dataFile.tellg() != 0)
		{
			dataFile.seekg(-1, dataFile.cur);
		}
		//若为换行符,则判断上一行
		if (dataFile.peek() == dataFile.widen('\n'))
		{
			dataFile.seekg(-1, dataFile.cur);
		}
	}
	if ((long)dataFile.tellg() != 0)	//到最后一行,但是指针此时指到最后一行的上一行末尾,
	{									//往后移3个正好指到最后一行的开头
		dataFile.seekg(3, dataFile.cur);
	}

	string  dataLine;
	//将所有的数据读到result中
	while (getline(dataFile, dataLine))
	{
		data.push_back(dataLine);
	}
	dataFile.close();
	return 0;
};



/**********读取飞机姿态的信息函数************
*******************参数说明******************
************dataPath:TXT文件路径,文件是每行代表一条信息*************
************data:保存信息的二维容器,要提前定义,调用函数后信息就保存在这个容器中*******
************numLine:读取文件的行数************
************返回0代表读取成功,-1代表读取失败*/
int getData1(const string dataPath, vector<vector<string>>& data, const unsigned int numLine)
{
	ifstream  dataFile(dataPath, std::ios::ate);//定位到文件末尾
	//static vector<string> data1;
	//data1.push_back("error:can't open file");
	if (!dataFile.is_open())
	{
		return -1;
	}
	dataFile.seekg(-2, dataFile.cur);//从末尾返回两个字符,避开换行符

	// 假定反向读取lineCount行记录
	//	int lineCount = 3;
	for (unsigned int i = 0; i < numLine-2; i++)
	{
		// 查看当前一个字符是否为回车符来判断是否一行结束并且不为文件头
		while (dataFile.peek() != dataFile.widen('\n') && (long)dataFile.tellg() != 0)
		{
			dataFile.seekg(-1, dataFile.cur);
		}
		//若为换行符,则判断上一行
		if (dataFile.peek() == dataFile.widen('\n'))
		{
			dataFile.seekg(-1, dataFile.cur);
		}
	}
	if ((long)dataFile.tellg() != 0)	//到最后一行,但是指针此时指到最后一行的上一行末尾,
	{									//往后移3个正好指到最后一行的开头
		dataFile.seekg(3, dataFile.cur);
	}

	string  dataLine;
	//将所有的数据读到result中
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

