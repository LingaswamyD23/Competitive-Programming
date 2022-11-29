#include<iostream>
#include <map>  
#include<vector>
#include<algorithm>
//#include<string>
using namespace std;

class Substring{
    public:
        int longest_substring_with_k_dist_char(string s, int k);
};

int Substring :: longest_substring_with_k_dist_char(string s, int k){
    int windowStart = 0, longestSubstringSoFar = 0;
    map<char, int> letterFrequency;

    for (int windowEnd = 0; windowEnd<s.size(); windowEnd++){
        char windowEndChar = s[windowEnd];
        if (!letterFrequency[windowEndChar]){
            letterFrequency[windowEndChar] = 0;
        } 
        letterFrequency[windowEndChar]++;

        while(letterFrequency.size() > k){
            char windowStartChar = s[windowStart];
            letterFrequency[windowStartChar]--;

            if (letterFrequency[windowStartChar]==0){
                letterFrequency.erase(windowStartChar);
            }
            windowStart++;
        }
        longestSubstringSoFar = max(longestSubstringSoFar, windowEnd-windowStart+1);
    }

    return longestSubstringSoFar;

}


int main(){
    Substring obj ;
    cout<<obj.longest_substring_with_k_dist_char("acccpbbebi", 3)<<endl; //6
    cout<<obj.longest_substring_with_k_dist_char("aaaabbcccd", 1)<<endl; //4
    cout<<obj.longest_substring_with_k_dist_char("abcdefg", 10)<<endl; //7
}