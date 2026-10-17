#include<iostream>
#include<string>
using namespace std;
string getHint(string secret, string guess) {
        int bulls = 0;
        int cows = 0;
        int freq[10] = {0};
        for(int i=0;i<secret.size();i++){
            freq[secret[i]-'0']++;
        }
        for(int i=0,j=0;i<secret.size() && j<guess.size();i++,j++){
            if(secret[i] == guess[i]){
                bulls++;
                freq[secret[i]-'0']--;
            }
        }
        for(int i=0;i<guess.size();i++){
            if(freq[guess[i]-'0'] > 0 && guess[i] != secret[i]){
                cows++;
                freq[guess[i]-'0']--;
            }
        }
        string ans = to_string(bulls) + "A" + to_string(cows) + "B";
        return ans;
}
int main(){
string secret = "1807";
string guess = "7810";
cout<<getHint(secret,guess)<<endl;
return 0;
}