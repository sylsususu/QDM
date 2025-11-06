#include "MotorController.h"

MotorController::MotorController()
{
	MT_Init();
	timer = new QTimer(this);
	timer_pos = new QTimer(this);
	
}

MotorController::~MotorController()
{
	if (timer) {
		delete timer;
		timer = nullptr;
	}
	if (timer_pos) {
		delete timer_pos;
		timer_pos = nullptr;
	}

	MT_DeInit();
}

bool MotorController::connectMotor()
{
	try 
	{
		int iResult;
		MT_Close_USB();
		MT_Close_UART();

		//打开USB
		iResult = MT_Open_USB();
		if (iResult != R_OK)
		{
			throw QString("MT_Open_USB:failed");
			
		}
		//检测板卡
		iResult = MT_Check();
		if (R_OK != iResult)
		{
			throw QString("MT_Check:failed");
			
		}
		

		//设置加速度
		int iAcc = m_Acc;
		int iID;
		for (iID = X; iID <= Z; iID++)
		{

			iResult = MT_Set_Axis_Acc(iID, iAcc);
			if (R_OK != iResult)
			{
				throw QString("MT_Set_Axis_Acc:failed");
			}
		}
		//设置减速度
		int iDec = m_Dec;
		for (iID = X; iID <= Z; iID++)
		{

			iResult = MT_Set_Axis_Dec(iID, iDec);
			if (R_OK != iResult)
			{
				throw QString("MT_Set_Axis_Dec:failed");
			}
		}
		//设置位置模式最大速度
		int iMaxv = m_Maxv;
		for (iID = X; iID <= Z; iID++)
		{
			iResult = MT_Set_Axis_Position_V_Max(iID, iMaxv);
			if (R_OK != iResult)
			{
				throw QString("MT_Set_Axis_Position_V_Max:failed");
			}
		}
	}
	catch (QString &e) 
	{
		// 捕获并处理异常
		qDebug() << "Exception:" << e;
		// TODO
		return false;
	}


	timer_pos->setInterval(500); // 设置定时器间隔为0.5秒
	QObject::connect(timer_pos, &QTimer::timeout, this, &MotorController::getPos); // 连接定时器的timeout信号到func函数
	timer_pos->start(); // 启动定时器

	return true;
}

void MotorController::disconnectMotor()
{
	MT_Close_USB();
	MT_Close_UART();
}

void MotorController::findZero()
{
	findNegPos = false;
	
	//添加置当前为0位代码-应用3轴
	MT_Set_Axis_Software_P(X, 0);
	MT_Set_Axis_Software_P(Y, 0);
	MT_Set_Axis_Software_P(Z, 0);

	//相对位置负无穷找零
	int iRef= -m_Home_V;
	int iResult;
	int iID;
	try
	{
		for (iID = X; iID <= Z; iID++)
		{
			MT_Set_Axis_Mode_Velocity(iID);
			iResult = MT_Set_Axis_Velocity_V_Target_Abs(iID, iRef);
			if (R_OK != iResult)
			{
				throw QString("findZero:failed");
			}
		}
	}
	catch (QString* e)
	{
		// 捕获并处理异常
		qDebug() << "Exception:" << e;
		// TODO
		return ;
	}
	


	//定时读取电机状态
	timer->setInterval(500); // 设置定时器间隔为0.5秒
	QObject::connect(timer, &QTimer::timeout, this, &MotorController::stateOfMotion); // 连接定时器的timeout信号到func函数
	timer->start(); // 启动定时器
	

}

