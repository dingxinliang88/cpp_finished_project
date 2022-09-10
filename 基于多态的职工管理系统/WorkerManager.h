#pragma once
#include <iostream>
#include <fstream>
#include"worker.h"
#include "employee.h"
#include "manager.h"
#include "boss.h"
#define FILENAME "empFile.txt"
using namespace std;

class WorkerManager
{
public:
	//���캯��
	WorkerManager();

	//��ʾ�˵�
	void Show_Menu();

	//�˳�ϵͳ
	void ExitSystem();

	//��¼ְ������
	int m_EmpNum;

	//ְ������ָ��
	Worker** m_EmpArray;

	//���ְ��
	void Add_Emp();

	//�����ļ�
	void save();

	//�ж��ļ��Ƿ����
	bool m_FileisExist;

	//�ж��ļ��Ƿ�Ϊ��
	bool m_FileisEmpty;

	//ͳ���ļ�������
	int get_EmpNum();

	//��ʼ��ְ��
	void init_Emp();

	//��ʾְ��
	void Show_Emp();

	//�ж�Ա���Ƿ���ڣ�������ڷ���ְ�����������λ�ã������ڷ���-1
	int isExist(int id);

	//ɾ��ְ��
	void Del_Emp();

	//�޸�ְ��
	void Mod_Emp();

	//����ְ��
	void Find_Emp();

	//ְ������
	void Sort_Emp();

	//�������
	void Clean_File();

	//��������
	~WorkerManager();
};