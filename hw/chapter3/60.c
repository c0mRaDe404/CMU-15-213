long loop(long x, int n) {
    long result = 0;    
    long mask;
    for (mask = 1; mask; mask <<= n) {
        result |= x & mask;
    }
    return result;
}
