#include <stdio.h>

long long L, T, va, vb, n, t[2], i, ti, w, d;

int main() {
    scanf("%lld %lld %lld %lld %lld", &L, &T, &va, &vb, &n);
    while(n--)
        scanf("%lld %*lld %lld", &i, &d), t[i-1] += d;
    printf("%lld", (va*(T-t[0]) + vb*(T-t[1]))/L);
}