bool MotorController::stateOfMotion()
{
	//监测三轴运动状态
	int iID;
	int Axis_V_XYZ=0;
	byte iRun_XYZ=0;
	for (iID = X; iID <= Z; iID++)
	{
		
		int iV_Now;
		MT_Get_Axis_V_Now(iID, &iV_Now);
		byte iRun, iDir, iNeg, iPos, iZero, iMode;
		MT_Get_Axis_Status(iID, &iRun, &iDir, &iNeg, &iPos, &iZero, &iMode);
		Axis_V_XYZ += iV_Now;
		iRun_XYZ += iRun;
	}
	
	if (Axis_V_XYZ == 0 && iRun_XYZ == 0 && findNegPos)
	{
		//第二次停止，找零完成
		timer->stop();
		QObject::disconnect(timer, &QTimer::timeout, this, &MotorController::stateOfMotion); // 连接定时器的timeout信号到func函数
	//	qDebug() << ("stateOfMotion OK");
		int iP_Now_X;
		MT_Get_Axis_Software_P_Now(X, &iP_Now_X);
		int iP_Now_Y;
		MT_Get_Axis_Software_P_Now(Y, &iP_Now_Y);
		int iP_Now_Z;
		MT_Get_Axis_Software_P_Now(Z, &iP_Now_Z);
	//	qDebug() << "X:" << iP_Now_X << "Y:" << iP_Now_Y << "Z:" << iP_Now_Z;
		emit stateOfMotionOk();
		return true;

	}

	if (Axis_V_XYZ == 0 && iRun_XYZ == 0 && !findNegPos)
	{
		//第一次停止，找到负限位了，然后找零点
		for (iID = X; iID <= Z; iID++)
		{
			MT_Set_Axis_Mode_Home(iID);
			int iResult = MT_Set_Axis_Home_V(iID, m_Home_V);
			if (R_OK == iResult)
			{
				//qDebug() << ("MT_Set_Axis_Home_V OK");
			}

		}
		findNegPos = true;
		
	}
	
	return false;
}

void MotorController::forward(Mode currentMode, int iRef)
{
	if (currentMode == Standard) {
		// 执行标准模式下的操作
	
		//int iRef= m_Ref;
		int iResult;
		//进入位置模式，如果过程中模式不改，只需要设置一次，也可以放在窗口初始化
		MT_Set_Axis_Mode_Position(Y);
		iResult = MT_Set_Axis_Position_P_Target_Rel(Y, iRef);
		if (R_OK == iResult)
		{
			//qDebug()<<("forward OK");
		}

	}
	else if (currentMode == FineTuning) {
		// 执行微调模式下的操作

		int iRef= m_V_Abs;
		int iResult;
		int iID;
		//进入速度模式，如果过程中不变模式，只需要设置一次,可以放在窗口初始化中
		MT_Set_Axis_Mode_Velocity(Y);
		iResult = MT_Set_Axis_Velocity_V_Target_Abs(Y, iRef);
		if (R_OK == iResult)
		{
			//qDebug() << ("OK");
		}

	}
}

void MotorController::backward(Mode currentMode, int iRef)
{
	if (currentMode == Standard) {
		// 执行标准模式下的操作

		//int iRef = -m_Ref;
		int iResult;
		//进入位置模式，如果过程中模式不改，只需要设置一次，也可以放在窗口初始化
		MT_Set_Axis_Mode_Position(Y);
		iResult = MT_Set_Axis_Position_P_Target_Rel(Y, -iRef);
		if (R_OK == iResult)
		{
			//qDebug() << ("backward OK");
		}

	}
	else if (currentMode == FineTuning) {
		// 执行微调模式下的操作
		int iRef = -m_V_Abs;
		int iResult;
		int iID;
		//进入速度模式，如果过程中不变模式，只需要设置一次,可以放在窗口初始化中
		MT_Set_Axis_Mode_Velocity(Y);
		iResult = MT_Set_Axis_Velocity_V_Target_Abs(Y, iRef);
		if (R_OK == iResult)
		{
			//qDebug() << ("OK");
		}
	}
}

void MotorController::left(Mode currentMode, int iRef)
{
	if (currentMode == Standard) {
		// 执行标准模式下的操作

		//int iRef = -m_Ref;
		int iResult;
		//进入位置模式，如果过程中模式不改，只需要设置一次，也可以放在窗口初始化
		MT_Set_Axis_Mode_Position(X);
		iResult = MT_Set_Axis_Position_P_Target_Rel(X, iRef);
		if (R_OK == iResult)
		{
			//qDebug() << ("left OK");
		}

	}
	else if (currentMode == FineTuning) {
		// 执行微调模式下的操作
		int iRef = m_V_Abs;
		int iResult;
		int iID;
		//进入速度模式，如果过程中不变模式，只需要设置一次,可以放在窗口初始化中
		MT_Set_Axis_Mode_Velocity(X);
		iResult = MT_Set_Axis_Velocity_V_Target_Abs(X, iRef);
		if (R_OK == iResult)
		{
			//qDebug() << ("OK");
		}
	}
}

