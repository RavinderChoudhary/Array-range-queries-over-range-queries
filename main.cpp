#include <bits/stdc++.h>
using namespace std;

int main() {
	vector<int> a = { 3, 4, 2, 2, 4, 6 }; 
    int n = a.size(); 
   
    vector<vector<int> > query = { { 1, 1, 2 }, { 1, 4, 5 },  
                          { 2, 1, 2 }, { 2, 1, 3 }, 
                          { 2, 3, 4 } 
                        }; 
    int q = query.size();
    vector<int> presum(q+1,0);
    for(int i=q-1;i>=0;i--){
        if(query[i][0] == 2){
            vector<int> tmp(q+1,0);
            int l = query[i][1]-1 , r = query[i][2]-1;
            tmp[l] = 1 , tmp[r+1] = -1;
            int val;
            int sum = 0;
            for(int j=0;j<=q;j++){
              presum[j] += tmp[j];
              
              sum += presum[j];
              if(j == i)
               val = sum;
            }
        
            presum[l] += val;
            presum[r+1] -= val;
        }
    }
    
    int sum = 0;
    for(int i=0;i<=q;i++){
      if(presum[i] < 0){  presum[i] = 0; continue; }
      sum += presum[i];
      presum[i] = sum;
    }
    
    for(int i=0;i<q;i++)
      if(query[i][0] == 1)
        presum[i] += 1;
    
    vector<int> final_presum(n+1,0);
    for(int i=0;i<q;i++){
        if(presum[i] != 0){
            int val = presum[i];
            int l = query[i][1]-1,r = query[i][2]-1;
            final_presum[l] += val;
            final_presum[r+1] -= val;
        }
    }
    
    sum = 0;
    for(int i=0;i<n;i++){
      sum += final_presum[i];
      cout<<sum<<" ";
    }
	return 0;
}
