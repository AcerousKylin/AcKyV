import numpy as np
import pandas as pd
import os
# 打开一个文件

# [value1, value2, value3, ...] 是一个列表，属于可变数据类型
scales = ["服务过程", "管理过程", "生产过程", "研发过程"]
results = []

# 按照scales列表里的元素对特定文件进行处理，将结果预置进results列表
for s in scales:
    
    # append()是向列表添加一个元素，而{}是一个空字典
    results.append({})
    
    # open()函数，用于文件操作，返回一个file类型的对象。
    # 语法：open(file, mode, encoding)，文件路径、打开模式和编码格式
    # 文件路径：必写，如果与代码文件同处一个文件夹中，直接写文件名即可，否则使用完整路径（灵活使用）
    # *至于文件路径的格式：./为当前路径 | ../为上一级路径（可叠加） | /为根目录
    # "../%s.txt"%s：前一个%s是格式占位符，表示这个位置会被后面%后的常量替换
    # 打开模式：可写，默认为r（只读模式），无法通过返回的对象对文件进行更改
    # 编码格式：中文的编码格式通常为utf-8
    f = open("../%s.txt" % s, encoding = "utf-8")
    
    # 读取所打开文件的所有行，返回一个列表
    string = f.readlines()
    
    # 将获取的列表第一行用'、'分割，返回分割后的形成的列表
    words = string[0].split("、")
    
    # 每个w是words里的一个词语
    for w in words:
        # 列表的反向索引，-1即倒数第一个/最后一个元素
        # 这里对最开始最后插入的字典进行操作
        # 字典中键值w处的索引值为一个空列表
        # 这里相当是为scales中所提及文件中的所有词语建立了键值，但索引为空
        results[-1][w] = []

# i在循环中为0~9
for i in range(10):
    
    # 同上，打开了上级文件夹中的年报文件夹，获取了2011~2020年中某一年的.txt文件
    # （怀疑这里写多了一个.txt文件，但不排除特意这样命名的可能）
    # 其他参数同上
    f = open("../年报/%d/%.txt" % (i+2011), "r", encoding='utf-8')
    
    # ""表示空字符串
    target = ""
    
    # 同上，读取了这一年的文件中的所有内容
    string = f.readlines()
    
    # 将所有读取到的文本进行合并
    for line in string:
        target += line

    # 去除target字符串中的所有空格
    target = target.replace(" ","")
    
    # j从0~3（scales列表的长度），len()返回目标的长度
    for j in range(len(scales)):
        
        # 打开以scales中元素命名的对应文件夹
        fkey = open("../%s.txt" % scales[j], encoding = "utf-8")
        
        # 读取所有内容
        s = fkey.readlines()
        
        # 仍然以"、"分割字符串
        words = s[0].split("、")
        
        # 针对每个单词进行操作
        for w in range(len(words)):
            
            # 计算target中出现了scales文件中词语的数量
            num = target.count(words[w])
            
            # 把得出的结果根据之前建成的键值对应存入results里
            results[j][words[w]].append(num)

# 遍历results列表，里面存放了以scales列表中元素命名的文件中的词语频率的字典
for i in range(len(results)):
    
    # pd即pandas，是Python的一个库文件
    # DataFrame是Pandas库汇总的一种数据结构，是一个带行标签和列标签的二维表
    # 自带一列有序标号列，通常用于处理Excel数据
    # 下面相当于是用results表的第i个元素（也就是一个字典）来创建DataFrame
    # 这种创建方式的具体创建是：字典的键值作为列标签，列中的值为对应键值的映射值
    # 此外还有很多创建方式，这是最简单的一种
    r = pd.DataFrame(results[i])
    r.to_excel("%s_词频统计.xlsx" % scales[i], index_label = ["2011", "2012", "2013", "2014", "2015", "2016", "2017", "2018", "2019", "2020"])
    
# 综上，这个程序将年报文件中以scales列表中元素为名的各个文件中所有词语出现的频率
# 以文件为表头，每个表以年份为行标，词语为列标，出现次数为值进行了展示。