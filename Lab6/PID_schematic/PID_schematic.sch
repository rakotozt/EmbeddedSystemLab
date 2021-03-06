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
$Comp
L PIC32MX250F128B-V_SP:PIC32MX250F128B-V_SP U?
U 1 1 5F8DAA47
P 7550 3200
F 0 "U?" H 7000 4467 50  0000 C CNN
F 1 "PIC32MX250F128B-V_SP" H 7000 4376 50  0000 C CNN
F 2 "DIP254P762X508-28" H 7550 3200 50  0001 L BNN
F 3 "SPDIP-28 Microchip" H 7550 3200 50  0001 L BNN
F 4 "PIC32MX250F128B-V/SP" H 7550 3200 50  0001 L BNN "Field4"
F 5 "32 Bit MCU, 128KB Flash, 32KB RAM, 40 MHz, 28 Pin, 3 Comp, CTMU, RTCC, 28 SPDIP" H 7550 3200 50  0001 L BNN "Field5"
F 6 "Microchip" H 7550 3200 50  0001 L BNN "Field6"
F 7 "None" H 7550 3200 50  0001 L BNN "Field7"
F 8 "Unavailable" H 7550 3200 50  0001 L BNN "Field8"
	1    7550 3200
	1    0    0    -1  
$EndComp
$Comp
L Device:LED D?
U 1 1 5F8DC59E
P 2050 3200
F 0 "D?" H 2043 3416 50  0000 C CNN
F 1 "LED" H 2043 3325 50  0000 C CNN
F 2 "" H 2050 3200 50  0001 C CNN
F 3 "~" H 2050 3200 50  0001 C CNN
	1    2050 3200
	0    -1   -1   0   
$EndComp
$Comp
L power:GND #PWR?
U 1 1 5F8E2C27
P 2450 3900
F 0 "#PWR?" H 2450 3650 50  0001 C CNN
F 1 "GND" H 2455 3727 50  0000 C CNN
F 2 "" H 2450 3900 50  0001 C CNN
F 3 "" H 2450 3900 50  0001 C CNN
	1    2450 3900
	1    0    0    -1  
$EndComp
$Comp
L Device:R_Small_US R1
U 1 1 5F8E3722
P 2050 2600
F 0 "R1" H 2118 2646 50  0000 L CNN
F 1 "300" H 2118 2555 50  0000 L CNN
F 2 "" H 2050 2600 50  0001 C CNN
F 3 "~" H 2050 2600 50  0001 C CNN
	1    2050 2600
	1    0    0    -1  
$EndComp
$Comp
L power:VDD #PWR?
U 1 1 5F8E48E0
P 2500 2150
F 0 "#PWR?" H 2500 2000 50  0001 C CNN
F 1 "VDD" H 2517 2323 50  0000 C CNN
F 2 "" H 2500 2150 50  0001 C CNN
F 3 "" H 2500 2150 50  0001 C CNN
	1    2500 2150
	1    0    0    -1  
$EndComp
Wire Wire Line
	2050 3350 2050 3900
Wire Wire Line
	2050 3900 2450 3900
Wire Wire Line
	2500 2150 2500 2350
Wire Wire Line
	2500 2350 2050 2350
Wire Wire Line
	2050 2350 2050 2500
Wire Wire Line
	2050 2700 2050 3050
Wire Wire Line
	2500 2350 2850 2350
Connection ~ 2500 2350
Wire Wire Line
	2850 3450 2850 3900
Wire Wire Line
	2850 3900 2450 3900
Connection ~ 2450 3900
Wire Wire Line
	2850 2700 2850 2800
Wire Wire Line
	2850 2350 2850 2500
$Comp
L Device:R_Small_US R2
U 1 1 5F8E3F9E
P 2850 2600
F 0 "R2" H 2918 2646 50  0000 L CNN
F 1 "10k" H 2918 2555 50  0000 L CNN
F 2 "" H 2850 2600 50  0001 C CNN
F 3 "~" H 2850 2600 50  0001 C CNN
	1    2850 2600
	1    0    0    -1  
$EndComp
$Comp
L Device:Q_Photo_NPN Q?
U 1 1 5F8E0A1F
P 2750 3250
F 0 "Q?" H 2940 3296 50  0000 L CNN
F 1 "Q_Photo_NPN" H 2940 3205 50  0000 L CNN
F 2 "" H 2950 3350 50  0001 C CNN
F 3 "~" H 2750 3250 50  0001 C CNN
	1    2750 3250
	1    0    0    -1  
$EndComp
$Comp
L Device:R_Small_US R?
U 1 1 5F8EC09F
P 3800 2800
F 0 "R?" V 4005 2800 50  0000 C CNN
F 1 "20k" V 3914 2800 50  0000 C CNN
F 2 "" H 3800 2800 50  0001 C CNN
F 3 "~" H 3800 2800 50  0001 C CNN
	1    3800 2800
	0    -1   -1   0   
