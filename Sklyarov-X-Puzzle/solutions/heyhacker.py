from utilities import *


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
	p = "Hey Hacker!"
	r = "zgH↕K@Qk@@#"
	bhex = str2hex(p)
	rhex = str2hex(r)
	pbin = str2bin(p)
	rbin = str2bin(r)
	print(bhex)
	print(rhex)
	print(pbin)
	print(rbin)
