#include <iostream>
#include "src/include/Page.h"
#include "src/include/DiskManager.h"
#include "src/include/BufferPool.h"

int main() {
    BufferPool bpm(new DiskManager("file.db"),20);
    Page *page=bpm.FetchPage(0);
    //page->Clear();
    bpm.Flush(0);
    //page->SetPageid(1);
    //page=bpm.FetchPage(1);
    //DiskManager dm("file.db");
    //dm.WritePage(1,"12345");
    //dm.ReadPage(1, page.Data());

    std::cout << page->Data();
    //dm.ShutDown();
}
