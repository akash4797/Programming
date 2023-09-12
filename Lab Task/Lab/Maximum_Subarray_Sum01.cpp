#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long maxSubarraySum(vector<int>& nums) {
    int n = nums.size();
    long long maxEndingHere = nums[0];
    long long maxSoFar = nums[0];

    for (int i = 1; i < n; ++i) {
        maxEndingHere = max((long long)nums[i], maxEndingHere + nums[i]);
        maxSoFar = max(maxSoFar, maxEndingHere);
    }

    return maxSoFar;
}

int main() {
    int n;
    cin >> n;

    vector<int> nums(n);
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }

    long long result = maxSubarraySum(nums);
    cout << result << endl;

    return 0;
}
