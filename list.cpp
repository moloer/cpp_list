#include <iostream>
#include <stdlib.h>
#include <string.h>

using namespace std;

/*节点结构体*/
struct node
{
	char name[50];//节点里面的数据
	struct node *next; //指向下一个节点
};
/*由于开辟节点空间是重复性的工作,所以写成函数*/
/*函数的参数是要存放到节点里的数据*/
struct node *creatnode(char *value)
{
	struct node *pnode=(struct node *)malloc(sizeof(struct node));//分配了一块空间
	if(value==NULL)	
	{
		pnode->name[0]='\0';
	}
	else
	{
		strcpy(pnode->name,value);
	}
	
	//将next变量置空
	pnode->next=NULL;
	return pnode;
}
/*
//创建节点的另外写法,把指针作为参数传进函数,然后改变它的指向
void creatnode(struct node** p)
{
	*p=malloc(sizeof(struct node));
	(*p)->name=xxx;
	(*p)->next=NULL;
}
*/ 
/*
//增加一个节点,返回修改后的链表
struct node *add(struct node *list,char *value)
{
	//遍历链表,遇到next为空则创建一个节点,然后将value放进去,然后将next指向该节点
	struct node *tmp=list;//用一个临时变量便利链表
	while(tmp->next!=NULL)
	{
		tmp=tmp->next;//tmp往后面移动一个节点	
	}
	struct node *newnode=creatnode(value);//创建新节点
	tmp->next=newnode;
	
	return list;
}*/
//增加一个节点,返回修改后的链表
void add(struct node **list,char *value)
{
	//遍历链表,遇到next为空则创建一个节点,然后将value放进去,然后将next指向该节点
	struct node *tmp=(*list);//用一个临时变量便利链表
	while(tmp->next!=NULL)
	{
		tmp=tmp->next;//tmp往后面移动一个节点	
	}
	struct node *newnode=creatnode(value);//创建新节点
	tmp->next=newnode;
	
	//return list;
}
//遍历链表
void travel(struct node *list)
{
	struct node *tmp=list;
	while(tmp->next)
	{
		cout<<tmp->next->name<<endl;
		tmp=tmp->next;//移到下一个节点
	}
}

void clear(struct node **list)
{
	struct node *tmp1=(*list);
	struct node *tmp2;
	while(tmp2=tmp1->next)
	{
		free(tmp1);
		tmp1=tmp2;//将第一个指针移到下一个节点
	}
	tmp1->name[0]='\0';	
}
//插入节点
void insert(struct node **list,char *value,int idx)
{
	int i=0;//用来计数的
	struct node *tmp=*list;
	while(tmp->next)
	{
		tmp=tmp->next;
		i++;
		if(i==idx)
		  break;
	}
	//判断是否尾部
	struct node *tmpnext=tmp->next;
	if(tmpnext==NULL)
	{
		tmp->next=creatnode(value);		
	}
	else
	{
		tmp->next=creatnode(value);
		tmp->next->next=tmpnext;
	}
}

//从指定位置删除节点

void list_delete(struct node **list,int idx)
{
	struct node *tmp=(*list);
	struct node *last;
	int i=0;
	while(tmp->next)
	{
		last=tmp;
		tmp=tmp->next;
		i++;
		if(i==idx)
		  break;
	}
	if(i!=idx) //如果idx超出节点数量,直接返回
	  return;
	last->next=tmp->next;
	free(tmp);//释放tmp指向的节点
	tmp=NULL;
}

int main(void)
{
	//创建一个链表,用一个节点来代表链表
	struct node *list=NULL;
	//给这个指针分配指向的对象,就是分配空间
	list=creatnode(NULL);	
	
	//加入内容
	//list=add(list,"zhangfei");
	//list=add(list,"zhaoyun");
	//list=add(list,"caocao");

	add(&list,"zhangfei");
	add(&list,"zhaoyun");
	add(&list,"caocao");
	add(&list,"liubei");
	insert(&list,"xiahoudun",3);
	//遍历显示链表的所有数据
	travel(list);
	list_delete(&list,1);
	cout<<"删除节点后"<<endl;
	travel(list);

	clear(&list);

	//travel(list);
}



