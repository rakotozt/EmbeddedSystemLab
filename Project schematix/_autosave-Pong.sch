EESchema Schematic File Version 4
EELAYER 30 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 1
Title ""
Date ""
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
Wire Wire Line
	6050 1750 6350 1750
Wire Wire Line
	6050 1650 6350 1650
Wire Wire Line
	6050 1850 6350 1850
Wire Wire Line
	6050 1950 6350 1950
Wire Wire Line
	6050 1250 6350 1250
Wire Wire Line
	6050 1350 6350 1350
Wire Wire Line
	6050 1450 6350 1450
Wire Wire Line
	6050 1550 6350 1550
Wire Wire Line
	6000 2150 6350 2150
Wire Wire Line
	6000 2250 6350 2250
Wire Wire Line
	6000 2350 6350 2350
Wire Wire Line
	6000 2450 6350 2450
Wire Wire Line
	6050 2650 6350 2650
Wire Wire Line
	6050 2850 6350 2850
Wire Wire Line
	6050 2950 6350 2950
Text Label 6200 1750 0    50   ~ 0
RA3
Text Label 6250 1950 0    50   ~ 0
AN1
Text Label 6250 1650 0    50   ~ 0
AN0
Text Label 6250 1850 0    50   ~ 0
RA4
Text Label 6200 1250 0    50   ~ 0
3V0
Text Label 6200 1350 0    50   ~ 0
3V0
Text Label 6200 1450 0    50   ~ 0
3V0
Text Label 6200 2150 0    50   ~ 0
RB2
Text Label 6200 2250 0    50   ~ 0
RB0
Text Label 6200 2350 0    50   ~ 0
RB1
Text Label 6150 2450 0    50   ~ 0
RPB11
Text Label 6150 2650 0    50   ~ 0
RB14
Text Label 6200 2850 0    50   ~ 0
VDD
Text Label 6200 2950 0    50   ~ 0
GND
Wire Wire Line
	1200 1300 1650 1300
Wire Wire Line
	1250 1700 1650 1700
Wire Wire Line
	1250 1800 1650 1800
Wire Wire Line
	1250 1900 1650 1900
Wire Wire Line
	1250 2000 1650 2000
Wire Wire Line
	1300 2100 1650 2100
Wire Wire Line
	1250 2500 1650 2500
Wire Wire Line
	1250 2700 1650 2700
Wire Wire Line
	4350 1500 4150 1500
Wire Wire Line
	4350 1800 4150 1800
Wire Wire Line
	1250 2800 1650 2800
Text Label 1450 1300 0    50   ~ 0
VIN
Text Label 1500 1700 0    50   ~ 0
X-
Text Label 1550 1800 0    50   ~ 0
Y+
Text Label 1550 2700 0    50   ~ 0
X+
Text Label 1550 2500 0    50   ~ 0
Y-
Text Label 1550 2100 0    50   ~ 0
RST
Text Label 1550 1900 0    50   ~ 0
DC
Text Label 1550 2000 0    50   ~ 0
CS
Text Label 4200 1500 0    50   ~ 0
CLK
Text Label 4200 1800 0    50   ~ 0
MOSI
$Comp
L Pong-rescue:PIC32MX250F128B-V_SP-PIC32MX250F128B-V_SP-Lab6-rescue PIC32
U 1 1 5F73896B
P 3450 2000
F 0 "PIC32" H 2900 3267 50  0000 C CNN
F 1 "PIC32MX250F128B-V_SP" H 2900 3176 50  0000 C CNN
F 2 "DIP254P762X508-28" H 3450 2000 50  0001 L BNN
F 3 "SPDIP-28 Microchip" H 3450 2000 50  0001 L BNN
F 4 "PIC32MX250F128B-V/SP" H 3450 2000 50  0001 L BNN "Field4"
F 5 "32 Bit MCU, 128KB Flash, 32KB RAM, 40 MHz, 28 Pin, 3 Comp, CTMU, RTCC, 28 SPDIP" H 3450 2000 50  0001 L BNN "Field5"
F 6 "Microchip" H 3450 2000 50  0001 L BNN "Field6"
F 7 "None" H 3450 2000 50  0001 L BNN "Field7"
F 8 "Unavailable" H 3450 2000 50  0001 L BNN "Field8"
	1    3450 2000
	1    0    0    -1  
$EndComp
$Comp
L Pong-rescue:LCD_2_4-LCD_2_4-Lab6-rescue DISP
U 1 1 5F73713A
P 7100 2250
F 0 "DISP" H 7100 3675 50  0000 C CNN
F 1 "LCD DISPLAY " H 7100 3584 50  0000 C CNB
F 2 "" H 7150 2250 50  0001 C CNN
F 3 "" H 7150 2250 50  0001 C CNN
	1    7100 2250
	1    0    0    -1  
