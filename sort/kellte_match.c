#include <stdio.h>
#include "mylib.h"

typedef struct kettle{
    int i;//初始下标
    int volume;//容量 
}Kettle;

int partition(Kettle *reb, Kettle *blue, int p, int r);
void blue_red_quick_sort( Kettle *blue, Kettle *red, int p, int r);
void kettle_swap(Kettle *a, Kettle *b);
void printf_arr(int *a, int len);

int main() {
    int a[10] = {1,2,3,4,5,6,7,8,9,10};
    Kettle red[10], blue[10];
    int i;
    srand((int)time(0));
    shuffle(a, 10);
    printf_arr(a, 10);
    for(i=0; i<10; i++){
        red[i].i = i+1;
        red[i].volume = a[i];
    }
    shuffle(a, 10);
    printf_arr(a, 10);
    for(i=0; i<10; i++){
        blue[i].i = i+1;
        blue[i].volume = a[i];
    }
    blue_red_quick_sort(red, blue, 0 , 9);//排序
    for(i=0; i<10; i++){
        printf("red[%d] = blue[%d] = %d\n", red[i].i, blue[i].i, red[i].volume);
    } 
    return 0;
}

void blue_red_quick_sort( Kettle *red, Kettle *blue, int p, int r){
    int q;
    if(p < r){
        q = partition(red, blue, p, r);
        blue_red_quick_sort(red, blue, p, q-1);
        blue_red_quick_sort(red, blue, q+1, r);
    }
}

int partition(Kettle *red, Kettle *blue, int p, int r){
    int red_key_index = random_val(p, r+1);//作为红色水壶划分key的下标 
    int blue_key_index;//作为蓝色水壶划分key的下标 
    int blue_key = red[red_key_index].volume; //蓝色水壶的划分key ，从红色中随机选取的分隔元素,做蓝色的分隔元素
    int red_key;//红色水壶的划分key 
    
    int i,j;

    for(j=p; j<=r; j++){
        if(blue_key == blue[j].volume){
            blue_key_index = j;
            break;
        }
    }
    red_key = blue[blue_key_index].volume;
    kettle_swap( blue+blue_key_index, blue+r);
    kettle_swap( red+red_key_index, red+r);
    
    //以下，对红色水壶进行划分 
    i = p-1;
    for(j=p; j<r; j++){
        if( red[j].volume < red_key ){
            i = i+1;
            kettle_swap( red+i, red+j );
        }
    }
    kettle_swap( red+i+1, red+r);
    
    //以下，对蓝色水壶进行划分 
    i = p-1;
    for(j=p; j<r; j++){
        if( blue[j].volume < blue_key ){
            i = i+1;
            kettle_swap( blue+i, blue+j );
        }
    }
    kettle_swap( blue+i+1, blue+r );
    return i+1;
}

void kettle_swap(Kettle *a, Kettle *b){
    Kettle temp  = *a;
    *a = *b;
    *b = temp;
}

void printf_arr(int *a, int len){
    int i=0;
    printf("[");
    for(i=0; i<len; i++){
        printf("%d ", a[i]);
    }
    printf("]\n");
}
