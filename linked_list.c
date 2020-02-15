#include"linked_list.h"
int main()
{   
    int32_t data[] = {50,100,150,200,250};
    list_init(5,data);
    print_list();
    printf("\n");
    printf("Length of the List: %d\n",list_length());
    list_deinit();
    print_list();
    printf("\n");
    printf("Length of the List: %d\n",list_length());

    return 0;
}