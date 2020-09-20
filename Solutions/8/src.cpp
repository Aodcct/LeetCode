class Solution {
public:
    int myAtoi(string str) {
        int index = 0;
        long long ret = 0;
        bool negative = false;
        while(str[index] == ' ')
            index++;
        
        if(index == str.size() )
            return 0;
        
        if(str[index] == '+') 
        {
            negative = false;
            index++;
        }
        else if(str[index] == '-')
        {
            negative = true;
            index++;
        }
        else if(str[index] > '9' || str[index] < '0')
            return 0;
        
        while(str[index] <= '9' && str[index] >= '0')
        {
            ret = ret * 10 + (negative ? -1 : 1) * (str[index] - '0');
            if( ret > INT_MAX && !negative) return INT_MAX;
            if( ret < INT_MIN && negative) return INT_MIN;
            index++;
        }
        return (int)ret;
    }
};