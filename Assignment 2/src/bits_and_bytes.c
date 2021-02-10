#include <stdio.h>

void print_it() {
  // TODO
  printf("Bit operations are fun!\n");
}

void print_int() {
  // TODO
  int x = 10;
  int y = 13;
  printf("x = %d\n", x);
  printf("y = %d\n", y);
  printf("size of signed int in bytes is %d.\n", sizeof(x));
  printf("size of signed int in bits is %d.\n", 8*sizeof(x));
  printf("%d + %d = %d.\n", x, y, x+y);
}

void print_float() {
  // TODO
  float x = 10;
  float y = 13;
  printf("x = %.6f\n", x);
  printf("y = %.6f\n", y);
  printf("size of single float in bytes is %d.\n", sizeof(x));
  printf("size of single float in bits is %d.\n", 8*sizeof(x));
  printf("%.6f + %.6f = %.6f.\n", x, y, (x+y));
  printf("%.6f + %.6f = %d.\n", x, y, (int)(x+y));
}

void print_char() {
  // TODO
  char c = 'C';
  char a = 65;
  char a2 = 'A';
  char f = 'F';
  char e = 'E';
  char b = 'B';

  printf("c = %c\n", c);
  printf("a = %c\n", a);
  printf("%c%c%c%c%c%c%c%c\n", c, a2, f, e, b, a2, b, e);
  printf("number of bytes: %d.\n", 9*sizeof(c));
}

void packing_bytes() {
  unsigned char b3 = 202; //CA 11001010
  unsigned char b2 = 254; //FE 11111110
  unsigned char b1 = 186; //BA 10111010
  unsigned char b0 = 190; //BE 10111110

  unsigned int u = b3;
  u = u<<8 | b2;
  u = u<<8 | b1;
  u = u<<8 | b0;

  printf("%X\n", u);

}

void unpacking_bytes() {
  // TODO
  unsigned int i1 = 1835098984u;
  unsigned int i2 = 1768842611u;

  unsigned char c4 = i1>>0;
  unsigned char c3 = i1>>8;
  unsigned char c2 = i1>>16;
  unsigned char c1 = i1>>24;
  unsigned char c8 = i2>>0;
  unsigned char c7 = i2>>8;
  unsigned char c6 = i2>>16;
  unsigned char c5 = i2>>24;

  printf("%c%c%c%c%c%c%c%c\n", c1, c2, c3, c4, c5, c6, c7, c8);
}

void print_bits() {
  // TODO
  unsigned char c1 = 181;
  for(int i = 7; i >= 0; i--) {
    printf("%d", (c1>>i)%2);
  }
  signed char c2 = -75;
  printf("\n");

  for(int i = 7; i >= 0; i--) {
    printf("%d", ((c2>>i)%2)*-1);
  }
  printf("\n");

}

void extracting_fields() {
  // TODO
  unsigned int i1 = 0xCAFEBABE;

  unsigned char c1 = i1>>29;
  i1 = i1<<3;
  unsigned char c2 = i1>>28;
  i1 = i1<<4;
  unsigned char c3 = i1>>28;
  i1 = i1<<4;
  unsigned char c4 = i1>>29;
  i1 = i1<<3;
  unsigned char c5 = i1>>29;
  i1 = i1<<3;
  unsigned char c6 = i1>>28;
  i1 = i1<<4;
  unsigned char c7 = i1>>28;
  i1 = i1<<4;
  unsigned char c8 = i1>>29;
  i1 = i1<<3;
  unsigned char c9 = i1>>30;
  i1 = i1<<2;
  unsigned char c10 = i1>>30;

  printf("%d %d %d %d %d %d %d %d %d %d\n", c1, c2, c3, c4, c5, c6, c7, c8, c9, c10);
}

void updating_fields() {
  // TODO
  unsigned int num = 17512807u;
  unsigned int num1 = 8u;
  unsigned int num2 = 17u;

  unsigned int leftside = num >>15;
  num = num <<21;
  num = num >>21;
  unsigned int rightside = num;

  unsigned int newnum = leftside;
  newnum = newnum << 5 | num2;
  newnum = newnum << 10 | rightside;


  unsigned int leftside2 = newnum >>22;
  newnum = newnum <<14;
  newnum = newnum >>14;

  unsigned int rightside2 = newnum;


  unsigned int newnum2 = leftside2;
  newnum2 = newnum2 << 4 | num1;
  newnum2 = newnum2 << 18 | rightside2;

  printf("%08X\n", newnum2);

}
