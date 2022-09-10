#include "speechManager.h"

//���캯��
SpeechManager::SpeechManager()
{
	//��ʼ������
	this->resetContest();

	//��ʼ����������
	this->m_Index = 1;

	//��ʼ����¼����
	this->m_Record.clear();
}

//չʾ�˵�
void SpeechManager::ShowMenu()
{
	cout << "----------------------------------------------" << endl;
	cout << "-----------���ݽ��������̹���ϵͳ��-----------" << endl;
	cout << "--------------0���˳���������-----------------" << endl;
	cout << "--------------1����ʼ�ݽ�����-----------------" << endl;
	cout << "--------------2���鿴�����¼-----------------" << endl;
	cout << "--------------3����ձ�����¼-----------------" << endl;
	cout << "----------------------------------------------" << endl;
}

//�˳�ϵͳ
void SpeechManager::ExitSystem()
{
	cout << "��ӭ�´�ʹ��" << endl;
	system("pause");
	exit(0);
}

//��ʼ������������
void SpeechManager::initSpeech()
{
	//�������
	this->v1.clear();
	this->v2.clear();
	this->vVictory.clear();
	this->m_Speaker.clear();
	//��ʼ������
	this->m_Index = 1;
}

//����ѡ��
void SpeechManager::createSpeaker()
{
	string nameSeed = "ABCDEFGHIJKL";
	for (int i = 0; i < nameSeed.size(); i++)
	{
		string name = "ѡ��";
		name += nameSeed.at(i);

		//��������ѡ��
		Speaker sp;
		sp.GetName() = name;
		
		for (int j = 0; j < 2; j++)
		{
			sp.GetScore()[j] = 0;
		}

		//����ѡ�ֱ�Ų�����v1������
		this->v1.push_back(i + 10001);

		//ѡ�ֱ�ź��Լ���Ӧѡ�ַ���map������
		this->m_Speaker.insert(make_pair(i + 10001, sp));
	}
}

//��ʼ����----�������̿���
void SpeechManager::startSpeech()
{
	for (; this->m_Index <= CONTESTNUM; this->m_Index++)
	{
		//1����ǩ
		this->speechDraw();
		//2������
		this->speechContest();
		//3����ʾ�������
		this->showScore();
	}

	//4���������
	this->saveRecord();

	//���ñ�������ȡ��¼
	this->resetContest();

	cout << "���������ϣ�" << endl;
	system("pause");
	system("cls");
}

//��ǩ
void SpeechManager::speechDraw()
{
	cout << "�� << " << this->m_Index << " >> �ֱ���ѡ�����ڳ�ǩ" << endl;
	cout << "--------------------------------------" << endl;
	cout << "��ǩ���ݽ�˳�����£�" << endl;
	if (this->m_Index == 1)
	{
		random_shuffle(v1.begin(), v1.end());	//ϴ���㷨 ����ѡ�ִ���
		for (vector<int>::iterator it = v1.begin(); it != v1.end(); it++)
		{
			cout << *it << " ";
		}
		cout << endl;
	}
	else
	{
		random_shuffle(v2.begin(), v2.end());
		for (vector<int>::iterator it = v2.begin(); it != v2.end(); it++)
		{
			cout << *it << " ";
		}
		cout << endl;
	}
	cout << "--------------------------------------" << endl;
	system("pause");
	cout << endl;
}

//����
void SpeechManager::speechContest()
{
	cout << "----------------�� <<" << this->m_Index << " >> �ֱ�����ʽ��ʼ----------------" << endl;
	
	multimap<double, int, greater<double>>groupScore;	//׼����ʱ���� ���С��ɼ�
	int num = 0;//����ͳ����Ա����	6��һ��
	
	vector<int>v_Src;//����ѡ������

	if (this->m_Index == 1)
	{
		v_Src = v1;
	}
	else
	{
		v_Src = v2;
	}

	//��������ѡ�ֽ��б���
	for (vector<int>::iterator it = v_Src.begin(); it != v_Src.end(); it++)
	{
		num++;
		//��ί���
		deque<double>d;
		for (int i = 0; i < JUGLENUM; i++)
		{
			double score = (rand() % 401 + 600) / 10.f;	//������Ϊ��������
			d.push_back(score);
		}
		sort(d.begin(), d.end(), greater<double>());//��������

		d.pop_front();		//ȥ����߷�
		d.pop_back();		//ȥ����ͷ�

		double sum = accumulate(d.begin(), d.end(), 0.0f);		//�ۼ��ܷ�

		double avg = sum / (double)d.size();					//ƽ����
	
		this->m_Speaker[*it].GetScore()[this->m_Index - 1] = avg;		//�����ַ�������

		//��������ݷ�����ʱС��������
		groupScore.insert(make_pair(avg, *it));//key�ǵ÷֣�value�Ǿ���ѡ�ֱ��

		//ÿ����ȡ��ǰ����
		if (num % 6 == 0)
		{
			cout << "��" << num / 6 << "С��������Σ�" << endl;
			for (multimap<double, int, greater<double>>::iterator it = groupScore.begin(); 
				it != groupScore.end(); it++)
			{
				cout << "��ţ�" << it->second << " ������" << this->m_Speaker[it->second].GetName()
					<< " �ɼ���" << this->m_Speaker[it->second].GetScore()[this->m_Index - 1] << endl;
			}

			int count = 0;
			//ȡǰ����
			for (multimap<double, int, greater<double>>::iterator it = groupScore.begin();
				it != groupScore.end() && count < 3; it++, count++)
			{
				if (this->m_Index == 1)
				{
					v2.push_back(it->second);
				}
				else
				{
					vVictory.push_back(it->second);
				}
			}
			groupScore.clear();			//������գ���ֹ�����һ�ֱ����ظ�ʹ������
			cout << endl;
		}
	}
	cout << "----------------�� << " << this->m_Index << " >> �ֱ������----------------" << endl;
	system("pause");
}

