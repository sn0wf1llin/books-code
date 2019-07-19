import sys

def xor(s1, s2, din_format='bin', verbose=False):
	res = ""

	if din_format == 'bin':
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

	elif din_format == 'hex':
		s1_hexlist = s1.split(" ")
		s2_hexlist = s2.split(" ")

		for h1, h2 in zip(s1_hexlist, s2_hexlist):
			if len(h1) > 0 and len(h2) > 0:
				result = hex(int(h1, 16) ^ int(h2, 16))
				res += str(result) + " "
		return res

	else:
		print('error: {} not found'.format(din_format))
		return None


def char2hex(c):
	if ord(c) == 8597:
		return (hex(18))
	return hex(ord(c))


def str2hex(s):
	return "".join(char2hex(i) + " " for i in s)


def str2bin(s, threshold=16):
	return hex2bin("".join(char2hex(i) + " " for i in s), threshold=threshold)


def hex2str(hexs):
	res = ""
	for i in hexs.split(" "):
		if len(i) > 0:
			res += chr(int(i, 16))

	return res


def hex2bin(hex_string, threshold=16):
	hexes = hex_string.strip().split(" ")
	bins = ""

	for i in hexes:
		h = int(i, 16)
		b = bin(h)[2:]
		if len(b) < threshold:
			b = "0" * (threshold - len(b)) + b

		bins += b
	return bins


def bin2str(bin_string, threshold=16):
	res = ""
	if " " not in bin_string:
		if len(bin_string) % threshold != 0:
			bin_string = "0" * (threshold - len(bin_string) % threshold) + bin_string
	else:
		bin_string = "".join(i for i in bin_string.split(" "))

	for i in range(int(len(bin_string) / threshold)):
		binc = bin_string[threshold * i:i * threshold + threshold]
		decc = int("{}".format(binc), 2)
		res += chr(decc) + delim

	return res


def bin2hex(bin_string, threshold=16):
	res = ""
	if len(bin_string) % threshold != 0:
		bin_string = "0" * (threshold - len(bin_string) % threshold) + bin_string

	for i in range(int(len(bin_string) / threshold)):
		binc = bin_string[i:i+threshold]
		decc = int("{}".format(binc), 2)
		if decc != 0 :
			res += str(hex(decc)) + " "

	return res

def print_with_delim(bins, threshold=16):
	if len(bins) % threshold != 0:
		print("WARNING: len(str) = {}, threshold = {}".format(len(bins), threshold))
		bins = '0' * ((1 + int(len(bins) / threshold )) * threshold - len(bins)) + bins

	res = ""
	for i in range(int(len(bins) / threshold) + 1):
		res += bins[i * threshold:i * threshold + threshold]

	print(res)

	return res
