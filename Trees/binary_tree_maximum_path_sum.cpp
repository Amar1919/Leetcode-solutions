// Problem: Binary Tree Maximum Path Sum

// Approach: Recursively calculate the maximum path sum that can be extended
// from each node to its parent. At each node, calculate left + right + node->val
// as a complete path through the node and update maxi. Return only
// max(left, right) + node->val because a parent can extend through only one side.

// Time Complexity: O(n) | Space Complexity: O(h)