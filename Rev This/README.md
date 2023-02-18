# Rev This

**864 points**

*Given:* [RevThis]()

___

I first ran the program to see what it outputs or what to look for, nothing.

To see the under the hood functions that are called I used `ltrace` on the file and it gave the following output:

[output.txt]()

Ok, still nothing of note.

I decided to use `IDA` to decompile the code to understand what it calls on a higher level.

```c
unsigned int v4; // [rsp+8h] [rbp-88h]
  int i; // [rsp+Ch] [rbp-84h]
  int j; // [rsp+10h] [rbp-80h]
  char v7[9]; // [rsp+17h] [rbp-79h]
  __int64 v8[6]; // [rsp+20h] [rbp-70h] BYREF
  __int64 v9[8]; // [rsp+50h] [rbp-40h] BYREF

  v9[7] = __readfsqword(0x28u);
  v4 = 0;
  memset(v8, 0, 34);
  *(__int64 *)((char *)&v8[4] + 2) = 0x100000000000000LL;
  memset(v9, 0, 34);
  *(__int64 *)((char *)&v9[4] + 2) = 0x100000000000000LL;
  rand_str(v8, 41LL);
  rand_str(v9, 41LL);
  for ( i = 0; i <= 40; ++i )
    v7[i] = *((_BYTE *)v9 + i) ^ *((_BYTE *)v8 + i);
  for ( j = 0; j <= 40; ++j )
    v4 += v7[j] - 4 * j;
  message(v4);
```

Ok so let's start explaining, the code gets 2 random strings `v8,v9` with `rand_str` and then calculated a value `v4` with 2 loops that `xor` the strings `v8,v9` and performs a subtraction of the result with `v4 += v7[j] - 4 * j;`.

The `message` function then `xors` this magic value with values of an integer array `v3`.

I wanted to reverse the process to see how we get all the relevant strings and the magic value of `v4` to perform the same operations in `message`.

The output of `ltrace` returns `THE SAME VALUES EVERY-TIME` even though the `rand_str` function used the `rand()` function.

That means we can get `v8,v9` by running `rand_str` with the values we have:

```c
int main() {
  long long arr[40];
  char s1[41];
  char s2[41];
  //v8
  {
    arr[0] = 0x6b8b4567;
    arr[1] = 0x327b23c6;
    arr[2] = 0x643c9869;
    arr[3] = 0x66334873;
    arr[4] = 0x74b0dc51;
    arr[5] = 0x19495cff;
    arr[6] = 0x2ae8944a;
    arr[7] = 0x625558ec;
    arr[8] = 0x238e1f29;
    arr[9] = 0x46e87ccd;
    arr[10] = 0x3d1b58ba;
    arr[11] = 0x507ed7ab;
    arr[12] = 0x2eb141f2;
    arr[13] = 0x41b71efb;
    arr[14] = 0x79e2a9e3;
    arr[15] = 0x7545e146;
    arr[16] = 0x515f007c;
    arr[17] = 0x5bd062c2;
    arr[18] = 0x12200854;
    arr[19] = 0x4db127f8;
    arr[20] = 0x216231b;
    arr[21] = 0x1f16e9e8;
    arr[22] = 0x1190cde7;
    arr[23] = 0x66ef438d;
    arr[24] = 0x140e0f76;
    arr[25] = 0x3352255a;
    arr[26] = 0x109cf92e;
    arr[27] = 0xded7263;
    arr[28] = 0x7fdcc233;
    arr[29] = 0x1befd79f;
    arr[30] = 0x41a7c4c9;
    arr[31] = 0x6b68079a;
    arr[32] = 0x4e6afb66;
    arr[33] = 0x25e45d32;
    arr[34] = 0x519b500d;
    arr[35] = 0x431bd7b7;
    arr[36] = 0x3f2dba31;
    arr[37] = 0x7c83e458;
    arr[38] = 0x257130a3;
    arr[39] = 0x62bbd95a;
    arr[40] = 0x436c6125;
    rand_str(arr, s1);
  }
  
  //v9
  {
    arr[0] = 0x628c895d;
    arr[1] = 0x333ab105;
    arr[2] = 0x721da317;
    arr[3] = 0x2443a858;
    arr[4] = 0x2d1d5ae9;
    arr[5] = 0x6763845e;
    arr[6] = 0x75a2a8d4;
    arr[7] = 0x8edbdab;
    arr[8] = 0x79838cb2;
    arr[9] = 0x4353d0cd;
    arr[10] = 0xb03e0c6;
    arr[11] = 0x189a769b;
    arr[12] = 0x54e49eb4;
    arr[13] = 0x71f32454;
    arr[14] = 0x2ca88611;
    arr[15] = 0x836c40e;
    arr[16] = 0x2901d82;
    arr[17] = 0x3a95f874;
    arr[18] = 0x8138641;
    arr[19] = 0x1e7ff521;
    arr[20] = 0x7c3dbd3d;
    arr[21] = 0x737b8ddc;
    arr[22] = 0x6ceaf087;
    arr[23] = 0x22221a70;
    arr[24] = 0x4516dde9;
    arr[25] = 0x3006c83e;
    arr[26] = 0x614fd4a1;
    arr[27] = 0x419ac241;
    arr[28] = 0x5577f8e1;
    arr[29] = 0x440badfc;
    arr[30] = 0x5072367;
    arr[31] = 0x3804823e;
    arr[32] = 0x77465f01;
    arr[33] = 0x7724c67e;
    arr[34] = 0x5c482a97;
    arr[35] = 0x2463b9ea;
    arr[36] = 0x5e884adc;
    arr[37] = 0x51ead36b;
    arr[38] = 0x2d517796;
    arr[39] = 0x580bd78f;
    arr[40] = 0x153ea438;
    rand_str(arr, s2);
  }

  printf("\ns1: %s\n", s1);
  printf("\ns2: %s\n", s2);
}
```

