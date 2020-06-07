def wordPattern(pattern: str, str: str) -> bool:
    words = str.split(" ")
    if len(pattern) != len(words):
        return False
    
    dict = {}
    for i in range(len(pattern)):
        if pattern[i] not in dict:
            if words[i] not in dict.values():
                dict[pattern[i]] = words[i]
            else:
                return False
        elif dict[pattern[i]] != words[i]:
            return False
    return True
    
print(wordPattern("abba", "dog cat cat dog"))