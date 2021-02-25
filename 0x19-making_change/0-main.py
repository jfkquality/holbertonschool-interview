#!/usr/bin/python3
"""
Main file for testing
"""

makeChange = __import__('0-making_change').makeChange

print(makeChange([1, 2, 25], 37))

print(makeChange([4, 5, 25], 37))

print(makeChange([5, 7, 25], 37))

print(makeChange([1, 5, 7, 25], 51))

print(makeChange([2, 5, 7, 25], 51))

print(makeChange([1256, 54, 48, 16, 102], 1453))
