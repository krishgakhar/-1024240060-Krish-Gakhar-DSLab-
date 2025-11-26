#include<iostream>
#include<vector>
using namespace std;

int main(){

    int pq[100];
    int n = 0;

    auto show = [&](int m){
        for(int i=1;i<=m;i++){
            cout<<pq[i]<<"  ";
        }
        cout<<"\n";
    };

    pq[++n] = 20;
    int i = n;
    while(i>1){
        int p = i/2;
        if(pq[p] > pq[i]){
            swap(pq[p],pq[i]);
            i = p;
        } else break;
    }

    pq[++n] = 5;
    i = n;
    while(i>1){
        int p = i/2;
        if(pq[p] > pq[i]){
            swap(pq[p],pq[i]);
            i = p;
        } else break;
    }

    pq[++n] = 13;
    i = n;
    while(i>1){
        int p = i/2;
        if(pq[p] > pq[i]){
            swap(pq[p],pq[i]);
            i = p;
        } else break;
    }

    pq[++n] = 2;
    i = n;
    while(i>1){
        int p = i/2;
        if(pq[p] > pq[i]){
            swap(pq[p],pq[i]);
            i = p;
        } else break;
    }

    cout<<"pq   after   few inserts :  ";
    show(n);

    pq[1] = pq[n];
    n--;

    int k = 1;
    while(true){
        int l = k*2;
        int r = l+1;
        int mn = k;

        if(l<=n && pq[l] < pq[mn]) mn = l;
        if(r<=n && pq[r] < pq[mn]) mn = r;

        if(mn != k){
            swap(pq[k], pq[mn]);
            k = mn;
        } else break;
    }

    cout<<"after removing   top : ";
    show(n);

    pq[++n] = 7;
    i = n;
    while(i>1){
        int p = i/2;
        if(pq[p] > pq[i]){
            swap(pq[p],pq[i]);
            i = p;
        } else break;
    }

    cout<<"after  another insert : ";
    show(n);

    return 0;
}
