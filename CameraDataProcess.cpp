#include"CameraDataProcess.h"
#include"omp.h"
#include <QtCore/qfile.h>
int CameraDataProcess::rawChangetoInt(unsigned char* inputbyte, int img_width, int img_height, QVector<int>& outputarray)
{
	
	outputarray.clear();
	int Size_byte = img_width * img_height;
	outputarray.resize(Size_byte);

#pragma omp parallel for num_threads(10) 
	for (int i = 0; i < Size_byte / 2; ++i)
	{
		int a0 = inputbyte[i * 3];

		int a1 = inputbyte[i * 3 + 1];

		int a2 = inputbyte[i * 3 + 2];


		int raw1 = (a0 << 4) | (a1 & 0xf);

		int raw2 = (a2 << 4) | ((a1 & 0xf0) >> 4);

		outputarray[i * 2] = raw1;
		outputarray[i * 2 + 1] = raw2;
	}


	return 0;
}

int CameraDataProcess::rawChangetoMat(unsigned char* inputbyte, int img_width, int img_height, cv::Mat& outputimg)
{
	int Size_byte = img_width * img_height;
	std::vector<unsigned short> outputarray(Size_byte,0);
	
//#pragma omp parallel for num_threads(32) 
	for (int i = 0; i < Size_byte / 2; ++i)
	{
		int a0 = inputbyte[i * 3];

		int a1 = inputbyte[i * 3 + 1];

		int a2 = inputbyte[i * 3 + 2];


		int raw1 = (a0 << 4) | (a1 & 0xf);

		int raw2 = (a2 << 4) | ((a1 & 0xf0) >> 4);

		outputarray[i * 2] = static_cast<unsigned short>(raw1);
		outputarray[i * 2+1] = static_cast<unsigned short>(raw2);
	}

	// 更改矩阵大小为n行
	//16U
	cv::Mat tmp = cv::Mat(outputarray);
	tmp = tmp.reshape(0, img_height);
	outputimg = tmp.clone();
	return 0;
}

int CameraDataProcess::intChangetoRoiInt(int img_width, int img_height, QVector<int>& v_12int, QRect roi, QVector<int>& v_12int_roi)
{
	//每次进入函数先清空，防止多次调用导致数据错误
	v_12int_roi.clear();

	int x = roi.x();
	int y = roi.y();
	int w = roi.width();
	int h = roi.height();

	//防止越界处理
	if ((x < 0) || (y < 0) || (w < 0) || (h < 0))
	{
		return -1;
	}
	if ((w > img_width) || (h > img_height))
	{
		return -1;
	}

	//(x,y)--(x+w,y)
	int j_start = x + y * img_width;
	int j_end = x + w + y * img_width;
	for (int i = y; i < y + h; ++i)
	{
		for (int j = x + i * img_width; j < x + w + i * img_width; ++j)
		{
			int tmp = v_12int[j];
			v_12int_roi.push_back(tmp);
		}
	}

	return 0;
}

int CameraDataProcess::mydivisionadd(QVector<int>& v_molecule, QVector<int>& v_denominator, QVector<int>& v_add)
{
	//将两个vector相除累加
	if (v_molecule.size() != v_denominator.size())
	{
		return -1;
	}
	if (v_molecule.size() != v_add.size())
	{
		return -1;
	}
	else
	{

		for (int i = 0; i < v_molecule.size(); ++i)
		{
			double i_tmp = 0;
			double i_openwave = (double)v_molecule[i];
			double i_closewave = (double)v_denominator[i];
			//分母为0
			if (i_closewave == 0)
			{
				i_tmp = 0;
			}
			else
			{
				i_tmp = (i_openwave) / (i_closewave) * 4096;
			}
			v_add[i] += (int)i_tmp;//int输出，做除法时，可能会为0
		}

	}//相除累加结束
	return 0;
}

double CameraDataProcess::myaverage(QVector<int>& v_tmp)
{
	double  average = 0.0;
	double sum = 0;

	for (int i = 0; i < v_tmp.size(); ++i)
	{
		sum += v_tmp[i];
	}

	average = sum / v_tmp.size();

	return average;
}

QImage CameraDataProcess::intChangetoQimg(int img_width, int img_height, QVector<int>& inputarray)
{
	unsigned char* c_uchar;
	c_uchar = (unsigned char*)malloc(img_width * img_height);  //预先申请动态空间
	for (int i = 0; i < inputarray.size(); i++)
	{

		int tmp =inputarray[i]/4096.0*255.0;
		if (tmp>255)
		{
			tmp = 255;
		}
		uchar utmp = (uchar)tmp;
		c_uchar[i] = utmp;

	}
	QImage img;
	img = QImage(c_uchar, img_width, img_height, QImage::Format_Indexed8);


	//灰度图颜色表
	QVector<QRgb> ColourTable;
	for (int i = 0; i < 256; i++)
	{
		ColourTable.append(qRgb(i, i, i));
	}

	img.setColorTable(ColourTable);
	return img;

}

