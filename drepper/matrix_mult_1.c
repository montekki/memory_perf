#include <sys/types.h>

#ifndef N
#define     N   1000
#endif /* N */

double mul1[N][N], mul2[N][N], res[N][N];

int main(void)
{
    size_t i, j, k;

    for (i = 0; i < N; ++i)
        for (j = 0; j < N; ++j)
            for (k = 0; k < N; ++k)
                res[i][j] += mul1[i][k] * mul2[k][j];

    return 0;
}
