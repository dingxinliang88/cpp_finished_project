#include "SpeechManager.h"

int main()
{
	//ʵ�������������
	SpeechManager sm;
	srand((unsigned int)time(NULL));//���������

	/*sm.Create_Speaker();
	sm.Speech_Draw();*/
	while (true)
	{
		sm.Show_Menu();

		cout << "������Ҫʵ�ֵĹ��ܣ�0~3����" << endl;
		int choice;//���ڱ����û���ѡ��
		cin >> choice;

		switch (choice)
		{
		case 0:	//0���˳���������
			sm.Exit_System();
			break;
		case 1:	//1����ʼ�ݽ�����
			sm.Start_Contest();
			break;
		case 2:	//2���鿴�����¼
			sm.Show_Record();
			break;
		case 3:	//3����ձ�����¼
			sm.Clear_Record();
			break;
		default:
			cout << "�����������������룡" << endl;
			system("pause");
			system("cls");
			break;
		}

	}


	system("pause");
	return 0;
}