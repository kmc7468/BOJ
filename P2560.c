#define R(a)((a)%1000+1000)%1000
#define s p[i-1]+p[i-a]
#define t s-p[i-b]
p[1000001],i;main(a,b,d,n){scanf("%d%d%d%d",&a,&b,&d,&n);for(;i<=n;++i)p[i]=R(i<a?1:(i<b?s:t-(i==d)));printf("%d",p[n]);}