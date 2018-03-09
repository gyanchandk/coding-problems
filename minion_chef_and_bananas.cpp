#include <bits/stdc++.h>
using namespace std;
int check(long int arr[],long int k,long int n,long int h)
{
    long int sum=0;
    for(int i=0;i<n;i++)
    {
        if(arr[i]<k)
          sum+=1;
        else
          sum+=ceil(arr[i]/k);

        if(sum>h)
        {
           cout<<"\nsum:"<<sum;
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

        //sort(arr,arr+n);

        if(n==h)
          {
              cout<<endl<<arr[n-1];
              continue;

          }

        long int low=1,high=arr[n-1];


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
