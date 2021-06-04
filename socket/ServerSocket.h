#pragma once
// CServerSocket ����Ŀ��
#include "ClientSocket.h"


#define MAX_DATA_BUFF 8194

class CSocketMan : public CAsyncSocket
{

public:
	CSocketMan();
	virtual ~CSocketMan();

	virtual void OnAccept(int nErrorCode);
	virtual void OnClose(int nErrorCode);
	virtual void OnReceive(int nErrorCode);

public:
	BOOL InitSock(bool bServer, CString strIP, UINT nPort);
	//��ʼ�������
	BOOL InitServer(CString strIP, UINT nPort);	
	// ��ʼ���ͻ���
	BOOL InitClient(CString strIP , UINT nPort);
	// ��������
	BOOL SendData(char* pBuffdata , int nLen);
	// ��������
	BOOL RecvData();
	// �ر�
	void CloseSock();
public:
	// �ͻ����ն�
	CClientSocket m_sockClient;
	// ����״̬
	BOOL m_bConnect;
	// �Ƿ�Ϊ�����
	char m_pBuff[MAX_DATA_BUFF];
	// �Ƿ�Ϊ�����
	BOOL m_bServer;

};


