#include <iostream>
#include <vector>
using namespace std;
const int prime = 101;
vector<int>rabinKarp(string txt,string pat)
{
    int n = txt.length();
    int m = pat.length();
    int hashTxt = 0 ,hashPat = 0;
    int h = 1;
    vector<int>pos;
    for(int i=0;i < m-1;i++){
        h = (h*prime)%prime;
    }
    for(int i=0 ; i < m;i++){
        hashTxt = (prime*hashTxt + txt[i])%prime;
        hashPat = (prime*hashPat + pat[i])%prime;
    }
    for(int i = 0;i <= n-m ; i++){
        if(hashTxt == hashPat){
            bool match = true;
            for(int j=0; j < m ; j++){
                if(txt[i+j] != pat[j]){
                    match = false;
                    break;
                }
            }
            if(match){
                pos.push_back(i);
            }
        }
        if(i<n-m){
            hashTxt = (prime*(hashTxt - txt[i]*h)+txt[m+i])% prime;
            if (hashTxt < 0)
                hashTxt += prime;
        }
    }
    return pos;
}


int main()
{
    string txt,pat;
    cout<<"enter text :";
    getline(cin,txt);
    cout<<"enter pattern :";
    getline(cin,pat);

    vector<int>position = rabinKarp(txt,pat);
    if(position.empty()){
        cout<<"not found pattern in position"<<endl;
    }else{
       cout<<"position:";
       for(int p : position){
         cout<<  p <<" ";
       }
       cout<<endl;
    }

}
