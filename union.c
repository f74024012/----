#include <stdio.h>
#include <limits.h>
union data /* union must be declared before use */
{
    float f;
    double d;
    unsigned a;
    unsigned long long u;
};
void bin32(union data f);
void bin64(union data d);
void bin_transfer32(char input2[],union data c);
void bin_transfer64(char input3[],union data k);

//unsigned long long x:32,y:32

//float aaa;

int main()
{
    union data bin;
    int i;
    float f=0.0f;
    double d;
    unsigned u;
    unsigned mask;
    char input,input1,input2[33],input3[65];


    printf("input bit pattern or float?<b,f>");
    scanf("%c",&input);

    printf("what do you want,float or double?<f,d>");
    scanf(" %c",&input1);


    if(input=='f'&&input1=='f')
    {
	printf("please enter a float number:");
	scanf("%f",&bin.f);
	bin32( bin);
    }
    if(input=='f'&&input1=='d')
    {
	printf("please enter a float number:");
	scanf("%lf",&bin.d);
	bin64(bin);
    }
    if(input=='b'&&input1=='f')
    {
	printf("please enter a 32 bits pattern");
	scanf("%s,",input2);

	bin_transfer32(input2,bin);
	//bin32((void *)&aaa);
    }
    if(input=='b'&&input1=='d')
    {
	printf("enter a 64 bits pattern");
	scanf("%s",input3);
	bin_transfer64(input3,bin);
    }
    return 0;
}

void bin32(union data f)
{


    unsigned mask=0x80000000U;
    unsigned value = f.a;
    while(mask){
	printf("%d", (mask&value)!=0U);
	//printf("%f",bin.f);
	mask>>=1;
    }
    //puts("");
}
void bin64(union data d)
{
    unsigned long long mask=0x8000000000000000ULL;
    unsigned long long value = d.u;
    while(mask){
	printf("%d", (mask&value)!=0ULL);
	mask>>=1;
    }
    //puts("");
}
void bin_transfer32(char input2[],union data c)
{
    int i;
    unsigned mask=0x80000000U;
    //float value;
    unsigned* ptr=(unsigned*)&c.a;
    *ptr=0u;
    //unsigned mask=1U<<31;

    for(i=0;i<32;i++)
    {
	if(input2[i]=='1')
	{
	    *ptr=*ptr|mask;
	}
	mask>>=1;
    }
    printf("%f\n",c.f);
    //aaa=value;
}
void bin_transfer64(char input3[],union data k)
{
    int i;
    unsigned long long mask=0x8000000000000000ULL;
    //double value;
    unsigned long long *ptr=(unsigned long long*)&k.u;
    *ptr=0lu;
    for(i=0;i<64;i++)
    {
	if(input3[i]=='1')
	{
	    *ptr=*ptr|mask;

	}
	mask>>=1;
    }
    printf("%lf\n",k.d);
}









