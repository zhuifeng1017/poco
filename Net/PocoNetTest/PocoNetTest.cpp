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
//03de6c570bfe24bfc328ccd7ca46b76eadaf4334
	//SHA1Engine engine;
	//engine.update("abcde");
	//cout << "_encryptDigest : " <<  SHA1Engine::digestToHex(engine.digest()) << endl;

	CSocks5Client skClient("192.168.108.213", 7778, "abcde");
	StreamSocket sk;
	bool ret = skClient.GetSocket(sk);
	if (!ret)
	{
		goto tagend;
	}

	if (argc >= 2)
	{
		cout << "begin recv data" << endl;
		CSendRecvFile::RecvFile(sk);
	}else
	{
		cout << "begin send data" << endl;
		const char *filePath = "D:\\ãë´¨µØÇø.mimg";
		//const char *filePath = "e:\\20130917085141.bmp";
		CSendRecvFile::SendFile(sk, filePath);
	}

	sk.close();

tagend:
	cout << "press any key to exit" << endl;
	cin.get();
	return 0;
}

