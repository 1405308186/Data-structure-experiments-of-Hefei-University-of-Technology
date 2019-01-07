// graph.cpp: implementation of the graph class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "graph.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

template<class T>
graph<T>::graph( T *array[] )
{

}

template<class T>
graph<T>::~graph()
{

}

template<class T>
void graph<T>::createAdjustedMatrixGraphFromFile( char fileName[] )
{
	FILE* pFile;          //�����ļ�ָ��
	char str[1000];         //��Ŷ���һ���ı����ַ���
	char strTemp[10];      //�ж��Ƿ�ע����
	cellType eWeight;      //�ߵ���Ϣ����Ϊ�ߵ�Ȩֵ
	GraphKind graphType;  //ͼ����ö�ٱ���
	pFile=fopen(fileName,"r");
	if(!pFile)
	{
		printf("�����ļ�%s��ʧ�ܡ�\n",fileName);
		return false;
	}
	while(fgets(str,1000,pFile)!=NULL)
	{
		strLTrim(str);     //ɾ���ַ�����߿ո�����һ���Զ���ĺ���
		if (str[0]=='\n')    //���У�������ȡ��һ��
			continue;
		strncpy(strTemp,str,2);
		if(strstr(strTemp,"//")!=NULL)  //����ע����
			continue;
		else                       //��ע���С��ǿ��У�����ѭ��
			break;
	}
    //ѭ��������str��Ӧ���Ѿ���ͼ�ı�ʶGraph���жϱ�ʶ�Ƿ���ȷ
	if(strstr(str,"Graph")==NULL)
	{
		printf("���󣺴򿪵��ļ���ʽ����\n");
		fclose(pFile); //�ر��ļ�
		return false;
	}
	//��ȡͼ�����ͣ���������
	while(fgets(str,1000,pFile)!=NULL)
	{
		strLTrim(str);    //ɾ���ַ�����߿ո�����һ���Զ��庯��
		if (str[0]=='\n')   //���У�������ȡ��һ��
			continue;
		strncpy(strTemp,str,2);
		if(strstr(strTemp,"//")!=NULL)  //ע���У�������������ȡ��һ��
			continue;		
		else                       //�ǿ��У�Ҳ��ע���У���ͼ�����ͱ�ʶ
			break;
	}
    //����ͼ������
	if(strstr(str,"UDG"))
		graphType=UDG;    //����ͼ
	else if(strstr(str,"UDN"))
		graphType=UDN;    //������
	else if(strstr(str,"DG"))
		graphType=DG;     //����ͼ
	else if(strstr(str,"DN"))
		graphType=DN;     //������
	else
	{
		printf("���󣺶�ȡͼ�����ͱ��ʧ�ܣ�\n");
		fclose(pFile);       //�ر��ļ�
		return false;
	}
	//��ȡ���������ݵ�str����������
	while(fgets(str,1000,pFile)!=NULL)
	{
		strLTrim(str);      //ɾ���ַ�����߿ո�����һ���Զ��庯��
		if (str[0]=='\n')     //���У�������ȡ��һ��
			continue;
		strncpy(strTemp,str,2);
		if(strstr(strTemp,"//")!=NULL)  //ע���У�������������ȡ��һ��
			continue;		
		else                       //�ǿ��У�Ҳ��ע���У���ͼ�Ķ���Ԫ����
			break;
	}

    //�������ݷ���ͼ�Ķ�������	
	char* token=strtok(str," ");
	int nNum=0;	
	while(token!=NULL)
	{
		G.Data[nNum]=*token; 
      token = strtok( NULL, " ");
		nNum++;
	}
	//ͼ���ڽӾ����ʼ��
	int nRow=0;    //�������±�
	int nCol=0;     //�������±�
	if(graphType==UDG || graphType==DG)
	{
		for(nRow=0;nRow<nNum;nRow++)
			for(nCol=0;nCol<nNum;nCol++)
				G.AdjMatrix[nRow][nCol]=0;
	}
	else
	{
		for(nRow=0;nRow<nNum;nRow++)
			for(nCol=0;nCol<nNum;nCol++)
				G.AdjMatrix[nRow][nCol]=INF;  //INF��ʾ�����
	}
		//ѭ����ȡ�ߵ����ݵ��ڽӾ���
	int edgeNum=0;         //�ߵ�����
	elementType Nf, Ns;     //�߻򻡵�2�����ڶ���
	while(fgets(str,1000,pFile)!=NULL)
	{
		strLTrim(str);       //ɾ���ַ�����߿ո�����һ���Զ��庯��
		if (str[0]=='\n')      //���У�������ȡ��һ��
			continue;
		strncpy(strTemp,str,2);
		if(strstr(strTemp,"//")!=NULL)  //ע���У�������������ȡ��һ��
			continue;
		char* token=strtok(str," ");  //�Կո�Ϊ�ָ������ָ�һ�����ݣ�д���ڽӾ���
		if(token==NULL)         //�ָ�Ϊ�մ���ʧ���˳�
		{
			printf("���󣺶�ȡͼ�ı�����ʧ�ܣ�\n");
			fclose(pFile);         //�ر��ļ�
			return false;
		}
		Nf=*token;               //��ȡ�ߵĵ�һ������
		token = strtok( NULL, " ");   //��ȡ��һ���Ӵ������ڶ�������
		if(token==NULL)          //�ָ�Ϊ�մ���ʧ���˳�
		{
			printf("���󣺶�ȡͼ�ı�����ʧ�ܣ�\n");
			fclose(pFile);          //�ر��ļ�
			return false;
		}
		Ns=*token;  //��ȡ�ߵĵڶ�������
                 //�ӵ�һ�������ȡ�к�		
		for(nRow=0;nRow<nNum;nRow++)
		{
			if(G.Data[nRow]==Nf)  //�Ӷ����б��ҵ���һ������ı��
				break;
		}
                  //�ӵڶ��������ȡ�к�
		for(nCol=0;nCol<nNum;nCol++)
		{
			if(G.Data[nCol]==Ns)  //�Ӷ����б��ҵ��ڶ�������ı��
				break;
		}
		//���Ϊ������ȡȨֵ
		if(graphType==UDN || graphType==DN)
		{                //��ȡ��һ���Ӵ������ߵĸ�����Ϣ����Ϊ�ߵ�Ȩ��
			token = strtok( NULL, " ");  
			if(token==NULL)    //�ָ�Ϊ�մ���ʧ���˳�
			{
				printf("���󣺶�ȡͼ�ı�����ʧ�ܣ�\n");
				fclose(pFile);    //�ر��ļ�
				return false;
			}
			eWeight=atoi(token);  //ȡ�ñߵĸ�����Ϣ
		}
		if(graphType==UDN || graphType==DN)  
			G.AdjMatrix[nRow][nCol]=eWeight;
//���Ϊ�����ڽӾ����ж�Ӧ�ı�����Ȩֵ��������Ϊ1
		else
			G.AdjMatrix[nRow][nCol]=1;  
		edgeNum++;   //������1
	}
  G.VerNum=nNum;           //ͼ�Ķ�����
	if(graphType==UDG || graphType==UDN)
		G.ArcNum=edgeNum / 2;  //����ͼ�����ı�������ͳ�Ƶ����ֳ�2  
	else
		G.ArcNum=edgeNum;
	G.gKind=graphType;         //ͼ������
	fclose(pFile);               //�ر��ļ�
	//return true;

}