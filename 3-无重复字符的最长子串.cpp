//https://leetcode-cn.com/problems/longest-substring-without-repeating-characters/description/
//因为字符与ASCII表编号对应,可以直接用数组,也可以用map自己做
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> dictionary(256,-1);//初始化256个-1,'a'在ASCii中为97,dictionary[97]=-1代表a没有被访问过
        int maxLen=0;
        int start=-1;//代表当前子串的开始位置-1,这样当前子串的尾巴位置-start=当前子串长度.
        for(int i=0;i<s.length();i++){
            if(dictionary[s[i]]>start){//当前字符被访问过
                start=dictionary[s[i]];////代表当前子串的开始位置-1
            }
            dictionary[s[i]]=i;//截至当前,字符最后出现时的位置
            if(maxLen<(i-start)) maxLen=i-start;
        }
        return maxLen;
    }
};