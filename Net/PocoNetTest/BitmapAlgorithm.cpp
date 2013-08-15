#include <stdio.h>
#include <tchar.h>
#include <iostream>

#if 0

#include <iostream>  
using namespace std;  

char *g_bitmap = NULL;    
int g_size = 0;    
int g_base = 0;   

//���ܣ���ʼ��bitmap   
//������ size��bitmap�Ĵ�С����bitλ�ĸ���   
//      start����ʼֵ   
//����ֵ��0��ʾʧ�ܣ�1��ʾ�ɹ�   
int bitmap_init(int size, int start)    
{    
	g_size = size/8+1;  
	g_base = start;  
	g_bitmap = new char[g_size];    
	if(g_bitmap == NULL)  
	{  
		return 0;    
	}  
	memset(g_bitmap, 0x0, g_size);    
	return 1;    
}    

//���ܣ���ֵindex�Ķ�Ӧλ��Ϊ1   
//index:Ҫ���ֵ   
//����ֵ��0��ʾʧ�ܣ�1��ʾ�ɹ�   
int bitmap_set(int index)    
{    
	int quo = (index-g_base)/8 ;  //ȷ�����ڵ��ֽ�  
	int remainder = (index-g_base)%8;  //�ֽ��ڵ�ƫ��    
	unsigned char x = (0x1<<(remainder-1));      
	if( quo > g_size)    
		return 0;  
	g_bitmap[quo] |= x;   //�����ֽ��ڵ��ض�λ��Ϊ1    
	return 1;     
}    

//���ܣ�ȡbitmap��iλ��ֵ   
//i����ȡλ   
//����ֵ��-1��ʾʧ�ܣ����򷵻ض�Ӧλ��ֵ   
int bitmap_get(int i)    
{    
	int quo = (i)/8 ;    
	int remainder = (i)%8;    
	unsigned char x = (0x1<<(remainder-1));    
	unsigned char res;    
	if( quo > g_size)    
		return -1;    
	res = g_bitmap[quo] & x;    
	return res > 0 ? 1 : 0;     
}    


//���ܣ�����indexλ��Ӧ��ֵ     
int bitmap_data(int index)    
{    
	return (index + g_base);    
}    

//�ͷ��ڴ�   
int bitmap_free()    
{    
	delete [] g_bitmap;  
	return 0;  
}      

int _tmain(int argc, _TCHAR* argv[])   
{    
	int a[] = {1,3,8,7,6,3,1,10,78,56,34,23,12,43,54,65,76,87,98,89,300};    
	int i;    
	bitmap_init(300, 0);    
	for(i=0; i<20; i++)  
	{  
		bitmap_set(a[i]);    
	}  
	for(i=0; i<=300; i++)    
	{    
		if(bitmap_get(i) > 0 )    
			cout << bitmap_data(i)<< " ";  
	}    
	cout << endl;    
	bitmap_free();   
	cin.get();


	return 0;    
}    

#endif