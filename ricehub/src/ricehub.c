#include <inttypes.h>
#include <stdlib.h>

#define ABS(x) ((x) >= 0 ? (x) : -(x))

uint64_t read();
void write(uint64_t);

extern int R, L, *X;
extern int64_t B;

int besthub() {
  int i, j, left = 1, mid, right = R, x, ans;
  int64_t hab;
  uint8_t ok;

  while (left <= right) {
    mid = (left + right) / 2;
    x = (mid - 1) / 2;
    hab = ok = 0;
    for (i = 0; i < mid; i++)
      hab += ABS(X[x] - X[i]);
    if (hab <= B)
      ok = 1;
    for (i = 1; i <= R - mid; i++) {
      j = i + mid - 1;
      if (mid % 2)
        hab -= X[x++] - X[i - 1];
      else
        hab -= X[++x] - X[i - 1];
      hab += X[j] - X[x];
      if (hab <= B)
        ok = 1;
    }
    if (ok) {
      left = mid + 1;
      ans = mid;
    } else {
      right = mid - 1;
    }
  }
  return ans;
}

void *malloc_upto_8(uint64_t x) { return malloc((x + 7) / 8 * 8); }

static void read_input() {
  int i;

  R = read();
  L = read();
  B = read();
  X = (int *)malloc_upto_8(sizeof(int) * R);
  for (i = 0; i < R; i++)
    X[i] = read();
}

int main() {
  int ans;

  read_input();
  ans = besthub();
  write(ans);

  return 0;
}
