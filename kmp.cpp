#include<iostream>
using namespace std;
void filllps(string pat,int n,int lps[])
{
    int len=0;
    lps[0]=0;
    int i=1;
    while(i<n)
    {
        if(pat[i]==pat[len])
        {
            len++;
            lps[i]=len;
            i++;
        }
        else
        {
            if(len==0)
            {lps[i]=0;
                i++;
            }
            else
            {
                len=lps[len-1];
            }
        }
    }
}
void kmp(string txt,string pat,int m,int n,int lps[])
{
    int i=0,j=0;
    while(i<m)
    {
        if(pat[j]==txt[i])
        {
            i++;
            j++;
        }
        if(j==m)
        {
            cout<<i-j;
            j=lps[j-1];
        }
        else if(i<n && pat[j]!=txt[i])
        {
            if(j==0)
            i++;
            else
            {
                j=lps[j-1];

            }     
        }
    }
}
int main()
{
    string txt,pat;
    cin>>txt;
    cin>>pat;
    int m=txt.length();
    int n=pat.length();
    int lps[n];
    filllps(pat,n,lps);
    kmp(txt,pat,m,n,lps);
}