class Solution:
    def isCircularSentence(self, sentence: str) -> bool:
        sentence_l = sentence.split(' ')
        for i in range(len(sentence_l)-1):
            if sentence_l[i][-1] != sentence_l[i+1][0]: return False
        return  sentence_l[-1][-1] == sentence_l[0][0]