#include "PulseControl.h"

PulseControl::~PulseControl()
{

	
}

bool PulseControl::pulseConnect()
{
	int temp = 0;

	int DevIndex = 0;
	temp = USB3OpenDevice(DevIndex);
	if (0 == temp)
	{
		
		Sleep(1000);
		// 关闭设备
		//temp = USB3CloseDevice(DevIndex);
		return true;
	}
	return false;
}

bool PulseControl::pulseDisConect()
{
	int DevIndex = 0;
	int temp = 0;
	temp=USB3CloseDevice(DevIndex);
	if (0 == temp)
	{
		return true;
	}

	return false;
}



void PulseControl::clearPulse()
{
	int temp=0;
	int DevIndex = 0;
	unsigned char Chan = 0;
	float wave[1] = { 0 };
	
	// 调用函数时，返回错误代码
	// 打开设备
	//temp = USB3OpenDevice(DevIndex);

	if (0 == temp)
	{
		// 分别对 4 个通道进行设置
		for (Chan = 0; Chan < 3; Chan++)
		{
			// 清除触发标志
			temp = SetUSB3ClrAoTrigger(DevIndex, Chan);

			// 清空 AoFifo
			temp = SetUSB3ClrAoFifo(DevIndex, Chan);

			// 设置为 NCycle 模式，代表硬件 Fifo 缓冲的有限次数/无限循环输出模式，其循环次数由 SetUSB3AoCycle() 函数决定。
			temp = SetUSB3AoSampleMode(DevIndex, Chan, 1);

			// 设置 Ao 采样周期为 10000ns=10ms，即 100kSa/s
			temp = SetUSB3AoSampleRate(DevIndex, Chan, 1000000);

			// 设置触发源为 GlobalSoftTrig 全局软件触发
			temp = SetUSB3AoTrigSource(DevIndex, Chan, 255);

			//设置采样时钟源为 Ao 内部采样时钟源，该时采样时钟频率由 SetUSB3AoSampleRate() 函数设定。
			temp = SetUSB3AoConvSource(DevIndex, Chan, 0);

			// 设置无限循环输出，AoCycle 参数设置为 0 即可。
			temp = SetUSB3AoCycle(DevIndex, Chan, 1);

			// 将波形数组 waveform 的前 500 个点下载到 AoFifo 中，
			temp = SetUSB3AoDataFifo(DevIndex, Chan, wave, 1);


		}
		// 选择需要通道的 ao 通道。
		// 0xf 参数的 bit-0 到 bit 3 对应 ao 0 到 ao 3。
		// 例如，如果只选择 ai 0 和 ai 1，此参数应设置为 0x03。
		// 依次类推。
		temp = SetUSB3AoSync(DevIndex, 0x07);

		// 启动全局软件触发
		temp = SetUSB3GlobalSoftTrig(DevIndex);

		Sleep(1000);

		// 关闭设备
		//temp = USB3CloseDevice(DevIndex);
	}

	
	
}

void PulseControl::startPulse(int cycleTime, int pulseNumbers,  QVector<float> A0, QVector<float> A1, QVector<float> A2, unsigned int ms)
{
	int temp=0;
	int DevIndex = 0;
	unsigned char Chan = 0;

	float *wave;
	float *camerawave;
	float *openclosewave;
	
	wave = (float *)malloc(cycleTime * sizeof(float));
	camerawave = (float *)malloc(cycleTime * sizeof(float));
	openclosewave = (float *)malloc(cycleTime * sizeof(float));
	
	for (int i = 0; i < cycleTime; i++)
	{
		wave[i] = A0[i];
		camerawave[i] = A1[i];
		openclosewave[i] = A2[i];
		
	}
	// 调用函数时，返回错误代码
	// 打开设备
	//temp = USB3OpenDevice(DevIndex);
	if (0==temp)
	{
		// 分别对 4 个通道进行设置
		for (Chan = 0; Chan < 3; Chan++)
		{
			// 清除触发标志
			temp = SetUSB3ClrAoTrigger(DevIndex, Chan);

			// 清空 AoFifo
			temp = SetUSB3ClrAoFifo(DevIndex, Chan);

			// 设置为 NCycle 模式，代表硬件 Fifo 缓冲的有限次数/无限循环输出模式，其循环次数由 SetUSB3AoCycle() 函数决定。
			temp = SetUSB3AoSampleMode(DevIndex, Chan, 1);

			// 设置 Ao 采样周期为 10000ns=10ms，即 100kSa/s
			temp = SetUSB3AoSampleRate(DevIndex, Chan, ms*1000000);

			// 设置触发源为 GlobalSoftTrig 全局软件触发
			temp = SetUSB3AoTrigSource(DevIndex, Chan, 255);

			//设置采样时钟源为 Ao 内部采样时钟源，该时采样时钟频率由 SetUSB3AoSampleRate() 函数设定。
			temp = SetUSB3AoConvSource(DevIndex, Chan, 0);

			// 设置无限循环输出，AoCycle 参数设置为 0 即可。
			temp = SetUSB3AoCycle(DevIndex, Chan, pulseNumbers);

			// 将波形数组 waveform 的前 500 个点下载到 AoFifo 中，
			if (0 == Chan)
			{
				temp = SetUSB3AoDataFifo(DevIndex, Chan, wave, cycleTime);
			}
			if (1 == Chan)
			{
				temp = SetUSB3AoDataFifo(DevIndex, Chan, camerawave, cycleTime);
			}
			if (2 == Chan)
			{
				temp = SetUSB3AoDataFifo(DevIndex, Chan, openclosewave, cycleTime);
			}



		}

		// 选择需要通道的 ao 通道。
		// 0xf 参数的 bit-0 到 bit 3 对应 ao 0 到 ao 3。
		// 例如，如果只选择 ai 0 和 ai 1，此参数应设置为 0x03。
		// 依次类推。
		temp = SetUSB3AoSync(DevIndex, 0x07);
		if (temp != 0)
		{
			qDebug() << "plus error!";
		}
		// 启动全局软件触发
		temp = SetUSB3GlobalSoftTrig(DevIndex);
		if (temp!=0)
		{
			qDebug() << "plus error!";
		}
		//Sleep(1000);

		// 关闭设备
		//temp = USB3CloseDevice(DevIndex);
	}

	
	if (wave)
	{
		free(wave);
		wave = nullptr;
	}
	if (camerawave)
	{
		free(camerawave);
		camerawave = nullptr;
	}
	if (openclosewave)
	{
		free(openclosewave);
		openclosewave = nullptr;
	}
	
}

