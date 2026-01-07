#include<bits/stdc++.h>

using namespace std;

int n, visitIdx=0;
int a[2060], ret[1030];

void inorder(int idx){
    //cout<<"inorder: " << idx <<'\n';
    if(a[(idx*2)+1]) inorder((idx*2)+1);
    ret[idx] = a[visitIdx++];
    //cout<<ret[idx] <<'\n';
    if(a[(idx+1)*2])inorder((idx+1)*2);
    return;
} 

int main(){

    cin >> n;
    for(int i=0; i<pow(2,n)-1; i++){
        cin>>a[i];
    }

    inorder(0);

    for(int i=0; i<n; i++){
        for(int j=pow(2,i)-1; j<pow(2,i+1)-1; j++){
            cout<< ret[j] << " ";
        }
        cout << '\n';
    }

    return 0;
}

// i - j
// 0 - 0
// 1 - 1 2
// 2 - 3 4 5 6
// 3 - 7 8 9 10 11 12 13 14