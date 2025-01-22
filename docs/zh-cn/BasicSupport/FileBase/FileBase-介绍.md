[< 返回 BasicSupport 导航](BasicSupport-导航)

本文建议阅读时间： 2 分钟。
> [!NOTE]
> 本文仅供参考，请以源码为准。

# FileBase 介绍
FileBase 提供了一组函数用于文件、文件夹的操作。
> [!TIP]
> 建议使用 FileEditor 以更方便的管理文件、文件夹。

所有函数均属于`Xiaoxuan4096::Basic::File`命名空间。

一些函数基于`<fstream>`，另一些函数基于`<filesystem>`。

所有函数都**不会**抛出异常。如无特殊说明，所有函数都**不使用**二进制读写模式。

如无特殊说明，函数类型默认为`void`。
> [!WARNING]
> FileBase 中所有涉及删除文件、文件夹的操作均**不可撤销**。

以下是函数列表。如需更详细的信息，请向下阅读。
```
void createFile(std::wstring path);
void deleteFile(std::wstring path);

void appendFile(std::wstring path, std::wstring content);
void rewriteFile(std::wstring path, std::wstring content);

void createEmptyDirectory(std::wstring path);
void removeEmptyDirectory(std::wstring path);
void removeDirectoryAndAllContents(std::wstring path);

void copySingleFile(std::wstring location, std::wstring destination) noexcept;
void copyDirectoryAndAllContents(std::wstring location, std::wstring destination) noexcept;

std::wstring readFile(std::wstring path);

bool existFile(std::wstring path);
```
---
## 文件的创建和删除
使用`createFile(std::wstring path)`函数可以创建一个文件。

|参数列表|类型|用途|
|---|---|---|
|path|`std::wstring`|指定文件路径。文件的上级目录**必须**存在，否则操作无效。|

使用`deleteFile(std::wstring path)`函数可以删除一个文件。

|参数列表|类型|用途|
|---|---|---|
|path|`std::wstring`|指定文件路径。文件**必须**存在，否则操作无效。|

---
## 文件读写
使用`appendFile(std::wstring path, std::wstring content)`函数可以向一个文件追加内容。

|参数列表|类型|用途|
|---|---|---|
|path|`std::wstring`|指定文件路径。文件的上级目录**必须**存在，否则操作无效。|
|content|`std::wstring`|指定追加内容。|

使用`rewriteFile(std::wstring path, std::wstring content)`函数可以覆写一个文件。

|参数列表|类型|用途|
|---|---|---|
|path|`std::wstring`|指定文件路径。文件的上级目录**必须**存在，否则操作无效。|
|content|`std::wstring`|指定覆写内容。|

使用`readFile(std::wstring path)`函数可以读取文件的内容。

函数返回一个`std::wstring`对象，这个对象内存储了文件的内容。
> [!CAUTION]
> **直接**使用此函数读取大文件时，内存分配可能失败。
>
> 如需读取大文件，请考虑使用 FileEditor 。

|参数列表|类型|用途|
|---|---|---|
|path|`std::wstring`|指定文件路径。若文件不存在，返回空的字符串。|

---
## 文件夹的创建和删除
使用`createEmptyDirectory(std::wstring path)`函数可以创建一个空文件夹。

|参数列表|类型|用途|
|---|---|---|
|path|`std::wstring`|指定文件夹路径。文件夹的上级目录**必须**存在，否则操作无效。|

使用`removeEmptyDirectory(std::wstring path)`函数可以删除一个空的文件夹。

|参数列表|类型|用途|
|---|---|---|
|path|`std::wstring`|指定文件夹路径。文件夹的上级目录**必须**存在，且文件夹必须为**空**，否则操作无效。|

使用`removeDirectoryAndAllContents(std::wstring path)`函数可以删除一个文件夹及其所有内容。

|参数列表|类型|用途|
|---|---|---|
|path|`std::wstring`|指定文件夹路径。文件夹的上级目录**必须**存在，否则操作无效。|

---
## 文件、文件夹的复制
> [!WARNING]
> 如果目标文件夹下存在同名文件，同名文件会被**覆写**。

使用`copySingleFile(std::wstring location, std::wstring destination)`函数可以复制一个文件。

|参数列表|类型|用途|
|---|---|---|
|location|`std::wstring`|指定源文件路径。文件**必须**存在，否则操作无效。|
|destination|`std::wstring`|指定目标文件夹路径。若目标文件夹不存在，会自动创建文件夹。|

使用`copyDirectoryAndAllContents(std::wstring location, std::wstring destination)`函数可以复制一个文件夹及其所有内容。

|参数列表|类型|用途|
|---|---|---|
|location|`std::wstring`|指定源文件夹路径。文件夹**必须**存在，否则操作无效。|
|destination|`std::wstring`|指定目标文件夹路径。若目标文件夹不存在，会自动创建文件夹。|

---
## 杂项
使用`existFile(std::wstring path)`函数可以检查一个文件是否存在。

函数返回一个`bool`值，`true`表示文件存在，`false`表示文件不存在。

|参数列表|类型|用途|
|---|---|---|
|path|`std::wstring`|指定文件路径。|