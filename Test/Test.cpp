#include <iostream>
#include "../FileEditor/FileEditor.h"
int main() {
    Xiaoxuan4096::File::FileEditor fe;
    std::wcout << fe.ouid.getObjectUniqueIdentityString();
    return 0;
}