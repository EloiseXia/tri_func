/*
 * @Description: 
 * @Author: Longjing Xia
 * @FilePath: \tri_func\unit_test_fnSin.cpp
 * @Date: 2022-03-26 10:26:39
 * @LastEditTime: 2022-03-26 10:50:15
 */


#include "fnSin.h"
#include <stdio.h>
#include <assert.h>

int main()
{
    assert(fnSin(0, 3.14159) - 0 < 0.0001);
    assert(fnSin(0, 36.128285) + 1 < 0.0001);
    assert(fnSin(1, 720) == 0);
    assert(fnSin(1, -60) + 0.866 < 0.001);
    printf("all passed.\n");
}


