class SlideWindow:
    def longest_substring_with_k_dist_char(strs, k):
        windowStart = 0
        longestSubstrinfSoFar = 0
        letterFrequency = {}
        for windowEnd in range(len(strs)):
            windowEndChar =strs[windowEnd]
            if windowEndChar not in letterFrequency:
                letterFrequency[windowEndChar] = 0
            
            letterFrequency[windowEndChar] +=1

            while(len(letterFrequency)>k):
                windowStartChar = strs[windowStart]
                letterFrequency[windowStartChar]-=1

                if letterFrequency[windowStartChar] ==0:
                    del letterFrequency[windowStartChar]
                
                windowStart +=1
            longestSubstrinfSoFar = max(longestSubstrinfSoFar, windowEnd-windowStart +1)
        
        return longestSubstrinfSoFar


if __name__ == '__main__':
    print(SlideWindow.longest_substring_with_k_dist_char(input(), int(input())))
