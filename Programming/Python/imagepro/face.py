import numpy as np
import cv2
import pickle
import os

face_cascade = cv2.CascadeClassifier('/anaconda3/pkgs/libopencv-3.4.2-h7c891bd_1/share/OpenCV/haarcascades/haarcascade_frontalface_alt2.xml')
rec = cv2.face.LBPHFaceRecognizer_create()
rec.read("trainner.yml")

labels = {}
with open("labels.pickle",'rb') as f:
    labels = pickle.load(f)
    labels = {v:k for k,v in labels.items()}
    
cap = cv2.VideoCapture(0)


while(True):
    ret, frame = cap.read()
    gray = cv2.cvtColor(frame, cv2.COLOR_BGR2GRAY)
    faces = face_cascade.detectMultiScale(gray, scaleFactor=1.5, minNeighbors=5)
    for(x,y,w,h) in faces:
        #print(x,y,w,h)
        roi_gray = gray[y:y+h, x:x+w]  #(ycord_start, ycord_end)
        roi_color = frame[y:y+h, x:x+w]
        #regcognize deeplearning
        """
        id_, conf = rec.predict(roi_gray)
        if conf>=45:
            print(id_)
            print(labels[id_])
            font = cv2.FONT_HERSHEY_SIMPLEX
            name = labels[id_]
            color = (255,255,255)
            stroke = 2
            cv2.putText(frame, name, (x+w,y+10), font, 1 , color, stroke, cv2.LINE_AA)
            
            if id_ == 1:
                cv2.putText(frame, '19 years old', (x+w,y+45), font, 1 , color, stroke, cv2.LINE_AA)
                cv2.putText(frame, 'Engineering student', (x+w,y+80), font, 1 , color, stroke, cv2.LINE_AA)
            if id_ == 2:
                cv2.putText(frame, '28 years old', (x+w,y+45), font, 1 , color, stroke, cv2.LINE_AA)
                cv2.putText(frame, 'Hollywood actress', (x+w,y+80), font, 1 , color, stroke, cv2.LINE_AA)
            """
        img_item = "me.png"
        cv2.imwrite(img_item,roi_color)
        
        color = (255, 0, 0)
        stroke = 2
        width = x + w
        height = y + h
        cv2.rectangle(frame, (x,y),(width, height), color,stroke)
    cv2.imshow('frame',frame)
    if cv2.waitKey(20) & 0xFF == ord('q'):
        break
cap.release()
#out.release()
cv2.destroyAllWindows()