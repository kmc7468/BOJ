#define R(a,b)((a)%b+b)%b
#define s p[i-1]+p[i-a]
p[1000001],i;main(a,b,d,n){scanf("%d%d%d%d",&a,&b,&d,&n);for(;i<=n;++i)p[i]=R(i<a?1:s-(i<b?0:p[i-b]+(i==d)),1000);printf("%d",p[n]);}