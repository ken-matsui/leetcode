impl Solution {
    pub fn add_binary(a: String, b: String) -> String {
        let mut i = 0u32;

        let mut a_decimal = 0u128;
        for av in a.chars().rev() {
            if av == '1' {
                a_decimal += av.to_digit(10).unwrap() as u128 * 2u128.pow(i);
            }
            i += 1;
        }

        let mut b_decimal = 0u128;
        i = 0u32;
        for bv in b.chars().rev() {
            if bv == '1' {
                b_decimal += bv.to_digit(10).unwrap() as u128 * 2u128.pow(i);
            }
            i += 1;
        }

        format!("{:b}", a_decimal + b_decimal)
    }
}