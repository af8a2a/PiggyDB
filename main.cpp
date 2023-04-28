#include <iostream>
#include "src/include/Page.h"
#include "src/include/DiskManager.h"

int main() {
    Page page;
    page.SetPageid(1);
    DiskManager dm("file.db");
    //dm.WritePage(1,"12345");
    dm.ReadPage(1, page.Data());
    std::cout << page.Data();
    dm.ShutDown();
}
