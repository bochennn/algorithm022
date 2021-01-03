# 学习笔记 #


## **递归 Recursion** ##
通过循环调用自身函数体来解决一系列可归纳成子问题的问题, 每次调用时总会改动一些关键变量, 直到达到边界条件时停止。

### <label style="color:grey">递归与循环的区别</label> ###
+ 都是通过控制一个或多个变量, 反复执行直到达到边界条件
+ 都是按照预先设计好的推断实现某一个值的求取
+ 递归通常是逆向思维居多. "递"和"归"不一定容易发现(比较难以理解); 而循环从开始条件到结束条件, 包括中间循环变量, 都可以表达出来(比较简洁明了)

### <label style="color:grey">Python模版</label> ###
```python
def recursion(level, param1, param2, ...):
  #recursion terminator 递归终结条件
  if level > MAX_LEVEL:
    process_result
    return

  #process logic in current level 处理当前层逻辑
  process(level, data...)
  
  #drill down 下探到下一层
  self.recursion(level + 1, param1, ...)
  
  # revert the current level status if needed 清理当前层
```

### <label style="color:grey">思维要点</label> ###
+ 避免人肉模拟递归，直接从函数本身入手
+ 找到最近最简方法， 将其拆解成可重复解决的子问题
+ 数学归纳法思维

### <label style="color:grey">例题</label> ###
+ [70. 爬楼梯](https://leetcode-cn.com/problems/climbing-stairs/)
+ [22. 括号生成](https://leetcode-cn.com/problems/generate-parentheses/)
+ [226. 翻转二叉树](https://leetcode-cn.com/problems/invert-binary-tree/description/)
+ [98. 验证二叉搜索树](https://leetcode-cn.com/problems/validate-binary-search-tree/)
+ [104. 二叉树的最大深度](https://leetcode-cn.com/problems/maximum-depth-of-binary-tree/)
+ [111. 二叉树的最小深度](https://leetcode-cn.com/problems/minimum-depth-of-binary-tree/)
+ [297. 二叉树的序列化与反序列化](https://leetcode-cn.com/problems/serialize-and-deserialize-binary-tree/)
+ [236. 二叉树的公共祖先](https://leetcode-cn.com/problems/lowest-common-ancestor-of-a-binary-tree/)
+ [105. 从前序与中序遍历序列构造二叉树](https://leetcode-cn.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/)


# #
## **分治** ##

### <label style="color:grey">Python模版</label> ###
```python
def  divide_conquer(problem, param1, param2):
  # recursion terminator
  if problem is None:
    print_result
    return
  
  # prepare data
  data = prepare_data(problem)
  subproblems = split_problem(problem, data)

  #conquer subproblems
  subresult1 = self.divide_conquer(subproblems[0], param1, ...)
  subresult2 = self.divide_conquer(subproblems[1], param1, ...)
  subresult3 = self.divide_conquer(subproblems[2], param1, ...)
  ...

  # process and generate the final result
  result = process_result(subresult1, subresult2, subresult3, ...)

  # revert the current level status
```
### <label style="color:grey">例题</label> ###
+ [50. Pow(x, n)](https://leetcode-cn.com/problems/powx-n/)
  
# #
## **回溯** ##
回溯法采用试错的思想, 它尝试分步去解决一个问题. 在分步解决问题的过程中, 当它通过尝试发现现有的分步答案不能得到有效的正确的解答的时候, 它将取消上一步甚至是上几步的计算, 再通过其它的可能的分步解答再次尝试寻找问题的答案.

回溯法通常用最简单的递归方法实现, 在反复重复上述的步骤后可能出现两种情况:
+ 找到一个可能存在的正确答案
+ 在尝试了所有可能的分步方法后宣告该问题没有答案

在最坏的情况下, 回溯法会导致一次复杂度为指数时间的计算

### <label style="color:grey">C++模版</label> ###
```c++
void backtracking(& result, & data, start, end, ...):
  // recursion terminator
  if (start == end) {
    add_result(result, data);
    return;
  }
  for (int i = start; i < end; i++) {
    // process logic in current level 处理当前层逻辑
    process(data);
    backtracking(result, data, startIndex + 1, n, ...);
    // remend 撤销当前层处理逻辑
    unprocess(data);
  }
```

### <label style="color:grey">例题</label> ###
+ [77. 组合](https://leetcode-cn.com/problems/combinations/)
+ [46. 全排列](https://leetcode-cn.com/problems/permutations/)
+ [47. 全排列 II](https://leetcode-cn.com/problems/permutations-ii/)
+ [78. 子集](https://leetcode-cn.com/problems/subsets/)

