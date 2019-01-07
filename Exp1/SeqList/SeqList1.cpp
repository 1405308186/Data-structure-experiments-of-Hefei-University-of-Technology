// SeqList1.cpp: implementation of the SeqList class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "SeqList1.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

SeqList::SeqList()
{
	listSize = 0;
}

SeqList::~SeqList()
{
	cout << this << " ˳��������٣�" << endl;
}

void SeqList::printList()
{
	if( isEmpty() )
	{
		cout << "˳���Ϊ�գ��޷���ӡ��" << endl;
	}
	int column = 0;
	for( int i = 0; i < listSize; i ++ )
	{
		cout<< setiosflags(ios::left) << setw(5) << Arr[i] << " ";
		if( ++ column % 10 == 0 )
			cout << endl;
	}
	cout << endl;
}

int SeqList::Length()
{
	return listSize;
}

int SeqList::locate( elementType value )
{
	for( int i = 0; i < listSize; i ++ )
		if( Arr[i] == value )
			return i + 1;
	return -1;
}

bool SeqList::isEmpty()
{
	return listSize == 0;
}

bool SeqList::isFull()
{
	return listSize == maxn;
}

bool SeqList::getElement( int pos, elementType& value )
{
	if( isEmpty() )
	{
		cout << "˳���Ϊ�գ���ѯʧ�ܣ�" << endl;
		return false;
	}
	if( pos > listSize )
	{
		cout << "��ѯλ�ó�����ǰ˳�����������ѯʧ�ܣ�" << endl;
		return false;
	}
	if( pos <= 0 )
	{
		cout << "��ѯλ�ñ������0����ѯʧ�ܣ�" << endl;
		return false;
	}
	value = Arr[pos];
	return true;
}

bool SeqList::insertList( int pos, elementType value )
{
	if( isFull() )
	{
		cout << "˳�������������ʧ�ܣ�" << endl;
		return false;
	}
	if( pos > listSize )
	{
		cout << "����λ�ó�����ǰ˳�������������ʧ�ܣ�" << endl;
		return false;
	}
	if( pos <= 0 )
	{
		cout << "����λ�ñ������0������ʧ�ܣ�" << endl;
		return false;
	}
	for( int i = listSize - 1; i >= pos - 1; i -- )
		Arr[ i + 1 ] = Arr[i];
	Arr[ pos - 1 ] = value;
	listSize ++;//һ�������٣�
	return true;//һ�������٣�
}

bool SeqList::insertList_1( elementType value )
{
	if( isFull() )
	{
		cout << "˳�������������ʧ�ܣ�" << endl;
		return false;
	}
	Arr[ listSize ++ ] = value;
	return true;//һ�������٣�
}

bool SeqList::deleteListNode( int pos, elementType& value )
{
	if( isEmpty() )
	{
		cout << "˳���Ϊ�գ�ɾ��ʧ�ܣ�" << endl;
		return false;
	}
	if( pos > listSize )
	{
		cout << "ɾ��λ�ô��ڱ���ɾ��ʧ�ܣ�" << endl;
		return false;
	}
	if( pos <= 0 )
	{
		cout << "ɾ��λ�ñ������0��ɾ��ʧ�ܣ�" << endl;
		return false;
	}
	value = Arr[ pos - 1 ];
	//for( int i = pos; i < listSize - 1; i ++ )
	for( int i = pos; i < listSize; i ++ )
		Arr[ i - 1 ] = Arr[i];
	listSize --;//һ�������٣�
	return true;//һ�������٣�
}

bool SeqList::deleteListNode_1( int value )
{
	if( isEmpty() )
	{
		cout << "˳���Ϊ�գ�ɾ��ʧ�ܣ�" << endl;
		return false;
	}
	if( locate(value) == -1 )
	{
		cout << "�����޴�Ԫ�أ�ɾ��ʧ�ܣ�" << endl;
		return false;
	}
	int index = locate(value);
	for( int i = index - 1; i < listSize; i ++ )
		Arr[i] = Arr[ i + 1 ];
	listSize --;//һ�������٣�����������ʧЧ��λ����ռ����ǰԪ�صĴ���
	return true;//һ�������٣�
	/*��������£�
	void delete(int A[],int key,int& n) 
	{ 
		int i,j; 
		for(i=0;i<n&&A[i]-key;i++); //����keyֵԪ�� 
		if(i>=n) 
			cout<<"not found"<<endl; 
		else
		{ 
			for(j=i;j<n-1;A[j]=A[j+1],j++);//���ҵ�������Ԫ�غ�ߵ�ֵ��ǰ���� 
			--n;//���鳤�ȼ�1 
		} 
	}
	--------------------- 
	���ߣ�castle_kao 
	��Դ��CSDN 
	ԭ�ģ�https://blog.csdn.net/castle_kao/article/details/53487610?utm_source=copy 
	��Ȩ����������Ϊ����ԭ�����£�ת���븽�ϲ������ӣ�
	*/
}

