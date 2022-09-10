#include "WorkerManager.h"

//���캯��
WorkerManager::WorkerManager()
{
	//�ļ�������
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	if (!ifs.is_open())
	{
		cout << "�ļ������ڣ�" << endl;
		//��ʼ������
		this->m_EmpNum = 0;
		this->m_EmpArray = NULL;
		this->m_FileisExist = false;
		ifs.close();
		return;
	}
	//�ļ�Ϊ��
	char ch;
	ifs >> ch;
	if (ifs.eof())
	{
		cout << "�ļ�Ϊ�գ�" << endl;
		//��ʼ������
		this->m_EmpNum = 0;
		this->m_EmpArray = NULL;
		this->m_FileisEmpty = true;
		ifs.close();
		return;
	}
	//�ļ����ڼ�¼����
	int num = this->get_EmpNum();
	cout << "��ǰְ������Ϊ��" << num << endl;
	this->m_EmpNum = num;
	//���ٿռ䣬���ļ������ݴ浽������
	this->m_EmpArray = new Worker * [this->m_EmpNum];
	this->init_Emp();//��ʼ��ְ��
}

//չʾ�˵�
void WorkerManager::Show_Menu()
{
	cout << "-----------------------------------------" << endl;
	cout << "------------��ְ������ϵͳ��-------------" << endl;
	cout << "-------------0.�˳�����ϵͳ--------------" << endl;
	cout << "-------------1.����ְ����Ϣ--------------" << endl;
	cout << "-------------2.��ʾְ����Ϣ--------------" << endl;
	cout << "-------------3.ɾ��ְ����Ϣ--------------" << endl;
	cout << "-------------4.�޸�ְ����Ϣ--------------" << endl;
	cout << "-------------5.����ְ����Ϣ--------------" << endl;
	cout << "-------------6.���ձ������--------------" << endl;
	cout << "-------------7.��������ĵ�--------------" << endl;
	cout << "-----------------------------------------" << endl;
}

//�˳�ϵͳ
void WorkerManager::ExitSystem()
{
	cout << "��ӭ�´�ʹ��" << endl;
	system("pause");
	exit(0);
}

//���ְ��
void WorkerManager::Add_Emp()
{
	cout << "���������ְ����������" << endl;
	int addNum = 0;
	cin >> addNum;

	if (addNum > 0)
	{
		//��������¿ռ�����
		int newSize = this->m_EmpNum + addNum;
		//�����¿ռ�
		Worker** newSpace = new Worker * [newSize];

		//��ԭ���ռ������ݿ������¿ռ���
		if (this->m_EmpArray != NULL)
		{
			for (int i = 0; i < this->m_EmpNum; i++)
			{
				newSpace[i] = this->m_EmpArray[i];
			}
		}
		//�������������
		for (int i = 0; i < addNum; i++)
		{
			int id;
			string name;
			int dSelect;
			cout << "�������" << i + 1 << "����ְ�����" << endl;
			cin >> id;
			//�ж�ְ������Ƿ����
			int ret = this->isExist(id);
			if (ret == -1)	//ְ����źϷ�
			{
				cout << "�������" << i + 1 << "����ְ������" << endl;
				cin >> name;
				cout << "��ѡ���ְ����λ��" << endl;
				cout << "1����ͨԱ��" << endl
					<< "2������" << endl
					<< "3���ϰ�" << endl;
				cin >> dSelect;

				Worker* worker = NULL;
				switch (dSelect)
				{
				case 1:
					worker = new Employee(id, name, 1);
					break;
				case 2:
					worker = new Manager(id, name, 2);
					break;
				case 3:
					worker = new Boss(id, name, 3);
					break;
				default:
					break;
				}
				//��������ְ��ָ�뱣�浽������
				newSpace[this->m_EmpNum + i] = worker;
			}
			else
			{
				cout << "��ǰ����ı�Ŵ��ڣ����������룡" << endl;
				i--;
				continue;
			}
		}

		delete[]this->m_EmpArray;		//�ͷ�ԭ�еĿռ�
		this->m_EmpArray = newSpace;	//�����¿ռ��ָ��
		this->m_EmpNum = newSize;		//�����µ�ְ������
		this->m_FileisEmpty = false;	//����ְ����Ϊ�ձ�־

		this->save();//ͬ�����浽�ļ���
		this->m_FileisExist = true;//�����ļ��Ƿ���ڱ�־
		cout << "�ɹ����" << addNum << "����ְ��" << endl;
	}
	else
	{
		cout << "������������" << endl;
	}
	system("pause");
	system("cls");
}

