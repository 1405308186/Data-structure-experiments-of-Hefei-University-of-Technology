// charSeqStack.cpp: implementation of the charSeqStack class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "charSeqStack.h"


using namespace std;
//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

charSeqStack::charSeqStack()
{
	top = -1;
}

charSeqStack::~charSeqStack()
{

}

bool charSeqStack::stackEmpty()
{
	return top == -1;
}

bool charSeqStack::stackFull()
{
	return top == maxLength - 1;
}

bool charSeqStack::getTop( elementType1& value )
{
	ios::sync_with_stdio(false);
	if( stackEmpty() )
	{
		value = '#';
		//cout << "ջ�գ�����ջ��Ԫ��ʧ�ܣ�charSeqStack" << endl;
		return false;
	}
	value = data[top];
	return true;
}

bool charSeqStack::push( elementType1 value )
{
	ios::sync_with_stdio(false);
	if( stackFull() )
	{
		cout << "ջ����ѹջʧ�ܣ�" << endl;
		return false;
	}
	top ++;
	data[top] = value;
	return true;
}

bool charSeqStack::pop()
{
	if( stackEmpty() )
	{
		cout << "ջ�գ���ջʧ�ܣ�" << endl;
		return false;
	}
	top --;
	return true;
}

int charSeqStack::length()
{
	if( stackEmpty() )
	{
		cout << "ջ�գ�" << endl;
		return -1;
	}
	return top + 1;
}

void charSeqStack::displayStack()
{
	if( stackEmpty() )
	{
		cout << "ջ�գ��޷���ӡ��" << endl;
		return;
	}
	int column = 0;
	for( int i = 0; i <= top; i ++ )
	{
		cout << setw(6) << setiosflags( ios::left ) << data[i];
		column ++;
		if( column % 10 == 0 )
			cout << endl;
	}
	cout << endl;
}

int charSeqStack::topValue()
{
	return top;
}

void charSeqStack::baseTransform( ll value )
{
	if( stackFull() )
	{
		cout << "ջ�������޷�ת����" << endl;
		return;
	}
	ll tmp = value;
	while(tmp)
	{
		ll mod = tmp % 16;
		if( mod <= 9 )
		{
			push( (char) ( mod + '0' ) );
		}
		else
		{
			switch(mod)
			{
			case 10:
				push('A');
				break;
			case 11:
				push('B');
				break;
			case 12:
				push('C');
				break;
			case 13:
				push('D');
				break;
			case 14:
				push('E');
				break;
			case 15:
				push('F');
				break;
			default:
				cerr << "Error in void charSeqStack::transfor()" << endl;
				break;
			}
		}
		tmp /= 16;
	}
}

bool charSeqStack::brancheMatch( char *Str )
{
	
	if( stackFull() )
	{
		cout << "ջ�������޷��жϣ�" << endl;
		return false;
	}
	int i = 0;
	char ch = Str[i];
	elementType1 ch1 = NULL;
	while( ch != '\0' )
	{
		if( ch == '(' || ch == '[' || ch == '{' )
		{
			push(ch);
			
		}
		else if( ch == ')' || ch == ']' || ch == '}' )
		{
			//ch1 = NULL;
			if( !stackEmpty() )
			{
				ch1 = NULL;
				getTop(ch1);
				//��������仰�ŵ��������if�ж�����������ȷ��
				//pop();
				//cout << (*this) << endl;
				if( ( ch == ')' && ch1 == '(' ) || 
					( ch == ']' && ch1 == '[' ) || ( ch == '}' && ch1 == '{' ) )
				{
					//ch = NULL;
					//ch1 = NULL;
					pop();
					//continue;
				}	//ch = Str[ ++ i ];
				
				else if( ( ch == ')' && ch1 != '(' ) || 
					( ch == ']' && ch1 != '[' ) || ( ch == '}' && ch1 != '{' ) )
					return false;
			}
			
			else //if( stackEmpty() && !ch1 )
				return false;
		}
		
		ch = Str[ ++ i ];
	}
	if( stackEmpty() )
	{
		return true;
	}
	
	while( !stackEmpty() )
	{
		pop();
	}
	
	return false;
}