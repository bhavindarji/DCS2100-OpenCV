import urllib
import cv2
import numpy as np
import time
 
url='http://admin:admin@192.168.1.106/cgi-bin/video.jpg'
 
while True:
 
    # Use urllib to get the image and convert into a cv2 usable format
    imgResp=urllib.urlopen(url)
    imgNp=np.array(bytearray(imgResp.read()),dtype=np.uint8)
    img=cv2.imdecode(imgNp,-1)
   
    # put the image on screen
    cv2.imshow('IPWebcam',img)
 
    #To give the processor some less stress
    #time.sleep(0.1)
 
    if cv2.waitKey(1) & 0xFF == ord('q'):
        break
