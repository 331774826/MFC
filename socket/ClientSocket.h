#pragma once

// CClientSocket ÃüÁîÄ¿±ê

class CSocketMan;

class CClientSocket : public CSocket
{
	friend class CSocketMan;
public:
	CClientSocket();

	virtual ~CClientSocket();
	// ¸¸Ö¸Õë
	CSocketMan* m_pParent;
public:
	virtual void OnClose(int nErrorCode);
	virtual void OnReceive(int nErrorCode);
};