QImage CameraDataProcess::intChangetoQcolorimg(int img_width, int img_height, const QVector<double>& magnetic_strength, double down, double up, QImage& image0)
{
	//int w_pic = img_width;
	//int h_pic = img_height;
	//QVector<QRgb> rgbColourTable;
	//unsigned char* Buffer;		//磁场强度信息值，根据在上下限up，down中比例转换到0-255
	//Buffer = (unsigned char*)malloc(w_pic * h_pic);
	//QImage img = QImage(Buffer, w_pic, h_pic, QImage::Format_Indexed8);
	//if (w_pic * h_pic != magnetic_strength.size())
	//{
	//	return img;
	//}
	//if (down >= up)
	//{
	//	return img;
	//}

	//for (int i = 0; i < w_pic * h_pic; i++)
	//{
	//	if (magnetic_strength[i] <= down)
	//	{
	//		Buffer[i] = (uchar)0;
	//	}
	//	if (magnetic_strength[i] >= up)
	//	{
	//		Buffer[i] = (uchar)255;
	//	}
	//	if ((magnetic_strength[i] < up) && (magnetic_strength[i] > down))
	//	{
	//		int tmp = (magnetic_strength[i] - down) / (up - down) * 255;
	//		uchar utmp = (uchar)tmp;
	//		Buffer[i] = utmp;
	//	}

	//}

	//for (int y = 0; y < 256; y++)
	//{

	//	QColor color;
	//	int index = (int)((float)(y) / (float)(255) * (float)(image0.height() - 2));
	//	if (y == 0)
	//	{
	//		color = image0.pixelColor(QPoint(1, image0.height() - 2));
	//	}
	//	else if (y == 255)
	//	{
	//		color = image0.pixelColor(QPoint(1, 1));
	//	}
	//	else
	//	{

	//		color = image0.pixelColor(QPoint(1, image0.height()-2-index));
	//	}

	//	QRgb rgb = color.rgb();
	//	rgbColourTable.push_back(rgb);
	//}


	//img.setColorTable(rgbColourTable);
	////img.save("image_mapping.png");
	//return img;
	int w_pic = img_width;
	int h_pic = img_height;
	QVector<QRgb> rgbColourTable;
	QImage img = QImage(w_pic, h_pic, QImage::Format_Indexed8);
	QVector<uchar>grayvalue;



	if (w_pic * h_pic != magnetic_strength.size())
	{
		return img;
	}
	if (down >= up)
	{
		return img;
	}

	for (int i = 0; i < w_pic * h_pic; i++)
	{
		if (magnetic_strength[i] <= down)
		{
			grayvalue.push_back((uchar)0);
		}
		if (magnetic_strength[i] >= up)
		{
			grayvalue.push_back((uchar)255);
		}
		if ((magnetic_strength[i] < up) && (magnetic_strength[i] > down))
		{
			int tmp = (magnetic_strength[i] - down) / (up - down) * 255;
			uchar utmp = (uchar)tmp;
			grayvalue.push_back(utmp);
		}

	}

	for (int row = 0; row < h_pic; ++row) {
		uchar* scanLine = img.scanLine(row); // 获取每一行的地址
		memcpy(scanLine, &grayvalue[row * w_pic], w_pic); // 将数据拷贝到对应地址
	}


	QImage copyImage = img.copy(); // 复制整个图像
	for (int y = 0; y < 256; y++)
	{

		QColor color;
		int index = (int)((float)(y) / (float)(255) * (float)(image0.height() - 2));

		if (index == 0)
		{
			color = image0.pixelColor(QPoint(1, image0.height() - 2));
		}
		else if (index == image0.height() - 2)
		{
			color = image0.pixelColor(QPoint(1, 1));
		}
		else
		{

			color = image0.pixelColor(QPoint(1, image0.height() - 2 - index));
		}

		QRgb rgb = color.rgb();
		rgbColourTable.push_back(rgb);
	}


	copyImage.setColorTable(rgbColourTable);



	return copyImage;
}

int CameraDataProcess::saveRawMat(int img_width, int img_height, unsigned char* Rawbuffer, string savepath)
{
	cv::Mat img;
	img = cv::Mat(img_height, img_width / 2 * 3, CV_8UC1, Rawbuffer);
	cv::imwrite(savepath, img);
	return 0;

}

int CameraDataProcess::readRawMat(string imgpath, unsigned char* Rawbuff)
{
	cv::Mat image;   //创建一个空图像image
	image = cv::imread(imgpath, cv::IMREAD_UNCHANGED);  //读取文件夹中的图像
// 	QVector<unsigned char> raw_mat;
// 	for (int i = 0; i < image.rows; i++)
// 	{
// 		uchar *ptr = image.ptr<uchar>(i);
// 		for (int j = 0; j < image.cols; j++)
// 		{
// 			raw_mat.push_back(ptr[j]);
// 
// 		}
// 	}
	if (image.empty())
	{
		return -1;
	}
	//mat to char*
	int nHeight = image.rows;
	int nWidth = image.cols;
	int nBytes = nHeight * nWidth;//图像总的字节


	memcpy(Rawbuff, image.data, nBytes);//转化函数,注意Mat的data成员	

	return 0;
}

