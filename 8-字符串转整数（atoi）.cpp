//https://leetcode-cn.com/problems/string-to-integer-atoi/description/
class Solution {
public:
    int myAtoi(string str) {
        if(str.size()==0){
            return 0;
        }
        long int res=0;
        int sign=1;//正负符号
        int idx=0;
        for(int i=0;i<str.size();i++){
            if(str[i]=='-'){
                if(str[i+1]>='0'&&str[i+1]<='9'){
                    sign=-1;
                    idx=i+1;
                    break;
                }
                else{
                    continue;
                }
                
            }
            else if(str[i]<'0'||str[i]>'9'){
                continue;
            }
            idx=i;
            break;
        }
        while(str[idx]>='0'&&str[idx]<='9'){
            res=res*10+(str[idx]-'0');
            int temp=res*sign;
            if(temp<-INT_MIN||temp>INT_MAX){
                return 0;
            }
            idx++;
        }
        res=res*sign;
        return res;
    }
};