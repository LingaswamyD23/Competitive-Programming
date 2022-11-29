#include <iostream>
#include <vector>
#include <tuple>
using namespace std;

class TwoPointers{
    public:
    tuple <int, int> findPair( vector <int> arr, int targetSum);

};

tuple <int, int> TwoPointers::findPair( vector <int> arr, int targetSum){
    int leftPointer = 0, rightPointer = arr.size()-1, pairSum;
    while(leftPointer != rightPointer){
        pairSum = arr[leftPointer]+arr[rightPointer];
        if (pairSum == targetSum){
            return make_tuple(arr[leftPointer], arr[rightPointer]);
        }
        else if (pairSum>targetSum){
            rightPointer--;
        }
        else if (pairSum<targetSum){
            leftPointer++;
        }
    }
    return {0, 0};
}

int main(){
    int a, b;
    TwoPointers obj;
    vector <int> arr = {1,2,3,4,5};
    tie(a, b) = obj.findPair(arr, 7);
    cout<<a<<" "<<b<<endl;
    tie(a, b) = obj.findPair({1,6,8,9,10}, 14);
    cout<<a<<" "<<b<<endl;
    tie(a, b) = obj.findPair({1,3,4,6,8,10}, 12);
    cout<<a<<" "<<b<<endl;
    tie(a, b) = obj.findPair({1,2,3,4,5}, 10);
    cout<<a<<" "<<b<<endl;
    //cout<<obj.findPair({1,6,8,9,10}, 14);
    //cout<<obj.findPair({1,3,4,6,8,10}, 12);
    //cout<<obj.findPair({1,2,3,4,5}, 10);
}