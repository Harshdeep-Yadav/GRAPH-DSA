class Solution {
public:
    int wordLadderLength(string startWord, string targetWord, vector<string>& wordList) {
        queue<pair<string,int>>q; // storing the startWort ,sequence number
        q.push({startWord,1});
        unordered_set<string>st(wordList.begin(),wordList.end()); // copy of wordList for marking visited 
        st.erase(startWord); // remove the reached string if exist
        while(!q.empty())
        {
            string word=q.front().first; // der
            int steps=q.front().second; // 1
            q.pop();
            if(word==targetWord) return steps;
            for(int i=0;i<word.size();i++) // travering every character of the word (der)
            {
                char original=word[i]; // first it take orginal = d ,then e ,then r
                for(char ch='a';ch<='z';ch++){
                    word[i]=ch;
                    // it exist in the wordlist
                    if(st.find(word)!=st.end()){
                        st.erase(word);
                        q.push({word,steps+1});
                    }
                }
            word[i]=original;
            }
        }
        return 0;
    }
};