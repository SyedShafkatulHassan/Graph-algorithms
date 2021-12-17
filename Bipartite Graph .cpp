#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb push_back
int main()
{
    ll tc;
    cin>>tc;
    for(ll p=0; p<tc; p++)
    {
        int v,e;
        cin >>v>>e;
        vector<ll>graph[v];
        for(int i = 0; i<e; i++)
        {
            int u,v;
            cin>>u>>v;
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        ll f=1;
        for(ll i=0; i<e; i++)
        {
            ll colour[v];
            for(ll j=0; j<e; j++)
            {
                colour[j]=-1;
            }
            for(ll j=0; j<e; j++)
            {
                if(colour[j]==-1)
                {
                    queue<ll>q;
                    q.push(j);
                    colour[j]=1;
                    while(!q.empty())
                    {
                        ll n= q.front();
                        q.pop();
                        for(auto it : graph[n])
                        {
                            if(colour[it] == -1)
                            {
                                colour[it] = 1 - colour[n];
                                q.push(it);
                            }
                            else if(colour[it] == colour[n])
                            {
                                f=2;
                                cout<<"NO"<<endl;
                                break;
                            }
                        }
                        if(f==2)
                        {
                            break;
                        }
                    }
                    if(f==2)
                    {
                        break;
                    }
                }
                if(f==2)
                {
                    break;
                }
            }
            if(f==2)
            {
                break;
            }
        }
        if(f==1)
        {
            cout<<"YES"<<endl;
        }
    }
}

