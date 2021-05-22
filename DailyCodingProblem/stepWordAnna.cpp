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
map<string,vector<string>> create_wordmap(vector<string> dict)
{
    map<string, vector<string>> wordmap;
    for (auto word :dict)
    {
        string orig_word  = word;
        sort(word.begin(), word.end());
        wordmap[word].push_back(orig_word);
    }

    return wordmap;
}

vector<string> step_words(string word, vector<string> dict) {
    map<string, vector<string>> word_map = create_wordmap(dict);
    vector<char> ascii_lowercase(26, 0);
    for (int i = 0; i < 26; i++)
        ascii_lowercase[i] = 'a' + i;

    vector<string> results;
    for (auto letter : ascii_lowercase) {
        string word_sample = word + letter;
        sort(word_sample.begin(), word_sample.end());
        if (word_map[word_sample].size() != 0)
            for (auto str : word_map[word_sample])
                results.push_back(str);
    }
    return results;
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

    cout << "***************" << endl;
    vector<string> results = step_words(word, dict);
    for (auto str : results)
        cout << str << endl;

    cout << "ending.. " ;
    return 0;
}

/*
 * We would like to come up with an organized way to represent the words in our dictionary. The main features should be that we can efficiently find words that are consist of certain letters, and that two words with the same letters, such as "TEAM" and "MEAT", should have the same key. For this we can use a hash map, where each key is a sorted list of word letters, and each value is a list of the corresponding words.

from collections import defaultdict

def create_wordmap(dictionary):
    wordmap = defaultdict(list)
    for word in dictionary:
        wordmap[tuple(sorted(word))].append(word)
    return wordmap
Creating this hash map will require us to loop through N words and sort each of them. If the average word length is k, we can consider this method to take O(N * k log k) time. The space needed will be O(N).

To find step words, we can loop through each letter of the alphabet, add it to the letters of the given word, and check if any values are stored for this key in our hash map. If so, we add those values to our result list.

from string import ascii_uppercase

def step_words(word, dictionary):
    wordmap = create_wordmap(dictionary)

    step_words = []
    for letter in ascii_uppercase:
        key = tuple(sorted(word + letter))
        if wordmap[key]:
            step_words.extend(wordmap[key])

    return step_words
If we consider the 26 letters of the alphabet to be a constant multiplier, and if our word map is created beforehand, finding step words will only take as much time as sorting the letters of our input word, or O(k log k). In the worst case, every word in the dictionary could be an anagram of the given word, so this would still require O(N) space.
 */
