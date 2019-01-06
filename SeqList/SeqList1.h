// SeqList1.h: interface for the SeqList class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_SEQLIST1_H__5F69CE41_7D8B_4396_BAAE_F849B1FD54D1__INCLUDED_)
#define AFX_SEQLIST1_H__5F69CE41_7D8B_4396_BAAE_F849B1FD54D1__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class SeqList  
{
public:
	SeqList();
	virtual ~SeqList();
	void printList();
	int Length();
	int locate( elementType value );//���ص�һ��ֵΪvalue��λ�ã�û���򷵻�-1
	bool isEmpty();//�п�
	bool isFull();//����
	bool getElement( int pos, elementType& value );//��ȡposλ�õ�ֵ
	bool insertList( int pos, elementType value );//��posλ��ǰ����valueֵ
	bool insertList_1( elementType value );//��β������valueֵ
	bool deleteListNode( int pos, elementType& value );//��λ��ɾ��Ԫ��
	bool deleteListNode_1( int value );//��ֵɾ��Ԫ��
	bool deleteListNode_2( int value );//��ֵɾ�����ж�ӦԪ��

	bool incInsert( int value );//���뱣�ֵ�������
	bool oddEvenSort( SeqList& LA, SeqList& LB);//˳�������ż������
	bool intersectionSet( SeqList& LA, SeqList& LB, SeqList& LC );//��������˳�����
	bool delRepeatedNode();//ɾ���ظ�Ԫ��
	bool delRepeatedNode_2();//ɾ���ظ�Ԫ��
	bool unionSet( SeqList& LA, SeqList& LB );//�󲢼�

	bool unionSet( SeqList& LA, SeqList& LB, SeqList& LC );//�󲢼�
	bool subTractSet( SeqList& LA, SeqList& LB, SeqList& LC );// ��

	bool intersectionSet( SeqList& LA, SeqList& LB );//�󽻼�
	bool subTractSet( SeqList& LA, SeqList& LB );// ��

	bool subSet( SeqList& LA, SeqList& LB );//�ж�A�Ƿ�ΪB���Ӽ�

	int midSearch( SeqList& LA, SeqList& LB );//������ȳ��������е���λ��


	//bool SeqList::delRepeatedNode( SeqList& L );
private:
	elementType Arr[maxn];//��ű�Ԫ�ص�����
	size_t listSize;//��¼��ǰ˳���Ĵ�С
};

#endif // !defined(AFX_SEQLIST1_H__5F69CE41_7D8B_4396_BAAE_F849B1FD54D1__INCLUDED_)