void PulseControl::startPulse_LockIn(int cycleTime, int pulseNumbers, QVector<float> A3, QVector<float> A1, QVector<float> A2, unsigned int ms)
{
	int temp = 0;
	int DevIndex = 0;
	unsigned char Chan = 0;

	float *current;
	float *camerawave;
	float *openclosewave;

	current = (float *)malloc(cycleTime * sizeof(float));
	camerawave = (float *)malloc(cycleTime * sizeof(float));
	openclosewave = (float *)malloc(cycleTime * sizeof(float));

	for (int i = 0; i < cycleTime; i++)
	{
		current[i] = A3[i];
		camerawave[i] = A1[i];
		openclosewave[i] = A2[i];

	}
	// 调用函数时，返回错误代码
	// 打开设备
	//temp = USB3OpenDevice(DevIndex);
	if (0 == temp)
	{
		// 分别对 4 个通道进行设置
		for (Chan = 1; Chan < 4; Chan++)
		{
			// 清除触发标志
			temp = SetUSB3ClrAoTrigger(DevIndex, Chan);

			// 清空 AoFifo
			temp = SetUSB3ClrAoFifo(DevIndex, Chan);

			// 设置为 NCycle 模式，代表硬件 Fifo 缓冲的有限次数/无限循环输出模式，其循环次数由 SetUSB3AoCycle() 函数决定。
			temp = SetUSB3AoSampleMode(DevIndex, Chan, 1);

			// 设置 Ao 采样周期为 10000ns=10ms，即 100kSa/s
			temp = SetUSB3AoSampleRate(DevIndex, Chan, ms * 1000000);

			// 设置触发源为 GlobalSoftTrig 全局软件触发
			temp = SetUSB3AoTrigSource(DevIndex, Chan, 255);

			//设置采样时钟源为 Ao 内部采样时钟源，该时采样时钟频率由 SetUSB3AoSampleRate() 函数设定。
			temp = SetUSB3AoConvSource(DevIndex, Chan, 0);

			// 设置无限循环输出，AoCycle 参数设置为 0 即可。
			temp = SetUSB3AoCycle(DevIndex, Chan, pulseNumbers);

			// 将波形数组 waveform 的前 500 个点下载到 AoFifo 中，
			if (3 == Chan)
			{
				temp = SetUSB3AoDataFifo(DevIndex, Chan, current, cycleTime);
			}
			if (1 == Chan)
			{
				temp = SetUSB3AoDataFifo(DevIndex, Chan, camerawave, cycleTime);
			}
			if (2 == Chan)
			{
				temp = SetUSB3AoDataFifo(DevIndex, Chan, openclosewave, cycleTime);
			}



		}

		// 选择需要通道的 ao 通道。
		// 0xf 参数的 bit-0 到 bit 3 对应 ao 0 到 ao 3。
		// 例如，如果只选择 ai 0 和 ai 1，此参数应设置为 0x03。
		// 依次类推。
		temp = SetUSB3AoSync(DevIndex, 0xe);
		if (temp != 0)
		{
			qDebug() << "plus error!";
		}
		// 启动全局软件触发
		temp = SetUSB3GlobalSoftTrig(DevIndex);
		if (temp != 0)
		{
			qDebug() << "plus error!";
		}
		//Sleep(1000);

		// 关闭设备
		//temp = USB3CloseDevice(DevIndex);
	}


	if (current)
	{
		free(current);
		current = nullptr;
	}
	if (camerawave)
	{
		free(camerawave);
		camerawave = nullptr;
	}
	if (openclosewave)
	{
		free(openclosewave);
		openclosewave = nullptr;
	}

}