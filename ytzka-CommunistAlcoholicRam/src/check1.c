#include <inttypes.h>
#include <stdint.h>
#include <stdlib.h>

#include <stdio.h>

uint64_t read();
void write(uint64_t);

int int_sum_i7(int i1, int i2, int i3, int i4, int i5, int i6, int i7, int i8) {
  return i1 - i2 + i3 - i4 + i5 - i6 + i7 - i8 + 0xdeadbeef;
}

int logical(int x, int y) {
  uint64_t *arr = (uint64_t *)malloc((x + y) * sizeof(uint64_t));
  for (int i = 0; i < x + y; i++) {
    arr[i] = i;
  }
  int index = 0;
  long sum = 0;
  while (index < x + y) {
    int tmp = arr[index];
    tmp *= tmp;
    sum += tmp;
    index++;
  }
  for (int i = x + y - 1; i >= 0; i--) {
    sum -= arr[i];
    sum -= arr[i];
  }
  int z = x + y;
  switch (z) {
  case 1:
    sum += 1;
    break;
  case 2:
    sum += 2;
    break;
  case 3:
    sum += 3;
    break;
  case 4:
    sum += 4;
    break;
  default:
    sum += z;
    break;
  }
  return sum < 0 ? sum : 0;
}

int gotoscript() {
  int x1, x2, cont;
goto1:
  x1 = read();
  x2 = read();
goto2:
  if (x1 > x2)
    x1 -= x2;
  else if (x1 < x2)
    x2 -= x1;
  else
    goto goto3;
  goto goto2;
goto3:
  cont = read();
  if (cont) {
    write(x1);
    goto goto1;
  } else
    goto goto4;
goto4:
  return x1;
}

int irrelevant(int a, int b) {
  int z1 = logical(a, a);
  int z2 = logical(a, b);
  int z3 = logical(b, a);
  int z4 = logical(b, b);
  int z5 = z1 + z2 + z3 + z4;
  int flag = 0;
  if (z5 != z1) {
    if (z5 != z2) {
      if (z5 != z3) {
        if (z5 != z4) {
          flag = 1;
          int nores1 = int_sum_i7(a, 2, a, a, b, b, 0, b);
        }
        int nores2 = int_sum_i7(a, a, b, 0, a, 5, b, b);
      }
      int nores3 = int_sum_i7(a, b, 2, b, 0, b, a, b);
    }
    int nores4 = int_sum_i7(a, a, a, 3, b, b, 9, b);
  }
  if (flag) {
    return logical(logical(logical(z1, z2), z3), z4);
  } else
    return 0xdeadbeef;
}

