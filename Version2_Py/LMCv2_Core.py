# Developed by....: Lucas Darlindo Freitas Rodrigues (lucas.darlindo@gmail.com) and Octacílio Carvalho de Almeida (octa.oca44@gmail.com)
# Institution.....: Federal University of Western Para :: Institute of Engineering and Geosciences (IEG)
# Course..........: Bacharelor on Computer Science (2018)
# Source Code.....: Apr 01, 2019 - 02:30 AM (Brasilia Standard Time: GMT-3) :: Programmed in C
# Actual Code.....: Jun 14, 2019 - 16:00 AM (Brasilia Standard Time: GMT-3) :: Programmed in Python
# Module..........: LMC's Core Module

import LMCv2_GUI as gui
import LMCv2_Logic as logic
import LMCv2_Data as data
import LMCv2_Exceptions as exceptions
import os

# Exceptions Options:
# 1) 'option'      -> Invalid input option given by the user.
# 2) 'exceededMax' -> The input number given by the user exceed the limit of the program (preconfigured as 8-bit type).
# 3) 'empty'       -> No data has been given by the user in the input.

# Go To -> Redirect to other methods in the program
# 1) Binary Rule's Table
# 2) Binary Adder (Max: 8-bit)
# 3) Verification for the addition made in the Binary Adder (Max: 8-bit to Decimal)
# 4) Transform: Binary to Decimal
# 5) Transform: Decimal to Binary
# 6) Binary Complement of Two
# 7) Transform: Decimal to Hexadecimal (Max: 8-bit to Hexadecimal)
# 8) Binary with float point (Rule from IEEE: 758) -> i) Simple Precision; ii) Double Precision; iii) Quadruple Precision; iv) Graphical Representation
# 9) Von Neumann's Arquitecture Representation
# 0) Ends the program

def clear():
    try:
        os.system('clear')
    except:
        try:
            os.system('cls')
        except:
            pass

def runProgram():
    data.start()
    gui.startup()
    gui.menu()

def goTo (option, args = ''):
    clear()

    if option == '1':
        gui.binaryRules()

    elif option == '2':
        data.save(("0b" + input("| Digite o primeiro valor binário (Max: 8-bit): ")), "f_Bin")
        data.save("0b" + input("| Digite o segundo valor binário (Max: 8-bit).: "), "s_Bin")
        if exceptions.check('goTo', option, (len(data.load("f_Bin"))+len(data.load("s_Bin")))):
            data.save(logic.binaryAdder(data.load("f_Bin"), data.load("s_Bin")), "b_Sum")
            
            print ("| Soma entre (" + data.load("f_Bin")[2:] + ") e (" + data.load("s_Bin")[2:] + "): ", data.load("b_Sum"))
            gui.binaryAdder(data.load('f_Bin')[2:], data.load('s_Bin')[2:], data.load('b_Sum'))

    elif option == '3':
        if exceptions.check('goTo', option, (len(data.load("f_Bin"))+len(data.load("s_Bin")))):
            data.save(logic.validateBinAdder(data.load("f_Bin"), data.load("s_Bin")), "decimal")
            print("| Primeiro valor binário inserido: " + data.load("f_Bin")[2:])
            print("| Segundo valor binário inserido.: " + data.load("s_Bin")[2:])
            print("| Resultado da soma binária......: ", data.load("b_Sum"))
            print("| Soma efetuada em decimal.......: ", int(data.load("f_Bin"), base=0), " + ", int(data.load("s_Bin"), base=0), " = ", data.load("decimal"))

    elif option == '4':
        data.save(input("| Digite o valor para conversão binário-decimal (Max: 8-bit, separados por espaços): ").split(" "), "binary")
        if exceptions.check('goTo', option, len(data.load("binary"))):
            print("| Valor convertido para decimal....................................................: ", logic.binToDecimal(binary = data.load("binary")))
            gui.binToDecimal(data.load('binary'), logic.binToDecimal(binary = data.load("binary")))

    elif option ==  '5':
        data.save(input("Digite o valor para conversão decimal-binário (Max: 8-bit ~ Decimal 255): "), "decimal")
        if exceptions.check('goTo', option, int(data.load("decimal"))):
            print("| Valor convertido para binário [MSBx4, LSBx4]..........................: ", logic.decToBinary(decimal = data.load("decimal")))
        
    elif option == '6':
        data.save(input("| Digite o valor para o complemento de dois (Max: 8-bit, separados por espaços): ").split(" "), "binary")
        if exceptions.check('goTo', option, len(data.load("binary"))):
            print("| Complemento de Dois...................................................: ", logic.complementTwo(binary = data.load("binary")))

    elif option == '7':
        data.save((input("| Digite o valor para conversão binário-hexadecimal (Max: 8-bit, separados por espaços): ")).split(" "), "b_Hexa")
        if exceptions.check('goTo', option, len(data.load("b_Hexa"))):
            data.save(logic.binToHexa(data.load("b_Hexa")), "hexa_R")
            gui.binToHexa(data.load('b_Hexa'), data.load('hexa_R'))

    elif option == '8': # Chamada do menu para representação binária em ponto flutuante (IEEE 754)
        if args == '':
            gui.ieee754()

        elif args == '1': # Seleção da precisão do tipo simples
            data.save(input("| Regra IEEE 754 (Precisão Simples | 32 Bits) -> Digite o valor: "), "float")
            data.save(logic.IEEE_754(data.load("float"), "simple"), "ieee754")
            gui.ieee754_block(data.load('ieee754'), 'simple')

        elif args == '2': # Seleção da precisão do tipo dupla
            data.save(input("| Regra IEEE 754 (Precisão Dupla | 64 Bits) -> Digite o valor: "), "float")
            data.save(logic.IEEE_754(data.load("float"), "double"), "ieee754")
            gui.ieee754_block(data.load('ieee754'), 'double')

        elif args == '3': # Seleção da precisão do tipo quadrupla
            data.save(input("| Regra IEEE 754 (Precisão Quadrupla | 128 Bits) -> Digite o valor: "), "float")
            data.save(logic.IEEE_754(data.load("float"), "quadruple"), "ieee754")
            gui.ieee754_block(data.load('ieee754'), 'quadruple')

        elif args == '4': # Seleção da precisão do tipo óctupla
            data.save(input("| Regra IEEE 754 (Precisão Óctupla | 256 Bits) -> Digite o valor: "), "float")
            data.save(logic.IEEE_754(data.load("float"), "octuple"), "ieee754")
            gui.ieee754_block(data.load('ieee754'), 'octuple')

        elif args == '5': # Seleção da representação gráfica para visualização da regra
            gui.ieeeRep()
        
        elif args == '0': # Retornar para o Menu Principal da Aplicação
            goBack()

    elif option == '9': # Exibição do modelo de arquitetura de Von Neumann
        gui.vonNeumann()

    elif option == '0': # Encerrar a execução da aplicação (limpar o terminal -> limpar e encerrar o conjunto de dados -> finalizar)
        clear()
        data.close()
        exit()

    else: # A entrada de opção do usuário foi inválida ou inexistente (exibe um erro)
        exceptions.raiseError('option')

    gui.inputWait()
    keepRunning()

def keepRunning ():
    gui.askUser()
    option = input("| Digite a opção desejada: ")
    if option == '1':
        gui.menu()
    else:
        goTo('0')

def goBack ():
    gui.menu()

def userInput (args = ''):
    data.save(input("| Digite a opção desejada: "), "input")

    if args == '':
        goTo(data.load("input"), args=args)
    elif args == '8':
        goTo('8', args=data.load("input"))