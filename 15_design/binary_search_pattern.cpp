// TEMPLATE 1:  EXACT SEARCH  --> 70% OF binary search problems
while (left <= right) {
    int mid = left + (right - left) / 2;

    if (nums[mid] == target)
        return mid;
    else if (nums[mid] < target)
        left = mid + 1;
    else
        right = mid - 1;
}

// TEMPLATE 2:  FIRST TRUE / LAST TRUE  --> 30% of binary search problems
while (left < right) {
    int mid = left + (right - left) / 2;

    if (condition(mid))
        right = mid;
    else
        left = mid + 1;
}

return left;


// A good rule of thumb is:

// Exact target? → while (left <= right)
// First/last valid answer or minimum/maximum feasible value? → while (left < right)