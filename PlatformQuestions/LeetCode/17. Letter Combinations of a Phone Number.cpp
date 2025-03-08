#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        if(digits.size() == 0) return ans;
        string s = "";
        dfs(digits, 0, s, ans);
        return ans;
    }
    void dfs(string digits, int pos, string s, vector<string>& ans){
        if(pos == digits.size()){
            ans.push_back(s);
            return;
        }
        string letters = getLetters(digits[pos]);
        for(int i = 0; i < letters.size(); i++){
            s += letters[i];
            dfs(digits, pos + 1, s, ans);
            s.pop_back();
        }
    }
    string getLetters(char c){
        switch(c){
            case '2': return "abc";
            case '3': return "def";
            case '4': return "ghi";
            case '5': return "jkl";
            case '6': return "mno";
            case '7': return "pqrs";
            case '8': return "tuv";
            case '9': return "wxyz";
        }
        return "";
    }
};