Comparing texts with updates in O(nlogn+mlogn)
Where “n” is the word length and “m” is the number of updates.
Input format:

n
string
m
m lines with queries

Where one query is
if “u” is the index to be updated and a new letter
if “z” is a comparison of two subwords: a-b, and c-d.


Sample input:
10
abcabcabca
7
z 1 3 4 6
u 2 z
z 1 3 4 6
u 1 z
u 4 z
u 5 z
z 1 3 4 6

Output:
1
0
1
