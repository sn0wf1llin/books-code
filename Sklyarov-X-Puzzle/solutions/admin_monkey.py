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


def str2dec(s, delim=" "):
	return "".join(str(ord(i)) + delim for i in s)


def str2bin(s, delim=" "):
	return hex2bin("".join(str2hex(s, delim)))


def hex2bin(hex_string, threshold=8, delim=" "):
	hexes = hex_string.strip().split(" ")
	bins = ""

	for i in hexes:
		h = int(i, 16)
		b = bin(h)[2:]
		if len(b) < threshold:
			b = "0" * (threshold - len(b)) + b

		bins += b + delim
	return bins


def bin2str(bin_string, threshold=8, delim=""):
	res = ""
	if len(bin_string) % threshold != 0:
		bin_string = "0" * (threshold - len(bin_string) % threshold) + bin_string

	for i in range(int(len(bin_string) / threshold)):
		binc = bin_string[threshold * i:i * threshold + threshold]
		decc = int("{}".format(binc), 2)
		res += chr(decc) + delim

	return res


def bin2hex(bin_string, threshold=8, delim=""):
	res = ""
	if len(bin_string) % threshold != 0:
		bin_string = "0" * (threshold - len(bin_string) % threshold) + bin_string

	for i in range(int(len(bin_string) / threshold)):
		binc = bin_string[i:i+threshold]
		decc = int("{}".format(binc), 2)
		res += str(hex(decc)) + delim

	return res


def decrypt(data, key):
	hexS = str2hex(data)
	binhexS = hex2bin(hexS)
	res = xor(binhexS, key)

	return bin2str(res)


def decrypt_file(fname, key):
	text = ""
	with open(fname, 'r') as f:
		for line in f.readlines():
			text += line
	print(decrypt(text, key))


def print_list(l):
	for i in l:
		zeros, ones = 0, 0
		for j in i:
			if j == '0':
				zeros += 1
			elif j == '1':
				ones += 1
		print("{}; 0 count = {}, 1 count = {}".format(i, zeros, ones))


if __name__ == "__main__":
	passwords = ["w&G4kP%jC", "9JM>u*1HQ", "+Bir3Zs8#", "A@=f[Lut5", "E8Kp&2{ny"]

	passwords_hex = [str2hex(i) for i in passwords]
	passwords_bin = [str2bin(i, delim=" ") for i in passwords]
	passwords_dec = [str2dec(i, delim=" ") for i in passwords]

	print_list(passwords_hex)
	print_list(passwords_bin)
	print_list(passwords_dec)