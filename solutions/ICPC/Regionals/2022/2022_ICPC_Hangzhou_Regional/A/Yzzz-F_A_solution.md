Tags:数论，裴蜀定理

Auther : Yzzz-F

题解：

这道题我们要选择一个s和d，令最终的结果ans=(sum+s * n+ n * (n+1)/2 * d),令ans%m的值最小

首先sum%m的情况我们知道，

对于  s * n+ n * (n+1)/2 * d  由于s与d由我们支配，那么根据裴蜀定理，这个式子一定是n和 n * (n+1)/2 的gcd的倍数  我们令g=gcd(n,n * (n+1)/2),那么结果就是 $k_1 * g$ ,

我么令最终的ans%m的余数为res  ，那么有 $res=ans - k_2 * m$ 

即 $res-sum= k_1 * g +k_2 * m$ 

然后用exgcd求解即可

​	 

