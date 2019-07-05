#include <iostream>

using namespace std;

void Heapsort(int buf[],int len);

int main(int argc, char *argv[])
{
     int buffer[10]={1,3,6,7,8,4,12,243,45,33};
     Heapsort(buffer,10);
     for(int i=0;i<10;++i)
         cout<<buffer[i]<<' ';
}


void HeapAdjust(int buf[],int start,int end)
{
    int c=start;
    int l=c*2+1;
    int temp=buf[c];
    for(;l<=end;c=l,l=2*l+1)
    {
        if(l<end && buf[l]<buf[l+1])
            l++;
        if(temp>=buf[l])
            break;
        else
        {
            buf[c]=buf[l];
            buf[l]=temp;
        }
    }
}



void Heapsort(int buf[],int len)
{
    int temp;
    for(int i=(len/2)-1;i>=0;--i)  //先构建大顶堆
        HeapAdjust(buf,i,len-1);
    for(int j=len-1;j>0;--j)     //进行排序
    {
        temp=buf[0];
        buf[0]=buf[j];
        buf[j]=temp;
        HeapAdjust(buf,0,j-1);
    }
}
