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
    swap(data[first],data[(first+last)/2]);  //���߽�ֵ�ƶ���������
    while(lower<=upper)
    {
        while(data[lower]<bound)
            lower++;
        while(data[upper]>bound)
            upper--;
        if(lower<upper)
            swap(data[lower++],data[upper--]);  //����ҵ�һ��С�ںʹ��ڱ߽�ֵ����   ����н���
        else
            lower++;
    }
    swap(data[first],data[upper]);   //������н���   ��Ϊ�˽��߽�ֵ�����ֵ�Ѿ��ź��򣩷ŵ���������������֮��   ��Ϊ��ʱupperָ���һ���������һ����
    if(first<upper-1)
       Qsort(data,first,upper-1);   //Ȼ����еݹ�   �Ѵ�ʱ�ı߽�ֵ��upper����ȥ   ��Ϊ�Ѿ��ź�����
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
    swap(data[max],data[n-1]); //�ҳ����ֵ�ŵ�����ĩβ   ��ֹ����lower���������ĩ��
    Qsort(data,0,n-2);
}


//�ڶ����汾
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
