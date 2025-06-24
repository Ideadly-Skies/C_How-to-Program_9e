class Solution:
    def decodeString(self, s: str) -> str:
        num_stack = []
        str_stack = [] 
        num_str = ""
        char_str = "" 
         
        i = 0 
        while i < len(s):
            if s[i] != "[" and s[i] != "]":
                while s[i].isnumeric(): 
                    num_str += s[i]
                    i += 1 
                else:
                    while i < len(s): 
                        if s[i] == "[" or s[i] == "]":
                            break
                        elif s[i].isnumeric():
                            num_str += s[i]
                            break
                        else:
                            char_str += s[i]  
                            i += 1

                if num_str: 
                    num_stack.append(num_str)
                    num_str = "" 
                
                if char_str: 
                    str_stack.append(char_str)
                    char_str = "" 
            
            i += 1
        
        i, j = 0, 0
        final_str = "" 
        while i < len(num_stack) and j < len(str_stack):
            final_str += int(num_stack[i]) * str_stack[j]
            i += 1
            j += 1
        
        while j < len(str_stack):
            final_str += str_stack[j] 
            j += 1 
             
        # print("num_stack: ", num_stack)
        # print("str_stack: ", str_stack) 
        return final_str 
               
if __name__ == "__main__":
    s1 = Solution()
    print(s1.decodeString("3[a]2[bc]"))
    print(s1.decodeString("3[a2[c]]"))
    print(s1.decodeString("2[abc]3[cd]ef"))