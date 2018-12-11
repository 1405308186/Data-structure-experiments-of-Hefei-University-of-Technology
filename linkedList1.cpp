// linkedList1.cpp: implementation of the linkedList class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "linkedList1.h"


//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

linkedList::linkedList()
{
	head = NULL;
	len = 0;
}

linkedList::~linkedList()
{
	LList* tmp = head;
	//for( int i = 0; i < len; i ++ )
	while( tmp->next )
	{
		LList *q = tmp;
		tmp = tmp->next;
		delete q;
	}
}

bool linkedList::initiateLinkedList()
{
	std::ios::sync_with_stdio(false);
	head = new LList;
	if( !head )
	{
		cout << "��ʼ��ʧ�ܣ�" << endl;
		return false;
	}
	head->next = NULL;
	return true;
}

bool linkedList::createLinkedListRail( int length )
{
	std::ios::sync_with_stdio(false);
	initiateLinkedList();
	LList* rail = head;
	for( int i = 1; i <= length; i ++ )
	{
		LList* tmp = new LList;
		int num;
		cin >> num;
		//num = i + 1;
		tmp->data = num;
		tmp->next = rail->next;
		rail->next = tmp;
		rail = tmp;
		len ++;
	}
	return true;
}

bool linkedList::createLinkedListFront( int length )
{
	std::ios::sync_with_stdio(false);
	initiateLinkedList();
	for( int i = 0; i < length; i ++ )
	{
		int num;
		cin >> num;
		//num = i + 1;
		LList* tmp = new LList;
		tmp->data = num;
		tmp->next = head->next;
		head->next = tmp;
		len ++;
	}
	return true;
}

void linkedList::addLinkedListNodeLast( int value )
{
	//ios::sync_with_stdio(false);
	
	LList* tmp = head;
	LList* last = NULL;
	while(tmp)
	{
		last = tmp;
		tmp = tmp->next;
	}
	LList* PNew = new LList;
	PNew->data = value;
	PNew->next = NULL;
	last->next = PNew;
	len ++;
}

bool linkedList::isEmpty()
{
	return head->next == NULL;
}

void linkedList::printLinkedList()
{
	std::ios::sync_with_stdio(false);
	if( isEmpty() )
	{
		cout << "�������޷���ӡ��" << endl;
		return;
	}
	LList* tmp = head->next;
	int column = 0;
	while(tmp)
	{
		cout << setiosflags(ios::left) << setw(3) << tmp->data << " ";
		column ++;
		if( column % 10 == 0 )
			cout << endl;
		tmp = tmp->next;
	}
	cout << endl;
}

int linkedList::linkedListLength()
{
	if( isEmpty() )
	{
		cout << "������" << endl;
		return -1;
	}
	int l = 0;
	LList* tmp = head->next;
	while(tmp)
	{
		tmp = tmp->next;
		l ++;
	}
	return l;
	//return len;
}

bool linkedList::getElementByPosition( int pos, int& value )
{
	ios::sync_with_stdio(false);
	if( isEmpty() )
	{
		cout << "����Ϊ�գ���ȡԪ��ʧ�ܣ�" << endl;
		return false;
	}
	if( pos > len )
	{
		cout << "λ�ô��ڱ�����ȡԪ��ʧ�ܣ�" << endl;
		return false;
	}
	if( pos <= 0 )
	{
		cout << "λ�ñ������0����ȡԪ��ʧ�ܣ�" << endl;
		return false;
	}
	int index = 0;
	LList* tmp = head;
	while(tmp)
	{
		if( index == pos )
		{
			//cout << tmp->data;
			value = tmp->data;
			return true;
		}
		tmp = tmp->next;
		index ++;
	}
	return true;
}

