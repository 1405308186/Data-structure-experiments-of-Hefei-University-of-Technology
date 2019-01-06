// charLinkedStack.cpp: implementation of the charLinkedStack class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "charLinkedStack.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

charLinkedStack::charLinkedStack()
{
	top = new CLStack;
	if( !top )
	{
		cerr << "Space allocating falied!Error in linkedStack::linkedStack()!" << endl;
	}
	top->link = NULL;
	//top = NULL;
	len = 0;
}

charLinkedStack::~charLinkedStack()
{
	while(top)
	{
		CLStack *q = top;
		top = top->link;
		delete q;
	}
	top = NULL;
}

bool charLinkedStack::stackEmpty()
{
	//follow style is not suitable for the code
	//return top == NULL;
	return top->link == NULL;
}

bool charLinkedStack::getTop( elementType1& value )
{
	if( stackEmpty() )
	{
		//cerr << "Stack is Empty!Error in linkedStack::getTop!" << endl;
		value = '#';
		return false;
	}
	value = top->data;
	return false;
}

bool charLinkedStack::push( elementType1 value )
{
	CLStack *newNode = new CLStack;
	if( !newNode )
	{
		cerr << "Space allocating falied!" << endl;
		return false;
	}
	newNode->data = value;
	newNode->link = top;
	top = newNode;
	len ++;
	return true;
}

bool charLinkedStack::pop()
{
	if( stackEmpty() )
	{
		cerr << "Stack is empty!Error in linkedStack::pop()!" << endl;
		return false;
	}
	CLStack *tmp = top;
	
	top = top->link;
	delete tmp;
	len --;
	return true;
}

int charLinkedStack::length()
{
	if( stackEmpty() )
	{
		cerr << "Stack is empty!Error in linkedStack::length()" << endl;
		return -1;
	}
	int cnt = 0;
	CLStack *tmp = top;
	while( tmp->link )
	{
		tmp = tmp->link;
		cnt ++;
	}
	return cnt;
}

void charLinkedStack::displayStack()
{
	if( stackEmpty() )
	{
		cerr << "Stack is empty!Error in linkedStack::displayStack()" << endl;
		return;
	}
	CLStack *tmp = top;
	int column = 0;
	while( tmp->link )
	{
		cout << setw(7) << setiosflags(ios::left) << tmp->data << " ";
		//cout << tmp->data << " ";
		column ++;
		if( column % 10 == 0 )
			cout << setw(7) << setiosflags(ios::left) << endl;
		tmp = tmp->link;
	}
	cout << endl;
}

CPStack charLinkedStack::topValue()
{
	return top->link;//write as "return top;" is not available
}

void charLinkedStack::decToHex( ll value )
{
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

bool charLinkedStack::brancheMatch( char *Str )
{
	
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
				//ch1 = NULL;
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
 
bool charLinkedStack::judge(const char *sour, const char *dest)		//���ȸ����������е����ݣ����Կɼ�const�����޶���
{
     assert(sour);//���Կɷ�ֹNULLָ��Ĵ���(���⴫��ָ������������������)
     assert(dest);
	//stack<char> ss;//�����⺯������һ��ջ
	charLinkedStack ss;
	if (strlen(sour) != strlen(dest)) //����������в�һ��������Ȼ�ǷǷ�������
		return false;
 
	ss.push(*sour++); //����Ԫ��ѹջ
	while (*dest != '\0')  
	{
 
		if (ss.stackEmpty() && *sour != '\0') //���ջΪ������ջ����δ�������򲻶�ѹ��Ԫ��
			ss.push(*sour++);
		char x;
		ss.getTop(x);
		while (*dest != x && *sour != '\0') 
		{
			ss.push(*sour++);//�����ջԪ�غ�ջ��Ԫ�ز�ƥ�������ѹ��Ԫ��
			ss.getTop(x);
		}
		ss.getTop(x);
		if (*dest == x )  //���������ȣ�����Ԫ�ص�������ָ��ָ���ջ���е���һλ����
		{
			dest++;
			ss.pop();
			continue;
		}
		ss.getTop(x);
		if (*sour == '\0'&& x != *dest)  //���һֱ����ȣ�֪����ջ���н�����Ϊƥ���ϣ�˵����ջ���зǷ�
		{
			return false;
		}
	}
	return true;//�������кϷ�
}