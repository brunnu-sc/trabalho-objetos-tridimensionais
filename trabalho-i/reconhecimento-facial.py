import cv2 

imagem = cv2.imread('foto.jpg') 

from google.colab.patches import cv2_imshow

cv2_imshow(imagem)

detector = cv2.CascadeClassifier('haarcascade_frontalface_default.xml')

img_cinza = cv2.cvtColor(imagem, cv2.COLOR_BGR2GRAY)

cv2_imshow(img_cinza)

deteccoes = detector.detectMultiScale(img_cinza, scaleFactor=1.3)

deteccoes

len(deteccoes)

for (x, y, l, a) in deteccoes:
  cv2.rectangle(imagem, (x, y), (x + l, y + a), (0, 255, 0), 2)

cv2_imshow(imagem)
