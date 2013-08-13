// PocoNetTest.cpp : Defines the entry point for the console application.
//

#include <stdio.h>
#include <tchar.h>
#include "E:\Works\Git-Space\PocoTest\test\CSimpleSocket.h"

int _tmain(int argc, _TCHAR* argv[])
{
	using namespace std;

	CSimpleSocket simple;
	simple.test();
	cin.get();
	return 0;
}

