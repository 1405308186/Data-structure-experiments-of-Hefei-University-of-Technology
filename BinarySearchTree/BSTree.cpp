// BSTree.cpp: implementation of the BSTree class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "BSTree.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

BSTree::BSTree()
{
	head = NULL;
	//head = new BSTNode;
	//head->leftChidld = head->rightChild = NULL;
}

BSTree::~BSTree()
{
	ios::sync_with_stdio(false);
	destroy(head);
	cout << "The binary search tree has been destroyed!" << endl;
}

void BSTree::destroy( _BSTree BST )
{
	if(BST)
	{
		destroy( BST->leftChidld );
		destroy( BST->rightChild );
		delete BST;
	}
}

void BSTree::preOrderTraversal( _BSTree BST )
{
	ios::sync_with_stdio(false);
	/*
	if(!BST)
	{
		cerr << "The binary search tree is empty.Error in void BSTree::preOrderTraversal( _BSTree BST )." << endl;
		return;
	}
	*/
	if(BST)
	{
		cout << BST->data << " ";
		preOrderTraversal( BST->leftChidld );
		preOrderTraversal( BST->rightChild );
	}
}

void BSTree::inOrderTraversal( _BSTree BST )
{
	ios::sync_with_stdio(false);
	if(BST)
	{
		inOrderTraversal( BST->leftChidld );
		cout << BST->data << " "; 
		inOrderTraversal( BST->rightChild );
	}
}

void BSTree::createBinarySearchTree( _BSTree BST, elementType value )
{
	//BST = NULL;
	//head = NULL;
	while( cin >> value )
	{
		if( value == "#" )
		{
			return;
		}
		insert( head, value );
	}
}

BSTNode *BSTree::getRootNode()
{
	return head;
}

BSTNode *BSTree::search( _BSTree BST, elementType value )//�ݹ����
{
	ios::sync_with_stdio(false);
	if(!head)
	{
		cerr << "The binary search tree is empty.Error in BSTNode *BSTree::search( _BSTree BST, elementType value )." << endl;
		return NULL;
	}
	else if( BST->data == value )
	{
		return BST;
	}
	else if( BST->data > value )
	{
		return search( BST->leftChidld, value );
	}
	else
	{
		return search( BST->rightChild, value );
	}
}

BSTNode *BSTree::search( _BSTree BST, elementType value, _BSTree &father )//��������
{
	ios::sync_with_stdio(false);
	if(!head)
	{
		cerr << "The binary search tree empty.Error in BSTNode *BSTree::search( _BSTree BST, elementType value, _BSTree &father )." << endl;
		return NULL;
	}
	BSTNode *tmp = head;
	father = NULL;
	while( tmp && tmp->data != value )
	{
		father = tmp;
		if( value < tmp->data )
		{
			tmp = tmp->leftChidld;
		}
		else
		{
			tmp = tmp->rightChild;
		}
	}
	return tmp;
}

bool BSTree::insert( _BSTree BST, elementType value )
{
	//if(!head)
	//{
	//	cerr << "The binary search tree does not exit.Error in bool BSTree::insert( _BSTree BST, elementType value )" << endl;
	//	return false;
	//}
	BSTNode *newNode, *target, *father;

	target = search( head, value, father );
	if(target)
	{
		cerr << "Inserting failed!" << value << " has been exited in the binary search tree.\nError in bool BSTree::insert( _BSTree BST, elementType value )" << endl;
		return false;
	}
	newNode = new BSTNode;
	newNode->data =  value;
	newNode->leftChidld = newNode->rightChild = NULL;
	if(!head)
	{
		head = newNode;
	}
	else if( value < father->data )
	{
		father->leftChidld = newNode;
	}
	else
	{
		father->rightChild = newNode;
	}
	return true;
}

bool BSTree::deleteNode( _BSTree BST, elementType value )
{
	if(!head)
	{
		cerr << "The binary search tree does not exit.Error in bool BSTree::deleteNode( _BSTree BST, elementType value )" << endl;
		return false;
	}
	BSTNode *newNode, *target, *father;
	target = search( head, value, father );
	if( !target )//����ʧ�ܣ���ɾ��
	{
		cerr << "Node-deleting failed!\n" << value << " is not in the binary search tree.\n" << "Error in bool BSTree::deleteNode( _BSTree BST, elementType value )." << endl;
		return false;
	}
	if( target->leftChidld && target->rightChild )//��ɾ��������� *target ���ӽڵ�
	{
		newNode = target->rightChild;			//�� target �������� newNode
		father = target;
		while( newNode->leftChidld )
		{
			father = newNode;
			newNode = newNode->leftChidld;
		}
		target->data = newNode->data;		//�� *newNode �����ݴ��o *target
		target = newNode;					//�ҵ����������Ϊ��ɾ�����
	}
	if( target->leftChidld )			//�����ӣ���¼�ǿպ��ӽ��
	{
		newNode = target->leftChidld;
	}
	else
	{
		newNode = target->rightChild;
	}
	if( target == head )					//��ɾ����Ǹ����
	{
		head = newNode;
	}
	else if( newNode && newNode->data < father->data )		//�������ӣ����ֶ���������
	{
		father->leftChidld = newNode;
	}
	else
	{
		father->rightChild = newNode;
	}
	delete target;
	return true;
}