The I rewrote the function `rand_str` like so:

```c
void rand_str(long long* arr, char* s){
  char v9[63];
  strcpy(v9, "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ");

  int i = 40;
  int j = 0;
  while ( i-- )
  {
    int v2 = 62.0 * ((double)arr[j] / 2147483647.0);
    int v8;
    if ( v2 >= 9.223372036854776e18 )
      v8 = (unsigned int)(int)(v2 - 9.223372036854776e18) ^ 0x8000000000000000LL;
    else
      v8 = (unsigned int)(int)v2;
    s[j++] = v9[v8];
  }
}
```

The only difference is the value of `rand()` is replaced with `arr[j]`.

This code gives us the 2 strings: 

* v8: oMNUckLhytCmvXUDI8B1f8N9o86ZdvQBiDwuYiL

* v9: oThlOU4Ww5bFTl31s3eYTQgxnLvFw2rVVIhJDlG

which means we can rewrite the code in `IDA` and run it outright:

```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void rand_str(long long* arr, char* s){
  char v9[63];
  strcpy(v9, "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ");

  int i = 40;
  int j = 0;
  while ( i-- )
  {
    int v2 = 62.0 * ((double)arr[j] / 2147483647.0);
    int v8;
    if ( v2 >= 9.223372036854776e18 )
      v8 = (unsigned int)(int)(v2 - 9.223372036854776e18) ^ 0x8000000000000000LL;
    else
      v8 = (unsigned int)(int)v2;
    s[j++] = v9[v8];
  }
}

int main() {
  long long arr[40];
  char s1[41];
  char s2[41];
  //v8
  {
    arr[0] = 0x6b8b4567;
    arr[1] = 0x327b23c6;
    arr[2] = 0x643c9869;
    arr[3] = 0x66334873;
    arr[4] = 0x74b0dc51;
    arr[5] = 0x19495cff;
    arr[6] = 0x2ae8944a;
    arr[7] = 0x625558ec;
    arr[8] = 0x238e1f29;
    arr[9] = 0x46e87ccd;
    arr[10] = 0x3d1b58ba;
    arr[11] = 0x507ed7ab;
    arr[12] = 0x2eb141f2;
    arr[13] = 0x41b71efb;
    arr[14] = 0x79e2a9e3;
    arr[15] = 0x7545e146;
    arr[16] = 0x515f007c;
    arr[17] = 0x5bd062c2;
    arr[18] = 0x12200854;
    arr[19] = 0x4db127f8;
    arr[20] = 0x216231b;
    arr[21] = 0x1f16e9e8;
    arr[22] = 0x1190cde7;
    arr[23] = 0x66ef438d;
    arr[24] = 0x140e0f76;
    arr[25] = 0x3352255a;
    arr[26] = 0x109cf92e;
    arr[27] = 0xded7263;
    arr[28] = 0x7fdcc233;
    arr[29] = 0x1befd79f;
    arr[30] = 0x41a7c4c9;
    arr[31] = 0x6b68079a;
    arr[32] = 0x4e6afb66;
    arr[33] = 0x25e45d32;
    arr[34] = 0x519b500d;
    arr[35] = 0x431bd7b7;
    arr[36] = 0x3f2dba31;
    arr[37] = 0x7c83e458;
    arr[38] = 0x257130a3;
    arr[39] = 0x62bbd95a;
    arr[40] = 0x436c6125;
    rand_str(arr, s1);
  }
  
  //v9
  {
    arr[0] = 0x628c895d;
    arr[1] = 0x333ab105;
    arr[2] = 0x721da317;
    arr[3] = 0x2443a858;
    arr[4] = 0x2d1d5ae9;
    arr[5] = 0x6763845e;
    arr[6] = 0x75a2a8d4;
    arr[7] = 0x8edbdab;
    arr[8] = 0x79838cb2;
    arr[9] = 0x4353d0cd;
    arr[10] = 0xb03e0c6;
    arr[11] = 0x189a769b;
    arr[12] = 0x54e49eb4;
    arr[13] = 0x71f32454;
    arr[14] = 0x2ca88611;
    arr[15] = 0x836c40e;
    arr[16] = 0x2901d82;
    arr[17] = 0x3a95f874;
    arr[18] = 0x8138641;
    arr[19] = 0x1e7ff521;
    arr[20] = 0x7c3dbd3d;
    arr[21] = 0x737b8ddc;
    arr[22] = 0x6ceaf087;
    arr[23] = 0x22221a70;
    arr[24] = 0x4516dde9;
    arr[25] = 0x3006c83e;
    arr[26] = 0x614fd4a1;
    arr[27] = 0x419ac241;
    arr[28] = 0x5577f8e1;
    arr[29] = 0x440badfc;
    arr[30] = 0x5072367;
    arr[31] = 0x3804823e;
    arr[32] = 0x77465f01;
    arr[33] = 0x7724c67e;
    arr[34] = 0x5c482a97;
    arr[35] = 0x2463b9ea;
    arr[36] = 0x5e884adc;
    arr[37] = 0x51ead36b;
    arr[38] = 0x2d517796;
    arr[39] = 0x580bd78f;
    arr[40] = 0x153ea438;
    rand_str(arr, s2);
  }

  printf("\ns1: %s\n", s1);
  printf("\ns2: %s\n", s2);
  
  char v7[40];
  for ( int i = 0; i < 40; i++ ){
    v7[i] = s1[i] ^ s2[i];
  }
  int v4 = 0;
  for ( int i = 0; i < 40; i++ ){
    v4 += v7[i] - 4*i;
  }

  printf("%d\n", v4);

  long long v3[4];
  v3[0] = 0x6071B14091B0C06LL;
  v3[1] = 0x70806031C1C061CLL;
  v3[2] = 0xA0B1D0E0716031BLL;
  v3[3] = 0x41C0E1B190A1D1DLL;

  for(int j = 0; j < 30; j++){
    printf("%d: ", j);
    for (int i = 0; i <= 32; ++i ){
      putchar((v4 + j) ^ *((char *)v3 + i));
    }
    printf("\n");
  }

  return 0;
}
```

