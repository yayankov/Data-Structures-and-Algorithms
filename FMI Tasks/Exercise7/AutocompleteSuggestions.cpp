#include <iostream>
#include <vector>

using namespace std;

struct TrieNode
{
    struct TrieNode *children[26]; //this is the alphabet size
    bool isEndOfWord;
};

struct TrieNode *getNode(void)
{
    struct TrieNode *pNode =  new TrieNode;

    pNode->isEndOfWord = false;

    for (int i = 0; i < 26; i++)
        pNode->children[i] = NULL;

    return pNode;
}

void insert(struct TrieNode *root, string key)
{
    struct TrieNode *pCrawl = root;

    for (int i = 0; i < key.length(); i++)
    {
        int index = key[i] - 'a';
        if (!pCrawl->children[index])
            pCrawl->children[index] = getNode();

        pCrawl = pCrawl->children[index];
    }

    pCrawl->isEndOfWord = true;
}

int wordCount(struct TrieNode *root)
{
    int result = 0;
    if (root -> isEndOfWord)
        result++;

    for (int i = 0; i < 26; i++)
      if (root -> children[i])
         result += wordCount(root -> children[i]);

    return result;
}

int ctr=0;
int search(struct TrieNode *root, string key)
{
    struct TrieNode *pCrawl = root;

    for (int i = 0; i < key.length(); i++)
    {
        int index = key[i] - 'a';
        if (!pCrawl->children[index])
            return 0;

        pCrawl = pCrawl->children[index];
    }
    //pCrawl->isEndOfWord = true;
    return  wordCount(pCrawl);
}


int main()
{
    int N;
    scanf("%d",&N);
    int Q;
    scanf("%d",&Q);
    
    char keys[100000];
    
    vector<string> newWord;

    struct TrieNode *root = getNode();
    for (int i = 0; i < N; i++)
    {
        //cin >> keys;
        scanf("%100000s", &keys);
        insert(root, keys);
    }
    string str;
    for(int i=0;i<Q;i++)
    {
        cin >> str;
     //   scanf("%10000s",&str);
        newWord.push_back(str);
    }

    for(int i=0;i<Q;i++)
    {
        int k = search(root, newWord[i]);
        //cout<<k<<endl;
        printf ("%d \n",k);
    }

    return 0;
}
