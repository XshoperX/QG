#include"Single_link.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <malloc.h>
#include <windows.h>
#include <conio.h>
#include <mmsystem.h>
//主函数//////////////////////////
int main(){
    fflush(stdin);//清除输入缓存区
    node *head=NULL;  //头指针
    int c=' ';
displaymenu(sel,menu); 
//该菜单选择有两种方案：1.使用上下方向键和回车键 2.直接输入对应字母不需要回车

for(;;)
   { 
        fflush(stdin);
        if(GetAsyncKeyState(VK_UP)){
            sel=(sel>0)?sel-1:sel;
            system("cls");
            displaymenu(sel,menu);
        }
        if(GetAsyncKeyState(VK_DOWN)){
            sel=(sel<10)?sel+1:sel;
            system("cls");
            displaymenu(sel,menu);
        }          
        
         c=getch();  //读取按键值来判断,C变量是按键值的载体

         if(c<='z'&&c>='a')             //若输入了小写字母，转化为大写字母
         c=c-('a'-'A');

         if(c<='K'&&c>='A'&&c!='H'){   //注：这里不允许接收k是因为VK_down对应的值正好是K
            sel=c-'A';
            system("cls");
            displaymenu(sel,menu);
            printf("command is [%c]",c);
            //************************依据所选的sel值来执行所选功能
         }

         else if(c=='\r'){    //判断是否是回车，若按下回车则进入函数（功能）
            printf("You choose the [%c]\n",'A'+sel);
            c = 'A' + sel ;
            if(c>='H') c++;
         }
         Sleep(100);//防止刷新过快导致的误触
        
        //按键操作结束，接下来是判断c的内容来进入函数
        switch(c){
            case'A':
                if(count==0){
                Sleep(200);
                printf("你还未创建链表，先创建一份链表吧!\n"); 
                Sleep(200);                            
                head=creat();
                printf("\n请按上下键来切换功能或按回车继续执行当前功能");    //只能是上或下键的原因是因为我只有按了上或下键或回车才会再次进入菜单函数并打印菜单（不按的话就一直循环但不会经过if里面的语句）
                break;               
              }
             if(count>0){           //若已创建，则进入添加节点函数
                head=addnewnode(head);
                printf("\n请按上下键来切换功能或按回车继续执行当前功能");   
                break;
             }            
             case'B':
                printstring(head);
               printf("\n请按上下键来切换功能或按回车继续执行当前功能");   
                if( getch())
                {system("cls"); displaymenu(sel,menu);};
                break;
             case'C':
                head=alter(head);
                printf("\n请按上下键来切换功能或按回车继续执行当前功能");
                break;  
             case'D':
                head=delete(head);
                printf("\n请按上下键来切换功能或按回车继续执行当前功能");
                break;  
             case'E':
                search(head);
                printf("\n请按上下键来切换功能或按回车继续执行当前功能");
                break;
             case'F':
                Find_Middle(head);
                printf("\n请按上下键来切换功能或按回车继续执行当前功能");
                break;
             case'G':
                 Change(head);
                 printf("\n请按上下键来切换功能或按回车继续执行当前功能");
                 break;
             case'I':
                Reverse(head);
                printf("\n请按上下键来切换功能或按回车继续执行当前功能");
                 break;
             case'J':
                Circle(head);
                printf("\n请按上下键来切换功能或按回车继续执行当前功能");
                 break;
             case'K':
                Check_Circle(head);
                printf("\n请按上下键来切换功能或按回车继续执行当前功能");
                 break;
            
        }
    }

}

//创建链表函数////////////////////
node *creat(){
    node *head=NULL, *p,*pnew;
    pnew=(node*)malloc(SIZE);
    p=pnew;
    printf("\n请输入data：(直接按回车时退出)\n");
    /////////////////先创建一个新节点
    gets(pnew->data);
     if(strlen(pnew->data)==0){system("cls"); displaymenu(sel,menu); return NULL;};  //若输入为空则退出函数，并重置菜单
     ////////////////
   for(;;){
    count++;
    if(count==1)    
        head=pnew;
    else    
        p->next=pnew;       //链接节点
    p=pnew;
    pnew=(node*)malloc(SIZE);
    //检查是否开辟成功
    if(pnew==NULL){
     printf("开辟失败");
     break;             
    }
    //继续输入
    printf("\n请输入：\n");
    gets(pnew->data);
      if(strlen(pnew->data)==0){break;};                //先前我在这里犯了个致命的错误
  }
    p->next=NULL;       //尾指针必须为空
    free(pnew);         //退出时释放新开辟的内存
    return head;
}

