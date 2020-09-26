// MTI.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include "Subnet_Container.h"

//debug 1 or 2 
#define debug_1 0 
#define debug_2 1 

int main()
{
    system("chcp 1251>nul");


#if debug_1 1



    Subnet_Container NetList_1("192.168.0.5/24");
    std::list<std::string> NetList_2_list;
    NetList_2_list.push_back( "192.168.0.2/24");
    NetList_2_list.push_back( "192.168.0.7/24");
    NetList_2_list.push_back( "192.168.1.55/24");
    NetList_2_list.push_back( "192.168.0.55/24");
    NetList_2_list.push_back( "192.168.5.55/24");

    NetList_1.Set_Subnet(NetList_2_list);
    NetList_1.Set_Subnet("192.168.5.58/24");

    
    for (auto it = NetList_1.Subnet.begin(); it != NetList_1.Subnet.end(); it++)
    {
        std::cout << ' '<<*it<<'\n';
    }

    
    printf("_______________________\n\n");

    if (!NetList_1.Delete_Subnet("192.168.0.5/24"))
    {
        printf("Удаление не удалось.\n");
        printf("_______________________\n\n");
    } 
    else
    {
        printf("Удаление удалось.\n");
        printf("_______________________\n\n");
    }

    for (auto it = NetList_1.Subnet.begin(); it != NetList_1.Subnet.end(); it++)
    {
        std::cout << ' ' << *it << '\n';
    }
#endif // debug 1
    
#if debug_2


   Subnet_Container NetList_1("192.168.0.0/24");
// NetList_1.Set_Subnet("192.2.0.5/24");
// NetList_1.Set_Subnet("192.2.0.5/24");
   std::cout<< NetList_1.Checking_Entry_Ip("192.168.0.126")<<'\n';
   std::cout<< NetList_1.Checking_Entry_Ip("192.168.1.1")<<'\n';
// std::cout<< NetList_1.Checking_Entry_Ip("192.168.2.5")<<'\n';
// std::cout<< NetList_1.Checking_Entry_Ip("192.2.2.5")<<'\n';
  
#endif // debug_2

    return 0;
 }
