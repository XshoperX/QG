#pragma once
//单链表ADT

//结构体创建
typedef struct node{
    char data[20];
    struct node *next;
}node;
    static int count=0;   //统计链表数
    #define SIZE sizeof(node)    //链表大小（动态内存）
    static int sel=0;    //高亮选择区
//声明函数///////////////////////
node *addnewnode(node *head);//添加节点
node *creat();//创建一个链表
node *display();//显示菜单界面
void printstring( node *head);//显示链表所有元素
node *alter(node *head);//修改链表某一节点数据
node *delete(node *head);//删除链表节点
void HideCursor();//隐藏光标
void Change(node *head);//调换链表中节点奇偶位置
void Find_Middle(node *head);//查找中间节点的位置
void Circle(node *head);//使链表成环
void Check_Circle(node *head);//检查链表是否成环
node *Reverse(node *head);//非递归反转链表
void search(node *head);//搜索链表某一节点数据
void displaymenu(int sel,char *menu[10]);//菜单函数

//菜单数组（需用于全局）///////
  char *menu[10]={
     "[A]创建一个链表&&添加节点",
     "[B]显示链表所有元素",
     "[C]修改链表某一节点数据",
     "[D]删除链表节点",
     "[E]搜索链表某一节点数据",
     "[F]查找中间节点的位置",
     "[G]调换链表中节点奇偶位置(有点bug)",
     "[I]非递归反转链表",
     "[J]使链表成环",
     "[K]检查链表是否成环",
    };