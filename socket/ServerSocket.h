#pragma once
// CServerSocket 命令目标
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
	//初始化服务端
	BOOL InitServer(CString strIP, UINT nPort);	
	// 初始化客户端
	BOOL InitClient(CString strIP , UINT nPort);
	// 发送数据
	BOOL SendData(char* pBuffdata , int nLen);
	// 接收数据
	BOOL RecvData();
	// 关闭
	void CloseSock();
public:
	// 客户接收端
	CClientSocket m_sockClient;
	// 连接状态
	BOOL m_bConnect;
	// 是否为服务端
	char m_pBuff[MAX_DATA_BUFF];
	// 是否为服务端
	BOOL m_bServer;

};


