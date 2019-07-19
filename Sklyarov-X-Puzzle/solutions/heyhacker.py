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
	result = None
	print("not work")
	return result


def invert_or_hexes(h1, h2):
	result = None
	print("not work")
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
			res += str(r) + " "

		elif ind % 3 == 1:
			r = invert_or_hexes(shex, '0x3')
			res += str(r) + " "

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

if __name__ == "__main__":
	p = "Hey Hacker!"
	r = "zgH↕K@Qk@@#"

	todo = "fkHA#HA#@Gc@[c j/@G{H^g"

	phex = str2hex(p)
	rhex = str2hex(r)
	print(phex)
	print(rhex)
	xored = xor(phex, rhex, din_format='hex')
	print("--- xor result ---")
	print(xored)

	crypted = crypt(p)
	print("--- crypt result ---")
	print(crypted)
	print("--- crypt --> str result ---")
	crypt_str = hex2str(crypted)
	print(crypt_str)
	# 1. xor 0x32 - 0x32 - 0x32
	# 2. xor 0x2 - 0x3 - 0x0
	# 3. xor 0x31 - 0x21 - 0x25

	# ---------------
	# decrypt todo
	# ---------------
	decrypted = decrypt(todo)
	print("--- crypt result ---")
	print(crypted)
	print("--- crypt --> str result ---")
	crypt_str = hex2str(crypted)
	print(crypt_str)
