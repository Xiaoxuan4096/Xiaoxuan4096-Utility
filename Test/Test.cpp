#include <iostream>
#include "../FileEditor/FileEditor.h"
int main() {
    Xiaoxuan4096::File::FileEditor fe;
    std::wcout << fe.getObjectUniqueIdentityString();
    return 0;
}