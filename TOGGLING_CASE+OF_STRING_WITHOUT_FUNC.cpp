#include<iostream>
#include<stdio.h>
using namespace std;
int main()
{
	char str1[100];int i=0;int t;
	cout<<"Enter the string 1 which you want to toggle : "<<endl;
	gets(str1);
	for(i=0;str1[i]!='\0';i++)
	{
		if(str1[i]>='a'&&str1[i]<='z')
		{
			t=(int)(str1[i]);
			str1[i]=(char)(t-32);
			continue;
		}
		if(str1[i]>='A'&&str1[i]<='Z')
		{
			t=(int)(str1[i]);
			str1[i]=(char)(t+32);
			continue;
		}
	}
	cout<<"The toggled string is : ";
	puts(str1);
	return 0;
}