bool SeqList::deleteListNode_2( int value )
{
	if( isEmpty() )
	{
		cout << "˳���Ϊ�գ�ɾ��ʧ�ܣ�" << endl;
		return false;
	}
	if( locate(value) == -1 )
	{
		cout << "�����޴�Ԫ�أ�ɾ��ʧ�ܣ�" << endl;
		return false;
	}
	int cnt = 0;
	for( int i = 0; i < listSize; i ++ )
		if( Arr[i] == value )
			cnt ++;
	while( cnt -- )
	{
		int pos = locate(value), data;
		deleteListNode( pos, data );
	}
	return true;
}

bool SeqList::incInsert( int value )
{
	if( isFull() )
	{
		cout << "˳�������������ʧ�ܣ�" << endl;
		return false;
	}
	int index = -1;
	if( value <= Arr[0] )
	{
		for( int k = listSize; k>= 0; k -- )
			Arr[ k + 1 ] = Arr[k];
		Arr[0] = value;
		listSize ++;
		return true;
	}
	else if( value > Arr[0] && value < Arr[ listSize - 1 ] )
	{
		for( int i = 0; i < listSize; i ++ )
		{
			if( Arr[i] >= value )
			{
				index = i;
				break;
			}
			else
				continue;
		}
	
		for( int j = listSize; j >= index; j -- )
		{
			Arr[ j + 1 ] = Arr[j];
		}
		Arr[index] = value;
		listSize ++;
		return true;
	}
	else
	{
		Arr[listSize] = value;
		listSize ++;
		return true;
	}
}

bool SeqList::oddEvenSort( SeqList& LA, SeqList& LB )//����ż������
{
	if( isFull() )
	{
		cout << "ԭ˳�������������ʧ�ܣ�" << endl;
		return false;
	}
	for( int i = 0; i < listSize; i ++ )
	{
		if( Arr[i] & 1 )
			LA.insertList_1( Arr[i] );
		else
			LB.insertList_1( Arr[i] );
	}
	return true;
}

bool SeqList::intersectionSet( SeqList& LA, SeqList& LB, SeqList& LC )
{
	int ia, ib;
	if( LA.isEmpty() || LB.isEmpty() )
	{
		cout << "������һ��˳���Ϊ�գ�����ʧ�ܣ�" << endl;
		return false;
	}
	for( ia = 0, ib = 0; ia < LA.listSize, ib < LB.listSize; )
	{
		if( ia == LA.listSize - 1 || ib == LB.listSize - 1 )
			//break;
			return true;
		if( LA.Arr[ia] == LB.Arr[ib] )
		{
			LC.insertList_1( LB.Arr[ib] );
			ia ++;
			ib ++;
		}
		else if( LA.Arr[ia] < LB.Arr[ib] )
		{
			ia ++;
			continue;
		}
		else 
		{
			ib ++;
			continue;
		}
	}
	return true;
}

bool SeqList::delRepeatedNode()
{	
	if( isEmpty() )
	{
		cout << "˳���Ϊ�գ�����ʧ�ܣ�" << endl;
		return false;
	}
	int x;
	for( int i = 0; i < listSize - 1; i ++ )
	{
		for( int j = i + 1; j < listSize; j ++ )
			if( Arr[i] == Arr[j] )
			{
				//for( int k = j; k < listSize - 1; k ++ )
					//Arr[k] = Arr[ k + 1 ];
				//listSize --;
				//deleteListNode( j, x );
				deleteListNode_1( Arr[i] );
				j --;//�һ���һ��Сʱ������仰��
			}
		//i --;
	}
	return true;
}

bool SeqList::delRepeatedNode_2()
{
	if( isEmpty() )
	{
		cout << "˳���Ϊ�գ�ȥ��ʧ�ܣ�" << endl;
		return false;
	}
	int i, j = 0, k;
	for( i = 1; i < listSize; i ++ )
    {
		k = 0;
	    while( ( k <= j ) && ( Arr[i] != Arr[k] ) )
	    {
			k ++;
	    }
	    if( k > j )
	    {
			j ++;
            Arr[j] = Arr[i];
	    }
	}
	listSize = j + 1;/*(1)��i ���ƴ���������j  �������ظ�����
(2)��k ���ڱ������ظ������� i �е�Ԫ�ؽ��жԱȣ���û���ظ��ͽ���ǰ i 
	��ָ��Ԫ���� j ���Ƶ����ظ������У����ظ����򳤶�+1��*/
	return true;
}

