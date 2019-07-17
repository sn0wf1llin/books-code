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
	return hex2bin("".join(str(char2hex(i)) + delim for i in s))


def hex2bin(hex_string, threshold=8, delim=""):
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


if __name__ == "__main__":
	# KEY = "00111110001001000011000100111000"
	# hex2bin()
	# s1 = "0110001101110010011001010110000101110100011101010111001001100101010111110110001101110010011001010110000101110100011101010111001001100101010111110110001101110010011001010110000101110100011101010111001001100101"
	# s2 = "0101110101010110010101000101100101001010010100010100001101011101011000010100011101000011010111010101111101010000010001000100101001011011011110110101001001001010010110110100010101000101010011010100110001000001"
	# print(xor(s1, s2))
	# S = "Vers"
	# S = "creature_creature_creature"
	# POSSIBLE_KEY = str2bin("The Conscience of a Hacker")
	# print(POSSIBLE_KEY)
	# decrypt_file("../Sklyarov-X-Puzzle-CD/PART I/Chapter1/1.2/The Conscience of a Hacker.txt", key=POSSIBLE_KEY)
	NEW_KEY = str2bin("1981")
	print(NEW_KEY)
	decrypt_file("../Sklyarov-X-Puzzle-CD/PART I/Chapter1/1.2/The Conscience of a Hacker.txt", key=NEW_KEY)