$EndComp
$Comp
L Device:R_Small_US R?
U 1 1 5F8ECC2B
P 4750 2200
F 0 "R?" H 4818 2246 50  0000 L CNN
F 1 "1M" H 4818 2155 50  0000 L CNN
F 2 "" H 4750 2200 50  0001 C CNN
F 3 "~" H 4750 2200 50  0001 C CNN
	1    4750 2200
	0    -1   -1   0   
$EndComp
Wire Wire Line
	5150 2900 5350 2900
$Comp
L power:VDD #PWR?
U 1 1 5F8F12FA
P 3850 3250
F 0 "#PWR?" H 3850 3100 50  0001 C CNN
F 1 "VDD" H 3867 3423 50  0000 C CNN
F 2 "" H 3850 3250 50  0001 C CNN
F 3 "" H 3850 3250 50  0001 C CNN
	1    3850 3250
	1    0    0    -1  
$EndComp
$Comp
L Comparator:LM319 U1
U 1 1 5F8F4192
P 4850 2900
F 0 "U1" H 4850 3267 50  0000 C CNN
F 1 "MCP6242" H 4850 3176 50  0000 C CNN
F 2 "" H 4850 2900 50  0001 C CNN
F 3 "http://www.ti.com/lit/ds/symlink/lm319-n.pdf" H 4850 2900 50  0001 C CNN
	1    4850 2900
	1    0    0    -1  
$EndComp
Wire Wire Line
	4550 2800 4300 2800
Wire Wire Line
	4300 2800 3900 2800
Connection ~ 2850 2800
Wire Wire Line
	2850 2800 2850 3050
Wire Wire Line
	4650 2200 4300 2200
Wire Wire Line
	4300 2200 4300 2800
Connection ~ 4300 2800
Wire Wire Line
	4850 2200 5350 2200
Wire Wire Line
	5350 2200 5350 2900
Wire Wire Line
	3700 2800 2850 2800
$Comp
L Device:R_POT RV?
U 1 1 5F8FAE76
P 4450 3550
F 0 "RV?" H 4381 3596 50  0000 R CNN
F 1 "R_POT" H 4381 3505 50  0000 R CNN
F 2 "" H 4450 3550 50  0001 C CNN
F 3 "~" H 4450 3550 50  0001 C CNN
	1    4450 3550
	0    -1   -1   0   
$EndComp
Wire Wire Line
	3850 3250 3850 3550
Wire Wire Line
	3850 3550 4300 3550
Wire Wire Line
	4450 3400 4450 3000
Wire Wire Line
	4450 3000 4550 3000
Wire Wire Line
	4850 3200 4850 3550
Wire Wire Line
	4850 3550 4600 3550
Wire Wire Line
	5350 2900 5750 2900
Connection ~ 5350 2900
$Comp
L Isolator:4N35 U?
U 1 1 5F90B3DA
P 4200 5250
F 0 "U?" H 4200 5575 50  0000 C CNN
F 1 "4N35" H 4200 5484 50  0000 C CNN
F 2 "Package_DIP:DIP-6_W7.62mm" H 4000 5050 50  0001 L CIN
F 3 "https://www.vishay.com/docs/81181/4n35.pdf" H 4200 5250 50  0001 L CNN
	1    4200 5250
	1    0    0    -1  
$EndComp
Wire Wire Line
	5750 4000 3900 4000
Wire Wire Line
	3900 4000 3900 5150
Connection ~ 4850 3550
Wire Wire Line
	4850 3750 4850 3550
$Comp
L power:GND #PWR?
U 1 1 5F8ED3B4
P 4850 3750
F 0 "#PWR?" H 4850 3500 50  0001 C CNN
F 1 "GND" H 4855 3577 50  0000 C CNN
F 2 "" H 4850 3750 50  0001 C CNN
F 3 "" H 4850 3750 50  0001 C CNN
	1    4850 3750
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR?
U 1 1 5F90EB9A
P 3900 5550
F 0 "#PWR?" H 3900 5300 50  0001 C CNN
F 1 "GND" H 3905 5377 50  0000 C CNN
F 2 "" H 3900 5550 50  0001 C CNN
F 3 "" H 3900 5550 50  0001 C CNN
	1    3900 5550
	1    0    0    -1  
$EndComp
Wire Wire Line
	3900 5550 3900 5350
