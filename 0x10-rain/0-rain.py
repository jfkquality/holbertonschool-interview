#!/usr/bin/python3
""" 0x10. Rain """


def rain(walls):
    """ 0. Rain """
    if not walls or len(walls) <= 2:
        return 0

    water = 0
    last_hi = 0
    peaks = {}
    for i, current in enumerate(walls[1:-1], start=1):
        prev = walls[i - 1]
        nxt = walls[i + 1]

        if prev <= current:
            if last_hi < current:
                last_hi = current
        elif prev <= nxt:
            water += prev - current
            if last_hi < nxt:
                last_hi = nxt
        else:
            if last_hi < prev:
                last_hi = prev
            water += nxt - current
    return water
