/*****************************************
Copyright(C):国盛量子
Version:v1.0
Author:杨万阳
Date:2023/03/27
Description:常用接口
*****************************************/

#pragma once
#include <QBitArray>
#include <QByteArray>
class Utils
{
public:
	static QBitArray bytesToBits(const QByteArray &bytes);

	static QByteArray bitsToBytes(const QBitArray &bits);

	/// <summary>
	/// 整形数字转16位的QBitArray
	/// </summary>
	/// <param name="num">整形数字</param>
	/// <returns>QBitArray</returns>
	template<typename T>
	static QBitArray intTo16Bits(const T &num)
	{
		QByteArray binBytes = QByteArray::number(num, 2);
		QBitArray binBits;
		binBits.resize(16);
		binBits.fill(0x00);
		for (int i = binBytes.count() - 1; i >= 0; i--)
		{
			binBits[i + 16 - binBytes.count()] = (binBytes[i] == '1') ? true : false;
		}
		return binBits;
	}
	/// <summary>
	/// 整形数字转size位的QBitArray
	/// </summary>
	/// <param name="num">整形数字</param>
	/// <returns>QBitArray</returns>
	template<typename T>
	static QBitArray intToBits(const T &num,int size)
	{
		QByteArray binBytes = QByteArray::number(num, 2);
		QBitArray binBits;
		binBits.resize(size);
		binBits.fill(0x00);
		for (int i = binBytes.count() - 1; i >= 0; i--)
		{
			binBits[i + size - binBytes.count()] = (binBytes[i] == '1') ? true : false;
		}
		return binBits;
	}
	
	/// <summary>
	/// 整形数字转两个字节长的QByteArray
	/// </summary>
	/// <param name="num">整形数字</param>
	/// <returns>QByteArray</returns>
	template<typename T>
	static QByteArray intToDoubleBytes(const T &num)
	{
		QByteArray bytes = Utils::bitsToBytes(intTo16Bits(num));
		return bytes;
	}
};

