impl Solution {
    pub fn plus_one(mut digits: Vec<i32>) -> Vec<i32> {
        let size = digits.len();
        let is_nine: bool = *digits.last().unwrap() == 9;

        if size == 1 {
            if is_nine {
                return vec![1, 0];
            } else {
                return vec![digits[0] + 1];
            }
        }

        if is_nine {
            let mut i = 0;
            for d in digits.iter_mut().rev() {
                if *d != 9 {
                    *d += 1;
                    break;
                } else {
                    *d = 0;
                    i += 1;
                }
            }
            if i == size {
                digits.insert(0, 1);
            }
        } else {
            digits[size - 1] += 1;
        }
        digits
    }
}
