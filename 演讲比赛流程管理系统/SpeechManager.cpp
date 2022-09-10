#include "SpeechManager.h"


//���캯��
SpeechManager::SpeechManager()
{
	//��ʼ����¼����
	this->m_Record.clear();

	//���ñ���
	this->Reset_Contest();

	//��ʼ����������
	this->m_Index = 1;
}


//չʾ�˵�
void SpeechManager::Show_Menu()
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
void SpeechManager::Exit_System()
{
	cout << "��ӭ�´�ʹ�ñ�ϵͳ" << endl;
	system("pause");
	exit(0);
}

//��ʼ������������
void SpeechManager::Init_Speech()
{
	//�����ÿ�
	this->v1.clear();
	this->v2.clear();
	this->vVictory.clear();
	this->m_Speaker.clear();
	//������������
	this->m_Index = 1;
}

//����ѡ��
void SpeechManager::Create_Speaker()
{
	//string NameSeed = "ABCDEFGHIJKL";//������������
	string NameSeed;
	char ch = 'A';
	for (int i = 0; i < SPEAKER_NUM; i++,ch++)
	{
		NameSeed += ch;
	}
	for (int i = 0; i < NameSeed.size(); i++)
	{
		//ʵ����ѡ��
		Speaker sp;
		sp.GetName() = "ѡ��";
		sp.GetName() += NameSeed.at(i);

		for (int j = 0; j < CONTSET_NUM; j++)
		{
			sp.GetScore()[j] = 0;
		}

		//��ѡ�ֱ�Ŵ����һ�ֱ���������
		this->v1.push_back(i + START_NUM);

		//��ѡ�ִ���ѡ��������
		this->m_Speaker.insert(make_pair(i + START_NUM, sp));
	}
}

//��������
void SpeechManager::Start_Contest()
{
	for (; this->m_Index <= CONTSET_NUM; this->m_Index++)
	{
		//��ǩ
		this->Speech_Draw();
		//��ʼ����
		this->Speech_Contest();
		//��ʾ�������
		this->Show_Score();
	}

	//�����¼
	this->Save_Record();

	//���ñ���
	this->Reset_Contest();

	cout << "---------------���������ϣ�---------------" << endl;
	system("pause");
	system("cls");
}

//��ǩ
void SpeechManager::Speech_Draw()
{
	cout << "�� << " << this->m_Index << " >> �ֱ���ѡ�����ڳ�ǩ" << endl;
	cout << "------------------------------------------------" << endl;
	cout << "��ǩ���ݽ�˳�����£�" << endl;
	
	if (this->m_Index == 1)
	{
		random_shuffle(v1.begin(), v1.end());
		this->Print_SpeechDraw(v1);
	}
	else
	{
		random_shuffle(v2.begin(), v2.end());
		this->Print_SpeechDraw(v2);
	}
	cout << "------------------------------------------------" << endl;
	system("pause");
	cout << endl;
}

//��ӡ��ǩ˳��
void SpeechManager::Print_SpeechDraw(vector<int>& v)
{
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}

//����
void SpeechManager::Speech_Contest()
{
	cout << "----------------�� <<" << this->m_Index << " >> �ֱ�����ʽ��ʼ----------------" << endl;
	multimap<int, double, greater<double>>GroupScore;//��ʱ���������ѡ�ֵ÷֣�key��ѡ�ֱ�ţ�value��ѡ�ֵ÷�
	int num = 0;	//���ڷ��飬6��һ��

	vector<int>v_Src;//��ʱѡ������
	if (this->m_Index == 1)
	{
		v_Src = v1;
	}
	else {
		v_Src = v2;
	}
	//����ѡ�ֿ�ʼ����
	for (vector<int>::iterator it = v_Src.begin(); it != v_Src.end(); it++)
	{
		num++;
		//��ί���
		deque<double>d;
		for (int i = 0; i < JUGLE_NUM; i++)
		{
			double score = (rand() % 401 + 600) / 10.f;//ת���ɸ����ͷ���
			d.push_back(score);
		}
		sort(d.begin(), d.end(), greater<double>());//�Է�����������

		d.pop_front();//ȥ����߷�
		d.pop_back();//ȥ����ͷ�

		double sum = accumulate(d.begin(), d.end(), 0.0f);//��ȡ�ܷ�
		double avg = sum / d.size();//��ȡ����
		
		//�����ִ���ѡ������
		this->m_Speaker[*it].GetScore()[this->m_Index - 1] = avg;

		//��������ݴ�����ʱѡ��������
		GroupScore.insert(make_pair(*it, avg));

		//ÿ6��ȡ��ǰ����
		if (!(num % FIRST_PROMOTED_NUM))
		{
			cout << "��" << num / FIRST_PROMOTED_NUM << "С��������Σ�" << endl;
			for (multimap<int, double>::iterator it = GroupScore.begin();
				it != GroupScore.end(); it++)
			{
				cout << "ѡ�ֱ�ţ�" << it->first << "  ������" << this->m_Speaker[it->first].GetName()
					<< "  �÷֣�" << this->m_Speaker[it->first].GetScore()[this->m_Index - 1] << endl;
			}
			int count = 0;
			for (multimap<int, double>::iterator it = GroupScore.begin();
				it != GroupScore.end() && count < FINAL_PROMOTED_NUM; it++, count++)
			{
				//�浽��һ���ڵ�ѡ��������
				if (this->m_Index == 1)
				{
					v2.push_back(it->first);
				}
				else
				{
					vVictory.push_back(it->first);
				}
			}
			GroupScore.clear();//�����ʱ��������ֹ��һ����������ظ�
			cout << endl;
		}
	}
	cout << "----------------�� << " << this->m_Index << " >> �ֱ������----------------" << endl;
	system("pause");
}

