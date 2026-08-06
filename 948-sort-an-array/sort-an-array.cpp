class Solution {
public:
    void merge(vector<int>& a,int l,int m,int r){
        vector<int> t;
        int i=l,j=m+1;
        while(i<=m&&j<=r)
            t.push_back(a[i]<a[j]?a[i++]:a[j++]);
        while(i<=m) t.push_back(a[i++]);
        while(j<=r) t.push_back(a[j++]);
        for(int k=0;k<t.size();k++) a[l+k]=t[k];
    }

    void ms(vector<int>& a,int l,int r){
        if(l>=r) return;
        int m=(l+r)/2;
        ms(a,l,m);
        ms(a,m+1,r);
        merge(a,l,m,r);
    }

    vector<int> sortArray(vector<int>& nums) {
        ms(nums,0,nums.size()-1);
        return nums;
    }
};