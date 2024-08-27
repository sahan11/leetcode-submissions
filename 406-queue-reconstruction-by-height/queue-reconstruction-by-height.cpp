/*example: people = {[4,4], [5,2], [5,0], [6,1], [7,1], [7,0]} (n=length of people=6) after sorting
vector v = {1, 1, 1, 1, 1, 1}, where every v[i]=1 is counting the i-th spot in people
=> construct segmentree: 
sgTree.tree = {INT_MIN, 6, 3, 3, 2, 1, 2, 1, 1, 1, INT_MIN, INT_MIN, 1, 1, ... }
                 
                 (6|[0,5])
            /                \
        (3|[0,2])           (3|[3,5])
        /      \             /      \
    (2|[0,1])  (1|[2])   (2|[3,4])  (1|[5])
    /       \              /     \
 (1|[0])    (1|[1])    (1|[3])  (1|[4])
           
tree[x]'s are arranged in level order traversal with tree[1] being the root node of sgTree.
In the diagram, every node (tree[x]|[left,right]) is represented by 
-> tree[x] : counting number of available leaf nodes in the range [left, right]
-> [left, right] : the range in [0, n-1] represented by the node at index x
for example, x=1 corresponds to range [0, 5]. tree[1]=6 counts the number of spots in [0,5]
(**[left] means [left, left] in order to specify that it is a leaf node)

Suppose that the resulting queue is q = {?, ?, ?, ?, ?, ?} for the moment.
-----------------------------------------------------------------------------------------------
(i=0, people[0] = [h[0],k[0]] = [4,4])
k[0]=4 => we put [4,4] to the 5th available spot of q (index=4)
=> q = {?, ?, ?, ?, [4,4], ?}
Then, we update sgTree by putting "v[4]=0". 
The leaf node at (1|[4]) turns to (0|[4]), and then we update its parent (and higher parents). 

                 (5|[0,5])
            /                \
        (3|[0,2])           (2|[3,5])
        /      \             /      \
    (2|[0,1])  (1|[2])   (1|[3,4])  (1|[5])
    /       \              /     \
 (1|[0])    (1|[1])    (1|[3])  (0|[4])
 
 -----------------------------------------------------------------------------------------------
 (i=1, people[1] = [5,2])
 k[1]=2 => we put [5,2] to the 3rd available spot of q (index=2)
 => q = {?, ?, [5,2], ?, [4,4], ?} and sgTree becomes 
 
                 (4|[0,5])
            /                \
        (2|[0,2])           (2|[3,5])
        /      \             /      \
    (2|[0,1])  (0|[2])   (1|[3,4])  (1|[5])
    /       \              /     \
 (1|[0])    (1|[1])    (1|[3])  (0|[4])
 
 -----------------------------------------------------------------------------------------------
 (i=2, people[2] = [5,0])
 k[2]=0 => we put [5,0] to the first available spot of q (index=0)
 => q = {[5,0], ?, [5,2], ?, [4,4], ?} and sgTree becomes
 
                 (3|[0,5])
            /                \
        (1|[0,2])           (2|[3,5])
        /      \             /      \
    (1|[0,1])  (0|[2])   (1|[3,4])  (1|[5])
    /       \              /     \
 (0|[0])    (1|[1])    (1|[3])  (0|[4])
 
 -----------------------------------------------------------------------------------------------
 (i=3, people[3] = [6,1])
 k[3]=1 => we put [6,1] to the 2nd available spot (k=2) of q.
 To find the corresponding index in q, we search from the root node (3|[0,5]).
                 (3|[0,5])
                /          \
        (1|[0,2])           (2|[3,5])
 The left child (x=2) of node(x=1) has only 1 spot left, 
 so we have to pass to the right child (x=3) of node(x=1) and reduce k by tree[2]=1
 
 =>          (2|[3,5])
             /        \
         (1|[3,4])  (1|[3,5])
 again we pass to the node(x=4), i.e. (1|[3,4]), and jump to the leaf node (1|[3])
 => index=3 and hence q = {[5,0], ?, [5,2], [6,1], [4,4], ?}. sgTree becomes
 
                 (2|[0,5])
            /                \
        (1|[0,2])           (1|[3,5])
        /      \             /      \
    (1|[0,1])  (0|[2])   (0|[3,4])  (1|[5])
    /       \              /     \
 (0|[0])    (1|[1])    (0|[3])  (0|[4])
 
 -----------------------------------------------------------------------------------------------
 (i=4, people[4] = [7,1])
 k[4]=1 => we put [7,1] to the 2nd available spot (k=2) of q.
 in the same manner, we traverse along (2|[0,5])->(1|[3,5])->(1|[5])
 so index = 5 and q = {[5,0], ?, [5,2], [6,1], [4,4], [7,1]}. sgTree becomes
 
                  (1|[0,5])
            /                \
        (1|[0,2])           (0|[3,5])
        /      \             /      \
    (1|[0,1])  (0|[2])   (0|[3,4])  (0|[5])
    /       \              /     \
 (0|[0])    (1|[1])    (0|[3])  (0|[4])
 
 -----------------------------------------------------------------------------------------------
 (i=5, people[5]=[7,0])
 the final element of people will be put to the spot of index=1 in the same manner.
 therefore,
 q = {[5,0], [7,0], [5,2], [6,1], [4,4], [7,1]}.
 
*/
struct segmentTree{
    std::vector<int> tree;
    int N;
    int length;
    