int longblock() {
  uint64_t *arr = (uint64_t *)malloc(50 * sizeof(uint64_t));
  uint64_t *proparr = (uint64_t *)malloc(50 * sizeof(uint64_t));
  arr[0] = 7;   // alabama
  arr[1] = 6;   // alaska
  arr[2] = 7;   // arizona
  arr[3] = 8;   // arkansas
  arr[4] = 10;  // california
  arr[5] = 8;   // colorado
  arr[6] = 11;  // connecticut
  arr[7] = 8;   // delaware
  arr[8] = 7;   // florida
  arr[9] = 7;   // georgia
  arr[10] = 6;  // hawaii
  arr[11] = 5;  // idaho
  arr[12] = 8;  // illinois
  arr[13] = 7;  // indiana
  arr[14] = 4;  // iowa
  arr[15] = 6;  // kansas
  arr[16] = 8;  // kentucky
  arr[17] = 9;  // louisiana
  arr[18] = 5;  // maine
  arr[19] = 8;  // maryland
  arr[20] = 13; // massachusetts
  arr[21] = 8;  // michigan
  arr[22] = 9;  // minnesota
  arr[23] = 11; // mississippi
  arr[24] = 8;  // missouri
  arr[25] = 7;  // montana
  arr[26] = 8;  // nebraska
  arr[27] = 6;  // nevada
  arr[28] = 13; // new hampshire
  arr[29] = 10; // new jersey
  arr[30] = 10; // new mexico
  arr[31] = 8;  // new york
  arr[32] = 14; // north carolina
  arr[33] = 12; // north dakota
  arr[34] = 4;  // ohio
  arr[35] = 8;  // oklahoma
  arr[36] = 6;  // oregon
  arr[37] = 12; // pennsylvania
  arr[38] = 12; // rhode island
  arr[39] = 14; // south carolina
  arr[40] = 12; // south dakota
  arr[41] = 9;  // tennessee
  arr[42] = 5;  // texas
  arr[43] = 4;  // utah
  arr[44] = 7;  // vermont
  arr[45] = 8;  // virginia
  arr[46] = 10; // washington
  arr[47] = 13; // west virginia
  arr[48] = 9;  // wisconsin
  arr[49] = 7;  // wyoming
  proparr[0] = arr[0] + arr[1];
  proparr[1] = arr[1] + arr[2];
  proparr[2] = arr[2] + arr[3];
  proparr[3] = arr[3] + arr[4];
  proparr[4] = arr[4] + arr[5];
  proparr[5] = arr[5] + arr[6];
  proparr[6] = arr[6] + arr[7];
  proparr[7] = arr[7] + arr[8];
  proparr[8] = arr[8] + arr[9];
  proparr[9] = arr[9] + arr[10];
  proparr[10] = arr[10] + arr[11];
  proparr[11] = arr[11] + arr[12];
  proparr[12] = arr[12] + arr[13];
  proparr[13] = arr[13] + arr[14];
  proparr[14] = arr[14] + arr[15];
  proparr[15] = arr[15] + arr[16];
  proparr[16] = arr[16] + arr[17];
  proparr[17] = arr[17] + arr[18];
  proparr[18] = arr[18] + arr[19];
  proparr[19] = arr[19] + arr[20];
  proparr[20] = arr[20] + arr[21];
  proparr[21] = arr[21] + arr[22];
  proparr[22] = arr[22] + arr[23];
  proparr[23] = arr[23] + arr[24];
  proparr[24] = arr[24] + arr[25];
  proparr[25] = arr[25] + arr[26];
  proparr[26] = arr[26] + arr[27];
  proparr[27] = arr[27] + arr[28];
  proparr[28] = arr[28] + arr[29];
  proparr[29] = arr[29] + arr[30];
  proparr[30] = arr[30] + arr[31];
  proparr[31] = arr[31] + arr[32];
  proparr[32] = arr[32] + arr[33];
  proparr[33] = arr[33] + arr[34];
  proparr[34] = arr[34] + arr[35];
  proparr[35] = arr[35] + arr[36];
  proparr[36] = arr[36] + arr[37];
  proparr[37] = arr[37] + arr[38];
  proparr[38] = arr[38] + arr[39];
  proparr[39] = arr[39] + arr[40];
  proparr[40] = arr[40] + arr[41];
  proparr[41] = arr[41] + arr[42];
  proparr[42] = arr[42] + arr[43];
  proparr[43] = arr[43] + arr[44];
  proparr[44] = arr[44] + arr[45];
  proparr[45] = arr[45] + arr[46];
  proparr[46] = arr[46] + arr[47];
  proparr[47] = arr[47] + arr[48];
  proparr[48] = arr[48] + arr[49];
  proparr[49] = arr[49] + arr[0];
  int sum = 0;
  sum += proparr[0];
  sum += proparr[1];
  sum += proparr[2];
  sum += proparr[3];
  sum += proparr[4];
  sum += proparr[5];
  sum += proparr[6];
  sum += proparr[7];
  sum += proparr[8];
  sum += proparr[9];
  sum += proparr[10];
  sum += proparr[11];
  sum += proparr[12];
  sum += proparr[13];
  sum += proparr[14];
  sum += proparr[15];
  sum += proparr[16];
  sum += proparr[17];
  sum += proparr[18];
  sum += proparr[19];
  sum += proparr[20];
  sum += proparr[21];
  sum += proparr[22];
  sum += proparr[23];
  sum += proparr[24];
  sum += proparr[25];
  sum += proparr[26];
  sum += proparr[27];
  sum += proparr[28];
  sum += proparr[29];
  sum += proparr[30];
  sum += proparr[31];
  sum += proparr[32];
  sum += proparr[32];
  sum += proparr[33];
  sum += proparr[34];
  sum += proparr[35];
  sum += proparr[36];
  sum += proparr[37];
  sum += proparr[38];
  sum += proparr[39];
  sum += proparr[40];
  sum += proparr[41];
  sum += proparr[42];
  sum += proparr[43];
  sum += proparr[44];
  sum += proparr[45];
  sum += proparr[46];
  sum += proparr[47];
  sum += proparr[48];
  sum += proparr[49];
  return sum / 2;
}

void matmul(uint64_t *mat, int n) {
  uint64_t *resmat = (uint64_t *)malloc(25 * sizeof(uint64_t));
  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 5; j++) {
      resmat[i * 5 + j] = (i == j ? 1 : 0);
    }
  }
  for (int t = 0; t < n; t++) {
    for (int i = 0; i < 5; i++) {
      for (int j = 0; j < 5; j++) {
        int tmp = 0;
        for (int k = 0; k < 5; k++) {
          tmp += resmat[i * 5 + k] * resmat[k * 5 + j];
        }
        resmat[i * 5 + j] = tmp;
      }
    }
  }
  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 5; j++) {
      mat[i * 5 + j] = resmat[i * 5 + j];
    }
  }
}

int main() {
  write(gotoscript());
  int irrel1 = read();
  int irrel2 = read();
  write(irrelevant(irrel1, irrel2));
  write(longblock());

  uint64_t *mat = (uint64_t *)malloc(25 * sizeof(uint64_t));
  for (int i = 0; i < 25; i++) {
    mat[i] = read();
  }
  matmul(mat, 2);
  for (int i = 0; i < 25; i++) {
    write(mat[i]);
  }
  return 0;
}

uint64_t read() {
  uint64_t x;
  scanf("%llu", &x);
  return x;
}

void write(uint64_t x) {
  printf("%llu\n", x);
  return;
}