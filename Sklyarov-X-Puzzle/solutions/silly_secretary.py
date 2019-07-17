import string


def encode_phrase(phrase, letters_dict):
	new_phrase = ""
	for i in range(len(phrase)):
		try:
			new_phrase += letters_dict[phrase[i].lower()]
		except Exception as e:
			new_phrase += phrase[i]
	return new_phrase


def exchange_letters(l1, l2, letd):
	l1k = letd[l1]
	l2k = letd[l2]
	letd[l1] = l2k
	letd[l2] = l1k

	return letd


def main():
	with open("silly_secretary.txt", 'r') as f:
		phrase = f.readline()
	letters = {k: k for k in string.ascii_lowercase}

	exchange_letters('u', 't', letters)
	exchange_letters('k', 'h', letters)
	exchange_letters('d', 'e', letters)
	exchange_letters('o', 's', letters)
	exchange_letters('v', 'i', letters)
	exchange_letters('r', 'n', letters)
	exchange_letters('f', 'a', letters)
	exchange_letters('z', 'l', letters)
	exchange_letters('p', 'g', letters)
	exchange_letters('c', 'm', letters)

	new_phrase = encode_phrase(phrase, letters)
	print(new_phrase)

if __name__ == "__main__":
	main()
