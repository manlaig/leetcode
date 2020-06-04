class Solution:
    def helper(self, w1, w2, w1_curr, w2_curr, d):
        if (w1_curr, w2_curr) in d:
            return d[(w1_curr, w2_curr)]
        if(w1_curr >= len(w1)):
            return len(w2) - w2_curr
        elif(w2_curr >= len(w2)):
            return len(w1) - w1_curr
        
        if w1[w1_curr] == w2[w2_curr]:
            d[(w1_curr, w2_curr)] = self.helper(w1,w2, w1_curr+1, w2_curr+1, d)
        else:
            d[(w1_curr, w2_curr)] = min(self.helper(w1, w2, w1_curr+1, w2_curr, d),
                                        self.helper(w1, w2, w1_curr+1, w2_curr+1, d), 
                                        self.helper(w1, w2, w1_curr, w2_curr+1, d)) + 1
        return d[(w1_curr, w2_curr)]
        
    def minDistance(self, word1: str, word2: str) -> int:
        d = {}
        return self.helper(word1, word2, 0, 0, d)