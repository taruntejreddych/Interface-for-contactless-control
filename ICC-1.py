import serial                                      
import pyautogui                                   

Arduino_Serial = serial.Serial('com3',38400)
while 1:
    incoming_data = str (Arduino_Serial.readline())
    print (incoming_data)
    if len(incoming_data) >= 9:
        length=len(incoming_data)
        incoming_data=incoming_data[2:length-5]      
        pyautogui.typewrite(incoming_data)
    elif len(incoming_data) == 8:
        if '1' in incoming_data:
            pyautogui.hotkey('ctrl','t')
            
        if '2' in incoming_data:
            pyautogui.hotkey('ctrl','n')
        
        if '3' in incoming_data:
            pyautogui.hotkey('ctrl','tab')
        
        if '4' in incoming_data:
            pyautogui.hotkey('ctrl','shift','tab')
        
        if '5' in incoming_data:
            pyautogui.hotkey('win','e')
        
        if '6' in incoming_data:
            pyautogui.hotkey('ctrl','w')
        
        if '7' in incoming_data:
            pyautogui.press('win')
        
        if '8' in incoming_data:
            pyautogui.press('tab')
        
        if '9' in incoming_data:
            pyautogui.press('backspace')
        
        if 'z' in incoming_data:
            pyautogui.hotkey('alt','tab')
        
        if 'c' in incoming_data:
            pyautogui.hotkey('win','tab')
        
        if 'a' in incoming_data:
            pyautogui.press('enter')
        
        if 'd' in incoming_data:
            pyautogui.press('up')
        
        if 'g' in incoming_data:
            pyautogui.press('down')
        
        if 'e' in incoming_data:
            pyautogui.press('left')
        
        if 'f' in incoming_data:
            pyautogui.press('right')
        
        if 'p' in incoming_data:
            pyautogui.press('space')
        
        if 'h' in incoming_data:
            pyautogui.hotkey('ctrl','l')
        
        if 'i' in incoming_data:
            pyautogui.hotkey('alt','f4')
        
        if 'j' in incoming_data:
            pyautogui.hotkey('ctrl','alt','c')
        
        if 'k' in incoming_data:    
            pyautogui.hotkey('volumedown')
            pyautogui.hotkey('volumedown')
            pyautogui.hotkey('volumedown')
            pyautogui.hotkey('volumedown')
            pyautogui.hotkey('volumedown')
            pyautogui.hotkey('volumedown')

        if 'l' in incoming_data:
            pyautogui.hotkey('volumeup')
            pyautogui.hotkey('volumeup')
            pyautogui.hotkey('volumeup')
            pyautogui.hotkey('volumeup')
            pyautogui.hotkey('volumeup')
            pyautogui.hotkey('volumeup')
    

    incoming_data = "";
    
