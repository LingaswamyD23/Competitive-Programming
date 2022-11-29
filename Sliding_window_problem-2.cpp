#include<iostream>
#include <algorithm>
#include<vector>
using namespace std;

class SlidingWindow{
    public:
    int smallest_subarry(vector<int> arr, int s){
        int windowStart = 0, windowSum = 0, minLengthSoFar = 9999;
        for (int windowEnd=0; windowEnd< arr.size(); windowEnd++){
                windowSum +=arr[windowEnd];

                while(windowSum>=s){
                    int currentWindowLength = windowEnd-windowStart+1;
                    minLengthSoFar = min(minLengthSoFar,currentWindowLength);
                    windowSum -=arr[windowStart];
                    windowStart +=1;
                }
        }
        if (minLengthSoFar == 9999){
            return 0;
        }
        return minLengthSoFar;
    }

};

int main(){
    SlidingWindow obj;
    vector <int> a{1,3,2,2,4,5};
    cout<<obj.smallest_subarry(a, 6);
}
