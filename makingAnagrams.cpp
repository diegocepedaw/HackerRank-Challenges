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

//https://www.hackerrank.com/challenges/ctci-making-anagrams

int number_needed(string a, string b) {

        string aSorted = a;
        sort(aSorted.begin(), aSorted.end());
        string bSorted = b;
        sort(bSorted.begin(), bSorted.end());

        int delCount = 0;
        int aIndex = 0;
        int bIndex = 0;
        while( aIndex < a.length() || bIndex < b.length())
        {

                if(aIndex >= a.length())
                {
                        delCount++;
                        bIndex++;
                        continue;
                }
                if(bIndex >= b.length())
                {
                        delCount++;
                        aIndex++;
                        continue;
                }

                if(aSorted[aIndex] == bSorted[bIndex])
                {
                        aIndex++;
                        bIndex++;
                        continue;
                }
                if(aSorted[aIndex] < bSorted[bIndex])
                {
                        delCount++;
                        aIndex++;
                        continue;
                }
                if(aSorted[aIndex] > bSorted[bIndex])
                {
                        delCount++;
                        bIndex++;
                        continue;
                }


        }

        return delCount;
}

int main(){
        string a;
        cin >> a;
        string b;
        cin >> b;
        cout << number_needed(a, b) << endl;
        return 0;
}
