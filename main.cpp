#include <iostream>
#include "src/include/storage/Page/Page.h"
#include "src/include/storage/DiskManager.h"
#include "src/include/BufferPool.h"

int main() {
    BufferPool bpm(new DiskManager("file.db"),20);
    Page *page=bpm.FetchPage(0);
    bpm.Flush(0);
    std::cout << page->Data();
}
