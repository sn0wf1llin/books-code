
# x = -1
# y = -1
#
# HACKER +
# HACKER +
# HACKER
# --------
# ENERGY
#
# 3 * 321 = 3*300+3*20+3*1
# 3 * hacker = 3*h*100000+3*a*10000 + 3*c*1000+3*k*100+3*e*10+3*r = EnErgy
# = e*100000+n*10000+e*1000+r*100+g*10+y
# 3*h*100000+3*a*10000 + 3*c*1000+3*k*100+3*r -n*10000-r*100-g*10-y=e*100000+e*1000-3*e*10

# E = 3*H
# K > 3
# R < 10
# 3 * x = y
import itertools


def check_energy(args):
    # EnErgy
    h, a, c, k, r, n, g, y, e = args
    wordhacker = sum([Ssum(h, 1), Ssum(a, 2), Ssum(c, 3), Ssum(k, 4), Ssum(e, 5), Ssum(r, 6)])
    wordenergy = sum([Ssum(e, 1), Ssum(n, 2), Ssum(e, 3), Ssum(r, 4), Ssum(g, 5), Ssum(y, 6)])
    if wordhacker + wordhacker + wordhacker == wordenergy:
        # print(f"{wordhacker} + {wordhacker} + {wordhacker} == {wordenergy}")
        return True

    return False

def Ssum(value, pos, max_pos=6):
    return value * 10 ** (max_pos - pos)

def check_d(comb):
    h, a, c, k, r, n, g, y, e = comb
    if (3*h*100000+3*a*10000 + 3*c*1000+3*k*100+3*r -n*10000-r*100-g*10-y ==e*100000+e*1000-3*e*10):
        return True#check_energy([h, a, c, k, r, n, g, y, e])
    return False

def tuple2int(hacker_digits):
# hacker_digits = [1, 2, 3, 4, 5, 6]
    hacker_value = 0
    for ind, d in enumerate(hacker_digits):
        hacker_value += Ssum(d, ind + 1)

    return hacker_value

ALL_DIGITS = [0, 1, 2, 3, 4, 5, 6, 7, 8, 9]
all_possible_combinations_count = 0
for comb in itertools.product(ALL_DIGITS, repeat=9):
    if comb[0] == 0:
        continue

    # comb = tuple2int(comb)

    if check_d(comb):
        all_possible_combinations_count += 1
        # print("found: {}".format(comb))

# real	13m8,556s
# user	13m8,458s
# sys	0m0,058s
