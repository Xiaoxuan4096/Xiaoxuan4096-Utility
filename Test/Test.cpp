#include <iostream>
#include "../FileEditor/FileEditor.h"
int main() {
    Xiaoxuan4096::File::FileEditor fe;
    fe.linkWithFile(L"D:/Desktop", L"bsk.txt");
    fe.createFile();
    fe.append(L"bsk");
    std::cout << "done!" << std::endl;
    return 0;
}