void MotorController::right(Mode currentMode, int iRef)
{
	if (currentMode == Standard) {
		// 执行标准模式下的操作

		//int iRef = m_Ref;
		int iResult;
		//进入位置模式，如果过程中模式不改，只需要设置一次，也可以放在窗口初始化
		MT_Set_Axis_Mode_Position(X);
		iResult = MT_Set_Axis_Position_P_Target_Rel(X, -iRef);
		if (R_OK == iResult)
		{
			//qDebug() << ("right OK");
		}

	}
	else if (currentMode == FineTuning) {
		// 执行微调模式下的操作
		int iRef =- m_V_Abs;
		int iResult;
		int iID;
		//进入速度模式，如果过程中不变模式，只需要设置一次,可以放在窗口初始化中
		MT_Set_Axis_Mode_Velocity(X);
		iResult = MT_Set_Axis_Velocity_V_Target_Abs(X, iRef);
		if (R_OK == iResult)
		{
			//qDebug() << ("OK");
		}
	}
}

void MotorController::up(Mode currentMode, int iRef)
{
	if (currentMode == Standard) {
		// 执行标准模式下的操作

		//int iRef = m_Ref;
		int iResult;
		//进入位置模式，如果过程中模式不改，只需要设置一次，也可以放在窗口初始化
		MT_Set_Axis_Mode_Position(Z);
		iResult = MT_Set_Axis_Position_P_Target_Rel(Z, iRef);
		if (R_OK == iResult)
		{
			//qDebug() << ("up OK");
		}

	}
	else if (currentMode == FineTuning) {
		// 执行微调模式下的操作
		int iRef = m_V_Abs;
		int iResult;
		int iID;
		//进入速度模式，如果过程中不变模式，只需要设置一次,可以放在窗口初始化中
		MT_Set_Axis_Mode_Velocity(Z);
		iResult = MT_Set_Axis_Velocity_V_Target_Abs(Z, iRef);
		if (R_OK == iResult)
		{
			//qDebug() << ("OK");
		}
	}
}

void MotorController::down(Mode currentMode, int iRef)
{
	if (currentMode == Standard) {
		// 执行标准模式下的操作

		
		int iResult;
		//进入位置模式，如果过程中模式不改，只需要设置一次，也可以放在窗口初始化
		MT_Set_Axis_Mode_Position(Z);
		iResult = MT_Set_Axis_Position_P_Target_Rel(Z, -iRef);
		if (R_OK == iResult)
		{
			//qDebug() << ("down OK");
		}

	}
	else if (currentMode == FineTuning) {
		// 执行微调模式下的操作
		int iRef = -m_V_Abs;
		int iResult;
		int iID;
		//进入速度模式，如果过程中不变模式，只需要设置一次,可以放在窗口初始化中
		MT_Set_Axis_Mode_Velocity(Z);
		iResult = MT_Set_Axis_Velocity_V_Target_Abs(Z, iRef);
		if (R_OK == iResult)
		{
			//qDebug() << ("OK");
		}
	}
}

void MotorController::load()
{
	readP0();
}

void MotorController::unload()
{
	readP1();
}

