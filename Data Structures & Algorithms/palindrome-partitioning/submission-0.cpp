class Solution {
public:
    bool isPalindrome(string s, int start, int end){
        while(start < end){
            if(s[start] != s[end]) return false;
            start++, end--;
        }
        return true;
    }
    void backtrack(string &s, int start, vector<string> &curr, vector<vector<string>> &result){
        int n = s.size();
        if(start == n){
            result.push_back(curr);
            return;
        }

        for(int end=start; end<n; end++){
            if(isPalindrome(s, start, end)){
                curr.push_back(s.substr(start, end-start+1));
                backtrack(s, end+1, curr, result);
                curr.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> result;
        vector<string> curr;
        backtrack(s, 0, curr, result);
        return result;
    }
};
