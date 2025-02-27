import serial
import pandas as pd

ser=serial.Serial('COM5',9600,timeout=0.5)
count=0
dataset=[]

while True:
    if(ser.inWaiting()>0):
        print("Data is Available to read")
        data=ser.readline()
        data=data.decode('utf-8')
        if(data.startswith("#")):
            print(data)
            data=data.split(",")
            print(data)
            h=float(data[1])
            out=data[2]
            print(h,out)
            dummy=[]
            dummy.append(h)
            dummy.append(out)
            dataset.append(dummy)
            count+=1
            print(dataset)
            if count==10:
                df=pd.DataFrame(dataset)
                df.to_csv('dataset.csv')
                count=0