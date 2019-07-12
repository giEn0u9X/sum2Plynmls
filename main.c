//
//  main.c
//  arrayDuoXiangShi
//
//  Created by 傅易欢 on 19/7/10.
//  Copyright © 2019年 Fu Yihuan. All rights reserved.
//

/*
 1.题目内容:
 一个多项式可以表达为 x 的各次幂与系数乘积的和,比如:
 2χ6+3χ5+12χ3+6χ+20 现在,你的程序要读入两个多项式,然后输出这两个多项式的和,也就是把对应的幂上的系 数相加然后输出。
 程序要处理的幂最大为 100。
 输入格式:
 总共要输入两个多项式,每个多项式的输入格式如下: 每行输入两个数字,第一个表示幂次,第二个表示该幂次的系数,所有的系数都是整数。
 第一行一定是最高幂,最后一行一定是 0 次幂。 注意第一行和最后一行之间不一定按照幂次降低顺序排列;如果某个幂次的系数为 0,
 就不出现在输入数据中了; 0 次幂的系数为 0 时还是会出现在输入数据中。
 输出格式:
 从最高幂开始依次降到 0 幂,如:
 2x6+3x5+12x3-6x+20
 注意其中的 x 是小写字母 x,而且所有的符号之间都没有空格,如果某个幂的系数为 0 则 不需要有那项。
 输入样例:
 6  2
 5  3
 3  12
 1  6 
 0  20
 
 
 6  2
 5  3
 2  12
 1  6 
 0  20
 
 
 样例:
 4x6+6x5+12x3+12x2+12x+40
 
 */

/*
 
 请输入多项式a：
 6 2
 5 3
 3 12
 1 6
 0 20
 change 00.	change 00.	aHang = 7
 请输入多项式b：
 6 2
 5 3
 2 12
 1 6
 0 20
 change 00.	change 00.	bHang = 7
 4x^6 + 6x^5 + 12x^3 + 12x^2 + 12x + 40
 Program ended with exit code: 0
 
 
 */





#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

const int lie = 2;

int qmax(int x,int y);
void inputDXS(int maxhang,int xDXS[][lie],int* xHang);
void changeoo(int xDXS[][2],int* xHang);
void shuchuArray(int x[][lie],int* xHang);
void sumDXS(int a[][lie],int* aHang,int b[][lie],int* bHang,int c[][lie],int cHang);
void prntDXS(int c[][lie],int cHang);

int main(int argc, const char * argv[]) {
    const int maxHang = 101;
    int aHang;
    aHang = maxHang;
    int bHang;
    bHang = maxHang;
    int a[aHang][lie];
    int b[bHang][lie];
    int c[][lie] = {0};
    int cHang;
    
    
    
    inputDXS(maxHang,a,&aHang);
    printf("aHang = %d\n",aHang);
    changeoo(a,&aHang);
    shuchuArray(a, &aHang);
    
    inputDXS(maxHang, b,&bHang);
    printf("bHang = %d\n",bHang);
    changeoo(b,&bHang);
    shuchuArray(b, &bHang);
    
    cHang = qmax(aHang,bHang);
    sumDXS(a, &aHang, b, &bHang, c, cHang);
    printf("cHang = %d\n",cHang);
    shuchuArray(c, &cHang);
    prntDXS(c, cHang);
    
    
    return 0;
}


int qmax(int x,int y){
    int ret=x;
    if(y>x)ret=y;
    return ret;
}

void inputDXS(int maxhang,int xDXS[][lie],int* xHang){
    *xHang = maxhang;
    //xDXS = xDXS[xHang][lie];
    //xDXS = (int *)malloc(sizeof(int*)*xHang*lie);
    printf("请输入多项式：(幂次 系数)\n");
    for(int i=0;i<*xHang || i<maxhang;i++){
        scanf("%d %d",&xDXS[i][0],&xDXS[i][1]);
        if(i==0)*xHang=xDXS[0][0]+1;
        if(xDXS[i][0]==0){
            for(int j=i+1;j<*xHang;j++){
                xDXS[j][0]=xDXS[j][1]=0;
            }
            break;
        }
    }
}

void changeoo(int xDXS[][2],int* xHang){
    bool isOcuped[*xHang];
    for(int i=0;i<*xHang;i++){   //给isOcupedA赋值 默认为0
        isOcuped[i] = 0;
    }
    //系数不为1的，bool值（占用）改为1
    for(int i=0;i<*xHang;i++){
        if((xDXS[i][0]<*xHang && xDXS[i][0]>=0 ) && xDXS[i][1]!=0)  isOcuped[xDXS[i][0]] = 1;
        //printf("change bool.\t");
    }
    //改变0,0-->n,0
    for(int i=0;i<*xHang;i++){
        if(xDXS[i][0]==0 && xDXS[i][1]==0){
            //printf("00,00.\t");
            for(int j=0;j<*xHang;j++){
                if(isOcuped[j]==0) {
                    //printf("change 00.\t");
                    xDXS[i][0] = j;        //printf("a[%d][0]=%d\n",i,j);
                    isOcuped[j] = 1;   //printf("isOcupedA[%d]=%d\n",j,(int)isOcupedA[j]);
                    break;
                }
            }
        }
    }
    
}


void shuchuArray(int x[][lie],int* xHang){
    //输出
    for(int i=0;i<*xHang;i++){
        printf("[%d]: ",i);
        for(int j=0;j<lie;j++){
            printf("%d\t",x[i][j]);
        }
        printf("\n");
    }

}


void sumDXS(int a[][lie],int* aHang,int b[][lie],int* bHang,int c[][lie],int cHang){
    //计算两多项式的和
    
    for(int i=0;i<*aHang;i++){    //每一行a----a[i]
        for(int j=0;j<*bHang;j++){
            if(a[i][0]==b[j][0]){
                c[i][0]=a[i][0];
                c[i][1]=a[i][1]+b[j][1];
            }
        }
    }
    //按幂次降序排列c的各行
    for(int i=0;i<cHang-1;i++){
        for(int j=i+1;j<cHang;j++){
            if(c[i][0]<c[j][0]){
                int temp[lie];
                temp[0] = c[i][0];  temp[1] = c[i][1];
                c[i][0] = c[j][0];  c[i][1] = c[j][1];
                c[j][0] = temp[0];  c[j][1] = temp[1];
            }
        }
    }

}

void prntDXS(int c[][lie],int cHang){
    //输出c多项式
    for(int i=0;i<cHang;i++){
        if(c[i][0]>1 && c[i][1]!=0)
            printf("%dx^%d + ",c[i][1],c[i][0]);
        else if(c[i][0]==1 && c[i][1]!=0)
            printf("%dx + ",c[i][1]);
        else if(c[i][0]==0)
            printf("%d\n",c[i][1]);
        else;
    }
}
