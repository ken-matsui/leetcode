impl Solution {
    pub fn create_target_array(nums: Vec<i32>, index: Vec<i32>) -> Vec<i32> {
        let mut v: Vec<i32> = Vec::new();
        for i in 0..index.len() {
            v.insert(index[i] as usize, nums[i]);
        }
        v
    }
}