int CameraDataProcess::read16Raw(string rawpath, int imgWidth, int imgHeight, QVector<ushort>& v_12int)
{
	// 读取raw10图片
	std::string strFilename = rawpath;
	int nWidth = imgWidth;
	int nHeight = imgHeight;
	ushort* pRaw16buf = new ushort[(size_t)nWidth * nHeight];
	if (!pRaw16buf)
	{
		//std::cout << "ERROR: 开辟内存失败！" << std::endl;
		return -1;
	}
	FILE* pfile = nullptr;
	errno_t err_code = fopen_s(&pfile, strFilename.c_str(), "rb");
	if (!pfile) {
		//std::cout << "ERROR: 打开文件失败！" << std::endl;
		return -1;
	}
	fread(pRaw16buf, sizeof(pRaw16buf[0]), (size_t)nWidth * nHeight, pfile);
	fclose(pfile);
	pfile = nullptr;


	for (int i = 0; i < nWidth * nHeight; ++i)
	{
		v_12int.push_back(pRaw16buf[i] / 16);
	}
	delete pRaw16buf;
	pRaw16buf = NULL;

	return 0;
}
int CameraDataProcess::matToQVector(cv::Mat inputarray, QVector<double>& v_double)
{
	v_double.clear();
	for (int i = 0; i < inputarray.rows; i++)
	{
		double* ptr = inputarray.ptr<double>(i); // 获取第i行数据的指针
		for (int j = 0; j < inputarray.cols; j++) 
		{
			double value = ptr[j]; // 获取第i行j列像素点的值
			v_double.push_back(value);
		}
	}
	return 0;
}

void CameraDataProcess::readTestTxt(QString fileName, int width, int height, QVector<double>& resultVec)
{
	QFile file(fileName);
	bool isOk = file.open(QIODevice::ReadOnly);
	QTextStream in(&file);
	while (!in.atEnd())
	{
		resultVec.push_back(in.readLine().toDouble());
	}
}

bool CameraDataProcess::gaussiantCurveFit(const vector<cv::Point2d>& cvFitPointVec, int n, double & a, double & b)
{
	cv::Mat B(3, 1, CV_64FC1, cv::Scalar(0));
	int N = cvFitPointVec.size();
	cv::Mat Y(N, 1, CV_64FC1, cv::Scalar(0));
	cv::Mat X(N, n, CV_64FC1, cv::Scalar(0));
	for (int i = 0; i < N; ++i)
	{
		double* ptr = X.ptr<double>(i);
		for (int j = 0; j < n; ++j)
		{
			ptr[j] = pow(cvFitPointVec[i].x, j);
		}
		Y.at<double>(i, 0) = log(cvFitPointVec[i].y);
	}
	//求解矩阵B：X*B = Y
	solve(X, Y, B, cv::DECOMP_QR);
	//由b0,b1,b2计算高斯函数系数a,b,c
	double a0 = B.at<double>(0, 0);
	double a1 = B.at<double>(1, 0);
	double a2 = B.at<double>(2, 0);
	double fParmB = -1 / (a2);
	double fParmC = -a1 / (2 * a2);
	double fParmA = std::exp(a0 + fParmC * fParmC / fParmB);
	a = fParmA;
	b = fParmC;

	//高斯函数公式
	/*for (int i = 0; i < cvFitPointVec.size(); i++)
	{
		double y = fParmA * exp(-pow(cvFitPointVec.at(i).x - fParmC, 2) / fParmB);
		cvResultVec.push_back(cv::Point2d(cvFitPointVec.at(i).x, y));
	}*/
	return true;
}

void CameraDataProcess::readTiff(QString fileName, int & width, int & height, QVector<float>& resultVec)
{
	QByteArray data = fileName.toLocal8Bit();
	string tmpstr = string(data);

	cv::Mat image;     //创建一个空图像image
	image = cv::imread(tmpstr, cv::IMREAD_ANYDEPTH);  //读取文件夹中的图像
	image.convertTo(image, CV_32FC1);
	if (image.empty()) {
		return; // 返回空的QVector
	}
	CV_Assert(image.channels() == 1); // 确保是单通道的Mat

	int rows = image.rows;
	int cols = image.cols;

	width = cols;
	height = rows;
	int Size_byte = width * height;
	resultVec.resize(Size_byte);

	//#pragma omp parallel for num_threads(4)
	for (int i = 0; i < rows; i++) {
		const float* ptr = image.ptr<float>(i);
		for (int j = 0; j < cols; j++) {
			resultVec[i*cols + j] = ptr[j];
		}
	}
}

