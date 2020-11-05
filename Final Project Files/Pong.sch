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
	7100 1850 7400 1850
Wire Wire Line
	7100 1750 7400 1750
Wire Wire Line
	7100 1950 7400 1950
Wire Wire Line
	7100 2050 7400 2050
Wire Wire Line
	7100 1350 7400 1350
Wire Wire Line
	7100 1450 7400 1450
Wire Wire Line
	7100 1550 7400 1550
Wire Wire Line
	7100 1650 7400 1650
Wire Wire Line
	7050 2250 7400 2250
Wire Wire Line
	7050 2350 7400 2350
Wire Wire Line
	7050 2450 7400 2450
Wire Wire Line
	7050 2550 7400 2550
Wire Wire Line
	7100 2750 7400 2750
Wire Wire Line
	7100 2950 7400 2950
Wire Wire Line
	7100 3050 7400 3050
Text Label 7250 1850 0    50   ~ 0
RA3
Text Label 7300 2050 0    50   ~ 0
AN1
Text Label 7300 1750 0    50   ~ 0
AN0
Text Label 7300 1950 0    50   ~ 0
RA4
Text Label 7250 1350 0    50   ~ 0
3V0
Text Label 7250 1450 0    50   ~ 0
3V0
Text Label 7250 1550 0    50   ~ 0
3V0
Text Label 7250 2250 0    50   ~ 0
RB2
Text Label 7250 2350 0    50   ~ 0
RB0
Text Label 7250 2450 0    50   ~ 0
RB1
Text Label 7200 2550 0    50   ~ 0
RPB11
Text Label 7200 2750 0    50   ~ 0
RB14
Text Label 7250 2950 0    50   ~ 0
VDD
Text Label 7250 3050 0    50   ~ 0
GND
Wire Wire Line
	2600 1450 3050 1450
Wire Wire Line
	2650 1850 3050 1850
Wire Wire Line
	2650 1950 3050 1950
Wire Wire Line
	2650 2050 3050 2050
Wire Wire Line
	2650 2150 3050 2150
Wire Wire Line
	2700 2250 3050 2250
Wire Wire Line
	2650 2350 3050 2350
Wire Wire Line
	2650 2650 3050 2650
Wire Wire Line
	2650 2850 3050 2850
Wire Wire Line
	5750 1650 5550 1650
Wire Wire Line
	5750 1950 5550 1950
Wire Wire Line
	2650 2950 3050 2950
Text Label 2850 1450 0    50   ~ 0
VIN
Text Label 2900 1850 0    50   ~ 0
X-
Text Label 2950 1950 0    50   ~ 0
Y+
Text Label 2950 2850 0    50   ~ 0
X+
Text Label 2950 2650 0    50   ~ 0
Y-
Text Label 2950 2250 0    50   ~ 0
RST
Text Label 2950 2050 0    50   ~ 0
DC
Text Label 2950 2150 0    50   ~ 0
CS
Text Label 5600 1650 0    50   ~ 0
CLK
Text Label 5600 1950 0    50   ~ 0
MOSI
$Comp
L Lab6-rescue:PIC32MX250F128B-V_SP-PIC32MX250F128B-V_SP PIC32
U 1 1 5F73896B
P 4850 2150
F 0 "PIC32" H 4300 3417 50  0000 C CNN
F 1 "PIC32MX250F128B-V_SP" H 4300 3326 50  0000 C CNN
F 2 "DIP254P762X508-28" H 4850 2150 50  0001 L BNN
F 3 "SPDIP-28 Microchip" H 4850 2150 50  0001 L BNN
F 4 "PIC32MX250F128B-V/SP" H 4850 2150 50  0001 L BNN "Field4"
F 5 "32 Bit MCU, 128KB Flash, 32KB RAM, 40 MHz, 28 Pin, 3 Comp, CTMU, RTCC, 28 SPDIP" H 4850 2150 50  0001 L BNN "Field5"
F 6 "Microchip" H 4850 2150 50  0001 L BNN "Field6"
F 7 "None" H 4850 2150 50  0001 L BNN "Field7"
F 8 "Unavailable" H 4850 2150 50  0001 L BNN "Field8"
	1    4850 2150
	1    0    0    -1  
$EndComp
$Comp
L Lab6-rescue:LCD_2_4-LCD_2_4 DISP
U 1 1 5F73713A
P 8150 2350
F 0 "DISP" H 8150 3775 50  0000 C CNN
F 1 "LCD DISPLAY " H 8150 3684 50  0000 C CNB
F 2 "" H 8200 2350 50  0001 C CNN
F 3 "" H 8200 2350 50  0001 C CNN
	1    8150 2350
	1    0    0    -1  