$Comp
L Device:R_Small_US R?
U 1 1 5F90FA1C
P 5100 5050
F 0 "R?" V 5305 5050 50  0000 C CNN
F 1 "1M" V 5214 5050 50  0000 C CNN
F 2 "" H 5100 5050 50  0001 C CNN
F 3 "~" H 5100 5050 50  0001 C CNN
	1    5100 5050
	0    -1   -1   0   
$EndComp
$Comp
L Device:R_Small_US R?
U 1 1 5F9102BC
P 5050 5550
F 0 "R?" H 5118 5596 50  0000 L CNN
F 1 "10k" H 5118 5505 50  0000 L CNN
F 2 "" H 5050 5550 50  0001 C CNN
F 3 "~" H 5050 5550 50  0001 C CNN
	1    5050 5550
	0    -1   -1   0   
$EndComp
Wire Wire Line
	4500 5150 4500 5050
Wire Wire Line
	4500 5050 5000 5050
Wire Wire Line
	4500 5350 4500 5550
Wire Wire Line
	4500 5550 4650 5550
Wire Wire Line
	5200 5050 6000 5050
Wire Wire Line
	6000 5050 6000 5550
Wire Wire Line
	6000 5550 5400 5550
$Comp
L Transistor_FET:IRLB8721PBF Q?
U 1 1 5F9149A8
P 5300 6000
F 0 "Q?" H 5504 6046 50  0000 L CNN
F 1 "IRLB8721PBF" H 5504 5955 50  0000 L CNN
F 2 "Package_TO_SOT_THT:TO-220-3_Vertical" H 5550 5925 50  0001 L CIN
F 3 "http://www.infineon.com/dgdl/irlb8721pbf.pdf?fileId=5546d462533600a40153566056732591" H 5300 6000 50  0001 L CNN
	1    5300 6000
	1    0    0    -1  
$EndComp
Wire Wire Line
	5100 6000 4650 6000
Wire Wire Line
	4650 6000 4650 5550
Connection ~ 4650 5550
Wire Wire Line
	4650 5550 4950 5550
Wire Wire Line
	5400 5800 5400 5550
Connection ~ 5400 5550
Wire Wire Line
	5400 5550 5150 5550
$Comp
L Motor:Motor_DC M?
U 1 1 5F91A285
P 6950 5550
F 0 "M?" H 7108 5546 50  0000 L CNN
F 1 "Motor_DC" H 7108 5455 50  0000 L CNN
F 2 "" H 6950 5460 50  0001 C CNN
F 3 "~" H 6950 5460 50  0001 C CNN
	1    6950 5550
	1    0    0    -1  
$EndComp
Wire Wire Line
	5400 6200 6200 6200
Wire Wire Line
	6950 6200 6950 5850
Wire Wire Line
	4500 5250 6200 5250
Wire Wire Line
	6950 5250 6950 5350
$Comp
L Diode:1N4001 D?
U 1 1 5F91E634
P 6200 5550
F 0 "D?" H 6200 5766 50  0000 C CNN
F 1 "1N4001" H 6200 5675 50  0000 C CNN
F 2 "Diode_THT:D_DO-41_SOD81_P10.16mm_Horizontal" H 6200 5375 50  0001 C CNN
F 3 "http://www.vishay.com/docs/88503/1n4001.pdf" H 6200 5550 50  0001 C CNN
	1    6200 5550
	0    1    1    0   
$EndComp
$Comp
L Device:C c1
U 1 1 5F921EE0
P 6550 5550
F 0 "c1" H 6665 5596 50  0000 L CNN
F 1 "0.1u" H 6665 5505 50  0000 L CNN
F 2 "" H 6588 5400 50  0001 C CNN
F 3 "~" H 6550 5550 50  0001 C CNN
	1    6550 5550
	1    0    0    -1  
$EndComp
Wire Wire Line
	6200 5400 6200 5250
Connection ~ 6200 5250
Wire Wire Line
	6200 5250 6550 5250
Wire Wire Line
	6550 5250 6550 5400
Connection ~ 6550 5250
Wire Wire Line
	6550 5250 6950 5250
Wire Wire Line
	6200 5700 6200 6200
Connection ~ 6200 6200
Wire Wire Line
	6200 6200 6550 6200
Wire Wire Line
	6550 5700 6550 6200
Connection ~ 6550 6200
Wire Wire Line
	6550 6200 6950 6200
$Comp
L power:GND #PWR?
U 1 1 5F926267
P 6000 5700
F 0 "#PWR?" H 6000 5450 50  0001 C CNN
F 1 "GND" H 6005 5527 50  0000 C CNN
F 2 "" H 6000 5700 50  0001 C CNN
F 3 "" H 6000 5700 50  0001 C CNN
	1    6000 5700
	1    0    0    -1  
$EndComp
Wire Wire Line
	6000 5700 6000 5550
Connection ~ 6000 5550
$EndSCHEMATC
