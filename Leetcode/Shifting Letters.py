class Solution:
    def shiftingLetters(self, S: str, shifts: List[int]) -> str:
        a = [0] * len(shifts)
        n = len(shifts)
        a[n-1] = shifts[n-1] % 26
        for i in range(n-2,-1,-1):
            a[i] = (a[i+1] + shifts[i]) % 26
        new = []
        new = list(S)
        for i in range(n):
            new[i] =chr((ord(S[i]) - ord('a') + a[i] )% 26 + ord('a')) 
            #S[i] = chr((ord(S[i]) - ord('a') + a[i] )% 26) # wont work as python strings are immutable, convert into list and then do updation and later return string
        #for i in new:
        #    print(i, end = " ")
        return "".join(new)