int CameraDataProcess::LevmarDif(double * p, double * x, int m, int n, int itmax, double opts[5], double info[10], double * work, double * covar, void * adata)
{
	register int i, j, k, l;
	int worksz, freework = 0, issolved;
	/* temp work arrays */
	double *e,
		*hx,
		*jacTe,
		*jac,
		*jacTjac,
		*Dp,
		*diag_jacTjac,
		*pDp,
		*wrk,
		*wrk2;

	int using_ffdif = 1;

	register double mu,tmp;

	double p_eL2, jacTe_inf, pDp_eL2;
	double p_L2, Dp_L2 = 1.7976931348623158e+308, dF, dL;
	double tau, eps1, eps2, eps2_sq, eps3, delta;
	double init_p_eL2;
	int nu, nu2, stop = 0, nfev, njap = 0, nlss = 0, K = (m >= 10) ? m : 10, updjac, updp = 1, newjac;
	const int nm = n * m;
	int(*linsolver)(double *A, double *B, double *x, int m) = NULL;
	
	mu = jacTe_inf = p_L2 = 0.0; 
	updjac = newjac = 0; 

	if (n < m) {
		fprintf(stderr, ("LEVMAR_DIF (): cannot solve a problem with fewer measurements [%d] than unknowns [%d]\n"), n, m);
		return -1;
	}

	if (opts) {
		tau = opts[0];
		eps1 = opts[1];
		eps2 = opts[2];
		eps2_sq = opts[2] * opts[2];
		eps3 = opts[3];
		delta = opts[4];
		if (delta < 0.0) 
		{
			delta = -delta; 
			using_ffdif = 0; 
		}
	}
	else { // use default values
		tau = 1E-03;
		eps1 = 1E-17;
		eps2 = 1E-17;
		eps2_sq = 1E-17*1E-17;
		eps3 = 1E-17;
		delta = 1E-06;
	}

	if (!work) {
		worksz = 4 * n + 4 * m + n * m + m * m; 
		work = (double *)malloc(worksz * sizeof(double)); /* allocate a big chunk in one step */
		if (!work) {
			fprintf(stderr, ("LEVMAR_DIF (): memory allocation request failed\n"));
			return -1;
		}
		freework = 1;
	}

	/* set up work arrays */
	e = work;
	hx = e + n;
	jacTe = hx + n;
	jac = jacTe + m;
	jacTjac = jac + nm;
	Dp = jacTjac + m * m;
	diag_jacTjac = Dp + m;
	pDp = diag_jacTjac + m;
	wrk = pDp + m;
	wrk2 = wrk + n;

	/* compute e=x - f(p) and its L2 norm */
	func(p, hx, m, n, adata); nfev = 1;
	/* ### e=x-hx, p_eL2=||e|| */

	p_eL2 = LEVMAR_L2NRMXMY(e, x, hx, n);


	init_p_eL2 = p_eL2;
	if (!_finite(p_eL2)) stop = 7;

	nu = 20;

	for (k = 0; k < itmax && !stop; ++k) 
	{
		if (p_eL2 <= eps3) 
		{ 
			stop = 6;
			break;
		}

		if ((updp && nu > 16) || updjac == K) 
		{ 
			if (using_ffdif) 
			{ 
				LEVMAR_FDIF_FORW_JAC_APPROX( p, hx, wrk, delta, jac, m, n, adata);
				
				++njap; nfev += m;
			}
			else 
			{ 
				LEVMAR_FDIF_CENT_JAC_APPROX(p, wrk, wrk2, delta, jac, m, n, adata);
		
				++njap; nfev += 2 * m;
			}
			nu = 2; updjac = 0; updp = 0; newjac = 1;
		}

		if (newjac)
		{
			newjac = 0;
			if (nm<=32*32)
			{
				register int l;
				register double alpha, *jaclm, *jacTjacim;

				for (i = m * m; i-- > 0; )
					jacTjac[i] = 0.0;
				for (i = m; i-- > 0; )
					jacTe[i] = 0.0;

				for (l = n; l-- > 0; ) {
					jaclm = jac + l * m;
					for (i = m; i-- > 0; ) {
						jacTjacim = jacTjac + i * m;
						alpha = jaclm[i]; //jac[l*m+i];
						for (j = i + 1; j-- > 0; ) 
							jacTjacim[j] += jaclm[j] * alpha; 

						 
						jacTe[i] += alpha * e[l];
					}
				}

				for (i = m; i-- > 0; ) 
					for (j = i + 1; j < m; ++j)
						jacTjac[i*m + j] = jacTjac[j*m + i];
			}
			else
			{
				LEVMAR_TRANS_MAT_MAT_MULT(jac, jacTjac, n, m);
			
				
				for (i = 0; i < m; ++i)
					jacTe[i] = 0.0;

				for (i = 0; i < n; ++i) 
				{
					register double *jacrow;

					for (l = 0, jacrow = jac + i * m, tmp = e[i]; l < m; ++l)
						jacTe[l] += jacrow[l] * tmp;
				}
			}

			for (i = 0, p_L2 = jacTe_inf = 0.0; i < m; ++i) 
			{
				if (jacTe_inf < (tmp = abs(jacTe[i]))) jacTe_inf = tmp;

				diag_jacTjac[i] = jacTjac[i*m + i]; 
				p_L2 += p[i] * p[i];
			}

		}

		
		if ((jacTe_inf <= eps1)) 
		{
			Dp_L2 = 0.0; 
			stop = 1;
			break;
		}

		
		if (k == 0) {
			for (i = 0, tmp = -1.7976931348623158e+308; i < m; ++i)
				if (diag_jacTjac[i] > tmp) tmp = diag_jacTjac[i]; /* find max diagonal element */
			mu = tau * tmp;
		}

		for (i = 0; i < m; ++i)
			jacTjac[i*m + i] += mu;

		issolved = AX_EQ_B_LU(jacTjac, jacTe, Dp, m); //A B X m
		++nlss; 
		linsolver = AX_EQ_B_LU;
	


		if (issolved) 
		{
			/* compute p's new estimate and ||Dp||^2 */
			for (i = 0, Dp_L2 = 0.0; i < m; ++i) 
			{
				pDp[i] = p[i] + (tmp = Dp[i]);
				Dp_L2 += tmp * tmp;
			}
			//Dp_L2=sqrt(Dp_L2);

			if (Dp_L2 <= eps2_sq * p_L2) 
			{ /* relative change in p is small, stop */
			//if(Dp_L2<=eps2*(p_L2 + eps2)){ /* relative change in p is small, stop */
				stop = 2;
				//break;
			}

			if (Dp_L2 >= (p_L2 + eps2) / ((1E-12)*(1E-12)))
			{ /* almost singular */
			//if(Dp_L2>=(p_L2+eps2)/LM_CNST(EPSILON)){ /* almost singular */
				stop = 4;
				break;
			}

			func(pDp, wrk, m, n, adata); ++nfev; /* evaluate function at p + Dp */
			/* compute ||e(pDp)||_2 */
			/* ### wrk2=x-wrk, pDp_eL2=||wrk2|| */
#if 1
			pDp_eL2 = LEVMAR_L2NRMXMY(wrk2, x, wrk, n);//e x hx n
			

#else
			for (i = 0, pDp_eL2 = 0.0; i < n; ++i) {
				wrk2[i] = tmp = x[i] - wrk[i];
				pDp_eL2 += tmp * tmp;
			}
#endif
			if (!_finite(pDp_eL2))
			{ /* sum of squares is not finite, most probably due to a user error.
									  * This check makes sure that the loop terminates early in the case
									  * of invalid input. Thanks to Steve Danauskas for suggesting it
									  */

				stop = 7;
				break;
			}

			dF = p_eL2 - pDp_eL2;
			if (updp || dF > 0) 
			{ /* update jac */
				for (i = 0; i < n; ++i) 
				{
					for (l = 0, tmp = 0.0; l < m; ++l)
						tmp += jac[i*m + l] * Dp[l]; /* (J * Dp)[i] */
					tmp = (wrk[i] - hx[i] - tmp) / Dp_L2; /* (f(p+dp)[i] - f(p)[i] - (J * Dp)[i])/(dp^T*dp) */
					for (j = 0; j < m; ++j)
						jac[i*m + j] += tmp * Dp[j];
				}
				++updjac;
				newjac = 1;
			}

			for (i = 0, dL = 0.0; i < m; ++i)
				dL += Dp[i] * (mu*Dp[i] + jacTe[i]);

			if (dL > 0.0 && dF > 0.0) 
			{ /* reduction in error, increment is accepted */
				tmp = ((2.0)*dF / dL - (1.0));
				tmp = (1.0) - tmp * tmp*tmp;
				mu = mu * ((tmp >= (1.0/3.0)) ? tmp : (1.0/3.0));
				nu = 2;

				for (i = 0; i < m; ++i) /* update p's estimate */
					p[i] = pDp[i];

				for (i = 0; i < n; ++i) 
				{ /* update e, hx and ||e||_2 */
					e[i] = wrk2[i]; //x[i]-wrk[i];
					hx[i] = wrk[i];
				}
				p_eL2 = pDp_eL2;
				updp = 1;
				continue;
			}
		}
		mu *= nu;
		nu2 = nu << 1; // 2*nu;
		if (nu2 <= nu) 
		{ /* nu has wrapped around (overflown). Thanks to Frank Jordan for spotting this case */
			stop = 5;
			break;
		}
		nu = nu2;

		for (i = 0; i < m; ++i) /* restore diagonal J^T J entries */
			jacTjac[i*m + i] = diag_jacTjac[i];
  
	}//end for

	if (k >= itmax) stop = 3;

	for (i = 0; i < m; ++i) /* restore diagonal J^T J entries */
		jacTjac[i*m + i] = diag_jacTjac[i];

	if (info) 
	{
		info[0] = init_p_eL2;
		info[1] = p_eL2;
		info[2] = jacTe_inf;
		info[3] = Dp_L2;
		for (i = 0, tmp = -1.7976931348623158e+308; i < m; ++i)
			if (tmp < jacTjac[i*m + i]) tmp = jacTjac[i*m + i];
		info[4] = mu / tmp;
		info[5] = (double)k;
		info[6] = (double)stop;
		info[7] = (double)nfev;
		info[8] = (double)njap;
		info[9] = (double)nlss;
	}

	if (covar) {
		LEVMAR_COVAR(jacTjac, covar, p_eL2, m, n);

	}

	if (freework) free(work);


	return (stop != 4 && stop != 7) ? k : -1;
}

