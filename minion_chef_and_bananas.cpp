#include <bits/stdc++.h>
using namespace std;
int check(long int arr[],long int k,long int n,long int h)
{
    long int sum=0;

    for(int i=0;i<n;i++)
    {
        if(arr[i]<=k){
          sum+=1;

        }
        else{
          sum+=arr[i]/k;

          if((arr[i]%k)!=0)
             sum+=1;

        }

        if(sum>h)
        {

            return 0;
        }

    }


    return 1;
}
int main() {

    int t;
    cin>>t;

    while(t--)
    {

        long int n,h;
        cin>>n>>h;

        long int arr[n];

        for(int i=0;i<n;i++)
           cin>>arr[i];

        long int max=arr[0];
        for(int i=1;i<n;i++)
        {
            if(arr[i]>max)
                max=arr[i];
        }

        if(n==h)
          {
              cout<<endl<<max;
              continue;

          }


        long int low=1,high=max;


        while(high>=low)
        {
            long int mid = low+(high-low)/2;
            int valid =check(arr,mid,n,h);

            if((mid==1 || check(arr,mid-1,n,h)==0) && valid)
              {
                  cout<<endl<<mid;
                  break;
              }
            else if(!valid){
                low=mid+1;

            }
            else{
                high=mid-1;
            }
        }


    }

	return 0;
}
