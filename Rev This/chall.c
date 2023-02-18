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
  // v4 = 18;
  for(int j = 0; j < 30; j++){
    printf("%d: ", j);
    for (int i = 0; i <= 32; ++i ){
      putchar((v4 + j) ^ *((char *)v3 + i));
    }
    printf("\n");
  }

  return 0;
}