$EndComp
$Comp
L Device:R_POT 10k
U 1 1 5FA216BE
P 2400 4650
F 0 "10k" H 2331 4696 50  0000 R CNN
F 1 "R_POT_1" H 2331 4605 50  0000 R CNN
F 2 "" H 2400 4650 50  0001 C CNN
F 3 "~" H 2400 4650 50  0001 C CNN
	1    2400 4650
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR?
U 1 1 5FA24D2B
P 2400 5000
F 0 "#PWR?" H 2400 4750 50  0001 C CNN
F 1 "GND" H 2405 4827 50  0000 C CNN
F 2 "" H 2400 5000 50  0001 C CNN
F 3 "" H 2400 5000 50  0001 C CNN
	1    2400 5000
	1    0    0    -1  
$EndComp
Wire Wire Line
	2400 5000 2400 4800
$Comp
L power:GND #PWR?
U 1 1 5FA2FB18
P 8800 4950
F 0 "#PWR?" H 8800 4700 50  0001 C CNN
F 1 "GND" H 8805 4777 50  0000 C CNN
F 2 "" H 8800 4950 50  0001 C CNN
F 3 "" H 8800 4950 50  0001 C CNN
	1    8800 4950
	1    0    0    -1  
$EndComp
Wire Wire Line
	8800 4750 8800 4950
$Comp
L Analog_DAC:MCP4822 U?
U 1 1 5FA31382
P 6550 4200
F 0 "U?" H 6550 4781 50  0000 C CNN
F 1 "MCP4822" H 6550 4690 50  0000 C CNN
F 2 "" H 7350 3900 50  0001 C CNN
F 3 "http://ww1.microchip.com/downloads/en/DeviceDoc/20002249B.pdf" H 7350 3900 50  0001 C CNN
	1    6550 4200
	1    0    0    -1  
$EndComp
Wire Wire Line
	7050 4550 7050 4400
Wire Wire Line
	6050 4200 5750 4200
Wire Wire Line
	5750 4200 5750 4700
Wire Wire Line
	5750 4700 6550 4700
$Comp
L power:GND #PWR?
U 1 1 5FA3C004
P 6550 4900
F 0 "#PWR?" H 6550 4650 50  0001 C CNN
F 1 "GND" H 6555 4727 50  0000 C CNN
F 2 "" H 6550 4900 50  0001 C CNN
F 3 "" H 6550 4900 50  0001 C CNN
	1    6550 4900
	1    0    0    -1  
$EndComp
Wire Wire Line
	6550 4900 6550 4700
Connection ~ 6550 4700
Wire Wire Line
	4150 1400 4600 1400
Text Label 4300 1400 0    50   ~ 0
SCLK
Wire Wire Line
	5600 4100 6050 4100
Text Label 5750 4100 0    50   ~ 0
SCLK
Text Label 1150 2800 0    50   ~ 0
SDI(mcp4822)
Text Label 5850 4300 0    50   ~ 0
RB5
Wire Wire Line
	6050 4300 5850 4300
Text Label 4450 2200 0    50   ~ 0
(mcp4822)
Text Label 5850 4400 0    50   ~ 0
RB8
Wire Wire Line
	6050 4400 5850 4400
Text Label 4350 2200 0    50   ~ 0
CS
Wire Wire Line
	4150 2200 4600 2200
Wire Wire Line
	3300 4750 3300 5000
$Comp
L power:GND #PWR?
U 1 1 5FA27064
P 3300 5000
F 0 "#PWR?" H 3300 4750 50  0001 C CNN
F 1 "GND" H 3305 4827 50  0000 C CNN
F 2 "" H 3300 5000 50  0001 C CNN
F 3 "" H 3300 5000 50  0001 C CNN
	1    3300 5000
	1    0    0    -1  
$EndComp
Wire Wire Line
	2400 4250 2400 4500
$Comp
L power:VDD #PWR?
U 1 1 5FAA15C8
P 2400 4250
F 0 "#PWR?" H 2400 4100 50  0001 C CNN
F 1 "VDD" H 2417 4423 50  0000 C CNN
F 2 "" H 2400 4250 50  0001 C CNN
F 3 "" H 2400 4250 50  0001 C CNN
	1    2400 4250
	1    0    0    -1  
$EndComp
$Comp
L power:VDD #PWR?
U 1 1 5FAA2D22
P 3300 4250
F 0 "#PWR?" H 3300 4100 50  0001 C CNN
F 1 "VDD" H 3317 4423 50  0000 C CNN
F 2 "" H 3300 4250 50  0001 C CNN
F 3 "" H 3300 4250 50  0001 C CNN
	1    3300 4250
	1    0    0    -1  
$EndComp
$Comp
L Device:R_POT 10k
U 1 1 5FA23920
P 3300 4600
F 0 "10k" H 3231 4646 50  0000 R CNN
F 1 "R_POT_2" H 3231 4555 50  0000 R CNN
F 2 "" H 3300 4600 50  0001 C CNN
F 3 "~" H 3300 4600 50  0001 C CNN
	1    3300 4600
	1    0    0    -1  
$EndComp
Wire Wire Line
	3300 4250 3300 4450
$Comp
L Device:R R2
U 1 1 5FA9708B
P 8050 4550
F 0 "R2" H 8120 4596 50  0000 L CNN
F 1 "560" H 8120 4505 50  0000 L CNN
F 2 "" V 7980 4550 50  0001 C CNN
F 3 "~" H 8050 4550 50  0001 C CNN
	1    8050 4550
	0    -1   -1   0   
