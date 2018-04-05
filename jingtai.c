#include <stdio.h>
#include <stdlib.h>
typedefstruct {
int *elem;
int length;
} SSTable;	
intSearch_w(SSTablest, int key) {
st.elem[0]=key;
for(inti = st.length;st.elem[i]!=key; --i)
    return i;           
}

intSearch_Bin(SSTablest, int key) {
int low = 1, high = st.length;  
while(low <= high) {
int mid = (low + high) / 2;
        if(key == st.elem[mid]) return mid;
else if(key <st.elem[mid])
            high = mid - 1;
        else low = mid + 1;
    }
    return -1;
}

int main(void) {
SSTablest;
printf("输入元素个数:");
scanf("%d", &st.length);
st.elem = (int *)malloc( (st.length + 1) * sizeof(int) );
int key;
printf("输入要查找元素:");
scanf("%d", &key);
printf("输入无序的各个元素:");
for(inti = 1; i<= st.length; ++i)
scanf("%d", &st.elem[i]);
printf("查找结果:%d\n", Search_w(st, key));
printf("输入有序的各个元素:");
for(inti = 1; i<= st.length; ++i)
scanf("%d", &st.elem[i]);
printf("查找结果:%d\n", Search_Bin(st, key));
return 0;
}

#include <stdio.h>
#include <stdlib.h>

typedefstructLNode {
int data；
structLNode *next;
} LNode, *LinkList;

void Create(LinkList&L, int n) {
  L = (LinkList)malloc(sizeof(LNode));
    L->next = NULL;
LinkList p = NULL, p2 = L;
for(inti = n; i> 0; --i) {
        p = (LinkList)malloc(sizeof(LNode));
scanf("%d", &p->data);
        p2 = p2->next = p;
    }	
    p2->next = NULL;
}

intSearch_w(LinkList L, int key) {
intans = 0;
    L = L->next;
for(inti = 1; L != NULL; ++i) {
if(L->data == key) {
ans = i; break;
        } else L = L->next;
    }
    return ans;
}

void Release(LinkList&L) {
LinkList p = NULL, next = NULL;
for(p = L->next; p; p = next) {
next = p->next;
free(p);
    }
free(L);
}

int main(void) {
LinkList L;int n, k;
printf("请输入元素个数:");
scanf("%d", &n);
printf("请输入要查找的元素:");
scanf("%d",&k);
printf("输入各个元素");
Create(L, n);
printf("查找结果: %d\n", Search_w(L, k));
Release(L);
return 0;
}