//��ʾ�������
void SpeechManager::Show_Score()
{
	cout << "----------------�� << " << this->m_Index << " >> �ֽ���ѡ����Ϣ���£�----------------" << endl;
	vector<int>v;//��ʱ�洢����ѡ��

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
		cout << "ѡ�ֱ�ţ�" << *it << "  ������" << this->m_Speaker[*it].GetName()
			<< "  �÷֣�" << this->m_Speaker[*it].GetScore()[this->m_Index - 1] << endl;
	}
	cout << endl;
	system("pause");
	system("cls");

	this->Show_Menu();
}

//�����¼
void SpeechManager::Save_Record()
{
	ofstream ofs;
	ofs.open(FILENAME, ios::out | ios::app);//׷�ӵķ�ʽ���ļ�
	//����¼д���ļ�
	for (vector<int>::iterator it = vVictory.begin(); it != vVictory.end(); it++)
	{
		ofs << *it << "," << this->m_Speaker[*it].GetScore()[CONTSET_NUM - 1] << ",";
	}
	ofs << endl;

	ofs.close();
	cout << "��¼�ѳɹ���������ǰĿ¼�µ��ļ�\"" << FILENAME << "\"��" << endl;
	//���±�־
	this->FileIsEmpty = false;
	this->FileIsExist = true;
}

//��ȡ��¼
void SpeechManager::Load_Record()
{
	ifstream ifs(FILENAME, ios::in);
	if (!ifs.is_open())
	{
		this->FileIsExist = false;//�ļ�������
		ifs.close();
		return;
	}
	char ch;
	ifs >> ch;
	if(ifs.eof())
	{
		this->FileIsEmpty = true;//�ļ�Ϊ��
		ifs.close();
		return;
	}

	this->FileIsEmpty = false;//�ļ���Ϊ��
	ifs.putback(ch);//���������ַ��Ż��ļ�

	string data;
	int index = 0;

	while (ifs >> data)
	{
		vector<string>v;//���ڴ�Ž�ȡ���ַ���
		//�Զ������ַ������н�ȡ
		int pos = 1;
		int start = 0;
		while (true)
		{
			pos = data.find(",", start);//��0��ʼ���Ҷ���","
			if (pos == -1)//δ�ҵ�
			{
				break;
			}
			string temp = data.substr(start, pos - start);//��ȡ��ȡ���ַ�
			v.push_back(temp);//��������
			start = pos + 1;//���²��ҵ�λ��
		}
		this->m_Record.insert(make_pair(index, v));//key��ʾ�ڼ��죬value��ʾǰ������¼
		index++;
	}
	ifs.close();
}

//��ʾ�����¼
void SpeechManager::Show_Record()
{
	if (this->FileIsEmpty)
	{
		cout << "�ļ�Ϊ�գ�" << endl;
	}
	else if (!this->FileIsExist)
	{
		cout << "�ļ������ڣ�" << endl;
	}
	else
	{
		for (int i = 0; i < m_Record.size(); i++)
		{
			cout << "��" << i + 1 << "��"
				<< "  �ھ���ţ�" << this->m_Record[i][0] << "  �÷֣�" << this->m_Record[i][1]
				<< "  �Ǿ���ţ�" << this->m_Record[i][2] << "  �÷֣�" << this->m_Record[i][3]
				<< "  ������ţ�" << this->m_Record[i][4] << "  �÷֣�" << this->m_Record[i][5]
				<< endl;
		}
	}
	system("pause");
	system("cls");
}

//��ռ�¼
void SpeechManager::Clear_Record()
{
	cout << "ȷ����գ�" << endl;
	cout << "1��ȷ��" << endl;
	cout << "2������" << endl;

	int select;
	cin >> select;
	if (select == 1)
	{
		ofstream ofs;
		ofs.open(FILENAME, ios::trunc);//��ios::trunc���ļ��������ڣ���ɾ���½��ļ�
		ofs.close();
		//���ñ���
		this->Reset_Contest();

		//���±�־
		this->FileIsEmpty = true;

		cout << "��ճɹ���" << endl;
	}
	system("pause");
	system("cls");
}

//���ñ���
void SpeechManager::Reset_Contest()
{
	//��ʼ������
	this->Init_Speech();
	//����ѡ��
	this->Create_Speaker();
	//���������¼
	this->Load_Record();
}

//��������
SpeechManager::~SpeechManager()
{

}