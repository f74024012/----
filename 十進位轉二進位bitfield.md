----
====
#include <stdio.h>
#include <limits.h>

void bin32(struct data1 f);
void bin64(struct data1 d);
void bin_transfer32(char input2[],union data c,struct data1 d,struct data1 *ptr1);
void bin_transfer64(char input3[],union data k,struct data1 b,struct data1 *ptr1);
struct data1
{
        unsigned x:32;
        unsigned long long y:64;
};
union data
{
        float f;
        double d;
        unsigned a;
        unsigned long long u;

};


//unsigned long long x:32,y:32

//float aaa;

int main()
{
        struct data1 bin1;
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
         bin32( bin1);
     }
     if(input=='f'&&input1=='d')
         {
                printf("please enter a float number:");
                scanf("%lf",&bin.d);
                bin64(bin1);
     }
     if(input=='b'&&input1=='f')
         {
                printf("please enter a 32 bits pattern");
                scanf("%s,",input2);

                  bin_transfer32(input2,bin,bin1,&bin1);
                  //bin32((void *)&aaa);
         }
     if(input=='b'&&input1=='d')
     {
        printf("enter a 64 bits pattern");
        scanf("%s",input3);
        bin_transfer64(input3,bin,bin1,&bin1);
     }
         return 0;
}

         void bin32(struct data1 f)
    {


     unsigned mask=0x80000000U;
     unsigned value = f.x;
     while(mask){
                         printf("%d", (mask&value)!=0U);
           //printf("%f",bin.f);
           mask>>=1;
     }
                     //puts("");
    }
    void bin64(struct data1 d)
{
     unsigned long long mask=0x8000000000000000ULL;
     unsigned long long value = d.y;
     while(mask){
           printf("%d", (mask&value)!=0ULL);
           mask>>=1;
     }
     //puts("");
}
    void bin_transfer32(char input2[],union data c,struct data1 d,struct data1 *ptr1)
    {
        int i;
        ptr1->x;
        unsigned mask=0x80000000U;
        //float value;
        unsigned* ptr=(unsigned*) ptr1->x;
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
    void bin_transfer64(char input3[],union data k,struct data1 b,struct data1 *ptr1)
    {
        int i;
        ptr1->y;
                  unsigned long long mask=0x8000000000000000ULL;
        //double value;
        unsigned long long *ptr=(unsigned long long*) ptr1->y;
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









                                                                                   
