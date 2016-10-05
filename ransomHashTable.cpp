#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

// https://www.hackerrank.com/challenges/ctci-ransom-note

unsigned long DJB2(string str){
    unsigned long hash = 5381;
    int c;

    for (int i = 0; i < str.length(); ++i) {
        c = (int) str[i];
        hash = ((hash << 5) + hash) + c; 
    }
    
    return hash % 911;
}

bool ransom_note(vector<string> magazine, vector<string> ransom) {
    vector< vector <string> > hashTable(912, vector <string>(1));
    for(int iii = 0; iii <magazine.size(); ++iii){
        hashTable[DJB2(magazine[iii])].push_back(magazine[iii]);
    }
    for(int iii=0;iii<ransom.size();++iii){
        int curHash = DJB2(ransom[iii]);
        bool found = false;
        for(int ppp=0;ppp<hashTable[curHash].size();++ppp){
            if(hashTable[curHash][ppp] == ransom[iii]){
                found = true;
                hashTable[curHash].erase(hashTable[curHash].begin()+ppp);
                break;
            }
                
        }
        if(found == false)
            return false;
    }
    return true;
    
    
}

int main(){
    int m;
    int n;
    cin >> m >> n;
    vector<string> magazine(m);
    for(int magazine_i = 0;magazine_i < m;magazine_i++){
       cin >> magazine[magazine_i];
    }
    vector<string> ransom(n);
    for(int ransom_i = 0;ransom_i < n;ransom_i++){
       cin >> ransom[ransom_i];
    }
    
    if(ransom_note(magazine, ransom))
        cout << "Yes\n";
    else
        cout << "No\n";
    
    return 0;
}