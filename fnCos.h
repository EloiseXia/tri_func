/*
 * @Description: cos函数
 * @Author: Longjing Xia
 * @FilePath: \tri_func\fnCos.h
 * @Date: 2022-03-27 13:46:00
 * @LastEditTime: 2022-03-27 13:59:24
 */
#pragma once

#include "fnSin.h"

/**
 * @description: 实现cos函数计算
 * @param {bool} inputMode: 输入为角度时，inputMode为1；为弧度时，inputMode为0
 * @param {double} inputNum: 输入的x
 * @return {double} outputNum: 输出的cosx
 */
double fnCos(bool inputMode, double inputNum)
{
    double outputNum = 1;  //输出
    double coefficient = 1, denominator = 1, numerator = 1; //系数，分母，分子

    //判断输入是角度还是弧度
    if(inputMode)
    {
        inputNum = fMod(inputNum, 360);
        inputNum = inputNum / 180 * PI;
    }
    else   
    {
        inputNum = fMod(inputNum, 2*PI);
    }

    //进行麦克劳林展开式的计算
    for(int i = 1; i < 101; ++i)
    {
        numerator = numerator * inputNum;
        denominator = denominator * i;
        if(i % 2 == 0)
        {
            coefficient = -coefficient;
            outputNum += coefficient * numerator / denominator;
        }
    }

    //解决输出负0的问题
    if(outputNum< 0.0001 && outputNum >-0.0001)
    {
        outputNum = 0;
    }
    return outputNum;
}