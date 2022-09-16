#include <iostream>
using namespace std;

void hello(){
	printf("hello/n");
	hello();
	//printf("hello\n");
}

int main()
{
	hello();
}



