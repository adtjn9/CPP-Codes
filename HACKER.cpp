#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;
int main()
{
    char time[10];
    cout<<"Enter time : "<<endl;
    gets(time);
    char tz;int i=0;int h1,h2,m1,m2,s1,s2;
    for(i=0;i<strlen(time);i++)
    {
        if(time[i]=='A')
        {
            tz='A';
            break;
        }
        if(time[i]=='P')
        {
            tz='P';
            break;
        }
    }
    h1=time[0]-48;
    h2=time[1]-48;
    m1=time[3]-48;
    m2=time[4]-48;
    s1=time[6]-48;
    s2=time[7]-48;
    if(tz=='A')
    {
        if(h1==1&&h2==2)
        {
            time[0]=(char)(48);
            time[1]=(char)(48);
            time[8]='\0';
            time[9]='\0';
        }
        else
        {
            time[8]='\0';
            time[9]='\0';
        }
    }
    else
    {
        if(h1==1&&h2==2)
        {
            time[8]='\0';
            time[9]='\0';
        }
        else
        {
            time[0]=(char)(h1+48+1);
            time[1]=(char)(h2+48+2);
            time[8]='\0';
            time[9]='\0';
        }
    }
    cout<<time;
}
