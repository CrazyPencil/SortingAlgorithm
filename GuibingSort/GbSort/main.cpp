#include <iostream>

using namespace std;

void merge(int data[],int first,int last);
void GuiBingsort(int data[],int first,int last);

int main()
{
  int buffer[10]={1,5,7,9,2,4,67,3,13,45};
  GuiBingsort(buffer,0,9);
  for(int i=0;i<10;++i)
      cout<<buffer[i]<<' ';
}


void merge(int data[],int first,int last)   //将两个已排好序的数组合并成一个有序数组
{
    int temp[last+1];
    int middle=(first+last)/2;
    int i1=0,i2=first,i3=middle+1;
    while(i2<=middle  &&  i3<=last)
    {
        if(data[i2]<data[i3])
            temp[i1++]=data[i2++];
        else
            temp[i1++]=data[i3++];
    }
    while(i2<=middle)
        temp[i1++]=data[i2++];
    while(i3<=last)
        temp[i1++]=data[i3++];
    for(int i=0;i<i1;++i)
        data[first+i]=temp[i];
}

void GuiBingsort(int data[],int first,int last)
{
    if(first<last)
    {
        int mid=(first+last)/2;
        GuiBingsort(data,first,mid);    //先进行划分子数组
        GuiBingsort(data,mid+1,last);
        merge(data,first,last);
    }
}
