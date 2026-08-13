class Solution {
public:
    string foreignDictionary(vector<string>& words) {
        unordered_set<char> allChars;
        for(auto &word : words){
            for(auto &c : word) allChars.insert(c);//now we have all the unique chars
        }

        unordered_map<char, unordered_set<char>> adj;
        unordered_map<char, int> inDeg;
        for(char c : allChars) inDeg[c] = 0;//initializing all chars inDeg as 0;

        for(int i=0; i<words.size()-1; i++){
            string w1 = words[i], w2 = words[i+1];
            int minLen = min(w1.size(), w2.size());
            bool foundDiff = false;

            for(int j=0; j<minLen; j++){
                if(w1[j] != w2[j]){
                    if(!adj[w1[j]].count(w2[j])){
                        adj[w1[j]].insert(w2[j]);
                        inDeg[w2[j]]++;
                    }
                    foundDiff = true;
                    break;
                }
            }

            if(!foundDiff){
                if(w1.size() > w2.size()) return "";
            }
        }

        //now we have adjacency list(BFS Kahn's algo)
        queue<char> q;
        for(auto &it : inDeg){
            if(it.second == 0) q.push(it.first);//pushing our startign point
        }

        // //Debugging
        // for(auto &it : inDeg){
        //     cout << it.first << " " << it.second << endl;
        // }


        string ans = "";
        while(!q.empty()){
            char curr = q.front();
            q.pop();
            ans += curr;

            for(char v : adj[curr]){
                inDeg[v]--;
                if(inDeg[v] == 0) q.push(v);
            }
        }

        if(ans.size() != allChars.size()) return "";
        return ans;

    }
};
