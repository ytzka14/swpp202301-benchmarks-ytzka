#include <inttypes.h>
#include <stdlib.h>

#define INF 0x7fffffff

uint64_t read();
void write(uint64_t);

extern int *Idx;

void ReNewPlus(int Now) {
  if (Idx[2 * Now] > Idx[2 * Now + 1])
    Idx[2 * Now + 1] = Idx[2 * Now];
}

void ReNewMinus(int Now) {
  if (Idx[2 * Now] > Idx[2 * Now + 1])
    Idx[2 * Now] = Idx[2 * Now + 1];
}

void Spray(int Now) {
  if (Idx[4 * Now] < Idx[2 * Now])
    Idx[4 * Now] = Idx[2 * Now];
  ReNewPlus(2 * Now);
  if (Idx[4 * Now + 1] > Idx[2 * Now + 1])
    Idx[4 * Now + 1] = Idx[2 * Now + 1];
  ReNewMinus(2 * Now);
  if (Idx[4 * Now + 2] < Idx[2 * Now])
    Idx[4 * Now + 2] = Idx[2 * Now];
  ReNewPlus(2 * Now + 1);
  if (Idx[4 * Now + 3] > Idx[2 * Now + 1])
    Idx[4 * Now + 3] = Idx[2 * Now + 1];
  ReNewMinus(2 * Now + 1);
  Idx[2 * Now] = 0;
  Idx[2 * Now + 1] = INF;
}

void IdxPlus(int Left, int Right, int Now, int LeftBound, int RightBound,
             int Height) {
  int Mid;

  if (LeftBound <= Left && Right <= RightBound) {
    if (Idx[2 * Now] < Height)
      Idx[2 * Now] = Height;
    ReNewPlus(Now);
  } else {
    Spray(Now);
    Mid = (Left + Right) / 2;
    if (LeftBound <= Mid)
      IdxPlus(Left, Mid, 2 * Now, LeftBound, RightBound, Height);
    if (Mid + 1 <= RightBound)
      IdxPlus(Mid + 1, Right, 2 * Now + 1, LeftBound, RightBound, Height);
  }
}

void IdxMinus(int Left, int Right, int Now, int LeftBound, int RightBound,
              int Height) {
  int Mid;

  if (LeftBound <= Left && Right <= RightBound) {
    if (Idx[2 * Now + 1] > Height)
      Idx[2 * Now + 1] = Height;
    ReNewMinus(Now);
  } else {
    Spray(Now);
    Mid = (Left + Right) / 2;
    if (LeftBound <= Mid)
      IdxMinus(Left, Mid, 2 * Now, LeftBound, RightBound, Height);
    if (Mid + 1 <= RightBound)
      IdxMinus(Mid + 1, Right, 2 * Now + 1, LeftBound, RightBound, Height);
  }
}

void *malloc_upto_8(uint64_t x) { return malloc((x + 7) / 8 * 8); }

void buildWall(int n, int k, int op[], int left[], int right[], int height[],
               int finalHeight[]) {
  int i, m;

  for (m = 1; m < n; m *= 2)
    ;
  Idx = (int *)malloc_upto_8(4 * sizeof(int) * m);
  for (i = 2; i < 2 * m; i++)
    Idx[2 * i + 1] = INF;
  for (i = 0; i < k; i++) {
    if (op[i] == 1)
      IdxPlus(0, m - 1, 1, left[i], right[i], height[i]);
    else
      IdxMinus(0, m - 1, 1, left[i], right[i], height[i]);
  }
  for (i = 1; i < m; i++)
    Spray(i);
  for (i = m; i < m + n; i++)
    finalHeight[i - m] = Idx[2 * i];
}

int main() {
  int n;
  int k;

  int i, j;
  int status = 0;

  n = read();
  k = read();

  int *op = (int *)malloc_upto_8(sizeof(int) * k);
  int *left = (int *)malloc_upto_8(sizeof(int) * k);
  int *right = (int *)malloc_upto_8(sizeof(int) * k);
  int *height = (int *)malloc_upto_8(sizeof(int) * k);
  int *finalHeight = (int *)malloc_upto_8(sizeof(int) * n);

  for (i = 0; i < k; i++) {
    op[i] = read();
    left[i] = read();
    right[i] = read();
    height[i] = read();
  }

  buildWall(n, k, op, left, right, height, finalHeight);

  for (j = 0; j < n; j++)
    write(finalHeight[j]);

  return 0;
}
