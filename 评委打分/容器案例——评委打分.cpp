#include<iostream>
using namespace std;
#include<string>
#include<vector>
#include<deque>
#include<ctime>
#include <algorithm>
class Person {
public:
	Person(string name) {
		this->m_Name = name;
	}
	string m_Name;
	int m_Score;
};
void CreatPerson(vector<Person>& v) {
	string nameSeed = "ABCDE";
	for (int i = 0; i < 5; i++) {
		Person p("ѡ��");
		p.m_Name += nameSeed.at(i);
		p.m_Score = 0;//��ʼ��Ϊ0
		v.push_back(p);
	}
}
void setScore(vector<Person>& v) {
	for (vector<Person>::iterator it = v.begin(); it != v.end(); it++) {
		deque<int>d;
		for (int i = 0; i < 10; i++) {
			int score = rand() % 41 + 60;
			d.push_back(score);
		}
		//����
		sort(d.begin(), d.end());
		//ȥ����߷ֺ���ͷ�
		d.pop_back();
		d.pop_front();

		//����
		int sum = 0;
		for (deque<int>::iterator it = d.begin(); it != d.end();it++) {
			sum += (*it);
		}
		int avg = sum / d.size();
		it->m_Score = avg;
	}
}
void showScore(vector<Person>& v) {
	for (vector<Person>::iterator it = v.begin(); it != v.end(); it++) {
		cout << "name:" << it->m_Name << " score:" << it->m_Score << endl;
	}
}
int main()
{
	srand((unsigned)time(NULL));
	//��������ѡ�֣��ŵ�vector������
	vector<Person>v;
	CreatPerson(v);
	//������ѡ�ִ��
	setScore(v);
	//չʾ����
	showScore(v);

	system("pause");
	return 0;
}