#include<stdio.h>
#include<string.h>
#define Max 20000
#define Hash 3007
#define  __int64 long long
int code[15],ch[15],mp[15][15],ex,ey,n,m,cur,ans,num;
char str[15];
inline int max(int a,int b){
    return a>b?a:b;
}
struct node{
    int size,next[Max],p[Hash],f[Max];
    __int64 state[Max];
    inline void init()    {
        memset(p,-1,sizeof(p));
        size=0;
    }
    inline void push(__int64 st,int val)    {
        int i,u=st%Hash;
        for(i=p[u];            i!=-1;            i=next[i])        {
            if(state[i]==st)            {
                if(val>f[i]) f[i]=val;
                return;
            }
        }
        state[size]=st;
        f[size]=val;
        next[size]=p[u];
        p[u]=size++;
    }
}
    dp[2];
inline void decode(__int64 st){
    memset(ch,0,sizeof(ch));
    num=st&7;
    st>>=3;
    for(int i=m;        i>=0;        i--)    {
        code[i]=st&7;
        st>>=3;
    }
}
inline __int64 encode(){
    __int64 st=0;
    int cnt=1;
    memset(ch,-1,sizeof(ch));
    ch[0]=0;
    for(int i=0;        i<=m;        i++)    {
        if(ch[code[i]]==-1)            ch[code[i]]=cnt++;
        st<<=3;
        st|=ch[code[i]];
    }
    st<<=3;
    st|=num;
    return st;
}
inline void shift(){
    for(int k=0;        k<dp[cur].size;        k++)    {
        num=dp[cur].state[k]&7;
        dp[cur^1].push((dp[cur].state[k]>>3)|num,dp[cur].f[k]);
    }
}
inline void dpblank(int i,int j){
    int k,l,left,up;
    for(k=0;        k<dp[cur].size;        k++)    {
        int tmp=dp[cur].f[k]+mp[i][j];
        decode(dp[cur].state[k]);
        left=code[j-1],up=code[j];
        if(left&&up)        {
            if(left!=up)            {
                code[j-1]=code[j]=0;
                for(l=0;                    l<=m;                    l++)                    if(code[l]==up)                        code[l]=left;
                dp[cur^1].push(encode(),tmp);
            }
        }
        else if(left||up)        {
            if(mp[i][j+1])            {
                code[j-1]=0;
                code[j]=left+up;
                dp[cur^1].push(encode(),tmp);
            }
            if(mp[i+1][j])            {
                code[j-1]=left+up,code[j]=0;
                dp[cur^1].push(encode(),tmp);
            }
            if(num<2)            {
                num++;
                code[j-1]=code[j]=0;
                dp[cur^1].push(encode(),tmp);
            }
        }
        else        {
            code[j-1]=code[j]=0;
            dp[cur^1].push(encode(),dp[cur].f[k]);
            if(mp[i][j+1]&&mp[i+1][j])            {
                code[j-1]=code[j]=7;
                dp[cur^1].push(encode(),tmp);
            }
            if(num<2)            {
                num++;
                if(mp[i][j+1])                {
                    code[j-1]=0,code[j]=7;
                    dp[cur^1].push(encode(),tmp);
                }
                if(mp[i+1][j])                {
                    code[j-1]=7,code[j]=0;
                    dp[cur^1].push(encode(),tmp);
                }
            }
        }
    }
}
void solve(){
    int i,j,k;
    cur=0;
    dp[0].init();
    dp[0].push(0,0);
    for(i=1;        i<=n;        i++)    {
        dp[cur^1].init();
        shift();
        cur^=1;
        for(j=1;            j<=m;            j++)        {
            if(mp[i][j])            {
                dp[cur^1].init();
                dpblank(i,j);
                cur^=1;
            }
        }
    }
    for(k=0;        k<dp[cur].size;        k++)        if(ans<dp[cur].f[k])            ans=dp[cur].f[k];
    printf("%d\n",ans);
}
int main(){
    int i,j,t;
    //  freopen("D:/out.txt","w",stdout);
    scanf("%d",&t);
    while(t--)    {
        ans=0;
        scanf("%d%d",&n,&m);
        ex=0;
        memset(mp,0,sizeof(mp));
        for(i=1;  i<=n;  i++)
            for(j=1; j<=m; j++) {
                scanf("%d",&mp[i][j]);
                ans=max(ans,mp[i][j]);
            }
        solve();
    }
    return 0;
}

