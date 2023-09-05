#!/usr/bin/python3
"""
In a text file, there is a single character H.
Only by using Ctrl+a and Ctrl+v,
what is the least amount of commands
necessary to make the text file have n H's?

    Here's me trying to figure it out:

    1  2  3  4  5  6  7  8  9  10  11  12  13  14  15  16  17  18  19  20

    0, 2,    4,    5,    6,     7,      8,      9,     10,     11,     12...
    0,    3,       5,       6,          7,          8,          9...
    0,       4,          6,             7,              8,              9...
    0,          5,              7,                  8,                  9...
    0,             6,                   8,                      9...

    0 H 2 HH 4 HHHH 5 HHHHHH 6 HHHHHHHH 7 HHHHHHHHHH 8 HHHHHHHHHHHH
    0 H 3 HHH 5 HHHHHH 6 HHHHHHHHH 7

    After looking at the data, turns out it's a type of factorization.
    Examples:

    20H is just copying 5H and pasting it 4 times
    35H is just copying 7H and pasting it 5 times

    100H is just copying 10H and pasting it 10 times;
        10H is just copying 5H and pasting it 2H times

    ALL PRIME NUMBER P*H IS JUST COPYING H AND PASTING IT P - 1 TIMES.
    """
from math import sqrt


def minOperations(n):
    """
    Returns the amount of commands (Ctrl+a or Ctrl+v)
    it takes to transform a text file with one H
    to have n H's.

    If the aount of H's 'n' is not possible
    to be achieved (negative or 0 H amounts),
    this function returns 0.

    (NOTE THAT FOR 1 H, THE RESUT IS ALSO 0!)
    """

    if n < 1:
        return 0

    # base case
    if n == 1:
        return 0

    # a is the 2nd biggest factor of n,
    # and b is the biggest factor of n.

    a: int = int(sqrt(n))

    while n / a % 1 != 0:
        a -= 1
    b: int = n // a

    return minOperations(a) + b

    
