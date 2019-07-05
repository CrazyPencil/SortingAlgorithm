#include <iostream>

using namespace std;

void swap(int &a,int &b);
void Qsort(int data[],int first,int last);
void QuickSort(int data[],int n);

void QUickSort(int data[],int low,int high);
int partition(int data[],int low,int high);


int main()
{
  int buffer[20]={1,5,3,6,8,2,7,10,9,0,34,53,2,14,15,17,35,8,4,23};
  QUickSort(buffer,0,19);
  for(int i=0;i<20;++i)
       cout<<buffer[i]<<' ';
}

void swap(int &a,int &b)
{
    int temp=0;
    temp=a;
    a=b;
    b=temp;
}


void Qsort(int data[],int first,int last)
{
    int lower=first+1;
    int upper=last;
    int bound=data[(first+last)/2];
    swap(data[first],data[(first+last)/2]);  //将边界值移动到数组首
    while(lower<=upper)
    {
        while(data[lower]<bound)
            lower++;
        while(data[upper]>bound)
            upper--;
        if(lower<upper)
            swap(data[lower++],data[upper--]);  //如果找到一组小于和大于边界值的数   则进行交换
        else
            lower++;
    }
    swap(data[first],data[upper]);   //这里进行交换   是为了将边界值（这个值已经排好序）放到两个独立的数组之间   因为此时upper指向第一个数组最后一个数
    if(first<upper-1)
       Qsort(data,first,upper-1);   //然后进行递归   把此时的边界值（upper）除去   因为已经排好序了
    if(upper+1 < last)
       Qsort(data,upper+1,last);

}


void QuickSort(int data[],int n)
{
    int max=0;
    if(n<2)
        return;
    for(int i=1;i<n;++i)
    {
        if(data[max]<data[i])
            max=i;
    }
    swap(data[max],data[n-1]); //找出最大值放到数组末尾   防止索引lower超出数组的末端
    Qsort(data,0,n-2);
}


//第二个版本
int partition(int data[],int low,int high)
{
    int pivot=data[low];
    while(low<high)
    {
        while(low<high && data[high]>=pivot)
            --high;
        data[low]=data[high];
        while(low<high && data[low]<=pivot)
            ++low;
        data[high]=data[low];
    }
    data[low]=pivot;
    return low;
}

void QUickSort(int data[],int low,int high)
{
    if(low<high)
    {
        int  pivotnum=partition(data,low,high);
        QUickSort(data,low,pivotnum-1);
        QUickSort(data,pivotnum+1,high);
    }

}
