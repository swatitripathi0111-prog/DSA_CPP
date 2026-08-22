#include<iostream>
using namespace std;
int FriendPairing(int n){
    if(n == 1 || n == 2){
        return n;
    }
    return FriendPairing(n-1) + (n-1)*FriendPairing(n-2);
}
int main(){
cout<<FriendPairing(4)<<endl;
 return 0;
}