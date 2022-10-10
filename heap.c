#include <stdio.h>
#include <stdlib.h>
struct Heap
{
    int * arr;
    int arr_lenght;
    int heap_lenght;
};

struct Heap* initialize_heap(int n)
{
    struct Heap* H=(struct Heap*)malloc(sizeof(struct Heap));
    H->arr=(int*)malloc(sizeof(int)*(n+1));
    H->arr_lenght=0;
    H->heap_lenght=0;//H->size=0;
    return H;

}

void swap(int arr[],int i,int j)
{
    int temp=arr[i];
    arr[i]=arr[j];
    arr[j]=temp;
}


void Heapify(int arr[],int n,int i)
{
    int left=2*i;
    int right=left+1;
    int largest=i;
    if (left<=n && arr[left]>arr[largest])
       largest=left;
    if (right<=n && arr[right]>arr[largest])
       largest=right;

    if (largest!=i)
    {
        
        swap(arr,largest,i);
        Heapify(arr,n,largest);
    }

}

void Max_Heapify(struct Heap* H,int i)
{
    Heapify(H->arr,H->heap_lenght,i);
}


void Build_Max_Heap(struct Heap* H)
{
    for (int i=H->heap_lenght/2;i>=1;i--)
    {
        Max_Heapify(H,i);
    }
}


void Extract_Max(struct Heap* H,int arr[])
{
    swap(arr,H->heap_lenght,1);
    
    H->heap_lenght-=1;
    Max_Heapify(H,1);



}


void Heapsort(struct Heap* H)
{
    for (int i=2;i<=H->arr_lenght;i++)
    {
        Extract_Max(H,H->arr);
    }
    
}


int main()
{
    
    int n;
    scanf("%d",&n);
    struct Heap* H=initialize_heap(n);
    int x;
    for (int i=1;i<=n;i++)
    {
        scanf("%d",&x);
        *(H->arr+i)=x;
        H->arr_lenght+=1;
        
    }
    H->heap_lenght=H->arr_lenght;

    Build_Max_Heap(H);
    Heapsort(H);

    for (int i=1; i<=n;i++)
    {
        printf("%d ",*(H->arr +i));
    }
    printf("\n");
}
