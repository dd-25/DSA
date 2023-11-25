#include<iostream>
using namespace std;

class trie
{
    public:
    trie* alpha[26];
    bool endofword;
    trie()
    {
        for(int i=0;i<26;i++)
        {
            alpha[i]=nullptr;
        }
        endofword=false;
    }
};

void insert(trie* root, string s)
{
    trie* temp=root;
    int n=s.size();
    for(int i=0;i<n;i++)
    {
        if(temp->alpha[s[i]-'a']==nullptr)
        {
            trie* neno=new trie();
            temp->alpha[s[i]-'a']=neno;
        }
        if(i==n-1)
        temp->alpha[s[i]-'a']->endofword=true;
        temp=temp->alpha[s[i]-'a'];
    }
    return;
}

bool search(trie* root, string s)
{
    trie* temp=root;
    int n=s.size();
    for(int i=0;i<n;i++)
    {
        if(temp->alpha[s[i]-'a']==nullptr)
        return false;
        else
        temp=temp->alpha[s[i]-'a'];
    }
    return temp->endofword;
}

int main()
{
    int n;
    cout<<"Enter the number of string you want initially in trie\n";
    cin>>n;
    trie* root1=new trie();
    cout<<"Enter the strings you want initially in trie\n";
    for(int i=0;i<n;i++)
    {
        string x;
        cin>>x;
        insert(root1,x);
    }
    cout<<"Enter the string you want to search\n";
    string s;
    cin>>s;
    if(search(root1,s))
    cout<<"Given string has been found in trie\n";
    else
    cout<<"Given string not found in the trie\n";
    return 0;
}