#include <iostream>
#include "workerManager.h"
#include "worker.h"
#include "employee.h"
#include "manager.h"
#include "boss.h"
using namespace std;

int main()
{
	WorkerManager wm;//ʵ���������߶���
	int choice = 0;//�û�ѡ��
	while (true)
	{
		wm.Show_Menu();

		cout << "�����빦�ܱ�ţ�0~7����" << endl;
		cin >> choice;

		switch (choice)
		{
		case 0:	//�˳�����ϵͳ
			wm.ExitSystem();
			break;
		case 1:	//����ְ����Ϣ
			wm.Add_Emp();
			break;
		case 2:	//��ʾְ����Ϣ
			wm.Show_Emp();
			break;
		case 3:	//ɾ��ְ����Ϣ
			wm.Del_Emp();
			break;
		case 4:	//�޸�ְ����Ϣ
			wm.Mod_Emp();
			break;
		case 5:	//����ְ����Ϣ
			wm.Find_Emp();
			break;
		case 6:	//���ձ������
			wm.Sort_Emp();
			break;
		case 7:	//��������ĵ�
			wm.Clean_File();
			break;
		default:
			system("cls");
			break;
		}
	}

	system("pause");
	return 0;
}