// SeqList.cpp: implementation of the SeqList class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "SeqList.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

template<class T>
SeqList<T>::SeqList()
{
	arraySize = swapTimes = compareTimes = 0;
	readDataFromFile();
}

template<class T>
SeqList<T>::SeqList( int length )
{
	ios::sync_with_stdio(false);
	srand( time(NULL) );
	Arr = new T[length];
	arraySize = swapTimes = compareTimes = 0;
	for( int i = 0; i < length; i ++ )
	{
		int value = rand() % ( 10000 - 100 + 1 ) + 100;
		Arr[i] = value;
		arraySize ++;
	}
}

template<class T>
SeqList<T>::SeqList( int length, char key )
{
	ios::sync_with_stdio(false);
	srand( time(NULL) );
	Arr = new T[length];
	arraySize = swapTimes = compareTimes = 0;
	int maxValue = -999;
	for( int i = 0; i < length; )
	{
		int value = rand() % ( 10000 - 100 + 1 ) + 100;
		value = max( value, maxValue);
		if( value != maxValue )
		{
			maxValue = value;
			Arr[i] = value;
			i ++;
			arraySize ++;
		}
		else
		{
			maxValue += rand() % 100 + 50;
			Arr[i] = maxValue;
			i ++;
			arraySize ++;
		}
	}
}

template<class T>
SeqList<T>::SeqList( int length, int choice )
{
	ios::sync_with_stdio(false);
	srand( time(NULL) );
	Arr = new T[length];
	arraySize = swapTimes = compareTimes = 0;
	for( int i = 0; i < length; i ++ )
	{
		//int value = rand() % ( 10000 - 100 + 1 ) + 100;
		//Arr[i] = value;
		Arr[i] = i + 1;
		arraySize ++;
	}
}

template<class T>
SeqList<T>::SeqList( int length, double choice )
{
	//freopen( "x2.in", "r", stdin );
	ios::sync_with_stdio(false);
	HANDLE hOut; 
    //  ��ȡ������ľ��
    hOut = GetStdHandle(STD_OUTPUT_HANDLE); 
	srand( time(NULL) );
	Arr = new T[length];
	arraySize = swapTimes = compareTimes = 0;
	SetConsoleTextAttribute(hOut, 128 | 8 | 3 );
	cout << "Please enter the elements of the array sequence in turn:" << endl;
	for( int i = 0; i < length; i ++ )
	{
		//int value = rand() % ( 10000 - 100 + 1 ) + 100;
		//Arr[i] = value;
		//Arr[i] = i + 1;
		cin >> Arr[i];
		arraySize ++;
	}
}
template<class T>
T *SeqList<T>::getArray()
{
	return Arr;
}

template<class T>
void SeqList<T>::readDataFromFile()
{
	ios::sync_with_stdio(false);
	HANDLE hOut; 
    //  ��ȡ������ľ��
    hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	char fileName[50];
	SetConsoleTextAttribute(hOut, 8 | 7 );
	cout << "Please input the name of the file:" << endl;
	cin >> fileName;

	freopen( fileName, "r", stdin );
	int _size = 1;
	Arr = (T*)malloc( sizeof(T) * _size );
	//arraySize ++;
	int length = 0, value;
	//while( scanf( "%d", &value ) != EOF )
	while( cin >> value )
	{
		Arr[arraySize] = value;
		//length ++;
		arraySize ++;
		//if( length >= _arraySize )
		//{
			//_size ++;
		T *Arr2 = (T*)realloc( Arr, sizeof(T) * 2 );
		if(Arr2)
		{
			Arr = Arr2;
		}
		//}
	}
	//cout << length;
	cout << _size << endl;
	/*
	Arr = new T[length];
	cout << length << endl;

	FILE *fp = fopen( fileName, "r" );
	int i = 0;
	//int j = 0;
	//for( i = 0; i)
	while( fscanf( fp, "%d", &Arr[i] ) != EOF )
	{
		i ++;
	}
	
	fclose(fp);
	*/
}

template<class T>
SeqList<T>::~SeqList()
{
	ios::sync_with_stdio(false);
	delete []Arr;
	arraySize = 0;
	cout << "The destruction has been called." << endl;
}

template<class T>
void SeqList<T>::display()
{
	ios::sync_with_stdio(false);
	int column = 0;
	for( int i = 0; i < arraySize; i ++ )
	{
	
		cout << setw(6) << setiosflags(ios::left) << Arr[i] << " ";
		column ++;
		
		if( column% 10 == 0 )
		{
			cout << endl;
		}
	}
	//SetConsoleTextAttribute(hOut, 8 | 7 );
	cout << endl;
}

