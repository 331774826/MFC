#pragma once

// CClientSocket ����Ŀ��

class CSocketMan;

class CClientSocket : public CSocket
{
	friend class CSocketMan;
public:
	CClientSocket();

	virtual ~CClientSocket();
	// ��ָ��
	CSocketMan* m_pParent;
public:
	virtual void OnClose(int nErrorCode);
	virtual void OnReceive(int nErrorCode);
};