void MotorController::writeP0()
{
	int iP_Now;
	int iV_Now;
	int iID;
	for (iID = X; iID <= Z; iID++)
	{
		//读取当前位置
		MT_Get_Axis_Software_P_Now(iID, &iP_Now);
		//读取当前速度
		MT_Get_Axis_V_Now(iID, &iV_Now);
		if (iID==X)
		{
			m_P_Now_X = iP_Now;
			m_V_Now_X = iV_Now;
		}
		else if (iID==Y)
		{
			m_P_Now_Y = iP_Now;
			m_V_Now_Y = iV_Now;
		}
		else if (iID==Z)
		{
			m_P_Now_Z = iP_Now;
			m_V_Now_Z = iV_Now;
		}
		
	}

	// 创建一个JSON对象
	QJsonObject jsonData;

	// 添加参数到JSON对象
	jsonData["Load_X"] = m_P_Now_X/valueX;
	jsonData["Load_Y"] = m_P_Now_Y/valueY;
	jsonData["Load_Z"] = m_P_Now_Z/valueZ;
	

	// 创建一个JSON文档
	QJsonDocument jsonDoc(jsonData);

	// 将JSON文档转换为字符串
	QString jsonString = jsonDoc.toJson();


	//QString filePath = QFileDialog::getSaveFileName(nullptr, "Save JSON File", ".", "JSON Files (*.json)");
	QString filePath ="./Motor.json";

	// 检查文件是否存在
	QFile file(filePath);
	if (file.exists()) {
		// 如果文件存在，则读取文件内容并解析为JSON对象
		if (file.open(QIODevice::ReadOnly)) {
			QByteArray fileData = file.readAll();
			QJsonDocument jsonDoc(QJsonDocument::fromJson(fileData));
			QJsonObject existingData = jsonDoc.object();

			// 将新的参数添加到已有的JSON对象中
			QJsonObject mergedData = existingData;
			for (auto it = jsonData.constBegin(); it != jsonData.constEnd(); ++it) {
				mergedData[it.key()] = it.value();
			}

			// 将合并后的JSON对象转换为字符串
			QJsonDocument mergedDoc(mergedData);
			QString mergedString = mergedDoc.toJson();
			file.close();
			// 将字符串写入文件
			if (file.open(QIODevice::WriteOnly)) {
				QTextStream stream(&file);
				stream << mergedString;
				file.close();
			}
		}
	}
	else {
		// 如果文件不存在，则直接保存JSON对象到文件
		QJsonDocument jsonDoc(jsonData);
		QString jsonString = jsonDoc.toJson();

		if (file.open(QIODevice::WriteOnly)) {
			QTextStream stream(&file);
			stream << jsonString;
			file.close();
		}
	}
	
	
}

void MotorController::writeP1()
{
	int iP_Now;
	int iV_Now;
	int iID;
	for (iID = X; iID <= Z; iID++)
	{
		//读取当前位置
		MT_Get_Axis_Software_P_Now(iID, &iP_Now);
		//读取当前速度
		MT_Get_Axis_V_Now(iID, &iV_Now);
		if (iID == X)
		{
			m_P_Now_X = iP_Now;
			m_V_Now_X = iV_Now;
		}
		else if (iID == Y)
		{
			m_P_Now_Y = iP_Now;
			m_V_Now_Y = iV_Now;
		}
		else if (iID == Z)
		{
			m_P_Now_Z = iP_Now;
			m_V_Now_Z = iV_Now;
		}

	}

	// 创建一个JSON对象
	QJsonObject jsonData;

	// 添加参数到JSON对象
	jsonData["Unload_X"] = m_P_Now_X / valueX;
	jsonData["Unload_Y"] = m_P_Now_Y / valueY;
	jsonData["Unload_Z"] = m_P_Now_Z / valueZ;


	// 创建一个JSON文档
	QJsonDocument jsonDoc(jsonData);

	// 将JSON文档转换为字符串
	QString jsonString = jsonDoc.toJson();


	//QString filePath = QFileDialog::getSaveFileName(nullptr, "Save JSON File", ".", "JSON Files (*.json)");
	QString filePath = "./Motor.json";

	// 检查文件是否存在
	QFile file(filePath);
	if (file.exists()) {
		// 如果文件存在，则读取文件内容并解析为JSON对象
		if (file.open(QIODevice::ReadOnly)) {
			QByteArray fileData = file.readAll();
			QJsonDocument jsonDoc(QJsonDocument::fromJson(fileData));
			QJsonObject existingData = jsonDoc.object();

			// 将新的参数添加到已有的JSON对象中
			QJsonObject mergedData = existingData;
			for (auto it = jsonData.constBegin(); it != jsonData.constEnd(); ++it) {
				mergedData[it.key()] = it.value();
			}

			// 将合并后的JSON对象转换为字符串
			QJsonDocument mergedDoc(mergedData);
			QString mergedString = mergedDoc.toJson();
			file.close();
			// 将字符串写入文件
			if (file.open(QIODevice::WriteOnly)) {
				QTextStream stream(&file);
				stream << mergedString;
				file.close();
			}
		}
	}
	else {
		// 如果文件不存在，则直接保存JSON对象到文件
		QJsonDocument jsonDoc(jsonData);
		QString jsonString = jsonDoc.toJson();

		if (file.open(QIODevice::WriteOnly)) {
			QTextStream stream(&file);
			stream << jsonString;
			file.close();
		}
	}
}