bool SeqList::unionSet( SeqList& LA, SeqList& LB )
{
	if( LA.isEmpty() || LB.isEmpty() )
	{
		cout << "������һ��˳���Ϊ�գ�����ʧ�ܣ�" << endl;
		return false;
	}
	int i = 0, j = 0;
	while( i < LA.listSize && j < LB.listSize )
	{
		if( LA.Arr[i] == LB.Arr[j] )
		{
			i ++;
			j ++;
		}
		else if( LA.Arr[i] < LB.Arr[j] )
		{
			LA.insertList_1( LB.Arr[j] );
			i ++;
		}
		else if( LA.Arr[i] > LB.Arr[j] )
		{
			LA.insertList_1( LB.Arr[j] );
			j ++;
		}
	}
	while( j <  LB.listSize )
	{
		LA.insertList_1( LB.Arr[j] );
		j ++;
	}
	return true;
}

bool SeqList::unionSet( SeqList& LA, SeqList& LB, SeqList& LC )
{
	if( LA.isEmpty() || LB.isEmpty() )
	{
		cout << "������һ��˳���Ϊ�գ�����ʧ�ܣ�" << endl;
		return false;
	}
	int i = 0, j = 0;
	while( i < LA.listSize && j < LB.listSize )
	{
		if( LA.Arr[i] == LB.Arr[j] )
		{
			LC.insertList_1( LA.Arr[i] );
			//LC.insertList_1( LB.Arr[j] );
			i ++;
			j ++;
		}
		else if( LA.Arr[i] < LB.Arr[j] )
		{
			LC.insertList_1( LA.Arr[j] );
			i ++;
		}
		if( LA.Arr[i] > LB.Arr[j] )
		{
			LC.insertList_1( LB.Arr[j] );
			j ++;
		}
	}
	while( i <  LA.listSize )
	{
		LC.insertList_1( LA.Arr[i] );
		i ++;
	}
	while( j <  LB.listSize )
	{
		LC.insertList_1( LB.Arr[j] );
		j ++;
	}
	return true;
}

bool SeqList::subTractSet( SeqList& LA, SeqList& LB, SeqList& LC )
{
	if( LA.isEmpty() || LB.isEmpty() )
	{
		cout << "������һ��˳���Ϊ�գ�����ʧ�ܣ�" << endl;
		return false;
	}
	for( int i = 0; i < LA.listSize; i ++ ) 
	{ 
		int j = 0; 
		while( j < LB.listSize && LB.Arr[j] != LA.Arr[i] ) 
			j ++; 
		if( j == LB.listSize ) //��ʾA->data[i]����B�У�����ŵ�C�� 
			//C->data[ k++]=A->data[i];
			LC.insertList_1( LA.Arr[i] );
	}
	return true;
}

bool SeqList::intersectionSet( SeqList& LA, SeqList& LB )
{
	if( LA.isEmpty() || LB.isEmpty() )
	{
		cout << "������һ��˳���Ϊ�գ�����ʧ�ܣ�" << endl;
		return false;
	}
	int i = 0, j = 0;
	while( i < LA.listSize && j < LB.listSize )
	{
		if( LA.Arr[i] == LB.Arr[j] )
		{
			i ++;
			j ++;
		}
		else if( LA.Arr[i] < LB.Arr[j] )
		{
			i ++;
		}
		else
		{
			//LA.deleteListNode_1( LA.Arr[i] );
			j ++;
		}
	}
	LA.listSize = i;
	
	return true;
}

bool SeqList::subTractSet( SeqList& LA, SeqList& LB )
{
	if( LA.isEmpty() || LB.isEmpty() )
	{
		cout << "������һ��˳���Ϊ�գ�����ʧ�ܣ�" << endl;
		return false;
	}
	int i = 0, j = 0;
	while( i < LA.listSize && j < LB.listSize )
	{
		if( LA.Arr[i] == LB.Arr[j] )
		{
			LA.deleteListNode_1( LA.Arr[i] );
			i ++;
			j ++;
		}
		else if( LA.Arr[i] < LB.Arr[j] )
		{
			i ++;
		}
		else
		{
			j ++;
		}
	}
	return true;
}

