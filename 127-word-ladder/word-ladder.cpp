class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {

        unordered_set<string> set(wordList.begin(), wordList.end());

        if (set.find(endWord) == set.end())
            return 0;

        queue<string> q;
        q.push(beginWord);

        int level = 1;

        while (!q.empty()) {

            int size = q.size();

            for (int j = 0; j < size; j++) {

                string word = q.front();
                q.pop();

                if (word == endWord)
                    return level;

                for (int i = 0; i < word.length(); i++) {

                    char original = word[i];

                    for (char ch = 'a'; ch <= 'z'; ch++) {

                        word[i] = ch;

                        string next = word;

                        if (set.find(next) != set.end()) {
                            q.push(next);
                            set.erase(next);
                        }
                    }

                    word[i] = original;
                }
            }

            level++;
        }

        return 0;
    }
};