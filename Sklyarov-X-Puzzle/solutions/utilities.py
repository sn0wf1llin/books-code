import sys

def xor(s1, s2, verbose=False):
	res = ""

	if len(s1) != len(s2):
		if len(s1) < len(s2):
			s2 = s2[:len(s1)]
		else:
			s2 = s2 * (int(len(s1) / len(s2)) + 1)
			s2 = s2[:len(s1)]

	if  verbose:
		print(s1)
		print(s2)
		print("-------------------------------------")

	for i, j in zip(s1, s2):
		if i == j:
			res += "0"
		else:
			res += "1"
	if  verbose:
		print(res)
		print("\n len s1 = {}, len s2 = {}, len res = {}".format(len(s1), len(s2), len(res)))

	return res


def char2hex(c):
	return hex(ord(c))


def str2hex(s, delim=" "):
	return "".join(str(char2hex(i)) + delim for i in s)


def str2bin(s, delim=" "):
	return hex2bin("".join(str(char2hex(i)) + " " for i in s), delim=" ")


def hex2bin(hex_string, threshold=16, delim=""):
	hexes = hex_string.strip().split(" ")
	bins = ""

	for i in hexes:
		h = int(i, 16)
		b = bin(h)[2:]
		if len(b) < threshold:
			b = "0" * (threshold - len(b)) + b

		bins += b + delim
	return bins


def bin2str(bin_string, threshold=16, delim=""):
	res = ""
	if len(bin_string) % threshold != 0:
		bin_string = "0" * (threshold - len(bin_string) % threshold) + bin_string

	for i in range(int(len(bin_string) / threshold)):
		binc = bin_string[threshold * i:i * threshold + threshold]
		decc = int("{}".format(binc), 2)
		res += chr(decc) + delim

	return res


def bin2hex(bin_string, threshold=16, delim=""):
	res = ""
	if len(bin_string) % threshold != 0:
		bin_string = "0" * (threshold - len(bin_string) % threshold) + bin_string

	for i in range(int(len(bin_string) / threshold)):
		binc = bin_string[i:i+threshold]
		decc = int("{}".format(binc), 2)
		res += str(hex(decc)) + delim

	return res
