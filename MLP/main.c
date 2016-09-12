//
//  main.c
//  MLP
//  Multi Layer Perceptron
//  Created by Cino on 9/12/16.
//  Copyright © 2016 Cino. All rights reserved.
//

#include <stdio.h>
#include <math.h>

float signoid(float in){
    float out;
    out=1/(1+exp(-in));
    return out;
}

float signoiddash(float in){
    float out;
    out=signoid(in)*(1-signoid(in));
    return out;
}

int main(int argc, const char * argv[]) {
    float x[2][2]={{1,1},{0.1,0.9}};
    float v[3]={0};
    float y[3]={1,0,0};
    float w[4][2]={{0.1,0.1},{-0.2,0.1},{-0.1,0.3},{0.2,0.3}};
    float w_[4][2]={{0.1,0.1},{-0.2,0.1},{-0.1,0.3},{0.2,0.3}};
    float gradient[3]={0},mid=0;
    float b3=0.2,b3_=0,y3=0,yita=0.25,alpha=0.0001,target=0.9,e=0;
    int counter=0;

    while(500-counter){
/////////////input and output of neurons, error//////////
    v[0]=x[0][0]*w[0][0]+x[1][0]*w[1][0]+x[1][1]*w[1][1];
    v[1]=x[0][1]*w[0][1]+x[1][0]*w[2][0]+x[1][1]*w[2][1];
    y[1]=signoid(v[0]);
    y[2]=signoid(v[1]);
    v[2]=b3*y[0]+y[1]*w[3][0]+y[2]*w[3][1];
    y3=signoid(v[2]);
    e=target-y3;
/////////////local gradients/////////////////////////////
    gradient[2]=signoiddash(v[2])*e;
    gradient[0]=signoiddash(v[0])*(gradient[2]*w[3][0]);
    gradient[1]=signoiddash(v[1])*(gradient[2]*w[3][1]);
/////////////weights adjusting///////////////////////////
    w_[3][0]=w[3][0]+alpha*w_[3][0]+yita*gradient[2]*y[1];
    mid=w[3][0];w[3][0]=w_[3][0];w_[3][0]=mid;
    w_[3][1]=w[3][1]+alpha*w_[3][1]+yita*gradient[2]*y[2];
    mid=w[3][1];w[3][1]=w_[3][1];w_[3][1]=mid;
    w_[1][0]=w[1][0]+alpha*w_[1][0]+yita*gradient[0]*x[1][0];
    mid=w[1][0];w[1][0]=w_[1][0];w_[1][0]=mid;
    w_[2][0]=w[2][0]+alpha*w_[2][0]+yita*gradient[1]*x[1][0];
    mid=w[2][0];w[2][0]=w_[2][0];w_[2][0]=mid;
    w_[1][1]=w[1][1]+alpha*w_[1][1]+yita*gradient[0]*x[1][1];
    mid=w[1][1];w[1][1]=w_[1][1];w_[1][1]=mid;
    w_[2][1]=w[2][1]+alpha*w_[2][1]+yita*gradient[1]*x[1][1];
    mid=w[2][1];w[2][1]=w_[2][1];w_[2][1]=mid;
    b3_=b3+alpha*b3_+yita*gradient[2]*y[0];
    mid=b3;b3=b3_;b3_=mid;
    w_[0][0]=w[0][0]+alpha*w_[0][0]+yita*gradient[0]*x[0][0];
    mid=w[0][0];w[0][0]=w_[0][0];w_[0][0]=mid;
    w_[0][1]=w[0][1]+alpha*w_[0][1]+yita*gradient[1]*x[0][1];
    mid=w[0][1];w[0][1]=w_[0][1];w_[0][1]=mid;
        counter++;
    }
/////////////print and examine///////////////////////////
    printf("%f\n",e);
//    printf("%f\n",gradient[2]);
//    printf("%f\n",gradient[0]);
//    printf("%f\n",gradient[1]);
    printf("Coming, Iroka!\n");
    return 0;
}
