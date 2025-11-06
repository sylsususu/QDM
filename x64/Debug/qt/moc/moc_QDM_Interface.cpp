/****************************************************************************
** Meta object code from reading C++ file 'QDM_Interface.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../QDM_Interface.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QVector>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'QDM_Interface.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_QDM_Interface_t {
    QByteArrayData data[208];
    char stringdata0[2620];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_QDM_Interface_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_QDM_Interface_t qt_meta_stringdata_QDM_Interface = {
    {
QT_MOC_LITERAL(0, 0, 13), // "QDM_Interface"
QT_MOC_LITERAL(1, 14, 22), // "on_MouseMoveCustomplot"
QT_MOC_LITERAL(2, 37, 0), // ""
QT_MOC_LITERAL(3, 38, 12), // "QMouseEvent*"
QT_MOC_LITERAL(4, 51, 24), // "on_MouseMoveGraphicsView"
QT_MOC_LITERAL(5, 76, 11), // "connectWave"
QT_MOC_LITERAL(6, 88, 10), // "setFreMode"
QT_MOC_LITERAL(7, 99, 12), // "sendWaveMode"
QT_MOC_LITERAL(8, 112, 12), // "sendSweepFre"
QT_MOC_LITERAL(9, 125, 10), // "sendFixFre"
QT_MOC_LITERAL(10, 136, 9), // "startWave"
QT_MOC_LITERAL(11, 146, 9), // "resetWave"
QT_MOC_LITERAL(12, 156, 13), // "getWaveStatus"
QT_MOC_LITERAL(13, 170, 13), // "connectCamera"
QT_MOC_LITERAL(14, 184, 15), // "setExposureMode"
QT_MOC_LITERAL(15, 200, 15), // "setExposureTime"
QT_MOC_LITERAL(16, 216, 14), // "setTriggerMode"
QT_MOC_LITERAL(17, 231, 15), // "softTriggerOnce"
QT_MOC_LITERAL(18, 247, 11), // "savePicture"
QT_MOC_LITERAL(19, 259, 10), // "choosePath"
QT_MOC_LITERAL(20, 270, 11), // "setAutoSave"
QT_MOC_LITERAL(21, 282, 6), // "setRoi"
QT_MOC_LITERAL(22, 289, 10), // "showCapImg"
QT_MOC_LITERAL(23, 300, 7), // "cv::Mat"
QT_MOC_LITERAL(24, 308, 7), // "showMat"
QT_MOC_LITERAL(25, 316, 15), // "autoFindExpTime"
QT_MOC_LITERAL(26, 332, 7), // "showFps"
QT_MOC_LITERAL(27, 340, 8), // "showFps2"
QT_MOC_LITERAL(28, 349, 1), // "t"
QT_MOC_LITERAL(29, 351, 9), // "saveImage"
QT_MOC_LITERAL(30, 361, 5), // "image"
QT_MOC_LITERAL(31, 367, 11), // "std::string"
QT_MOC_LITERAL(32, 379, 8), // "filename"
QT_MOC_LITERAL(33, 388, 10), // "setBinning"
QT_MOC_LITERAL(34, 399, 10), // "setCapMode"
QT_MOC_LITERAL(35, 410, 7), // "setGain"
QT_MOC_LITERAL(36, 418, 28), // "onContrastSliderValueChanged"
QT_MOC_LITERAL(37, 447, 25), // "onGammaSliderValueChanged"
QT_MOC_LITERAL(38, 473, 24), // "onGainSliderValueChanged"
QT_MOC_LITERAL(39, 498, 22), // "onlineEditValueChanged"
QT_MOC_LITERAL(40, 521, 20), // "openPulseSettingPage"
QT_MOC_LITERAL(41, 542, 16), // "clearPulseManual"
QT_MOC_LITERAL(42, 559, 13), // "SetPulseParam"
QT_MOC_LITERAL(43, 573, 9), // "cycleTime"
QT_MOC_LITERAL(44, 583, 12), // "pulseNumbers"
QT_MOC_LITERAL(45, 596, 14), // "QVector<float>"
QT_MOC_LITERAL(46, 611, 2), // "A0"
QT_MOC_LITERAL(47, 614, 2), // "A1"
QT_MOC_LITERAL(48, 617, 2), // "A2"
QT_MOC_LITERAL(49, 620, 18), // "SetPulseTimesParam"
QT_MOC_LITERAL(50, 639, 12), // "startTime0_0"
QT_MOC_LITERAL(51, 652, 10), // "ctuTime0_0"
QT_MOC_LITERAL(52, 663, 12), // "startTime1_0"
QT_MOC_LITERAL(53, 676, 10), // "ctuTime1_0"
QT_MOC_LITERAL(54, 687, 12), // "startTime1_1"
QT_MOC_LITERAL(55, 700, 10), // "ctuTime1_1"
QT_MOC_LITERAL(56, 711, 12), // "startTime2_0"
QT_MOC_LITERAL(57, 724, 10), // "ctuTime2_0"
QT_MOC_LITERAL(58, 735, 12), // "connectPulse"
QT_MOC_LITERAL(59, 748, 12), // "connectMotor"
QT_MOC_LITERAL(60, 761, 8), // "findZero"
QT_MOC_LITERAL(61, 770, 18), // "recordLoadPosition"
QT_MOC_LITERAL(62, 789, 20), // "recordUnloadPosition"
QT_MOC_LITERAL(63, 810, 7), // "loadPos"
QT_MOC_LITERAL(64, 818, 9), // "unloadPos"
QT_MOC_LITERAL(65, 828, 9), // "motorStop"
QT_MOC_LITERAL(66, 838, 12), // "motorForward"
QT_MOC_LITERAL(67, 851, 13), // "motorBackward"
QT_MOC_LITERAL(68, 865, 9), // "motorLeft"
QT_MOC_LITERAL(69, 875, 10), // "motorRight"
QT_MOC_LITERAL(70, 886, 7), // "motorUp"
QT_MOC_LITERAL(71, 894, 9), // "motorDown"
QT_MOC_LITERAL(72, 904, 12), // "setMotorMode"
QT_MOC_LITERAL(73, 917, 13), // "motorSlowStop"
QT_MOC_LITERAL(74, 931, 10), // "findZeroOk"
QT_MOC_LITERAL(75, 942, 12), // "showMotorPos"
QT_MOC_LITERAL(76, 955, 5), // "pos_x"
QT_MOC_LITERAL(77, 961, 5), // "pos_y"
QT_MOC_LITERAL(78, 967, 5), // "pos_z"
QT_MOC_LITERAL(79, 973, 14), // "setMotorXButon"
QT_MOC_LITERAL(80, 988, 5), // "isRun"
QT_MOC_LITERAL(81, 994, 14), // "setMotorYButon"
QT_MOC_LITERAL(82, 1009, 14), // "setMotorZButon"
QT_MOC_LITERAL(83, 1024, 13), // "setButtonAble"
QT_MOC_LITERAL(84, 1038, 6), // "enable"
QT_MOC_LITERAL(85, 1045, 14), // "connectCurrent"
QT_MOC_LITERAL(86, 1060, 9), // "openLaser"
QT_MOC_LITERAL(87, 1070, 7), // "openLed"
QT_MOC_LITERAL(88, 1078, 12), // "connectLight"
QT_MOC_LITERAL(89, 1091, 7), // "Current"
QT_MOC_LITERAL(90, 1099, 8), // "_current"
QT_MOC_LITERAL(91, 1108, 7), // "voltage"
QT_MOC_LITERAL(92, 1116, 9), // "CurrentOK"
QT_MOC_LITERAL(93, 1126, 9), // "VoltageOK"
QT_MOC_LITERAL(94, 1136, 5), // "OutOK"
QT_MOC_LITERAL(95, 1142, 19), // "CurrentAndVoltageOK"
QT_MOC_LITERAL(96, 1162, 10), // "currentOut"
QT_MOC_LITERAL(97, 1173, 10), // "currentSet"
QT_MOC_LITERAL(98, 1184, 14), // "connectCoilXYZ"
QT_MOC_LITERAL(99, 1199, 8), // "coilXSet"
QT_MOC_LITERAL(100, 1208, 8), // "coilXOut"
QT_MOC_LITERAL(101, 1217, 8), // "coilYSet"
QT_MOC_LITERAL(102, 1226, 8), // "coilYOut"
QT_MOC_LITERAL(103, 1235, 8), // "coilZSet"
QT_MOC_LITERAL(104, 1244, 8), // "coilZOut"
QT_MOC_LITERAL(105, 1253, 10), // "CoilXOutOK"
QT_MOC_LITERAL(106, 1264, 24), // "CoilXCurrentAndVoltageOK"
QT_MOC_LITERAL(107, 1289, 10), // "CoilYOutOK"
QT_MOC_LITERAL(108, 1300, 24), // "CoilYCurrentAndVoltageOK"
QT_MOC_LITERAL(109, 1325, 10), // "CoilZOutOK"
QT_MOC_LITERAL(110, 1336, 24), // "CoilZCurrentAndVoltageOK"
QT_MOC_LITERAL(111, 1361, 8), // "CurrentX"
QT_MOC_LITERAL(112, 1370, 8), // "CurrentY"
QT_MOC_LITERAL(113, 1379, 8), // "CurrentZ"
QT_MOC_LITERAL(114, 1388, 17), // "startSweepMeasure"
QT_MOC_LITERAL(115, 1406, 9), // "stopSweep"
QT_MOC_LITERAL(116, 1416, 18), // "startFixFreMeasure"
QT_MOC_LITERAL(117, 1435, 10), // "stopFixFre"
QT_MOC_LITERAL(118, 1446, 14), // "startAllFixFre"
QT_MOC_LITERAL(119, 1461, 13), // "drawSweepData"
QT_MOC_LITERAL(120, 1475, 16), // "processSweepData"
QT_MOC_LITERAL(121, 1492, 2), // "on"
QT_MOC_LITERAL(122, 1495, 3), // "off"
QT_MOC_LITERAL(123, 1499, 17), // "processSweepData2"
QT_MOC_LITERAL(124, 1517, 8), // "frevalue"
QT_MOC_LITERAL(125, 1526, 5), // "count"
QT_MOC_LITERAL(126, 1532, 14), // "unsigned char*"
QT_MOC_LITERAL(127, 1547, 9), // "rawBuffer"
QT_MOC_LITERAL(128, 1557, 12), // "showSweepPic"
QT_MOC_LITERAL(129, 1570, 10), // "clearPulse"
QT_MOC_LITERAL(130, 1581, 13), // "showFixFreImg"
QT_MOC_LITERAL(131, 1595, 5), // "onmat"
QT_MOC_LITERAL(132, 1601, 6), // "offmat"
QT_MOC_LITERAL(133, 1608, 17), // "fastShowFixFreImg"
QT_MOC_LITERAL(134, 1626, 5), // "index"
QT_MOC_LITERAL(135, 1632, 6), // "tmpmat"
QT_MOC_LITERAL(136, 1639, 12), // "sweepLostPic"
QT_MOC_LITERAL(137, 1652, 10), // "fixLostPic"
QT_MOC_LITERAL(138, 1663, 8), // "sendPlus"
QT_MOC_LITERAL(139, 1672, 1), // "s"
QT_MOC_LITERAL(140, 1674, 15), // "changeLockState"
QT_MOC_LITERAL(141, 1690, 14), // "importPicNoMag"
QT_MOC_LITERAL(142, 1705, 16), // "importPicWithMag"
QT_MOC_LITERAL(143, 1722, 21), // "averODMRAnalysisNoMag"
QT_MOC_LITERAL(144, 1744, 23), // "averODMRAnalysisWithMag"
QT_MOC_LITERAL(145, 1768, 16), // "getInitParaNoMag"
QT_MOC_LITERAL(146, 1785, 18), // "getInitParaWithMag"
QT_MOC_LITERAL(147, 1804, 10), // "changePara"
QT_MOC_LITERAL(148, 1815, 3), // "row"
QT_MOC_LITERAL(149, 1819, 3), // "col"
QT_MOC_LITERAL(150, 1823, 17), // "importParaWithMag"
QT_MOC_LITERAL(151, 1841, 15), // "importParaNoMag"
QT_MOC_LITERAL(152, 1857, 13), // "saveParaNoMag"
QT_MOC_LITERAL(153, 1871, 15), // "saveParaWithMag"
QT_MOC_LITERAL(154, 1887, 13), // "loadNoMagData"
QT_MOC_LITERAL(155, 1901, 16), // "setDataDimension"
QT_MOC_LITERAL(156, 1918, 17), // "findAllSinglePeak"
QT_MOC_LITERAL(157, 1936, 14), // "vector<double>"
QT_MOC_LITERAL(158, 1951, 5), // "x_Vec"
QT_MOC_LITERAL(159, 1957, 5), // "y_Vec"
QT_MOC_LITERAL(160, 1963, 12), // "vector<int>&"
QT_MOC_LITERAL(161, 1976, 12), // "peakIndexVec"
QT_MOC_LITERAL(162, 1989, 22), // "findAllSinglePeak_auto"
QT_MOC_LITERAL(163, 2012, 9), // "findIndex"
QT_MOC_LITERAL(164, 2022, 19), // "std::vector<double>"
QT_MOC_LITERAL(165, 2042, 4), // "data"
QT_MOC_LITERAL(166, 2047, 5), // "value"
QT_MOC_LITERAL(167, 2053, 18), // "startAnalysisNoMag"
QT_MOC_LITERAL(168, 2072, 20), // "startAnalysisWithMag"
QT_MOC_LITERAL(169, 2093, 16), // "startAllAnalysis"
QT_MOC_LITERAL(170, 2110, 15), // "calMagDirection"
QT_MOC_LITERAL(171, 2126, 16), // "openColorMapPage"
QT_MOC_LITERAL(172, 2143, 16), // "contrastAnalysis"
QT_MOC_LITERAL(173, 2160, 15), // "setAnalysisMode"
QT_MOC_LITERAL(174, 2176, 14), // "setAnalysisRoi"
QT_MOC_LITERAL(175, 2191, 19), // "SetAnalysisRoiParam"
QT_MOC_LITERAL(176, 2211, 1), // "x"
QT_MOC_LITERAL(177, 2213, 1), // "y"
QT_MOC_LITERAL(178, 2215, 1), // "w"
QT_MOC_LITERAL(179, 2217, 1), // "h"
QT_MOC_LITERAL(180, 2219, 22), // "CancelAnalysisRoiParam"
QT_MOC_LITERAL(181, 2242, 9), // "calParams"
QT_MOC_LITERAL(182, 2252, 14), // "calSensitivity"
QT_MOC_LITERAL(183, 2267, 18), // "openRoiAnalysePage"
QT_MOC_LITERAL(184, 2286, 15), // "mousePressEvent"
QT_MOC_LITERAL(185, 2302, 5), // "event"
QT_MOC_LITERAL(186, 2308, 14), // "mouseMoveEvent"
QT_MOC_LITERAL(187, 2323, 25), // "on_minimizeButton_clicked"
QT_MOC_LITERAL(188, 2349, 22), // "on_closeButton_clicked"
QT_MOC_LITERAL(189, 2372, 11), // "startAllOut"
QT_MOC_LITERAL(190, 2384, 11), // "addLogEntry"
QT_MOC_LITERAL(191, 2396, 10), // "logMessage"
QT_MOC_LITERAL(192, 2407, 10), // "QTextEdit*"
QT_MOC_LITERAL(193, 2418, 8), // "textEdit"
QT_MOC_LITERAL(194, 2427, 8), // "clearLog"
QT_MOC_LITERAL(195, 2436, 8), // "ClearLog"
QT_MOC_LITERAL(196, 2445, 20), // "onRadioButtonToggled"
QT_MOC_LITERAL(197, 2466, 7), // "checked"
QT_MOC_LITERAL(198, 2474, 21), // "onRadioButtonToggled0"
QT_MOC_LITERAL(199, 2496, 24), // "onRadioButtonToggledGain"
QT_MOC_LITERAL(200, 2521, 13), // "showGrayvalue"
QT_MOC_LITERAL(201, 2535, 15), // "updateGrayValue"
QT_MOC_LITERAL(202, 2551, 13), // "LinearSmooth3"
QT_MOC_LITERAL(203, 2565, 15), // "vector<double>&"
QT_MOC_LITERAL(204, 2581, 5), // "input"
QT_MOC_LITERAL(205, 2587, 4), // "size"
QT_MOC_LITERAL(206, 2592, 13), // "LinearSmooth5"
QT_MOC_LITERAL(207, 2606, 13) // "LinearSmooth7"

    },
    "QDM_Interface\0on_MouseMoveCustomplot\0"
    "\0QMouseEvent*\0on_MouseMoveGraphicsView\0"
    "connectWave\0setFreMode\0sendWaveMode\0"
    "sendSweepFre\0sendFixFre\0startWave\0"
    "resetWave\0getWaveStatus\0connectCamera\0"
    "setExposureMode\0setExposureTime\0"
    "setTriggerMode\0softTriggerOnce\0"
    "savePicture\0choosePath\0setAutoSave\0"
    "setRoi\0showCapImg\0cv::Mat\0showMat\0"
    "autoFindExpTime\0showFps\0showFps2\0t\0"
    "saveImage\0image\0std::string\0filename\0"
    "setBinning\0setCapMode\0setGain\0"
    "onContrastSliderValueChanged\0"
    "onGammaSliderValueChanged\0"
    "onGainSliderValueChanged\0"
    "onlineEditValueChanged\0openPulseSettingPage\0"
    "clearPulseManual\0SetPulseParam\0cycleTime\0"
    "pulseNumbers\0QVector<float>\0A0\0A1\0A2\0"
    "SetPulseTimesParam\0startTime0_0\0"
    "ctuTime0_0\0startTime1_0\0ctuTime1_0\0"
    "startTime1_1\0ctuTime1_1\0startTime2_0\0"
    "ctuTime2_0\0connectPulse\0connectMotor\0"
    "findZero\0recordLoadPosition\0"
    "recordUnloadPosition\0loadPos\0unloadPos\0"
    "motorStop\0motorForward\0motorBackward\0"
    "motorLeft\0motorRight\0motorUp\0motorDown\0"
    "setMotorMode\0motorSlowStop\0findZeroOk\0"
    "showMotorPos\0pos_x\0pos_y\0pos_z\0"
    "setMotorXButon\0isRun\0setMotorYButon\0"
    "setMotorZButon\0setButtonAble\0enable\0"
    "connectCurrent\0openLaser\0openLed\0"
    "connectLight\0Current\0_current\0voltage\0"
    "CurrentOK\0VoltageOK\0OutOK\0CurrentAndVoltageOK\0"
    "currentOut\0currentSet\0connectCoilXYZ\0"
    "coilXSet\0coilXOut\0coilYSet\0coilYOut\0"
    "coilZSet\0coilZOut\0CoilXOutOK\0"
    "CoilXCurrentAndVoltageOK\0CoilYOutOK\0"
    "CoilYCurrentAndVoltageOK\0CoilZOutOK\0"
    "CoilZCurrentAndVoltageOK\0CurrentX\0"
    "CurrentY\0CurrentZ\0startSweepMeasure\0"
    "stopSweep\0startFixFreMeasure\0stopFixFre\0"
    "startAllFixFre\0drawSweepData\0"
    "processSweepData\0on\0off\0processSweepData2\0"
    "frevalue\0count\0unsigned char*\0rawBuffer\0"
    "showSweepPic\0clearPulse\0showFixFreImg\0"
    "onmat\0offmat\0fastShowFixFreImg\0index\0"
    "tmpmat\0sweepLostPic\0fixLostPic\0sendPlus\0"
    "s\0changeLockState\0importPicNoMag\0"
    "importPicWithMag\0averODMRAnalysisNoMag\0"
    "averODMRAnalysisWithMag\0getInitParaNoMag\0"
    "getInitParaWithMag\0changePara\0row\0col\0"
    "importParaWithMag\0importParaNoMag\0"
    "saveParaNoMag\0saveParaWithMag\0"
    "loadNoMagData\0setDataDimension\0"
    "findAllSinglePeak\0vector<double>\0x_Vec\0"
    "y_Vec\0vector<int>&\0peakIndexVec\0"
    "findAllSinglePeak_auto\0findIndex\0"
    "std::vector<double>\0data\0value\0"
    "startAnalysisNoMag\0startAnalysisWithMag\0"
    "startAllAnalysis\0calMagDirection\0"
    "openColorMapPage\0contrastAnalysis\0"
    "setAnalysisMode\0setAnalysisRoi\0"
    "SetAnalysisRoiParam\0x\0y\0w\0h\0"
    "CancelAnalysisRoiParam\0calParams\0"
    "calSensitivity\0openRoiAnalysePage\0"
    "mousePressEvent\0event\0mouseMoveEvent\0"
    "on_minimizeButton_clicked\0"
    "on_closeButton_clicked\0startAllOut\0"
    "addLogEntry\0logMessage\0QTextEdit*\0"
    "textEdit\0clearLog\0ClearLog\0"
    "onRadioButtonToggled\0checked\0"
    "onRadioButtonToggled0\0onRadioButtonToggledGain\0"
    "showGrayvalue\0updateGrayValue\0"
    "LinearSmooth3\0vector<double>&\0input\0"
    "size\0LinearSmooth5\0LinearSmooth7"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_QDM_Interface[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
     145,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,  739,    2, 0x0a /* Public */,
       4,    1,  742,    2, 0x0a /* Public */,
       5,    0,  745,    2, 0x0a /* Public */,
       6,    0,  746,    2, 0x0a /* Public */,
       7,    0,  747,    2, 0x0a /* Public */,
       8,    0,  748,    2, 0x0a /* Public */,
       9,    0,  749,    2, 0x0a /* Public */,
      10,    0,  750,    2, 0x0a /* Public */,
      11,    0,  751,    2, 0x0a /* Public */,
      12,    1,  752,    2, 0x0a /* Public */,
      13,    0,  755,    2, 0x0a /* Public */,
      14,    1,  756,    2, 0x0a /* Public */,
      15,    1,  759,    2, 0x0a /* Public */,
      16,    0,  762,    2, 0x0a /* Public */,
      17,    0,  763,    2, 0x0a /* Public */,
      18,    0,  764,    2, 0x0a /* Public */,
      19,    0,  765,    2, 0x0a /* Public */,
      20,    0,  766,    2, 0x0a /* Public */,
      21,    0,  767,    2, 0x0a /* Public */,
      22,    1,  768,    2, 0x0a /* Public */,
      25,    0,  771,    2, 0x0a /* Public */,
      26,    0,  772,    2, 0x0a /* Public */,
      27,    1,  773,    2, 0x0a /* Public */,
      29,    2,  776,    2, 0x0a /* Public */,
      33,    0,  781,    2, 0x0a /* Public */,
      34,    0,  782,    2, 0x0a /* Public */,
      35,    0,  783,    2, 0x0a /* Public */,
      36,    0,  784,    2, 0x0a /* Public */,
      37,    0,  785,    2, 0x0a /* Public */,
      38,    0,  786,    2, 0x0a /* Public */,
      39,    0,  787,    2, 0x0a /* Public */,
      40,    0,  788,    2, 0x0a /* Public */,
      41,    0,  789,    2, 0x0a /* Public */,
      42,    5,  790,    2, 0x0a /* Public */,
      49,    8,  801,    2, 0x0a /* Public */,
      58,    0,  818,    2, 0x0a /* Public */,
      59,    0,  819,    2, 0x0a /* Public */,
      60,    0,  820,    2, 0x0a /* Public */,
      61,    0,  821,    2, 0x0a /* Public */,
      62,    0,  822,    2, 0x0a /* Public */,
      63,    0,  823,    2, 0x0a /* Public */,
      64,    0,  824,    2, 0x0a /* Public */,
      65,    0,  825,    2, 0x0a /* Public */,
      66,    0,  826,    2, 0x0a /* Public */,
      67,    0,  827,    2, 0x0a /* Public */,
      68,    0,  828,    2, 0x0a /* Public */,
      69,    0,  829,    2, 0x0a /* Public */,
      70,    0,  830,    2, 0x0a /* Public */,
      71,    0,  831,    2, 0x0a /* Public */,
      72,    0,  832,    2, 0x0a /* Public */,
      73,    0,  833,    2, 0x0a /* Public */,
      74,    0,  834,    2, 0x0a /* Public */,
      75,    3,  835,    2, 0x0a /* Public */,
      79,    1,  842,    2, 0x0a /* Public */,
      81,    1,  845,    2, 0x0a /* Public */,
      82,    1,  848,    2, 0x0a /* Public */,
      83,    1,  851,    2, 0x0a /* Public */,
      85,    0,  854,    2, 0x0a /* Public */,
      86,    0,  855,    2, 0x0a /* Public */,
      87,    0,  856,    2, 0x0a /* Public */,
      88,    0,  857,    2, 0x0a /* Public */,
      89,    2,  858,    2, 0x0a /* Public */,
      92,    0,  863,    2, 0x0a /* Public */,
      93,    0,  864,    2, 0x0a /* Public */,
      94,    0,  865,    2, 0x0a /* Public */,
      95,    0,  866,    2, 0x0a /* Public */,
      96,    0,  867,    2, 0x0a /* Public */,
      97,    0,  868,    2, 0x0a /* Public */,
      98,    0,  869,    2, 0x0a /* Public */,
      99,    0,  870,    2, 0x0a /* Public */,
     100,    0,  871,    2, 0x0a /* Public */,
     101,    0,  872,    2, 0x0a /* Public */,
     102,    0,  873,    2, 0x0a /* Public */,
     103,    0,  874,    2, 0x0a /* Public */,
     104,    0,  875,    2, 0x0a /* Public */,
     105,    0,  876,    2, 0x0a /* Public */,
     106,    0,  877,    2, 0x0a /* Public */,
     107,    0,  878,    2, 0x0a /* Public */,
     108,    0,  879,    2, 0x0a /* Public */,
     109,    0,  880,    2, 0x0a /* Public */,
     110,    0,  881,    2, 0x0a /* Public */,
     111,    2,  882,    2, 0x0a /* Public */,
     112,    2,  887,    2, 0x0a /* Public */,
     113,    2,  892,    2, 0x0a /* Public */,
     114,    0,  897,    2, 0x0a /* Public */,
     115,    0,  898,    2, 0x0a /* Public */,
     116,    0,  899,    2, 0x0a /* Public */,
     117,    0,  900,    2, 0x0a /* Public */,
     118,    0,  901,    2, 0x0a /* Public */,
     119,    2,  902,    2, 0x0a /* Public */,
     120,    3,  907,    2, 0x0a /* Public */,
     123,    3,  914,    2, 0x0a /* Public */,
     128,    1,  921,    2, 0x0a /* Public */,
     129,    0,  924,    2, 0x0a /* Public */,
     130,    2,  925,    2, 0x0a /* Public */,
     133,    2,  930,    2, 0x0a /* Public */,
     136,    0,  935,    2, 0x0a /* Public */,
     137,    0,  936,    2, 0x0a /* Public */,
     138,    1,  937,    2, 0x0a /* Public */,
     140,    1,  940,    2, 0x0a /* Public */,
     141,    0,  943,    2, 0x0a /* Public */,
     142,    0,  944,    2, 0x0a /* Public */,
     143,    0,  945,    2, 0x0a /* Public */,
     144,    0,  946,    2, 0x0a /* Public */,
     145,    0,  947,    2, 0x0a /* Public */,
     146,    0,  948,    2, 0x0a /* Public */,
     147,    2,  949,    2, 0x0a /* Public */,
     150,    0,  954,    2, 0x0a /* Public */,
     151,    0,  955,    2, 0x0a /* Public */,
     152,    0,  956,    2, 0x0a /* Public */,
     153,    0,  957,    2, 0x0a /* Public */,
     154,    0,  958,    2, 0x0a /* Public */,
     155,    1,  959,    2, 0x0a /* Public */,
     156,    3,  962,    2, 0x0a /* Public */,
     162,    3,  969,    2, 0x0a /* Public */,
     163,    2,  976,    2, 0x0a /* Public */,
     167,    0,  981,    2, 0x0a /* Public */,
     168,    0,  982,    2, 0x0a /* Public */,
     169,    0,  983,    2, 0x0a /* Public */,
     170,    0,  984,    2, 0x0a /* Public */,
     171,    0,  985,    2, 0x0a /* Public */,
     172,    0,  986,    2, 0x0a /* Public */,
     173,    0,  987,    2, 0x0a /* Public */,
     174,    0,  988,    2, 0x0a /* Public */,
     175,    4,  989,    2, 0x0a /* Public */,
     180,    0,  998,    2, 0x0a /* Public */,
     181,    0,  999,    2, 0x0a /* Public */,
     182,    0, 1000,    2, 0x0a /* Public */,
     183,    0, 1001,    2, 0x0a /* Public */,
     184,    1, 1002,    2, 0x0a /* Public */,
     186,    1, 1005,    2, 0x0a /* Public */,
     187,    0, 1008,    2, 0x0a /* Public */,
     188,    0, 1009,    2, 0x0a /* Public */,
     189,    0, 1010,    2, 0x0a /* Public */,
     190,    2, 1011,    2, 0x0a /* Public */,
     194,    1, 1016,    2, 0x0a /* Public */,
     195,    0, 1019,    2, 0x0a /* Public */,
     196,    1, 1020,    2, 0x0a /* Public */,
     198,    1, 1023,    2, 0x0a /* Public */,
     199,    1, 1026,    2, 0x0a /* Public */,
     200,    2, 1029,    2, 0x0a /* Public */,
     201,    0, 1034,    2, 0x0a /* Public */,
     202,    2, 1035,    2, 0x0a /* Public */,
     206,    2, 1040,    2, 0x0a /* Public */,
     207,    2, 1045,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3,    2,
    QMetaType::Void, 0x80000000 | 3,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 23,   24,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Double,   28,
    QMetaType::Void, 0x80000000 | 23, 0x80000000 | 31,   30,   32,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::Int, 0x80000000 | 45, 0x80000000 | 45, 0x80000000 | 45,   43,   44,   46,   47,   48,
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int,   50,   51,   52,   53,   54,   55,   56,   57,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::Int,   76,   77,   78,
    QMetaType::Void, QMetaType::Bool,   80,
    QMetaType::Void, QMetaType::Bool,   80,
    QMetaType::Void, QMetaType::Bool,   80,
    QMetaType::Void, QMetaType::Bool,   84,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Float, QMetaType::Float,   90,   91,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Float, QMetaType::Float,   90,   91,
    QMetaType::Void, QMetaType::Float, QMetaType::Float,   90,   91,
    QMetaType::Void, QMetaType::Float, QMetaType::Float,   90,   91,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Double, QMetaType::Double,    2,    2,
    QMetaType::Void, QMetaType::Double, 0x80000000 | 23, 0x80000000 | 23,    2,  121,  122,
    QMetaType::Void, QMetaType::Double, QMetaType::Int, 0x80000000 | 126,  124,  125,  127,
    QMetaType::Void, 0x80000000 | 23,   24,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 23, 0x80000000 | 23,  131,  132,
    QMetaType::Void, QMetaType::Int, 0x80000000 | 23,  134,  135,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,  139,
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,  148,  149,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Bool, 0x80000000 | 157, 0x80000000 | 157, 0x80000000 | 160,  158,  159,  161,
    QMetaType::Bool, 0x80000000 | 157, 0x80000000 | 157, 0x80000000 | 160,  158,  159,  161,
    QMetaType::Int, 0x80000000 | 164, QMetaType::Double,  165,  166,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int,  176,  177,  178,  179,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 3,  185,
    QMetaType::Void, 0x80000000 | 3,  185,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString, 0x80000000 | 192,  191,  193,
    QMetaType::Void, 0x80000000 | 192,  193,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,  197,
    QMetaType::Void, QMetaType::Bool,  197,
    QMetaType::Void, QMetaType::Bool,  197,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,  176,  177,
    QMetaType::Void,
    QMetaType::Int, 0x80000000 | 203, QMetaType::Long,  204,  205,
    QMetaType::Int, 0x80000000 | 203, QMetaType::Long,  204,  205,
    QMetaType::Int, 0x80000000 | 203, QMetaType::Long,  204,  205,

       0        // eod
};

