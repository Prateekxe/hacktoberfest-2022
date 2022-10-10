#include <stdio.h> 
 
void merge(int arr[],int mid,int lo,int hi){
     int B[hi+1];
     int i=lo;
     int j=mid+1;
     int k=lo;
     while (i<=mid && j<=hi){
           if (arr[i]<=arr[j]){
               B[k]=arr[i];
               i++;k++;
           } 
           else {
               B[k]=arr[j];
               j++;k++;
           }
     } 
     while (i<=mid){
         B[k]=arr[i]; 
         i++;k++;
     } 
     while (j<=hi){
         B[k]=arr[j]; 
         j++;k++;
     } 
     for (int i=lo;i<=hi;i++){
         arr[i]=B[i];
     }
}

void mergesort(int arr[],int lo,int hi){ 
     if (lo>=hi){
         return;
     } 
     int mid=(hi+lo)/2;
     mergesort(arr,lo,mid);
     mergesort(arr,mid+1,hi);
     merge(arr,mid,lo,hi);    
} 


int main(){
    int n;
    scanf("%d",&n);
    int arr[n];
    for (int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    int lo=0,hi=n-1;
    mergesort(arr,lo,hi); 
    for (int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
}
