class Solution:
    def maxTask(self, h, l):
        n = len(h)

        prev_no = 0
        prev_task = 0

        for i in range(n):
            curr_no = max(prev_no, prev_task)
            curr_task = max(
                prev_task + l[i],  
                
                prev_no + h[i]     
            )

            prev_no = curr_no
            prev_task = curr_task

        return max(prev_no, prev_task)