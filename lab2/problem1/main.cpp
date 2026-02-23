#include "NumberList.h"

int main() {
    NumberList list;
    list.Init();
    
    list.Add(1);
    list.Add(0);
    list.Add(-5);
    list.Add(2);

    list.Print();
    
    list.Sort();
    
    list.Print();
    return 0;
}
