#ifndef _SPEACER_H_
#define _SPEACER_H_
#include <iostream>
#include <string>
using namespace std;

//ѡ����
class Speaker
{
public:
	//�ṩ�ӿڻ�ȡ����
	string& GetName()
	{
		return this->m_Name;
	}

	double* GetScore()
	{
		return this->m_Score;
	}

private:
	string m_Name;//����
	double m_Score[2];//����	��������ֵ÷�
};
#endif