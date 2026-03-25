# MySQL DDL

## 数据库

### 创建数据库

```mysql
CREATE DATABASE [数据库名];
-- 直接创建数据库

CREATE DATABASE IF NOT EXISTS [数据库名];
-- 判断数据库是否已经存在，不存在则创建数据库  

--CREATE DATABASE [数据库名] CHARACTER SET [字符集]; 
-- 创建数据库并指定字符集
```

### 查看数据库

```mysql
SHOW DATABASES;
-- 查看所有的数据库

SHOW CREATE DATABASE [数据库名];
-- 查看某个数据库的定义信息 
```

### 修改数据库

```mysql
ALTER DATABASE [数据库名] DEFAULT CHARACTER SET [字符集]; 
-- 修改数据库默认的字符集
```

### 删除数据库

```mysql
--DROP DATABASE [数据库名]; 
-- 删除数据库 
```

### 使用数据库

```mysql
SELECT DATABASE();
-- 使用 MySQL 中的全局函数，来查看正在使用的数据库

USE [数据库名];
-- 使用/切换数据库  USE 数据库名; 
```



- USE [if not exist] [数据库名];

  切换到指定数据库。

- CREATE DATABASE [数据库名] [字符集声明, 整理声明] ;

  创建数据库。字符集和排序规则不写默认为[utf8, utf8_gernal_ci]。

- DROP DATABASE [数据库名];

  删除数据库。数据库名必须存在。

- SHOW DATABASES;

  查看所有数据库名称。

- ALTER DATABASE [数据库名] [字符编码];

  修改数据库（只能修改其字符编码，无法修改名称）。

## 表

### 创建表

```mysql
CREATE TABLE [表名] (
	[字段名1] [字段1数据类型],
	[字段名2] [字段2数据类型],
	...);
-- 创建包含所定义字段的表
	
CREATE TABLE [表名] like [表];
-- 快速创建一个表结构相同的表
```

### 查看表

```mysql
DESC [表名];
-- 查看表的结构

SHOW CREATE TABLE [表名];
-- 查看创建该表的SQL语句

-- 当需要调用跨数据库的表时，直接使用[库名].[表名]即可
```

### 删除表

```mysql
DROP TABLE [if exists] [表名];
-- 直接删除表
-- if exist: 检查
```

### 修改表

```mysql
ALTER TABLE [表名] ADD [字段名] [类型] [FIRST | AFTER [字段名]];
-- 添加指定类型的新字段，并指定插入位置
	-- FIRST: 在最前方添加该字段
	-- AFTER [字段名]: 在指定列后添加该字段

ALTER TABLE [表名] ADD CONSTRAINT [约束名] [约束类型] [字段名]
-- 修改指定字段的约束条件
-- 约束名的指这个约束的名字，而非约束类型，即使写了也会显示PRIMARY，但最好还是起一个个性化名字

ALTER TABLE [表名] DROP INDEX [唯一约束名/列名（约束名默认为列名）];
-- 删除约束/索引

ALTER TABLE [附表名] ADD FOREIGN KEY [附表字段名] REFERENCES [主表名](主表字段名);
-- 为附表添加外键约束

ALTER TABLE [表名] ALTER [表名] SET DEFAULT [值];
-- 设定指定字段的默认值

ALTER TABLE [表名] MODIFY [字段名] [类型];
-- 更改指定字段的类型为指定类型

ALTER TABLE [表名] CHANGE [字段名] [新字段名] [类型] [约束名];
-- 更改指定字段名称为新字段名，并修改字段类型至指定类型
-- 注意，若只想修改类型或者约束名，那么前面的所有参数都需填写
	-- 比如：修改类型但不更改字段名时，需要在前面写两次字段名
	-- 再比如：修改约束类型但不更改字段名和类型时，需要在前面写两次字段名，类型名也要写

ALTER TABLE [表名] DROP [字段名];
-- 删除指定表的指定字段

RENAME TABLE [表名1] TO [表名2];
-- 重命名表

ALTER TABLE [表名] CHARACTER SET [字符集], COLLATE [排序规则];
-- 更改指定表的字符集和排序规则
```

### 复制表

```mysql
CREATE TABLE [新表] SELECT * FROM [旧表];
-- 创建与旧表结构及其数据相同的新表
-- 新表中没有了新表的主键（PRIMARY KEY）、Extra（AUTO_INCREMENT）等属性

CREATE TABLE [新表] SELECT * FROM WHERE [旧表字段=值];
CREATE TABLE [新表] LIKE [旧表];
-- 只复制旧表结构到新表

INSERT INTO [新表] SELECT * FROM [旧表];
-- 将数据复制进相同结构的新表

INSERT INTO [新表](字段1,字段2,……) SELECT 字段1, 字段2,…… FROM [旧表];
-- 将旧表选定的字段复制进新表的指定字段（字段间一一对应）

SELECT * INTO [新表] FROM [旧表] WHERE [旧表字段=值];
-- 将旧表符合条件的元组复制进新表

SELECT * INTO [新表] FROM [旧表]
-- 将旧表所有元组复制进新表

SHOW CREATE TABLE [旧表];
-- 显示创建旧表的命令，从而利用命令复刻新表

-- 还有一些物理结构上的操作：
-- mysqldump：将表导出，改好名字再导回去
-- 等等
```

## 数据

### 插入

```mysql
INSERT INTO [] VALUES ([value11], null, [value13]...) ([value21], [value22], [value23]...)
-- 插入多个元组
-- 插入空值使用null
```

### 更新/修改

```mysql
UPDATE [表名] SET [字段名2=值2] WHERE [字段名1=值1];
-- 修改指定元组的某个字段值

UPDATE [表名] SET [字段名1=值1], [字段名2=值2], [字段名3 is null]...;
-- 修改所有值
-- 注意：修改为空值要用is null而非=

SET TABLE read_only = 1;
```

