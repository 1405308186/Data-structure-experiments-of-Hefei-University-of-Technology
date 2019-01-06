// linkedList1.h: interface for the linkedList class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_LINKEDLIST1_H__4C3F34C9_D36C_43D6_97CF_A8E55FD6BD7D__INCLUDED_)
#define AFX_LINKEDLIST1_H__4C3F34C9_D36C_43D6_97CF_A8E55FD6BD7D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "StdAfx.h"

using namespace std;

class linkedList  
{
public:
	linkedList();//���캯��
	virtual ~linkedList();//�������������ٵ�����
	bool createLinkedListRail( int length );//β�巨����������
	bool createLinkedListFront( int length );//ͷ�巨����������
	void addLinkedListNodeLast( int value );//���棺�����ʼ������ʹ�ã�
	//�ҳ����жϵ��ö���������Ƿ��ʼ������Ϊ�Ƿ���øú��������ݣ����ʧ�ܣ���������жϣ����ǲ�������ڵ�ʱ����
	bool initiateLinkedList();//��ʼ��������
	bool isEmpty();//�жϵ������Ƿ�Ϊ��
	bool getElementByPosition( int pos, int& value );//�������е�pos��Ԫ�أ����������������ڣ�����
	bool insertListByPosition( int pos, int value );//�ڵ�pos�����ǰ����ֵΪvalue�Ľ��
	bool getElementByValue( int& pos, int value );//�����в���Ԫ��ֵΪx�Ľ�㣬�ɹ����ؽ��ָ�룬ʧ�ܱ���
	bool removeListNodeByPosition( int pos, int& value );//ɾ���������е�pos��Ԫ�ؽ��
	bool insertListSort( int value );//��һ����������ĵ�����L�в���һ��ֵΪvalue��Ԫ�أ��������������������
	bool oddEvenSort( linkedList& LA,linkedList& LB );//�����õ������е�Ԫ�ذ���ż�Է���o�����õĵ�����LA��LB
	void printLinkedList();//��ӡ������
	int linkedListLength();//���ص�������
private:
	LList *head;
	int len;
};

#endif // !defined(AFX_LINKEDLIST1_H__4C3F34C9_D36C_43D6_97CF_A8E55FD6BD7D__INCLUDED_)
