#include<stdio.h>
#include<math.h>

int main()
{
	int N, i, j, r, n, d;
	int sqrt_N;
	printf("请输入您想判断的数字：");
	scanf("%d", &N);
	sqrt_N = sqrt(N);
	if (N <= 0)
		printf("请输入正整数");
	else if (N == 1)
		printf("1既不是质数也不是合数\n");
	else if(N > 1)
		for (i = 1; i <= sqrt_N ; i++) //i为试除数，从1开始遍历到根号N，检查每个数字是否是N的因数(埃拉托色尼筛法)
		{ 
			if (N % i == 0 && i != 1) 
			{
				printf("%d不是质数\n%d的因数有:\n", N, N);
				for (j = 1; j <= N; j++) 
				{
					if (N % j == 0) //找出N的因数j
						printf("%d\n", j);
				}
				//接下来找N的质因数
				printf("其中质因数有:\n"); 
				for (j = 1; j <= N; j++) 
				{
					if (N % j == 0) //找出N的因数
					{ 
						for (i = 2; i <= j; i++) //i为试除数，用于接下来找出质因数j
						{ 
							if (i == j) 
							{
								printf("%d ", j); //找到质因数j
								n = N; //对n重新赋值
								r = 0; //对r重新赋值
								for (d = 0; r == 0; d++) 
								{ //循环计算n，即N整除每个质因数的次数，得到每个质因数的个数
									r = n % j;
									if (r == 0)
										n = n / j;
									else
										break;
								}
								printf("其个数为%d\n", d);
							}
							if (j % i == 0 )
								break;
						}
					}
				}
				break;	
			}
			if (i == sqrt_N) 
			{
				printf("\n%d是质数", N);
				break;
			}
		}
	else
		printf("请正确输入数字!");

	return 0;
}