$EndComp
$Comp
L pspice:C C2
U 1 1 5FA98CB9
P 8250 5100
F 0 "C2" H 8428 5146 50  0000 L CNN
F 1 "1uF" H 8428 5055 50  0000 L CNN
F 2 "" H 8250 5100 50  0001 C CNN
F 3 "~" H 8250 5100 50  0001 C CNN
	1    8250 5100
	1    0    0    -1  
$EndComp
$Comp
L pspice:C C1
U 1 1 5FA9887A
P 7750 5050
F 0 "C1" H 7928 5096 50  0000 L CNN
F 1 "1uF" H 7928 5005 50  0000 L CNN
F 2 "" H 7750 5050 50  0001 C CNN
F 3 "~" H 7750 5050 50  0001 C CNN
	1    7750 5050
	1    0    0    -1  
$EndComp
$Comp
L Device:R R1
U 1 1 5FA97130
P 7450 4100
F 0 "R1" H 7520 4146 50  0000 L CNN
F 1 "560" H 7520 4055 50  0000 L CNN
F 2 "" V 7380 4100 50  0001 C CNN
F 3 "~" H 7450 4100 50  0001 C CNN
	1    7450 4100
	0    -1   -1   0   
$EndComp
$Comp
L Connector:AudioJack2_Ground_Switch J?
U 1 1 5FA29F0B
P 8800 4450
F 0 "J?" H 8832 4875 50  0000 C CNN
F 1 "AudioJack2_Ground_Switch" H 8832 4784 50  0000 C CNN
F 2 "" H 8800 4650 50  0001 C CNN
F 3 "~" H 8800 4650 50  0001 C CNN
	1    8800 4450
	1    0    0    -1  
$EndComp
Wire Wire Line
	8250 5350 8250 5700
Wire Wire Line
	8250 5700 8050 5700
Wire Wire Line
	8050 5700 8050 5750
Connection ~ 8050 5700
$Comp
L power:GND #PWR?
U 1 1 5FAABE63
P 8050 5750
F 0 "#PWR?" H 8050 5500 50  0001 C CNN
F 1 "GND" H 8055 5577 50  0000 C CNN
F 2 "" H 8050 5750 50  0001 C CNN
F 3 "" H 8050 5750 50  0001 C CNN
	1    8050 5750
	1    0    0    -1  
$EndComp
Wire Wire Line
	7750 5300 7750 5700
Wire Wire Line
	7750 5700 8050 5700
Wire Wire Line
	7050 4100 7300 4100
Wire Wire Line
	7600 4100 7750 4100
Wire Wire Line
	9000 4100 9000 4250
Wire Wire Line
	7050 4550 7900 4550
Wire Wire Line
	8200 4550 8250 4550
Wire Wire Line
	8250 4550 8250 4850
Connection ~ 8250 4550
Wire Wire Line
	8250 4550 9000 4550
Wire Wire Line
	7750 4100 7750 4800
Connection ~ 7750 4100
Wire Wire Line
	7750 4100 9000 4100
Wire Wire Line
	2550 4650 2750 4650
Wire Wire Line
	1650 2200 1250 2200
Wire Wire Line
	1250 2200 1250 2250
Wire Wire Line
	4150 1600 4600 1600
Text Label 2550 4650 0    50   ~ 0
AN5
Text Label 3450 4600 0    50   ~ 0
AN11
Wire Wire Line
	3450 4600 3650 4600
Text Label 1250 2200 0    50   ~ 0
R_POT_1
Text Label 4250 1600 0    50   ~ 0
R_POT_2
Text Notes 6050 5350 0    50   Italic 10
SOUND PART\n
Text Notes 2200 5400 0    50   Italic 10
POTETIOMETERS AND PUSH BUTTON TO CONTROL PADDLES\n
$Comp
L Switch:SW_Push SW1
U 1 1 5FAC9CE3
P 4350 4500
F 0 "SW1" V 4396 4452 50  0000 R CNN
F 1 "btn" V 4305 4452 50  0000 R CNN
F 2 "" H 4350 4700 50  0001 C CNN
F 3 "~" H 4350 4700 50  0001 C CNN
	1    4350 4500
	0    -1   -1   0   
$EndComp
Wire Wire Line
	4350 4700 4350 4950
$Comp
L power:GND #PWR?
U 1 1 5FACD010
P 4350 4950
F 0 "#PWR?" H 4350 4700 50  0001 C CNN
F 1 "GND" H 4355 4777 50  0000 C CNN
F 2 "" H 4350 4950 50  0001 C CNN
F 3 "" H 4350 4950 50  0001 C CNN
	1    4350 4950
	1    0    0    -1  
$EndComp
Wire Wire Line
	4350 4300 4350 4150
Text Label 4350 4300 1    50   ~ 0
RB7
Wire Wire Line
	4150 2300 4600 2300
Text Label 4300 2300 0    50   ~ 0
SW1
$EndSCHEMATC
