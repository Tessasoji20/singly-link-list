#include<stdio.h>
#include<stdlib.h>
void main()
{
    struct node
    {
        int data;
        struct node *next;
    };
    struct node *head=NULL, *pos=NULL, *tail=NULL;
   
    int ch, entry, count, element, del;
    while(1)
    {
        printf("1. Insert\n2. Display\n3. Count\n4. Search\n5.Delete\n6. Exit");
        printf("\n\nEnter your choice: ");
        scanf("%d", &ch);
   
        switch(ch)
        {
            case 1: {
                    printf("\nEnter data: ");
                    scanf("%d", &entry);
                    if(head==NULL)
                    {
                        head=(struct node *)malloc(sizeof(struct node));
                        head->data=entry;
                        pos=head;
                        tail=head;
                    }
                    else
                    {
                        tail->next=(struct node *)malloc(sizeof(struct node));
                        tail=tail->next;
                        tail->data=entry;
                    }
                    break;
                }
               
            case 2: {
                    pos=head;
                    if(head==NULL)
                    {
                        printf("\nNo elements!");
                    }
                    else
                    {
                        printf("\nElements are: ");
                        while(pos!=NULL)
                        {
                            printf("\t%d", pos->data);
                            pos=pos->next;
                        }
                    }
                    printf("\n");
                    break;
                }
           
       
            case 3: {
                    pos=head;
                    if(head==NULL)
                    {
                        printf("\nNo elements!\n");
                    }
                    else
                    {
                        count=0;
                        printf("\nThe total number of elements are: ");
                        while(pos!=NULL)
                        {
                            count++;
                            pos=pos->next;
                        }
                        printf("%d\n", count);
                    }
                    break;
                }
               
            case 4: {
                    if(head==NULL)
                    {
                        printf("\nNo elements!");
                    }
                    else
                    {
                        int flag=0;
                        printf("\nEnter element to be searched: ");
                        scanf("%d", &element);
                        pos=head;
                        while(pos!=NULL)
                        {
                            if(pos->data==element)
                            {
                                printf("\nThe element %d was found at position %d", element, pos);
                                flag=1;
                            }
                            pos=pos->next;
                        }
                        if(flag==0)
                        {
                            printf("\nElement not found!\n");
                        }
                    }
                    printf("\n");
                    break;
                }   
               
            case 5: {
                    if(head==NULL)
                    {
                        printf("\nNo elements!\n");
                    }
                    else
                    {
                        struct node *temp=head;
                        printf("\nEnter position of element: ");
                        scanf("%d", &element);
                        if(element==0)
                        {
                            printf("\nElement deleted is: %d\n", head->data);
                            head=head->next;
                            temp->next=NULL;
                            free(temp);
                        }
                        else
                        {
                            for(int i=1; i<element-1; i++)
                            {
                                temp=temp->next;
                            }
                            printf("\nElement deleted is: %d\n", temp->next->data);
                            struct node *del=temp->next;
                            temp->next=temp->next->next;
                            del->next=NULL;
                            free(del);
                        }
                    }
                    break;
                }
               
            case 6: {
                    printf("\nGood bye!\n\n");
                    exit(0);
                }
        }
    }
}

	

