# Maximum Frequency

#You are given an array of integers that contain numbers in random 
#order. Write a program to find and return the number which occurs the 
#maximum times in the given input.
#If two or more elements contend for the maximum frequency, return the 
#element which occurs in the array first.

def maxFreq(l):
    d = {}
    for w in l:
        if w in d:
            d[w] += 1
        else:
            d[w]=1

    final = max(d)
    for w in l:
        if d[w] == final:
            return w


# Main
n = int(input())
l = list(int(i) for i in input().strip().split(' '))
print(maxFreq(l))
