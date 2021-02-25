#!/usr/bin/python3
"""
Main file for testing
"""

makeChange = __import__('0-making_change').makeChange

print(makeChange([1, 2, 25], 37))

print(makeChange([1256, 54, 48, 16, 102], 1453))

print(makeChange([1, 2, 25, 36, 40], 37))

print(makeChange([1, 2, 25, 37], 50))

print(makeChange([2, 4, 26, 37], 50))
