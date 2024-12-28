#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct node
{
int id;
char name[100];
struct node*next;
};
int in_list(struct node* list, int i) {
    struct node* current = list;
    while (current != NULL) {
        if (current->id==i)
        {
            return 1;
        }
        current = current->next;
    }
    return 0;
}
void in_list2(struct node* list, int i) {
    struct node* current = list;
    while (current != NULL) {
        if (current->id==i)
        {
            printf("%s %d found.\n",current->name,current->id);
            return ;
        }
        current = current->next;
    }
    printf("Student %d not found.\n",i);
    return ;
}
struct node * create(int x,char nam[])
{
    struct node *nn=(struct node *)malloc(sizeof (struct node));
    nn->next=NULL;
    nn->id=x;
    strcpy(nn->name,nam);
    return nn;
}
void print(struct node* list) 
{
    struct node* current = list;
    printf("List: [");
    while (current!= NULL) 
    {
        printf("%s %d",current->name,current->id);
        if (current->next!=NULL)
        printf(", ");
        current = current->next;
    }
    printf("]\n");
    return;
}
void add_end(struct node* list, struct node* new) 
{
    struct node* current = list;
    while (current->next != NULL) 
    {
        current = current->next;
    }
    current->next = new;
    new->next=NULL;
    printf("%s %d inserted.\n",new->name,new->id);
    return;
}
int delete(struct node**list,int i)
{
    struct node* current = *list;
    struct node* tmp = NULL;
    int cnt=0;
    while (current!= NULL) {
        if (current->id==i)
        {
            if (tmp==NULL&&current==*list)
            {
                *list=current->next;
            }
            else if (current->next==NULL)
            {
                tmp->next=NULL;
            }
            else
            {
                tmp->next=current->next;
            }
            printf("%s %d deleted.\n",current->name,current->id);
            free(current);
            return 1;
        }
        tmp=current;
        current = current->next;
        if (cnt!=0)
        tmp=tmp->next;
        cnt++;
    }
    return 0;
}
void free_list(struct node *list) {
    struct node *current;
    while (list != NULL) {
        current = list;
        list = list->next;
        free(current);
    }
}
int main ()
{
int n;
struct node * list=NULL;
scanf("%d",&n);
for (int i=0;i<n;i++)
{
char str[10];
scanf("%s",str);
if(strcmp("Insert",str)==0)
{
char nam[50];
int j;
scanf(" %s %d",nam,&j);
if (list==NULL)
{
    list=create(j,nam);
    printf("%s %d inserted.\n",nam,j);
    print(list);
}
else
{
    int r=in_list(list,j);
    if (r==0)
    {
        struct node *new=create(j,nam);
        add_end(list,new);
        print(list);
    }
    else
    {
        printf("Student %d already exists.\n",j);
    }
}
continue;;
}
else if(strcmp("Delete",str)==0)
{
    int j;
    scanf("%d",&j);
    int res=delete(&list,j);
    if (res==1)
    {
        print(list);
    }
    else
    {
        printf("Student %d not found.\n",j);
    }
continue;
}
else if(strcmp("Search",str)==0)
{
    int i=0;
    scanf("%d",&i);
    in_list2(list,i);
continue;
}
printf("\n");
}
free_list(list);
    return 0;
}