#pragma once 
#include <iostream>
#include <vector>
#include <deque>
#include <map>
#include <algorithm>
#include <functional>
#include <numeric>
#include <ctime>
#include <fstream>
#include "speaker.h"

#define FILENAME "speech.csv"
#define JUGLE_NUM 10
#define SPEAKER_NUM 12
#define CONTSET_NUM 2
#define FIRST_PROMOTED_NUM 6
#define FINAL_PROMOTED_NUM 3
#define START_NUM 10001
using namespace std;


//��������������
class SpeechManager
{
public:
	//���캯��
	SpeechManager();

	//չʾ�˵�
	void Show_Menu();

	//�˳�ϵͳ
	void Exit_System();

	//��ʼ������������
	void Init_Speech();

	//����ѡ��
	void Create_Speaker();

	//��������
	void Start_Contest();

	//��ǩ
	void Speech_Draw();

	//��ӡ��ǩ˳��
	void Print_SpeechDraw(vector<int>& v);

	//����
	void Speech_Contest();

	//��ʾ�������
	void Show_Score();

	//�����¼
	void Save_Record();

	//��ȡ��¼
	void Load_Record();

	//�����¼����
	map<int, vector<string>>m_Record;

	//��ʾ�����¼
	void Show_Record();

	//���ñ���
	void Reset_Contest();

	//��ռ�¼
	void Clear_Record();

	//�ļ�Ϊ�ձ�־
	bool FileIsEmpty;

	//�ļ����ڱ�־
	bool FileIsExist;

	//��Ա����
	//��һ��ѡ�ֱ������
	vector<int>v1;
	//�ڶ���ѡ�ֱ������
	vector<int>v2;
	//ǰ����ѡ������
	vector<int>vVictory;
	//��ű�ź�ѡ�ֵ�����
	map<int, Speaker>m_Speaker;
	//��������
	int m_Index;

	//��������
	~SpeechManager();
};