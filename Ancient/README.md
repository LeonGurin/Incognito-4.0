# Ancient

**100 points**

*Given:* [challenge.png]()

___

The first step was get the image to work because it was corrupt.

Because the file was of the `png` extension and it had chunks like `iHDR` I dived into a hex editor to fix the header and I replaced the first bytes with `89 50 4E 47 0D` and it loaded.

Weird symbols showed up and you know what that means? another obscure cipher with pictures.

I tried searching "ancient" in `decode.Fr` but got nothing, then I decided to reverse image search in google to see if it notices the symbols until I got a blog with a writeup for this cipher.

I was a monk number system which was explained pretty well in here: (https://omniglot.com/language/numbers/cistercian-numbers.htm)[https://omniglot.com/language/numbers/cistercian-numbers.htm].

Deciphering the numbers one by one got me the following:

```
105 99 116 102 123 48 108 100 95 109 48 110 107 95 49 57 48 100 101 49 99 51 125
```

Using a conversion to ascii gets us the flag:

> ictf{0ld_m0nk_190de1c3}


