#!/usr/bin/env python3

def genNums(ult = 0, nums = [], rem = 6):
    if rem == 0:
        print(nums, sum(nums))
        return
    for x in [0, 4, 7]:
        if x < ult:
            continue
        genNums(x, nums + [x], rem - 1)
