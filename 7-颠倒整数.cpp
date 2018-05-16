//https://leetcode-cn.com/problems/reverse-integer/description/
class Solution {
public:
    int reverse(int x) {
        long int res=0;
        int power=1;
        while(x!=0){
            power=(10*power);
            int low= x%10;
            res=res*10+low;
            x=x/10;  
        }
     
        if(res<-2147483648||res>2147483647){
            return 0;
        }
        return (int)res;
    }
};