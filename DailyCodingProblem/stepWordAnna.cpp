#include <bits/stdc++.h>
using namespace std;
/*
 * A step word is formed by taking a given word, adding a letter, and anagramming the result. For example, starting with the word "APPLE", you can add an "A" and anagram to get "APPEAL".

*  Given a dictionary of words and an input word, create a function that returns all valid step words.
 */

bool isStepAnagram(string s, string t) {
    bool foundOneMismatch = false;
		if (s.length()+1 != t.length()) {
			return false;
		}
		vector<int> counter(26,0);

		for (int i = 0; i < t.length(); i++) {
			counter[s[i] - 'a']++;
			counter[t[i] - 'a']--;
		}
		int sum = 0;
		for (int count : counter) {
		    sum += count;
		}
		if (sum != -1) return false;
		else return true;
}

int main()
{
    string word = "apple";
    vector<string> dict{"appeal", "candyapple", "papple"};

    for (auto & i : dict)
    {
        if (i.length() == word.length()+1)
        {
            if (isStepAnagram(word, i)) cout << i << endl;
        }
    }

    return 0;
}


