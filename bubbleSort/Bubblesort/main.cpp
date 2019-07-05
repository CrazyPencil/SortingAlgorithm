#include <iostream>

using namespace std;

void bubblesort(int buf[],int len);
void bubblesort2(int buf[],int len);
void Selectedsort(int buf[],int len);
void Insertsort(int buf[],int len);

int main(int argc, char *argv[])
{
    int buffer[10]={1,5,7,3,9,6,34,56,123,0};
    Insertsort(buffer,10);
    for(int i=0;i<10;++i)
        cout<<buffer[i]<<' ';
}


void bubblesort(int buf[],int len)  //最简单版冒泡
{
    for(int i=0;i<len;++i)
    {
        for(int j=len-2;j>=i;--j)    //这里要从后往前
        {
            if(buf[j]>buf[j+1])
            {
                int temp;
                temp=buf[j+1];
                buf[j+1]=buf[j];
                buf[j]=temp;
            }
        }
    }
}


void bubblesort2(int buf[],int len)  //优化版冒泡   加入标志位   避免不必要的比较
{
    bool flag=true;
    for(int i=0;i<len && flag;++i)
    {
        flag=false;
        for(int j=len-2;j>=i;--j)
        {
            if(buf[j]>buf[j+1])
            {
                int temp;
                temp=buf[j+1];
                buf[j+1]=buf[j];
                buf[j]=temp;
                flag=true;
            }
        }
    }
}


void Selectedsort(int buf[],int len)  //只比较  不交换  只有找到每次循环中最小的  在进行交换
{
   int min=0;
   for(int i=0;i<len-1;++i)
   {
       min=i;
       for(int j=i+1;j<=len-1;++j)
       {
           if(buf[min]>buf[j])
               min=j;
       }
       if(min!=i)
       {
           int temp;
           temp=buf[i];
           buf[i]=buf[min];
           buf[min]=temp;
       }
   }
}


void Insertsort(int buf[],int len)    //插入排序
{
    for(int i=1;i<len;++i)
    {
        if(buf[i]<buf[i-1])
        {
            int temp=buf[i];  //设置哨兵
            int j;
            for(j=i-1;buf[j]>temp && j>=0;--j)
                buf[j+1]=buf[j];
            buf[j+1]=temp;
        }
    }
}





















