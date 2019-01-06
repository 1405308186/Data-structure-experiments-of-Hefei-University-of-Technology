// _Binary_Tree.h: interface for the _Binary_Tree class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX__BINARY_TREE_H__9381B15F_E185_4489_9415_360A22C0A4E2__INCLUDED_)
#define AFX__BINARY_TREE_H__9381B15F_E185_4489_9415_360A22C0A4E2__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "charLinkedQueue.h"

//�տ�ʼ����дӢ��ע�͵ģ�����֪�Ѷ����ˣ�����ԭ����Ӣ��ע���ұ�����

class _Binary_Tree  
{
public:
	_Binary_Tree();//���������Ĺ��캯��
	_Binary_Tree( elementType *Arr );//�������Ĺ��캯��
	void build( elementType *Arr );//�����齨�����������൱�ڳ�ʼ�������������Ĺ��캯���޷�����������
	void createNode( binTree BT, elementType *Arr, int number );//���ݴ������������������ݹ齨��
	virtual ~_Binary_Tree();//��������
	bool createBinaryTree( binTree &BT, elementType stringLine[100][3], int length, int &row );//�����ı�����
															//�����������
	bool readFileToArray( elementType stringLine[100][3], int &length );//���ı����ݶ����ά������
	bool emptyBinaryTree();//�������пգ��������ڴ��������캯�������Ķ�����
	bool _exit( binTree BT, elementType value );//�жϽڵ������Ƿ��ڶ�������
	binTree getNodePoint();//���ظ��ڵ��ַ
	binTree getNodePoint( binTree BT, elementType value );//����value�ڶ������еĵ�ַ
	binTree getParent( binTree BT, elementType value );//����value�ĸ�ĸ
	void preOrderTraverse(binTree BT);//ǰ�����
	void inOrderTraverse(binTree BT);//�������
	void postOrderTraverse(binTree BT);//�������
	void levelOrderTraverse(binTree BT);//��α���
	void destroy( binTree BT );//���ٶ�����
	void level( binTree BT, int number );//��������и����ڵ�Ĳ��
	int height( binTree BT );//��������߶�
	int numberOfBTreeNode( binTree BT );//���ض������ڵ�����
	int numberOfBTreeLeafNode( binTree BT, int &number );//���ض�����Ҷ�ڵ����
	void numberOfNodeDegreeTwo( binTree BT, int &number );//��������ж�Ϊ2�Ľڵ����
	//void family( binTree BT, elementType1 number );
	void getParent( binTree BT, elementType value, bool &flag );//��value�ĸ��ڵ�
	void getSibling( binTree BT, elementType value, bool &flag );//when call the function, the parameter flag
																//must be assigned for false
																//��value���ֵܽڵ㣬��1����һ��bug
	void getSibling( binTree BT, elementType value );//��value���ֵܽڵ㣬��2
	void getChild( binTree BT, elementType value, bool &flag );//��value���ӽڵ�
	int levelJudge( binTree BT, elementType value, int &number, int level );//����value�ڵ�Ĳ��
	void exchangeLeftAndRightSibling( binTree BT );//������������
	void copyBTree( binTree BT1, binTree BT );//���ƶ�����
	charLinkedQueue clq;//����
	void allLeafToRootPath( binTree BT, elementType *path, int &pathLength );//������Ҷ�ڵ㵽���ڵ�·��
	void binaryTreeLongestPath( binTree BT, elementType *path, int &pathLength, 
		elementType *longestPath, int &longestLength );//��Ҷ�ڵ㵽���ڵ���·��
	binTree nearestAncestor( binTree BT, bitNode *BNode1, bitNode *BNode2 );//�������ڵ���������
																			//����������elementType����
																			//��Ϊ�����ģ����淢���в�ͨ
																			//��������̫���˰�
private:
	bitNode *BTree;

};

#endif // !defined(AFX__BINARY_TREE_H__9381B15F_E185_4489_9415_360A22C0A4E2__INCLUDED_)
