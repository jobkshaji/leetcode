#include<iostream>
using namespace std;
#include<array>
int main(){
	array<int,10>Ak={'a','b','c','d','e','f','g','h','i','j'};
	cout<<"size of array"<< Ak.size()<< endl;
	cout<<"Element at index 2 using at():"<< Ak.at(2)<<endl;
	cout<<"element accessing using[] :" << Ak[3]<< endl;
	
	}
