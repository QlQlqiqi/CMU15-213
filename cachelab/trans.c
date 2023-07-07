/*
 * trans.c - Matrix transpose B = A^T
 *
 * Each transpose function must have a prototype of the form:
 * void trans(int M, int N, int A[N][M], int B[M][N]);
 *
 * A transpose function is evaluated by counting the number of misses
 * on a 1KB direct mapped cache with a block size of 32 bytes.
 */
#include <stdio.h>
#include "cachelab.h"

int is_transpose(int M, int N, int A[N][M], int B[M][N]);

/*
 * transpose_submit - This is the solution transpose function that you
 *     will be graded on for Part B of the assignment. Do not change
 *     the description string "Transpose submission", as the driver
 *     searches for that string to identify the transpose function to
 *     be graded.
 */
char transpose_submit_desc[] = "Transpose submission";
void transpose_submit(int M, int N, int A[N][M], int B[M][N]) {
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
  if (M == 32 || M == 64) {
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

/*
 * You can define additional transpose functions below. We've defined
 * a simple one below to help you get started.
 */

/*
 * trans - A simple baseline transpose function, not optimized for the cache.
 */
char trans_desc[] = "Simple row-wise scan transpose";
void trans(int M, int N, int A[N][M], int B[M][N]) {
  int i, j, tmp;

  for (i = 0; i < N; i++) {
    for (j = 0; j < M; j++) {
      tmp = A[i][j];
      B[j][i] = tmp;
    }
  }
}

/*
 * registerFunctions - This function registers your transpose
 *     functions with the driver.  At runtime, the driver will
 *     evaluate each of the registered functions and summarize their
 *     performance. This is a handy way to experiment with different
 *     transpose strategies.
 */
void registerFunctions() {
  /* Register your solution function */
  registerTransFunction(transpose_submit, transpose_submit_desc);

  /* Register any additional transpose functions */
  // registerTransFunction(trans, trans_desc);
}

/*
 * is_transpose - This helper function checks if B is the transpose of
 *     A. You can check the correctness of your transpose by calling
 *     it before returning from the transpose function.
 */
int is_transpose(int M, int N, int A[N][M], int B[M][N]) {
  int i, j;

  for (i = 0; i < N; i++) {
    for (j = 0; j < M; ++j) {
      if (A[i][j] != B[j][i]) {
        return 0;
      }
    }
  }
  return 1;
}
