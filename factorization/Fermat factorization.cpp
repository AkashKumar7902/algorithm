/*
        Given number n can be represented by p*q;
        so, n = p*q
        
        a = 1/2(p + q) and b = 1/2(q - p)
        
        so calculating the values of p and q from above 2 expressions, we get, 
        
        p = a - b       and       q = a + b
        
        so , n = (a + b)(a - b)
             n = a^2 - b^2
             a^2 = n + b^2
             a = sqrt(n + b^2)
             
             now, we will try to make a perfect square by putting b = 1 and so on.
             
*/

int fermat(int n) {
    int a = ceil(sqrt(n));
    int b2 = a*a - n;
    int b = round(sqrt(b2));
    while (b * b != b2) {
        a = a + 1;
        b2 = a*a - n;
        b = round(sqrt(b2));
    }
    return a - b;
}
