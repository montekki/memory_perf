#include <sys/types.h>

#ifndef N
#define     N   1000
#endif /* N */

#define     SM  (CLS / sizeof(double))

double mul1[N][N], mul2[N][N], res[N][N], tmp[N][N];

int main(void)
{
    double *rmul2, *rres, *rmul1;
    size_t i, i2, j, j2, k, k2;

    for (i = 0; i < N; i += SM)
        for (j = 0; j < N; j += SM)
            for (k = 0; k < N; k += SM)
                for (i2 = 0, rres = &res[i][j],
                        rmul1 = &mul1[i][k]; i2 < SM;
                        ++i2, rres += N, rmul1 += N)
                    for (k2 = 0, rmul2 = &mul2[k][j];
                            k2 < SM; ++k2, rmul2 += N)
                        for (j2 = 0; j2 < SM; ++j2)
                            rres[j2] += rmul1[k2] * rmul2[j2];

    return 0;
}
