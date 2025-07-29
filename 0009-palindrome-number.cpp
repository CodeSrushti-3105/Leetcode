class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0 || (x % 10 == 0 && x != 0)) return false;

        int original = x;
        int reverse = 0;

        while (x > 0) {
            int digit = x % 10;

           
            if (reverse > INT_MAX / 10 || (reverse == INT_MAX / 10 && digit > 7)) {
                return false;  
            }

            reverse = reverse * 10 + digit;
            x = x / 10;
        }

        return reverse == original;
    }
};
