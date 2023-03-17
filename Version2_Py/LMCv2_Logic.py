# Developed by....: Lucas Darlindo Freitas Rodrigues (lucas.darlindo@gmail.com) and Octacílio Carvalho de Almeida (octa.oca44@gmail.com)
# Institution.....: Federal University of Western Para :: Institute of Engineering and Geosciences (IEG)
# Course..........: Bacharelor on Computer Science (2018)
# Source Code.....: Apr 01, 2019 - 02:30 AM (Brasilia Standard Time: GMT-3) :: Programmed in C
# Actual Code.....: Jun 14, 2019 - 16:00 AM (Brasilia Standard Time: GMT-3) :: Programmed in Python
# Module..........: LMC's Logic Module

# Desafio de implementação (Cássio):
# Programa para receber um valor flutuante e gerar uma string;

import re

def binToDecimal (binary):
    i = (len(binary) - 1)
    decimal = 0
    for b in binary:
        decimal += int(b) * (2 ** i)
        i = i - 1

    return decimal

def decToBinary (decimal):
    res = bin(int(decimal))[2:]

    return res.zfill(8 - len(res))

def binToHexa (binary):
    return str(hex(binToDecimal(binary))[2:]).upper()

def binaryAdder (f_Binary, s_Binary):
    fb, sb = int(f_Binary, base=0), int(s_Binary, base=0)

    result = fb + sb
    result = bin(result)[2:]

    return result

def validateBinAdder (f_Binary, s_Binary):
    fb, sb = int(f_Binary, base=0), int(s_Binary, base=0)

    decimalBase = fb + sb

    return decimalBase

def complementTwo (binary):
    inverse = "0b"
    for b in binary:
        if b == '0':
            inverse = inverse + (b.replace('0', '1'))
        else:
            inverse = inverse + (b.replace('1', '0'))

    complement = bin(int(inverse, base=0) + int("0b00000001", base=0))
    return complement[2:].zfill(8 - len(complement[2:]))

