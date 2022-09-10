#ifndef _SPEECHMANAGRE_H_
#define _SPEECHMANAGER_H_
#include <iostream>
//������ͷ�ļ�
#include <map>
#include <vector>
#include <string>
#include <deque>
//�㷨��ͷ�ļ�
#include <algorithm>
#include <functional>
#include <numeric>
//�ļ�����ͷ�ļ�
#include <fstream>

#include <ctime>
#include "speaker.h"

#define FILENAME "speech.csv"
#define JUGLENUM 10
#define SPEAKERNUM 12
#define CONTESTNUM 2
using namespace std;

//�����ݽ�����������
class SpeechManager
{
public:
	//���캯��
	SpeechManager();

	//չʾ�˵�
	void ShowMenu();

	//�˳�ϵͳ
	void ExitSystem();

	//��ʼ������������
	void initSpeech();

	//����ѡ��
	void createSpeaker();

	//��ʼ����----�������̿���
	void startSpeech();

	//��ǩ
	void speechDraw();

	//����
	void speechContest();

	//��ʾ�������
	void showScore();

	//�������
	void saveRecord();

	//��ȡ��¼
	void loadRecord();

	//���ñ���
	void resetContest();

	//�ļ�Ϊ�յı�־
	bool FileIsEmpty;

	//�ļ��Ƿ���ڱ�־
	bool FileIsExist;

	//�����¼
	map<int, vector<string>>m_Record;//key����ڼ��죬value�����ļ��н�ȡ�ļ�¼����

	//��ʾ����÷�
	void showRecord();

	//��ռ�¼
	void clearRecord();

	//��Ա����
	//��һ�ֱ���ѡ�� ���� 12��
	vector<int>v1;
	//��һ�ֽ���ѡ�ֱ������
	vector<int>v2;
	//ǰ����
	vector<int>vVictory;
	//��ű���Լ���Ӧѡ�ֵ�����
	map<int, Speaker>m_Speaker;

	//��������
	int m_Index;

	//��������
	~SpeechManager();
};
#endif