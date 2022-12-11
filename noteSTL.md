# STL

比较重要的一些STL的特殊使用方式。

## 去重
`unique(__first, __last);`  
将重复值移到容器 **尾部** ，并返回第一个重复值的地址。  
======***/***/// `return the first /'s _it`
```cpp
sort(x.begin(), x.end());  
x.erase(unique(x.begin(), x.end()), x.end());
```

## 搜索
`find(__first, __last, val);`  
返回 **第一个** 等于 *val* 的地址，若未找到返回 *n.pos* 。  
`rfind(__first, __last, val);`  
返回 **最后一个** 等于 *val* 的地址，若未找到返回 *n.pos* 。  
```cpp
x.find(x.begin(), x.end(), 'v');
x.rfind(x.begin(), x.end(), 'v');
```

## 转换大小写
`transform(__first, __last, __result);`  
*::toupper* 转换为 **大写** ，*::tolower* 转换为 **小写** 。
```cpp
transform(x.begin(), x.end(), ::toupper);
transform(x.begin(), x.end(), ::tolower);
```