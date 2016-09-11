//
//  main.c
//  NN
//  Single Layer Perceptron to Identify Fruit
//  Created by Cino on 9/11/16.
//  Copyright © 2016 王c. All rights reserved.
//  Test passed on Sep 11

#include <stdio.h>
int sgn(float t){
    int r;
    if(t>=0) r=1;
    else r=-1;
    return r;
}
int main(int argc, const char * argv[]) {
    float x[4][3]={{1,121,16.8},{1,114,15.2},
                   {1,210,9.4},{1,195,8.1}};//input
    float w[3]={-1230,-30,300},yita=0.01;//weight
    int d[4]={1,1,-1,-1};//desired
    int y[4]={0,0,0,0};//output
    int i=0,k=0,counter=0;
    
    for(;i<=3;i++){
        y[i]=sgn(x[i][0]*w[0]+x[i][1]*w[1]+x[i][2]*w[2]);
        if(y[i]!=d[i]){
            for(k=0;k<=2;k++){
                w[k]=w[k]+yita*(d[i]-y[i])*x[i][k];
            }
            k=0;i=0;
            counter++;
        }
        if(counter>99){//for non-linear seperated
            printf("Error");
            break;
        }
    }
    for(i=0;i<=2;i++){
        printf("%f\n",w[i]);
    }
    printf("Coming Iroka\n");
    return 0;
}

