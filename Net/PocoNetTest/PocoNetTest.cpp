// PocoNetTest.cpp : Defines the entry point for the console application.
//

#include <stdio.h>
#include <tchar.h>
#include <time.h>
#include <iostream>
#include <hash_map>
#include <map>

#include "E:\Works\Git-Space\PocoTest\test\CSimpleSocket.h"
#include "E:\Works\Git-Space\PocoTest\test\Socks5Client.h"
#include "E:\Works\Git-Space\PocoTest\test\SendRecvFile.h"

#if 0

int _tmain(int argc, _TCHAR* argv[])
{
	using namespace std;
	CSimpleSocket simple;
	simple.test();
	cin.get();
	return 0;
}

#endif

int _tmain(int argc, _TCHAR* argv[])
{
	using namespace std;
	using namespace Poco;
	using namespace Poco::Net;

	CSocks5Client skClient("192.168.108.213", 7778, "03de6c570bfe24bfc328ccd7ca46b76eadaf4334");
	StreamSocket sk;
	bool ret = skClient.GetSocket(sk);
	if (!ret)
	{
		goto tagend;
	}

	if (argc >= 2)
	{
		cout << "begin recv data" << endl;
		CSendRecvFile::recvFile(sk);
	}else
	{
		cout << "begin send data" << endl;
		CSendRecvFile::sendFile(sk);
	}

	sk.close();

tagend:
	cout << "press any key to exit" << endl;
	cin.get();
	return 0;
}

