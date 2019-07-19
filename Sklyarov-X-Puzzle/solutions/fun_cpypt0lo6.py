from utilities import *


def main():
    xormask = "\x08\x18\x3c\x3e\x44\x32\x03\x52\x27\x47\x01\x06\x4d"
    hexxormask = "0x08 0x18 0x3c 0x3e 0x44 0x32 0x03 0x52 0x27 0x47 0x01 0x06 0x4d"
    data = "passwdpasswd"
    # print(xormask)
    data_s = str2bin(data, threshold=16)
    data_s = "".join(i for i in data_s.split(" "))
    mask_s = hex2bin(hexxormask, threshold=16, delim=" ")
    mask_s = "".join(i for i in mask_s.split(" "))
    print(data_s)
    print(mask_s)
    xor_res = xor(data_s, mask_s)
    print(xor_res)
    b = binstr2bins(xor_res)
    print(b)
    unxored = bin2str(b, threshold=16, delim="")
    print(unxored)
    # only DES possible left ...
    # john the ripper <-- :{unxored}
    # jtr <-- file <-- :xyOM3Vs3T4vb

if __name__ == "__main__":
    main()
