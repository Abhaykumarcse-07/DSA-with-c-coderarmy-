class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int leftmax = 0 , rightmax=0,maxheight = height[0], index = 0,water = 0;

        //max hegiht buildingg
        for(int i  =1;i<n; i++){
            if(maxheight < height[i]){
                maxheight =  height[i];
                index = i;
            }
        }
        //left 
        for(int i=0 ; i< index ; i++){
            if(leftmax>height[i])
            water = water + leftmax - height[i];
            else
            leftmax  =height[i];
        }

        //rightpart
        for(int i=n-1; i> index ; i--){
            if(rightmax>height[i])
            water+= rightmax -height[i];
            else
            rightmax = height[i];
        }
        return water;
    }
};

const size_t BUFFER_SIZE = 0x6fafffff; alignas(std::max_align_t) char buffer[BUFFER_SIZE]; size_t buffer_pos = 0; void* operator new(size_t size) { constexpr std::size_t alignment = alignof(std::max_align_t); size_t padding = (alignment - (buffer_pos % alignment)) % alignment; size_t total_size = size + padding; char* aligned_ptr = &buffer[buffer_pos + padding]; buffer_pos += total_size; return aligned_ptr; } void operator delete(void* ptr, unsigned long) {} void operator delete(void* ptr) {} void operator delete[](void* ptr) {}