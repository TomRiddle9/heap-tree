#include<stdio.h>
#include<stdlib.h>

int size =0;
void swap(int* a, int* b){

    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapify(int arr[], int size, int i){

    int largest = i;
    int left = 2*i+1;
    int right = 2*i+2;

    if(left<size && arr[left]>arr[largest])
        largest = left;
    if(right<size && arr[right]>arr[largest])
        largest = right;
    if(largest != i){
            swap(&arr[i], &arr[largest]);
            heapify(arr,size,i);
    }
}

void insert(int arr[], int num){

    if(size==0){
            arr[0]= num;
            size += 1;
    }
    else{
            arr[size]= num;
            size+=1;
            for(int i= size/2-1;i>=0;i--){
                    heapify(arr,size,i);
            }
    }
}

void delete_node(int array[], int num_del)
{
  int i;
  for (i = 0; i < size; i++)
  {
    if (num_del == array[i])
      break;
  }

  swap(&array[i], &array[size - 1]);
  size -= 1;
  for (int i = size / 2 - 1; i >= 0; i--)
  {
    heapify(array, size, i);
  }
}

void print_list(int arr[], int size){
    for(int i=0;i<size;i++){
            printf("\n %d",arr[i]);
    }
}

int main(){

    int arr[100];
    insert(arr,7);
    insert(arr,8);
    insert(arr,9);
    insert(arr,10);
    insert(arr,2);

    printf("\n Max heap is -    ");
    print_list(arr,size);
    printf("\n After deleting one node -   ");
    delete_node(arr,8);
    print_list(arr,size);
    return 0;
}
