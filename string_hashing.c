//something wrong.


#include <stdio.h>
int mod = 100003,base = 26;
char str[100003];
int hash[100003] = {0};


int a_div_b_mod_m(int b)
{
	int ans = 1;
	int m = mod-2;
	while(m>0)
	{
		if(m%2==1)
		{
			ans = ((ans%mod)*(b%mod))%mod;
		}

		b = (b %mod)* (b %mod);
		
		b =b%mod;
		
		m >>1;
	}
	
	return ans;
}

void hashing(int n,int k)
{
	int i;
	int h=0;
	int b=1;
	while(i<k)
	{
		h = (h%mod + (b*str[i])%mod)%mod;
		b = ((b%mod)*base)%mod;
	
		i++;
	}
	
	hash[h] += 1;

	int div = a_div_b_mod_m(base);
	for(i=k;i<n;i++)
	{
		h = ((((h-str[i-k])%mod)*(div%mod))+ (str[i] * b)%mod)%mod;
		hash[h] += 1;
	}

	return;
}




void func(int k)
{
	char temp[100003];

	scanf("%s",temp);
	int i;
	int h=0;
	int b=1;

        while(i<k)
	{
		h = (h%mod + (b*str[i])%mod)%mod;
		b = b*base;
		i++;
	}
	
	printf("%d\n",hash[h]);
	
	return;
}


int main()
{
	int n,k,q,i;
	scanf("%d %d %d",&n,&k,&q);

	hashing(n,k);
	scanf("%s",str);

	for(i=0;i<q;i++)
	{
		func(k);
	}

	return 0;
}