//添加链表函数
node *addnewnode(node *head){
    if(head==NULL) return NULL;
     node *p,*pnew;
    pnew=(node*)malloc(SIZE);
   p=head;
    printf("\n请输入：(直接按回车时退出)\n");

     /////////////////先创建一个新节点
    gets(pnew->data);
     if(strlen(pnew->data)==0){system("cls"); displaymenu(sel,menu); return head;};  //若输入为空则退出函数，并重置菜单
     ////////////////
    for(;p->next!=NULL;){    //找到尾链表；
        p=p->next;
    }
    for(;;){
        count++;
        p->next=pnew;
    p=pnew;
    pnew=(node*)malloc(SIZE);
    if(pnew==NULL){
     printf("开辟失败");
     break;//检查是否开辟成功
    }
    printf("\n请输入：\n");

    //////////////先创建一个新节点
    gets(pnew->data);
    if(strlen(pnew->data)==0){break;};          //先前我在这里犯了个致命的错误导致尾指针不为NULL就退出函数  
     ////////////////
  }
    p->next=NULL;
    free(pnew);
    return head;
}

//显示函数////////////////////////////////////////////////////
  void printstring( node *head){
    node *p=head,*q=NULL;
    if (p==NULL)
     return ;
     for(p=head;p!=NULL;p=p->next){
        printf("data:");printf("%s\n",p->data);
     }
    }


//修改函数//////////////////////////////////
node *alter(node *head){
    if(head==NULL){ printf("NULL!");return NULL;}
node *pnew=NULL;
pnew=head;   
printstring(head);
printf("\n你想修改第几个数据？请输入对应排序:");
int i=0;//排序
do{
scanf("%d",&i);
getchar();  //吸收
if(i>count)
printf("不正确的值！,请重新输入：");
}while(i>count);
i=i-1;
printf("\n请修改:\n");
for(int j=0;j<i;j++){
    pnew=pnew->next;
}
      printf("data:");
      gets(pnew->data);
    printf("\n修改完毕");
    return head;
}
 
////////////////////////////////

//删除函数/////////////////////////////////
node *delete(node *head){
    if(head==NULL){ printf("NULL!");return NULL;}
    node *pnew=NULL,*p=NULL,*pnext=NULL;
    pnew=head;
    p=head;   
    printstring(head);
    printf("\n你想删除第几个数据？请输入对应排序:");
    int i=0;//排序

    do
    {
    scanf("%d",&i);
    getchar();  //吸收
    if(i>count)
    printf("不正确的值！,请重新输入：");
    }while(i>count);

    i=i-1;
    if(i==0)
    {
     p=p->next;
    printf("\n已删除:\n");
    count--;
    free(head);       //释放掉内容
    return p;
    }
    else
    {
    for(int j=0;j<i-1;j++){
    pnew=pnew->next;
}
    pnext=pnew->next;
    pnew->next=pnext->next;
    }
    count--;
    free(pnext);
printf("\n已删除:\n");
return p;
}
/////////////////////////////////////////////


    //菜单函数/////////////////////////
 void displaymenu(int sel,char *menu[10])
 {
    int i;          //i==sel对应的是高亮选择区
    printf("\033[35;40m\n========================================================================================================================\n");
    for(i=0;i<10;i++){
        if(i==sel)
        printf("                        \033[32;40m<<%s>>\n",menu[i]);
        else
        printf("                          \033[37;40m%s\n",menu[i]);
    }
    printf("\033[35;40m\n========================================================================================================================\n");
 
    }


//搜索函数/////////////////////////////////////
void search(node *head){
    
    if(head==NULL) return ;
    node *p;      
    p=head;
    char task[30];     //暂存搜索内容

printf("输入搜索内容：");
gets(task);
for(;p!=NULL;p=p->next){
    if(!strcmp(task,p->data))
    {
        printf("\nfind it!\n");return;   //找到了返回
    }
  }
  printf("404 no find"); return;    //循环完了还没找到，打印并返回
}



//寻找中间节点
void Find_Middle(node *head)
{   if(head==NULL) return ;
	node *fast = head;
	node *slow = head;
	while (fast != NULL && fast->next != NULL)
	{
		fast = fast->next->next;
		slow = slow->next;
	}
	printf("中间节点的值为:%s\n", slow->data);
}

//调换链表中奇偶
void Change(node* head)
{
     node *prenode = head;
     node *nextnode = head;
     node *current = head;
     if(head==NULL)return;;
        current = head ->next;
        nextnode = head ->next->next;
    
    while (nextnode->next != NULL && nextnode != NULL)
    {
        prenode ->next = nextnode;
        current->next = nextnode->next;
        nextnode->next = current;
        prenode = current;
        current=current->next;
        nextnode=current->next;
    }
    
}

// 反转链表（非递归）
node* Reverse(node *head) {
    node* prev = NULL;
    node* current = head;
    node* next = NULL;
    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    return prev;
}

//使得链表成环
void Circle(node* head)
{
    struct node* last = head;
    while (last->next)
    {
        last = last->next;
    }
    last->next = head;
}

//判断是否成环
void Check_Circle(struct  node* head)
{
    if (head!=NULL)
    {
        struct node * slow = head;
        struct node * fast = head;
        slow = slow ->next;
        fast = fast ->next ->next;
        while (fast != slow  && (fast && fast ->next ))
        {
            slow = slow ->next;
            fast = fast ->next ->next;
        }   
        if (fast == NULL || fast->next == NULL)
        {
            printf("失败\n");
            return; 
        }else
        {
            printf("成功\n");
            return;
        }       
    }
}