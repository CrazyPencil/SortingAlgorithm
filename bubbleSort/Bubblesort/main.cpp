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


void bubblesort(int buf[],int len)  //��򵥰�ð��
{
    for(int i=0;i<len;++i)
    {
        for(int j=len-2;j>=i;--j)    //����Ҫ�Ӻ���ǰ
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


void bubblesort2(int buf[],int len)  //�Ż���ð��   �����־λ   ���ⲻ��Ҫ�ıȽ�
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


void Selectedsort(int buf[],int len)  //ֻ�Ƚ�  ������  ֻ���ҵ�ÿ��ѭ������С��  �ڽ��н���
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


void Insertsort(int buf[],int len)    //��������
{
    for(int i=1;i<len;++i)
    {
        if(buf[i]<buf[i-1])
        {
            int temp=buf[i];  //�����ڱ�
            int j;
            for(j=i-1;buf[j]>temp && j>=0;--j)
                buf[j+1]=buf[j];
            buf[j+1]=temp;
        }
    }
}





