//�����ļ�
void WorkerManager::save()
{
	ofstream ofs;
	ofs.open(FILENAME, ios::out);

	for (int i = 0; i < this->m_EmpNum; i++) {
		ofs << this->m_EmpArray[i]->m_Id << " "
			<< this->m_EmpArray[i]->m_Name << " "
			<< this->m_EmpArray[i]->m_DeptId << endl;
	}
	ofs.close();
}

//ͳ���ļ�������
int WorkerManager::get_EmpNum()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	int id, num = 0;
	string name;
	int dId;
	while (ifs >> id && ifs >> name && ifs >> dId)
	{
		num++;
	}
	return num;
}

//��ʼ��ְ��
void WorkerManager::init_Emp()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);

	int id;
	string name;
	int dId;
	int index = 0;

	while (ifs >> id && ifs >> name && ifs >> dId)
	{
		Worker* worker = NULL;
		if (dId == 1)		//Employee
		{
			worker = new Employee(id, name, dId);
		}
		else if (dId == 2)//Manager
		{
			worker = new Manager(id, name, dId);
		}
		else   //Boss
		{
			worker = new Boss(id, name, dId);
		}
		this->m_EmpArray[index++] = worker;
	}
	ifs.close();
}

//��ʾְ��
void WorkerManager::Show_Emp()
{
	if (this->m_FileisEmpty)
	{
		cout << "��¼Ϊ��" << endl;
	}
	else if (!this->m_FileisExist)
	{
		cout << "�ļ�������" << endl;
	}
	else
	{
		for (int i = 0; i < this->m_EmpNum; i++)
		{
			this->m_EmpArray[i]->showInfo();//���ö�̬���ýӿ�
		}
	}
	system("pause");
	system("cls");
}

//�ж�Ա���Ƿ���ڣ�������ڷ���ְ�����������λ�ã������ڷ���-1
int WorkerManager::isExist(int id)
{
	int index = -1;
	for (int i = 0; i < this->m_EmpNum; i++)
	{
		if (this->m_EmpArray[i]->m_Id == id)
		{
			index = i;
			break;
		}
	}
	return index;
}

//ɾ��ְ��
void WorkerManager::Del_Emp()
{
	if (this->m_FileisEmpty)
	{
		cout << "��¼Ϊ��" << endl;
	}
	else if(!this->m_FileisExist)
	{
		cout << "�ļ�������" << endl;
	}
	else
	{
		//����ְ�����ɾ��
		cout << "������Ҫɾ����ְ����ţ�" << endl;
		int id = 0;
		cin >> id;

		int index = this->isExist(id);
		if (index != -1)//ְ������
		{
			for (int i = index; i < this->m_EmpNum - 1; i++)
			{
				this->m_EmpArray[i] = this->m_EmpArray[i + 1];	//����ǰ��
			}
			this->m_EmpNum--;//������Ա����
			this->save();//ͬ�����ļ���
			cout << "ɾ���ɹ�" << endl;
		}
		else
		{
			cout << "ɾ��ʧ�ܣ�δ�ҵ���ְ��" << endl;
		}
	}
	system("pause");
	system("cls");
}

//�޸�ְ��
void WorkerManager::Mod_Emp()
{
	if (this->m_FileisEmpty)
	{
		cout << "��¼Ϊ��" << endl;
	}
	else if (!this->m_FileisExist)
	{
		cout << "�ļ�������" << endl;
	}
	else
	{
		cout << "������Ҫ�޸ĵ�ְ����ţ�" << endl;
		int id = 0;
		cin >> id;

		int ret = this->isExist(id);
		if (ret != -1)
		{
			//����Ա��
			delete this->m_EmpArray[ret];
			int newId = 0;
			string newName = "";
			int dSelect = 0;

			cout << "�鵽" << id << "��ְ��,��������ְ���ţ�" << endl;
			cin >> newId;
			cout << "��������������" << endl;
			cin >> newName;
			cout << "�������¸�λ��" << endl;
			cout << "1����ͨԱ��" << endl
				<< "2������" << endl
				<< "3���ϰ�" << endl;
			cin >> dSelect;

			Worker* worker = NULL;
			switch (dSelect)
			{
			case 1:
				worker = new Employee(newId,newName, 1);
				break;
			case 2:
				worker = new Manager(newId, newName, 2);
				break;
			case 3:
				worker = new Boss(newId, newName, 3);
				break;
			default:
				break;
			}
			//�������ݵ�����
			this->m_EmpArray[ret] = worker;
			this->save();
			cout << "�޸ĳɹ���" << endl;		
		}
		else
		{
			cout << "�޸�ʧ�ܣ�δ�ҵ���ְ��" << endl;
		}
	}
	system("pause");
	system("cls");
}