template<class T>
int SeqList<T>::getArrayLength()
{
	return arraySize;
}

template<class T>
void SeqList<T>::showSwapingAndComparingTimesAndArrayLength()
{
	ios::sync_with_stdio(false);
	HANDLE hOut; 
    //  ��ȡ������ľ��
    hOut = GetStdHandle(STD_OUTPUT_HANDLE); 
	SetConsoleTextAttribute(hOut, 8 | 5 );
	cout << "Array length = " << arraySize << endl;
	cout << "Comparing times = " << compareTimes << endl;
	cout << "Swaping times = " << swapTimes << endl;
	//SetConsoleTextAttribute(hOut, 8 | 7 );
}

template<class T>
void SeqList<T>::judgeIncreasingSequence()
{
	bool flag = true;
	for( int i = 1; i < arraySize; i ++ )
	{
		if( Arr[i] >= Arr[ i - 1 ] )
		{
			continue;
		}
		else
		{
			!flag;
			cout << "Not increasing." << endl;
			cout << i - 1 << "-th --- " << Arr[ i - 1 ] << endl;
			cout << i << "-th ---- " << Arr[i] << endl;
			//return;
		}
	}
	//cout << flag << endl;
	if(flag)
	{
		cout << "Completely increasing." << endl;
	}
	return;
}

template<class T>
void SeqList<T>::fixUpTree( Rec *tree, int pos )
{
	int i = pos;
	if ( i  %  2 )   //iλ��������  
		tree[ ( i - 1 ) / 2 ] = tree[ i + 1 ];   //�������������ڵ�   
	else
		tree[ ( i - 1 ) / 2 ] = tree[ i - 1 ];   //�Һ������������ڵ�   
	i = ( i - 1 ) / 2;
	int j;
	while (i)     //���������ڵ㣬����ֹѭ��   
	{
		i % 2 ? j = i + 1 : j = i - 1;     //ȷ��i���ֵ�j���±�   
		if ( !tree[i].active || !tree[j].active )  //���Һ�����һ��Ϊ��   
		{
			if ( tree[i].active )
				tree[ (i - 1) / 2 ] = tree[i];
			else
				tree[ (i - 1) / 2 ] = tree[j];
		}
		else  //���Һ��Ӷ���Ϊ��   
		{
			if ( tree[i].data <= tree[j].data )
				tree[ ( i - 1 ) / 2 ] = tree[i];
			else
				tree[ ( i - 1 ) / 2 ] = tree[j];
		}
		i = ( i - 1 ) / 2;   //�ص���һ��   
	}
}

template<class T>
void SeqList<T>::treeSelectSort( T a[], int n )
{
	int i = 0;
	while ( pow( double(2), i ) < n )
		i ++;
	int leaf = pow( 2, i );   //��ȫ������Ҷ�ӽڵ����   
	int size = 2 * leaf - 1;   //���ڵ�����  ��ʾ3  
	Rec *tree = new Rec[size];  //˳��洢һ����   
	for ( i = 0; i < leaf; i ++ )
	{
		if (i < n )
		{
			//leaf-1��Ҷ�ӽڵ����ʼ�±�
			tree[ i + leaf - 1 ].data = a[i];
			tree[ i + leaf - 1 ].index = i;
			tree[ i + leaf - 1 ].active = true;
		}
		else//Ҷ�ӽڵ��±�� leaf-1+n��ʼ�����涼�ǿյģ��޴˲�����  
			tree[ i + leaf - 1 ].active = false;    
	}
	i = leaf - 1;    //��ʾ3  
	int j;
	while (i)   //���������ڵ㣬����ֹѭ��   
	{
		j = i;
		while ( j < 2 * i )   //�������ʾ4  
		{
			//���ҽڵ���ҽڵ��ѳ��֣���ʹ�����ҽڵ㣬��ֵ��Ҳ����ڵ��  
			if ( ! tree[j + 1].active || tree[j + 1].data > tree[j].data )  
				tree[ ( j - 1 ) / 2 ] = tree[j];
			else
				tree[ ( j - 1 ) / 2 ] = tree[j + 1];
			j += 2;     //�����Ƚ�   
		}
		i = ( i - 1 ) / 2;  //�ص���һ��    
	}
	i = 0;
	while ( i < n - 1 ) //ȷ��ʣ�µ�n-1���ڵ�Ĵ���   
	{
		a[i] = tree[0].data;
		tree[ leaf - 1 + tree[0].index ].active = false; //���֣���������һ��
		//ÿ�γ��ֺ������
		fixUpTree( tree, leaf - 1 + tree[0].index );
		i ++;
	}
	a[ n - 1 ] = tree[0].data;  //���һ����λ   
	delete []tree;
}