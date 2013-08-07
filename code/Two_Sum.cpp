class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        vector<pair<int,int>> a;
        a.clear();
        for (int i=0;i<numbers.size();++i) 
            a.push_back(make_pair(numbers[i],i+1));
        sort(a.begin(),a.end());
        int p2 = a.size()-1;
        for (int i=0;i<a.size();++i){
            while (p2>=0 && a[i].first+a[p2].first>target) --p2;
            if (p2>=0 && a[i].first+a[p2].first == target){
                vector<int> ans;
                ans.clear();
                ans.push_back(a[i].second);
                ans.push_back(a[p2].second);
                sort(ans.begin(),ans.end());
                return ans;
            }
        }
    }
};