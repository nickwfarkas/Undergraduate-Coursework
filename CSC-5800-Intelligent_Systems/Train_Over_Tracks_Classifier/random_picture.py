import random
import requests
from bs4 import BeautifulSoup
import urllib.request
import time

url = "http://rrcrossings.woodhavenmi.org/allen.jpg?rnd="

for i in range(1,101):
    urllib.request.urlretrieve(url,'./images/image'+str(i)+'.jpeg')
    print(f"{i} pictures collected")
    time.sleep(250)