def _IEEE754 (double, precision):
    binaryFP = []
    i = 0
    decimalFP = double.split(".")
    ieee754 = ""

    if float(double) < 0:
        signal = "1"
    else:
        signal = "0"

    if precision == 'simple': # 32 Bits (Precisão Simples)
        decimalFP[0] = str(decToBinary(decimalFP[0])) # Parte INTEIRA
        decimalFP[1] = "0." + decimalFP[1] # Parte FLOAT
        binFloat = []
        while i < 16:
            if (float(decimalFP[1])*2) >= 1:
                t = str(float(decimalFP[1])*2)
                binFloat.append(1)
                decimalFP[1] = "0." + t[2:]
            else:
                binFloat.append("0")
                decimalFP[1] = str(float(decimalFP[1])*2)
            
            i = i+1
        binF = ""
        for b in binFloat:
            binF = binF + str(b)

        binary = (decimalFP[0] + "." + binF)
        #print(binary)
        initialPos = binary.find(".")
        #print(initialPos)
        binary = binary.replace(".", "")
        #print(binary)

        tmp = binary.split("1", 1)
        tmp = "1." + tmp[1]
        newPos = tmp.find(".")
        #print(newPos)
        desloc = initialPos - newPos
        #print(desloc)
        #print(tmp)
        expDec = desloc + 127
        exp = decToBinary(str(expDec))
        #tmp = tmp[0] + "." + tmp[1]

        ieee754 = signal + " " + exp + " " + tmp[2:25]

    elif precision == 'double': # 64 Bits (Precisão Dupla)
        decimalFP[0] = str(decToBinary(decimalFP[0])) # Parte INTEIRA
        decimalFP[1] = "0." + decimalFP[1] # Parte FLOAT
        binFloat = []
        while i < 54:
            if (float(decimalFP[1])*2) > 1:
                t = str(float(decimalFP[1])*2)
                binFloat.append(1)
                decimalFP[1] = "0." + t[2:]
            else:
                binFloat.append("0")
                decimalFP[1] = str(float(decimalFP[1])*2)
            
            i = i+1
        binF = ""
        for b in binFloat:
            binF = binF + str(b)

        binary = (decimalFP[0] + "." + binF)
        #print(binary)
        initialPos = binary.find(".")
        #print(initialPos)
        binary = binary.replace(".", "")
        #print(binary)

        tmp = binary.split("1", 1)
        tmp = "1." + tmp[1]
        newPos = tmp.find(".")
        #print(newPos)
        desloc = initialPos - newPos
        #print(desloc)
        #print(tmp)
        expDec = desloc + 1023
        exp = decToBinary(str(expDec))
        #tmp = tmp[0] + "." + tmp[1]

        ieee754 = signal + " " + exp + " " + tmp[2:54]

    elif precision == 'quadruple': # 128 Bits (Precisão Quadrupla)
        decimalFP[0] = str(decToBinary(decimalFP[0])) # Parte INTEIRA
        decimalFP[1] = "0." + decimalFP[1] # Parte FLOAT
        binFloat = []
        while i < 115:
            if (float(decimalFP[1])*2) > 1:
                t = str(float(decimalFP[1])*2)
                binFloat.append(1)
                decimalFP[1] = "0." + t[2:]
            else:
                binFloat.append("0")
                decimalFP[1] = str(float(decimalFP[1])*2)
            
            i = i+1
        binF = ""
        for b in binFloat:
            binF = binF + str(b)

        binary = (decimalFP[0] + "." + binF)
        #print(binary)
        initialPos = binary.find(".")
        #print(initialPos)
        binary = binary.replace(".", "")
        #print(binary)

        tmp = binary.split("1", 1)
        tmp = "1." + tmp[1]
        newPos = tmp.find(".")
        #print(newPos)
        desloc = initialPos - newPos
        #print(desloc)
        #print(tmp)
        expDec = desloc + 16383
        exp = decToBinary(str(expDec))
        #tmp = tmp[0] + "." + tmp[1]

        ieee754 = signal + " " + exp + " " + tmp[2:115]

    elif precision == 'octuple':  # 256 Bits (Precisão Octupla)
        decimalFP[0] = str(decToBinary(decimalFP[0]))  # Parte INTEIRA
        decimalFP[1] = "0." + decimalFP[1]  # Parte FLOAT
        binFloat = []
        while i < 239:
            if (float(decimalFP[1]) * 2) > 1:
                t = str(float(decimalFP[1]) * 2)
                binFloat.append(1)
                decimalFP[1] = "0." + t[2:]
            else:
                binFloat.append("0")
                decimalFP[1] = str(float(decimalFP[1]) * 2)

            i = i + 1
        binF = ""
        for b in binFloat:
            binF = binF + str(b)

        binary = (decimalFP[0] + "." + binF)
        # print(binary)
        initialPos = binary.find(".")
        # print(initialPos)
        binary = binary.replace(".", "")
        # print(binary)

        tmp = binary.split("1", 1)
        tmp = "1." + tmp[1]
        newPos = tmp.find(".")
        # print(newPos)
        desloc = initialPos - newPos
        # print(desloc)
        # print(tmp)
        expDec = desloc + 262143
        exp = decToBinary(str(expDec))
        # tmp = tmp[0] + "." + tmp[1]

        ieee754 = signal + " " + exp + " " + tmp[2:239]

    return ieee754
        
def IEEE_754 (double, precision):
    if precision == 'simple': # 32 Bits (Precisão Simples)
        ieee = _IEEE754(double = double, precision='simple')
        return ieee

    elif precision == 'double': # 64 Bits (Precisão Dupla)
        ieee = _IEEE754(double = double, precision='double')
        return ieee
    
    elif precision == 'quadruple': # 128 Bits (Precisão Quadrupla)
        ieee = _IEEE754(double = double, precision = 'quadruple')
        return ieee

    elif precision == 'octuple': # 128 Bits (Precisão Quadrupla)
        ieee = _IEEE754(double = double, precision = 'octuple')
        return ieee
