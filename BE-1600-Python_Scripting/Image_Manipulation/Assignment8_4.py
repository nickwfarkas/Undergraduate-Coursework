from cImage import *

def makeRed(oldPixel):
        if(oldPixel.getRed()*2 > 255):
                return Pixel(255, oldPixel.getGreen(), oldPixel.getBlue())
        else:
                return Pixel(oldPixel.getRed()*2, oldPixel.getGreen(), oldPixel.getBlue())

def makeMoreRed(imageFile):
    oldImage = FileImage(imageFile)
    width = oldImage.getWidth()
    height = oldImage.getHeight()

    myImageWindow = ImageWin("Enhance Red", width * 2, height)
    oldImage.draw(myImageWindow)
    newIm = EmptyImage(width, height)

    for row in range(height):
        for col in range(width):
            oldPixel = oldImage.getPixel(col, row)							
            newPixel = makeRed(oldPixel)							
            newIm.setPixel(col, row, newPixel)

    newIm.setPosition(width + 1, 0)
    newIm.draw(myImageWindow)
    myImageWindow.exitOnClick()

makeMoreRed("butterfly.gif")
