#include <iostream>
#include "UI.h"
#include "Tests.h"

int main()
{
    UI U;
    TestExpense();
    TestServiceCRUD();
    TestServiceDel();
    TestServiceShow();
    TestServiceSort();
    TestServiceFilter();
    TestRepository();
    U.Run();
}
