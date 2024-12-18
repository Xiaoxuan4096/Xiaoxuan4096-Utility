# Xiaoxuan4096-Utility
自己编写的一些实用程序。

---
## 版权声明
> [!IMPORTANT]
> 本程序及其所有部分归 **Xiaoxuan4096** 所有。如用于商业目的，须事先向 **Xiaoxuan4096@outlook.com** 致函申请。
---
## 内容
### BasicSupport
这是对其他库的基本支持。
- [FileBase](/BasicSupport/FileBase/FileBase.h) ：基础文件操作函数。
- [StringUtilities](/BasicSupport/StringUtilities/StringUtilities.h) ：字符串操作函数。
- [ObjectUniqueIdentityString](/BasicSupport/ObjectUniqueIdentityString/ObjectUniqueIdentityString.h) ：对象唯一标识符。通过随机数产生。
- [Exception](/BasicSupport/Exception/Exception.h) ：异常处理类。
### [FileEditor](/FileEditor/FileEditor.h)
基础的文件读写库。

---
## 注意事项
编写环境：Microsoft Visual Studio 2022

---
## 更新日志
### 2024/12/10
完善 UniqueIdentityString 类并重命名为 ObjectUniqueIdentityString 。
### 2024/12/08
引入 UniqueIdentityString 类。

向 FileBase 库添加复制文件功能。

修改使用的 C++ 标准为 C++17 ，使用`<filesystem>`重写 FileBase 库。
### 2024/12/06
创建 FileEditor 的基础函数。

开始编写 FileEditor ，增加 FileBase 中对文件夹操作的支持。
### 2024/12/01
更改许可证为 GPL-3.0 License。
### 2024/11/28
迁移 Exception 库（版本：0.0.0.1）至本仓库。

迁移 StringUtilities 库（版本：0.0.0.0）至本仓库。

迁移 FileBase 库（版本：0.0.0.0）至本仓库并修复 FileBase 编译问题。