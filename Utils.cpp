
#include "Utils.h"


// QByteArray 转换为 QBitArray
QBitArray Utils::bytesToBits(const QByteArray &bytes)
{
	QBitArray bits(bytes.count() * 8);
	for (int i = 0; i < bytes.count(); ++i)
		for (int b = 0; b < 8; ++b)
			bits.setBit(i * 8 + b, bytes.at(i) & (0x01 << (7 - b)));
	return bits;
}

// QBitArray 转换为 QByteArray
QByteArray Utils::bitsToBytes(const QBitArray &bits)
{
	QByteArray bytes;
	bytes.resize(bits.count() / 8 + ((bits.count() % 8) ? 1 : 0));
	bytes.fill(0x00);
	for (int b = 0; b < bits.count(); ++b)
		bytes[b / 8] = (bytes.at(b / 8) | ((bits[b] ? 1 : 0) << (7 - (b % 8))));
	return bytes;
}

