#include <bits/stdc++.h>
using namespace std;

int main() {
    set<string> compoundwords;
    vector<string> words;
    string word;

    while(cin >> word)
        words.push_back(word);

    for (int i = 0; i < words.size(); i++) {
        for(int j = i+1; j < words.size(); j++) {
            compoundwords.insert(words[i] + words[j]);
            compoundwords.insert(words[j] + words[i]);
        }
    }

    for (auto str : compoundwords) {
        cout << str << "\n";
    }
}