int CameraDataProcess::AX_EQ_B_LU(double * A, double * B, double * x, int m)
{
		void *buf = NULL;
			int buf_sz = 0;

			register int i, j, k;
			int *idx, maxi = -1, idx_sz, a_sz, work_sz, tot_sz;
			double *a, *work, max, sum, tmp;

			if (!A) return 1;

			idx_sz = m;
			a_sz = m * m;
			work_sz = m;
			tot_sz = (a_sz + work_sz) * sizeof(double) + idx_sz * sizeof(int);

			buf_sz = tot_sz;
			buf = (void *)malloc(tot_sz);
			if (!buf) {
				fprintf(stderr, ("memory allocation in  AX_EQ_B_LU() failed!\n"));
				exit(1);
			}

			a = static_cast<double*>(buf);
			work = a + a_sz;
			idx = (int *)(work + work_sz);

			/* avoid destroying A, B by copying them to a, x resp. */
			memcpy(a, A, a_sz * sizeof(double));
			memcpy(x, B, m * sizeof(double));

			for (i = 0; i < m; ++i)
			{
				max = 0.0;
				for (j = 0; j < m; ++j)
					if ((tmp = abs(a[i*m + j])) > max)
						max = tmp;
				if (max == 0.0)
				{
					fprintf(stderr, ("Singular matrix A in  AX_EQ_B_LU()!\n"));

					free(buf);
					return 0;
				}
				work[i] = (float)(1.0) / max;
			}

			for (j = 0; j < m; ++j)
			{
				for (i = 0; i < j; ++i)
				{
					sum = a[i*m + j];
					for (k = 0; k < i; ++k)
						sum -= a[i*m + k] * a[k*m + j];
					a[i*m + j] = sum;
				}
				max = 0.0;
				for (i = j; i < m; ++i)
				{
					sum = a[i*m + j];
					for (k = 0; k < j; ++k)
						sum -= a[i*m + k] * a[k*m + j];
					a[i*m + j] = sum;
					if ((tmp = work[i] * abs(sum)) >= max)
					{
						max = tmp;
						maxi = i;
					}
				}
				if (j != maxi)
				{
					for (k = 0; k < m; ++k)
					{
						tmp = a[maxi*m + k];
						a[maxi*m + k] = a[j*m + k];
						a[j*m + k] = tmp;
					}
					work[maxi] = work[j];
				}
				idx[j] = maxi;
				if (a[j*m + j] == 0.0)
					a[j*m + j] = 1.192092896e-07F;
				if (j != m - 1)
				{
					tmp = (float)(1.0) / (a[j*m + j]);
					for (i = j + 1; i < m; ++i)
						a[i*m + j] *= tmp;
				}
			}

			for (i = k = 0; i < m; ++i) {
				j = idx[i];
				sum = x[j];
				x[j] = x[i];
				if (k != 0)
					for (j = k - 1; j < i; ++j)
						sum -= a[i*m + j] * x[j];
				else
					if (sum != 0.0)
						k = i + 1;
				x[i] = sum;
			}

			for (i = m - 1; i >= 0; --i) {
				sum = x[i];
				for (j = i + 1; j < m; ++j)
					sum -= a[i*m + j] * x[j];
				x[i] = sum / a[i*m + i];
			}
			free(buf);
			return 1;
}

