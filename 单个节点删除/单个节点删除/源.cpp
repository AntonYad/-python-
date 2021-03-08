#define _CRT_SECURE_NO_WARNINGS 1
classRemove{ public:boolremoveNode(ListNode*pNode) {if(NULL==pNode||NULL==pNode->next)returnfalse;pDelListNode*pDel=pNode->next;pNode->val=pDel->val;pNode->next=pDel->next;free(pDel);returntrue;    }};#include<stdio.h>#include <string.h>
