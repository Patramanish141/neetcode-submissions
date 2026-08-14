class Solution {
public:
    vector<string> neighbors(string word, unordered_set<string> wordSet){
        vector<string> neighbor;
        int n = word.size();

        for(int i=0; i<n; i++){
            char og = word[i];
            for(char ch='a'; ch<='z'; ch++){
                if(ch == og) continue;
                word[i] = ch;
                if(wordSet.count(word)) neighbor.push_back(word);
            }
            word[i] = og;
        }

        return neighbor;
    }
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> wordSet(wordList.begin(), wordList.end());
        if(!wordSet.count(endWord)) return 0;

        queue<pair<string, int>> q;//word, steps
        q.push({beginWord, 1});
        wordSet.erase(beginWord);

        while(!q.empty()){
            auto [word, steps] = q.front();
            q.pop();
            if(word == endWord) return steps;

            for(string v : neighbors(word, wordSet)){
                q.push({v, steps+1});
                wordSet.erase(v);
            }
        }

        return 0;

    }
};
