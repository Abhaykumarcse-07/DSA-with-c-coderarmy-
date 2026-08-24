class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int start = 0,end =0,mid, ans, n = piles.size();
        long long sum = 0;
        for(int i=0;i<n ; i++){
            sum = sum + piles[i];
            end = max(end,piles[i]);
        }
        start = sum/h;
        if(start==0){
            start =1;
        }

        while(start<=end){
            mid = start + (end-start)/2;


            int totaltime = 0;
            for(int i = 0 ; i<n ; i++){
                totaltime = totaltime + piles[i]/mid;
                if(piles[i]%mid)
                totaltime++;
            }
            if(totaltime>h){
                start = mid + 1 ;
            }
            else{
                ans = mid;
                end = mid -1;
            }
        }
        return ans;
    }
};
#pragma GCC optimize("Ofast")

#include <iostream>

static constexpr std::size_t max_align = alignof(std::max_align_t);
alignas(max_align) static unsigned char BUFFER[64 * 1024 * 1024];
static std::size_t pos = 0;

void *operator new(const std::size_t size) {
    const std::size_t padding = (max_align - (pos % max_align)) % max_align;
    pos += padding + size;
    return static_cast<void *>(&BUFFER[pos - size]);
}

void *operator new[](const std::size_t size) {
    return operator new(size);
}

void operator delete(void *) noexcept {}

void operator delete[](void *) noexcept {}

void operator delete(void *, std::size_t) noexcept {}

void operator delete[](void *, std::size_t) noexcept {}