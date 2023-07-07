
#include <stdio.h>
#include <string.h>

void TransposeSubmit(int M, int N, int A[N][M], int B[M][N]) {
  int i;
  int j;
  int k;
  int v1;
  int v2;
  int v3;
  int v4;
  int v5;
  int v6;
  int v7;
  int v8;
  if (M == 32) {
    for (i = 0; i < N; i += 8) {
      for (j = 0; j < M; j += 8) {
        // 非对角线
        if (i != j) {
          for (k = i; k < i + 8; k++) {
            v1 = A[k][j];
            v2 = A[k][j + 1];
            v3 = A[k][j + 2];
            v4 = A[k][j + 3];
            v5 = A[k][j + 4];
            v6 = A[k][j + 5];
            v7 = A[k][j + 6];
            v8 = A[k][j + 7];
            B[j][k] = v1;
            B[j + 1][k] = v2;
            B[j + 2][k] = v3;
            B[j + 3][k] = v4;
            B[j + 4][k] = v5;
            B[j + 5][k] = v6;
            B[j + 6][k] = v7;
            B[j + 7][k] = v8;
          }
          continue;
        }
        // 对角线
        // 0
        k = i;
        v1 = A[k][j];
        v2 = A[k][j + 1];
        v3 = A[k][j + 2];
        v4 = A[k][j + 3];
        v5 = A[k][j + 4];
        v6 = A[k][j + 5];
        v7 = A[k][j + 6];
        v8 = A[k][j + 7];
        B[k][j] = v1;
        B[k][j + 1] = v2;
        B[k][j + 2] = v3;
        B[k][j + 3] = v4;
        B[k][j + 4] = v5;
        B[k][j + 5] = v6;
        B[k][j + 6] = v7;
        B[k][j + 7] = v8;

        // 1
        k++;
        v1 = A[k][j];
        v2 = A[k][j + 1];
        v3 = A[k][j + 2];
        v4 = A[k][j + 3];
        v5 = A[k][j + 4];
        v6 = A[k][j + 5];
        v7 = A[k][j + 6];
        v8 = A[k][j + 7];

        B[k][j + 0] = B[i + 0][j + k - i];
        B[i + 0][j + k - i] = v1;

        B[k][j + 1] = v2;
        B[k][j + 2] = v3;
        B[k][j + 3] = v4;
        B[k][j + 4] = v5;
        B[k][j + 5] = v6;
        B[k][j + 6] = v7;
        B[k][j + 7] = v8;

        // 2
        k++;
        v1 = A[k][j];
        v2 = A[k][j + 1];
        v3 = A[k][j + 2];
        v4 = A[k][j + 3];
        v5 = A[k][j + 4];
        v6 = A[k][j + 5];
        v7 = A[k][j + 6];
        v8 = A[k][j + 7];

        B[k][j + 0] = B[i + 0][j + k - i];
        B[i + 0][j + k - i] = v1;
        B[k][j + 1] = B[i + 1][j + k - i];
        B[i + 1][j + k - i] = v2;

        B[k][j + 2] = v3;
        B[k][j + 3] = v4;
        B[k][j + 4] = v5;
        B[k][j + 5] = v6;
        B[k][j + 6] = v7;
        B[k][j + 7] = v8;

        // 3
        k++;
        v1 = A[k][j];
        v2 = A[k][j + 1];
        v3 = A[k][j + 2];
        v4 = A[k][j + 3];
        v5 = A[k][j + 4];
        v6 = A[k][j + 5];
        v7 = A[k][j + 6];
        v8 = A[k][j + 7];

        B[k][j + 0] = B[i + 0][j + k - i];
        B[i + 0][j + k - i] = v1;
        B[k][j + 1] = B[i + 1][j + k - i];
        B[i + 1][j + k - i] = v2;
        B[k][j + 2] = B[i + 2][j + k - i];
        B[i + 2][j + k - i] = v3;

        B[k][j + 3] = v4;
        B[k][j + 4] = v5;
        B[k][j + 5] = v6;
        B[k][j + 6] = v7;
        B[k][j + 7] = v8;

        // 4
        k++;
        v1 = A[k][j];
        v2 = A[k][j + 1];
        v3 = A[k][j + 2];
        v4 = A[k][j + 3];
        v5 = A[k][j + 4];
        v6 = A[k][j + 5];
        v7 = A[k][j + 6];
        v8 = A[k][j + 7];

        B[k][j + 0] = B[i + 0][j + k - i];
        B[i + 0][j + k - i] = v1;
        B[k][j + 1] = B[i + 1][j + k - i];
        B[i + 1][j + k - i] = v2;
        B[k][j + 2] = B[i + 2][j + k - i];
        B[i + 2][j + k - i] = v3;
        B[k][j + 3] = B[i + 3][j + k - i];
        B[i + 3][j + k - i] = v4;

        B[k][j + 4] = v5;
        B[k][j + 5] = v6;
        B[k][j + 6] = v7;
        B[k][j + 7] = v8;

        // 5
        k++;
        v1 = A[k][j];
        v2 = A[k][j + 1];
        v3 = A[k][j + 2];
        v4 = A[k][j + 3];
        v5 = A[k][j + 4];
        v6 = A[k][j + 5];
        v7 = A[k][j + 6];
        v8 = A[k][j + 7];

        B[k][j + 0] = B[i + 0][j + k - i];
        B[i + 0][j + k - i] = v1;
        B[k][j + 1] = B[i + 1][j + k - i];
        B[i + 1][j + k - i] = v2;
        B[k][j + 2] = B[i + 2][j + k - i];
        B[i + 2][j + k - i] = v3;
        B[k][j + 3] = B[i + 3][j + k - i];
        B[i + 3][j + k - i] = v4;
        B[k][j + 4] = B[i + 4][j + k - i];
        B[i + 4][j + k - i] = v5;

        B[k][j + 5] = v6;
        B[k][j + 6] = v7;
        B[k][j + 7] = v8;

        // 6
        k++;
        v1 = A[k][j];
        v2 = A[k][j + 1];
        v3 = A[k][j + 2];
        v4 = A[k][j + 3];
        v5 = A[k][j + 4];
        v6 = A[k][j + 5];
        v7 = A[k][j + 6];
        v8 = A[k][j + 7];

        B[k][j + 0] = B[i + 0][j + k - i];
        B[i + 0][j + k - i] = v1;
        B[k][j + 1] = B[i + 1][j + k - i];
        B[i + 1][j + k - i] = v2;
        B[k][j + 2] = B[i + 2][j + k - i];
        B[i + 2][j + k - i] = v3;
        B[k][j + 3] = B[i + 3][j + k - i];
        B[i + 3][j + k - i] = v4;
        B[k][j + 4] = B[i + 4][j + k - i];
        B[i + 4][j + k - i] = v5;
        B[k][j + 5] = B[i + 5][j + k - i];
        B[i + 5][j + k - i] = v6;

        B[k][j + 6] = v7;
        B[k][j + 7] = v8;

        // 7
        k++;
        v1 = A[k][j];
        v2 = A[k][j + 1];
        v3 = A[k][j + 2];
        v4 = A[k][j + 3];
        v5 = A[k][j + 4];
        v6 = A[k][j + 5];
        v7 = A[k][j + 6];
        v8 = A[k][j + 7];

        B[k][j + 0] = B[i + 0][j + k - i];
        B[i + 0][j + k - i] = v1;
        B[k][j + 1] = B[i + 1][j + k - i];
        B[i + 1][j + k - i] = v2;
        B[k][j + 2] = B[i + 2][j + k - i];
        B[i + 2][j + k - i] = v3;
        B[k][j + 3] = B[i + 3][j + k - i];
        B[i + 3][j + k - i] = v4;
        B[k][j + 4] = B[i + 4][j + k - i];
        B[i + 4][j + k - i] = v5;
        B[k][j + 5] = B[i + 5][j + k - i];
        B[i + 5][j + k - i] = v6;
        B[k][j + 6] = B[i + 6][j + k - i];
        B[i + 6][j + k - i] = v7;

        B[k][j + 7] = v8;
      }
    }
  }
}

int IsTranspose(int M, int N, int A[N][M], int B[M][N]) {
  int i;
  int j;

  for (i = 0; i < N; i++) {
    for (j = 0; j < M; ++j) {
      if (A[i][j] != B[j][i]) {
        return 0;
      }
    }
  }
  return 1;
}

int main() {
  int a[32][32];
  int b[32][32];
  for (int i = 0; i < 32; i++) {
    for (int j = 0; j < 32; j++) {
      a[i][j] = i * 32 + j;
      b[i][j] = 0;
    }
  }
  TransposeSubmit(32, 32, a, b);
  printf("%d\n", IsTranspose(32, 32, a, b));
  return 0;
}