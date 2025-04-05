/*
A generic sort funciton using template and a function pointer for compare function

Made by: Neeraj Lakhotia
GitHub: https://github.com/neeraj08
*/

#include<iostream>
using namespace std;

template<typename T>
inline void swap(T *a,T *b){
	T temp=*a;
	*a=*b;
	*b=temp;
}

template<typename T>
void sort(T Arr[],int size,bool (*compare)(T,T)){ //using a pointer to a compare function
	bool anything_swapped; 
	for( int i=0;i<size;i++){
		anything_swapped=false;	
		for(int j=0;j<size-1-i;j++){
			if(compare(Arr[j],Arr[j+1])){
				swap(Arr+j,Arr+j+1);
				anything_swapped=true;
			}
		}
		if(anything_swapped==false)
			return; // return if nothing was swapped in an iteration i.e. it's sorted before all iterations
		// so the complexity for an already sorted array =O(n)
	}
	
}

template<typename T>
bool is_greater(T a,T b){
	return a>b;
}

template<typename T>
bool is_smaller(T a,T b){
	return a<b;
}

template<typename T>
void print_array(T Arr[],int size){
	for(int i=0;i<size;i++){
		cout<<Arr[i]<<" ";
	}
	cout<<endl;
}
int main(){
	int int_array[]={9,8,7,6,5,4,3,2,1};
	int size=sizeof(int_array)/sizeof(int_array[0]);
	sort(int_array,size,is_greater);
	print_array(int_array,size);
	
	float float_array[]={0.2,-3.8,45,-2000,.6,89,-20.7};
	size=sizeof(float_array)/sizeof(float_array[0]);
	sort(float_array,size,is_smaller);
	print_array(float_array,size);
	
}