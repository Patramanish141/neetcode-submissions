class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if(digits.empty()) return {};

        vector<string> res = {""};
        vector<string> digitToChar = {
            "", "", "abc", "def", "ghi", "jkl",
            "mno", "qprs", "tuv", "wxyz"
        };

        for(char &digit : digits){
            vector<string> temp;
            for(string &currStr : res){
                for(char &c : digitToChar[digit - '0']){
                    temp.push_back(currStr + c);
                }
            }
            res = temp;
        }

        return res;
    }
};
