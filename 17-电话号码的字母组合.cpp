class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> res;
        if(digits.size()==0){
            return res;
        }
        
        string strmap[]={"","#","abc","def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz" };
        string cur_str="";
        combination(res, digits, 0, cur_str,strmap);
        return res;
    }
    void combination(vector<string> &res, string & digits, int start,string & cur_str,string * strmap){
        if(start<0||start>digits.size()){
            return;
        }
        if(start==digits.size()){
            res.push_back(cur_str);
            return;
        }
        int index=digits[start]-'0';
        for(int i=0;i<strmap[index].size();i++){
            char cur_char=strmap[index][i];
            string temp_str=cur_str+cur_char;
            combination(res,digits,start+1,temp_str,strmap);
        }
        
    }
};