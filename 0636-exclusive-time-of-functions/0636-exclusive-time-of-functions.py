class Solution:
    def exclusiveTime(self, n: int, logs: List[str]) -> List[int]:
        result = [0] * n
        stack = []
        prev_time = 0
        
        for log in logs:
            fn_id, action, timestamp = log.split(":")
            fn_id, timestamp = int(fn_id), int(timestamp)
            
            if action == "start":
                if stack:
                    result[stack[-1]] += timestamp - prev_time
                stack.append(fn_id)
                prev_time = timestamp
            else:
                result[stack.pop()] += timestamp - prev_time + 1
                prev_time = timestamp + 1

        return result