bool linkedList::insertListByPosition( int pos, int value )
{
	ios::sync_with_stdio(false);
	if( isEmpty() )
	{
		cout << "����Ϊ�գ�����Ԫ��ʧ�ܣ�" << endl;
		return false;
	}
	else if( pos > len )
	{
		cout << "λ�ô��ڱ��Ҳ�ֵ����1��ɾ��Ԫ��ʧ�ܣ�" << endl;
		return false;
	}
	else if( pos == len )
	{
		cout << "����ֱ�Ӱ��½ڵ��������β����" << endl;
		addLinkedListNodeLast( value );
		return true;
	}
	else if( pos <= 0 )
	{
		cout << "λ�ñ������0������Ԫ��ʧ�ܣ�" << endl;
		return false;
	}
	int index = 0;
	LList* tmp = head;
	while( index != pos - 1 && tmp )
	{
		index ++;
		tmp = tmp->next;
	}
	if( tmp == NULL )
	{
		cout << "λ�ô��ڱ��Ҳ��ڱ��ĺ�һλ������Ԫ��ʧ�ܣ�" << endl;
		return false;
	}
	LList* PNew = new LList;
	PNew->data =  value;
	PNew->next = tmp->next;
	tmp->next = PNew;
	len ++;
	return true;
}

bool linkedList::getElementByValue( int& pos, int value )
{
	ios::sync_with_stdio(false);
	if( isEmpty() )
	{
		cout << "����Ϊ�գ���ȡԪ��ʧ�ܣ�" << endl;
		return false;
	}
	int index = 1;
	LList* tmp = head->next;
	while(tmp)
	{
		if( tmp->data == value )
		{
			pos = index;
			return true;
		}
		tmp = tmp->next;
		index ++;
	}
	return false;
}

bool linkedList::removeListNodeByPosition( int pos, int& value )
{
	ios::sync_with_stdio(false);
	if( isEmpty() )
	{
		cout << "����Ϊ�գ�ɾ��Ԫ��ʧ�ܣ�" << endl;
		return false;
	}
	if( pos > len )
	{
		cout << "λ�ô��ڱ���ɾ��Ԫ��ʧ�ܣ�" << endl;
		return false;
	}
	if( pos <= 0 )
	{
		cout << "λ�ñ������0��ɾ��Ԫ��ʧ�ܣ�" << endl;
		return false;
	}
	LList* tmp = head;
	int index = 0;
	while( index != pos - 1 && tmp )
	{
		tmp = tmp->next;
		index ++;
	}
	LList* PDel = tmp->next;
	value = PDel->data;
	tmp->next = tmp->next->next;
	delete PDel;
	len --;
	return true;
}

bool linkedList::insertListSort( int value )
{
	ios::sync_with_stdio(false);
	if( isEmpty() )
	{
		cout << "����Ϊ�գ�����Ԫ��ʧ�ܣ�" << endl;
		return false;
	}
	LList* tmp = head;
	while( tmp->next && tmp->next->data < value )//��һ���ڵ��data��valueС�ͼ���ѭ��
	//д�������������±����һ���ڵ��data���value�޷����룡��Ϊѭ������ʱtmp->nextΪNULL���޷����롣
	//while( tmp && tmp->next->data < value )
	{
		//if( tmp->data < value )
			tmp = tmp->next;
	}
	LList* PNew = new LList;
	PNew->data = value;
	PNew->next = tmp->next;
	tmp->next = PNew;
	return true;
}

bool linkedList::oddEvenSort( linkedList& LA,linkedList& LB )
{
	ios::sync_with_stdio(false);
	if( isEmpty() )
	{
		cout << "ԭ����Ϊ�գ�����Ԫ��ʧ�ܣ�" << endl;
		return false;
	}
	//if( !LA.head->next && !LB.head->next )
	if( !LA.head && !LB.head )
	{
		LA.initiateLinkedList();
		LB.initiateLinkedList();
	}
	LList* tmp = head->next;
	while(tmp)
	{
		if( tmp->data >= 0 && ( tmp->data & 1 ) )
			LA.addLinkedListNodeLast( tmp->data );
		//else if( tmp->data >= 0 && !( tmp->data & 1 ) )
		else
			LB.addLinkedListNodeLast( tmp->data );
		tmp = tmp->next;
	}
	return true;
}