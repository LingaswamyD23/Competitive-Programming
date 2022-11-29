#find smallest contiguous subarry

def smallest_subarry(arr, s):
    windowStart = 0
    windowSum = 0
    minLengthSoFar = 99999

    for windowEnd in range(len(arr)):
        windowSum +=arr[windowEnd]
        #if not continue iteration grow the window
        #if yes shrink the window
        while windowSum >=s:
            currentWindowLength = windowEnd-windowStart+1
            minLengthSoFar = min(minLengthSoFar,currentWindowLength)
            windowSum -=arr[windowStart]
            windowStart +=1
    if minLengthSoFar == 99999:
        return 0
    return minLengthSoFar

if __name__ == '__main__':
    arr = [1,3,2,2,4,5]
    s = 6
    print(smallest_subarry(arr,s))
    print(smallest_subarry([2,1,5,2,8], 7))