double CameraDataProcess::LEVMAR_L2NRMXMY(double * e, double * x, double * y, int n)
{
	const int blocksize = 8, bpwr = 3; /* 8=2^3 */
	register int i;
	int j1, j2, j3, j4, j5, j6, j7;
	int blockn;
	register double sum0 = 0.0, sum1 = 0.0, sum2 = 0.0, sum3 = 0.0;

	blockn = (n >> bpwr) << bpwr;

	if (x)
	{
		for (i = blockn - 1; i > 0; i -= blocksize)
		{
			e[i] = x[i] - y[i]; sum0 += e[i] * e[i];
			j1 = i - 1; e[j1] = x[j1] - y[j1]; sum1 += e[j1] * e[j1];
			j2 = i - 2; e[j2] = x[j2] - y[j2]; sum2 += e[j2] * e[j2];
			j3 = i - 3; e[j3] = x[j3] - y[j3]; sum3 += e[j3] * e[j3];
			j4 = i - 4; e[j4] = x[j4] - y[j4]; sum0 += e[j4] * e[j4];
			j5 = i - 5; e[j5] = x[j5] - y[j5]; sum1 += e[j5] * e[j5];
			j6 = i - 6; e[j6] = x[j6] - y[j6]; sum2 += e[j6] * e[j6];
			j7 = i - 7; e[j7] = x[j7] - y[j7]; sum3 += e[j7] * e[j7];
		}


		i = blockn;
		if (i < n)
		{

			switch (n - i)
			{
			case 7: e[i] = x[i] - y[i]; sum0 += e[i] * e[i]; ++i;
			case 6: e[i] = x[i] - y[i]; sum1 += e[i] * e[i]; ++i;
			case 5: e[i] = x[i] - y[i]; sum2 += e[i] * e[i]; ++i;
			case 4: e[i] = x[i] - y[i]; sum3 += e[i] * e[i]; ++i;
			case 3: e[i] = x[i] - y[i]; sum0 += e[i] * e[i]; ++i;
			case 2: e[i] = x[i] - y[i]; sum1 += e[i] * e[i]; ++i;
			case 1: e[i] = x[i] - y[i]; sum2 += e[i] * e[i]; //++i;
			}
		}
	}
	else
	{
		for (i = blockn - 1; i > 0; i -= blocksize)
		{
			e[i] = -y[i]; sum0 += e[i] * e[i];
			j1 = i - 1; e[j1] = -y[j1]; sum1 += e[j1] * e[j1];
			j2 = i - 2; e[j2] = -y[j2]; sum2 += e[j2] * e[j2];
			j3 = i - 3; e[j3] = -y[j3]; sum3 += e[j3] * e[j3];
			j4 = i - 4; e[j4] = -y[j4]; sum0 += e[j4] * e[j4];
			j5 = i - 5; e[j5] = -y[j5]; sum1 += e[j5] * e[j5];
			j6 = i - 6; e[j6] = -y[j6]; sum2 += e[j6] * e[j6];
			j7 = i - 7; e[j7] = -y[j7]; sum3 += e[j7] * e[j7];
		}



		i = blockn;
		if (i < n)
		{


			switch (n - i)
			{
			case 7: e[i] = -y[i]; sum0 += e[i] * e[i]; ++i;
			case 6: e[i] = -y[i]; sum1 += e[i] * e[i]; ++i;
			case 5: e[i] = -y[i]; sum2 += e[i] * e[i]; ++i;
			case 4: e[i] = -y[i]; sum3 += e[i] * e[i]; ++i;
			case 3: e[i] = -y[i]; sum0 += e[i] * e[i]; ++i;
			case 2: e[i] = -y[i]; sum1 += e[i] * e[i]; ++i;
			case 1: e[i] = -y[i]; sum2 += e[i] * e[i]; //++i;
			}
		}
	}
	return sum0 + sum1 + sum2 + sum3;
}

