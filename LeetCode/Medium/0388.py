class Solution:
    # 找最长的文件路径深度，输出最长路径长度
    def lengthLongestPath(self, input: str) -> int:
        stk = []
        ans = 0
        lines = input.split("\n")
        for line in lines:
            level = 0
            for ch in line:
                if ch == '\t':
                    level += 1
                else:
                    break
            line = line[level:]
            while len(stk) > level:
                stk.pop()
            stk.append(line)
            if line.find(".") != -1:
                s = "/".join(stk)
                ans = max(len(s), ans)
        return ans
                
        