void MotorController::readP0()
{
	//QString filePath = QFileDialog::getOpenFileName(nullptr, "Open JSON File", ".", "JSON Files (*.json)");
	QString filePath = "./Motor.json";
	// 检查用户是否选择了文件
	if (!filePath.isEmpty()) {
		// 打开JSON文件
		QFile file(filePath);
		if (!file.open(QIODevice::ReadOnly)) {
			// 文件打开失败
			return;
		}

		// 读取JSON数据
		QByteArray jsonData = file.readAll();

		// 关闭文件
		file.close();

		// 将JSON数据解析为JSON文档
		QJsonDocument jsonDoc = QJsonDocument::fromJson(jsonData);

		// 将JSON文档转换为JSON对象
		QJsonObject jsonObj = jsonDoc.object();

		// 从JSON对象中获取记录位置值
		int m_P_before_X = jsonObj["Load_X"].toDouble()*valueX;
		int m_P_before_Y = jsonObj["Load_Y"].toDouble()*valueY;
		int m_P_before_Z = jsonObj["Load_Z"].toDouble()*valueZ;

		goXPos(m_P_before_X);
		goYPos(m_P_before_Y);
		goZPos(m_P_before_Z);
		
		
	
	}
	

}

void MotorController::readP1()
{
	//QString filePath = QFileDialog::getOpenFileName(nullptr, "Open JSON File", ".", "JSON Files (*.json)");
	QString filePath = "./Motor.json";
	// 检查用户是否选择了文件
	if (!filePath.isEmpty()) {
		// 打开JSON文件
		QFile file(filePath);
		if (!file.open(QIODevice::ReadOnly)) {
			// 文件打开失败
			return;
		}

		// 读取JSON数据
		QByteArray jsonData = file.readAll();

		// 关闭文件
		file.close();

		// 将JSON数据解析为JSON文档
		QJsonDocument jsonDoc = QJsonDocument::fromJson(jsonData);

		// 将JSON文档转换为JSON对象
		QJsonObject jsonObj = jsonDoc.object();

		// 从JSON对象中获取记录位置值
		int m_P_before_X = jsonObj["Unload_X"].toDouble()*valueX;
		int m_P_before_Y = jsonObj["Unload_Y"].toDouble()*valueY;
		int m_P_before_Z = jsonObj["Unload_Z"].toDouble()*valueZ;

		goXPos(m_P_before_X);
		goYPos(m_P_before_Y);
		goZPos(m_P_before_Z);
	}
}

void MotorController::stop()
{
	int iID;
	for (iID=X;iID<=Z;iID++)
	{
		int iResult = MT_Set_Axis_Halt(iID);
		if (R_OK == iResult)
		{
			qDebug() << ("stop OK");
		}
	}
}

void MotorController::onStopV()
{
	int iID;
	for (iID = X; iID <= Z; iID++)
	{
		int iResult = MT_Set_Axis_Velocity_Stop(iID);
		if (R_OK == iResult)
		{
			qDebug() << ("onStopV OK");
		}
	}
	
}

