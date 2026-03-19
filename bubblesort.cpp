#include<stdio.h>

void bubbleSort(int arr[], int n){
	int i, j, temp;
	
	//passes=1,2,3,4,5
	for(i=0;i<n;i++){
		
		//Compansions
		
		for(j=0;j<n;j++){
			
			//Swap elements are in wrong order
			
		if(arr[j]>arr[j+1]){
			temp=arr[j];
			arr[j]=arr[j+1];
			arr[j+1]=temp;
			}
		}
	}
}

//print array

void printArray(int arr[], int n){
	int i;
	for(i=0;i<n;i++){
		printf("%d", arr[i]);
	}
	printf("\n");
}

int main(){
	int arr[]={5,2,9,1,6};
	int n=5;
	
	printf("Original array:\n");
	printArray(arr, n);
	
	bubbleSort(arr, n);
	
	printf("Sorted Array:\n");
	printArray(arr, n);
	
	return 0;	
}