    segmentTree(std::vector<int>& v){
        N = v.size();
        length = 4*N;
        tree.resize(length, INT_MIN);
        build(v, 1, 0, N-1);
    }
    
    void build(std::vector<int>& v, int x, int left, int right){
        if (left==right){
            tree[x] = v[left];
            return;
        }
        int mid = (left+right)/2;
        build(v, 2*x, left, mid);
        build(v, 2*x+1, mid+1, right);
        tree[x] = tree[2*x] + tree[2*x+1];
        return;
    }
    
    //update tree if v[index]=value
    void update(int x, int left, int right, int index, int value){
        if (left==right){
            tree[x] = value;
            return;
        }
        int mid = (left+right)/2;
        if (index>mid){
            update(2*x+1, mid+1, right, index, value);
        }else{
            update(2*x, left, mid, index, value);
        }
        tree[x] = tree[2*x] + tree[2*x+1];
        return;
    }
    
    //find the k-th available leaf node
    int find(int x, int left, int right, int k){
        if (left==right){
            return left;
        }
        
        int mid = (left+right)/2;
        if (k<=tree[2*x]){
            return find(2*x, left, mid, k);
        }else{
            return find(2*x+1, mid+1, right, k-tree[2*x]);
        }
    }    
};

class Solution {
public:
    static bool myCompare(std::vector<int>& u, std::vector<int>& v){
        if (u[0]<v[0]) return true;
        if (u[0]>v[0]) return false;
        
        if (u[1]>v[1]) return true;
        return false;
    }
    
    void printQ(std::vector<std::vector<int>>& q){
        for (int i=0; i<q.size(); i++)
            std::cout<<"("<<q[i][0]<<","<<q[i][1]<<"), ";
        std::cout<<std::endl;
    }
    
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        int n = people.size();
        std::sort(people.begin(), people.end(), myCompare);
        std::vector<std::vector<int>> result(n, std::vector<int>{0,0});

        std::vector<int> v(n, 1);
        segmentTree sgTree = segmentTree(v); 
        int index;
        
        for (int i=0; i<n; i++){
            index = sgTree.find(1, 0, n-1, people[i][1]+1);    
            result[index][0] = people[i][0];
            result[index][1] = people[i][1];
            //update sgTree
            sgTree.update(1, 0, n-1, index, 0);
        }
        
        return result;
    }
};