//��ʾ�������
void SpeechManager::showScore()
{
	cout << "----------------�� << " << this->m_Index << " >> �ֽ���ѡ����Ϣ���£�----------------" << endl;
	
	vector<int>v;//��ʱ�洢��ǰ�ֵ���һ�ֵ�ѡ��

	if (this->m_Index == 1)
	{
		v = v2;
	}
	else
	{
		v = vVictory;
	}

	for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << "ѡ�ֱ�ţ�" << *it << " ������" << this->m_Speaker[*it].GetName()
			<< " �÷֣�" << this->m_Speaker[*it].GetScore()[this->m_Index - 1] << endl;
	}
	cout << endl;

	system("pause");
	system("cls");
	this->ShowMenu();
}

//�������
void SpeechManager::saveRecord()
{
	ofstream ofs;
	ofs.open(FILENAME, ios::out | ios::app);//������ķ�ʽ���ļ�---д�ļ���׷��д

	//��ÿ���˵�����д���ļ���
	for (vector<int>::iterator it = vVictory.begin(); it != vVictory.end(); it++)
	{
		ofs << *it << "," << m_Speaker[*it].GetScore()[1] << ",";
	}
	ofs << endl;

	//�ر��ļ�
	ofs.close();

	cout << "��¼�Ѿ�����" << endl;
	//���±�־
	this->FileIsEmpty = false;
	this->FileIsExist = true;
}

//��ȡ��¼
void SpeechManager::loadRecord()
{
	ifstream ifs(FILENAME, ios::in);	//���������󣬶�ȡ�ļ�

	if (!ifs.is_open())
	{
		this->FileIsEmpty = true;
		ifs.close();
		return;
	}

	char ch;
	ifs >> ch;
	if (ifs.eof())
	{
		this->FileIsEmpty = true;
		ifs.close();
		return;
	}

	//�ļ���Ϊ��
	this->FileIsEmpty = false;

	ifs.putback(ch);//��ȡ�ĵ����ַ��Ż�ȥ

	string data;
	int index = 0;
	while (ifs >> data)
	{
		vector<string>v;//��Ž�ȡ��6���ַ���

		//�Զ�ȡ�����ݽ��н�ȡ
		int pos = 1;
		int start = 0;

		while (true)
		{
			pos = data.find(",", start);//��0��ʼ����" , "
			if (pos == -1)
			{
				break;//�Ҳ��� break����
			}

			string temp = data.substr(start, pos - start);//�ҵ��ˣ����зָ����1����ʼλ�ã�����2����ȡ����
			v.push_back(temp);
			start = pos + 1;	//������һ�β������
		}
		this->m_Record.insert(make_pair(index, v));		//��������¼
		index++;
	}
	ifs.close();
}

//��ʾ����÷�
void SpeechManager::showRecord()
{
	if (this->FileIsEmpty)
	{
		cout << "�ļ�Ϊ��" << endl;
	}
	else if (!this->FileIsExist)
	{
		cout << "�ļ�������" << endl;

	}
	else
	{
		for (int i = 0; i < this->m_Record.size(); i++)
		{
			cout << "��" << i + 1 << "��"
				<< " �ھ���ţ�" << this->m_Record[i][0] << " �÷֣�" << this->m_Record[i][1]
				<< " �Ǿ���ţ�" << this->m_Record[i][2] << " �÷֣�" << this->m_Record[i][3]
				<< " ������ţ�" << this->m_Record[i][4] << " �÷֣�" << this->m_Record[i][5]
				<< endl;
		}
	}
	system("pause");
	system("cls");
}

//��ռ�¼
void SpeechManager::clearRecord()
{
	cout << "ȷ����գ�" << endl;
	cout << "1��ȷ��" << endl;
	cout << "2������" << endl;

	int select = 0;
	cin >> select;

	if (select == 1)
	{
		ofstream ofs(FILENAME, ios::trunc);//�򿪷�ʽ��ios::truck �������ɾ���ļ������´���
		ofs.close();

		//��ʼ������������
		this->initSpeech();
		//����ѡ��
		this->createSpeaker();
		//���������¼
		this->loadRecord();

		cout << "��ճɹ�" << endl;
		this->FileIsEmpty = true;	//�����ļ�Ϊ�յı�־
	}
	system("pause");
	system("cls");
}

//���ñ���
void SpeechManager::resetContest()
{
	//��ʼ������������
	this->initSpeech();
	//����ѡ��
	this->createSpeaker();
	//���������¼
	this->loadRecord();
}

//��������
SpeechManager::~SpeechManager()
{

}