#include <iostream>
#include <queue>
using namespace std;

int main() {
    string st = "aabc";  
    queue<char> q;
    int freq[256] = {0}; 
    for(char c : st){
        q.push(c);
        freq[c]++;
    }


    while(!q.empty()){
        char ch = q.front();
        q.pop();

        if(freq[ch] > 1){
            cout << ch << "-1 ";
            freq[ch] = 0;  
        } else if(freq[ch] == 1){
            cout << ch << " ";
            freq[ch] = 0;  
        }
    }

    cout << endl;
}
