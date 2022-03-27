/*
 * @Description: Cos函数单元测试
 * @Author: Longjing Xia
 * @FilePath: \tri_func\unit_test_fnCos.cpp
 * @Date: 2022-03-27 14:00:21
 * @LastEditTime: 2022-03-27 14:40:44
 */

#include "fnCos.h"
#include <stdio.h>
#include <assert.h>

int main()
{
    assert(fnCos(0, 3.14159) - 1 < 0.0001);
    assert(fnCos(0, 36.128285) - 1 < 0.0001);
    assert(fnCos(1, 720) == 1);
    assert(fnCos(1, -60) - 0.5 < 0.001);
    assert(fnCos(1, 120) + 0.5 < 0.0001);
    printf("all passed.\n");
}