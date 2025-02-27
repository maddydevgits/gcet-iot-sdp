import pickle
from flask import Flask,request

with open('ai.pkl','rb') as f:
    ai=pickle.load(f)

app=Flask(__name__)

@app.route('/')
def homeRoute():
    return 'AI Deployment Server Running'

@app.route('/predict',methods=['GET'])
def predict():
    h=float(request.args.get('h'))
    result=ai.predict([[h]])
    return result[0]

if __name__=="__main__":
    app.run(
        host='0.0.0.0',
        port=2000,
        debug=True
    )