void CameraDataProcess::LEVMAR_FDIF_FORW_JAC_APPROX(double * p, double * hx, double * hxx, double delta, double * jac, int m, int n, void * adata)
{
	register int i, j;
	double tmp;
	register double d;
	for (j = 0; j < m; ++j)
	{
		/* determine d=max(1E-04*|p[j]|, delta), see HZ */
		d = (float)(1E-04)*p[j];
		d = abs(d);
		if (d < delta)
			d = delta;

		tmp = p[j];
		p[j] += d;

		func(p, hxx, m, n, adata);

		p[j] = tmp; /* restore */

		d = (float)(1.0) / d;
		for (i = 0; i < n; ++i) {
			jac[i*m + j] = (hxx[i] - hx[i])*d;
		}
	}
}

void CameraDataProcess::LEVMAR_FDIF_CENT_JAC_APPROX( double * p, double * hxm, double * hxp, double delta, double * jac, int m, int n, void * adata)
{
	register int i, j;
	double tmp;
	register double d;

	for (j = 0; j < m; ++j)
	{
		/* determine d=max(1E-04*|p[j]|, delta), see HZ */
		d = (float)(1E-04)*p[j]; // force evaluation
		d = abs(d);
		if (d < delta)
			d = delta;

		tmp = p[j];
		p[j] -= d;
		func(p, hxm, m, n, adata);

		p[j] = tmp + d;
		func(p, hxp, m, n, adata);
		p[j] = tmp; /* restore */

		d = (float)(0.5) / d; /* invert so that divisions can be carried out faster as multiplications */
		for (i = 0; i < n; ++i) {
			jac[i*m + j] = (hxp[i] - hxm[i])*d;
		}
	}
}

void CameraDataProcess::LEVMAR_TRANS_MAT_MAT_MULT(double * a, double * b, int n, int m)
{
	register int i, j, k, jj, kk;
	register double sum, *bim, *akm;
	const int bsize = 32;
#define __MIN__(x, y) (((x)<=(y))? (x) : (y))
#define __MAX__(x, y) (((x)>=(y))? (x) : (y))
	for (jj = 0; jj < m; jj += bsize)
	{
		for (i = 0; i < m; ++i)
		{
			bim = b + i * m;
			for (j = __MAX__(jj, i); j < __MIN__(jj + bsize, m); ++j)
				bim[j] = 0.0;
		}

		for (kk = 0; kk < n; kk += bsize)
		{
			for (i = 0; i < m; ++i)
			{
				bim = b + i * m;
				for (j = __MAX__(jj, i); j < __MIN__(jj + bsize, m); ++j)
				{
					sum = 0.0;
					for (k = kk; k < __MIN__(kk + bsize, n); ++k)
					{
						akm = a + k * m;
						sum += akm[i] * akm[j];
					}
					bim[j] += sum;
				}
			}
		}
	}


	for (i = 0; i < m; ++i)
		for (j = 0; j < i; ++j)
			b[i*m + j] = b[j*m + i];

#undef __MIN__
#undef __MAX__
}

