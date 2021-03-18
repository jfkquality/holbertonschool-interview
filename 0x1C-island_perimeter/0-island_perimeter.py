#!/usr/bin/python3
""" Python 3 program to find perimeter of area
#covered by 1 in 2D matrix consisits of 0's and 1's.
"""


def numofneighbors(mat, row, col, rows, cols):
    """ Find the number of covered side for mat[i][j]."""

    count = 0

    # UP
    if (row > 0 and mat[row - 1][col]):
        count += 1

    # LEFT
    if (col > 0 and mat[row][col - 1]):
        count += 1

    # DOWN
    if (row < rows - 1 and mat[row + 1][col]):
        count += 1

    # RIGHT
    if (col < cols - 1 and mat[row][col + 1]):
        count += 1

    return count


def island_perimeter(grid):
    """ Returns sum of perimeter of shapes formed with 1's. """

    perimeter = 0
    land = grid

    rows = len(land)
    cols = len(land[0])

    # Traversing the matrix and finding ones to
    # calculate their contribution.
    for row in range(0, rows):
        for col in range(0, cols):
            if (land[row][col]):
                perimeter += (4 - numofneighbors(land, row, col, rows, cols))

    return perimeter


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
