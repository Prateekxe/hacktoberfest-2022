#include <stdio.h>
int swap(int arr[],int i,int j){
    int temp;
    temp=arr[i];
    arr[i]=arr[j];
    arr[j]=temp;
}


int partition(int arr[],int low, int high){  
    int i=low+1; 
    int j=high; 
    int pivot=arr[low];
    while(i<j){
         while(arr[i]<=pivot){
             i++;
         } 
         while(arr[j]>pivot){
             j--;
         } 
         if (i<j){
             swap(arr,i,j); 
         }
    }  
    
    int idx=j;
    return idx;
    

}

void quicksort(int arr[],int low,int high){ 
     if (low>=high){
        return;
     }
     int idx; 
    
     idx=partition(arr,low,high); 
     swap(arr,low,idx);
     quicksort(arr,low,idx-1);
     quicksort(arr,idx+1,high);

} 
int main(){
    int n; 
    scanf("%d",&n); 
    int arr[n];
    for (int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    } 
    quicksort(arr,0,n-1); 
    for (int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
}
