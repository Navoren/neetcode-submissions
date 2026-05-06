class Solution {
public:
    int reverse(int n) {

    const int MIN = -2147483648; // -2^31
    const int MAX = 2147483647;  // 2^31 - 1
    
    int rev = 0;
    while(n != 0) {

        int digit = n % 10;
        n /= 10;

        if(rev > MAX/10 || (rev == MAX / 10 && digit > MAX%10)) return 0;
        if(rev < MIN/10 || (rev == MIN / 10 && digit < MIN%10)) return 0;

        rev = (rev*10) + digit;
    }

    return rev;
}
};