$EndComp
$Comp
L Device:R_POT 10k
U 1 1 5FA216BE
P 2150 3100
F 0 "10k" H 2081 3146 50  0000 R CNN
F 1 "R_POT" H 2081 3055 50  0000 R CNN
F 2 "" H 2150 3100 50  0001 C CNN
F 3 "~" H 2150 3100 50  0001 C CNN
	1    2150 3100
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR?
U 1 1 5FA24D2B
P 2150 3450
F 0 "#PWR?" H 2150 3200 50  0001 C CNN
F 1 "GND" H 2155 3277 50  0000 C CNN
F 2 "" H 2150 3450 50  0001 C CNN
F 3 "" H 2150 3450 50  0001 C CNN
	1    2150 3450
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR?
U 1 1 5FA27064
P 5700 3600
F 0 "#PWR?" H 5700 3350 50  0001 C CNN
F 1 "GND" H 5705 3427 50  0000 C CNN
F 2 "" H 5700 3600 50  0001 C CNN
F 3 "" H 5700 3600 50  0001 C CNN
	1    5700 3600
	1    0    0    -1  
$EndComp
$Comp
L Connector:AudioJack2_Ground_Switch J?
U 1 1 5FA29F0B
P 5100 4800
F 0 "J?" H 5132 5225 50  0000 C CNN
F 1 "AudioJack2_Ground_Switch" H 5132 5134 50  0000 C CNN
F 2 "" H 5100 5000 50  0001 C CNN
F 3 "~" H 5100 5000 50  0001 C CNN
	1    5100 4800
	1    0    0    -1  
$EndComp
$Comp
L Device:R_POT RV?
U 1 1 5FA23920
P 5700 3200
F 0 "RV?" H 5631 3246 50  0000 R CNN
F 1 "R_POT" H 5631 3155 50  0000 R CNN
F 2 "" H 5700 3200 50  0001 C CNN
F 3 "~" H 5700 3200 50  0001 C CNN
	1    5700 3200
	1    0    0    -1  
$EndComp
Wire Wire Line
	2150 3450 2150 3250
Wire Wire Line
	2150 2950 2150 2550
Wire Wire Line
	5700 3350 5700 3600
Wire Wire Line
	5700 3050 5700 2450
Wire Wire Line
	5700 2450 5550 2450
$Comp
L power:GND #PWR?
U 1 1 5FA2FB18
P 5100 5300
F 0 "#PWR?" H 5100 5050 50  0001 C CNN
F 1 "GND" H 5105 5127 50  0000 C CNN
F 2 "" H 5100 5300 50  0001 C CNN
F 3 "" H 5100 5300 50  0001 C CNN
	1    5100 5300
	1    0    0    -1  
$EndComp
Wire Wire Line
	5100 5100 5100 5300
$Comp
L Analog_DAC:MCP4822 U?
U 1 1 5FA31382
P 3750 4550
F 0 "U?" H 3750 5131 50  0000 C CNN
F 1 "MCP4822" H 3750 5040 50  0000 C CNN
F 2 "" H 4550 4250 50  0001 C CNN
F 3 "http://ww1.microchip.com/downloads/en/DeviceDoc/20002249B.pdf" H 4550 4250 50  0001 C CNN
	1    3750 4550
	1    0    0    -1  
$EndComp
Wire Wire Line
	5300 4600 5300 4450
Wire Wire Line
	5300 4450 4250 4450
Wire Wire Line
	5300 4900 4250 4900
Wire Wire Line
	4250 4900 4250 4750
Wire Wire Line
	3250 4550 2950 4550
Wire Wire Line
	2950 4550 2950 5050
Wire Wire Line
	2950 5050 3750 5050
$Comp
L power:GND #PWR?
U 1 1 5FA3C004
P 3750 5250
F 0 "#PWR?" H 3750 5000 50  0001 C CNN
F 1 "GND" H 3755 5077 50  0000 C CNN
F 2 "" H 3750 5250 50  0001 C CNN
F 3 "" H 3750 5250 50  0001 C CNN
	1    3750 5250
	1    0    0    -1  
$EndComp
Wire Wire Line
	3750 5250 3750 5050
Connection ~ 3750 5050
Wire Wire Line
	5550 1550 6000 1550
Text Label 5700 1550 0    50   ~ 0
SCLK
Wire Wire Line
	2800 4450 3250 4450
Text Label 2950 4450 0    50   ~ 0
SCLK
Text Label 2550 2950 0    50   ~ 0
SDI(mcp4822)
Text Label 3050 4650 0    50   ~ 0
RB5
Wire Wire Line
	3250 4650 3050 4650
Wire Wire Line
	5550 2350 6000 2350
Text Label 5750 2350 0    50   ~ 0
CS
Text Label 5850 2350 0    50   ~ 0
(mcp4822)
Text Label 3050 4750 0    50   ~ 0
RB8
Wire Wire Line
	3250 4750 3050 4750
Wire Wire Line
	2150 2550 3050 2550
$EndSCHEMATC