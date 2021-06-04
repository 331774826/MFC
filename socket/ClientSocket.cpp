// ClientSocket.cpp : ʵ���ļ�
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


// CClientSocket ��Ա����

void CClientSocket::OnClose(int nErrorCode)
{
	// TODO: �ڴ����ר�ô����/����û���

	if(m_pParent)
	{
		CSocketMan* pSock = (CSocketMan*) m_pParent;

		pSock->CloseSock();
	}

	CAsyncSocket::OnClose(nErrorCode);
}


void CClientSocket::OnReceive(int nErrorCode)
{
	// TODO: �ڴ����ר�ô����/����û���
	if(m_pParent)
	{
		CSocketMan* pSock = (CSocketMan*) m_pParent;

		pSock->RecvData();
	}

	CAsyncSocket::OnReceive(nErrorCode);
}
