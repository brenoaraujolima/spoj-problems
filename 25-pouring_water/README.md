Given two vessels, one of which can accommodate a litres of water and the other - b litres of water, determine the number of steps required to obtain exactly c litres of water in one of the vessels.

At the beginning both vessels are empty. The following operations are counted as 'steps':

emptying a vessel,
filling a vessel,
pouring water from one vessel to the other, without spilling, until one of the vessels is either full or empty.
 

Input
An integer t, 1<=t<=100, denoting the number of testcases, followed by t sets of input data, each consisting of three positive integers a, b, c, not larger than 40000, given in separate lines.

Output
For each set of input data, output the minimum number of steps required to obtain c litres, or -1 if this is impossible.

Example
Sample input:
2
5
2
3
2
3
4