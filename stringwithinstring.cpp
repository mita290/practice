#include<bits/stdc++.h>

using namespace std;

void compute(string pattern, int lps[]){
    int len=0;
    int i=1;
    int m=pattern.length();
    lps[0]=0;
    while(i<m){
        if(pattern[i]==pattern[len]){
            len++;
            lps[i]=len;
            i++;
        }
        else if(len!=0){
            len=lps[len-1];
        }
        else{
            lps[i]=0;
            i++;
        }
    }
}

int main(){
    string str,pat;
    cin>>str>>pat;
    int len=str.length();
    int plen=pat.length();

    int lps[plen];
    compute(pat,lps);
    int lpsindex=0, match=0;
    
    for(int index=0;index<len;){
        if(pat[index]==str[index]){
            lpsindex++;
            index++;
            if(lpsindex==plen){
                match++;
                lpsindex=0;
            }
        }
        else{
            if(lpsindex!=0){
                lpsindex=lps[lpsindex-1];
            }
            else{
                index++;
            }
        }
    }
    cout<<"Count="<<match;
    return 0;
}