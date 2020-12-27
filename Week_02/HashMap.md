HashMap

C++中使用unordered\_map实现，hash\_map约等于unordered\_map
https://www.jianshu.com/p/56bb01df8ac7

最初的 C++ 标准库中没有类似 hash\_map 的实现，但不同实现者自己提供了非标准的 hash\_map。 
因为这些实现不是遵循标准编写的，所以它们在功能和性能保证方面都有细微差别。

从 C++ 11 开始，hash\_map 实现已被添加到标准库中。但为了防止与已开发的代码存在冲突，决定使用替代名称 unordered\_map。
这个名字其实更具描述性，因为它暗示了该类元素的无序性。


对于统计有限字符的集合时，发现使用自制hash效率更高

其中一种制作hash的方式, 需要考虑避免哈希碰撞
int hash(string s) {
  if (!s.size()) return 0;
  int ans = 0;
  for (char i: s) {
    ans = ans + 5*i*i*i/26 + i*1009 - i*i*997;
  }
  return ans;
}


leetcode经典题型:
Anagram (49, 242)
TwoSum (1)





