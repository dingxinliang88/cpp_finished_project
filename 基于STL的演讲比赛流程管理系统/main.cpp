#include <iostream>
#include"speechManager.h"
using namespace std;

int main()
{
	srand((unsigned int)time(NULL));	//���������
	//ʵ�������������
	SpeechManager sm;

	int choice;
	while (true)
	{
		sm.ShowMenu();

		cout << "������Ҫʵ�ֵĹ��ܣ�0~3����" << endl;
		cin >> choice;
		switch (choice)
		{
		case 0:		//�˳���������
			sm.ExitSystem();
			break;
		case 1:		//��ʼ�ݽ�����
			sm.startSpeech();
			break;
		case 2:		//�鿴�����¼
			sm.showRecord();
			break;
		case 3:		//��ձ�����¼
			sm.clearRecord();
			break;
		default:
			system("cls");
			break;
		}
	}

	system("pause");
	return 0;
}