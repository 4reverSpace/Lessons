import random


def to_text(text): # Перевод двумерного массив из бит в текст
    out = ''
    char = 0
    for i in range(len(text)):
        for j in range(7):
            char += 2 ** (6 - j) * text[i][j]
        out = out + chr(char)
        char = 0
    return out


def create_key(): # Создание псевдослучайного ключа
    return ''.join(str(random.randint(0, 1)) for i in range(64))


def xor(text, key): # Функция ксора каждого бита еста с каждым битом ключа
    output = ''
    for i in range(len(text) * 7):
        for j in range(len(key)):
            text[i // 7][i % 7] = text[i // 7][i % 7] ^ key[j] 
    return text


def do_that_thing(key): #  вот эта функция , которая изменяет ключ
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


class message: # решил сделать класс ( зашифорванное сообщение , ключ и дешифорванное - параметры класса ) 

    def __init__(self, text1, text2, key):
        self.dec_text = text1
        self.enc_text = text2
        self.key = do_that_thing(list(map(int, list(str(key)))))

    def decrypt(self):  ## могут возникнуть служебные символы, поэтому декодированный текст всегда в чистых битах(поправочка , по 7 бит, askii коды всех стандартных символов умещаются  ) 
        temp=[]
        for i in range(len(self.enc_text)//7):
            temp.append([int(self.enc_text[i*7+j]) for j in range(7)]) 
        self.dec_text = to_text(xor(temp, self.key))

    def encrypt(self): #функция шифорвки 
        message = []
        for i in self.dec_text:
            message.append(list((map(int, list(format(ord(i), '07b'))))))
        temp = xor(message, self.key)
        for i in temp:
            self.enc_text = self.enc_text + ''.join(map(str,i))
# Примеры работы:
#Дешифрованное сообщение :test
#Ключ:
# Шифорванное сообщение:1110100110010111100111110100

# Шифорванное сообещние:1110100110010111100111110100
# Ключ:1101000110001110001110110111011110101000111001110000010100010010
# Дешифорванное сообщение :test
