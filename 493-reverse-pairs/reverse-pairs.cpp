class Solution {
public:

    void merge(vector<int>& a,int low, int mid, int high){
        vector<int> temp;
        int left = low;
        int right = mid+1;

        while(left<=mid && right<=high){
            if(a[left] <= a[right]){
                temp.push_back(a[left]);
                left++;
            }
            else{
                temp.push_back(a[right]);
                right++;
            }
        }

        while(left<=mid){
            temp.push_back(a[left]);
            left++;
        }
        while(right<=high){
            temp.push_back(a[right]);
            right++;
        }

        for(int i = low ; i<=high ; i++){
            a[i]=temp[i-low];
        }
    }

    int countPairs(vector<int>& a,int low, int mid, int high){
        int right = mid+1;
        int cnt=0;
        for(int i =low;i <= mid ; i++){
            while(right <= high && static_cast<long long>(a[i]) > 2LL * a[right]) right++;
            cnt += (right-(mid+1));
        }
        return cnt;
    }

    int mergeSort(vector<int>& a,int low, int high){
        int cnt =0;
        if(low>=high) return cnt;
        int mid = (low+high)/2;
        cnt+=mergeSort(a,low,mid);
        cnt+=mergeSort(a,mid+1,high);
        cnt+=countPairs(a,low,mid,high);
        merge(a,low,mid,high);
        return cnt;
    }

    int reversePairs(vector<int>& nums) {
        int n = nums.size();
        return mergeSort(nums,0,n-1);
    }
};