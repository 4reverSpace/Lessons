import random

def to_bin(text):
    return ''.join(format(ord(i),'08b')for i in text)


def to_text(bin):
    out = ''
    char = 0
    for i in range(len(bin)//8):
        for j in range(8):
            char += 2 ** (7 - j) * int(bin[i*8+j])
        out = out + chr(char)
        char = 0
    return out


def create_key():
    return ''.join(str(random.randint(0, 1)) for i in range(64))


def xor(text, key):
    for i in range(len(text) * 8):
        for j in range(len(key)):
            text[i // 8][i % 8] = text[i // 8][i % 8] ^ key[j]
    return text


def do_that_thing(key):
    lfsr_1 = key[0:19]
    lfsr_2 = key[19:42]
    lfsr_3 = key[42:]
    for i in range(64):
        majority = lfsr_1[10] & lfsr_2[12] | lfsr_1[10] & lfsr_3[12] | lfsr_2[12] & lfsr_3[12]
        if (lfsr_1[0] == majority):
            lfsr_1.append(lfsr_1.pop(0) ^ lfsr_1[1] ^ lfsr_1[2] ^ lfsr_1[5])
        if (lfsr_2[0] == majority):
            lfsr_2.append(lfsr_2.pop(0) ^ lfsr_2[1])
        if (lfsr_3[0] == majority):
            lfsr_3.append(lfsr_3.pop(0) ^ lfsr_3[1] ^ lfsr_3[2] ^ lfsr_3[15])
    return lfsr_1 + lfsr_2 + lfsr_3


class message:

    def __init__(self, text1, text2, key):
        self.dec_text = text1
        self.enc_text = text2
        self.key = do_that_thing(list(map(int, list(str(key)))))

    def decrypt(self):  ## могут возникнуть служебные символы, поэтому декодированный текст всегда в чистых битах
        temp=[]
        for i in range(len(self.enc_text)//8):
            temp.append([int(self.enc_text[i*8+j]) for j in range(8)])
        temp = (xor(temp, self.key))
        self.dec_text = ''
        for i in temp:
            self.dec_text = self.dec_text + ''.join(map(str,i))

    def encrypt(self):
        message = []
        for i in range(len(self.dec_text)//8):
            message.append([int(self.dec_text[i*8+j]) for j in range(8)])
        temp = xor(message, self.key)
        self.enc_text =''
        for i in temp:
            self.enc_text = self.enc_text + ''.join(map(str,i))
