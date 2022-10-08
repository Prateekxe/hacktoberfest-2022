#include <stdio.h>
//#define M 11
int cnt=0;

int hash(int key, int size){
    return key%size;
}
int probe(int h[], int key, int size){
    int index = hash(key,size);
    int i=0;
    while(h[(index+i*i)%size]!=0){
        i++;
        cnt++;
    }
    return (index + i*i)%size;
    
}

void insert(int h[], int key, int size){
    int index = hash(key, size);
    
    if(h[index]!=0)
        index = probe(h,key,size);
    h[index]=key;
}

int main(){
    
    int M;
    scanf("%d", &M);
    int h[M];
    h[M] = 0;
    int s,k;
    scanf("%d", &s);
    for(int i=0; i<s; i++){
        scanf("%d", &k);
        insert(h,k,M);
    }
    printf("%d",cnt);
    return 0;
}
