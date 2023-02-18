# Crypto1

**439 points**

*Given:* [chal.py]()

___

The script we got encrypted a flag with a weird function that does weird things based on the index of the character that is being encrypted.

But the challenge was super easy, we just needed to find for each character the correct character in the result -> that would get us the original character for each index.

It just means cycling 256 values and one of those is bout to be the right one for the encryption.

And so the script I made was:

```python
flag = "" #redacted

def func(f, i):
    if i<5:
        out = ord(f) ^ 0x76 ^ 0xAD
        var1 = (out & 0xAA) >> 1
        var2 = 2 * out & 0xAA
        return var1 | var2 
    elif i>=5 and i<10:
        out = ord(f) ^ 0x76 ^ 0xBE
        var1 = (out & 0xCC) >> 2
        var2 = 4 * out & 0xCC
        return var1 | var2
    else:
        out = ord(f) ^ 0x76 ^ 0xEF
        var1 = (out & 0xF0) >> 4
        var2 = 16 * out & 0xF0
        return var1 | var2

res = 'ÓÓ~Ô×£ö®£ö¿ÚÚª'

for letter in res:
    for i in range(0, 256):
        if func(chr(i), res.index(letter)) == ord(letter):
            flag += chr(i)
            break

print(flag)
```

The flag is:

> ictf{88f30d1cd1ab443}
