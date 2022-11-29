class TwoPointers:
    def findPair(arr, targetSum):
        leftPointer = 0
        rightPointer = len(arr)-1
        while(leftPointer!= rightPointer):
            pairSum = arr[leftPointer]+arr[rightPointer]
            if pairSum== targetSum:
                return [arr[leftPointer],arr[rightPointer]]
            elif pairSum<targetSum:
                leftPointer +=1
            elif pairSum>targetSum:
                rightPointer -=1
        return None

if __name__ == '__main__':
    print(TwoPointers.findPair([1,2,3,4,5], 7))
    print(TwoPointers.findPair([1,6,8,9,10], 14))
    print(TwoPointers.findPair([1,3,4,6,8,10], 12))
    print(TwoPointers.findPair([1,2,3,4,5], 10))
