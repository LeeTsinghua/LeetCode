#ifdef _WIN32
#define _CRT_SECURE_NO_DEPRECATE
#pragma warning(disable:4996)
#endif 

#include <iostream>
#include <cstring>
using namespace std;
bool Judge(string &s, int h, int t, int &f);
void string_copy(string &s, char *c, int h, int t);
int main()
{
	char *c_result;
	string s,result;
	int head, tail, flag, r_head, r_tail;
	int len;
	int Temp_len,Max_len;

	s = "au";
	len = s.length();
	flag = 0;
	head = 0;
	tail = 1;
	r_head = 0;
	r_tail = 1;
	Max_len = 0;
	while (head < len)
	{
		Temp_len = tail-head;
		while (tail < len)
		{			
			if (Judge(s,head, tail, flag))
			{
				if (Temp_len > Max_len) 
				{
					Max_len = Temp_len;
					r_head = head;
					r_tail = tail;
				}
				head = flag + 1;
				tail = head + 1;
				break;
			}
			else
			{
				tail++;
				Temp_len++;
			}
		}
		if (tail >= len) 
		{
			break;
		}
	}
	c_result = new char[Max_len+1];
	string_copy(s,c_result, r_head, r_tail);
	result = c_result;
	return 0;
}

bool Judge(string &s,int h, int t, int &f)
{
	bool R=false;
	for (int i = h; i < t; i++)
	{
		if (s[i] == s[t]) 
		{
			f = i;
			R = true;
			break;
		}

	}
	return R;
}

void string_copy(string &s, char *c , int h, int t)
{
	int i = 0;
	for ( i = 0; i < t-h; i++)
	{
		c[i] = s[i + h];
	}
	c[i + 1] = '\0';
}