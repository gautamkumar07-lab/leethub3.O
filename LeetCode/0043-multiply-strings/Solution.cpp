class Solution {
public:
    string multiply(string num1, string num2) {

        // If any number is 0, answer is 0
        if (num1 == "0" || num2 == "0")
            return "0";

        int n = num1.size();
        int m = num2.size();

        // Result array can have at most n + m digits
        vector<int> result(n + m, 0);

        // Multiply each digit from right to left
        for (int i = n - 1; i >= 0; i--) {

            for (int j = m - 1; j >= 0; j--) {

                // Convert char to integer digit
                int digit1 = num1[i] - '0';
                int digit2 = num2[j] - '0';

                // Current multiplication
                int product = digit1 * digit2;

                // Positions in result array
                int p1 = i + j;
                int p2 = i + j + 1;

                // Add existing value
                int sum = product + result[p2];

                // Store carry and remainder
                result[p1] += sum / 10;
                result[p2] = sum % 10;
            }
        }

        string ans = "";

        // Skip leading zeros
        for (int num : result) {

            if (!(ans.empty() && num == 0))
                ans += to_string(num);
        }

        return ans;
    }
};