// ServerSocket.cpp : 实现文件
//

#include "stdafx.h"
#include "StoreMan.h"
#include "ServerSocket.h"
#include "StoreManUpdate.h"

// CServerSocket

CSocketMan::CSocketMan()
	: m_bConnect(FALSE)
	, m_bServer(FALSE)
{
}

CSocketMan::~CSocketMan()
{
}

// 初始化
BOOL CSocketMan::InitSock(bool bServer, CString strIP, UINT nPort)
{
	if(bServer)
	{
		m_bServer = TRUE;

		return InitServer(strIP,nPort);
	}
	else
	{
		return InitClient(strIP,nPort);
	}

	return FALSE;
}

// 初始化客户端
BOOL CSocketMan::InitClient(CString strIP , UINT nPort)
{
	if(!Create())return FALSE;

	m_bConnect = Connect(strIP,nPort);

	g_StoreUpdate.m_bInitConnectOK = m_bConnect;

	return m_bConnect;
}

// 初始化服务端
BOOL CSocketMan::InitServer(CString strIP, UINT nPort)
{
	if(!Create(nPort,SOCK_STREAM,FD_READ | FD_WRITE | FD_OOB | FD_ACCEPT | FD_CONNECT | FD_CLOSE,strIP))return FALSE;

	m_sockClient.m_pParent    = this;

	return Listen();
}


void CSocketMan::OnAccept(int nErrorCode)
{
	// TODO: 在此添加专用代码和/或调用基类

	if(m_bServer)
	{
		m_sockClient.Close();

		BOOL bRet = Accept(m_sockClient);

		m_bConnect = TRUE;

		g_StoreUpdate.m_bInitConnectOK = m_bConnect;
	}

	CAsyncSocket::OnAccept(nErrorCode);
}


void CSocketMan::OnClose(int nErrorCode)
{
	// TODO: 在此添加专用代码和/或调用基类

	m_bConnect = FALSE;

	CAsyncSocket::OnClose(nErrorCode);
}

void CSocketMan::OnReceive(int nErrorCode)
{
	// TODO: 在此添加专用代码和/或调用基类
	if(m_bConnect)
	{
		memset(m_pBuff,0,sizeof(m_pBuff));

		if(!m_bServer)
		{
			Receive(m_pBuff,sizeof(m_pBuff));
		}
	}

	CAsyncSocket::OnReceive(nErrorCode);
}


// 发送数据
BOOL CSocketMan::SendData(char* pBuffdata , int nLen)
{
	BOOL bSend = FALSE;

	if(m_bServer)
	{
		bSend = m_sockClient.Send(pBuffdata,nLen);
	}
	else
	{
		bSend = Send(pBuffdata,nLen);
	}

	return bSend;
}


// 接收数据
BOOL CSocketMan::RecvData()
{
	memset(m_pBuff,0,sizeof(m_pBuff));

	int nCount = m_sockClient.Receive(m_pBuff,sizeof(m_pBuff));

	return TRUE;
}

// 关闭
void CSocketMan::CloseSock()
{
	m_sockClient.Close();

	m_bConnect = FALSE;

	g_StoreUpdate.m_bInitConnectOK = m_bConnect;
}
