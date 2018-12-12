// charLinkedQueue.h: interface for the charLinkedQueue class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_CHARLINKEDQUEUE_H__13C2F642_81C0_4489_9CF2_3D58D8B48EA9__INCLUDED_)
#define AFX_CHARLINKEDQUEUE_H__13C2F642_81C0_4489_9CF2_3D58D8B48EA9__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

//�տ�ʼ����дӢ��ע�͵ģ�����֪�Ѷ����ˣ�����ԭ����Ӣ��ע���ұ�����

class charLinkedQueue  
{
public:
	charLinkedQueue();
	virtual ~charLinkedQueue();
	bool emptyCharLinkedQueue();
	//bool fullSeqCircleQueue();
	bool enQueue( bitNode *value );//the type must be bitNode*
	bool deQueue( /*bitNode *value*/ );
	bool getFront( bitNode *&value );//the type must be bitNode*&
	int length();
	friend ostream &operator<<( ostream &os, charLinkedQueue &clq )
	{
		/*
		if( ( scq._front - 1 ) % maxn == scq._rear )
			return os;
		int column  = 0;
		for( int i = scq._front; i % maxn != scq._rear; i = ( i + 1 ) % maxn )
		{
			os << setw(3) << setiosflags(ios::left) << scq.data[i] << " ";
			column ++;
			if( column % 10 == 0 )
				os << endl;
		}
		os << endl;
		*/
		if( clq._front == NULL )
			return os;
		CLNode *tmp = clq._front;
		int column = 0;
		while( tmp != clq._rear->link )
		{
			os << setw(4) << setiosflags(ios::left) << tmp->data << " ";
			column ++;
			tmp = tmp->link;
			if( column % 10 == 0 )
				os << endl;
		}
		os << endl;
	}
	//Ϊ����˳��ʹ��ԭ�����������������ж������Ĳ�α���������Ҫ�ľ���������_front��_rear���͡�
	//deQueue()��enQueue()��charNode������ȷ���ϣ����������γ��ԣ�����������----
	//�����Git��������������ÿ���汾��ͻ�֪���Ҹ����˶�����Ѫ��������
private:
	CLNode *_front;//the type must be CLNode*
	CLNode *_rear;//the type must be CLNode*
};

#endif // !defined(AFX_CHARLINKEDQUEUE_H__13C2F642_81C0_4489_9CF2_3D58D8B48EA9__INCLUDED_)
