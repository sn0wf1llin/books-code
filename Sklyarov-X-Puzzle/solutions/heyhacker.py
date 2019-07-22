from utilities import *


def or_hexes(h1, h2):
	result = hex(int(h1, 16) | int(h2, 16))
	return result


def and_hexes(h1, h2):
	result = hex(int(h1, 16) & int(h2, 16))
	return result


def xor_hexes(h1, h2):
	result = hex(int(h1, 16) ^ int(h2, 16))
	return result


def invert_and_hexes(h1, h2):
	result = '-'
	return result


def guess_or(h1):
	print("---\n", chr(int(h1, 16)))
	vars = "\t : "
	variants = ['00', '01', '10', '11']
	for pos_var in variants:
		_ = bin(int(h1, 16))
		_ = _[2:-2]
		_ = hex(int(_ + pos_var , 2))
		vars += chr(int(_, 16)) + " "
	print(vars)
	result = '-'
	return result


def decrypt(p):
	res = ""
	for ind, s in enumerate(p):
		shex = char2hex(s)

		if ind % 3 == 0:
			r = xor_hexes(shex, '0x32')
			res += str(r) + " "

		elif ind % 3 == 2:
			r = invert_and_hexes(shex, '0xc8')
			res += r + " "

		elif ind % 3 == 1:
			r = guess_or(shex)
			res += r + " "

	return res


def crypt(p):
	res = ""
	for ind, s in enumerate(p):
		shex = char2hex(s)

		if ind % 3 == 0:
			r = xor_hexes(shex, '0x32')
			res += str(r) + " "

		elif ind % 3 == 2:
			r = and_hexes(shex, '0xc8')
			res += str(r) + " "

		elif ind % 3 == 1:
			r = or_hexes(shex, '0x3')
			res += str(r) + " "

	return res


def hex2str_unknown(hexs):
	res = ""
	for i in hexs.split(" "):
		if len(i) > 0:
			if i != '-':
				res += chr(int(i, 16))
			else:
				res += "-"
	return res


if __name__ == "__main__":
	p = "Hey Hacker!"
	r = "zgH↕K@Qk@@#"

	todo = "fkHA#HA#@Gc@[c j/@G{H^g"

	# phex = str2hex(p)
	# rhex = str2hex(r)
	# print(phex)
	# print(rhex)
	# xored = xor(phex, rhex, din_format='hex')
	# print("--- xor result ---")
	# print(xored)
	#
	# crypted = crypt(p)
	# print("--- crypt result ---")
	# print(crypted)
	# print("--- crypt --> str result ---")
	# crypt_str = hex2str(crypted)
	# print(crypt_str)
	# 1. xor 0x32 - 0x32 - 0x32
	# 2. xor 0x2 - 0x3 - 0x0
	# 3. xor 0x31 - 0x21 - 0x25

	# ---------------
	# decrypt todo
	# ---------------
	print(todo)
	decrypted = decrypt(todo)
	print("--- decrypt result ---")
	print(decrypted)
	print("--- decrypt --> str result ---")
	decrypt_str = hex2str_unknown(decrypted)
	print(decrypt_str)
