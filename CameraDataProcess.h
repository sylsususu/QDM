#pragma once
#include <QImage>
#include <stdlib.h>
#include <opencv2/opencv.hpp>
#include<qtextstream.h>
using namespace std;

class CameraDataProcess
{
public:  //声明静态成员函数

	/// \brief 相机数据转换成12bit的int数据
	/// \param [in]inputbyte     相机原数据
	/// \param [in]camera_width  图片的宽
	/// \param [in]camera_height 图片的高
	/// \param [out] outputarray 转换后的12bit的int数据
	/// \return 成功返回 0
	static int rawChangetoInt(unsigned char* inputbyte, int img_width, int img_height, QVector<int>& outputarray);

	/// \brief 相机数据转换成12bit的int数据
	/// \param [in]inputbyte				相机原数据
	/// \param [in]img_width				转换后图片的宽
	/// \param [in]img_height				转换后图片的高
	/// \param [out] img					转换后mat图片
	/// \return								成功返回 0
	static int rawChangetoMat(unsigned char* inputbyte, int img_width, int img_height, cv::Mat& outputimg);

	/// \brief 将12bit的int，按照Roi区域划分
	/// \param [in] roi       roi区域算法，只计算roi区域的数据
	/// \param [out] v_12int  存放将m_Rawbuffer拆分后的12bit的int数据
	/// \return  成功返回0
	static int intChangetoRoiInt(int img_width, int img_height, QVector<int>& v_12int, QRect roi, QVector<int>& v_12int_roi);

	/// \brief 相除累加算法
	/// \param [in] v_molecule    分子数组
	/// \param [in] v_denominator 分母数组
	/// \param [out] v_add        累加数组
	/// \保证三个数组size一致
	/// \return  成功返回0
	static int mydivisionadd(QVector<int>& v_molecule, QVector<int>& v_denominator, QVector<int>& v_add);


	/// \brief 求一个vector的均值
	/// \param [in] v_tmp 待求均值的vector
	/// \return int,成功返回均值
	static double myaverage(QVector<int>& v_tmp);

	/// \brief 12bit的int数据经过压缩到0-255转换成Qiamge
	/// \param [in]img_width  图片的宽
	/// \param [in]img_height 图片的高
	/// \param [in]inputarray 12bit的int数据
	/// \return 成功返回 QImage
	static QImage intChangetoQimg(int img_width, int img_height, QVector<int>& inputarray);

	/// \brief 将double数据，根据比色卡上下限转换到0-255，再转换到伪彩图
	/// \param [in]img_width  图片的宽
	/// \param [in]img_height 图片的高
	/// \param [in] magnetic_strength 需要转换的磁场强度数组
	/// \param [in] down 比色卡下限
	/// \param [in] up 比色卡上限
	/// \param [in] image0 渐变图的图片，需要在界面上设置grab函数抓取
	/// \return 成功返回QImage
	static QImage intChangetoQcolorimg(int img_width, int img_height, const QVector<double>& magnetic_strength, double down, double up, QImage& image0);

	/// \brief 将相机原数据，保存为Mat图片
	/// \param [in]img_width				图片的宽
	/// \param [in]img_height				图片的高
	/// \param [in] Rawbuffer		        需要保存的相机原数据
	/// \param [in] imgpath					保存图片的路径 比如：img/snapmat.png
	/// \return								成功返回0
	static int saveRawMat(int img_width, int img_height, unsigned char* Rawbuffer, string savepath);


	/// \brief 读取路径下的Mat图片，转换成相机原数据
	/// \param [in]imgpath					需要读取图片的路径 比如：img/snapmat.png
	/// \param [out]Rawbuff					得到的相机原数据
	/// \return								成功返回0
	static int readRawMat(string imgpath, unsigned char* Rawbuff);

	/// \brief 读取路径下的16RAW数据，转换QVector<int>(0-4096)
	/// \param [in]rawpath					需要读取RAW的路径 比如：img/snapmat.png
	/// \param [in]imgWidth					图片宽
	/// \param [in]rawpath					图片高
	/// \param [out]v_12int					得到的12bit数据
	/// \return								成功返回0
	static int  read16Raw(string rawpath, int imgWidth, int imgHeight, QVector<ushort>& v_12int);

	/// <summary>
	/// double类型mat转QVector
	/// </summary>
	/// <param name="inputarray"></param>
	/// <param name="v_double"></param>
	/// <returns></returns>
	static int matToQVector(cv::Mat inputarray, QVector<double>& v_double);

	/// <summary>
	/// 读入用于测试的标准磁场文件txt
	/// </summary>
	/// <param name="fileName"></param>
	/// <param name="width"></param>
	/// <param name="height"></param>
	/// <param name="resultVec"></param>
	static void readTestTxt(QString fileName, int width, int height, QVector<double>& resultVec);


	//高斯单峰拟合
	static bool gaussiantCurveFit(const vector<cv::Point2d>& cvFitPointVec, int n, double& a, double& b);


	//读取保存的tiff图片，保存成QVector
	static void readTiff(QString fileName, int &width, int &height, QVector<float>& resultVec);

	//通过有限差分近似雅可比矩阵
	static int LevmarDif( double *p, double *x, int m, int n, int itmax, double opts[5], double info[10], double *work, double *covar, void *adata);

	static int AX_EQ_B_LU(double *A, double *B, double *x, int m);

	static double  LEVMAR_L2NRMXMY(double *e, double *x, double *y, int n);

	static void LEVMAR_FDIF_FORW_JAC_APPROX(
		/* function to differentiate */
		double *p,              /* I: current parameter estimate, mx1 */
		double *hx,             /* I: func evaluated at p, i.e. hx=func(p), nx1 */
		double *hxx,            /* W/O: work array for evaluating func(p+delta), nx1 */
		double delta,           /* increment for computing the Jacobian */
		double *jac,            /* O: array for storing approximated Jacobian, nxm */
		int m,
		int n,
		void *adata);

	static void LEVMAR_FDIF_CENT_JAC_APPROX(
		/* function to differentiate */
		double *p,              /* I: current parameter estimate, mx1 */
		double *hxm,            /* W/O: work array for evaluating func(p-delta), nx1 */
		double *hxp,            /* W/O: work array for evaluating func(p+delta), nx1 */
		double delta,           /* increment for computing the Jacobian */
		double *jac,            /* O: array for storing approximated Jacobian, nxm */
		int m,
		int n,
		void *adata);

	static void LEVMAR_TRANS_MAT_MAT_MULT(double *a, double *b, int n, int m);

	static int LEVMAR_COVAR(double *JtJ, double *C, double sumsq, int m, int n);

	static int LEVMAR_LUINVERSE(double *A, double *B, int m);

	static void func(double* p, double* x, int m, int n, void* data);
};

