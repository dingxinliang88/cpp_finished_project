#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <ctime>
using namespace std;

#define Worker_Num 10
enum {
	CEHUA,
	MEISHU,
	YANFA
};
class Worker {
public:
	string m_Name;//����
	int m_Salary;//����
};
void CreateWorker(vector<Worker>& v) {
	string nameSeed = "ABCDEFGHIJ";
	for (int i = 0; i < Worker_Num; i++) {
		Worker worker;
		worker.m_Name = "Ա��";
		worker.m_Name += nameSeed.at(i);
		worker.m_Salary = rand() % 10000 + 10000;
		//��Ա������vector����
		v.push_back(worker);
	}
}
void setGroup(vector<Worker>& v, multimap<int, Worker>& m) {
	//����Ա���������
	for (vector<Worker>::iterator it = v.begin(); it != v.end(); it++) {
		int depId = rand() % 3;
		m.insert(make_pair(depId, *it));
	}
}
void showWokerBydepId(int elem, multimap<int, Worker>& m) {
	multimap<int, Worker>::iterator pos = m.find(elem);
	int count = m.count(elem);
	int index = 0;
	for (; pos != m.end() && index < count; pos++, index++) {
		cout << "������ " << pos->second.m_Name << " ���ʣ�" << pos->second.m_Salary << endl;
	}
}
void showWorkerByGroup(multimap<int, Worker>& m) {
	cout << "�߻����ţ�" << endl;
	showWokerBydepId(CEHUA, m);
	cout << "------------------------------" << endl;
	cout << "�������ţ�" << endl;
	showWokerBydepId(MEISHU, m);
	cout << "------------------------------" << endl;
	cout << "�з����ţ�" << endl;
	showWokerBydepId(YANFA, m);
}

int main() 
{
	srand((unsigned int)time(NULL));
	//����Ա��
	vector<Worker>vWorker;
	CreateWorker(vWorker);
	//Ա������
	multimap<int, Worker> mWorker;
	setGroup(vWorker, mWorker);
	//������ʾ
	showWorkerByGroup(mWorker);
	
	system("pause");
	return 0;
}