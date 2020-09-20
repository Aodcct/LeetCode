// 法一:字典树

#define MAX_CHILD_NUM 26

class TrieNode
{
public:
    TrieNode() : num(0) , flag(false) { memset(child, 0, sizeof(child)); }
    int num;
    bool flag;
    TrieNode* child[MAX_CHILD_NUM];
};

TrieNode *root, *p;

void Insert(const string& str)
{
    p = root;
    for(char c : str)
    {
        int temp = c - 'a';
        if(p->child[temp] == nullptr)
        {
            p->child[temp] = new TrieNode();
        }
        p = p->child[temp];
        (p->num)++;
    }
    p->flag = true;
}

int Query(const string& str)
{
    p = root;
    for(char c : str)
    {
        int temp = c - 'a';
        if(p->child[temp] == nullptr)
            return -1;
        p = p->child[temp];
    }
    if(p->flag == true)
        return p->num;
    else
        return -1;
}

void Del(TrieNode* p)
{
    for(int i = 0; i < MAX_CHILD_NUM; i++)
    {
        if(p->child[i] != nullptr)
            Del(p->child[i]);
    }
    delete p;
}

string FindLongestCommonPrefix(int strsNum)
{
    p = root;
    string longestCommonPrefix = "";
    while(p != nullptr)
    {
        bool flag = false;
        for(int i = 0; i < MAX_CHILD_NUM; i++)
        {
            if(p->child[i] != nullptr && p->child[i]->num == strsNum)
            {
                longestCommonPrefix += (i + 'a');
                p = p->child[i];
                flag = true;
                break;
            }
        }
        if(flag == false)
            break;
    }
    return longestCommonPrefix;
}

void Debug(TrieNode* p)
{
    if(p != nullptr)
    {
        for(int i = 0; i < MAX_CHILD_NUM; i++)
        {
            if(p->child[i] != nullptr)
            {
                printf("%c %d\n", i + 'a', p->child[i]->num);
                Debug(p->child[i]);
            }
        }
    }
}
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        root = new TrieNode();
        for(string str : strs)
        {
            Insert(str);
        }
        // Debug(root);
        return FindLongestCommonPrefix(strs.size() );
    }
};