void MotorController::onStop()
{
	int iID;
	for (iID = X; iID <= Z; iID++)
	{
		int iResult = MT_Set_Axis_Position_Stop(iID);
		if (R_OK == iResult)
		{
			qDebug() << ("onStop OK");
		}
	}
	
}

void MotorController::getPos()
{
	try
	{
		//监测三轴位置
		int iP_Now_X;
		if (R_OK!=MT_Get_Axis_Software_P_Now(X, &iP_Now_X))
		{
			throw QString("getPosX:failed");
		}
		int iP_Now_Y;
		if (R_OK != MT_Get_Axis_Software_P_Now(Y, &iP_Now_Y))
		{
			throw QString("getPosY:failed");
		}
		int iP_Now_Z;
		if (R_OK!=MT_Get_Axis_Software_P_Now(Z, &iP_Now_Z))
		{
			throw QString("getPosZ:failed");
		}
		

		emit getMotorPos(iP_Now_X, iP_Now_Y, iP_Now_Z);

		//监测三轴运动状态
		byte iRun_X, iDir_X, iNeg_X, iPos_X, iZero_X, iMode_X;
		if (R_OK != MT_Get_Axis_Status(X, &iRun_X, &iDir_X, &iNeg_X, &iPos_X, &iZero_X, &iMode_X))
		{
			throw QString("getRunX:failed");
		}
		
		if (iRun_X > 0)
		{
			emit isRunX(true);
		}
		else
		{
			emit isRunX(false);
		}

		byte iRun_Y, iDir_Y, iNeg_Y, iPos_Y, iZero_Y, iMode_Y;
		if (R_OK != MT_Get_Axis_Status(Y, &iRun_Y, &iDir_Y, &iNeg_Y, &iPos_Y, &iZero_Y, &iMode_Y))
		{
			throw QString("getRunY:failed");
		}
		if (iRun_Y > 0)
		{
			emit isRunY(true);
		}
		else
		{
			emit isRunY(false);
		}

		byte iRun_Z, iDir_Z, iNeg_Z, iPos_Z, iZero_Z, iMode_Z;
		if (R_OK != MT_Get_Axis_Status(Z, &iRun_Z, &iDir_Z, &iNeg_Z, &iPos_Z, &iZero_Z, &iMode_Z))
		{
			throw QString("getRunZ:failed");
		}
		if (iRun_Z > 0)
		{
			emit isRunZ(true);
		}
		else
		{
			emit isRunZ(false);
		}
	}
	catch (QString& e)
	{
		// 捕获并处理异常
		qDebug() << "Exception :" << e;
		// TODO
		timer_pos->stop();
		return;
	}
	
	

	
}

void MotorController::goXPos(int m_Abs)
{
	int iResult;
	//进入位置模式，如果过程中模式不改，只需要设置一次，也可以放在窗口初始化
	MT_Set_Axis_Mode_Position(X);
	iResult = MT_Set_Axis_Position_P_Target_Abs(X, m_Abs);
	if (R_OK == iResult)
	{
		//qDebug() << ("goXPos OK");
	}
}

void MotorController::goYPos(int m_Abs)
{
	int iResult;
	//进入位置模式，如果过程中模式不改，只需要设置一次，也可以放在窗口初始化
	MT_Set_Axis_Mode_Position(Y);
	iResult = MT_Set_Axis_Position_P_Target_Abs(Y, m_Abs);
	if (R_OK == iResult)
	{
		//qDebug() << ("goYPos OK");
	}
}

void MotorController::goZPos(int m_Abs)
{
	int iResult;
	//进入位置模式，如果过程中模式不改，只需要设置一次，也可以放在窗口初始化
	MT_Set_Axis_Mode_Position(Z);
	iResult = MT_Set_Axis_Position_P_Target_Abs(Z, m_Abs);
	if (R_OK == iResult)
	{
		//qDebug() << ("goZPos OK");
	}
}

float MotorController::value(int a)
{
	if (0 == a)
	{
		return valueX;
	}
	if (1 == a)
	{
		return valueY;
	}
	if (2 == a)
	{
		return valueZ;
	}
	return valueX;
}
