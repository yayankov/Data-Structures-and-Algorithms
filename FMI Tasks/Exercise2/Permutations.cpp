#include<iostream>
#include<string>
using namespace std;

bool Sort(string word1,string word2)
{
    int len=word1.length();
    int Count[26]={0};

    for(int i=0;i<len;i++)
    {
        Count[word1[i]-'a']++;
    }
    int Count2[26]={0};

    for(int i=0;i<len;i++)
    {
        Count2[word2[i]-'a']++;
    }
    bool isTrue=true;
    for(int i=0;i<26;i++)
    {
        if(Count[i]!=Count2[i])
            isTrue=false;
    }
    return isTrue;

}

int main()
{
    int len;
    cin>>len;
    string word1;

    cin>> word1;
    string word2;
    cin>> word2;
    if(    Sort(word1,word2))

    {
        cout<<"yes";
    }
    else {
        cout<<"no";
    }
    return 0;
}
