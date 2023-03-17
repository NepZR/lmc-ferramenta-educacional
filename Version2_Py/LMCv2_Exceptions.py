# Developed by....: Lucas Darlindo Freitas Rodrigues (lucas.darlindo@gmail.com) and Octacílio Carvalho de Almeida (octa.oca44@gmail.com)
# Institution.....: Federal University of Western Para :: Institute of Engineering and Geosciences (IEG)
# Course..........: Bacharelor on Computer Science (2018)
# Source Code.....: Apr 01, 2019 - 02:30 AM (Brasilia Standard Time: GMT-3) :: Programmed in C
# Actual Code.....: Jun 12, 2019 - 14:10 AM (Brasilia Standard Time, GMT-3) :: Programmed in Python
# Module..........: LMC's Exceptions Treatment Module

import LMCv2_GUI as gui

# Exceptions Options:
# 1) 'option'      -> Invalid input option given by the user.
# 2) 'exceededMax' -> The input number given by the user exceed the limit of the program (preconfigured as 8-bit type).
# 3) 'empty'       -> No data has been given by the user in the input.

def check(method, option, data):
    feedback = False
    if method == 'goTo':
        if option == '2':
            if data > 20:
                raiseError('exceededMax')
            elif data < 9 or data == 0:
                raiseError('empty')
            else:
                feedback = True

        elif option == '3':
            if data < 2:
                raiseError('empty')
            else:
                feedback = True

        elif option == '4':
            if data > 8:
                raiseError('exceededMax')
            elif data == 0:
                raiseError('empty')
            else:
                feedback = True
        
        elif option == '5':
            if data > 255:
                raiseError('exceededMax')
            elif data == 0:
                raiseError('empty')
            else:
                feedback = True

        elif option == '6':
            if data > 8:
                raiseError('exceededMax')
            elif data == 0:
                raiseError('empty')
            else:
                feedback = True

        elif option == '7':
            if data > 8:
                raiseError('exceededMax')
            elif data == 0:
                raiseError('empty')
            else:
                feedback = True
                
    return feedback

def raiseError(type):
    if type == 'option':
        print(" ______________________________________________________________________________________________________________________________ ")
        print("|                                                                                                                              |")
        print("|------------------------------------------------ OPÇÃO INVÁLIDA! Tente Novamente ---------------------------------------------|")
        print("|______________________________________________________________________________________________________________________________|")
        gui.inputWait()
        gui.menu()
    elif type == 'exceededMax':
        print(" ______________________________________________________________________________________________________________________________ ")
        print("|                                                                                                                              |")
        print("|--------------------------------------------- O VALOR EXCEDE 8-BIT! Tente Novamente ------------------------------------------|")
        print("|______________________________________________________________________________________________________________________________|")
        gui.inputWait()
        gui.menu()
    elif type == 'empty':
        print(" ______________________________________________________________________________________________________________________________ ")
        print("|                                                                                                                              |")
        print("|--------------------------------------------- DADOS NÃO INFORMADOS! Tente Novamente ------------------------------------------|")
        print("|______________________________________________________________________________________________________________________________|")
        gui.inputWait()
        gui.menu()