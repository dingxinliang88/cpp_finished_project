#pragma once
#ifndef BOOK_H
#define BOOK_H

#include<iostream>
#include<string>
using namespace std;
class Book
{
private:
	int index;
	string mBookId;			//���
	string mBookName;		//����
	string mBookAuthor;		//����
	string mBookPub;		//������
	string mBookPubDate;	//��������
	int mRemainAmount;		//���

public:
	void SetIndex(int i) {		//�����±�
		index = i;
	}                       
	void SetInfo(string, string, string, string, string, int);//�޸ĺ���
	void SetBookId() {			//�޸����
		cin >> mBookId; 
	}                      
	void SetBookName() {		//�޸�����
		cin >> mBookName; 
	}                  
	void SetBookAuthor() {		//�޸�����
		cin >> mBookAuthor; 
	}              
	void SetBookPub() {			//�޸ĳ�����
		cin >> mBookPub;
	}                   
	void SetBookPubDate() {		//�޸ĳ�������
		cin >> mBookPubDate; 
	}           
	void SetBookAmount() {		//�޸�����
		cin >> mRemainAmount;
	}            
	void SetBookAmount1() { 
		mRemainAmount++; 
	}
	void SetBookAmount2() { 
		mRemainAmount--; 
	}
	void Show();

	string GetBookId() {		//��ȡ���
		return mBookId;
	}                   
	string GetBookName() {		//��ȡ����
		return mBookName; 
	}				 
	string GetBookAuthor() {	//��ȡ����
		return mBookAuthor; 
	}			 
	string GetBookPub() {		//��ȡ������ 
		return mBookPub; 
	}				 
	string GetBookPubDate() {	//��ȡ��������
		return mBookPubDate;
	}         
	int GetBookAmount() {		//��ȡ����
		return mRemainAmount; 
	}           
};
#endif // !BOOK_H