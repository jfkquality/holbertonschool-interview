# Python program to print all
# sublist from a given list

# function to generate all the sub lists
# def sub_lists (l):
    # base = []
    # lists = [base]
    # for i in range(len(l)):
    #     orig = lists[:]
    #     # print(orig)
    #     new = l[i]
    #     for j in range(len(lists)):
    #         lists[j] = lists[j] + [new]
    #         lists = orig + lists
    #         print(lists)

z=[[]]
a=[1,2,3,4]
for i in range(len(a)):
    for j in range(i+1,len(a)+1):
        sub=a[i:j]
        print(sub)
        z.append(sub)
        z.append([])
# print(z)

# driver code
# if __name__ == "__main__":
# l1 = [1, 2, 3]
# print(sub_lists(l1))
