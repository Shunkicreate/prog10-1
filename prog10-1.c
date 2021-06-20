/*********************************************
  prog10-1.c
    Student ID: 26002002409
    Name: Shunki Tada
**********************************************/

#include <stdio.h>
#include <assert.h>
#include "sort-common.h"

void quick_sort(struct data data[], int num);

void quick_sort(struct data data[], int num)
{
    int pivot = (data[0].key + data[num].key) / 2;
    int i=0;
    int j=num-1;
    int lt = data[i].key;
    int rt = data[j].key;
    struct data mini_data;
    while(j-i>1){
        i=0;
        j=num-1;
        while(lt<pivot){
            i++;
            lt = data[i].key;
        }
        while(rt>pivot){
            j--;
            rt = data[j].key;
        }
        mini_data=data[j];
        data[j]=data[i];
        data[i]=mini_data;
        printf("j-i %d\n",j-i);
        printf("j %d\n",j);
        printf("i %d\n",i);

    }
    quick_sort(data,i);
    quick_sort(data+j,num-j);



}


/*=============================================*/

void test1()
{
    struct data data[] = {
        { 21, 'a' }, { 33, 'b' }, { 31, 'c' }, { 14, 'd' }, { 20, 'e' },
        {  1, 'f' }, { 24, 'g' }, { 12, 'h' }, { 10, 'i' }, { 15, 'j' }
    };
    int num = sizeof(data) / sizeof(data[0]);

    print(data, num);
    quick_sort(data, num);

    print(data, num);

    assert(is_sorted(data, num));

    printf("Success: %s\n", __func__);
}

int main()
{
    test1();

    return 0;
}
