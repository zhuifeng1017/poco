#if 0
#include <stdio.h>
#include <tchar.h>
#include <time.h>
#include <iostream>
#include <hash_map>
#include <map>
#include <Windows.h>

////  测试stl hash_map bucket数量变化
/// 
int _tmain(int argc, _TCHAR* argv[])
{
	using namespace std;
	using namespace stdext;

	hash_map<unsigned, unsigned> m;
	typedef pair<unsigned, unsigned> UInt_Pair;
	m.rehash(64);
	cout << "max_load_factor:  " <<  m.max_load_factor() << endl;

	unsigned oldBucketCnt = m.bucket_count();
	cout<<"bucket_count:" <<oldBucketCnt<<endl;

	std::srand((int)::time(0));	//RAND_MAX
	for (int i=0; i < 10000; ++i)
	{
		int val = std::rand();
		//m[val] = i;
		m.insert(UInt_Pair(val, i));
		unsigned cnt = m.bucket_count();
		if (oldBucketCnt != cnt)
		{
			cout<<"bucket_count:" <<cnt<<endl;
			oldBucketCnt = cnt;
		}

		//char text[64];
		//sprintf(text, "bucket_count: %d\n", m.bucket_count());
		//OutputDebugStringA(text);
	}

	//map<unsigned, unsigned> mp;

	//CSimpleSocket simple;
	//simple.test();
	cin.get();
	return 0;
}
#endif