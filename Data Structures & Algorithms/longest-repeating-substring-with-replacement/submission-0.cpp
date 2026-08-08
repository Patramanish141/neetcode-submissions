class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        vector<int> freq(26, 0);
        int maxFreq = 0, ans=0, left=0;

        for(int right=0; right<n; right++){
            freq[s[right] - 'A']++;
            maxFreq = max(maxFreq, freq[s[right] - 'A']);

            int windowLen = right - left + 1;
            if(windowLen - maxFreq > k){//char to be replaced in the window is > k
                freq[s[left] - 'A']--;
                left++;
            }

            ans = max(ans, right - left + 1);
        }
        return ans;
    }
};