bool SeqList::subSet( SeqList& LA, SeqList& LB )
{
	int i = 0, j = 0;
	while( i < LA.listSize && j < LB.listSize )
	{
		if( LA.Arr[i] == LB.Arr[j] )
		{
			i ++;
			j ++;
		}
		else if( LA.Arr[i] > LB.Arr[j] )
		{
			j ++;
		}
		else
		{
			return false;	
		}
	}
	if( i >= LA.listSize )
		return true;
	else
		return false;
	
}

int SeqList::midSearch( SeqList& LA, SeqList& LB )
{
	int start1 = 0, end1 = LA.listSize - 1, m1, start2 = 0, end2 = LB.listSize - 1, m2;
	//�ֱ��ʾ����A��B����λ����ĩλ������λ��
 
	while( start1 != end1 || start2 != end2 )
	{
		m1 = (start1 + end1) / 2;
		m2 = (start2 + end2) / 2;
		if ( LA.Arr[m1] == LB.Arr[m2] )
			return LA.Arr[m1];   //�������� 1)
 
		if( LA.Arr[m1] < LB.Arr[m2] ) // �������� 2)
		{  
			if(  (start1 + end1 ) % 2 == 0 )  //��Ԫ�ظ���Ϊ����
			{  
				start1 = m1;  //����A�м����ǰ�Ĳ����ұ����м��
				end2 = m2;  //����B�м���Ժ�Ĳ����ұ����м��
			}
			else				//Ԫ�ظ���Ϊż��
			{ 
				start1 = m1 + 1;  //����A�м�㼰�м����ǰ����
				end2 = m2;  //����B�м���Ժ󲿷��ұ����м��
			}
		}
		else
		{  //��������3)
			if( ( start2 + end2 ) % 2 == 0 )   //��Ԫ�ظ���Ϊ����
			{ 
				end1 = m1;    //����A�м���Ժ�Ĳ����ұ����м��
				start2 = m2;    //����B�м����ǰ�Ĳ����ұ����м��
			}
			else     //Ԫ�ظ���Ϊż��
			{  
				end1 = m1;    //����A�м���Ժ󲿷��ұ����м��
				start2 = m2 + 1;    //����B�м�㼰�м����ǰ����
			}
		}
	}
	return  LA.Arr[start2] < LB.Arr[start2] ? LA.Arr[start1] : LB.Arr[start2];
}

/*
�����������Ҳ�������������֮�����ס��Ƚ����ϵĽ��������ճ���ڴˣ�
�����漰�����ݽṹ��˳����ʵ�֡�ɾ�������롢���ҵ�֪ʶ����鿴�����ݽṹ -> ���Ա�
����������

һ������ΪL (L>=1)����������S�����ڵ�[L/2]��λ�õ�����ΪS����λ�������磬������S1=(11, 13, 15, 17, 19)����S1����λ����15���������е���λ���Ǻ���������Ԫ�ص��������е���λ�������磬��S2= (2, 4��6��8, 20)����S1��S2����λ����11�������������ȳ���������A��B�������һ����ʱ��Ϳռ������涼�����ܸ�Ч���㷨���ҳ���������A��B����λ����Ҫ��
1) �����㷨�Ļ������˼�롣
2) �������˼�룬���C��C++��Java���������㷨���ؼ�֮������ע�͡�
3) ˵����������㷨��ʱ�临�ӶȺͿռ临�Ӷȡ�

����Ϊ2011���о������Լ�����������⡣
������

(1)�㷨�Ļ������˼�����£�

�ֱ���������������A��B����λ������Ϊa��b,������A��B����λ���������£�

1) ��a=b����a��b��Ϊ������λ�����㷨������

2) ��a<b������������A�н�С��һ�룬ͬʱ��������B�нϴ��һ�룬Ҫ�����������ĳ�����ȡ�

3) ��a>b������������A�нϴ��һ�룬ͬʱ��������B�н�С��һ�룬Ҫ�����������ĳ�����ȡ�

(2)�㷨ʵ������

�ڱ������������������У��ظ�����1)��2)��3)��ֱ�����������о�ֻ��һ��Ԫ��ʱΪֹ����С�߼�Ϊ�������λ����
(3)�㷨��ʱ�临�Ӷ�ΪO(log2n)���ռ临�Ӷ�ΪO(1)��
--------------------- 
���ߣ�mishidemudong 
��Դ��CSDN 
ԭ�ģ�https://blog.csdn.net/u010159842/article/details/47037487?utm_source=copy 
��Ȩ����������Ϊ����ԭ�����£�ת���븽�ϲ������ӣ�
*/