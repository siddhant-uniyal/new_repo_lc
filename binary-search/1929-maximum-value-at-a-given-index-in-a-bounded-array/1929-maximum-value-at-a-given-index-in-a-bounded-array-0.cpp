using ll = long long;
class Solution {
public:
    int maxValue(int n, int index, int maxSum) {
        //  x-2  x-1 x x-1

        //  4x - 4 <= 6

        //  4x <= 10

        //  x <= 10 / 4

        //  _ _ _ _ _ _
        //  x-1  x x-1 x-2 x-3 x-4

        //  6x - 11 <= 10

        //  6x <= 21

        // 0 .. index - 1

        // index + 1 .. n - 1

        long long neg = 1LL * index * (index + 1) / 2;
        neg += 1LL * (n - 1 - index) * (n - index) / 2;

        return (neg + maxSum)/n;
    }
};