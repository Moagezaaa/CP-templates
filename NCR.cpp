ll nCr(ll n, ll r) {
    if (r > n) return 0;
    if (r == 0 || r == n) return 1;
    if (r > n - r) r = n - r;
    ll result = 1;
    for (ll i = 1; i <= r; i++) {
        result *= (n - i + 1);
        result /= i;
    }

    return result;
}