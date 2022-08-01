#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(void){

    string arr;
    int count = 0;

    freopen("names.txt", "r", stdin);
    
    for(int i=0; i<30; i++){
        getline(cin, arr);
        
        for(int j=0; j<arr.size(); j++){
            if(arr[j]=='M'){
                count++;
            }
        }
    }


    cout << count << endl;
}
