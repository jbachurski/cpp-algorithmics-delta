ain(m,a,i,n,p)
{
    for(i -= i; i < m; i = i - (-1))
    {
        for(a -= a; a < (n<<1)-(-1); a = a - (-1))
        {
            p=(((n-a<=i)-(-(a-n<=i)))-1 == 1);
            putchar((1<<(1-(-1)-(-1)-(-1)-(-1)))-(-((p-(-p)-(-p)-(-p)-(-p))<<1)));
        }
        putchar((1-(-1)-(-1)-(-1)-(-1))<<1);
    }
}
main(m,a,i,n,p,u,t)
{
    n -= n;
    u = (((1<<1)-(-1))<<1<<1<<1<<1);
    p = ((1<<1<<1<<1<<1<<1) - (-(1<<1<<1<<1<<1)) - (-(1<<1<<1<<1)) - (-1));
    for(t = getchar(); (u <= t) - (-(t <= p))-1==1; t = getchar())
    {
        n = (((n << 1) << 1) << 1) - (-(n << 1));
        n -= u - t;
    }
    ain(n,a,i,n);
    ain(n-(-1),a,i,n);
    ain(1,a,i,n);
    ain(1,a,i,n);
}
