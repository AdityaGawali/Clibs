#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>



struct node
{
    int32_t data;
    struct node* next;
};

typedef enum 
{
    START = 0,
    AFTER = 1,
    END = 2
}position_e;


/*
GLOBAL HEAD POINTER 
*/
 static struct node* head = NULL;

void head_init(int32_t data)
{
    head = (struct node*)(malloc(sizeof(struct node)));
    head->data = data;
    head->next = NULL;

}


void add_node( position_e pos ,int32_t ref_data, int32_t data)
{
    struct node* temp = head;

    if(head == NULL)
    {
        head_init(data);
    }
    else
    {
    if(pos == END)
    {
        

        while(temp->next != NULL)
        {
            temp = temp->next;
        }
        struct node* new_node = (struct node*)malloc(sizeof(struct node));
        temp->next = new_node;
        new_node->data = data;
        new_node->next = NULL;
        
    }
    else if(pos == START)
    {
        struct node* first = (struct node*)(malloc(sizeof(struct node)));
        first->data = data;
        first->next = head;
        head = first;
        
    }
    else if(pos == AFTER)
    {
    
        struct node* temp1 = (struct node*)(malloc(sizeof(struct node)));;
        while(temp !=  NULL )
        {
            if(temp->data == ref_data)
            {
                break;
            }

            temp = temp->next;
        }
        if(temp == NULL)
        {
            printf("ERROR Data: %d not present in List\n",ref_data);

        }
        else
        {
            struct node* after = (struct node*)(malloc(sizeof(struct node)));
            temp1->next = temp->next;
            temp->next = after;
            after->data = data;
            after->next = temp1->next;
        }
    }
}

}



void print_list()
{
    struct node* temp = head;

    if(head == NULL)
    {
        printf("List is Empty\n");
    }
    else
    {        
    while(temp != NULL)
    {
        printf("Data: %d\n" ,temp->data);
        temp = temp->next;
    }
    }
}

void delete_node(position_e pos, int32_t ref_data)
{   
    struct node* temp = head;
    struct node* temp1 = NULL;
    struct node* temp2 = NULL;
    if(head == NULL)
    {
        printf("ERROR-> list already empty\n");
    }
    else
    
    {

    
    if(pos == START)
    {
        head  = temp->next;
        free(temp);
    }
    else if(pos == AFTER)
    {
        while(temp !=  NULL )
        {
            if(temp->data == ref_data)
            {
                break;
            }
            temp = temp->next;
        }
        if(temp == NULL)
        {
            printf("ERROR-> Data: %d not present in List\n",ref_data);

        }
        else
        {
            temp1 = (temp->next)->next;
            temp2 = temp->next;
            temp->next = temp1;
            free(temp2);
                
        }
    }
    
    else if(pos == END)
    {
        while((temp->next) != NULL)
        {
            temp1 = temp;
            temp = temp->next;
        }
        if(temp == head)
        {
            head = NULL;
        }
        else
        {
            temp1->next = NULL;
        }
        
        free(temp);
    }
}
}

void list_init(uint32_t length, int32_t* data)
{
    head_init(data[0]);
    for(uint32_t i  = 1; i<length;i++)
    {
        add_node(END,0,data[i]);
    }
    printf("List created sucessfuly\n");
}

uint32_t list_length()
{
   struct node* temp  = head;
   uint32_t count=0;
        while(temp != NULL)
        {
            temp=temp->next;
            count++;
        }
    return count;
}
void list_deinit()
{
    struct node* temp  = head;
    if(head == NULL)
    {
        printf("List is already empty\n");
    }
    else
    {   
        uint32_t len =list_length();
        for(uint32_t i =0;i<len;i++)
        { 
            printf("****\n");
            delete_node(END,0);
        }
        printf("List deleted sucessfully\n");
    }

    
}