void QDM_Interface::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        QDM_Interface *_t = static_cast<QDM_Interface *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_MouseMoveCustomplot((*reinterpret_cast< QMouseEvent*(*)>(_a[1]))); break;
        case 1: _t->on_MouseMoveGraphicsView((*reinterpret_cast< QMouseEvent*(*)>(_a[1]))); break;
        case 2: _t->connectWave(); break;
        case 3: _t->setFreMode(); break;
        case 4: _t->sendWaveMode(); break;
        case 5: _t->sendSweepFre(); break;
        case 6: _t->sendFixFre(); break;
        case 7: _t->startWave(); break;
        case 8: _t->resetWave(); break;
        case 9: _t->getWaveStatus((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 10: _t->connectCamera(); break;
        case 11: _t->setExposureMode((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 12: _t->setExposureTime((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 13: _t->setTriggerMode(); break;
        case 14: _t->softTriggerOnce(); break;
        case 15: _t->savePicture(); break;
        case 16: _t->choosePath(); break;
        case 17: _t->setAutoSave(); break;
        case 18: _t->setRoi(); break;
        case 19: _t->showCapImg((*reinterpret_cast< cv::Mat(*)>(_a[1]))); break;
        case 20: _t->autoFindExpTime(); break;
        case 21: _t->showFps(); break;
        case 22: _t->showFps2((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 23: _t->saveImage((*reinterpret_cast< const cv::Mat(*)>(_a[1])),(*reinterpret_cast< const std::string(*)>(_a[2]))); break;
        case 24: _t->setBinning(); break;
        case 25: _t->setCapMode(); break;
        case 26: _t->setGain(); break;
        case 27: _t->onContrastSliderValueChanged(); break;
        case 28: _t->onGammaSliderValueChanged(); break;
        case 29: _t->onGainSliderValueChanged(); break;
        case 30: _t->onlineEditValueChanged(); break;
        case 31: _t->openPulseSettingPage(); break;
        case 32: _t->clearPulseManual(); break;
        case 33: _t->SetPulseParam((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< QVector<float>(*)>(_a[3])),(*reinterpret_cast< QVector<float>(*)>(_a[4])),(*reinterpret_cast< QVector<float>(*)>(_a[5]))); break;
        case 34: _t->SetPulseTimesParam((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4])),(*reinterpret_cast< int(*)>(_a[5])),(*reinterpret_cast< int(*)>(_a[6])),(*reinterpret_cast< int(*)>(_a[7])),(*reinterpret_cast< int(*)>(_a[8]))); break;
        case 35: _t->connectPulse(); break;
        case 36: _t->connectMotor(); break;
        case 37: _t->findZero(); break;
        case 38: _t->recordLoadPosition(); break;
        case 39: _t->recordUnloadPosition(); break;
        case 40: _t->loadPos(); break;
        case 41: _t->unloadPos(); break;
        case 42: _t->motorStop(); break;
        case 43: _t->motorForward(); break;
        case 44: _t->motorBackward(); break;
        case 45: _t->motorLeft(); break;
        case 46: _t->motorRight(); break;
        case 47: _t->motorUp(); break;
        case 48: _t->motorDown(); break;
        case 49: _t->setMotorMode(); break;
        case 50: _t->motorSlowStop(); break;
        case 51: _t->findZeroOk(); break;
        case 52: _t->showMotorPos((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 53: _t->setMotorXButon((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 54: _t->setMotorYButon((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 55: _t->setMotorZButon((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 56: _t->setButtonAble((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 57: _t->connectCurrent(); break;
        case 58: _t->openLaser(); break;
        case 59: _t->openLed(); break;
        case 60: _t->connectLight(); break;
        case 61: _t->Current((*reinterpret_cast< float(*)>(_a[1])),(*reinterpret_cast< float(*)>(_a[2]))); break;
        case 62: _t->CurrentOK(); break;
        case 63: _t->VoltageOK(); break;
        case 64: _t->OutOK(); break;
        case 65: _t->CurrentAndVoltageOK(); break;
        case 66: _t->currentOut(); break;
        case 67: _t->currentSet(); break;
        case 68: _t->connectCoilXYZ(); break;
        case 69: _t->coilXSet(); break;
        case 70: _t->coilXOut(); break;
        case 71: _t->coilYSet(); break;
        case 72: _t->coilYOut(); break;
        case 73: _t->coilZSet(); break;
        case 74: _t->coilZOut(); break;
        case 75: _t->CoilXOutOK(); break;
        case 76: _t->CoilXCurrentAndVoltageOK(); break;
        case 77: _t->CoilYOutOK(); break;
        case 78: _t->CoilYCurrentAndVoltageOK(); break;
        case 79: _t->CoilZOutOK(); break;
        case 80: _t->CoilZCurrentAndVoltageOK(); break;
        case 81: _t->CurrentX((*reinterpret_cast< float(*)>(_a[1])),(*reinterpret_cast< float(*)>(_a[2]))); break;
        case 82: _t->CurrentY((*reinterpret_cast< float(*)>(_a[1])),(*reinterpret_cast< float(*)>(_a[2]))); break;
        case 83: _t->CurrentZ((*reinterpret_cast< float(*)>(_a[1])),(*reinterpret_cast< float(*)>(_a[2]))); break;
        case 84: _t->startSweepMeasure(); break;
        case 85: _t->stopSweep(); break;
        case 86: _t->startFixFreMeasure(); break;
        case 87: _t->stopFixFre(); break;
        case 88: _t->startAllFixFre(); break;
        case 89: _t->drawSweepData((*reinterpret_cast< double(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2]))); break;
        case 90: _t->processSweepData((*reinterpret_cast< double(*)>(_a[1])),(*reinterpret_cast< cv::Mat(*)>(_a[2])),(*reinterpret_cast< cv::Mat(*)>(_a[3]))); break;
        case 91: _t->processSweepData2((*reinterpret_cast< double(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< unsigned char*(*)>(_a[3]))); break;
        case 92: _t->showSweepPic((*reinterpret_cast< cv::Mat(*)>(_a[1]))); break;
        case 93: _t->clearPulse(); break;
        case 94: _t->showFixFreImg((*reinterpret_cast< cv::Mat(*)>(_a[1])),(*reinterpret_cast< cv::Mat(*)>(_a[2]))); break;
        case 95: _t->fastShowFixFreImg((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< cv::Mat(*)>(_a[2]))); break;
        case 96: _t->sweepLostPic(); break;
        case 97: _t->fixLostPic(); break;
        case 98: _t->sendPlus((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 99: _t->changeLockState((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 100: _t->importPicNoMag(); break;
        case 101: _t->importPicWithMag(); break;
        case 102: _t->averODMRAnalysisNoMag(); break;
        case 103: _t->averODMRAnalysisWithMag(); break;
        case 104: _t->getInitParaNoMag(); break;
        case 105: _t->getInitParaWithMag(); break;
        case 106: _t->changePara((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 107: _t->importParaWithMag(); break;
        case 108: _t->importParaNoMag(); break;
        case 109: _t->saveParaNoMag(); break;
        case 110: _t->saveParaWithMag(); break;
        case 111: _t->loadNoMagData(); break;
        case 112: _t->setDataDimension((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 113: { bool _r = _t->findAllSinglePeak((*reinterpret_cast< vector<double>(*)>(_a[1])),(*reinterpret_cast< vector<double>(*)>(_a[2])),(*reinterpret_cast< vector<int>(*)>(_a[3])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 114: { bool _r = _t->findAllSinglePeak_auto((*reinterpret_cast< vector<double>(*)>(_a[1])),(*reinterpret_cast< vector<double>(*)>(_a[2])),(*reinterpret_cast< vector<int>(*)>(_a[3])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 115: { int _r = _t->findIndex((*reinterpret_cast< const std::vector<double>(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 116: _t->startAnalysisNoMag(); break;
        case 117: _t->startAnalysisWithMag(); break;
        case 118: _t->startAllAnalysis(); break;
        case 119: _t->calMagDirection(); break;
        case 120: _t->openColorMapPage(); break;
        case 121: _t->contrastAnalysis(); break;
        case 122: _t->setAnalysisMode(); break;
        case 123: _t->setAnalysisRoi(); break;
        case 124: _t->SetAnalysisRoiParam((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4]))); break;
        case 125: _t->CancelAnalysisRoiParam(); break;
        case 126: _t->calParams(); break;
        case 127: _t->calSensitivity(); break;
        case 128: _t->openRoiAnalysePage(); break;
        case 129: _t->mousePressEvent((*reinterpret_cast< QMouseEvent*(*)>(_a[1]))); break;
        case 130: _t->mouseMoveEvent((*reinterpret_cast< QMouseEvent*(*)>(_a[1]))); break;
        case 131: _t->on_minimizeButton_clicked(); break;
        case 132: _t->on_closeButton_clicked(); break;
        case 133: _t->startAllOut(); break;
        case 134: _t->addLogEntry((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< QTextEdit*(*)>(_a[2]))); break;
        case 135: _t->clearLog((*reinterpret_cast< QTextEdit*(*)>(_a[1]))); break;
        case 136: _t->ClearLog(); break;
        case 137: _t->onRadioButtonToggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 138: _t->onRadioButtonToggled0((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 139: _t->onRadioButtonToggledGain((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 140: _t->showGrayvalue((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 141: _t->updateGrayValue(); break;
        case 142: { int _r = _t->LinearSmooth3((*reinterpret_cast< vector<double>(*)>(_a[1])),(*reinterpret_cast< long(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 143: { int _r = _t->LinearSmooth5((*reinterpret_cast< vector<double>(*)>(_a[1])),(*reinterpret_cast< long(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 144: { int _r = _t->LinearSmooth7((*reinterpret_cast< vector<double>(*)>(_a[1])),(*reinterpret_cast< long(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 33:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 4:
            case 3:
            case 2:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QVector<float> >(); break;
            }
            break;
        }
    }
}

const QMetaObject QDM_Interface::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_QDM_Interface.data,
      qt_meta_data_QDM_Interface,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *QDM_Interface::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QDM_Interface::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_QDM_Interface.stringdata0))
        return static_cast<void*>(const_cast< QDM_Interface*>(this));
    return QDialog::qt_metacast(_clname);
}

int QDM_Interface::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 145)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 145;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 145)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 145;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