int CameraDataProcess::LEVMAR_COVAR(double * JtJ, double * C, double sumsq, int m, int n)
{
	register int i;
	int rnk;
	double fact;

	rnk = LEVMAR_LUINVERSE(JtJ, C, m);//A B m
	
	if (!rnk) {}
	else
	{
		rnk = m;

		fact = sumsq / (n - rnk);
		for (i = 0; i < m*m; ++i)
			C[i] *= fact;
	}
	return rnk;
}

int CameraDataProcess::LEVMAR_LUINVERSE(double * A, double * B, int m)
{
	void *buf = NULL;
	int buf_sz = 0;

	register int i, j, k, l;
	int *idx, maxi = -1, idx_sz, a_sz, x_sz, work_sz, tot_sz;
	double *a, *x, *work, max, sum, tmp;

	/* calculate required memory size */
	idx_sz = m;
	a_sz = m * m;
	x_sz = m;
	work_sz = m;
	tot_sz = (a_sz + x_sz + work_sz) * sizeof(double) + idx_sz * sizeof(int); /* should be arranged in that order for proper doubles alignment */

	buf_sz = tot_sz;
	buf = (void *)malloc(tot_sz);
	if (!buf) {
		fprintf(stderr, ("memory allocation in  LEVMAR_LUINVERSE) () failed!\n"));
		return 0; /* error */
	}

	a = static_cast<double*>(buf);
	x = a + a_sz;
	work = x + x_sz;
	idx = (int *)(work + work_sz);

	/* avoid destroying A by copying it to a */
	for (i = 0; i < a_sz; ++i) a[i] = A[i];

	/* compute the LU decomposition of a row permutation of matrix a; the permutation itself is saved in idx[] */
	for (i = 0; i < m; ++i) {
		max = 0.0;
		for (j = 0; j < m; ++j)
			if ((tmp = abs(a[i*m + j])) > max)
				max = tmp;
		if (max == 0.0) {
			fprintf(stderr, ("Singular matrix A in LEVMAR_LUINVERSE ()!\n"));
			free(buf);

			return 0;
		}
		work[i] = (1.0) / max;
	}

	for (j = 0; j < m; ++j) {
		for (i = 0; i < j; ++i) {
			sum = a[i*m + j];
			for (k = 0; k < i; ++k)
				sum -= a[i*m + k] * a[k*m + j];
			a[i*m + j] = sum;
		}
		max = 0.0;
		for (i = j; i < m; ++i) {
			sum = a[i*m + j];
			for (k = 0; k < j; ++k)
				sum -= a[i*m + k] * a[k*m + j];
			a[i*m + j] = sum;
			if ((tmp = work[i] * abs(sum)) >= max) {
				max = tmp;
				maxi = i;
			}
		}
		if (j != maxi) {
			for (k = 0; k < m; ++k) {
				tmp = a[maxi*m + k];
				a[maxi*m + k] = a[j*m + k];
				a[j*m + k] = tmp;
			}
			work[maxi] = work[j];
		}
		idx[j] = maxi;
		if (a[j*m + j] == 0.0)
			a[j*m + j] = 2.2204460492503131e-016;
		if (j != m - 1) {
			tmp = (1.0) / (a[j*m + j]);
			for (i = j + 1; i < m; ++i)
				a[i*m + j] *= tmp;
		}
	}

	/* The decomposition has now replaced a. Solve the m linear systems using
	 * forward and back substitution
	 */
	for (l = 0; l < m; ++l) {
		for (i = 0; i < m; ++i) x[i] = 0.0;
		x[l] = (1.0);

		for (i = k = 0; i < m; ++i) {
			j = idx[i];
			sum = x[j];
			x[j] = x[i];
			if (k != 0)
				for (j = k - 1; j < i; ++j)
					sum -= a[i*m + j] * x[j];
			else
				if (sum != 0.0)
					k = i + 1;
			x[i] = sum;
		}

		for (i = m - 1; i >= 0; --i) {
			sum = x[i];
			for (j = i + 1; j < m; ++j)
				sum -= a[i*m + j] * x[j];
			x[i] = sum / a[i*m + i];
		}

		for (i = 0; i < m; ++i)
			B[i*m + l] = x[i];
	}

	free(buf);

	return 1;
}

void CameraDataProcess::func(double * p, double * x, int m, int n, void * data)
{
	double* data1 = (double*)data;

	for (int i = 0; i < n; i++)
	{
		x[i] = 0;
		for (int j = 0; j < 8; j++)
		{
			x[i] += p[j * 3] * exp(-pow(data1[i] - p[j * 3 + 1], 2) / p[j * 3 + 2]);
		}
		x[i] += p[24];
	}
}
