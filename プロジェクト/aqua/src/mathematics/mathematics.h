
/*!
 *  @file       mathematics.h
 *  @brief      数学
 *  @author     Kazuya Maruyama
 *  @date       2021/03/10
 *  @version    7.17
 *
 *  Copyright (c) 2013-2021, Kazuya Maruyama. All rights reserved.
 */

#pragma once

#include <cmath>
#include "vector\vector.h"

/*!
 *  @brief      aqua名前空間
 */
namespace aqua
{
    /*!
     *  @brief      円周率
     */
    static const float PI = 3.141592653589793f;

    /*!
     *  @brief      角度をラジアンに変換
     *
     *  @param[in]  degree  角度
     */
    float       DegToRad( float degree );

    /*!
     *  @brief      ラジアンを角度に変換
     *
     *  @param[in]  radian  ラジアン
     */
    float       RadToDeg( float radian );

    /*!
     *  @brief      乱数を求める(正の整数)
     *
     *  @param[in]  max     最大値
     *  @param[in]  min     最小値
     *
     *  @return     最小値から最大値までの範囲で求められた乱数値
     */
    int         Rand(int max, int min = 0 );

    /*!
     *  @brief      数値の上下を求める
     * 
     *  @param[in]  num     数値
     *  @param[in]  t_max   最大値
     *  @param[in]  t_min   最小値  
     * 
     *  @return     最小値から最大値までの数値
     */
    template<class ENUM,class T> ENUM Limit(T num, T t_min, T t_max)
    {
        return (ENUM)std::max<T>(t_min, std::min<T>(num, t_max));
    }

    /*!
     *  @brief      数値の上下を求める
     *
     *  @param[in]  num     数値
     *  @param[in]  t_max   最大値
     *  @param[in]  t_min   最小値
     *
     *  @return     最小値から最大値までの数値
     */
    template<class T> T Limit(T num, T t_min, T t_max)
    {
        return std::max<T>(t_min, std::min<T>(num, t_max));
    }
    /*!
     *  @brief      数値の上下を求める
     *
     *  @param[in]  num     数値
     *  @param[in]  t_max   最大値
     *  @param[in]  t_min   最小値
     *
     *  @return     最小値から最大値までの数値
     */
    template<class T> T Mod(T num, T t_min, T t_max)
    {
        T m_next = (T)1;

        if (num > t_max)
            return num - (t_max + m_next);

        if (num < t_min)
            return (t_max + m_next) + num;

        return num;
    }

    /*!
     *  @brief      数値の上下を求める
     *
     *  @param[in]  num     数値
     *  @param[in]  t_max   最大値
     *  @param[in]  t_min   最小値
     *
     *  @return     最小値から最大値までの数値
     */
    template<class ENUM,class T> ENUM Mod(ENUM num, ENUM t_min, ENUM t_max)
    {
        T m_num = (T)num;
        T m_min = (T)t_min;
        T m_max = (T)t_max;
        T m_sub_max = (T)1;

        if (m_num > m_max)
            return (ENUM)(m_num - (m_max + m_sub_max));

        if (m_num < m_min)
            return (ENUM)((m_max + m_sub_max) + m_num);

        return num;
    }

    /*!
     *  @brief      数値の上下を求める
     *
     *  @param[in]  num     数値
     *  @param[in]  t_max   最大値
     *  @param[in]  t_min   最小値
     *
     *  @return     最小値から最大値までの数値
     */
    template<class ENUM, class T> ENUM Mod(T num, ENUM t_min, ENUM t_max)
    {
        T m_min = (T)t_min;
        T m_max = (T)t_max;
        T m_sub_max = (T)1;

        if (num > m_max)
            return (ENUM)(num - (m_max + m_sub_max));

        if (num < m_min)
            return (ENUM)((m_max + m_sub_max) + num);

        return (ENUM)num;
    }

    /*!
     *  @brief      数値の上下を求める
     *
     *  @param[in]  num     数値
     *  @param[in]  t_max   最大値
     *  @param[in]  t_min   最小値
     *
     *  @return     最小値から最大値までの数値
     */
    template<class ENUM, class T> ENUM Mod(T num, T t_min, T t_max)
    {
        T m_sub_max = (T)1;

        if (num > t_max)
            return (ENUM)(num - (t_max + m_sub_max));

        if (num < t_min)
            return (ENUM)((t_max + m_sub_max) + num);

        return (ENUM)num;
    }
}
