from cImage import *
import math

def drawCircle(r,h,k): 
    image = ImageWin("Circle", 300, 300)
    view = EmptyImage(300,300)
    blue = Pixel(0,0,255)

    for i in range(360):
        view.setPixel(h+int(r*math.cos(i)),k+int(r*math.sin(i)),blue)

    view.draw(image)

drawCircle(100,150,150)
