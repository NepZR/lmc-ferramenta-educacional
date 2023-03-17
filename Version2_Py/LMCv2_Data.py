# Developed by....: Lucas Darlindo Freitas Rodrigues (lucas.darlindo@gmail.com) and Octacílio Carvalho de Almeida (octa.oca44@gmail.com)
# Institution.....: Federal University of Western Para :: Institute of Engineering and Geosciences (IEG)
# Course..........: Bacharelor on Computer Science (2018)
# Source Code.....: Apr 01, 2019 - 02:30 AM (Brasilia Standard Time: GMT-3) :: Programmed in C
# Actual Code.....: May 24, 2019 - 01:30 AM (Brasilia Standard Time, GMT-3) :: Programmed in Python
# Module..........: LMC's Data Management Module

data = []

def start():
    data.insert(0, "") # Valor binário (primeiro)
    data.insert(1, "") # Valor binário (segundo)
    data.insert(2, "") # Valor binário (soma binária)
    data.insert(3, "") # Valor decimal (qualquer)
    data.insert(4, "") # Valor binário (binário-hexadecimal)
    data.insert(5, "") # Valor hexadecimal
    data.insert(6, "") # Valor binário (qualquer)
    data.insert(7, "") # Valor inteiro (entrada de dados :: opção)
    data.insert(8, "") # Valor real (ponto flutuante :: IEEE 754)
    data.insert(9, "") # Valor binário (IEEE 754 :: Binário Resultante)

def close():
    data.clear()

def load (dataType):
    if dataType == 'f_Bin':
        return data[0]
    elif dataType == 's_Bin':
        return data[1]
    elif dataType == 'b_Sum':
        return data[2]
    elif dataType == 'decimal':
        return data[3]
    elif dataType == 'b_Hexa':
        return data[4]
    elif dataType == 'hexa_R':
        return data[5]
    elif dataType == 'binary':
        return data[6]
    elif dataType == 'input':
        return data[7]
    elif dataType == 'float':
        return data[8]
    elif dataType == 'ieee754':
        return data[9]

def save (value, dataType):
    if dataType == 'f_Bin':
        data.pop(0)
        data.insert(0, value)
    elif dataType == 's_Bin':
        data.pop(1)
        data.insert(1, value)
    elif dataType == 'b_Sum':
        data.pop(2)
        data.insert(2, value)
    elif dataType == 'decimal':
        data.pop(3)
        data.insert(3, value)
    elif dataType == 'b_Hexa':
        data.pop(4)
        data.insert(4, value)
    elif dataType == 'hexa_R':
        data.pop(5)
        data.insert(5, value)
    elif dataType == 'binary':
        data.pop(6)
        data.insert(6, value)
    elif dataType == 'input':
        data.pop(7)
        data.insert(7, value)
    elif dataType == 'float':
        data.pop(8)
        data.insert(8, value)
    elif dataType == 'ieee754':
        data.pop(9)
        data.insert(9, value)