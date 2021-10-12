#include <iostream>
#include<string>
#include<vector>

using namespace std;

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
