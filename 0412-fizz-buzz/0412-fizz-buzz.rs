impl Solution {
    pub fn fizz_buzz(n: i32) -> Vec<String> {
        let mut v: Vec<String> = Vec::new();

        for i in 1..n + 1 {
            let divisible_by_three: bool = i % 3 == 0;
            let divisible_by_five: bool = i % 5 == 0;

            if (divisible_by_three && divisible_by_five) {
                v.push(String::from("FizzBuzz"));
            } else if (divisible_by_three) {
                v.push(String::from("Fizz"));
            } else if (divisible_by_five) {
                v.push(String::from("Buzz"));
            } else {
                v.push(i.to_string());
            }
        }

        v
    }
}