The only thing of note now is the reason for the loop with `j`.

For some reason the final computed value that I got for `v4` was wrong for some reason by a letter (I think), it has something to do with the values output by `ltrace` that I got which did not include the right last characters.

The final output of the code is:

```
s1: QoMNUckLhytCmvXUDI8B1f8N9o86ZdvQBiDwuYiLWy

s2: LoThlOU4Ww5bFTl31s3eYTQgxnLvFw2rVVIhJDlGd  
-1183
0: gmzhuzfg}g}}bgifzbwfo|jk||kxzo}e<
1: dnykvyed~d~~adjeyatelihh{yl~f?
2: eoxjwxdee`ekdx`udm~hi~~izxmg>
3: bhmpcbxbxxgblcgrcjyonyyn}jx`9
4: ci~lq~bcycyyfcmb~fsbkxnoxxo|~kya8
5: `j}or}a`z`zze`na}epah{ml{{l}hzb;
6: ak|ns|`a{a{{dao`|dq`izlmzzm~|i{c:
7: ndsa|sontnttkn`osk~ofucbuubqsftl5
8: oer`}rnououujoanrjngtbcttcprgum4
9: lfqc~qmlvlvvilbmqi|mdwa`ww`sqdvn7
10: mgpbplmwmwwhmclph}lev`avvarpewo6
11: j`wexwkjpjppojdkwozkbqgfqqfuwbph1
12: kavdyvjkqkqqnkejvn{jcpfgppgtvcqi0
13: hbugzuihrhrrmhfiumxi`sedssdwu`rj3
14: ictf{thisisslightlyharderrevtask2
15: v|kydkwvlvllsvxwksfw~m{zmmzik~lt-
16: w}jxejvwmwmmrwyvjrgvlz{ll{hjmu,
17: t~i{fiutntnnqtzuiqdu|oyxooxki|nv/
18: uhzghtuouoopu{thpet}nxynnyjh}ow.
19: rxo}`osrhrhhwr|sowbszi~ii~mozhp)
20: syn|anrsisiivs}rnvcr{h~hhln{iq(
21: pzmbmqpjpjjup~qmu`qxk}|kk|omxjr+
22: q{l~clpqkqkktqpltapyj|}jj}nlyks*
23: ~tcqlc~d~dd{~pc{nvesreeracvd|%
24: ubpmb~eeezq~bzo~wdrsdds`bwe}$
25: |vasna}|f|ffy|r}ayl}tgqpggpcatf~'
26: }w`ro`|}g}ggx}s|`xm|ufpqffqb`ug&
27: zpguhg{z`z``zt{gj{rawvaavegr`x!
28: {qftifz{a{aa~{uzf~kzs`vw``wdfsay
29: xrewjeyxbxbb}xvye}hypcutcctgepbz#
```

And for `j=11` we get the flag itself: 

>  ictf{thisisslightlyharderrevtask}

*Another thought about the challenge -* there is a chance it was possible to brute force the problem by guessing the value of `v4` but oh well 🤷‍♂️

