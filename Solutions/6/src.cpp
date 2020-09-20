/*
法一：按行访问
复杂度分析： 时间O(n) 空间O(n) 
法二：按列访问*
*/

class Solution {
public:
    string convert(string s, int numRows) {
        
        if (numRows == 1) return s; //!
        
        vector<string> rows(min(numRows, (int)(s.size() ) ) ); //有符号数与无符号运算时强制转换为无符号数，故需将s.size()的返回值转换为有符号数进行比较。
        int curRow = 0;
        bool dir = false;
        for(char c : s)
        {
            rows[curRow] += c;
            if(curRow == 0 || curRow == numRows - 1) dir = !dir;
            curRow += dir ? 1 : -1;
        }
        string ret;
        for(string row : rows) ret += row;
        return ret;
    }
};
