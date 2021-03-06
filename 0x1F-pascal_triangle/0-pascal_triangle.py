#!/usr/bin/python3
"""
0. Pascals Triangle
"""


def pascal_triangle(n):
    """
    Create Pascals Triangle
    """

    if n <= 0:
        return []
    triangle = [[1]]
    row = 1
    while row < n:
        newRow = [1]
        idx = 1
        while idx < row:
            newRow.append(triangle[row - 1][idx - 1] +
                          triangle[row - 1][idx])
            idx += 1
        newRow.append(1)
        triangle.append(newRow)
        row += 1
    return triangle