//����ְ��
void WorkerManager::Find_Emp()
{
	if (this->m_FileisEmpty)
	{
		cout << "��¼Ϊ��" << endl;
	}
	else if (!this->m_FileisExist)
	{
		cout << "�ļ�������" << endl;
	}
	else
	{
		cout << "��������ҷ�ʽ(1 or 2):" << endl;
		cout << "1������ְ����Ų���" << endl;
		cout << "2������ְ����������" << endl;

		int select = 0;
		cin >> select;
		if (select == 1)
		{
			int id;
			cout << "���������ְ����ţ�" << endl;
			cin >> id;

			int ret = this->isExist(id);
			if (ret != -1)
			{
				cout << "���ҳɹ�����ְ����Ϣ���£�" << endl;
				this->m_EmpArray[ret]->showInfo();
			}
			else
			{
				cout << "����ʧ�ܣ����޴���" << endl;
			}
		}
		else if (select == 2)
		{
			string name;
			cout << "���������ְ��������" << endl;
			cin >> name;
			bool flag = false;//���ұ�־��Ĭ��δ�ҵ�

			for (int i = 0; i < this->m_EmpNum; i++)
			{
				if (this->m_EmpArray[i]->m_Name == name)
				{
					cout << "���ҳɹ�����ְ����Ϣ���£�" << endl;
					this->m_EmpArray[i]->showInfo();
					flag = true;
				}
			}
			if (flag == false)
			{
				cout << "����ʧ�ܣ����޴���" << endl;
			}
		}
		else
		{
			cout << "����ѡ������" << endl;
		}
	}
	system("pause");
	system("cls");
}

//ְ������
void WorkerManager::Sort_Emp()
{
	if (this->m_FileisEmpty)
	{
		cout << "��¼Ϊ��" << endl;
		system("pause");
		system("cls");
	}
	else if (!this->m_FileisExist)
	{
		cout << "�ļ�������" << endl;
		system("pause");
		system("cls");
	}
	else
	{
		cout << "����������ʽ(1 or 2):" << endl;
		cout << "1������ְ��������" << endl;
		cout << "2������ְ���Ž���" << endl;

		int select = 0;
		cin >> select;
		for (int i = 0; i < this->m_EmpNum; i++)
		{
			int MinOrMax = i;
			for (int j = i + 1; j < this->m_EmpNum; j++)
			{
				if (select == 1)//����
				{
					if (this->m_EmpArray[i]->m_Id > this->m_EmpArray[j]->m_Id)
					{
						MinOrMax = j;
					}
				}
				else//����
				{
					if (this->m_EmpArray[i]->m_Id < this->m_EmpArray[j]->m_Id)
					{
						MinOrMax = j;
					}
				}
			}
			if (MinOrMax != i)
			{
				Worker* temp = this->m_EmpArray[i];
				this->m_EmpArray[i] = this->m_EmpArray[MinOrMax];
				this->m_EmpArray[MinOrMax] = temp;
			}
		}
	}
	cout << "����ɹ����������" << endl;
	this->save();
	this->Show_Emp();
}

//�������
void WorkerManager::Clean_File()
{
	cout << "ȷ����գ�" << endl;
	cout << "1��ȷ��" << endl;
	cout << "2������" << endl;
	
	int select = 0; 
	cin >> select;
	if (select == 1)
	{
		//����ļ�
		ofstream ofs(FILENAME, ios::trunc);//ɾ���ļ��������´���
		ofs.close();
		
		if (this->m_EmpArray != NULL)
		{
			for (int i = 0; i < this->m_EmpNum; i++)
			{
				if (this->m_EmpArray[i] != NULL)
				{
					delete this->m_EmpArray[i];//�ͷŶ�����ÿһ��ְ��
					this->m_EmpArray[i] = NULL;
				}
			}
			//ɾ������������ָ��
			delete[]this->m_EmpArray;
			this->m_EmpArray = NULL;
			this->m_EmpNum = 0;
			this->m_FileisEmpty = true;
		}
		cout << "��ճɹ���" << endl;
	}
	system("pause");
	system("cls");
}

//��������
WorkerManager::~WorkerManager()
{
	if (this->m_EmpArray != NULL)
	{
		for (int i = 0; i < this->m_EmpNum; i++)
		{
			if (this->m_EmpArray[i] != NULL)
			{
				delete this->m_EmpArray[i];//�ͷŶ�����ÿһ��ְ������
				this->m_EmpArray[i] = NULL;
			}
		}
		delete[]this->m_EmpArray;
		this->m_EmpArray = NULL;
	}
}