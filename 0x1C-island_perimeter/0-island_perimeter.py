#!/usr/bin/python3
""" Python 3 program to find perimeter of area
#covered by 1 in 2D matrix consisits of 0's and 1's.
"""


def numofneighbour(mat, i, j, row, col):
    """ Find the number of covered side for mat[i][j]."""

    count = 0

    # UP
    if (i > 0 and mat[i - 1][j]):
        count += 1

    # LEFT
    if (j > 0 and mat[i][j - 1]):
        count += 1

    # DOWN
    if (i < row - 1 and mat[i + 1][j]):
        count += 1

    # RIGHT
    if (j < col-1 and mat[i][j + 1]):
        count += 1

    return count


def island_perimeter(grid):
    """ Returns sum of perimeter of shapes formed with 1's. """

    perimeter = 0

    row = len(grid)
    col = len(grid[0])

    # Traversing the matrix and finding ones to
    # calculate their contribution.
    for i in range(0, row):
        for j in range(0, col):
            if (grid[i][j]):
                perimeter += (4 - numofneighbour(grid, i, j, row, col))

    return perimeter


# # Driver Code
# mat = [ [0, 1, 0, 0, 0],
#         [1, 1, 1, 0, 0],
#         [1, 0, 0, 0, 0] ]

# print(findperimeter(mat), end="\n");
# print(island_perimeter(mat), end="\n");

# def island_perimeter(grid):

#     # Eliminate top, bottom "water" rows
#     temp_land = [row for row in grid if 1 in row]

#     land = []
#     # print(len(land))
#     for idx, row in enumerate(temp_land):
#         if 1 in row:
#             new_row = row[1:len(row) - 2]
#             land.append(new_row)
#             print(row.count(1))
#             print(idx, new_row)
#     if len(land) == 0:
#         return 0
#     if len(land) == 1 and row.count(1) == 1:
#         return 4

#     together = []
#     count = 0
#     found_idx = row.index(1)
#     across = 1
#     down = 1
#     for row_idx, row in enumerate(land):
#         for i, val in enumerate(row):
#             print("ROW", row_idx, "I=", i, "VAL=", val)
#             if i == len(land[0]) - 1:
#                 print(row_idx, i, "HI")
#                 together.append([row_idx, found_idx, across])
#                 across = 1
#                 break
#             if val == 0:
#                 print(row_idx, i, "BYE")
#                 together.append([row_idx, found_idx, across])
#                 try:
#                     found_idx = row.index(1, found_idx + across + 1)
#                     across = 1
#                 except:
#                     break
#                 across = 1
#                 continue
#             across += 1
#         down += 1
#     print(together)
#         # if row[found + 1] == 1:
#         #     across += 1
#     # print(land)
#     # rows = len(land)
#     # columns = len(land[0])
