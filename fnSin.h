/*
 * @Description: sin函数
 * @Author: Longjing Xia
 * @FilePath: \tri_func\fnSin.h
 * @Date: 2022-03-26 09:35:07
 * @LastEditTime: 2022-03-26 10:39:08
 */
#pragma once

#define PI (3.1415926)

/**
 * @description: 实现浮点型数据的取余操作
 * @param {double} dividend:被除数
 * @param {double} divisor：除数
 * @return {double} reminder: 余数
 */
double fMod(double dividend, double divisor)
{
    double quotient, reminder; //中间变量，余数
    if(divisor  == 0.00)
        return 0.00;
    quotient = int (dividend/divisor);
    reminder = dividend - quotient * divisor ;

    //解决余数为负的问题
    if((dividend < 0.00) != (divisor  < 0.00))
        reminder = reminder -divisor;
    return reminder;
}


/**
 * @description:  实现sin函数计算
 * @param {bool} inputMode:  输入为角度时，inputMode为1；为弧度时，inputMode为0
 * @param {double} inputNum: 输入的x
 * @return {double} outputNum: 输出的sinx
 */
double fnSin(bool inputMode, double inputNum)
{
    double outputNum = 0;  //输出
    double coefficient = -1, denominator=1, numerator = 1; //系数，分母，分子

    //判断输入是角度还是弧度
    if(inputMode)
    {
        inputNum = fMod(inputNum, 360);
        inputNum = inputNum/180 *PI;
    }
    else   
    {
        inputNum = fMod(inputNum, 2*PI);
    }

    //进行麦克劳林展开式的计算
    for(int i =1; i<100; ++i)
    {
        numerator = numerator * inputNum;
        denominator = denominator *i;
        if((i-1) % 2 == 0)
        {
            coefficient = -coefficient;
            outputNum += coefficient*numerator/denominator;
        }
    }

    //解决输出负0的问题
    if(outputNum< 0.0001 && outputNum >-0.0001)
    {
        outputNum = 0;
    }
    return outputNum;
}