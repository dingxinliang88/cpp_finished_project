#include <iostream>
#include <string>
using namespace std;

class Speaker
{
public:
	//�ṩ��ȡѡ�����Եĺ���
	string& GetName() { return this->m_Name; }
	double* GetScore() { return this->m_Score; }

private:
	string m_Name;	//����
	double m_Score[2];//�������������֣�
};