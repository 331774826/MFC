// ClientSocket.cpp : 实现文件
//

#include "stdafx.h"
#include "StoreMan.h"
#include "ClientSocket.h"
#include "ServerSocket.h"


// CClientSocket

CClientSocket::CClientSocket()
{
	m_pParent = NULL;
}

CClientSocket::~CClientSocket()
{

}


// CClientSocket 成员函数

void CClientSocket::OnClose(int nErrorCode)
{
	// TODO: 在此添加专用代码和/或调用基类

	if(m_pParent)
	{
		CSocketMan* pSock = (CSocketMan*) m_pParent;

		pSock->CloseSock();
	}

	CAsyncSocket::OnClose(nErrorCode);
}


void CClientSocket::OnReceive(int nErrorCode)
{
	// TODO: 在此添加专用代码和/或调用基类
	if(m_pParent)
	{
		CSocketMan* pSock = (CSocketMan*) m_pParent;

		pSock->RecvData();
	}

	CAsyncSocket::OnReceive(nErrorCode);
}
