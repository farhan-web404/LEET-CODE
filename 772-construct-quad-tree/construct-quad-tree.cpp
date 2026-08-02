/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/

class Solution {
public:
    Node* build(vector<vector<int>>& grid, int x, int y, int n) {
        bool same = true;
        int val = grid[x][y];

        for (int i = x; i < x + n; i++) {
            for (int j = y; j < y + n; j++) {
                if (grid[i][j] != val) {
                    same = false;
                    break;
                }
            }
            if (!same) break;
        }

        if (same)
            return new Node(val, true);

        int m = n / 2;

        return new Node(
            true,
            false,
            build(grid, x, y, m),
            build(grid, x, y + m, m),
            build(grid, x + m, y, m),
            build(grid, x + m, y + m, m)
        );
    }

    Node* construct(vector<vector<int>>& grid) {
        return build(grid, 0, 0, grid.size());
    }
};