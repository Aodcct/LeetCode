class Solution {
public:
    string multiply(string num1, string num2) {
        
        
        if(num1[0] == '0' || num2[0] == '0')
            return "0";
        
        
        string ret(num1.size() + num2.size(), '0');
        int carry = 0;
        for(int i = 0; i < num1.size(); i++)
        {
            for(int j = 0; j < num2.size(); j++)
            {
                int index = i + j + 1;
                int temp = (num1[i] - '0') * (num2[j] - '0') + (ret[index] - '0');
                carry = temp / 10;
                ret[index] = (temp % 10) + '0';
                while(carry != 0 && index >= 0)
                {
                    index--;
                    temp = (ret[index] - '0') + carry;
                    carry = temp / 10;
                    ret[index] = (temp % 10) + '0';
                }
            }
        }
        int index = 0;
        while(ret[index] == '0')
            index++;
        return ret.substr(index);
    }
};