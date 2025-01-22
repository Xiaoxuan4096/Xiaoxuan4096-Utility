[< 返回 BasicSupport 导航](BasicSupport-导航)

本文建议阅读时间： 2 分钟。
> [!NOTE]
> 本文仅供参考，请以源码为准。

# Exception 介绍
Exception 提供了一个简单的异常类。

类名为`Exception`，属于`Xiaoxuan4096::Basic::Exception`命名空间。

`Exception`类部分基于`<Windows.h>`。

`Exception`类中存在的变量见下。
```
private:
    std::wstring detail = L"Warning: An error occurred.";
    SYSTEMTIME time;
```
`Exception`类提供的函数见下。
```
Exception(std::wstring exceptionDetail); // Time data will be added automatically.
std::wstring getExceptionDetail();
SYSTEMTIME getExceptionTime();
```