char _map[10][4];


void DFS(vector<string>& strs, const string& str, int step, int depth, string& temp)
{
    if(step == depth)
    {
        strs.push_back(temp);
        return ;
    }
    for(int i = 0; i < 4; i++)
    {
        if(_map[str[step] - '0'][i] == '#') continue;
        temp[step] = _map[str[step] - '0'][i];
        DFS(strs, str, step + 1, depth, temp);
    }
}

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        
        // init
        memset(_map, 0, sizeof(_map) );
        _map[2][0] = 'a'; _map[2][1] = 'b'; _map[2][2] = 'c'; _map[2][3] = '#';
        _map[3][0] = 'd'; _map[3][1] = 'e'; _map[3][2] = 'f'; _map[3][3] = '#';
        _map[4][0] = 'g'; _map[4][1] = 'h'; _map[4][2] = 'i'; _map[4][3] = '#';
        _map[5][0] = 'j'; _map[5][1] = 'k'; _map[5][2] = 'l'; _map[5][3] = '#';
        _map[6][0] = 'm'; _map[6][1] = 'n'; _map[6][2] = 'o'; _map[6][3] = '#';
        _map[7][0] = 'p'; _map[7][1] = 'q'; _map[7][2] = 'r'; _map[7][3] = 's';
        _map[8][0] = 't'; _map[8][1] = 'u'; _map[8][2] = 'v'; _map[8][3] = '#';
        _map[9][0] = 'w'; _map[9][1] = 'x'; _map[9][2] = 'y'; _map[9][3] = 'z';
        
        vector<string> ans;
        
        if(digits == "") return ans;
        
        
        string temp(digits.size(), ' ');
        DFS(ans, digits, 0, digits.size(), temp);
        return ans;
    }
};