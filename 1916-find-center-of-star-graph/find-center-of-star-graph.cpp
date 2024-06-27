class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        int node1 = edges[0][0];
        int node2 = edges[0][1];
        int node3 = edges[1][0];
        int node4 = edges[1][1];

        if(node1 == node3) return node1;
        if(node1 == node4) return node1;
        if(node2 == node3) return node2;
        if(node2 == node4) return node4;
        return -1;
    }
};