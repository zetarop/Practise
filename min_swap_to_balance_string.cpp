/*

You are given a string S of 2N characters consisting of N ‘[‘ brackets and N ‘]’ brackets. 
A string is considered balanced if it can be represented in the for S2[S1] where S1 and S2 are balanced strings. 
We can make an unbalanced string balanced by swapping adjacent characters. Calculate the minimum number of swaps necessary to make a string balanced.
Note - Strings S1 and S2 can be empty.

*/

#include <iostream>
#include<string>
#include<vector>

using namespace std;

//O(n) time | O(n) space
int minimumNumberOfSwaps(string S){
    
    vector<int> obi; // opening bracket index
    for(int i = 0; i < S.size(); i++){
        if(S[i] == '[')
            obi.push_back(i);
    }
    int count = 0;
    int idx = 0;
    int result = 0;
    for(int i = 0; i < S.size(); i++){
        
        if(S[i] == '[')
            count++;
        else{
            count--;
            if(count < 0){
                while(obi[idx] <= i)
                    idx++;
                result += (obi[idx] - i);
                swap(S[i], S[obi[idx]]);
                idx++;
                count = 1;
            }
        }
    }
    return result;
}

int main(){
    
    string s;
    cin >> s;
    cout << minimumNumberOfSwaps(s) << endl;
	return 0;
}
